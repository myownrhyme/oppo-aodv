#include "oppo-aodv.h"
#include <string.h>
#include <omnetpp.h>
#include<algorithm>
#define UPDATETIME 5.0
#define SENDDATA 100

Define_Module(Node);
Node::Node(){

}
Node::~Node(){

}

void Node::initialize(){
    update = new cMessage("update");
    senddata = new cMessage("senddata");
    //---test code---
//    if (getIndex()==0){
//        scheduleAt(0.0,update);
//    }
    //--------
      scheduleAt(simTime()+uniform(0,UPDATETIME),update);
//    scheduleAt(simTime()+SENDDATA,senddata);
}

void Node::handleMessage(cMessage *msg){
    if(msg->isSelfMessage()){
        if(msg == update){
               handleUPDATEDATA();//send update packet

           }
    }else{
        /*
         * send update ack
         * */
        if(mycast<UPDATEDATA*>(msg)!=NULL ){
            //return routetable
            vector<unsigned int> v;
            for(deque<Neighbor>::iterator i =neighbortable.begin();i!=neighbortable.end();i++)
            {
                  unsigned int temp=(*i).nodeid;
                  v.push_back(temp);
            }
            NeighborSet sendtemp(v);
            UPDATEACK *t = new UPDATEACK("updateack");
            t->setNeighborset(sendtemp);
            send(t,"g$o",(msg->getArrivalGateId() -  msg->getArrivalGate()->getBaseId()));
            EV<<"go to next";
            update = new cMessage("update");
            scheduleAt(simTime()+uniform(0,UPDATETIME),update);
        }
        if(mycast<UPDATEACK*>(msg)!=NULL){
            UPDATEACK *t=check_and_cast<UPDATEACK*>(msg);
            deque<Neighbor>::iterator i;
            for(i =neighbortable.begin();i!=neighbortable.end();i++)
            {

                if((*i).nodeid == (t->getSenderModule()->getIndex())){
                    //calculate delay and successful rate;
                    (*i).neighborvector=(t->getNeighborset()).neighborvector;
                }
            }

            if(i == neighbortable.end())
            {
                Neighbor neighbor;
                neighbor.nodeid= t->getSenderModule()->getIndex();
                neighbor.neighborvector=(t->getNeighborset()).neighborvector;
                (neighbor.delay).push_back(0);
                (neighbor.SuccessfulRate).push_back(1);
                neighbortable.push_back(neighbor);
            }
            if(neighbortable.size()>10)
                neighbortable.pop_front();

            /*
             * test code
             * */
//            for(auto j: neighbortable){
//                EV<<j.nodeid<<endl;
//            }
            delete t;
        }
    }
}

void Node::handleUPDATEDATA(){
    UPDATEDATA *updatedata =new UPDATEDATA("updatedata");
    broadcastUPDATE(updatedata);
}

void Node::broadcastUPDATE(UPDATEDATA *msg){
    int n = gateSize("g");
    for(int i = 0 ;i<n ;i++){
        UPDATEDATA *copy=msg->dup();
        send(copy,"g$o",i);
    }
}

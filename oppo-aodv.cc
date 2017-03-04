#include <string.h>
#include <omnetpp.h>

#define UPDATETIME 5.0
#define SENDDATA 100
using namespace omnetpp;

Node::Node(){

};
Node::~Node(){};

void Node::initialize(){
    cMessage *update = new cMessage("update");
    cMessage *rreq = new cMessage("rreq");
    cMessage *rrep = new cMessage("rrep");
    cMessage *senddata = new cMessage("senddata");
    schduleAt(simTime()+UPDATETIME,senddata);
    schduleAt(simTime()+SENDDATA,update);
}

void Node::handleMessage(cMessage *msg){

}

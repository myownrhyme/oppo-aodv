#ifndef __OPPO_AODV_
#define __OPPO_AODV_
#include <string.h>
#include <omnetpp.h>
#include <vector>
#include <deque>
#include "MyMessage_m.h"

using namespace omnetpp;
using namespace std;


class Node : public cSimpleModule{
private:
    deque<Neighbor> neighbortable;
    vector<RestorePath> resPath;
    cMessage *update ;
    cMessage *rreq ;
    cMessage *senddata ;

protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    //virtual void finish() override;
    void handleRREP(AODVRREP *msg);
    void handleRREQ(AODVRREQ *msg);
    void handleDATAACK(AODVDATAACK *msg);
    void handleDATA(AODVDATA *msg);
    void handleUPDATEDATA();
    void handleUPDATEACK(UPDATEACK *msg);
    void broadcastUPDATE(UPDATEDATA *msg);
public:
    Node();
    virtual ~Node();
};

#endif


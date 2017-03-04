#include <string.h>
#include <omnetpp.h>
#include <vector>

using namespace omnetpp;

class Node : public cSimpleModule{
private:
    vector<Neighbor> neighbor;
    vector<RestorePath> resPath;

protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

public:
    Node();
    virtual ~Node();
};



struct Neighbor{
    unsigned int Nodeid;
    double SuccessfulRate;
    double delay;
    vector<unsigned int> neighborSet;
};

struct RestorePath{
    unsigned int Nodeid;
    vector<unsigned int> fowSet;
    //out of date time;
    simtime_t outtime;
};




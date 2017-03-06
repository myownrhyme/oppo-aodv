#ifndef __COMMON__
#define __COMMON__
#include <vector>
#include <omnetpp.h>
using namespace std;
using namespace omnetpp;
struct Neighbor
{
    unsigned int nodeid;
    vector<double> SuccessfulRate;
    vector<double> delay;
    vector<unsigned int> neighborvector;
};

struct NeighborSet :public cMessage{
    vector<unsigned int> neighborvector;
    NeighborSet(){};
    NeighborSet(vector<unsigned int> v):neighborvector(v){};
};


template<class P, class T>
P mycast(T *p)
{
    if (!p)
        return NULL;
    P ret = dynamic_cast<P>(p);
    if (!ret)
        return NULL;
    return ret;
}

struct RestorePath: public cMessage
{
    unsigned int dest;
    vector<unsigned int> fowSet;
    //out of date time;
    simtime_t outtime;
};
#endif

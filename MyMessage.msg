cplusplus{{
#include "common.h"
}}


class noncobject NeighborSet;
class noncobject RestorePath;

enum basicHead
{
    RREQ = 1;
    RREP = 2;
    DATA = 3;
    UPDATE = 4;
    dataACK = 5;
	updateACK = 6;
};

packet MyPacket	
{
    unsigned int packetType;
}
//
// Represents an AODV Route Request
//
class AODVRREQ extends MyPacket
{
    unsigned int packetType = RREQ;
    unsigned int hopCount;
    unsigned int seq;
    unsigned int destNode;
}

//
// Represents an AODV Route Reply
//
class AODVRREP extends MyPacket
{
    unsigned int packetType = RREP;
    unsigned int hopCount;
    unsigned int seq;
    RestorePath downHelper;
    unsigned int downGuide;
    RestorePath upHelper;
    unsigned int upGuide;
}


// Represents an data packets
//

class AODVDATA extends MyPacket
{
	unsigned int packetType = RREQ;
    unsigned int hopCount;
    unsigned int destNode;
    RestorePath table_prior;
}

class AODVDATAACK extends MyPacket
{
	 unsigned int AckType = dataACK;
}

class UPDATEDATA extends MyPacket{
	unsigned int packetType = UPDATE;
    unsigned int hopCount;
    unsigned int seq;
    unsigned int destNode;
}

class UPDATEACK extends MyPacket{
 	unsigned int AckType = updateACK;
 	NeighborSet neighborset;
}

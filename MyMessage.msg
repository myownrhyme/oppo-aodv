cplusplus{{
#include <vector>
}}

enum basicHead
{
    RREQ = 1;
    RREP = 2;
    DATA = 3;
    UPDATE = 4;
};

enum basicAck{
	dataACK = 1;
	uodateACK = 2;
};

packet MyPacket
{
    unsigned int packetType;
}

packet MyACK{
	unsigned int AckType;	
};

//
// Represents an AODV Route Request
//
class AODVRREQ extends MyPacket
{
    unsigned int packetType = RREQ;
    unsigned int hopCount;
    unsigned int seq;
    unsigned int Nodeid;
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
    unsigned int Nodeid;
    std::vector<unsigned int> downHelper;
    unsigned int downGuide;
    std::vector<unsigned int> upHelper;
    unsigned int upGuide;
}


// Represents an data packets
//

class AODVDATA extends MyPacket
{
	unsigned int packetType = RREQ;
    unsigned int hopCount;
    unsigned int Nodeid;
    unsigned int destNode;
    std::vector<unsigned int> table_prior;
}

class AODVDATAACK extends MyACK
{
	 unsigned int AckType = dataACK;
}

class updateDATA extend MyPacket{
	unsigned int packetType = UPDATE;
    unsigned int hopCount;
    unsigned int seq;
    unsigned int Nodeid;
    unsigned int destNode;
}

class updateACK extend MyACK{
 	unsigned int AckType = updateACK;
 	
}

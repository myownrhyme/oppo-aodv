//
// Generated file, do not edit! Created by nedtool 5.0 from MyMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "MyMessage_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: no doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: no doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("basicHead");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("basicHead"));
    e->insert(RREQ, "RREQ");
    e->insert(RREP, "RREP");
    e->insert(DATA, "DATA");
    e->insert(UPDATE, "UPDATE");
    e->insert(dataACK, "dataACK");
    e->insert(updateACK, "updateACK");
);

Register_Class(MyPacket);

MyPacket::MyPacket(const char *name, int kind) : ::omnetpp::cPacket(name,kind)
{
    this->packetType = 0;
}

MyPacket::MyPacket(const MyPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

MyPacket::~MyPacket()
{
}

MyPacket& MyPacket::operator=(const MyPacket& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MyPacket::copy(const MyPacket& other)
{
    this->packetType = other.packetType;
}

void MyPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
}

void MyPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
}

unsigned int MyPacket::getPacketType() const
{
    return this->packetType;
}

void MyPacket::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

class MyPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    MyPacketDescriptor();
    virtual ~MyPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(MyPacketDescriptor);

MyPacketDescriptor::MyPacketDescriptor() : omnetpp::cClassDescriptor("MyPacket", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

MyPacketDescriptor::~MyPacketDescriptor()
{
    delete[] propertynames;
}

bool MyPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MyPacket *>(obj)!=nullptr;
}

const char **MyPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MyPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MyPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int MyPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *MyPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int MyPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MyPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **MyPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MyPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MyPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MyPacket *pp = (MyPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MyPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MyPacket *pp = (MyPacket *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        default: return "";
    }
}

bool MyPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MyPacket *pp = (MyPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *MyPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *MyPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MyPacket *pp = (MyPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(AODVRREQ);

AODVRREQ::AODVRREQ(const char *name) : ::MyPacket(name)
{
    this->packetType = RREQ;
    this->hopCount = 0;
    this->seq = 0;
    this->destNode = 0;
}

AODVRREQ::AODVRREQ(const AODVRREQ& other) : ::MyPacket(other)
{
    copy(other);
}

AODVRREQ::~AODVRREQ()
{
}

AODVRREQ& AODVRREQ::operator=(const AODVRREQ& other)
{
    if (this==&other) return *this;
    ::MyPacket::operator=(other);
    copy(other);
    return *this;
}

void AODVRREQ::copy(const AODVRREQ& other)
{
    this->packetType = other.packetType;
    this->hopCount = other.hopCount;
    this->seq = other.seq;
    this->destNode = other.destNode;
}

void AODVRREQ::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MyPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->seq);
    doParsimPacking(b,this->destNode);
}

void AODVRREQ::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MyPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->seq);
    doParsimUnpacking(b,this->destNode);
}

unsigned int AODVRREQ::getPacketType() const
{
    return this->packetType;
}

void AODVRREQ::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

unsigned int AODVRREQ::getHopCount() const
{
    return this->hopCount;
}

void AODVRREQ::setHopCount(unsigned int hopCount)
{
    this->hopCount = hopCount;
}

unsigned int AODVRREQ::getSeq() const
{
    return this->seq;
}

void AODVRREQ::setSeq(unsigned int seq)
{
    this->seq = seq;
}

unsigned int AODVRREQ::getDestNode() const
{
    return this->destNode;
}

void AODVRREQ::setDestNode(unsigned int destNode)
{
    this->destNode = destNode;
}

class AODVRREQDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AODVRREQDescriptor();
    virtual ~AODVRREQDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AODVRREQDescriptor);

AODVRREQDescriptor::AODVRREQDescriptor() : omnetpp::cClassDescriptor("AODVRREQ", "MyPacket")
{
    propertynames = nullptr;
}

AODVRREQDescriptor::~AODVRREQDescriptor()
{
    delete[] propertynames;
}

bool AODVRREQDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AODVRREQ *>(obj)!=nullptr;
}

const char **AODVRREQDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AODVRREQDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AODVRREQDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int AODVRREQDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *AODVRREQDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
        "hopCount",
        "seq",
        "destNode",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int AODVRREQDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "seq")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destNode")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AODVRREQDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **AODVRREQDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AODVRREQDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AODVRREQDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AODVRREQ *pp = (AODVRREQ *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string AODVRREQDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVRREQ *pp = (AODVRREQ *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return ulong2string(pp->getHopCount());
        case 2: return ulong2string(pp->getSeq());
        case 3: return ulong2string(pp->getDestNode());
        default: return "";
    }
}

bool AODVRREQDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AODVRREQ *pp = (AODVRREQ *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setHopCount(string2ulong(value)); return true;
        case 2: pp->setSeq(string2ulong(value)); return true;
        case 3: pp->setDestNode(string2ulong(value)); return true;
        default: return false;
    }
}

const char *AODVRREQDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *AODVRREQDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AODVRREQ *pp = (AODVRREQ *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(AODVRREP);

AODVRREP::AODVRREP(const char *name) : ::MyPacket(name)
{
    this->packetType = RREP;
    this->hopCount = 0;
    this->seq = 0;
    this->downGuide = 0;
    this->upGuide = 0;
}

AODVRREP::AODVRREP(const AODVRREP& other) : ::MyPacket(other)
{
    copy(other);
}

AODVRREP::~AODVRREP()
{
}

AODVRREP& AODVRREP::operator=(const AODVRREP& other)
{
    if (this==&other) return *this;
    ::MyPacket::operator=(other);
    copy(other);
    return *this;
}

void AODVRREP::copy(const AODVRREP& other)
{
    this->packetType = other.packetType;
    this->hopCount = other.hopCount;
    this->seq = other.seq;
    this->downHelper = other.downHelper;
    this->downGuide = other.downGuide;
    this->upHelper = other.upHelper;
    this->upGuide = other.upGuide;
}

void AODVRREP::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MyPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->seq);
    doParsimPacking(b,this->downHelper);
    doParsimPacking(b,this->downGuide);
    doParsimPacking(b,this->upHelper);
    doParsimPacking(b,this->upGuide);
}

void AODVRREP::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MyPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->seq);
    doParsimUnpacking(b,this->downHelper);
    doParsimUnpacking(b,this->downGuide);
    doParsimUnpacking(b,this->upHelper);
    doParsimUnpacking(b,this->upGuide);
}

unsigned int AODVRREP::getPacketType() const
{
    return this->packetType;
}

void AODVRREP::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

unsigned int AODVRREP::getHopCount() const
{
    return this->hopCount;
}

void AODVRREP::setHopCount(unsigned int hopCount)
{
    this->hopCount = hopCount;
}

unsigned int AODVRREP::getSeq() const
{
    return this->seq;
}

void AODVRREP::setSeq(unsigned int seq)
{
    this->seq = seq;
}

RestorePath& AODVRREP::getDownHelper()
{
    return this->downHelper;
}

void AODVRREP::setDownHelper(const RestorePath& downHelper)
{
    this->downHelper = downHelper;
}

unsigned int AODVRREP::getDownGuide() const
{
    return this->downGuide;
}

void AODVRREP::setDownGuide(unsigned int downGuide)
{
    this->downGuide = downGuide;
}

RestorePath& AODVRREP::getUpHelper()
{
    return this->upHelper;
}

void AODVRREP::setUpHelper(const RestorePath& upHelper)
{
    this->upHelper = upHelper;
}

unsigned int AODVRREP::getUpGuide() const
{
    return this->upGuide;
}

void AODVRREP::setUpGuide(unsigned int upGuide)
{
    this->upGuide = upGuide;
}

class AODVRREPDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AODVRREPDescriptor();
    virtual ~AODVRREPDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AODVRREPDescriptor);

AODVRREPDescriptor::AODVRREPDescriptor() : omnetpp::cClassDescriptor("AODVRREP", "MyPacket")
{
    propertynames = nullptr;
}

AODVRREPDescriptor::~AODVRREPDescriptor()
{
    delete[] propertynames;
}

bool AODVRREPDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AODVRREP *>(obj)!=nullptr;
}

const char **AODVRREPDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AODVRREPDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AODVRREPDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int AODVRREPDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *AODVRREPDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
        "hopCount",
        "seq",
        "downHelper",
        "downGuide",
        "upHelper",
        "upGuide",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int AODVRREPDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "seq")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "downHelper")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "downGuide")==0) return base+4;
    if (fieldName[0]=='u' && strcmp(fieldName, "upHelper")==0) return base+5;
    if (fieldName[0]=='u' && strcmp(fieldName, "upGuide")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AODVRREPDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "RestorePath",
        "unsigned int",
        "RestorePath",
        "unsigned int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **AODVRREPDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AODVRREPDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AODVRREPDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AODVRREP *pp = (AODVRREP *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string AODVRREPDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVRREP *pp = (AODVRREP *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return ulong2string(pp->getHopCount());
        case 2: return ulong2string(pp->getSeq());
        case 3: {std::stringstream out; out << pp->getDownHelper(); return out.str();}
        case 4: return ulong2string(pp->getDownGuide());
        case 5: {std::stringstream out; out << pp->getUpHelper(); return out.str();}
        case 6: return ulong2string(pp->getUpGuide());
        default: return "";
    }
}

bool AODVRREPDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AODVRREP *pp = (AODVRREP *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setHopCount(string2ulong(value)); return true;
        case 2: pp->setSeq(string2ulong(value)); return true;
        case 4: pp->setDownGuide(string2ulong(value)); return true;
        case 6: pp->setUpGuide(string2ulong(value)); return true;
        default: return false;
    }
}

const char *AODVRREPDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: return omnetpp::opp_typename(typeid(RestorePath));
        case 5: return omnetpp::opp_typename(typeid(RestorePath));
        default: return nullptr;
    };
}

void *AODVRREPDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AODVRREP *pp = (AODVRREP *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getDownHelper()); break;
        case 5: return (void *)(&pp->getUpHelper()); break;
        default: return nullptr;
    }
}

Register_Class(AODVDATA);

AODVDATA::AODVDATA(const char *name) : ::MyPacket(name)
{
    this->packetType = RREQ;
    this->hopCount = 0;
    this->destNode = 0;
}

AODVDATA::AODVDATA(const AODVDATA& other) : ::MyPacket(other)
{
    copy(other);
}

AODVDATA::~AODVDATA()
{
}

AODVDATA& AODVDATA::operator=(const AODVDATA& other)
{
    if (this==&other) return *this;
    ::MyPacket::operator=(other);
    copy(other);
    return *this;
}

void AODVDATA::copy(const AODVDATA& other)
{
    this->packetType = other.packetType;
    this->hopCount = other.hopCount;
    this->destNode = other.destNode;
    this->table_prior = other.table_prior;
}

void AODVDATA::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MyPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->destNode);
    doParsimPacking(b,this->table_prior);
}

void AODVDATA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MyPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->destNode);
    doParsimUnpacking(b,this->table_prior);
}

unsigned int AODVDATA::getPacketType() const
{
    return this->packetType;
}

void AODVDATA::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

unsigned int AODVDATA::getHopCount() const
{
    return this->hopCount;
}

void AODVDATA::setHopCount(unsigned int hopCount)
{
    this->hopCount = hopCount;
}

unsigned int AODVDATA::getDestNode() const
{
    return this->destNode;
}

void AODVDATA::setDestNode(unsigned int destNode)
{
    this->destNode = destNode;
}

RestorePath& AODVDATA::getTable_prior()
{
    return this->table_prior;
}

void AODVDATA::setTable_prior(const RestorePath& table_prior)
{
    this->table_prior = table_prior;
}

class AODVDATADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AODVDATADescriptor();
    virtual ~AODVDATADescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AODVDATADescriptor);

AODVDATADescriptor::AODVDATADescriptor() : omnetpp::cClassDescriptor("AODVDATA", "MyPacket")
{
    propertynames = nullptr;
}

AODVDATADescriptor::~AODVDATADescriptor()
{
    delete[] propertynames;
}

bool AODVDATADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AODVDATA *>(obj)!=nullptr;
}

const char **AODVDATADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AODVDATADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AODVDATADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int AODVDATADescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *AODVDATADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
        "hopCount",
        "destNode",
        "table_prior",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int AODVDATADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destNode")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "table_prior")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AODVDATADescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "RestorePath",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **AODVDATADescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AODVDATADescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AODVDATADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AODVDATA *pp = (AODVDATA *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string AODVDATADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVDATA *pp = (AODVDATA *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return ulong2string(pp->getHopCount());
        case 2: return ulong2string(pp->getDestNode());
        case 3: {std::stringstream out; out << pp->getTable_prior(); return out.str();}
        default: return "";
    }
}

bool AODVDATADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AODVDATA *pp = (AODVDATA *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setHopCount(string2ulong(value)); return true;
        case 2: pp->setDestNode(string2ulong(value)); return true;
        default: return false;
    }
}

const char *AODVDATADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: return omnetpp::opp_typename(typeid(RestorePath));
        default: return nullptr;
    };
}

void *AODVDATADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AODVDATA *pp = (AODVDATA *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getTable_prior()); break;
        default: return nullptr;
    }
}

Register_Class(AODVDATAACK);

AODVDATAACK::AODVDATAACK(const char *name) : ::MyPacket(name)
{
    this->AckType = dataACK;
}

AODVDATAACK::AODVDATAACK(const AODVDATAACK& other) : ::MyPacket(other)
{
    copy(other);
}

AODVDATAACK::~AODVDATAACK()
{
}

AODVDATAACK& AODVDATAACK::operator=(const AODVDATAACK& other)
{
    if (this==&other) return *this;
    ::MyPacket::operator=(other);
    copy(other);
    return *this;
}

void AODVDATAACK::copy(const AODVDATAACK& other)
{
    this->AckType = other.AckType;
}

void AODVDATAACK::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MyPacket::parsimPack(b);
    doParsimPacking(b,this->AckType);
}

void AODVDATAACK::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MyPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->AckType);
}

unsigned int AODVDATAACK::getAckType() const
{
    return this->AckType;
}

void AODVDATAACK::setAckType(unsigned int AckType)
{
    this->AckType = AckType;
}

class AODVDATAACKDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AODVDATAACKDescriptor();
    virtual ~AODVDATAACKDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AODVDATAACKDescriptor);

AODVDATAACKDescriptor::AODVDATAACKDescriptor() : omnetpp::cClassDescriptor("AODVDATAACK", "MyPacket")
{
    propertynames = nullptr;
}

AODVDATAACKDescriptor::~AODVDATAACKDescriptor()
{
    delete[] propertynames;
}

bool AODVDATAACKDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AODVDATAACK *>(obj)!=nullptr;
}

const char **AODVDATAACKDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AODVDATAACKDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AODVDATAACKDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int AODVDATAACKDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *AODVDATAACKDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "AckType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int AODVDATAACKDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='A' && strcmp(fieldName, "AckType")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AODVDATAACKDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **AODVDATAACKDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AODVDATAACKDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AODVDATAACKDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AODVDATAACK *pp = (AODVDATAACK *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string AODVDATAACKDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AODVDATAACK *pp = (AODVDATAACK *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getAckType());
        default: return "";
    }
}

bool AODVDATAACKDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AODVDATAACK *pp = (AODVDATAACK *)object; (void)pp;
    switch (field) {
        case 0: pp->setAckType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *AODVDATAACKDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *AODVDATAACKDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AODVDATAACK *pp = (AODVDATAACK *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UPDATEDATA);

UPDATEDATA::UPDATEDATA(const char *name) : ::MyPacket(name)
{
    this->packetType = UPDATE;
    this->hopCount = 0;
    this->seq = 0;
    this->destNode = 0;
}

UPDATEDATA::UPDATEDATA(const UPDATEDATA& other) : ::MyPacket(other)
{
    copy(other);
}

UPDATEDATA::~UPDATEDATA()
{
}

UPDATEDATA& UPDATEDATA::operator=(const UPDATEDATA& other)
{
    if (this==&other) return *this;
    ::MyPacket::operator=(other);
    copy(other);
    return *this;
}

void UPDATEDATA::copy(const UPDATEDATA& other)
{
    this->packetType = other.packetType;
    this->hopCount = other.hopCount;
    this->seq = other.seq;
    this->destNode = other.destNode;
}

void UPDATEDATA::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MyPacket::parsimPack(b);
    doParsimPacking(b,this->packetType);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->seq);
    doParsimPacking(b,this->destNode);
}

void UPDATEDATA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MyPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->packetType);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->seq);
    doParsimUnpacking(b,this->destNode);
}

unsigned int UPDATEDATA::getPacketType() const
{
    return this->packetType;
}

void UPDATEDATA::setPacketType(unsigned int packetType)
{
    this->packetType = packetType;
}

unsigned int UPDATEDATA::getHopCount() const
{
    return this->hopCount;
}

void UPDATEDATA::setHopCount(unsigned int hopCount)
{
    this->hopCount = hopCount;
}

unsigned int UPDATEDATA::getSeq() const
{
    return this->seq;
}

void UPDATEDATA::setSeq(unsigned int seq)
{
    this->seq = seq;
}

unsigned int UPDATEDATA::getDestNode() const
{
    return this->destNode;
}

void UPDATEDATA::setDestNode(unsigned int destNode)
{
    this->destNode = destNode;
}

class UPDATEDATADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UPDATEDATADescriptor();
    virtual ~UPDATEDATADescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(UPDATEDATADescriptor);

UPDATEDATADescriptor::UPDATEDATADescriptor() : omnetpp::cClassDescriptor("UPDATEDATA", "MyPacket")
{
    propertynames = nullptr;
}

UPDATEDATADescriptor::~UPDATEDATADescriptor()
{
    delete[] propertynames;
}

bool UPDATEDATADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UPDATEDATA *>(obj)!=nullptr;
}

const char **UPDATEDATADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UPDATEDATADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UPDATEDATADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int UPDATEDATADescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *UPDATEDATADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "packetType",
        "hopCount",
        "seq",
        "destNode",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int UPDATEDATADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetType")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "seq")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destNode")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UPDATEDATADescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **UPDATEDATADescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *UPDATEDATADescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int UPDATEDATADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UPDATEDATA *pp = (UPDATEDATA *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UPDATEDATADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UPDATEDATA *pp = (UPDATEDATA *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPacketType());
        case 1: return ulong2string(pp->getHopCount());
        case 2: return ulong2string(pp->getSeq());
        case 3: return ulong2string(pp->getDestNode());
        default: return "";
    }
}

bool UPDATEDATADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UPDATEDATA *pp = (UPDATEDATA *)object; (void)pp;
    switch (field) {
        case 0: pp->setPacketType(string2ulong(value)); return true;
        case 1: pp->setHopCount(string2ulong(value)); return true;
        case 2: pp->setSeq(string2ulong(value)); return true;
        case 3: pp->setDestNode(string2ulong(value)); return true;
        default: return false;
    }
}

const char *UPDATEDATADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *UPDATEDATADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UPDATEDATA *pp = (UPDATEDATA *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UPDATEACK);

UPDATEACK::UPDATEACK(const char *name) : ::MyPacket(name)
{
    this->AckType = updateACK;
}

UPDATEACK::UPDATEACK(const UPDATEACK& other) : ::MyPacket(other)
{
    copy(other);
}

UPDATEACK::~UPDATEACK()
{
}

UPDATEACK& UPDATEACK::operator=(const UPDATEACK& other)
{
    if (this==&other) return *this;
    ::MyPacket::operator=(other);
    copy(other);
    return *this;
}

void UPDATEACK::copy(const UPDATEACK& other)
{
    this->AckType = other.AckType;
    this->neighborset = other.neighborset;
}

void UPDATEACK::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MyPacket::parsimPack(b);
    doParsimPacking(b,this->AckType);
    doParsimPacking(b,this->neighborset);
}

void UPDATEACK::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MyPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->AckType);
    doParsimUnpacking(b,this->neighborset);
}

unsigned int UPDATEACK::getAckType() const
{
    return this->AckType;
}

void UPDATEACK::setAckType(unsigned int AckType)
{
    this->AckType = AckType;
}

NeighborSet& UPDATEACK::getNeighborset()
{
    return this->neighborset;
}

void UPDATEACK::setNeighborset(const NeighborSet& neighborset)
{
    this->neighborset = neighborset;
}

class UPDATEACKDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UPDATEACKDescriptor();
    virtual ~UPDATEACKDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(UPDATEACKDescriptor);

UPDATEACKDescriptor::UPDATEACKDescriptor() : omnetpp::cClassDescriptor("UPDATEACK", "MyPacket")
{
    propertynames = nullptr;
}

UPDATEACKDescriptor::~UPDATEACKDescriptor()
{
    delete[] propertynames;
}

bool UPDATEACKDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UPDATEACK *>(obj)!=nullptr;
}

const char **UPDATEACKDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UPDATEACKDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UPDATEACKDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int UPDATEACKDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *UPDATEACKDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "AckType",
        "neighborset",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int UPDATEACKDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='A' && strcmp(fieldName, "AckType")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighborset")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UPDATEACKDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "NeighborSet",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **UPDATEACKDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *UPDATEACKDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int UPDATEACKDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UPDATEACK *pp = (UPDATEACK *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UPDATEACKDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UPDATEACK *pp = (UPDATEACK *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getAckType());
        case 1: {std::stringstream out; out << pp->getNeighborset(); return out.str();}
        default: return "";
    }
}

bool UPDATEACKDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UPDATEACK *pp = (UPDATEACK *)object; (void)pp;
    switch (field) {
        case 0: pp->setAckType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *UPDATEACKDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(NeighborSet));
        default: return nullptr;
    };
}

void *UPDATEACKDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UPDATEACK *pp = (UPDATEACK *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getNeighborset()); break;
        default: return nullptr;
    }
}



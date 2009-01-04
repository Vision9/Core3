/*
 *	server/zone/objects/tangible/deed/harvesterdeed/HarvesterDeed.h generated by engine3 IDL compiler 0.55
 */

#ifndef HARVESTERDEED_H_
#define HARVESTERDEED_H_

#include "engine/orb/DistributedObjectBroker.h"

class DeedObject;

class HarvesterObject;

class TangibleObject;

class packets;

class Player;

class CreatureObject;

#include "../DeedObject.h"

class HarvesterDeed : public DeedObject {
public:
	HarvesterDeed(CreatureObject* creature, int tempCRC, const UnicodeString& n, const String& tempn);

	HarvesterDeed(unsigned long long oid, int tempCRC, const UnicodeString& n, const String& tempn);

	HarvesterDeed(CreatureObject* creature, HarvesterObject* hino);

	void parseItemAttributes();

	void setSurplusMaintenance(int maint);

	void setMaintenanceRate(float rate);

	void setSurplusPower(int pow);

	void setPowerRate(float rate);

	void setExtractionRate(float rate);

	void setHopperSize(float size);

	void setLotSize(int size);

	int getSurplusMaintenance();

	float getMaintenanceRate();

	int getSurplusPower();

	float getPowerRate();

	float getExtractionRate();

	float getHopperSize();

	int getLotSize();

protected:
	HarvesterDeed(DummyConstructorParameter* param);

	virtual ~HarvesterDeed();

	friend class HarvesterDeedHelper;
};

class HarvesterDeedImplementation;

class HarvesterDeedAdapter : public DeedObjectAdapter {
public:
	HarvesterDeedAdapter(HarvesterDeedImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void parseItemAttributes();

	void setSurplusMaintenance(int maint);

	void setMaintenanceRate(float rate);

	void setSurplusPower(int pow);

	void setPowerRate(float rate);

	void setExtractionRate(float rate);

	void setHopperSize(float size);

	void setLotSize(int size);

	int getSurplusMaintenance();

	float getMaintenanceRate();

	int getSurplusPower();

	float getPowerRate();

	float getExtractionRate();

	float getHopperSize();

	int getLotSize();

};

class HarvesterDeedHelper : public DistributedObjectClassHelper, public Singleton<HarvesterDeedHelper> {
	static HarvesterDeedHelper* staticInitializer;

public:
	HarvesterDeedHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<HarvesterDeedHelper>;
};

#include "../DeedObjectImplementation.h"

class HarvesterDeedServant : public DeedObjectImplementation {
public:
	HarvesterDeed* _this;

public:
	HarvesterDeedServant(CreatureObject* creature, int tempCRC, const UnicodeString& n, const String& tempn, int tp);
	HarvesterDeedServant(unsigned long long oid, int tempCRC, const UnicodeString& n, const String& tempn, int tp);
	HarvesterDeedServant(unsigned long long oid, int tp);
	virtual ~HarvesterDeedServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*HARVESTERDEED_H_*/

/*
 *	server/zone/objects/installation/bank/BankInstallation.cpp generated by engine3 IDL compiler 0.60
 */

#include "BankInstallation.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/Zone.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/tangible/terminal/bank/BankTerminal.h"

/*
 *	BankInstallationStub
 */

BankInstallation::BankInstallation() : InstallationObject(DummyConstructorParameter::instance()) {
	_impl = new BankInstallationImplementation();
	_impl->_setStub(this);
}

BankInstallation::BankInstallation(DummyConstructorParameter* param) : InstallationObject(param) {
}

BankInstallation::~BankInstallation() {
}


void BankInstallation::insertToZone(Zone* zone) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(zone);

		method.executeWithVoidReturn();
	} else
		((BankInstallationImplementation*) _impl)->insertToZone(zone);
}

void BankInstallation::spawnBankObjects() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		((BankInstallationImplementation*) _impl)->spawnBankObjects();
}

/*
 *	BankInstallationImplementation
 */

BankInstallationImplementation::BankInstallationImplementation(DummyConstructorParameter* param) : InstallationObjectImplementation(param) {
	_initializeImplementation();
}

BankInstallationImplementation::~BankInstallationImplementation() {
}


void BankInstallationImplementation::finalize() {
}

void BankInstallationImplementation::_initializeImplementation() {
	_setClassHelper(BankInstallationHelper::instance());

	_serializationHelperMethod();
}

void BankInstallationImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (BankInstallation*) stub;
	InstallationObjectImplementation::_setStub(stub);
}

DistributedObjectStub* BankInstallationImplementation::_getStub() {
	return _this;
}

BankInstallationImplementation::operator const BankInstallation*() {
	return _this;
}

void BankInstallationImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void BankInstallationImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void BankInstallationImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void BankInstallationImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void BankInstallationImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void BankInstallationImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void BankInstallationImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void BankInstallationImplementation::_serializationHelperMethod() {
	InstallationObjectImplementation::_serializationHelperMethod();

	_setClassName("BankInstallation");

	addSerializableVariable("banks", &banks);
}

BankInstallationImplementation::BankInstallationImplementation() {
	_initializeImplementation();
	// server/zone/objects/installation/bank/BankInstallation.idl(67):  		setLoggingName("BankInstallation");
	setLoggingName("BankInstallation");
}

void BankInstallationImplementation::insertToZone(Zone* zone) {
	// server/zone/objects/installation/bank/BankInstallation.idl(77):  		super.insertToZone(zone);
	InstallationObjectImplementation::insertToZone(zone);
	// server/zone/objects/installation/bank/BankInstallation.idl(79):  		spawnBankObjects();
	spawnBankObjects();
}

/*
 *	BankInstallationAdapter
 */

BankInstallationAdapter::BankInstallationAdapter(BankInstallationImplementation* obj) : InstallationObjectAdapter(obj) {
}

Packet* BankInstallationAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		insertToZone((Zone*) inv->getObjectParameter());
		break;
	case 7:
		spawnBankObjects();
		break;
	default:
		return NULL;
	}

	return resp;
}

void BankInstallationAdapter::insertToZone(Zone* zone) {
	((BankInstallationImplementation*) impl)->insertToZone(zone);
}

void BankInstallationAdapter::spawnBankObjects() {
	((BankInstallationImplementation*) impl)->spawnBankObjects();
}

/*
 *	BankInstallationHelper
 */

BankInstallationHelper* BankInstallationHelper::staticInitializer = BankInstallationHelper::instance();

BankInstallationHelper::BankInstallationHelper() {
	className = "BankInstallation";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void BankInstallationHelper::finalizeHelper() {
	BankInstallationHelper::finalize();
}

DistributedObject* BankInstallationHelper::instantiateObject() {
	return new BankInstallation(DummyConstructorParameter::instance());
}

DistributedObjectServant* BankInstallationHelper::instantiateServant() {
	return new BankInstallationImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* BankInstallationHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new BankInstallationAdapter((BankInstallationImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}


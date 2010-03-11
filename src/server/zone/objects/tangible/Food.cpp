/*
 *	server/zone/objects/tangible/Food.cpp generated by engine3 IDL compiler 0.60
 */

#include "Food.h"

#include "server/zone/objects/scene/SceneObject.h"

/*
 *	FoodStub
 */

Food::Food() : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new FoodImplementation();
	_impl->_setStub(this);
}

Food::Food(DummyConstructorParameter* param) : TangibleObject(param) {
}

Food::~Food() {
}


void Food::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((FoodImplementation*) _impl)->initializeTransientMembers();
}

/*
 *	FoodImplementation
 */

FoodImplementation::FoodImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}

FoodImplementation::~FoodImplementation() {
}


void FoodImplementation::finalize() {
}

void FoodImplementation::_initializeImplementation() {
	_setClassHelper(FoodHelper::instance());

	_serializationHelperMethod();
}

void FoodImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Food*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* FoodImplementation::_getStub() {
	return _this;
}

FoodImplementation::operator const Food*() {
	return _this;
}

void FoodImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void FoodImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void FoodImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void FoodImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void FoodImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void FoodImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void FoodImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void FoodImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("Food");

}

FoodImplementation::FoodImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/Food.idl(53):  		Logger.setLoggingName("Food");
	Logger::setLoggingName("Food");
}

void FoodImplementation::initializeTransientMembers() {
	// server/zone/objects/tangible/Food.idl(57):  		super.initializeTransientMembers();
	TangibleObjectImplementation::initializeTransientMembers();
	// server/zone/objects/tangible/Food.idl(59):  		Logger.setLoggingName("Food");
	Logger::setLoggingName("Food");
}

/*
 *	FoodAdapter
 */

FoodAdapter::FoodAdapter(FoodImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* FoodAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	default:
		return NULL;
	}

	return resp;
}

void FoodAdapter::initializeTransientMembers() {
	((FoodImplementation*) impl)->initializeTransientMembers();
}

/*
 *	FoodHelper
 */

FoodHelper* FoodHelper::staticInitializer = FoodHelper::instance();

FoodHelper::FoodHelper() {
	className = "Food";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void FoodHelper::finalizeHelper() {
	FoodHelper::finalize();
}

DistributedObject* FoodHelper::instantiateObject() {
	return new Food(DummyConstructorParameter::instance());
}

DistributedObjectServant* FoodHelper::instantiateServant() {
	return new FoodImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* FoodHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new FoodAdapter((FoodImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}


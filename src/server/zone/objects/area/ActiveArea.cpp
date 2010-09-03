/*
 *	server/zone/objects/area/ActiveArea.cpp generated by engine3 IDL compiler 0.60
 */

#include "ActiveArea.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/area/ActiveAreaEvent.h"

/*
 *	ActiveAreaStub
 */

ActiveArea::ActiveArea() : SceneObject(DummyConstructorParameter::instance()) {
	_impl = new ActiveAreaImplementation();
	_impl->_setStub(this);
}

ActiveArea::ActiveArea(DummyConstructorParameter* param) : SceneObject(param) {
}

ActiveArea::~ActiveArea() {
}


void ActiveArea::sendTo(SceneObject* player, bool doClose) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);
		method.addBooleanParameter(doClose);

		method.executeWithVoidReturn();
	} else
		((ActiveAreaImplementation*) _impl)->sendTo(player, doClose);
}

void ActiveArea::enqueueEnterEvent(SceneObject* obj) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		((ActiveAreaImplementation*) _impl)->enqueueEnterEvent(obj);
}

void ActiveArea::enqueueExitEvent(SceneObject* obj) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		((ActiveAreaImplementation*) _impl)->enqueueExitEvent(obj);
}

void ActiveArea::notifyEnter(SceneObject* object) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else
		((ActiveAreaImplementation*) _impl)->notifyEnter(object);
}

void ActiveArea::notifyExit(SceneObject* object) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else
		((ActiveAreaImplementation*) _impl)->notifyExit(object);
}

bool ActiveArea::isRegion() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithBooleanReturn();
	} else
		return ((ActiveAreaImplementation*) _impl)->isRegion();
}

bool ActiveArea::containsPoint(float x, float y) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addFloatParameter(x);
		method.addFloatParameter(y);

		return method.executeWithBooleanReturn();
	} else
		return ((ActiveAreaImplementation*) _impl)->containsPoint(x, y);
}

void ActiveArea::notifyPositionUpdate(QuadTreeEntry* obj) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((ActiveAreaImplementation*) _impl)->notifyPositionUpdate(obj);
}

void ActiveArea::notifyInsert(QuadTreeEntry* entry) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((ActiveAreaImplementation*) _impl)->notifyInsert(entry);
}

void ActiveArea::notifyDissapear(QuadTreeEntry* entry) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((ActiveAreaImplementation*) _impl)->notifyDissapear(entry);
}

float ActiveArea::getRadius() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithFloatReturn();
	} else
		return ((ActiveAreaImplementation*) _impl)->getRadius();
}

void ActiveArea::setRadius(float r) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addFloatParameter(r);

		method.executeWithVoidReturn();
	} else
		((ActiveAreaImplementation*) _impl)->setRadius(r);
}

/*
 *	ActiveAreaImplementation
 */

ActiveAreaImplementation::ActiveAreaImplementation(DummyConstructorParameter* param) : SceneObjectImplementation(param) {
	_initializeImplementation();
}

ActiveAreaImplementation::~ActiveAreaImplementation() {
}


void ActiveAreaImplementation::finalize() {
}

void ActiveAreaImplementation::_initializeImplementation() {
	_setClassHelper(ActiveAreaHelper::instance());

	_serializationHelperMethod();
}

void ActiveAreaImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ActiveArea*) stub;
	SceneObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ActiveAreaImplementation::_getStub() {
	return _this;
}

ActiveAreaImplementation::operator const ActiveArea*() {
	return _this;
}

void ActiveAreaImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ActiveAreaImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ActiveAreaImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ActiveAreaImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ActiveAreaImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ActiveAreaImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ActiveAreaImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ActiveAreaImplementation::_serializationHelperMethod() {
	SceneObjectImplementation::_serializationHelperMethod();

	_setClassName("ActiveArea");

	addSerializableVariable("radius", &radius);
	addSerializableVariable("radius2", &radius2);
}

ActiveAreaImplementation::ActiveAreaImplementation() {
	_initializeImplementation();
	// server/zone/objects/area/ActiveArea.idl(57):  		radius = 0;
	radius = 0;
	// server/zone/objects/area/ActiveArea.idl(58):  		radius2 = 0;
	radius2 = 0;
	// server/zone/objects/area/ActiveArea.idl(60):  		Logger.setLoggingName("ActiveArea");
	Logger::setLoggingName("ActiveArea");
}

void ActiveAreaImplementation::sendTo(SceneObject* player, bool doClose) {
}

void ActiveAreaImplementation::notifyEnter(SceneObject* object) {
}

void ActiveAreaImplementation::notifyExit(SceneObject* object) {
}

bool ActiveAreaImplementation::isRegion() {
	// server/zone/objects/area/ActiveArea.idl(86):  		return false;
	return false;
}

void ActiveAreaImplementation::notifyInsert(QuadTreeEntry* entry) {
	// server/zone/objects/area/ActiveArea.idl(96):  		notifyPositionUpdate(entry);
	notifyPositionUpdate(entry);
}

float ActiveAreaImplementation::getRadius() {
	// server/zone/objects/area/ActiveArea.idl(103):  		return radius;
	return radius;
}

void ActiveAreaImplementation::setRadius(float r) {
	// server/zone/objects/area/ActiveArea.idl(107):  		radius = r;
	radius = r;
	// server/zone/objects/area/ActiveArea.idl(108):  		radius2 = r * r;
	radius2 = r * r;
}

/*
 *	ActiveAreaAdapter
 */

ActiveAreaAdapter::ActiveAreaAdapter(ActiveAreaImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* ActiveAreaAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendTo((SceneObject*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 7:
		enqueueEnterEvent((SceneObject*) inv->getObjectParameter());
		break;
	case 8:
		enqueueExitEvent((SceneObject*) inv->getObjectParameter());
		break;
	case 9:
		notifyEnter((SceneObject*) inv->getObjectParameter());
		break;
	case 10:
		notifyExit((SceneObject*) inv->getObjectParameter());
		break;
	case 11:
		resp->insertBoolean(isRegion());
		break;
	case 12:
		resp->insertBoolean(containsPoint(inv->getFloatParameter(), inv->getFloatParameter()));
		break;
	case 13:
		resp->insertFloat(getRadius());
		break;
	case 14:
		setRadius(inv->getFloatParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ActiveAreaAdapter::sendTo(SceneObject* player, bool doClose) {
	((ActiveAreaImplementation*) impl)->sendTo(player, doClose);
}

void ActiveAreaAdapter::enqueueEnterEvent(SceneObject* obj) {
	((ActiveAreaImplementation*) impl)->enqueueEnterEvent(obj);
}

void ActiveAreaAdapter::enqueueExitEvent(SceneObject* obj) {
	((ActiveAreaImplementation*) impl)->enqueueExitEvent(obj);
}

void ActiveAreaAdapter::notifyEnter(SceneObject* object) {
	((ActiveAreaImplementation*) impl)->notifyEnter(object);
}

void ActiveAreaAdapter::notifyExit(SceneObject* object) {
	((ActiveAreaImplementation*) impl)->notifyExit(object);
}

bool ActiveAreaAdapter::isRegion() {
	return ((ActiveAreaImplementation*) impl)->isRegion();
}

bool ActiveAreaAdapter::containsPoint(float x, float y) {
	return ((ActiveAreaImplementation*) impl)->containsPoint(x, y);
}

float ActiveAreaAdapter::getRadius() {
	return ((ActiveAreaImplementation*) impl)->getRadius();
}

void ActiveAreaAdapter::setRadius(float r) {
	((ActiveAreaImplementation*) impl)->setRadius(r);
}

/*
 *	ActiveAreaHelper
 */

ActiveAreaHelper* ActiveAreaHelper::staticInitializer = ActiveAreaHelper::instance();

ActiveAreaHelper::ActiveAreaHelper() {
	className = "ActiveArea";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ActiveAreaHelper::finalizeHelper() {
	ActiveAreaHelper::finalize();
}

DistributedObject* ActiveAreaHelper::instantiateObject() {
	return new ActiveArea(DummyConstructorParameter::instance());
}

DistributedObjectServant* ActiveAreaHelper::instantiateServant() {
	return new ActiveAreaImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ActiveAreaHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ActiveAreaAdapter((ActiveAreaImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}


//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2015 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#ifndef WITH_OSG
#include <omnetpp.h>

// fallbac code used in case OpenSceneGraph and osgEarth is not present on the system
using namespace omnetpp;

class UAVNode : public cSimpleModule
{
  protected:
    virtual void initialize() { throw cRuntimeError("This example requires OpenSceneGraph and osgEarth installed"); }
    virtual void handleMessage(cMessage *msg) {};
};

Define_Module(UAVNode);

class OsgEarthScene : public cSimpleModule
{
  protected:
    virtual void initialize() { throw cRuntimeError("This example requires OpenSceneGraph and osgEarth installed"); }
    virtual void handleMessage(cMessage *msg) {};
};

Define_Module(OsgEarthScene);

class MobileNode : public cSimpleModule
{
  protected:
    virtual void initialize() { throw cRuntimeError("This example requires OpenSceneGraph and osgEarth installed"); }
    virtual void handleMessage(cMessage *msg) {};
};

Define_Module(MobileNode);

class ChannelController : public cSimpleModule
{
  protected:
    virtual void initialize() { throw cRuntimeError("This example requires OpenSceneGraph and osgEarth installed"); }
    virtual void handleMessage(cMessage *msg) {};
};

Define_Module(ChannelController);

#endif // WITH_OSG
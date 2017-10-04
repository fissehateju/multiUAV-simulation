//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#ifndef CHARGINGNODE_H_
#define CHARGINGNODE_H_

#include <omnetpp.h>
#include "GenericNode.h"
#include "Battery.h"

using namespace omnetpp;

class ChargingNode : public GenericNode {
protected:
    unsigned int spotsWaiting;
    unsigned int spotsCharging;
    // review weather vector is the best construct for "queues"
    std::vector<MobileNode*> objectsWaiting;
    std::vector<MobileNode*> objectsCharging;
    double chargingCurrent;
public:
    ChargingNode();
    virtual ~ChargingNode();
    virtual void selectNextCommand() override;
    virtual void initializeState() override;
    virtual void loadCommands(CommandQueue commands) override;
    virtual void clearCommands() override;
    virtual void updateState() override;
    virtual bool commandCompleted() override;
    virtual double nextNeededUpdate() override;
    virtual ReplacementData* endOfOperation() override;
protected:
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void refreshDisplay() const override;
    virtual void appendToObjectsWaiting(MobileNode* module);
    virtual void fillSpots();
    virtual void charge();
    virtual float calculateChargeAmount(Battery battery, double seconds);
    virtual float calculateChargeAmountLinear(double seconds);
    virtual double calculateMaximumChargeTimeLinear(Battery battery);
    virtual float calculateChargeAmountNonLinear(double seconds);
    virtual simtime_t timeWhenDone(Battery battery);
    virtual simtime_t timeWhenDone(Battery battery, double targetCapacityPercentage);
};

#endif /* CHARGINGNODE_H_ */

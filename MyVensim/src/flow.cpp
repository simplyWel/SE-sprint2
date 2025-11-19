#include "flow.h"
#include "system.h"

Flow::Flow() : source(nullptr), target(nullptr) {}

Flow::Flow(const Flow& other) {
    source = other.source;
    target = other.target;
}

Flow::~Flow() {}

double Flow::equation() {return 0.0;}

void Flow::setSource(System* s) {source = s;}

void Flow::setTarget(System* t) {target = t;}

System* Flow::getSource() const {return source;}

System* Flow::getTarget() const {return target;}

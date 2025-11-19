#include "system.h"

System::System(double v) : value(v) {}

System::System(const System& other) : value(other.value) {}

System::~System() {}

void System::setValue(double v) {value = v;}

double System::getValue() const {return value;}

void System::addValue(double ad) {value += ad;}

const System& System::operator=(const System& other) {
    if (this != &other) {          
        setValue(other.getValue());
    }
    return *this;                  
}
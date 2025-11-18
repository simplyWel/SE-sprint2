#include "system.h"

System::System() : value(0.0), valueNext(0.0) {}

System::~System() {}

void System::setValue(double v) {value = v;}

double System::getValue() const {return value;}

void System::setValueNext(double v) {valueNext = v;}

double System::getValueNext() const {return valueNext;}

void System::commit() {value = valueNext;}

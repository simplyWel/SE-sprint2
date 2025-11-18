#include "model.h"
#include "system.h"
#include "flow.h"
#include <iostream>

int main(){
    Model m;
    System s1, s2;
    Flow f;
    s1.setValue(10);
    m.add(&s1);
    m.add(&s2);
    m.add(&f);
    f.setSource(&s1);
    f.setTarget(&s2);
    m.run(0,10);
    m.report();
    return 0;
}
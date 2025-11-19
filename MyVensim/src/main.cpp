#include "model.h"
#include "system.h"
#include "flow.h"
#include <iostream>

class Flow1 : public Flow {
public:
    double equation() override { return 0.01 * source->getValue(); }
};

int main(){
    System q1(100.0);
    System q2(0.0);
    System q3(0.0);
    System q4(0.0);
    System q5(0.0);

    Flow1 f1; f1.setSource(&q1); f1.setTarget(&q2);
    Flow1 f2; f2.setSource(&q2); f2.setTarget(&q3);
    Flow1 f3; f3.setSource(&q3); f3.setTarget(&q4);
    Flow1 f4; f4.setSource(&q4); f4.setTarget(&q1);
    Flow1 f5; f5.setSource(&q1); f5.setTarget(&q3);
    Flow1 f6; f6.setSource(&q2); f6.setTarget(&q5);

    Model m;

    m.add(&q1);
    m.add(&q2);
    m.add(&q3);
    m.add(&q4);
    m.add(&q5);

    m.add(&f1); m.add(&f2);
    m.add(&f3); m.add(&f4);
    m.add(&f5); m.add(&f6);

    m.run(0, 100);
    m.report();
    return 0;
}
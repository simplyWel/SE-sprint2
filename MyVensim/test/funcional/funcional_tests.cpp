#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../src/model.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

//test1
class Flow_exp : public Flow {
public:
    double equation() override {
        return 0.1 * getSource()->getValue();
    }
};

void exponentialFuncionalTest() {
    cout << "\nExponential Functional Test\n";

    Model m;
    System pop1, pop2;
    pop1.setValue(10);
    pop2.setValue(0);

    Flow_exp exp;

    m.add(&pop1);
    m.add(&pop2);
    m.add(&exp);

    exp.setSource(&pop1);
    exp.setTarget(&pop2);

    m.run(0, 10);
    m.report();

    double expected_pop1 = 3.4868;
    double expected_pop2 = 6.5132;

    assert(fabs(pop1.getValue() - expected_pop1) < 0.001);
    assert(fabs(pop2.getValue() - expected_pop2) < 0.001);

    cout << "Exponential Functional Test passed!\n";
}

//test2
class Flow_log : public Flow {
public:
    double equation() override {
        double p2 = getTarget()->getValue();
        return 0.01 * p2 * (1 - p2 / 70.0);
    }
};

void logisticalFuncionalTest() {
    cout << "\nLogistical Functional Test\n";

    Model m;
    System p1, p2;
    p1.setValue(10);
    p2.setValue(0);

    Flow_log log;

    m.add(&p1);
    m.add(&p2);
    m.add(&log);

    log.setSource(&p1);
    log.setTarget(&p2);

    m.run(0, 10);
    m.report();

    // valores esperados
    double expected_p1 = 10.0;     
    double expected_p2 = 0.0;      

    assert(fabs(p1.getValue() - expected_p1) < 0.001);
    assert(fabs(p2.getValue() - expected_p2) < 0.001);

    cout << "Logistical Functional Test passed!\n";
}

//test3
class Flow_alt : public Flow {
public:
    double equation() override {
        return 0.01 * getSource()->getValue();
    }
};

void complexFuncionalTest() {
    cout << "\nComplex Functional Test\n";

    Model m;
    System Q1, Q2, Q3, Q4, Q5;

    Q1.setValue(10);
    Q2.setValue(0);
    Q3.setValue(1);
    Q4.setValue(10);
    Q5.setValue(0);

    Flow_alt f, g, t, u, r;

    m.add(&Q1); 
    m.add(&Q2); 
    m.add(&Q3); 
    m.add(&Q4); 
    m.add(&Q5);

    m.add(&f); 
    m.add(&g); 
    m.add(&t); 
    m.add(&u); 
    m.add(&r);

    f.setSource(&Q4); f.setTarget(&Q1);
    g.setSource(&Q1); g.setTarget(&Q3);
    t.setSource(&Q2); t.setTarget(&Q3);
    u.setSource(&Q3); u.setTarget(&Q4);
    r.setSource(&Q2); r.setTarget(&Q5);

    m.run(0, 10);
    m.report();

    double eQ1 = 4.0655;
    double eQ2 = 0.0000;
    double eQ3 = 7.5667;
    double eQ4 = 7.2832;
    double eQ5 = 0.0000;

    assert(fabs(Q1.getValue() - eQ1) < 0.001);
    assert(fabs(Q2.getValue() - eQ2) < 0.001);
    assert(fabs(Q3.getValue() - eQ3) < 0.001);
    assert(fabs(Q4.getValue() - eQ4) < 0.001);
    assert(fabs(Q5.getValue() - eQ5) < 0.001);

    cout << "Complex Functional Test passed!\n";
}

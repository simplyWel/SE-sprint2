#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../src/model.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

class FlowLog : public Flow {
private:
    System* p2;
public:
    FlowLog(System* p2 = nullptr) : Flow(), p2(p2) {}

    double equation() override {
        if (!p2) return 0.0;
        double val = p2->getValue();
        return 0.01 * val * (1 - val / 70.0);
    }
};

class FlowExp : public Flow {
public:
    FlowExp() : Flow() {}
    double equation() override {
        if (!getSource()) return 0.0;
        return 0.1 * getSource()->getValue();
    }
};

class FlowTaxa : public Flow {
private:
    double taxa;
public:
    FlowTaxa(double taxa = 0.01) : Flow(), taxa(taxa) {}

    double equation() override {
        if (!getSource()) return 0.0;
        return taxa * getSource()->getValue();
    }
};

void exponentialFuncionalTest() {
    cout << "\nExponential Functional Test\n";

    Model m;
    System pop1(10.0), pop2(0.0);

    FlowExp exp; // classe definida em src/flow.h

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
    System p1(10.0), p2(0.0);

    FlowLog log;

    m.add(&p1);
    m.add(&p2);
    m.add(&log);

    log.setSource(&p1);
    log.setTarget(&p2);

    m.run(0, 10);
    m.report();

    double expected_p1 = 10.0;
    double expected_p2 = 0.0;

    assert(fabs(p1.getValue() - expected_p1) < 0.001);
    assert(fabs(p2.getValue() - expected_p2) < 0.001);

    cout << "Logistical Functional Test passed!\n";
}

void complexFuncionalTest() {
    cout << "\nComplex Functional Test\n";

    Model m;
    System Q1(100.0), Q2(0.0), Q3(100.0), Q4(0.0), Q5(0.0);

    FlowTaxa f, g, t, u, r;

    m.add(&Q1); m.add(&Q2); m.add(&Q3); m.add(&Q4); m.add(&Q5);
    m.add(&f); m.add(&g); m.add(&t); m.add(&u); m.add(&r);

    f.setSource(&Q4); f.setTarget(&Q1);
    g.setSource(&Q1); g.setTarget(&Q3);
    t.setSource(&Q2); t.setTarget(&Q3);
    u.setSource(&Q3); u.setTarget(&Q4);
    r.setSource(&Q2); r.setTarget(&Q5);

    m.run(0, 100);
    m.report();
    
    assert(fabs(Q1.getValue() - 61.5266) < 0.001);
    assert(fabs(Q2.getValue() -       0) < 0.001);
    assert(fabs(Q3.getValue() -  81.223) < 0.001);
    assert(fabs(Q4.getValue() - 57.2504) < 0.001);
    assert(fabs(Q5.getValue() -       0) < 0.001);

    cout << "Complex Functional Test passed\n\n";
}
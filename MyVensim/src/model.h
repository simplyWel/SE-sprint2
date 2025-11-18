#ifndef MODEL_H
#define MODEL_H

#include <vector>
using namespace std;

class Flow;
class System;

class Model {
private:
    vector<Flow*> flows;
    vector<System*> systems;
public:
    Model();
    ~Model();
    void add(Flow* f);
    void add(System* s);
    void run(int start, int end);
    void report();
};

#endif
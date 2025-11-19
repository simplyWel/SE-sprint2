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
    Model(const Model& model); 
    ~Model();

    const Model& operator=(const Model& model); 
    
    void add(Flow* f);
    void add(System* s);
    void run(int start, int end);
    void report();
};

#endif
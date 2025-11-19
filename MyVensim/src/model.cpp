#include "model.h"
#include "flow.h"
#include "system.h"
#include <iostream>
using namespace std;

Model::Model(){ }

Model::Model(const Model& model) {
    systems = model.systems;
    flows   = model.flows;
}

Model::~Model(){ }

const Model& Model::operator=(const Model& model) {
    if (this != &model) {          
        systems = model.systems;   
        flows   = model.flows;     
    }
    return *this;                  
}

void Model::add(Flow* f){
    flows.push_back(f);
}

void Model::add(System* s){
    systems.push_back(s);
}

void Model::run(int t0, int t1) {
    for (int t = t0; t < t1; ++t) {

        // vetor de deltas – um delta para cada System
        std::vector<double> delta(systems.size(), 0.0);

        // calcula cada fluxo
        for (Flow* f : flows) {
            double amount = f->equation();
            System* s  = f->getSource();
            System* tg = f->getTarget();

            // encontra posição do source e target no vetor de systems
            for (size_t i = 0; i < systems.size(); ++i) {
                if (systems[i] == s) {
                    delta[i] -= amount;
                }
                if (systems[i] == tg) {
                    delta[i] += amount;
                }
            }
        }

        // aplica os deltas simultaneamente
        for (size_t i = 0; i < systems.size(); ++i) {
            systems[i]->addValue(delta[i]);
        }
    }
}

void Model::report() {
    cout << "Systems: [ ";
    for (System* s : systems) {
        cout << s->getValue() << " ";
    }
    cout << "]\n";
}

#include "model.h"
#include "flow.h"
#include "system.h"
#include <iostream>
using namespace std;

Model::Model(){ }

Model::~Model(){ }

void Model::add(Flow* f){
    flows.push_back(f);
}

void Model::add(System* s){
    systems.push_back(s);
}

void Model::run(int start, int end){
    for(int t = start; t < end; t++){
        // Calculate valueNext = old value
        for(System* s : systems){
            s->setValueNext(s->getValue());
        }

        // Applies all flows
        for(Flow* f : flows){
            double value = f->equation();

            if(f->getSource())
                f->getSource()->setValueNext(f->getSource()->getValueNext() - value);

            if(f->getTarget())
                f->getTarget()->setValueNext(f->getTarget()->getValueNext() + value);
        }

        // Commit: update all values 
        for(System* s : systems){
            s->commit();
        }
    }
}

void Model::report() {
    cout << "Systems: [ ";
    for (System* s : systems) {
        cout << s->getValue() << " ";
        //implementar os testes por assert aqui 
    }
    cout << "]\n";
}

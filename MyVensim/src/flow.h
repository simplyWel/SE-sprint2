#ifndef FLOW_H
#define FLOW_H

class System;

class Flow {
protected:
    System* source;
    System* target;

public:
    Flow();
    Flow(const Flow& other); 
    ~Flow();

    void setSource(System* s);
    void setTarget(System* t);

    System* getSource() const;
    System* getTarget() const;

    virtual double equation();
};

#endif
#ifndef FLOW_H
#define FLOW_H

class System;

class Flow {
private:
    System* source;
    System* target;

public:
    Flow();
    ~Flow();

    virtual double equation();

    void setSource(System* s);
    void setTarget(System* t);

    System* getSource() const;
    System* getTarget() const;
};

#endif
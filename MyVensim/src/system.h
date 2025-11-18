#ifndef SYSTEM_H
#define SYSTEM_H

class System {
private:
    double value;
    double valueNext;
public:
    System();
    ~System();

    void setValue(double v);
    double getValue() const;

    void setValueNext(double v);
    double getValueNext() const;

    void commit();

    //criar um operador sobrecarregado com = nos .h da src

};

#endif

#ifndef SYSTEM_H
#define SYSTEM_H

class System {
private:
    double value;
public:
    System(double v);
    System(const System& other);
    ~System();

    void setValue(double v);
    double getValue() const;

    void setValueNext(double v);
    void addValue(double da);

    const System& operator=(const System& other);

};

#endif

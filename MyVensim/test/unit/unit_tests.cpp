#include "../../src/system.h"
#include "unit_tests.h"
#include <cassert>
#include <iostream>
using namespace std;

void sampleUnitTest(){
    System s(5);
    assert(s.getValue() == 5); //return in this line
    cout << "All tests passed" << endl;
}
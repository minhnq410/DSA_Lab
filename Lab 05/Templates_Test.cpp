#include <iostream>

#include "slist.h"

using namespace std;

int main()
{
    SList<int>* s1 = new SList<int>();
    SList<double>* s2 = new SList<double>();

    int i1 = 1;
    int i2 = 2;
    int i3 = 3;
    int i4 = 4;
    int* pi1 = &i1;
    int* pi2 = &i2;
    int* pi3 = &i3;
    int* pi4 = &i4;

    double d1 = 1.2;
    double d2 = 2.3;
    double d3 = 3.4;
    double d4 = 4.5;
    double* pd1 = & d1;
    double* pd2 = & d2;
    double* pd3 = & d3;
    double* pd4 = & d4;

    s1->addFirst(pi1);
    s1->addFirst(pi2);
    s1->addFirst(pi3);
    s1->addFirst(pi4);
    s2->addFirst(pd1);
    s2->addFirst(pd2);
    s2->addFirst(pd3);
    s2->addFirst(pd4);

    s1->print();
    s2->print();
    return 0;
}

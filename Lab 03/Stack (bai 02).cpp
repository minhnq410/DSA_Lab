#include <string>
#include <iostream>

#include "slist.h"

using namespace std;

class Stack {
private:
    SList* slist;

public:
    Stack() { slist = new SList(); }
    bool isEmpty() { return slist->isEmpty(); }
    long getSize() { return slist->getSize(); }
    void push(string* s) {
        //your code goes here
        slist->addFirst(s);
    }
    string* pop() {
        //your code goes here
        return slist->removeFirst();
    }
    string* top() {
        //your code goes here
        string* s = slist->removeFirst();
        slist->addFirst(s);
        return s;
    }
    void print() { slist->print(); }
};

int main()
{
    Stack* s = new Stack();
    string s1 = "1", s2 = "2", s3 = "3", s4 = "4";

    s->push(&s1);
    s->print();
    s->push(&s2);
    s->print();
    s->push(&s3);
    s->print();
    s->push(&s4);
    s->print();
    cout << "top: "<< *(s->top()) << endl;
    cout << "pop: "<< *(s->pop()) << endl;
    s->print();

    return 0;
}

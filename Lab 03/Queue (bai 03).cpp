#include <string>
#include <iostream>

#include "slist.h"

using namespace std;

class Queue {
private:
    SList* slist;

public:
    Queue() { slist = new SList(); }
    bool isEmpty() { return slist->isEmpty(); }
    long getSize() { return slist->getSize(); }
    void enqueue(string* s) {
        //your code goes here
        slist->addLast(s);
    }
    string* dequeue() {
        //your code goes here
        return slist->removeFirst();
    }
    string* front() {
        //your code goes here
        string* s = slist->removeFirst();
        slist->addFirst(s);
        return s;
    }
    void print() { slist->print(); }
};

int main()
{
    Queue* s = new Queue();
    string s1 = "1", s2 = "2", s3 = "3", s4 = "4";

    s->enqueue(&s1);
    s->print();
    s->enqueue(&s2);
    s->print();
    s->enqueue(&s3);
    s->print();
    s->enqueue(&s4);
    s->print();
    cout << "front: "<< *(s->front()) << endl;
    cout << "dequeue: "<< *(s->dequeue()) << endl;
    s->print();

    return 0;
}


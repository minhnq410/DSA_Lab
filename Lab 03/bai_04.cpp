#include <iostream>
#include <queue>
#include <string>

#include "slist.h"

using namespace std;

void reverseSList(SList* sl);

int main()
{
    SList* sl = new SList();
    string s1 = "1";
    string s2 = "2";
    string s3 = "3";
    sl->addFirst(&s1);
    sl->addFirst(&s2);
    sl->addFirst(&s3);
    sl->print();
    cout << "Reverse" << endl;
    reverseSList(sl);
    sl->print();

    return 0;
}

void reverseSList(SList* sl)
{
    long sl_size = sl->getSize();
    queue<string> myQ;
    for (int i = 0; i < sl_size; i++)
    {
        myQ.push(*(sl->removeFirst()));
    }
    for (int i = 0; i < sl_size; i++)
    {
        string* s = &myQ.front();
        sl->addFirst(s);
        myQ.pop();
    }
}

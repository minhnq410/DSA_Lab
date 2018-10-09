#ifndef __SLIST_H
#define __SLIST_H

#include <string>
#include <iostream>

using namespace std;

/* Node of a singly linked list of strings */
struct SNode {
   string* element;
   SNode *next; // Pointer to the next node

   /* Creates a node. */
   SNode(string* e, SNode* n)  {
      element = e;
      next = n;
   }
   string* getElement() { return element; }
   void print() { cout << *element; }
};

class SList {
protected:		// data member
    SNode* head;
    long size;		// number of nodes in the list

public:
    /* Default constructor that creates an empty list */
    SList() {
        head = NULL;
        size = 0;
    }
    // ... update and search methods would go here ...
    long getSize() { return size; }
    int isEmpty() { return size<=0; }

    SNode* addFirst(string* s) {
        SNode* newNode = new SNode(s, head);
        head = newNode;
        size++;
        return newNode;
    }

    SNode* addLast(string* s){
        SNode* newNode = new SNode(s, NULL);
        if (size == 0) { head = newNode; }
        else
        {
            SNode* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            temp = NULL;
            delete temp;
        }
        size++;
        return newNode;
    }

    string* removeFirst() {
        if (head==NULL) return NULL;
        string* s = head->element;
        SNode * t = head;
        head = head->next;
        delete t;
        size--;
        return s;
    }

    void print() {
        SNode* iter = head;
        while (iter!=NULL) {
            iter->print();
            cout << ", ";
            iter = iter->next;
        }
        cout << endl;
    }
};

#endif

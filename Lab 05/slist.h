#ifndef __SLIST_H
#define __SLIST_H

#include <string>
#include <iostream>

using namespace std;

/* Node of a singly linked list of strings */\
template <typename Type>
struct SNode {
   Type* element;
   SNode<Type> *next; // Pointer to the next node

   /* Creates a node. */
   SNode(Type* e, SNode<Type>* n)  {
      element = e;
      next = n;
   }
   Type* getElement() { return element; }
   void print() { cout << *element; }
};

template <typename Type>
class SList {
protected:		// data member
    SNode<Type>* head;
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

    SNode<Type>* addFirst(Type *s) {
        SNode<Type> *newNode = new SNode<Type>(s, head);
        head = newNode;
        size++;
        return newNode;
    }

    SNode<Type>* addLast(Type *s){
        SNode<Type> *newNode = new SNode<Type>(s, NULL);
        if (size == 0) { head = newNode; }
        else
        {
            SNode<Type> *temp = head;
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

    Type* removeFirst() {
        if (head==NULL) return NULL;
        Type *s = head->element;
        SNode<Type> *t = head;
        head = head->next;
        delete t;
        size--;
        return s;
    }

    void print() {
        SNode<Type> *iter = head;
        while (iter!=NULL) {
            iter->print();
            cout << ", ";
            iter = iter->next;
        }
        cout << endl;
    }
};

#endif

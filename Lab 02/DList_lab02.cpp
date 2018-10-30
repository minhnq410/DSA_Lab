#include <string>
#include <iostream>

using namespace std;

/* Node of a singly linked list of strings */
struct DNode {
   string* element;
   DNode *next; // Pointer to the next node
   DNode *prev; // Pointer to the previous node
   /* Creates a node. */
   DNode(string* e, DNode* n, DNode* p)  {
      element = e;
      next = n;
      prev = p;
   }
   string* getElement() { return element; }
   void print() { cout << *element; }
};

class DList {
protected:		// data member
    DNode* head;
    DNode* tail;
    long size;		// number of nodes in the list

public:
    /* Default constructor that creates an empty list */
    DList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    // ... update and search methods would go here ...
    long getSize() { return size; }
    int isEmpty() { return size<=0; }

    // add a new node to the beginning of the list
    DNode* addFirst(string* s) {
        if (this->isEmpty())
        {
            DNode* newNode = new DNode(s, NULL, NULL);
            head = newNode;
            tail = newNode;
            size++;
            return newNode;
        }
        else
        {
            DNode* newNode = new DNode(s, head, NULL);
            head = newNode;
            size++;
            return newNode;
        }
    }

    //remove the first node in the list
    string* removeFirst() {
        if (head==NULL) return NULL;
        //  code to remove the first node in the list
        else
        {
            DNode* temp = head;
            if (size == 1)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                head = head->next;
                head->prev = NULL;
            }
            temp = new DNode(NULL, NULL, NULL);
            delete temp;
            size--;
        }
    }

    // insert a new node after node n and store the string s there
    void insertAfter (DNode* n, string* s) {
        DNode* newNode = new DNode(s, n->next, n);
        if (n == tail)
        {
            tail = newNode;
        }
        else
        {
            (n->next)->prev = newNode;
        }
        n->next = newNode;
        size++;
    }

    // delete node n and return the string stored in n
    string* deleteAfter (DNode* n) {
        if (n == tail)
        {
            tail = n->prev;
        }
        else
        {
            (n->next)->prev = n->prev;
        }
        if (n == head)
        {
            head = n->next;
        }
        else
        {
            (n->prev)->next = n->next;
        }
        n->next = NULL;
        n->prev = NULL;
        string* s = n->element;
        delete n;
        return s;
    }

    //display the list's data in order from head to tail
    void print() {
        DNode* iter = head;
        while (iter!=NULL) {
            // call DNode method to display iter's data
            //.....
            cout << *(iter->getElement());
            iter = iter->next;
        }
        cout << endl;
    }
};

int main(void)
{
   // You should modified this function to test list's methods.

   DList* dl = new DList();
   string s1 = "1";
   DNode* p = dl->addFirst(&s1);
   dl->print();
    string s1_2 = "1.5";
   dl->insertAfter(p,&s1_2);
   dl->print();
   dl->deleteAfter(p);
   dl->print();

   string s2 = "2";
   dl->addFirst(&s2);
   dl->print();

   string s3 = "3";
   dl->addFirst(&s3);
   dl->print();

   string s4 = "4";
   dl->addFirst(&s4);
   dl->print();

   string s5 = "5";
   dl->addFirst(&s5);
   dl->print();

   dl->removeFirst();
   dl->print();
   dl->removeFirst();
   dl->print();
   dl->removeFirst();
   dl->print();

   return 0;
}


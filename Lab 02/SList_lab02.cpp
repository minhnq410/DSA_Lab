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

    // add a new node to the beginning of the list
    SNode* addFirst(string* s) {
        SNode* newNode = new SNode(s, head);
        head = newNode;
        size++;
        return newNode;
    }

    //remove the first node in the list
    string* removeFirst() {
        if (head==NULL) return NULL;
        //  code to remove the first node in the list
        else
        {
            SNode* temp = head;
            head = head->next;
            string* s = temp->element;
            delete temp;
            size--;
            return s;
        }
    }

    // insert a new node after node n and store the string s there
    void insertAfter (SNode * n, string* s) {
        SNode* newNode = new SNode(s, n->next);
        n->next = newNode;
        size++;
    }

    // delete node n and return the string stored in n
    string* deleteAfter (SNode * n) {
        if (head == n)
        {
            SNode* temp = head;
            head = head->next;
            string* s = temp->element;
            delete temp;
            size--;
            return s;
        }
        else
        {
            SNode* temp = head;
            while (temp->next != n)
            {
                temp = temp->next;
            }
            temp->next = n->next;
            string* s = temp->element;
            delete temp;
            size--;
            return s;
        }
    }

    //display the list's data in order from head to tail
    void print() {
        SNode* iter = head;
        while (iter!=NULL) {
            // call SNode method to display iter's data
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

   SList* dl = new SList();
   string s1 = "1";
   SNode* p = dl->addFirst(&s1);
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


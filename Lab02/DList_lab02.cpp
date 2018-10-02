#include <string>
#include <iostream>

using namespace std;

/* Node of a singly linked list of strings */
struct SNode {
   string* element;
   SNode *next; // Pointer to the next node
   SNode *prev; // Pointer to the previous node
   /* Creates a node. */
   SNode(string* e, SNode* n, SNode* p)  {
      element = e;
      next = n;
      prev = p;
   }
   string* getElement() { return element; }
   void print() { cout << *element; }
};

class DList {
protected:		// data member
    SNode* head;
    SNode* trailer;
    long size;		// number of nodes in the list

public:
    /* Default constructor that creates an empty list */
    DList() {
        head = trailer;
        trailer = NULL;
        size = 0;
    }
    // ... update and search methods would go here ...
    long getSize() { return size; }
    int isEmpty() { return size<=0; }

    // add a new node to the beginning of the list
    SNode* addFirst(string* s) {
        SNode* newNode = new SNode(s, head, NULL);
        head = newNode;
        size++;
        return newNode;
    }

    SNode* addLast(string* s) {
        SNode* newNode = new SNode(s, NULL, trailer);
        trailer = newNode;
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
            head->prev = NULL;
            temp = new SNode(NULL, NULL, NULL);
            delete temp;
            size--;
        }
    }

    // insert a new node after node n and store the string s there
    void insertAfter (SNode n, string* s) {
        SNode* newNode = new SNode(s, n.next, &n);
        (n.next)->prev = newNode;
        n.next = newNode;
        size++;
    }

    // delete node n and return the string stored in n
    string* insertAfter (SNode n) {
        if (head == &n)
        {
            SNode* temp = head;
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            size--;
            return temp->getElement();
        }
        else if (trailer == &n)
        {
            SNode* temp = trailer;
            trailer = trailer->prev;
            trailer->next = NULL;
            temp->prev = NULL;
            size--;
            return temp->getElement();
        }
        else
        {
            SNode* temp = head;
            while (head->next != &n)
            {
                head = head->next;
            }
            head->next = n.next;
            (n.next)->prev = head;
            head = temp;
            n.next = NULL;
            n.prev = NULL;
            size--;
            return n.getElement();
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
    /*
   SList* dl = new SList();
   string s1 = "1";
   SNode* p = dl->addFirst(&s1);
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
    */
   return 0;
}


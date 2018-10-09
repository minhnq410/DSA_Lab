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

class Stack {
protected:		// data member
    SNode* head;
    long size;		// number of nodes in the list

public:
    /* Default constructor that creates an empty list */
    Stack() {
        head = NULL;
        size = 0;
    }
    // ... update and search methods would go here ...
    long getSize() { return size; }
    int isEmpty() { return size<=0; }

    // add a new node to the beginning of the list
    SNode* push(string* s) {
        SNode* newNode = new SNode(s, head);
        head = newNode;
        size++;
        return newNode;
    }

    //remove the first node in the list
    string pop() {
        if (head==NULL) return NULL;
        //  code to remove the first node in the list
        else
        {
            SNode* temp = head;
            head = head->next;
            string* s = temp->element;
            delete temp;
            size--;
            return *s;
        }
    }

    string top(){
        if (head == NULL) return NULL;
        else return *(head->getElement());
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

   Stack* dl = new Stack();
   string s1 = "1";
   SNode* p = dl->push(&s1);
   dl->print();


   string s2 = "2";
   dl->push(&s2);
   dl->print();

   string s3 = "3";
   dl->push(&s3);
   dl->print();

   string s4 = "4";
   dl->push(&s4);
   dl->print();
   cout << dl->pop() << endl;
   dl->print();

   string s5 = "5";
   dl->push(&s5);
   dl->print();

   dl->pop();
   dl->print();
   dl->pop();
   dl->print();
   dl->pop();
   dl->print();

   return 0;
}


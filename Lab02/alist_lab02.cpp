#include <string>
#include <iostream>

using namespace std;

/* Node of a singly linked list of strings */
class AList {
protected:
    int* a;	// dynamically allocated array of ints
    long maxSize, size;	// logic size of the array(not the allocated size)

public:
    /* Default constructor that creates an empty list */
    AList(int maxSize) {
        this->maxSize = maxSize;
        a = new int[maxSize];
        size = 0;
    }
    //clean up all the memory that has been allocated in the constructor.
    ~AList() {
        //your implementation
        delete[] a;
        size = 0;
    }
    // ... update and search methods would go here ...
    long getSize() { return size; }
    int isEmpty() { return size<=0; }
    int isFull() {
       // your implementation
       return size == maxSize;
    };

    //add a number to the end of the array
    //return index of the new entry
    //do nothing and return -1 if the array is already full
    int addLast(int n) {
        // your implementation
        if (this->isFull())
        {
            return -1;
        } else {
            int i = size;
            *(a+i) = n;
            size += 1;
            return size;
        }
    }

    //insert a number to the entry indexed i in the array
    // if i is too big (>size) then add the new entry to the end instead
    // do nothing if the array is already full
    void insert(int n, int i) {
        // your implementation
        if (size < i) {this->addLast(n);}
        else if (i < size) {
            for (int j = this->getSize(); j > i; j--)
                {
                    *(a+j) = *(a+j-1);
                }
            *(a+i) = n;
            size += 1;
        }
    }

    //remove entry with index i, shift all entries from i+1 to the left
    // do nothing if there is no entry i
    int removeIndex(int i) {
        // your implementation
        if (i < this->getSize())
        {
            for (int j = i; j < this->getSize(); j++)
            {
                *(a+j) = *(a+j+1);
            }
            size -= 1;
        }
    }

    //remove all the entries with value n,
    // shift entries to the left to cover the deleted slots.
    int removeData(int n) {
        // your implementation
        int counter = 0;
        for (int i = 0; i < size - counter; i++)
        {
            if ( *(a+i+counter) == n )
            {
                counter += 1;
                i -= 1;
            } else *(a+i) = *(a+i+counter);
        }
        size = size - counter;
    }

    //display the array's data in order
    void print() {
        // your implementation
        for (int i = 0; i < size; i++)
        {
            cout << *(a+i) << endl;
        }

    }
};

int main(void)
{
   // your code to test class AList
   AList* a = new AList(5);
   a->addLast(0);
   a->addLast(2);
   a->insert(1,1);
   a->addLast(2);
   a->addLast(4);
   cout << a->getSize() << endl;
   a->addLast(5);
   a->print();
   a->removeData(2);
   a->print();
   a->removeIndex(1);
   a->print();
   return 0;
}

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
    }
    // ... update and search methods would go here ...
    long getSize() { return size; }
    int isEmpty() { return size<=0; }
    int isFull() {
       // your implementation
    };

    //add a number to the end of the array
    //return index of the new entry
    //do nothing and return -1 if the array is already full
    int addLast(int n) {
        // your implementation
    }

    //insert a number to the entry indexed i in the array
    // if i is too big (>size) then add the new entry to the end instead
    // do nothing if the array is already full
    void insert(int n, int i) {
        // your implementation
    }

    //remove entry with index i, shift all entries from i+1 to the left
    // do nothing if there is no entry i
    int removeIndex(int i) {
        // your implementation
    }

    //remove all the entries with value n,
    // shift entries to the left to cover the deleted slots.
    int removeData(int n) {
        // your implementation
    }

    //display the array's data in order
    void print() {
        // your implementation
    }
};

int main(void)
{
   // your code to test class AList
   return 0;
}

#include <iostream>

using namespace std;

struct BTNode {
    int* value;
    //BTNode* Parent;
    BTNode* LeftChild;
    BTNode* RightChild;

    TNode (int* value)
    {
        this->value = value;
    }

    void print()
    {
        cout << *value;
    }

};

class BinaryTree {

    BTNode* root;
    int size;

    BinaryTree()
    {
        root = NULL;
        size = 0;
    }

    int getSize() {return size;}

    bool isInternal(BTNode* n)
    {
        if(n->LeftChild != NULL || n->RightChild != NULL)
        {
            return 1;
        }
        else return 0;
    }
    bool isExternal(BTNode* n)
    {
        return !isInternal(n);
    }

    void inorderPrint(BTNode* n)
    {
        inorderPrint(n->LeftChild);
        n->print();
        inorderPrint(n->RightChild);
    }

    void postorderPrint(BTNode* n)
    {
        postorderPrint(n->LeftChild);
        postorderPrint(n->RightChild);
        n->print();
    }
};


int main()
{

    return 0;
}

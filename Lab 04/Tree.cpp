#include <iostream>
#include <string>

using namespace std;

struct Node {
    int* value;
    Node* LeftChild;
    Node* RightChild;

    Node(int* value)
    {
        this->value = value;
        LeftChild = NULL;
        RightChild = NULL;
    }

    int getValue()
    {
        return *value;
    }

    void setLeft(Node* n)
    {
        this->LeftChild = n;
    }

    void setRight(Node* n)
    {
        this->RightChild = n;
    }

    bool isInternal()
    {
        return (this->LeftChild != NULL || this->RightChild != NULL);
    }

    void inorderPrint()
    {
        if( this->LeftChild != NULL)
        {
            (this->LeftChild)->inorderPrint();
        }
        if( this->isInternal())
        {
            switch (this->getValue())
            {
                case 1: cout << "+ "; break;
                case 2: cout << "- "; break;
                case 3: cout << "* "; break;
                case 4: cout << "/ "; break;
            }
        }
        else cout << *value << " ";
        if( this->RightChild != NULL)
        {
            (this->RightChild)->inorderPrint();
        }
    }
    void postorderPrint()
    {
        if (this->LeftChild != NULL)
        {
            (this->LeftChild)->postorderPrint();
        }
        if (this->RightChild != NULL)
        {
            this->RightChild->postorderPrint();
        }
        if( this->isInternal())
        {
            switch (this->getValue())
            {
                case 1: cout << "+ "; break;
                case 2: cout << "- "; break;
                case 3: cout << "* "; break;
                case 4: cout << "/ "; break;
            }
        }
        else cout << *value << " ";
    }

    double evaluate()
    {
        if(!this->isInternal())
        {
            return this->getValue();
        }
        else
        {
            double x = (this->LeftChild)->evaluate();
            double y = (this->RightChild)->evaluate();
            int c = *value;
            if (c == 1) return x + y;
            if (c == 2) return x - y;
            if (c == 3) return x * y;
            if (c == 4) return x / y;
        }
    }

};

int main()
{
    int c1 = 3; // dau *
    int c2 = 3;
    int c3 = 4;
    int c4 = 1;  // dau +
    int c5 = 4;  // dau /
    int c6 = 10;
    int c7 = 2;

    int* v1 = &c1;
    int* v2 = &c2;
    int* v3 = &c3;
    int* v4 = &c4;
    int* v5 = &c5;
    int* v6 = &c6;
    int* v7 = &c7;

    Node* n1 = new Node(v1);
    Node* n2 = new Node(v2);
    Node* n3 = new Node(v3);
    Node* n4 = new Node(v4);
    Node* n5 = new Node(v5);
    Node* n6 = new Node(v6);
    Node* n7 = new Node(v7);

    n4->setRight(n1);
    n4->setLeft(n5);
    n1->setLeft(n2);
    n1->setRight(n3);
    n5->setLeft(n6);
    n5->setRight(n7);

    n4->inorderPrint();
    cout << "= ";
    cout << n4->evaluate();
    return 0;
}



#include <iostream>
#include <string>

using namespace std;

bool isOperator(char c);

struct Node {
    char* value;
    Node* LeftChild;
    Node* RightChild;

    Node(char* value)
    {
        this->value = value;
        LeftChild = NULL;
        RightChild = NULL;
    }

    int getValue()
    {
        return *value - '0';
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
        cout << *value << " ";
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
        cout << *value << " ";
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
            char c = *value;
            if (c == '+') return x + y;
            if (c == '-') return x - y;
            if (c == '*') return x * y;
            if (c == '/') return x / y;
        }
    }

};

class BinaryTree {

    private:
        Node* root;

    public:
        BinaryTree(Node* root)
        {
            this->root = root;

        }

        Node* getRoot()
        {
            return root;
        }

};
int main()
{
    char c1 = '*';
    char c2 = '3';
    char c3 = '4';
    char c4 = '+';
    char c5 = '/';
    char c6 = '5';
    char c7 = '2';

    char* v1 = &c1;
    char* v2 = &c2;
    char* v3 = &c3;
    char* v4 = &c4;
    char* v5 = &c5;
    char* v6 = &c6;
    char* v7 = &c7;

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
    cout << " = ";
    cout << n4->evaluate();
    return 0;
}



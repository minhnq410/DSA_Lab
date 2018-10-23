#include <iostream>
#include <string>

using namespace std;

bool isOperator(char c);

struct Node {
    char* value;
    //BTNode* Parent;
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
};

class BinaryTree {

    private:

        Node* root;
        int size;

    public:

        BinaryTree()
        {
            root = NULL;
            size = 0;
        }

        BinaryTree(Node* root)
        {
            this->root = root;

        }

        bool isEmpty() {return size <= 0;}
        int getSize() {return size;}
        Node* getRoot()
        {
            return root;
        }

        void insertNode(char* c)
        {
            if (this->isEmpty())
            {
                Node* newNode = new Node(c);
                root = newNode;
            }

            size++;

        }

        void insertSubR(BinaryTree* sub)
        {
            if(this->isEmpty())
            {
                this->root = sub->getRoot();
            }
            else
            {
                Node* temp = root;
                while (temp->RightChild != NULL)
                {
                    temp = temp->RightChild;
                }
                temp->RightChild = sub->getRoot();
            }
            this->size += sub->getSize();
        }


        bool isInternal(Node* n)
        {
            return (n->LeftChild != NULL || n->RightChild != NULL);
        }

        bool isLeaf(Node* n)
        {
            return !isInternal(n);
        }

        void inorderPrint(Node* n)
        {
            if( isInternal(n) && n->LeftChild != NULL)
            {
                inorderPrint(n->LeftChild);
            }
            cout << *(n->value) << " ";
            if( isInternal(n) && n->RightChild != NULL)
            {
                inorderPrint(n->RightChild);
            }

        }

        void postorderPrint(Node* n)
        {
            if (isInternal(n))
            {
                if(n->LeftChild != NULL)
                {
                    postorderPrint(n->LeftChild);
                }

                postorderPrint(n->RightChild);
            }
            cout << *(n->value) << " ";
        }

};

int main()
{
    //string s;
    //getline(cin, s);
    //cout << s;
    char c1 = '*';
    char* v1 = &c1;
    char c2 = '3';
    char* v2 = &c2;
    char* v3;
    char c3 = '4';
    v3 = &c3;
    char c4 = '+';
    char c5 = '2';
    char* v4 = &c4;
    char* v5 = &c5;

    Node* n1 = new Node(v1);
    Node* n2 = new Node(v2);
    Node* n3 = new Node(v3);
    Node* n4 = new Node(v4);
    Node* n5 = new Node(v5);
    n4->setRight(n1);
    n4->setLeft(n5);
    n1->setLeft(n2);
    n1->setRight(n3);
    BinaryTree* tree = new BinaryTree(n4);
    tree->inorderPrint(tree->getRoot());

    return 0;
}


bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

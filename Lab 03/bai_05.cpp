// http://www.cplusplus.com/reference/stl/stack/pop/
// stack::push/pop
#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool isSyntacticallyCorrect (string s);

int main ()
{
    string s;
    getline(cin, s);


/*
    cout << "Popping out elements...";
    while (!mystack.empty())
    {
        cout << " " << mystack.top();
        mystack.pop();
    }
    cout << endl;
*/
    cout << isSyntacticallyCorrect(s);

    return 0;
}

bool isSyntacticallyCorrect (string s)
{
    stack<char> mystack;
    //bool result = true;

    for (int i=0; i<s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            mystack.push(s[i]);
            continue;
        }

        switch (s[i])
        {
            case ')':
                {
                    if (mystack.top() == '(')
                    {
                        mystack.pop();
                        break;
                    }
                    else return false;
                };
            case ']':
                {
                    if (mystack.top() == '[')
                    {
                        mystack.pop();
                        break;
                    }
                    else return false;
                };
            case '}':
                {
                    if (mystack.top() == '{')
                    {
                        mystack.pop();
                        break;
                    }
                    else return false;
                };
        }
    }
    if (!mystack.empty()) return false;
}

// http://www.cplusplus.com/reference/stl/stack/pop/
// stack::push/pop
#include <string>
#include <iostream>
#include <stack>
using namespace std;

boolean isSyntacticallyCorrect (string s);

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
    return 0;
}

boolean isSyntacticallyCorrect (string s)
{
    stack<char> mystack;

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
                char x = mystack.top();
                if (mystack.pop() == '[' || mystack.pop() == '{')
                return false;
            };
        case ']':
        }

    }
}

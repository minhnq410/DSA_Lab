#include <iostream>
#include <vector>

using namespace std;

void subSets( vector< vector<int> > &subsets, int n);

int main()
{
    vector< vector <int> > a;
    int n;
    cin >> n;
    subSets(a, n);
    for (int i = 0; i < a.size(); i ++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void subSets( vector< vector<int> > &subsets, int n)
{
    if (n == 0)
    {
        vector<int> empty;
        subsets.push_back(empty);
    }
    else
    {
        subSets(subsets, n - 1);
        int size = subsets.size();

        for (int i = 0; i < size; i++)
        {
            vector<int> temp = subsets[i];
            temp.push_back(n);
            subsets.push_back(temp);
        }
    }
}

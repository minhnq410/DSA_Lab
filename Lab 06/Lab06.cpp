#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct compare{
    bool operator()(string a, string b)
    {
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        return a < b;
    }
};


int main()
{
    ifstream fileIn("File.txt");
    vector<string> words;
    while (!fileIn.eof())
    {
        string w;
        fileIn >> w;
        words.push_back(w);
    }
    fileIn.close();

    map<string, int> ::iterator i;
    map<string, int, compare > myMap;
    for (int i = 0; i < words.size(); i++)
    {
        string w = words[i];
        myMap[w]++;
    }
    for (i = myMap.begin(); i != myMap.end(); i++)
    {
        cout << i->first << "\t" << i->second << endl;
    }
    return 0;
}

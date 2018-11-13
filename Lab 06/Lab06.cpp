#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool smaller (string a, string b)
{
    a[0] = tolower(a[0]);
    b[0] = tolower(b[0]);
    return a < b;
}

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

    sort(words.begin() , words.end() , smaller);
    vector<int> occurences;
    for (int i = 0; i < words.size(); i++)
    {
        occurences.push_back(1);
        if (i + 1 == words.size()) break;
        if (words[i] == words[i + 1])
        {
            occurences[i]++;
            words.erase(words.begin() + i + 1);
            i--;
        }
    }
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << "\t" << occurences[i] << endl;
    }

    return 0;
}

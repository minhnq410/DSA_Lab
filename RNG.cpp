#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int n = rand() % 100 + 1;

    int array [n];
    for (int  i = 0; i < n; i++)
    {
        array[i] = rand() % 1000 + 1;
    }

    ofstream fileOut ("EXX2.IN.TXT");
    fileOut << n << " ";
    for (int i = 0; i < n; i ++)
    {
        fileOut << array[i] << " ";
    }
    fileOut.close();
}

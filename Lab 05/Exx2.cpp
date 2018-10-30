#include <fstream>

using namespace std;

void insertionSortAscending(int a[], int n);

int main()
{
    ifstream fileIn ("EXX2.IN.TXT");
    int n;
    fileIn >> n;
    int a [n];
    for (int i = 0; i < n; i++)
    {
        fileIn >> a[i];
    }
    fileIn.close();

    insertionSortAscending(a, n);

    ofstream fileOut ("EXX2.OUT.TXT");
    for (int i = 0; i < n; i++)
    {
        fileOut << a[i] << endl;
    }
    fileOut.close();

    return 0;
}

void insertionSortAscending(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] >= temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}


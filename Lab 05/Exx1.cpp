#include <fstream>

using namespace std;

void bubbleSortDescending(int a[], int n);

int main()
{
    ifstream fileIn ("EXX1.IN.TXT");
    int n;
    fileIn >> n;
    int a [n];
    for (int i = 0; i < n; i++)
    {
        fileIn >> a[i];
    }
    fileIn.close();

    bubbleSortDescending(a, n);

    ofstream fileOut ("EXX1.OUT.TXT");
    for (int i = 0; i < n; i++)
    {
        fileOut << a[i] << endl;
    }
    fileOut.close();

    return 0;
}

void bubbleSortDescending(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ( a[j] < a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

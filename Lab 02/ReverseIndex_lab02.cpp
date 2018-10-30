#include <iostream>
#include <utility>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Reverse(int a[], int i, int j);

int main ()
{
    srand(time(0));
    int n, i, j;
    cin >> n;
    do { cin >> i;} while (i > n || i < 0);
    do { cin >> j;} while (j > n || j < i);

    ofstream fo("KQ1.TXT");

    int mang[n];
    for (int i = 0; i < n; i++)
    {
        mang[i] = rand() % 100;
    }
    for (int i = 0; i < n; i++)
    {
        fo << mang[i] << endl;
    }
    Reverse (mang, i, j);

    ofstream fo2("KQ2.TXT");
    for (int i = 0; i < n; i++)
    {
        fo2 << mang[i] << endl;
    }
    return 0;
}

void Reverse(int a[], int i, int j)
{
    if (i < j)
    {
        swap(a[i], a[j]);
        Reverse(a, i + 1, j - 1);
    }
}

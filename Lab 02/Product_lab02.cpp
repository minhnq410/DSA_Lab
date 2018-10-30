#include <iostream>

using namespace std;

int Product (int m, int n);

int main()
{
    int m, n;
    cin >> m >> n;
    cout << Product(m, n);
    return 0;
}

int Product (int m, int n)
{
    if (m == 0 || n == 0) return 0;
    if (n == 1) return m;
    if (m == 1) return n;
    return m + Product (m, n - 1);
}

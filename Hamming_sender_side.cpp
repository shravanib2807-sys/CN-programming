#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data;
    cout << "Enter Data Word: ";
    cin >> data;
    int m = data.length();
    int r = 0;
    while ((1 << r) < m + r + 1)
        r++;
    int n = m + r;
    int code[20] = {0};
    int j = 0;
    for (int i = n; i >= 1; i--)
    {
        if ((i & (i - 1)) != 0)
        {
            code[i] = data[j] - '0';
            j++;
        }
    }
    for (int p = 1; p <= n; p = p * 2)
    {
        int parity = 0;

        for (int i = 1; i <= n; i++)
        {
            if ((i & p) != 0)
                parity = parity ^ code[i];
        }

        code[p] = parity;
    }
    cout << "\nm = " << m << endl;
    cout << "r = " << r << endl;
    cout << "n = " << n << endl;
    cout << "\nRedundant Bits:\n";

    for (int p = 1; p <= n; p = p * 2)
    {
        cout << "R" << p << " = " << code[p] << endl;
    }
    cout << "\nCode Word = ";

    for (int i = n; i >= 1; i--)
        cout << code[i];

    cout << endl;

    return 0;
}
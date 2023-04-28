#include <iostream>
using namespace std;
int main()
{
    int n = 10, m = 10, k = 5;
    int c;
    cin >> c;
    bool flag = true;

    if (m <= n)
    {
        if (c == 0 || m - c <= 0)
        {
            cout << "Invalid Input" << endl;
            cout << m << endl;
            return 0;
        }

        if (m - c < k)
            m = n;
        else
            m = m - c;

        cout << "No. of candies sold = " << c << endl;
        cout << "No. of candies left = " << m << endl;
    }
    else
        cout << "Invalid Input" << endl;
    return 0;
}

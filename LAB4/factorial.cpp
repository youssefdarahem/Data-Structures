
#include <iostream>
using namespace std;

// 2! = 2 * 1  = 2
// 3! = 3 * 2 * 1  = 6
// 4! = 4 * 3 * 2 * 1 = 24

// 4 * factorial(3)
// 4 * 3 * factorial(2) ...

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{

    // cout << factorial(1) << endl;
    // cout << factorial(2) << endl;
    // cout << factorial(3) << endl;
    cout << factorial(4) << endl;
    // cout << factorial(5) << endl;

    return 0;
}

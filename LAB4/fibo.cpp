// 0, 1, 1, 2, 3, 5, 8, 13
// 0, 1, 2, 3, 4, 5, 6, 7, 8
#include <iostream>
#include <vector>
using namespace std;

// memo = [-1,-1,-1,-1,-1,-1,-1,-1]

int fibonacci(int n, vector<int> &memo)
{

    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }

    if (memo[n] != -1)
    {
        return memo[n];
    }

    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);

    return memo[n];
}

int fibonacciHelper(int n)
{
    vector<int> memo(n + 1, -1); // memo = [-1,-1,-1,-1,-1]

    return fibonacci(n, memo);
}

int main()
{
    int n = 10;
    cout << "Fibonacci(" << n << ") = " << fibonacciHelper(n) << endl;

    return 0;
}

// n = 5

// fib(5) = fib(4) + fib(3)

// fib(4) = 2 + 1

// fib(3) = 1 + 1

// fib(2) = fib(1) // 1 + fib(0) //0

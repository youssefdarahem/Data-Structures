#include <iostream>
#include <vector>
using namespace std;

// [1,2,3,4,5] = 1+2+3+4+5

int arrSum(int arrToSum[])
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += arrToSum[i];
    }
    return sum;
}

// vec = []
// vec = [1] --> sum = 1
int vecSum(vector<int> vecToSum) // {5}
{
    if (vecToSum.size() == 0)
    {
        return 0;
    }
    if (vecToSum.size() <= 1)
    {
        return vecToSum[0];
    }

    vector<int> remaining(vecToSum.begin() + 1, vecToSum.end()); // {5}

    return vecToSum[0] + vecSum(remaining); // 1 + 2 + 3 + 4 + 5;
}

// 1 + vecSum({2,3,4,5})
// 1 + 2 + vecSum({3,4,5})
///

int main()
{

    // int arr[5] = {1, 2, 3, 4, 5};
    vector<int> numVect = {1, 2, 3, 4, 5};
    cout << vecSum(numVect) << endl;
    return 0;
}

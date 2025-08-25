#include <iostream>
using namespace std;

void moveDisk(char fp, char tp)
{
    cout << "moving disk from " << fp << " to " << tp << endl;
}

void moveTower(int height, char from, char to, char with)
{
    if (height >= 1)
    {
        moveTower(height - 1, from, with, to);
        moveDisk(from, to);
        moveTower(height - 1, with, to, from);
    }
}

int main()
{
    moveTower(3, 'A', 'C', 'B');
    // moveTower(3, from, distention, via)
}

//  move a tower of h-1 to withpole using toPole
//  move disk to distention
//  move a tower of h-1 to topole using fromPole
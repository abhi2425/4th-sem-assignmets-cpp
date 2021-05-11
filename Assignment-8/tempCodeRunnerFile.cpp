#include <iostream>
#include <stdio.h>
using namespace std;

void towerOfHanoi(int n, char source,
                  char destination, char auxillary)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << source << " to rod " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, auxillary, destination);
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
    towerOfHanoi(n - 1, auxillary, destination, source);
}

int main()
{
    int numberOfDisk = 0;
    cout << "*****Tower Of Hanoi******" << endl;
    cout << "Enter The Number Of Disks-:" << endl;
    cin >> numberOfDisk;
    towerOfHanoi(numberOfDisk, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}
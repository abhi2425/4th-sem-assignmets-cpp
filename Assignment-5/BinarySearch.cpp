//Binary Search Using Recursion
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

const int MAX_SIZE = 50;
int sortedArray[MAX_SIZE], size;

int binarySearch(int leftIndex, int rightIndex, int value)
{
    int midIndex = floor((leftIndex + rightIndex) / 2);
    if (sortedArray[midIndex] == value)
        return midIndex;
    if (leftIndex > rightIndex)
        return -1;
    if (leftIndex <= rightIndex)
        sortedArray[midIndex] < value ? binarySearch(midIndex + 1, rightIndex, value) : binarySearch(leftIndex, midIndex - 1, value);
}

void traverseArray()
{
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << sortedArray[i] << " ";
    }
    cout << "]" << endl;
}

bool checkSortedOrNot()
{
    int count = 0;
    for (int i = 1; i <= size - 1; i++)
        if (sortedArray[i - 1] <= sortedArray[i])
            count++;
    if (count == size - 1)
        return true;
    return false;
}

int main()
{
    int value;
    cout << "****Binary Search Using Recursion****" << endl;
    cout << "Enter the size of array-:" << endl;
    cin >> size;
    if (size > 0)
    {
        cout << "Enter the elements of array{Sorted} in ascending order -:" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> sortedArray[i];
        }
        bool isSorted = checkSortedOrNot();
        traverseArray();

        if (isSorted)
        {
            cout << "Enter the element to be searched-:" << endl;
            cin >> value;
            int index = binarySearch(0, size - 1, value);
            if (index == -1)
                cout << "Element not found!!" << endl;
            cout << "Index of " << value << " is-:" << index;
        }
        else
            cout << "Entered array is not sorted. So,Binary Search Can not be applied." << endl;
    }
    else
        cout << "Size " << size << " is not allowed!!" << endl;

    return 0;
}
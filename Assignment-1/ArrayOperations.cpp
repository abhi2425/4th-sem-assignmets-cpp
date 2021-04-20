#include <iostream>
#include <cstring>
#include <process.h>
using namespace std;
void menu();
void menuRepeat();

const int maxSize = 50;
int array[maxSize], size = 0;

void traverseArray()
{
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]" << endl;
}

void insertAtBeginning(int value)
{
    size++;
    for (int i = size; i > 1; i--)
    {
        array[i - 1] = array[i - 2];
    }
    array[0] = value;
    cout << "Inserted Successfully!" << endl;
}
void insertAtEnd(int value)
{
    array[size] = value;
    size++;
    cout << "Inserted Successfully!" << endl;
}

void insertOperations()
{
    int value;
    char choice[10];
    cout << "Enter the value-:";
    cin >> value;
    cout << "Enter location 'begin','end' or a 'position'-:";
    cin >> choice;
    if (strcmp(choice, "begin") == 0)
    {
        insertAtBeginning(value);
        traverseArray();
    }
    else if (strcmp(choice, "end") == 0)
    {
        insertAtEnd(value);
        traverseArray();
    }
    else if (strcmp(choice, "position") == 0)
    {
        int pos = 1;
        cout << "Position-:";
        cin >> pos;
        if (pos > size + 1)
        {
            cout << "Exceeding position max allowed-:" << size << endl;
            return;
        }
        size++;
        for (int i = size; i >= pos; i--)
            array[i] = array[i - 1];
        array[pos - 1] = value;
        cout << "Inserted Successfully!" << endl;
        traverseArray();
    }
    else
    {
        cout << "Wrong Input!!" << endl;
    }
}

void swapTheNumbers(int *nextElement, int *currentElement)
{
    int temp = *nextElement;
    *nextElement = *currentElement;
    *currentElement = temp;
}

void selectionSortFunction()
{
    int i, j, min_index;
    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
            if (array[j] < array[min_index])
                min_index = j;

        swapTheNumbers(&array[min_index], &array[i]);
    }
    traverseArray();
}

int linearSearch(string purpose)
{
    int num = 0, index = -1;
    if (size != 0)
    {
        cout << "Element to be " << purpose << "? " << endl;
        cin >> num;
        for (int i = 0; i < size; i++)
        {
            if (array[i] == num)
                index = i;
        }
        if (index == -1)
        {
            cout << "Sorry can't find the Element " << num << " in the array ";
            traverseArray();
            cout << endl;
        }
        else
        {
            cout << num << " Found at position-: " << index + 1 << " of array ";
            traverseArray();
            cout << endl;
        }
    }
    else
    {
        cout << "Empty Array!" << endl;
        traverseArray();
    }

    return index;
}
void deleteElement()
{
    // int index = linearSearch("Deleted");
    // if (index >= 0)
    // {
    //     for (int i = index; i < size; i++)
    //     {
    //         array[i] = array[i + 1];
    //     }
    //     size--;
    //     cout << "And deleted Successfully!!" << endl;
    //     traverseArray();
    //     cout << endl;
    // }
    // return;
    int index;
    if (size != 0)
    {
        cout << "Enter index to be deleted-: \n";
        cin >> index;

        if (index < 0 || index >= size)
        {
            cout << "Invalid\n";
        }
        else
        {
            for (int i = index; i <= size - 1; i++)
            {
                array[i] = array[i + 1];
            }
            size--;
            cout << "Deleted Successfully!" << endl;
            traverseArray();
        }
    }
    else
    {
        cout << "Empty Array!" << endl;
        traverseArray();
    }
}

void menu()
{
    char choice;
    cout << "******** Arrays Operations*********" << endl;
    cout << "\n Menu:";
    cout << "\n 1. Insert Elements";
    cout << "\n 2. Transverse Array Elements";
    cout << "\n 3. Selection Sort";
    cout << "\n 4. Linear search";
    cout << "\n 5. Delete Element";
    cout << "\n 6. Exit";
    cout << "\n Enter the choice-:";
    cin >> choice;
    switch (choice)
    {
    case '1':
        insertOperations();
        menuRepeat();
    case '2':
        traverseArray();
        menuRepeat();
    case '3':
        selectionSortFunction();
        menuRepeat();
    case '4':
        linearSearch("Searched");
        menuRepeat();
    case '5':
        deleteElement();
        menuRepeat();
    case '6':
        exit(0);
    }
}
void menuRepeat()
{
    char ch;
    cout << "Want to continue!! y/n-: ";
    cin >> ch;
    if (ch == 'y')
    {
        cout << endl;
        menu();
    }
    else if (ch == 'n')
    {
        cout << "Bye!!!";
        exit(0);
    }
    else
    {
        cout << "Wrong Input!!" << endl;
        menu();
    }
}
int main()
{
    cout << "Enter size of Array-: ";
    cin >> size;
    if (size > 0)
    {
        cout << "Enter " << size << " Elements-: " << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> array[i];
        }
        menu();
    }
    else
    {
        cout << "Size should be greater than 0" << endl;
        menu();
    }
    return 0;
}

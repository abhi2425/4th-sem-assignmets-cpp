

#include <stdio.h>
#include <iostream>

using namespace std;
const int STACK_SIZE = 4;
class Stack
{
    int top_of_stack;
    int arr[STACK_SIZE];

public:
    Stack()
    {
        top_of_stack = -1;
    }

    void push();
    void pop();
    void view();
    bool isStackEmpty();
    bool isStackFull();
};

bool Stack::isStackEmpty()
{
    return (top_of_stack == (-1) ? true : false);
}

bool Stack::isStackFull()
{
    return (top_of_stack == STACK_SIZE ? true : false);
}

void Stack::push()
{
    if (isStackFull())
    {
        cout << "\nSTACK IS FULL { OVERFLOW }";
    }
    else
    {
        int i;
        cout << "\nEnter an element :: ";
        cin >> i;
        ++top_of_stack;
        arr[top_of_stack] = i;
        cout << "\nInsertion successful.\n";
    }
}

void Stack::pop()
{
    int num;
    if (isStackEmpty())
    {
        cout << "\n STACK IS EMPTY [ UNDERFLOW ] " << endl;
    }
    else
    {
        cout << "\nDeleted item is : " << arr[top_of_stack] << "\n";
        top_of_stack--;
    }
}

void Stack::view()
{
    if (isStackEmpty())
    {
        cout << "\n STACK IS EMPTY [ UNDERFLOW ] " << endl;
    }
    else
    {
        cout << "\nSTACK :\n";
        for (int i = top_of_stack; i >= 0; i--)
        {
            cout << arr[i] << "\n";
        }
    }
}

int main()
{
    Stack s;
    char choice;
    choice = 0;
    cout << endl;
    cout << "*****STACK IMPLEMENTATION USING ARRAYS*******" << endl;
    while (choice != 4)
    {
        cout << "\n1. Push In To Stack\n";
        cout << "2. Pop From Stack\n";
        cout << "3. Display The Stack\n";
        cout << "4. Quit\n";
        cout << "\nEnter your Choice :: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            s.push();
            break;

        case '2':
            s.pop();
            break;

        case '3':
            s.view();
            break;

        case '4':
            exit(0);

        default:
            cout << "\nWrong Choice!! \n";
            break;
        }
    }

    return 0;
}
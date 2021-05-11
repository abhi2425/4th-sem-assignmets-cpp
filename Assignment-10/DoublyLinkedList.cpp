#include <bits/stdc++.h>
using namespace std;

// Linear Doubly Linked List

struct Node_Linear
{
    struct Node_Linear *prev;
    struct Node_Linear *next;
    int data;
};
struct Node_Linear *head_Linear;

void traverse_Linear()
{
    struct Node_Linear *temp;
    temp = head_Linear;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtBeg_Linear()
{
    struct Node_Linear *temp;
    int data;
    temp = new Node_Linear();
    if (temp == NULL)
    {
        cout << "Memory Error!!" << endl;
    }
    else
    {
        cout << "Enter number to be inserted:" << endl;
        cin >> data;

        if (head_Linear == NULL)
        {
            temp->next = NULL;
            temp->prev = NULL;
            temp->data = data;
            head_Linear = temp;
        }
        else
        {
            temp->data = data;
            temp->prev = NULL;
            temp->next = head_Linear;
            head_Linear->prev = temp;
            head_Linear = temp;
        }
        cout << "number inserted !!" << endl;
    }
}
void insertAtEnd_Linear()
{
    struct Node_Linear *temp, *temp;
    int data;
    temp = new Node_Linear();
    if (temp == NULL)
    {
        cout << "Memory Error!!" << endl;
    }
    else
    {
        cout << "Enter number to be inserted:" << endl;
        cin >> data;
        temp->data = data;
        if (head_Linear == NULL)
        {
            temp->next = NULL;
            temp->prev = NULL;
            head_Linear = temp;
        }
        else
        {
            temp = head_Linear;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = temp;
            temp->prev = temp;
            temp->next = NULL;
        }
    }
    cout << "number inserted !!" << endl;
}
void insertAtPosition_Linear()
{
    struct Node_Linear *temp, *temp2;
    int data, position, i;
    temp = new Node_Linear();
    if (temp == NULL)
    {
        cout << "Memory Error!!" << endl;
    }
    else
    {
        temp2 = head_Linear;
        cout << "Enter the position:" << endl;
        cin >> position;
        for (i = 0; i < position; i++)
        {
            temp2 = temp2->next;
            if (temp2 == NULL)
            {
                cout << "There are less than " << position << "elements" << endl;
                return;
            }
        }
        cout << "Enter number to be inserted:" << endl;
        cin >> data;
        temp->data = data;
        temp->next = temp2->next;
        temp->prev = temp2;
        temp2->next = temp;
        temp2->next->prev = temp;
        cout << "number inserted !!" << endl;
    }
}
void deleteBeg_Linear()
{
    struct Node_Linear *temp;
    if (head_Linear == NULL)
    {
        cout << "Underflow!!" << endl;
    }
    else if (head_Linear->next == NULL)
    {
        head_Linear = NULL;
        delete (head_Linear);
        cout << "number deleted" << endl;
    }
    else
    {
        temp = head_Linear;
        head_Linear = head_Linear->next;
        head_Linear->prev = NULL;
        delete (temp);
        cout << "number deleted" << endl;
    }
}
void deleteEnd_Linear()
{
    struct Node_Linear *temp;
    if (head_Linear == NULL)
    {
        cout << "Underflow!!" << endl;
    }
    else if (head_Linear->next == NULL)
    {
        head_Linear = NULL;
        delete (head_Linear);
        cout << "number deleted" << endl;
    }
    else
    {
        temp = head_Linear;
        if (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete (temp);
        cout << "number deleted" << endl;
    }
}
void deletePosition_Linear()
{
    struct Node_Linear *temp, *temp2;
    int val;
    cout << "Enter the data after which the node is to be deleted : " << endl;
    cin >> val;
    temp = head_Linear;
    while (temp->data != val)
        temp = temp->next;
    if (temp->next == NULL)
    {
        cout << "Can't Delete!!!" << endl;
    }
    else if (temp->next->next == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        delete (temp2);
        cout << "number deleted" << endl;
    }
}

// Circular Doubly Linked List
struct Node_Circular
{
    struct Node_Circular *prev;
    struct Node_Circular *next;
    int data;
};
struct Node_Circular *head_Circular;

void traverse_Circular()
{
    struct Node_Circular *ptr;
    ptr = head_Circular;
    if (head_Circular == NULL)
    {
        cout << "Empty List!!" << endl;
    }
    else
    {
        while (ptr->next != head_Circular)
        {

            cout << ptr->data << endl;
            ptr = ptr->next;
        }
        cout << ptr->data << endl;
    }
}

void InsertBeg_Circular()
{
    struct Node_Circular *ptr, *temp;
    int item;
    ptr = new Node_Circular();
    if (ptr == NULL)
    {
        cout << "Memory Error!!" << endl;
    }
    else
    {
        cout << "Enter number to be inserted:" << endl;
        cin >> item;
        ptr->data = item;
        if (head_Circular == NULL)
        {
            head_Circular = ptr;
            ptr->next = head_Circular;
            ptr->prev = head_Circular;
        }
        else
        {
            temp = head_Circular;
            while (temp->next != head_Circular)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head_Circular->prev = ptr;
            ptr->next = head_Circular;
            head_Circular = ptr;
        }
        cout << "Number Inserted!!" << endl;
    }
}
void InsertEnd_Circular()
{
    struct Node_Circular *ptr, *temp;
    int item;
    ptr = new Node_Circular();
    if (ptr == NULL)
    {
        cout << "Memory Error!!" << endl;
    }
    else
    {
        cout << "Enter number to be inserted:" << endl;
        cin >> item;
        ptr->data = item;
        if (head_Circular == NULL)
        {
            head_Circular = ptr;
            ptr->next = head_Circular;
            ptr->prev = head_Circular;
        }
        else
        {
            temp = head_Circular;
            while (temp->next != head_Circular)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head_Circular->prev = ptr;
            ptr->next = head_Circular;
        }
    }
    cout << "Number Inserted!!" << endl;
}

void deletion_beginning()
{
    struct Node_Circular *temp;
    if (head_Circular == NULL)
    {
        cout << "Underflow!!" << endl;
    }
    else if (head_Circular->next == head_Circular)
    {
        head_Circular = NULL;
        delete (head_Circular);
        cout << "number deleted!!" << endl;
    }
    else
    {
        temp = head_Circular;
        while (temp->next != head_Circular)
        {
            temp = temp->next;
        }
        temp->next = head_Circular->next;
        head_Circular->next->prev = temp;
        delete (head_Circular);
        head_Circular = temp->next;
    }
}
void deletion_last()
{
    struct Node_Circular *ptr;
    if (head_Circular == NULL)
    {
        cout << "Underflow!!" << endl;
    }
    else if (head_Circular->next == head_Circular)
    {
        head_Circular = NULL;
        delete (head_Circular);
        cout << "number deleted!!" << endl;
    }
    else
    {
        ptr = head_Circular;
        if (ptr->next != head_Circular)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = head_Circular;
        head_Circular->prev = ptr->prev;
        delete (ptr);
        cout << "number deleted!!" << endl;
    }
}

int main()
{

    cout << "*****Doubly Linked List******" << endl;
    cout << endl;
    char choice;
    do
    {
        cout << "1.Linear:" << endl;
        cout << "2.Circular:" << endl;
        cout << "3.Exit:" << endl;
        cout << "Enter your choice-:";
        cin >> choice;

        if (choice == '1')
        {
            char choice;
            do
            {
                cout << "***Linear Doubly Linked List***" << endl;
                cout << "1. Insert at beginning:" << endl;
                cout << "2. Insert at End:" << endl;
                cout << "3. Insert at Position:" << endl;
                cout << "4. Delete from Beginning:" << endl;
                cout << "5. Delete from End:" << endl;
                cout << "6. Delete from Position:" << endl;
                cout << "7. Exit:" << endl;

                cout << "Enter your choice-:";
                cin >> choice;

                switch (choice)
                {
                case '1':
                    insertAtBeg_Linear();
                    break;
                case '2':
                    insertAtEnd_Linear();
                    break;
                case '3':
                    insertAtPosition_Linear();
                    break;
                case '4':
                    deleteBeg_Linear();
                    break;
                case '5':
                    deleteEnd_Linear();
                    break;
                case '6':
                    deletePosition_Linear();
                    break;
                default:
                    break;
                }
            } while (choice != '7');
        }
        else if (choice == '2')
        {
            char choice;
            do
            {
                cout << "***Circular Doubly Linked List***" << endl;
                cout << "1. Insert at beginning:" << endl;
                cout << "2. Insert at End:" << endl;
                cout << "3. Delete from Beginning:" << endl;
                cout << "4. Delete from End:" << endl;
                cout << "5. Exit:" << endl;
                cout << "Enter your choice-:";
                cin >> choice;

                switch (choice)
                {
                case '1':
                    InsertBeg_Circular();
                    break;
                case '2':
                    InsertEnd_Circular();
                    break;
                case '3':
                    deletion_beginning();
                    break;
                case '4':
                    deletion_last();
                    break;
                default:
                    break;
                }
            } while (choice != '5');
        }
        else
            break;

    } while (choice != '3');

    return 0;
}

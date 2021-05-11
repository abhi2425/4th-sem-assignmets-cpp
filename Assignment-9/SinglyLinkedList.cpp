#include <bits/stdc++.h>
using namespace std;

// Linear Singly Linked List
struct Node_Linear
{
    int info;
    struct Node_Linear *link;
};
struct Node_Linear *start = NULL;

void traverse_Linear()
{
    struct Node_Linear *temp;
    if (start == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    temp = start;
    while (temp != NULL)
    {
        cout << temp->info << "  ";
        temp = temp->link;
    }
    cout << endl;
}

void insertAtBeg_Linear()
{
    int data;
    struct Node_Linear *temp;
    temp = new Node_Linear();
    cout << "Enter number to be inserted:" << endl;
    cin >> data;
    temp->info = data;
    temp->link = start;
    start = temp;
    traverse_Linear();
}

void insertAtEnd_Linear()
{
    int data;
    struct Node_Linear *temp, *head;
    temp = new Node_Linear();
    cout << "Enter number to be inserted:" << endl;
    cin >> data;
    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL)
    {
        head = head->link;
    }
    head->link = temp;
    traverse_Linear();
}

void insertAtPosition_Linear()
{
    struct Node_Linear *temp, *newnode;
    int position, data, i = 1;
    newnode = new Node_Linear();
    cout << "Enter position and data:" << endl;
    cin >> position >> data;
    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < position - 1)
    {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
    traverse_Linear();
}

void deleteBeg_Linear()
{
    struct Node_Linear *temp;
    if (start == NULL)
        cout << "List is empty!!" << endl;
    else
    {
        temp = start;
        start = start->link;
        delete (temp);
        traverse_Linear();
    }
}

void deleteEnd_Linear()
{
    struct Node_Linear *temp, *prevnode;
    if (start == NULL)
        cout << "List is empty!!" << endl;
    else
    {
        temp = start;
        while (temp->link != 0)
        {
            prevnode = temp;
            temp = temp->link;
        }
        delete (temp);
        prevnode->link = 0;
        traverse_Linear();
    }
}

void deletePosition_Linear()
{
    struct Node_Linear *temp, *position;
    int i = 1, index;
    if (start == NULL)
        cout << "List is empty!!" << endl;
    else
    {
        cout << "Enter position:" << endl;
        cin >> index;
        position = new Node_Linear();
        temp = start;
        while (i < index - 1)
        {
            temp = temp->link;
            i++;
        }
        position = temp->link;
        temp->link = position->link;
        delete (position);
        traverse_Linear();
    }
}

// circular singly linked list
struct Node_Circular
{
    int data;
    struct Node_Circular *next;
};
struct Node_Circular *head = NULL;

void traverse_Circular()
{
    struct Node_Circular *current = head;
    if (head == NULL)
    {
        cout << "Empty List!!" << endl;
        return;
    }
    do
    {
        cout << current->data << "  ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

void InsertBeg_Circular()
{
    int node;
    cout << "Enter number to be inserted:" << endl;
    cin >> node;
    struct Node_Circular *newNode = new Node_Circular();
    if (!newNode)
    {
        cout << "Memory Error!!" << endl;
        return;
    }
    newNode->data = node;
    newNode->next = newNode;
    if (head == NULL)
        head = newNode;
    else
    {
        struct Node_Circular *temp = head;
        while ((temp->next) != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    traverse_Circular();
}
void InsertEnd_Circular()
{
    int node;
    cout << "Enter number to be inserted:" << endl;
    cin >> node;
    struct Node_Circular *newNode = new Node_Circular();
    if (!newNode)
    {
        cout << "Memory Error!!" << endl;
        return;
    }
    newNode->data = node;
    newNode->next = newNode;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node_Circular *temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
    }
    traverse_Circular();
}
void InsertPos_Circular()
{
    int node, position;
    cout << "Enter position and data" << endl;
    cin >> position >> node;

    struct Node_Circular *newNode = new Node_Circular();
    if (!newNode)
    {
        cout << "Memory Error!!" << endl;
        return;
    }
    newNode->data = node;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        int k = 1;
        struct Node_Circular *current = head, *previous;
        while (k < position && (current->next) != head)
        {
            k++;
            previous = current;
            current = current->next;
        }
        if (k != position)
        {
            cout << "Desired position does not exist!!" << endl;
            return;
        }
        else
        {
            newNode->next = current;
            previous->next = newNode;
        }
    }
    traverse_Circular();
}
void DeleteBeg_Circular()
{
    if (head == NULL)
    {
        cout << "Empty List!!" << endl;
        return;
    }
    struct Node_Circular *temp = head;
    struct Node_Circular *temp2 = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = head->next;
    head = head->next;
    delete (temp2);
    traverse_Circular();
}

void DeleteEnd_Circular()
{
    if (head == NULL)
    {
        cout << "Empty List!!" << endl;
        return;
    }
    struct Node_Circular *current = head, *previous;
    while (current->next != head)
    {
        previous = current;
        current = current->next;
    }
    previous->next = head;
    delete (current);
    traverse_Circular();
}

void DeletePos_Circular()
{
    int position;
    cout << "Enter The Position:" << endl;
    cin >> position;
    if (head == NULL)
    {
        cout << "Empty List!!" << endl;
        return;
    }
    struct Node_Circular *current = head, *previous;
    int k = 1;
    while (k < position && (current->next) != head)
    {
        k++;
        previous = current;
        current = current->next;
    }
    if (k != position)
    {
        cout << "Desired position does not exist!!" << endl;
        return;
    }
    previous->next = current->next;
    delete (current);
    traverse_Circular();
}

int main()
{

    cout << "*****Singly Linked List******" << endl;
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
                cout << "***Linear Singly Linked List***" << endl;
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
                cout << "***Circular Singly Linked List***" << endl;
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
                    InsertBeg_Circular();
                    break;
                case '2':
                    InsertEnd_Circular();
                    break;
                case '3':
                    InsertPos_Circular();
                    break;
                case '4':
                    DeleteBeg_Circular();
                    break;
                case '5':
                    DeleteEnd_Circular();
                    break;
                case '6':
                    DeletePos_Circular();
                    break;
                default:
                    break;
                }
            } while (choice != '7');
        }
        else
            break;

    } while (choice != '3');

    return 0;
}
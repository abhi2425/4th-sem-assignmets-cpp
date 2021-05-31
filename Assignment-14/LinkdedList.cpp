#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
Node *head = NULL;

void createList()
{
    struct Node *newNode, *temp;
    int data, i = 2;
    char choice = 'y';
    head = new Node;

    cout << "Enter the data of Node 1: " << endl;
    cin >> data;

    head->data = data;
    head->next = NULL;
    temp = head;
    do
    {
        if (choice != 'y')
            break;
        newNode = new Node;
        if (newNode == NULL)
        {
            cout << "Unable to allocate memory." << endl;
            break;
        }
        else
        {
            cout << "Enter the data of Node-" << i << endl;
            cin >> data;
            newNode->data = data;
            newNode->next = NULL;
            temp->next = newNode;
            temp = temp->next;
            i++;
            cout << "Want to add more numbers in list-: y/n" << endl;
            cin >> choice;
        }
    } while (choice != 'n' || choice != 'N');
    cout << "SINGLY LINKED LIST CREATED SUCCESSFULLY\n";
}

int countNodes()
{
    int count = 0;
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void reverseList(struct Node **head_ref)
{
    struct Node *prev = NULL;
    struct Node *current = *head_ref;
    struct Node *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void displayList()
{
    struct Node *temp;
    if (head == NULL)
        cout << "List is empty.";
    else
    {
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main()
{

    cout << endl;
    cout << "****Singly Linked List,Counting Nodes And Reverse Operation*****" << endl;
    createList();
    cout << "\nData in the list \n";
    displayList();
    int total = countNodes();
    cout << "Total number of nodes=" << total << endl;
    reverseList(&head);
    cout << "Reverse list is-:" << endl;
    displayList();
    return 0;
}
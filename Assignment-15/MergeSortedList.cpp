#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *createList()
{
    struct Node *head, *newNode, *temp;
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
    return head;
}

void displayList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Merging The Linked List using Recursion
Node *mergeSortedLists(Node *head1, Node *head2)
{
    Node *result = NULL;
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeSortedLists(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeSortedLists(head1, head2->next);
    }
    return result;
}
int main()
{
    Node *head1, *head2, *result = NULL;
    cout << endl;
    cout << "*****Merging Two Sorted Linked List*****" << endl;
    cout << "First Sorted Linked List: " << endl;
    head1 = createList();
    displayList(head1);
    cout << "Second Sorted Linked List: " << endl;
    head2 = createList();
    displayList(head2);
    result = mergeSortedLists(head1, head2);
    cout << "Final Merged Sorted List: " << endl;
    displayList(result);
    return 0;
}
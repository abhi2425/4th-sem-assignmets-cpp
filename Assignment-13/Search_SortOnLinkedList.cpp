#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head = NULL;

void display()
{
    node *current;
    current = head;
    cout << "List-:" << endl;
    while (current != NULL)
    {
        cout << current->data << endl;
        current = current->next;
    }
}
void createList(int data)
{
    node *front, *tail;
    tail = new node;
    tail->data = data;
    tail->next = NULL;
    if (head == NULL)
        head = tail;
    else
    {
        front = head;
        while (front->next != NULL)
            front = front->next;
        front->next = tail;
    }
}

void sort()
{
    node *h = head, *i, *j, *next_i;
    for (i = h; i != NULL && i->next != NULL; i = i->next)
    {
        node *min;
        min = i;
        for (j = i->next; j != NULL; j = j->next)
            if (j->data < min->data)
                min = j;
        if (min != i)
        {
            //swapping
            int temp;
            temp = min->data;
            min->data = i->data;
            i->data = temp;
        }
    }
    head = h;
}

void searchList(int item, int totalNumberOfElements)
{
    struct node *temp;
    int i = 0, flag;
    temp = head;
    if (head == NULL)
    {
        cout << "\nEmpty List\n";
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                cout << "Item found at location: " << (i + 1) << endl;
                flag = 0;
            }
            else
                flag++;

            i++;
            temp = temp->next;
        }
        if (flag == totalNumberOfElements)
            cout << "Item not found\n";
    }
}

int main()
{
    int num, totalNumberOfElements;
    int searchItem;
    char choice;
    cout << endl;
    cout << "***Searching And Selection Sort In A Linked List***" << endl;

    cout << "Enter number of elements: ";
    cin >> totalNumberOfElements;
    cout << "Enter " << totalNumberOfElements << " numbers: ";
    for (int i = 0; i < totalNumberOfElements; i++)
    {
        cin >> num;
        createList(num);
    }
    display();
    do
    {
        cout << "1. Search." << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Exit." << endl;
        cout << "Enter your choice-:" << endl;
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "Enter number to be searched-: " << endl;
            cin >> searchItem;
            searchList(searchItem, totalNumberOfElements);
            break;
        case '2':
            cout << "\nBefore sorting.\n";
            display();
            sort();
            cout << "\nAfter sorting.\n";
            display();
            break;
        case '3':
            exit(0);
            break;
        default:
            cout << "Wrong Choice!" << endl;
            break;
        }
    } while (choice != '3');
}

#include <iostream>
#include <cstdlib>
#include <malloc.h>

using namespace std;

struct Stack_Node
{
    int info;
    struct Stack_Node *next;
};

class Stack
{
    struct Stack_Node *top;

public:
    Stack();
    void push();
    void pop();
    void display();
};

Stack::Stack()
{
    top = NULL;
}

void Stack::display()
{
    struct Stack_Node *p = top;
    if (top == NULL)
        cout << "\nStack is empty!\n";
    else
    {
        cout << "\nStack elements-:\n";
        while (p != NULL)
        {
            cout << p->info << endl;
            p = p->next;
        }
    }
}

void Stack::push()
{
    int data;
    struct Stack_Node *p = new Stack_Node;
    if (p == NULL)
    {
        cout << "Out of memory" << endl;
        exit(0);
    }
    cout << "Enter a element to insert:";
    cin >> data;
    p = new Stack_Node;
    p->info = data;
    p->next = NULL;

    if (top != NULL)
        p->next = top;
    top = p;
    cout << "\nNew element inserted" << endl;
    display();
}

void Stack::pop()
{
    struct Stack_Node *temp;

    if (top == NULL)
        cout << "\nThe Stack is Empty" << endl;
    else
    {
        temp = top;
        top = top->next;
        cout << "\nThe value popped is " << temp->info << endl;
        delete temp;
    }
}

struct Queue_Node
{
    int info;
    struct Queue_Node *next;
};

class Queue
{

private:
    Queue_Node *rear;
    Queue_Node *front;

public:
    Queue();
    void enqueue();
    void dequeue();
    void display();
};

Queue::Queue()
{
    rear = NULL;
    front = NULL;
}

void Queue::display()
{
    Queue_Node *p = new Queue_Node;
    p = front;
    if (front == NULL)
        cout << "\nNothing to Display\n";
    else
    {
        while (p != NULL)
        {
            cout << endl
                 << p->info;
            p = p->next;
        }
    }
}

void Queue::enqueue()
{
    int data;
    Queue_Node *temp = new Queue_Node;
    cout << "Enter the data to enqueue: " << endl;
    cin >> data;
    temp->info = data;
    temp->next = NULL;

    if (front == NULL)
        front = temp;
    else
        rear->next = temp;
    rear = temp;
    display();
}

void Queue::dequeue()
{
    Queue_Node *temp = new Queue_Node;
    if (front == NULL)
    {
        cout << "\nQueue is Emtpty\n";
    }
    else
    {
        temp = front;
        front = front->next;
        cout << "Dequeued Element-:" << temp->info;
        delete temp;
    }
}

int main()
{
    Stack s;
    Queue queue;
    char choice;
    cout << endl;
    cout << "*****Stack and Queue Implementation using Linked List*****" << endl;
    do
    {
        cout << "1.) Stack Implementation." << endl;
        cout << "2.) Queue Implementation." << endl;
        cout << "3.) Exit." << endl;
        cout << "Enter your choice-:" << endl;
        cin >> choice;

        if (choice == '1')
        {
            int choice;
            while (choice != 4)
            {
                cout << "\nEnter your choice:";
                cout << "\n1. PUSH\n2. POP\n3. DISPLAY\n4. Exit\n";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    s.push();
                    break;
                case 2:
                    s.pop();
                    break;
                case 3:
                    s.display();
                    break;
                case 4:
                    break;
                default:
                    cout << "Invalid Choice";
                    break;
                }
            }
        }
        else if (choice == '2')
        {
            int choice;
            while (choice != 4)
            {
                cout << "\n1.Enqueue\n2. Dequeue\n3. Display\n  4.Exit\n";
                cout << "\nEnter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    queue.enqueue();
                    break;
                case 2:
                    queue.dequeue();
                    break;
                case 3:
                    queue.display();
                    break;
                case 4:
                    break;
                default:
                    cout << "\nInvalid Input. Try again! \n";
                    break;
                }
            }
        }
        else if (choice == '3')
            exit(0);
        else
            cout << "Wrong Choice!" << endl;
    } while (choice != '3');
    return 0;
}
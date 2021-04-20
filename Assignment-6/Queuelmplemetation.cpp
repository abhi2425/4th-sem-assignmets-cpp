#include <iostream>
using namespace std;

class Queue
{
public:
    int array[5], front, rear, x, result;
    void enqueue();
    void dequeue();
    void displayQueue();
    Queue()
    {
        front = 0;
        rear = 0;
    }
};
void Queue::enqueue()
{
    if (rear >= 5)
        cout << "\nQueue overflow!!\n";
    else
    {
        cout << "\nEnter the number to be inserted: ";
        cin >> x;
        rear++;
        array[rear] = x;
        cout << "\nNumber pushed in the queue:" << array[rear];
    }
    displayQueue();
}
void Queue::dequeue()
{
    if (rear == 0)
        cout << "\nQueue underflow!!\n";
    else
    {
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        else
            front++;
    }
    cout << "\nDeleted element is:";
    result = array[front];
    cout << result;
    displayQueue();
}
void Queue::displayQueue()
{
    if (rear == 0)
        cout << "\nQueue Empty!!\n";
    else
        cout << "\nContents of queue is:";
    for (int i = front + 1; i <= rear; i++)
        cout << array[i] << "\t";
}

int main()
{
    int choice;
    Queue queue;
    cout << "****Queue Implementation Using Arrays*****";
    do
    {
        cout << endl;
        cout << "\n1.Insert In the Queue\n2.Delete From the Queue\n3.Display Queue\n";
        cout << "\nEnter your choice::";
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
            queue.displayQueue();
            break;
        default:
            cout << "\nwrong choice!!\n";
        }
    } while (choice < 4);
    return 0;
}
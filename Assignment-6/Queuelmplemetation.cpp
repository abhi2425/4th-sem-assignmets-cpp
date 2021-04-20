#include <iostream>
using namespace std;
const int SIZE = 20;
class Queue
{
public:
    int array[SIZE], front, rear, value;
    int queue_size = 5;
    void enqueue();
    void dequeue();
    bool isQueueEmpty();
    void displayQueue();
    Queue()
    {
        front = 0;
        rear = 0;
    }
};
bool Queue::isQueueEmpty()
{
    return rear == 0 ? true : false;
}
void Queue::enqueue()
{
    if (rear >= queue_size)
        cout << "Queue overflow!!" << endl;
    else
    {
        cout << "\nEnter the number to be inserted: ";
        cin >> value;
        rear++;
        array[rear] = value;
        cout << "Number pushed in the queue:" << array[rear] << endl;
    }
    displayQueue();
}
void Queue::dequeue()
{
    if (isQueueEmpty())
        cout << "\nQueue is Empty!!\n";
    else
    {
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front++;
            cout << "Dequeued element is:" << array[front] << endl;
        }
        displayQueue();
    }
}
void Queue::displayQueue()
{
    if (isQueueEmpty())
        cout << "\nQueue is Empty!!\n";
    else
    {
        cout << "Queue:" << endl;
        for (int i = front + 1; i <= rear; i++)
            cout << array[i] << endl;
    }
}

int main()
{
    char choice;
    Queue queue;
    cout << "****Queue Implementation Using Arrays*****";
    do
    {
        cout << endl;
        cout << "\n1.Insert In the Queue\n2.Delete From the Queue\n3.Display Queue\n4.Quit\n";
        cout << "\nEnter your choice::";
        cin >> choice;
        switch (choice)
        {
        case '1':
            queue.enqueue();
            break;
        case '2':
            queue.dequeue();
            break;
        case '3':
            queue.displayQueue();
            break;
        case '4':
            exit(0);
            break;
        default:
            cout << "\nwrong choice!!\n";
        }
    } while (choice != '4');

    return 0;
}
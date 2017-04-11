// Kanchan Nannavare
// Class Queue using array

#include <iostream>
using namespace std;

/////////////////
// Queue class //
/////////////////

class Queue
{
private:
    string array[100];
    int n, front, back;
    
public:
    Queue() : n(0), front(0), back(0)
    {
    }
    
    void enqueue(string item)
    {
        if(n < 100 && back == 99)
        {
            back = 0;
        }
        else if (n >= 100 || back == front - 1)
        {
            cout << "Error\n";
            return;
        }
        array[back++] = item;
        n++;
    }

    string dequeue()
    {
        string item;
        item = array[front];
        array[front] = "";
        front = front + 1;
        n--;
        return item;
    }
    
    bool is_empty()
    {
        return (n == 0);
    }
    
    string get_front()
    {
        return array[front];
    }
    
};

///////////////////////////////////////////////////
// A function that displays the items in a queue //
///////////////////////////////////////////////////

void display_queue(Queue q) // q is a copy created using the copy constructor.
{
    cout << "FRONT <-- ";
    
    while (! q.is_empty())
        cout << q.dequeue() << " <-- ";
    
    cout << "BACK\n";
}

//////////////////
// Main program //
//////////////////

int main()
{
    Queue queue, copy;
    
    string fruit[] = {"apples", "blueberries", "carrots"};
    
    for (int i = 0; i < 3; i++)
    {
        cout << "The queue is empty? " << boolalpha << queue.is_empty() << endl;
        cout << "enqueueing " << fruit[i] << endl;
        queue.enqueue(fruit[i]);
        display_queue(queue);
        cout << "queue.get_front() returns " << queue.get_front() << endl << endl;
    }
    
    cout << "\nStarting to dequeue\n\n";
    
    while (! queue.is_empty())
    {
        display_queue(queue);
        cout << "queue.get_front() returns " << queue.get_front() << endl;
        cout << "queue.dequeue() returns " << queue.dequeue() << endl;
        cout << "The queue is empty? " << boolalpha << queue.is_empty() << endl << endl;
    }
    
    cout << "We are at the end\n";
    
    return 0;
}

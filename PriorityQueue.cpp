// Kanchan Nannavare
// An implementation of a priority queue using a heap.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

class Heap
{
private:
    static int const CAPACITY = 100;
    int array[CAPACITY], n;
    
    void swap(int index_1, int index_2)
    {
        int temporary = array[index_1];
        array[index_1] = array[index_2];
        array[index_2] = temporary;
    }
    
public:
    Heap()
    {
        n = 0;
    }
    
    bool insert(int value)
    {
        if (n == CAPACITY)
        {
            cout << "ERROR: Capacity of the heap exceeded." << endl;
            return false;
        }
        
        //  Put the value at the bottom of the heap.
        
        array[n] = value;
        
        //  Move the value up to its appropriate position.
        
        int index = n;
        int parent = (index - 1) / 2;
        
        while (index > 0 and array[index] > array[parent])
        {
            swap(index, parent);
            index = parent;
            parent = (index - 1) / 2;
        }
        
        n = n + 1;
        return true;
    }
    
    int pull()
    {
        if (n == 0)
        {
            cout << "ERROR: Pulling a value from an empty heap." << endl;
            return -99;
        }
        
        int return_value = array[0];
        
        //  Put a value from the bottom of the heap at the top.
        
        array[0] = array[n - 1];
        
        //  Move the value down to its appropriate position.
        
        int index = 0;
        
        while (true)
        {
            int left_child  = 2 * index + 1;
            int right_child = left_child + 1;
            int bigger_child;
            
            if (left_child >= n)
            {
                break;
            }
            
            if (right_child >= n or array[left_child] > array[right_child])
            {
                bigger_child = left_child;
            }
            else
            {
                bigger_child = right_child;
            }
            
            if (array[bigger_child] > array[index])
            {
                swap(index, bigger_child);
                index = bigger_child;
            }
            else
            {
                break;
            }
        }
        
        n = n - 1;
        return return_value;
    }
    
    bool is_empty()
    {
        return (n == 0);
    }
    
    // Display function
    
    void display()
    {
        if (this->is_empty())
        {
            return;
        }
        cout << endl;
        
        int number_of_items_in_the_current_level = 1;
        int height = 1 + log2(n);
        int field_width = 4;
        int width = pow(2, height - 1) * field_width;
        int index = 0;
        
        for (int level = 1; level <= height; level++)
        {
            if (level < height)
                cout << setw(field_width / 2) << "";
            
            for (int i = 0; i < number_of_items_in_the_current_level; i++)
            {
                if (index >= n) break;
                
                int w = ((i == 0) && (level != height) ? width/2 : width);
                cout << setw(w) << array[index++];
            }
            
            cout << endl;
            number_of_items_in_the_current_level *= 2;
            width /= 2;
        }
    }
    
    bool test_insert()
    {
        bool is_correct = false;
        
        if (n == 1)
        {
            is_correct = true;
        }
        else if (array[n-1]%2 == 1 && array[(n-2)/2] >= array[n-1])
        {
            is_correct = true;
        }
        else if (array[n-1]%2 == 0 && array[(n-3)/2] >= array[n-1])
        {
            is_correct = true;
        }
        return is_correct;
    }
    
    int get_size()
    {
        return n;
    }
    
    bool test_pull(int value, int size)
    {
        bool is_correct = false;
        
        if (size == 0 || size == 1)
        {
            is_correct = true;
            return is_correct;
        }
        
        if (array[0] != value)
        {
            is_correct = true;
        }
        else if (size == size - 1)
        {
            is_correct = true;
        }
        
        return is_correct;
    }
    
    bool test_heap()
    {
        bool is_correct = false;
        if (n == 0 || n == 1)
        {
            is_correct = true;
            return is_correct;
        }
        
        for (int i = 0; i < n; i++)
        {
            if (array[i] >= array[2*i+1] && array[i] >= array[2*i + 2])
            {
                is_correct = true;
            }
        }
        
        return is_correct;
    }
};

int main()
{
    srand(time(0));
    
    Heap priority_queue;
    
    for (int i = 0; i < 15; i++)
    {
        cout << "Insert in the priority queue:";
        int random_number = rand() % 90 + 10;
        priority_queue.insert(random_number);
        cout << ' ' << random_number << endl;
        
        if (!priority_queue.test_insert())
        {
            cout << "Somthing is wrong with the insert function" << endl;
        }
        if (priority_queue.test_heap())
        {
            priority_queue.display();
        }
        else
        {
            cout << "Something is wrong with the heap tree.\n";
        }
    }
    
    cout << endl;
    
    while (not priority_queue.is_empty())
    {
        int size_before_pull = priority_queue.get_size();
        int value = priority_queue.pull();
        cout << "Pulling from the priority queue: " << value << endl;
        
        if(!priority_queue.test_pull(value, size_before_pull))
        {
            cout << "Something is wrong with the pull function.\n";
        }
        if (priority_queue.test_heap() == true)
        {
            priority_queue.display();
        }
        else
        {
            cout << "Something is wrong with the heap tree.\n";
        }
    }
    cout << endl;
    
    return 0;
}

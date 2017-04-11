// Kanchan Nannavare
// Written on December 02, 2015
// Heap tree

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

////////////////
// Heap class //
////////////////

template<typename Type>
class Heap
{
private:
    vector<Type> value_vector;
    
    Type value(int node)
    {
        return value_vector[node];
    }
    
    int get_parent(int node)
    {
        return (node - 1) / 2;
    }
    
    void swap_values(int node1, int node2)
    {
        Type temp = value(node1);
        value_vector[node1] = value(node2);
        value_vector[node2] = temp;
    }
    
    void bubble_down(int root)
    {
        int left = 2*root + 1;
        int right = 2*root + 2;
        int max;
        
        if (right >= get_size())
        {
            if (left >= get_size())
            {
                return;
            }
            else
                max = left;
        }
        else
        {
            if (value(right) < value(left))
            {
                max = left;
            }
            else
                max = right;
        }
        
        if (value(root) < value(max))
        {
            swap_values(root, max);
            bubble_down(max);
        }
    }
    
public:
    int get_size()
    {
        return value_vector.size();
    }
    
    bool is_empty()
    {
        return value_vector.empty();
    }
    
    void add(Type new_value)
    {
        value_vector.push_back(new_value);
        
        int node = value_vector.size() - 1;
        int parent = get_parent(node);
        
        while (parent >= 0 && value(parent) < value(node))
        {
            swap_values(parent, node);
            node = parent;
            parent = get_parent(node);
        }
    }
    
    Type remove()
    {
        const int ROOT = 0;
        
        Type return_value = value(ROOT);
        
        if (get_size() > 0)
        {
            swap_values(0, get_size()-1);
            value_vector.pop_back();
            bubble_down(0);
        }
        
        return return_value;
    }
    
    void display()
    {
        if (this->is_empty()) return;
        
        int number_of_items_in_the_current_level = 1;
        int height = 1 + log2(value_vector.size());
        int field_width = 4;
        int width = pow(2, height - 1) * field_width;
        int index = 0;
        
        for (int level = 1; level <= height; level++)
        {
            if (level < height)
                cout << setw(field_width / 2) << "";
            
            for (int i = 0; i < number_of_items_in_the_current_level; i++)
            {
                if (index >= value_vector.size()) break;
                
                int w = ((i == 0) && (level != height) ? width/2 : width);
                cout << setw(w) << value(index++);
            }
            
            cout << endl;
            number_of_items_in_the_current_level *= 2;
            width /= 2;
        }
    }
};

//////////////////////////////////////////////////////
// A function to display information about the heap //
//////////////////////////////////////////////////////

template<typename Type>
void show_info(Heap<Type>& heap)
{
    cout << "The size of the heap is " << heap.get_size();
    cout << " (" << (heap.is_empty()? "" : "NOT ") << "empty)" << endl;
    cout << endl;
    heap.display();
    cout << endl << "Press ENTER to continue";
    string enter;
    getline(cin, enter);
    cout << endl;
}

//////////////////
// Main program //
//////////////////

int main()
{
    Heap<int> heap;
    show_info(heap);
    
    // Add some random values to the heap.
    
    srand(time(0));
    
    int n = 5 + rand() % 11;
    
    for (int i = 0; i < n; i++)
    {
        int random_number = rand() % 100;
        cout << "Adding " << random_number << " to the heap." << endl;
        heap.add(random_number);
        show_info(heap);
    }
    
    cout << "****************************************" << endl << endl;
    
    // Remove the values from the heap.
    
    while ( ! heap.is_empty())
    {
        cout << "Removing " << heap.remove() << " from the heap." << endl;
        show_info(heap);
    }
    
    return 0;
}

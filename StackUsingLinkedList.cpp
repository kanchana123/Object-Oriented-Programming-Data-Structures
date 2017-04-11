// Kanchan Nannavare
// Stack class using linkedlist
// Written on November 10, 2015

#include <iostream>

using namespace std;

////////////////
// Node class //
////////////////

class Node
{
private:
    
    int value;
    Node*  next;
    
public:
    
    Node(int value, Node* next = NULL) : value(value), next(next)
    {
    }
    
    void set_next(Node* next)
    {
        this->next = next;
    }
    
    int get_value()
    {
        return value;
    }
    
    Node* get_next()
    {
        return next;
    }
};

///////////////////////
// Linked list class //
///////////////////////

class LinkedList
{
private:
    Node* head;
    
public:
    LinkedList() : head(NULL) 
    {
    }
    
    void display()
    {
        Node* node = head;
        
        while (node != NULL)
        {
            cout << node->get_value() << " -> ";
            node = node->get_next();
        }
        
        cout << "NULL" << endl;
    }
    
    void add_to_head(int value)
    {
        head = new Node(value, head);
    }
    
    int get_head()
    {
        return head->get_value();
    }
    
    void remove_from_head()
    {
        if (head == NULL) return;
        Node* previous_head = head;
        head = head->get_next();
        delete previous_head;
    }
    
    bool insert_after(int existing_value, int new_value)
    {
        Node* node = head;
        
        while (node != NULL)
        {
            if (node->get_value() == existing_value)
            {
                node->set_next(new Node(new_value, node->get_next()));
                return true;
            }
            node = node->get_next();
        }
        
        return false;
    }
    
    bool remove(int value_to_be_removed)
    {
        if (head == NULL)
            return false;
        
        if (head->get_value() == value_to_be_removed)
        {
            remove_from_head();
            return true;
        }
        
        Node* node = head;
        
        while (node->get_next() != NULL)
        {
            Node* next_node = node->get_next();
            
            if (next_node->get_value() == value_to_be_removed)
            {
                node->set_next(next_node->get_next());
                delete next_node;
                return true;
            }
            
            node = node->get_next();
        }
        return false;
    }
    
    int operator[](int index)
    {
        Node* node = head;    
        
        for (int i = 0; i < index; i++)
        {
            node = node->get_next();
        }
        
        return node->get_value();
    }
};

class Stack
{
private:
    LinkedList list;
    int n;
public:
    Stack() : list(), n(0)
    {
    }
    
    void push(int value)
    {
        list.add_to_head(value);
        n++;
    }
    
    int pop()
    {
        int value = list.get_head();
        list.remove_from_head();
        n--;
        
        return value;
    }
    
    int get_top()
    {
        return list.get_head();
    }
    
    bool is_empty()
    {
        return (n == 0);
    }
};

//////////////////
// Main program //
//////////////////

int main()
{
    Stack stack;
    
    cout << "The stack " << (stack.is_empty() ? "IS" : "is NOT") << " empty."
    << endl << endl;
    
    int values[] = {2,7,5,3,9};
    
    for (int i = 0; i < 5; i++)
    {
        stack.push(values[i]);
        cout << "The item on top of the stack is " << stack.get_top() << endl;
    }
    
    cout << endl;
    
    while (! stack.is_empty())
    {
        cout << "The item on top of the stack is " << stack.get_top() << endl;
        cout << "pop returns " << stack.pop() << endl;
        cout << "The stack " << (stack.is_empty() ? "IS" : "is NOT") << " empty."
        << endl << endl;
    }
    
    return 0;  
}


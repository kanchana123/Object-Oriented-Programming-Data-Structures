// Kanchan Nannavare
// Sorted list

/* C++ class that uses a linked list to maintain a sorted (alphabetically) list of strings.  */


#include <iostream>
#include <vector>

using namespace std;

////////////////
///// Menu /////
////////////////

class Menu
{
private:
    vector<string> options;
    
public:
    Menu(string options_array[], int n)
    {
        for (int i = 0; i < n; i++)
            options.push_back(options_array[i]);
    }
    
    void display_options()
    {
        cout << "<<<< OPTIONS >>>>" << endl;
        
        for (int i = 0; i < options.size(); i++)
            cout << (i + 1) << ": " << options[i] << endl;
    }
    
    int get_input()
    {
        cout << "Please enter an option (1-" << options.size() << "): ";
        int option;
        cin >> option;
        return option;
    }
};

////////////////
/// Node ///////
////////////////

class Node
{
private:
    string value;
    Node* next;
public:
    
    Node(string value, Node* next = NULL) : value(value), next(next)
    {
        
    }
    
    void set_next(Node* next)
    {
        this->next = next;
    }
    
    string get_value()
    {
        return value;
    }
    
    Node* get_next()
    {
        return next;
    }
};

///////////////////
/// Linked List ///
///////////////////

class LinkedList
{
private:
    Node* head;
public:
    LinkedList() : head(NULL)
    {
        
    }
    
    LinkedList(string value)
    {
        head = new Node(value);
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
    
    void add_to_head(string value)
    {
        head = new Node(value, head);
    }
    
    void remove_from_head()
    {
        if (head == NULL)
        {
            return;
        }
        Node* previous_head = head;
        head = head->get_next();
        delete previous_head;
    }
    
    bool insert_after(string existing_value, string new_value)
    {
        Node* node = head;
        
        while (node!=NULL)
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
    
    bool remove(string value_to_be_removed)
    {
        if (head == NULL)
        {
            return false;
        }
        if (head->get_value() == value_to_be_removed)
        {
            remove_from_head();
            return true;
        }
        
        Node* node = head;
        
        while (node != NULL)
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
    
    string operator[](int index)
    {
        Node* node = head;
        for (int i = 0; i < index; i++)
        {
            node = node->get_next();
        }
        string something = node->get_value();
        return  something;
    }
    
    int get_size()
    {
        int count = 0;
        Node* node = head;
        LinkedList list;
        
        while (node != NULL)
        {
            node = node->get_next();
            count++;
        }
        
        return count;
    }
};

///////////////////
/// Sorted List ///
///////////////////

class SortedList
{
private:
    LinkedList list;
    Node* head;
public:
    SortedList() : head(NULL)
    {
        
    }
    
    SortedList(LinkedList another_list) : list(another_list)
    {
        
    }
    
    void display()
    {
        vector<string> my_list;
        for (int i = 0; i < list.get_size(); i++)
        {
            my_list.push_back(list[i]);
        }
        
        sort(my_list.begin(), my_list.end());
    
        for (int i= 0; i < my_list.size(); i++)
        {
            cout << my_list[i] << " -> ";
        }
        cout << "NULL" << endl;
    }
};

//////////////
//// Main ////
//////////////

int main()
{
    string options[] = {"Add an item",
        "Remove an item",
        "Quit"};
    
    Menu menu = Menu(options, 3);
    int option;
    
    LinkedList list;
    do {
        SortedList sorted_list(list);
        sorted_list.display();
        menu.display_options();
        option = menu.get_input();
        string user_input;
        if (option == 1)
        {
            cout << "Enter an item to add to this list: ";
            cin >> user_input;
            list.add_to_head(user_input);
        }
        else if (option == 2)
        {
            cout << "Enter an item to remove from this list: ";
            cin >> user_input;
            list.remove(user_input);
        }
    } while (option != 3);
    
    return 0;
}

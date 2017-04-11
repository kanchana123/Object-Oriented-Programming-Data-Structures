// Kanchan Nannavare
// Train class that uses a linked list to contain the collection of railroad cars.

#include <iostream>
#include <vector>

using namespace std;

////////////////
// Node class //
////////////////

class Node
{
private:
    string value;
    Node   *next;
    
public:
    Node(string value_parameter, Node *pointer)
    {
        value = value_parameter;
        next  = pointer;
    }
    
    friend class LinkedList;
};

///////////////////////
// Linked list class //
///////////////////////

class LinkedList
{
private:
    Node *head;
    
public:
    LinkedList()
    {
        head = NULL;
    }
    
    ~LinkedList()
    {
        while (head != NULL)
        {
            remove_head();
        }
    }
    
    void add_to_head(string value)
    {
        head = new Node(value, head);
    }
    
   
    void remove_head()
    {
        if (head == NULL) {
            return;
        }
        
        Node *head_new = head->next;
        delete head;
        head = head_new;
    }
    
       int get_size()
    {
        Node *node = head;
        int size = 0;
        while (node != NULL) {
            size++;
            node = node->next;
        }
        return size;
    }
    
    void display()
    {
        Node *node = head;
        
        while(node != NULL)
        {
            cout << node->value;
            node = node->next;
        }
        cout << endl;
        
    }
};

////////////////////////////////
/////////// CLASS TRAIN ///////
//////////////////////////////

class Train
{
private:
    LinkedList row1, row2, row3, row4;
public:
    
    void locomotive()
    {
        if (row1.get_size() < 8)
        {
            row1.add_to_head(" ___      ");
            row2.add_to_head(" |__|__i  ");
            row3.add_to_head(" |      | ");
            row4.add_to_head("-O-O---oo-");
        }
    }
    
    void box_car()
    {
        if (row1.get_size() < 8)
        {
            row1.add_to_head("          ");
            row2.add_to_head("  _____   ");
            row3.add_to_head(" |  %  |  ");
            row4.add_to_head("--o---o--+");
        }
    }
    
    void flat_car()
    {
        if (row1.get_size() < 8)
        {
            row1.add_to_head("          ");
            row2.add_to_head("          ");
            row3.add_to_head(" ._____.  ");
            row4.add_to_head("--o---o--+");
        }
    }
    
    void caboose()
    {
        if (row1.get_size() < 8)
        {
            row1.add_to_head("    _     ");
            row2.add_to_head("  _'_'_   ");
            row3.add_to_head(" |     |  ");
            row4.add_to_head("--o---o--+");
        }
    }
    
    void remove()
    {
        if (row1.get_size() != 0) {
            row1.remove_head();
            row2.remove_head();
            row3.remove_head();
            row4.remove_head();
        }
        return;
    }
    
    void tracks()
    {
        for (int i = 0; i < 80; i++) {
            cout << "~";
        }
        cout << endl;
    }
    
    void display()
    {
        if (row1.get_size() == 0)
        {
            cout << "No more cars to show. Add more cars.\n";
            return;
        }
        else {
            row1.display();
            row2.display();
            row3.display();
            row4.display();
            tracks();
        }
        return;
    }
};

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
    
    int prompt()
    {
        cout << "Please enter an option (1-" << options.size() << "): ";
        int option;
        cin >> option;
        return option;
    }
};

//////////////////
// Main program //
//////////////////

int main()
{
    Train train;
    const int OPTIONS = 6;
    
    string options[OPTIONS] = {"Add a locomotive to the train",
                                "Add a box car to the train",
                                "Add a flat car to the train",
                                "Add a caboose to the train",
                                "Remove the last car", "Quit"};
    
    Menu menu(options, OPTIONS);
    int option;
    
    do
    {
        menu.display_options();
        option = menu.prompt();
        cout << endl;
        
        if (option == 1)
        {
            train.locomotive();
        }
        else if (option == 2)
        {
            train.box_car();
        }
        else if (option == 3)
        {
            train.flat_car();
        }
        else if (option == 4)
        {
            train.caboose();
        }
        else if (option == 5)
        {
            train.remove();
        }
        
        train.display();
        
    } while (option != 6);
    
    
    return 0;
}

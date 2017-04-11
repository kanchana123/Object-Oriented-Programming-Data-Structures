// Kanchan Nannavare
// This program implements a deque using a doubly-linked list.

#include <iostream>

using namespace std;

//////////////////
/// MENU CLASS ///
//////////////////

class Menu
{
private:
    string *options;
    int n;
    
public:
    Menu(string input_options[], int n)
    {
        this->n = n;
        options = new string[n];
        
        for (int i = 0; i < n; i++)
            this->options[i] = input_options[i];
    }
    
    ~Menu()
    {
        delete[] options;
    }
    
    void display()
    {
        cout << "<<<< OPTIONS >>>>\n";
        for (int i = 0; i < n; i++)
            cout << (i+1) << ": " << options[i] << endl;
    }
    
    int prompt()
    {
        int option;
        do
        {
            cout << "Please enter an option (1-" << n << "): ";
            cin >> option;
        }
        while (option < 1 || option > n);
        return option;
    }
};

//////////////////
/// NODE CLASS ///
//////////////////

template<typename Type> class Deque;

template<typename Type>
class Node
{
private:
    Type value;
    Node *previous, *next;
    
    Node(Type value, Node *previous, Node *next)
    {
        this->value = value;
        this->previous = previous;
        this->next = next;
    }
    
    friend class Deque<Type>;
};

///////////////////
/// DEQUE ClASS ///
///////////////////

template<typename Type>
class Deque
{
private:
    Node<Type> *back, *front;
    
public:
    Deque()
    {
        back = front = NULL;
    }
    
    ~Deque()
    {
        while (back != NULL)
        {
            pop_back();
        }
    }
    
    void push_front(Type value)
    {
        if (front == NULL)
            front = back = new Node<Type>(value, NULL, NULL);
        else
        {
            front = new Node<Type>(value, front, NULL);
            front->previous->next = front;
        }
    }


    Type pop_front()
    {
        if (front == NULL)
        {
            cout << "\nERROR: List is empty.\n\n";
        }
        
        Type front_value = front->value;
        
        if (front == back)
        {
            delete front;
            front = back = NULL;
        }
        else
        {
            front = front->previous;
            delete front->next;
            front->next = NULL;
        }
        
        return front_value;
    }
    
    void push_back(Type value)
    {
        if (back == NULL)
            back = front = new Node<Type>(value, NULL, NULL);
        else
        {
            back = new Node<Type>(value, NULL, back);
            back->next->previous = back;
        }
    }
    
    Type pop_back()
    {
        
        if (back == NULL)
        {
            
            cout << "\nERROR: List is empty.\n\n";
        }
        
        Type back_value = back->value;
        
        if (back == front)
        {
            delete back;
            back = front = NULL;
        }
        else
        {
            back = back->next;
            delete back->previous;
            back->previous = NULL;
        }
        
        return back_value;
    }
    
    bool is_empty()
    {
        if (back == NULL && front == NULL)
        {
            return true;
        }
        
        return false;
    }

    void display()
    {
        for (Node<Type>* node = back; node != NULL; node = node->next)
        {
            cout << node->value;
            if (node != front)
            {
                cout << " --> ";
            }
        }
        cout << endl;
    }
    
};


////////////////////
/// MAIN PROGRAM ///
////////////////////

int main()
{
    string options[] = {"push_front", "pop_front",
                        "push_back", "pop_back",
                        "quit"};
    const int OPTIONS = 5;
    Menu menu(options, OPTIONS);
    menu.display();

    int option = menu.prompt();

    Deque<string> *deque_pointer;
    deque_pointer = new Deque<string>();
    Deque<string> deque = *deque_pointer;
    
    do {

        if (option == 1)
        {
            cout << "Enter item to add to the front of the list: ";
            string user_input;
            cin >> user_input;
            deque.push_front(user_input);
        }
        else if (option == 2)
        {
            cout << "Front item in the list is " << deque.pop_front() << "\n";
        }
        else if (option == 3)
        {
            cout << "Enter item to add to the back of the list: ";
            string user_input;
            cin >> user_input;
            deque.push_back(user_input);
        }
        else if (option == 4)
        {
            cout << "Back item in the list is " << deque.pop_back() << "\n";
        }
        
        if (deque.is_empty() != true)
        {
            deque.display();
        }
        menu.display();
        option = menu.prompt();

    } while (option != 5);
    
    return 0;
}


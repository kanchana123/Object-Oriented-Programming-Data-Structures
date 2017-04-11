// Kanchan Nannavare
// Binary search tree without recursion

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

///////////////////////////////////
// Binary Search Tree Node Class //
///////////////////////////////////

class BST_Node
{
private:
    int value;
    BST_Node *left_child, *right_child;
    
public:
    BST_Node(int value)
    {
        this->value = value;
        left_child = NULL;
        right_child = NULL;
    }
    
    friend class BinarySearchTree;
};

//////////////////////////////
// Binary Search Tree Class //
//////////////////////////////

class BinarySearchTree
{
private:
    BST_Node* root;
    
    void inorderTraversal(BST_Node* root);
    BST_Node* search(int target, BST_Node* root, BST_Node* &parent);
    void moveNodeUp(BST_Node* node, BST_Node* parent, BST_Node* &grandparent);
    int get_height(BST_Node* root);
    
public:
    BinarySearchTree();
    BinarySearchTree(int value);
    ~BinarySearchTree();
    void add(int value);
    void remove(int value);
    bool search(int target);
    void display();
    bool is_empty();
    int get_height();
};

BinarySearchTree::BinarySearchTree() : root(NULL)
{
}

BinarySearchTree::BinarySearchTree(int value) : root(new BST_Node(value))
{
}

BinarySearchTree::~BinarySearchTree()
{
    while (root != NULL)
        remove(root->value);
}

void BinarySearchTree::add(int value)
{
    BST_Node *temp, *parent;
    if (root == NULL)
    {
        root = new BST_Node(value);
    }
    else
    {
        temp = root;
        while (temp != NULL)
        {
            parent = temp;
            if (value <= temp->value)
            {
                temp = temp->left_child;
            }
            else
            {
                temp = temp->right_child;
            }
        }
        
        BST_Node *new_node = new BST_Node(value);
        if (value <= parent->value)
        {
            parent->left_child = new_node;
        }
        else
            parent->right_child = new_node;
    }
    
}

bool BinarySearchTree::search(int target)
{
    BST_Node *temp;
    temp = root;
    
    if (root->value == target)
    {
        return true;
    }
    else
    {
        while (temp != NULL)
        {
            if (target == temp->value)
            {
                return true;
            }
            else if (target <= temp->value)
            {
                temp = temp->left_child;
            }
            else
            {
                temp = temp->right_child;
            }
        }
    }
    return false;
}

BST_Node* BinarySearchTree::search(int target, BST_Node* root, BST_Node* &parent)
{
    if (root == NULL || root->value == target) return root;
    
    parent = root;
    
    if (target > root->value)
        return search(target, root->right_child, parent);
    else
        return search(target, root->left_child, parent);
}

int BinarySearchTree::get_height()
{
    return get_height(root)-1;
}

int BinarySearchTree::get_height(BST_Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int left_height = get_height(root->left_child);
        int right_height = get_height(root->right_child);
        return max(left_height, right_height)+1;
    }
}

void BinarySearchTree::remove(int value)
{
    BST_Node* parent = NULL;
    BST_Node* location = search(value, root, parent);
    
    if (location == NULL) return;
    
    if (location->left_child == NULL)
    {
        moveNodeUp(location->right_child, location, parent);
    }
    else if (location->right_child == NULL)
    {
        moveNodeUp(location->left_child, location, parent);
    }
    else
    {
        BST_Node* parent = location;
        BST_Node* node = location->left_child;
        
        while (node->right_child != NULL)
        {
            parent = node;
            node = node->right_child;
        }
        
        location->value = node->value;
        moveNodeUp(node->left_child, node, parent);
    }
}

void BinarySearchTree::moveNodeUp(BST_Node* node,
                                  BST_Node* parent,
                                  BST_Node* &grandparent)
{
    if (grandparent == NULL)
        root = node;
    else if (parent == grandparent->left_child)
        grandparent->left_child = node;
    else
        grandparent->right_child = node;
    
    delete parent;
}

void BinarySearchTree::display()
{
    inorderTraversal(root);
    cout << endl;
}

void BinarySearchTree::inorderTraversal(BST_Node* root)
{
    if (root == NULL) return;
    
    inorderTraversal(root->left_child);
    cout << root->value << ' ';
    inorderTraversal(root->right_child);
}

bool BinarySearchTree::is_empty()
{
    return (root == NULL);
}

//////////////////
// Main Program //
//////////////////

int main()
{
    BinarySearchTree tree;
    
    cout << "The tree is " << (tree.is_empty() ? "" : "NOT") << " empty.\n";
    
    int array[22] = {41, 23, 56, 7, 31, 52, 84, 0, 11, 24, 33, 32, 61, 22, 45, 55, 65, 75, 85, 95, 99, 3};
    
    for (int i = 0; i < 22; i++)
        tree.add(array[i]);
    
    tree.display();
    cout << endl;
    
    srand(time(0));
    
    while(! tree.is_empty())
    {
        int random_index = rand() % 22;
        if (tree.search(array[random_index]))
        {
            cout << "Attempting to remove " << array[random_index] << endl;
            cout << "Searching for " << array[random_index] << " returns " << boolalpha
            << tree.search(array[random_index]) << endl;
            cout << "Height is " << tree.get_height() << endl;
            tree.remove(array[random_index]);
            tree.display();
        }
    }
    
    return 0;
}


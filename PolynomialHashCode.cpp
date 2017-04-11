// Kanchan Nannavare
// Hashtable - polynomial hash code

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//////////////////////
// Hash table class //
//////////////////////

class HashTable
{
private:
    static const int N = 11;
    string table[N];
    int collision;
    
    int hashFunction(string value)
    {
        int a = 32;
        unsigned long total = 0;
        for (int i = 0; i < value.length(); i++)
            total = (total*a) + int(value[i]);          // Polynomial hash code
        
        return total % N;
    }
    
public:
    void add(string value)
    {
        int index = hashFunction(value);
        collision = 0;
        
        for(int i = 0; i < N; i++)
        {
            if (table[(index + i) % N] == "" || table[(index + i) % N] == "#")
            {
                table[(index + i) % N] = value;
                collision = collision + i;          // counts collisions for each value
                return;
            }
        }
        
        cout << endl << "WARNING: The table is full." << endl << endl;
    }
    
    void remove(string value)
    {
        int index = hashFunction(value);
        
        for(int i = 0; i < N; i++)
        {
            if (table[(index + i) % N] == "") break;
            if (table[(index + i) % N] == value)
            {
                table[(index + i) % N] = "#";
                return;
            }
        }
        
        cout << endl << "WARNING: " << value << " is not in the table" << endl << endl;
    }
    
    bool search(string value)
    {
        int index = hashFunction(value);
        for(int i = 0; i < N; i++)
        {
            if (table[(index + i) % N] == value) return true;
            if (table[(index + i) % N] == "") return false;
        }
        return false;
    }
    
    void display()
    {
        for (int i = 0; i < N; i++)
            cout << setw(2) << i << ": " << table[i] << endl;
    }
    
    int no_of_collisions()
    {
        return collision;
    }
};

//////////////////
// Main program //
//////////////////

int main()
{
    HashTable hashTable;
    
    string names[6] = {"Pheobe", "Joey", "Chandler", "Ross", "Monica", "Rachel"};
    
    int j = 0;
    while (j < 2)
    {
        for (int i = 0; i < 6; i++)
        {
            hashTable.add(names[i]);
            cout << names[i] << " collides " << hashTable.no_of_collisions() << " times.\n";
            hashTable.display();
        }
        j++;
    }
    
    /*
     With the old function, the values added in the beginning doesn't collide much but the last value collides a lot. In this case last one collided 10 times and others in range of 1 - 3 colligions per value. When I changed the hash function to polynomial, there is not much collision in the beginning but it is higher for last 4-6 values and it's in range of 3-7 collisions for each value.
     */

    
    return  0;
}

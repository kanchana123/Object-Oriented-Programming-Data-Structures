// Kanchan Nannavare
// This Programs prints old MacDonland Farm song

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Animal
{
protected:
    string name;
public:
    Animal()
    {
    }
    
    Animal(string name_animal)
    {
        this->name = name_animal;
    }
    
    string get_name()
    {
        return name;
    }
    
    void display_info()
    {
        cout << "A " << name << " is an animal\n";
        return;
    }
};

class FarmAnimal : public Animal
{
protected:
    string sound;
public:
    FarmAnimal(Animal animal) : Animal(animal)
    {
    }
    
    FarmAnimal(string name_animal, string sound_animal)
    {
        this->name = name_animal;
        this->sound = sound_animal;
    }
    
    string get_sound()
    {
        return sound;
    }
    void display_info()
    {
        cout << "A " << name << " is an animal that makes the sound " << sound << endl;
        return;
    }
};

class Verse : public FarmAnimal
{
public:
    Verse(FarmAnimal farm_animal) : FarmAnimal(farm_animal)
    {
        
    }
    
    void display()
    {
        cout << "Old MacDonald had a farm, E-I-E-I-O\n";
        cout << "And on that farm he had a " << name << ", E-I-E-I-O\n";
        cout << "With a " << sound << " " << sound << " here and a " << sound << " " <<
                sound << " there\n";
        cout << "Here a " << sound << ", there a " << sound << ", everywhere a " <<
                sound << " " << sound << endl;
        cout << "Old MacDonald had a farm, E-I-E-I-O\n";
    }
};

class OldMacDonald : public Verse
{
private:

public:
    OldMacDonald(Verse verse) : Verse(verse)
    {

    }
    
    void add_verse(FarmAnimal farm_animal)
    {
        Verse verse(farm_animal);
        verse.display();
        return;
    }
    
    void display(FarmAnimal farm_animal_1, FarmAnimal farm_animal_2, FarmAnimal farm_animal_3)
    {
  
        add_verse(farm_animal_1);
        cout << endl;
        add_verse(farm_animal_2);
        cout << endl;
        add_verse(farm_animal_3);
        cout << endl;
    }
    
    void WhichAnimalMakesTheSound(string animal_sound)
    {
        if (animal_sound == "moo")
        {
            FarmAnimal cow("cow", "moo");
            cow.display_info();
        }
        else if (animal_sound == "oink")
        {
            FarmAnimal pig("pig", "oink");
            pig.display_info();
        }
        else if (animal_sound == "cluck")
        {
            FarmAnimal hen("hen", "cluck");
            hen.display_info();
        } else {
            cout << "Old MacDonald did not have an animal that makes the sound " <<
                    animal_sound << " on his farm\n";
        }
    }
};

int main()
{
    Animal animal("fish");
    animal.display_info();
    
    FarmAnimal farm_animal_cow("cow","moo");
    FarmAnimal farmer("farmer", "\"Farming is hard work!\"");
    
    farm_animal_cow.display_info();
    farmer.display_info();
    
    Verse verse(farm_animal_cow);
    verse.display();
    
    OldMacDonald old_macdonald(verse);
    FarmAnimal farm_animal_pig("pig", "oink");
    FarmAnimal farm_animal_hen("hen", "cluck");
    old_macdonald.display(farm_animal_cow, farm_animal_pig, farm_animal_hen);

    cout << "Please enter an animal sound: ";
    string sound;
    cin >> sound;
    
    old_macdonald.WhichAnimalMakesTheSound(sound);

    return 0;
}

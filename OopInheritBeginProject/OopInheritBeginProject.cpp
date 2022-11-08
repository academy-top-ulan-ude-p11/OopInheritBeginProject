#include <iostream>

using namespace std;

class Unit
{
protected:
    string title;
    int health;

public:
    Unit() : title{ "Unit" }, health{ 0 } {};
    Unit(string title, int health) : title{ title } 
    {
        this->health = (health < 0) ? 0 : health;
    };
    
    string& Title()
    {
        return title;
    }

    void SetHealth(int health)
    {
        this->health = (health < 0) ? 0 : health;
    }

    int GetHealth()
    {
        return health;
    }

    void Info()
    {
        cout << "Unit: " << title << " [" << health << "]";
    }



    friend ostream& operator<<(ostream& out, const Unit& unit)
    {
        out << "Unit: " << unit.title << " [" << unit.health << "]";
        return out;
    }
};

class HumanUnit : public Unit
{
    int moveMax;
public:
    HumanUnit() : Unit(), moveMax{ 0 } {}
    HumanUnit(string title, int health, int moveMax) 
                    : Unit(title, health), moveMax{ moveMax }
    {
        //this->title = title;
        //this->health = health;
    }

    void Info()
    {
        Unit::Info();
        cout << " -> " << moveMax;
    }

    void Move()
    {
        cout << "unit " << title << " move\n";
    }


    friend ostream& operator<<(ostream& out, const HumanUnit& unit)
    {
        out << "Unit: " << unit.title << " [" << unit.health << "] -> " << unit.moveMax;
        return out;
    }
};

class NonHumanUnit : public Unit
{
    float volume;
};


int main()
{
    HumanUnit human("Infantry", 100, 5);

    human.Info();
    human.SetHealth(100);
}


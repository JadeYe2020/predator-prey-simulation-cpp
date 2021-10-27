#include <iostream>
#include <conio.h> //for pause
#include <cstdlib>
#include <string>
using namespace std;

class Weapon {
    public:
        Weapon(){}; //default constructor
        ~Weapon(){};

        double calcSwordDamage(){
            return 5 + rand() % 20; //to return a random double from 5 to 25
        } //end method

        double calcFlameDamage(){
            return 10 + rand() % 15;
        } //end method
}; //end class Weapon

class CharacterClass{
    private:
        char charType; //k= knight, d=dragon
        double health;
        int dex;
        int stren;
        int armor;
        Weapon weap; //aggregate member

    public:
        CharacterClass() {};

        //Constructor for knight
        CharacterClass(char ct, double hlth, int dx, int st, int arm)
            :charType(ct), health(hlth), dex(dx), stren(st), armor(arm) //initialization section
            {} //empty body b/c initialization section is used

        //Constructor for dragon
        CharacterClass(char ct, double hlth, int dx, int st)
            :charType(ct), health(hlth), dex(dx), stren(st) //initialization section
            {}

        //property procedures
        void setHealth(double health) { this->health = health;}
        double getHealth() {return this->health;}

        //Attack, def, die methods
        double calcDefense(){
            if(charType == 'k')
                return dex+armor+rand()%11;
            else
                return dex+rand()%16;
        }

        double calcAttack(){
            if(charType == 'k')
                return weap.calcSwordDamage() + dex + stren;
            else
                return weap.calcFlameDamage() + dex + stren;
        }

        string die(){
            if(charType == 'k')
                return "Dragon won - Yea for evil!";
            else
                return "Knight won - Hazzah for good!";
        }

}; //end class CharacterClass

int main() {
    int ran;
    double defense, attack, damage;

    //instance game characters, locally, so no "new"
    CharacterClass Knight('k', 300, 30, 20, 20);
    CharacterClass Dragon('d', 300, 20, 10);

    cout << "The battle begins!" << endl;
    cout << "Press any key to continue" << endl;
    _getch(); //pause for get a character entered

    //battle logic
    do{
        ran = rand()%2; //0=k, 1=d
        if(ran == 0) //knight attacks
        {
            defense = Dragon.calcDefense();
            attack = Knight.calcAttack();
            damage = attack - defense;
            if(defense > attack)
                damage = 0;
            Dragon.setHealth(Dragon.getHealth() - damage);
            cout << "Dragon was hit for " << damage << endl;
            cout << "Dragon has " << Dragon.getHealth() << " left" << endl;
        }
        else
        {
            defense = Knight.calcDefense();
            attack = Dragon.calcAttack();
            damage = attack - defense;
            if(defense > attack)
                damage = 0;
            Knight.setHealth(Knight.getHealth() - damage);
            cout << "Knight was hit for " << damage << endl;
            cout << "Knight has " << Knight.getHealth() << " left" << endl;
        }

    } while(Knight.getHealth()>0 && Dragon.getHealth()>0);

    if(Knight.getHealth()<=0)
        cout << Knight.die() << endl;
    else
        cout << Dragon.die() << endl;

    cout << "Battle Ended" << endl;

    return 0;
} //end main

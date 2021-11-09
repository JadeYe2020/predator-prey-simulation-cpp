//Demo driver for Vehicle and its sub classes

#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Boat.h"
#include "Bicycle.h"

//prototypes
void withoutCasting();
void sliceExample();
void upCasting();
void downCasting();
void typeIDExample();
void polyExample();

int main() {
//    withoutCasting();
//    sliceExample();
//    upCasting();
//    downCasting();
//    typeIDExample();
    polyExample();

    return 0;
} //end main

//Method implementations
void withoutCasting()
{
    Bicycle myBike;
    Boat myBoat;
    cout << myBike.BlowHorn() << endl; //early bind
    cout << myBoat.BlowHorn() << endl; //early bind
}

void sliceExample()
{
    Bicycle myBike;
//    Vehicle v1 = myBike; //implicit upcast
    Vehicle v1 = (Vehicle) myBike; //explicit upcast
    cout << v1.BlowHorn() << endl;
    //solution is to use pointers and dynamic variables so that we can treat v1 as a Bicycle at runtime and not slice it
}

void upCasting()
{
    Vehicle *pV = new Vehicle; //declared on heap mem
    Bicycle *pBic = new Bicycle;
    Boat *pBoat = new Boat;
    pV = pBic; //up cast
    cout << pV->BlowHorn() << endl;
}

void downCasting()
{
    cout << "upcast Boat to Vehicle pointer: " << endl;
    Vehicle *pV = new Boat; //up cast Boat
    Bicycle *pBic = dynamic_cast<Bicycle*>(pV);
    cout << "pBic = " << pBic << endl; //wrong type returns null pointer
    Boat *pBoat = dynamic_cast<Boat*>(pV);
    cout << "pBoat = " << pBoat << endl;
}

void typeIDExample()
{
    Vehicle *pV = new Boat;
    if(typeid(Bicycle) == typeid(*pV))
        cout << "pV points to a Bicycle" << endl;
    else
        cout << "pV points to a Boat" << endl;
}

void polyExample() //late binding routine
{
    Vehicle *pV = new Vehicle; //declared on heap mem
    Bicycle *pBic = new Bicycle;
    Boat *pBoat = new Boat;

//    Vehicle *pVArray[2]; //declared on stack mem
    Vehicle **pVArray = new Vehicle*[2];

    pVArray[0] = (Vehicle*)pBic;
    pVArray[1] = (Vehicle*)pBoat;

    for(int i=0; i<2; i++)
    {
        cout << pVArray[i]->BlowHorn() << endl; //late bind
    }
}

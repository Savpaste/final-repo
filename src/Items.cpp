#include<iostream>
#include<string>
#include "Items.h"
using namespace std;


//Initializes static counter of items created
int Item::totalItems = 0;

//Overload constructor for items
Item::Item(string name, int value)
    : name(name),
    value(value) {
    totalItems++;
    }

Item::~Item() {

}

int Item::getTotalItems() {
    return totalItems;
}

//Calls the operator overloader for adding items and returns the item name and value
ostream& operator<<(ostream& out, const Item& item) {
    out << item.name  << " (Value: " << item.value << ")";
    return out;
}

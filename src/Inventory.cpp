#include<iostream>
#include "Inventory.h"
#include "Items.h"
using namespace std;

//Overload constructor for Inventory
Inventory::Inventory(int capacity)
    : capacity(capacity) {
    itemCount = 0;
    items = new Item*[capacity];
    for(int i = 0; i < capacity; i++) {
        //Initializes each slot to nullptr
        items[i] = nullptr;
    }
}

//Deep copy constructor for Inventory
Inventory::Inventory(const Inventory& others) {
    capacity = others.capacity;
    itemCount = others.itemCount;
    items = new Item*[others.capacity]; //Allocates new array for deep copy
    for(int i = 0; i < itemCount; i++) { //Copies each item
        items[i] = new Item(*others.items[i]); //Call Item copy constructor
    }
    for(int i = 0; i < capacity; i++) { //Initializes remaining slots to nullptr
        items[i] = nullptr;
    }
}

//Destructor for Inventory
Inventory::~Inventory() {
    for(int i = 0; i < itemCount; i++) {}
    delete[] items;
}

//Function to add items depending on if the capacity has been reached or not
bool Inventory::addItem(const Item& item) {
    if (itemCount < capacity) {
        items[itemCount] = new Item(item);
        itemCount++;
        return true;
    }
    return false;
}

//Function to display the item count and item capacity
void Inventory::display() const {
    cout << "(" << itemCount << "/" << capacity << "):" << endl;
    for(int i = 0; i < itemCount; i++) {
        cout << "-" << *items[i] << endl;
    }
}

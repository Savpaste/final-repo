//
// Created by Avery Williams on 10/24/25.
//

#ifndef FINAL_REPO_LOCAL_INVENTORY_H
#define FINAL_REPO_LOCAL_INVENTORY_H


#include "Items.h"

//Class that handles the overall inventory for a player
class Inventory {

    private:
    Item** items; //Dynamic array of pointers to items
    int capacity;
    int itemCount;

    public:
    //Constructor and deconstructor
    Inventory(int capacity);
    Inventory(const Inventory& other);
    ~Inventory();

    //Inventory actions
    bool addItem(const Item& item);
    void display() const;


};

#endif //FINAL_REPO_LOCAL_INVENTORY_H
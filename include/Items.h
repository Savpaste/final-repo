#ifndef FINAL_REPO_LOCAL_ITEMS_H
#define FINAL_REPO_LOCAL_ITEMS_H


#include "string"


//Class that handles individual items
class Item {

    private:
    static int totalItems;
    std::string name;
    int value;

    public:
    //Constructor and deconstructor
    Item(std::string name = "misc.", int value = 0);

    //Getter for total number of items in inventory
    static int getTotalItems();

    //Operator overload for displaying item attributes
    friend std::ostream& operator<<(std::ostream& out, const Item& item);
};

#endif //FINAL_REPO_LOCAL_ITEMS_H
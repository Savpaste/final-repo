#ifndef FINAL_REPO_LOCAL_CHARACTER_H
#define FINAL_REPO_LOCAL_CHARACTER_H


#include <iostream>
#include <string>

//Abstract class for all characters in the game
class Character {

    protected:
    std::string name;
    int x, y;

    public:
    //Constructor and deconstructor
    Character(std::string name);
    virtual ~Character();

    //Getter for name
    std::string getName() const { return name; }

    //Getters for position
    int getX() const { return x; }
    int getY() const { return y; }

    //Setters for position
    void setPosition(int x, int y);

};

#endif //FINAL_REPO_LOCAL_CHARACTER_H
#ifndef FINAL_REPO_LOCAL_CHALLENGES_H
#define FINAL_REPO_LOCAL_CHALLENGES_H


#include <vector>
#include <string>

//Abstract class for the different types of games
class Game {

    protected:
    std::string gameType;
    std::vector <std::string> prizes;
    bool correct;

    public:
    //Constructor and deconstructor
    Game();
    virtual ~Game();

    //Getters for game type and answer
    std::string getGameType() const { return gameType; }
    bool isCorrect() const;

    //Game management to add prizes for completion of games
    void addPrize(std::string prize);

};

#endif //FINAL_REPO_LOCAL_CHALLENGES_H
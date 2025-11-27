#include "Game.h"


Game::Game()
    : gameType("Game"), correct(false) {

}

Game::~Game() {

}

bool Game::isCorrect() const {
    return correct;
}

void Game::addPrize(std::string prize) {
    prizes.push_back(prize);
}
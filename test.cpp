#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>

using namespace std;

#include "game.h"

int main() {
    int iterations = 2;
    int dice = 4;
    int arraySize = (dice * 6) + 1;

    game g(arraySize);
    
    for(int i = 0; i < iterations; i++) {
        int score = 0;
        int diceAmount = dice;
        player p(diceAmount, score);

        while(diceAmount > 0) {
            int numDiceToRemove = 0;

            for(int i = 0; i < diceAmount; i++) {
                p.playersDice[i].rollDie();
                // cout << p.playersDice[i].value << endl;
            }

            p.scoreRoll(diceAmount, numDiceToRemove);

            for(int i = 0; i < numDiceToRemove; i++) {
                diceAmount--;
            }
        }
        cout << "Score: " << p.score << endl;
        g.updateStats(p.score);
    }
    g.printStats();
}

#include "player.h"

class game {
public:
    int size;
    int * stats;
    int numOfIterations;
    int numOfDice;

    game(int arraySize, int dice, int iterations) {
        size = arraySize;
        numOfDice = dice;
        numOfIterations = iterations;
        stats = new int[size];
        for(int i = 0; i < arraySize; i++) {
            stats[i] = 0;
        }
    }

    void playGame() {
        for(int i = 0; i < numOfIterations; i++) {
            int score = 0;
            int diceAmount = numOfDice;

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
            stats[p.score]++;
        }
        printStats();
    }
private:
    void printStats() {
        for(int i = 0; i < size; i++) {
            cout << "Score " << i << " occurred " << stats[i] << " times." << endl;
        }
    }
};
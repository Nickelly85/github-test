#include "die.h"

class player {
public:
    vector<die> playersDice;
    int score;
    
    player(int startingNumDice, int initialScore) {
        score = initialScore;
        
        for(int i = 0; i < startingNumDice; i++) {
            die temp;
            playersDice.push_back(temp);
        }
    }

    void scoreRoll(int numOfDice, int &counter) {
        int min = 7;
        bool isThree = false;
        
        for(int i = 0; i < numOfDice; i++) {
            if(playersDice[i].value == 3) {
                counter++;
                isThree = true;
            }
            else { 
                if(playersDice[i].value < min) {
                    min = playersDice[i].value;
                }
            }
        }
        if(isThree) {
            score += 0;
        }
        else {
            score += min;
            counter++;
        }

        return;
    }
};
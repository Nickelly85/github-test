#include "player.h"

class game {
public:
    int size;
    int * stats;

    game(int arraySize) {
        size = arraySize;
        stats = new int[size];
        for(int i = 0; i < arraySize; i++) {
            stats[i] = 0;
        }
    }

    void updateStats(int score) {
        stats[score]++;
    }

    void printStats() {
        for(int i = 0; i < size; i++) {
            cout << "Score " << i << " occurred " << stats[i] << " times." << endl;
        }
    }
};
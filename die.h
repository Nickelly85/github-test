class die {
public: 
    int value;

    die() {
        value = 0;
    }

    void rollDie() {
        std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 6); // distribution in range [1, 6]

        value = dist6(rng);
    }
};
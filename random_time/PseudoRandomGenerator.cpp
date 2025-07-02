#include <ctime>
#include <iostream>

/**
 * @class PseudoRandomGenerator
 * @brief A simple pseudo-random number generator using LCG algorithm.
 * @details This class mimics the behavior of srand() and rand() from <cstdlib>.
 * It is implemented using only C++98 features.
 */
class PseudoRandomGenerator {
  private:
    /**
     * @brief The current seed value.
     * @details This value is updated with each number generation.
     */
    unsigned long _seed;

  public:
    /**
     * @brief Constructs a new PseudoRandomGenerator object.
     * @param seedValue The initial seed. If 0, it uses the current time.
     */
    explicit PseudoRandomGenerator(unsigned long seedValue = 0) {
        if (seedValue == 0) {
            this->_seed = static_cast<unsigned long>(std::time(NULL));
        } else {
            this->_seed = seedValue;
        }
    }

    /**
     * @brief Sets a new seed. Equivalent to srand().
     * @param seedValue The new seed value.
     */
    void seed(unsigned long seedValue) { this->_seed = seedValue; }

    /**
     * @brief Generates the next pseudo-random number. Equivalent to rand().
     * @details It uses a common Linear Congruential Generator (LCG) formula.
     * The constants are from POSIX.1-2001 standard.
     * @return An integer between 0 and 32767 (similar to some rand() implementations).
     */
    int generate() {
        // LCG formula: X_n+1 = (a * X_n + c) mod m
        const unsigned long a = 1103515245;
        const unsigned long c = 12345;

        this->_seed = a * this->_seed + c;

        // Return a value within the typical 15-bit range of rand()
        return static_cast<int>((this->_seed / 65536) % 32768);
    }
};

int main() {
    // 1. Create a generator seeded with the current time
    std::cout << "--- Random numbers seeded by time ---" << std::endl;
    PseudoRandomGenerator rng;
    for (int i = 0; i < 5; ++i) {
        std::cout << rng.generate() << std::endl;
    }

    std::cout << "\n--- Random numbers with a fixed seed ---" << std::endl;
    // 2. Create a generator with a fixed seed for reproducible results
    PseudoRandomGenerator rng_fixed(42);
    for (int i = 0; i < 5; ++i) {
        std::cout << rng_fixed.generate() << std::endl;
    }

    std::cout << "\n--- Another sequence with the same fixed seed ---" << std::endl;
    // 3. Confirm that the sequence is the same with the same seed
    PseudoRandomGenerator rng_fixed2(42);
    for (int i = 0; i < 5; ++i) {
        std::cout << rng_fixed2.generate() << std::endl;
    }

    return 0;
}

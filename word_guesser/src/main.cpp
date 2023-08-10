#include "lib.hpp"
#include <ctime>
#include <iostream>
#include <optional>
#include <ostream>
#include <string>
#include <sys/_types/_size_t.h>
#include <sys/types.h>
#include <vector>

using namespace std;

int main() {
    const vector<string> WORDS = {
        "compass",        "sextant",   "spinakeur",
        "equilibristics", "gymnazium", "jentelman",
    };

    srand(static_cast<unsigned int>(time(0)));
    const int RANDOM_INDEX = rand_up(WORDS.size());
    string game_word = WORDS[RANDOM_INDEX];
    string hidden_word(game_word.size(), '*');
    char guess;

    while (game_word != hidden_word) {
        cout << hidden_word << endl;
        std::cout << "Your guess: -> ";
        cin >> guess;
        size_t res = game_word.find(guess);

        if (res == string::npos) {
            std::cout << "No such letter in the word, try again.." << std::endl;
            continue;
        }

        for (uint index = 0; index < game_word.size(); ++index) {
            if (game_word[index] == guess) {
                hidden_word[index] = guess;
            }
        }
    }
    std::cout << "You win!" << std::endl;
    std::cout << "Hidden word is: " << game_word << std::endl;

    return 0;
}

#include <iostream>
#include <sys/types.h>

using std::cin;
using std::cout;

void game(const int DISTANCE) {

    bool game_over = false;
    int cur_distance = DISTANCE;
    int step;
    uint attempt = 0;
    int range = 0;

    while (!game_over) {
        cout << "\nHow many steps do you want to go?\n";
        cout << "Enter a number: \n";
        cin >> step;
        cur_distance -= step;
        range += abs(step);
        attempt += 1;

        if (cur_distance < 0)
            cout
                << "\nOops..\nYou missed out target, go back by entering minus "
                   "steps.\n\n";
        if (abs(cur_distance) == 0) {
            game_over = true;
            cout << "\nYou win the game in " << attempt << " attempts !\n"
                 << "Covering a total of " << range << " miles !\n"
                 << "To reach a target that was " << DISTANCE
                 << " miles away from you !\n"
                 << "Your score is: "
                 << ((DISTANCE * 100) / (range)) - (attempt - 1)
                 << "/100 points !\n";
        } else if (abs(cur_distance) >= 500) {
            cout << "You too far away from target...\n";
        } else if (abs(cur_distance) <= 70) {
            cout << "You are soooooo close to target...\n";
        } else if (abs(cur_distance) <= 200) {
            cout << "You are very close to target...\n";
        } else if (abs(cur_distance) < 500) {
            cout << "You are closer to target...\n";
        }
    }
}

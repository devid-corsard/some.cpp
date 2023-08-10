#include <cstdlib>
#include <ctime>

int rand_up(int n) {
    std::srand(static_cast<unsigned>(std::time(0)));
    int distance = rand() % n;
    return distance;
}

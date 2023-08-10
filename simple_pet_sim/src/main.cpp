#include "lib.hpp"
#include <ctime>
#include <iostream>
#include <malloc/_malloc.h>
#include <optional>
#include <ostream>
#include <set>
#include <string>
#include <sys/_types/_size_t.h>
#include <sys/types.h>
#include <vector>

using namespace std;

class Kitty {
  public:
    Kitty(string name, int hunger = 0, int boredom = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    inline string GetName() const;

  private:
    string name;
    int hunger;
    int boredom;
    int GetMood() const;
    void PassTime(int time = 1);
};

Kitty::Kitty(string name, int hunger, int boredom)
    : name(name), hunger(hunger), boredom(boredom) {}

int Kitty::GetMood() const { return (hunger + boredom); }
inline string Kitty::GetName() const { return name; }

void Kitty::PassTime(int time) {
    hunger += time;
    boredom += time;
};

void Kitty::Talk() {
    std::cout << "I'm a kitty😼 and i'm feeling ";
    int mood = GetMood();
    if (mood > 15) {
        std::cout << "mad😡." << std::endl;
    } else if (mood > 10) {
        std::cout << "depressed😩." << std::endl;
    } else if (mood > 5) {
        std::cout << "okay🥱." << std::endl;
    } else {
        std::cout << "goooooood😌!" << std::endl;
    }
    PassTime();
};
void Kitty::Eat(int food) {
    hunger -= food;
    if (hunger < 0) {
        hunger = 0;
        std::cout << "Ewww🤢..." << std::endl;
    } else {
        std::cout << "Om-nom-nom😀" << std::endl;
    }
    PassTime();
};
void Kitty::Play(int fun) {
    boredom -= fun;
    if (boredom < 0) {
        std::cout << "C'mon🫠..." << std::endl;
        boredom = 0;
    } else {

        std::cout << "Ueee🥳" << std::endl;
    }
    PassTime();
};

class Farm {
  public:
    Farm(int spaces = 1);
    void Add(const Kitty& kitty);
    void CallRoll();

  private:
    vector<Kitty> kitties;
};

Farm::Farm(int spaces) { kitties.reserve(spaces); }

void Farm::Add(const Kitty& kitty) { kitties.push_back(kitty); }

void Farm::CallRoll() {
    for (vector<Kitty>::const_iterator iter = kitties.begin();
         iter != kitties.end(); ++iter) {
        std::cout << iter->GetName() << " here!" << std::endl;
    }
}

int main() {
    Kitty myKitty("Katya");
    std::cout << "my kitty name:" << myKitty.GetName() << std::endl;

    std::cout << "Creating kitty farm" << std::endl;
    vector<string> names = {"Klara", "Bora", "Malibu"};
    Farm myFarm(names.size());
    for (string name : names) {
        myFarm.Add(Kitty(name));
    }
    std::cout << "Calling Rolls" << std::endl;
    myFarm.CallRoll();
}

#include <iostream>
#include <limits>
#include <cassert>
#include "hero.h"
#include "numUtils.h"


using namespace std;

inline constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};
inline const string clearAndGoHome{"\x1B[2J\x1B[H"};

void goOnQuest(Hero& hero) {
    short difficulty = getRandNumBelow(100);
    short reqiredStrength;
    if (difficulty < 50) { // Easy
        reqiredStrength = 5;
    }
    else if (difficulty < 85) { // Medium
        reqiredStrength = 25;
    }
    else {
        reqiredStrength = 75;
    }

    short successChance = hero.getStrength() >= reqiredStrength ? 50 : 20;
    short neutralChance = 30;
    short roll = getRandNumBelow(100);

    string outcome;
    short newCourage = hero.getCourage();
    if (roll < successChance) {
        outcome = " was successful in their ";
        newCourage -= 1;
    }
    else if (roll < successChance + neutralChance) {
        outcome = " had a neutral ";
        newCourage -= 3;
    }
    else {
        outcome = " failed their ";
        newCourage -= 6;
    }
    hero.setCourage(newCourage);

    cout << hero.getName() << outcome << "quest.\n";
    cout << "Their courage is now " << hero.getCourage() << ".\n";
}

Hero createHero() {
    string name;
    Hero hero;
    cout << "Please input the name of your hero: ";
    cin >> name;
    cin.ignore(INF_FLAG, '\n');

    hero = Hero(name);
    cout << "\nYour hero's name is " << hero.getName() << ".\n";
    cout << "They have a strength value of " << hero.getStrength() << " and a courage value of " << hero.getCourage() << ".\n\n\n\n"; 
    return hero;
}

void doSelection(char selection, Hero& hero) {
    cout << clearAndGoHome;
    switch (selection) {
        case '1': // Go on a quest
            goOnQuest(hero);
            break;
        case '2': // Train
            short minutes;
            cout << "Please enter how long (in minutes) you would like to train: ";
            minutes = getNumber();
            cout << "Your hero gained " << hero.train(minutes) << " strength points.\nThey now have " << hero.getStrength() << " strength points.\n";
            break;
        case '3': // Attend therapy
            cout << "Your hero gained " << hero.attendTherapy() << " courage points.\nThey now have " << hero.getCourage() << " courage points.\n";
            break;
        default: // Check stats
            cout << "\nYour hero's name is " << hero.getName() << ".\n";
            cout << "They have a strength value of " << hero.getStrength() << " and a courage value of " << hero.getCourage() << ".\n";
            break;
    }
}

void menu(char &restartCharacter, Hero& hero)
{
    char menuSelected;

    cout << "\n\tHero Menu!\n\n";
    cout << "\t1) Go on a quest\n";
    cout << "\t2) Train\n";
    cout << "\t3) Attend therapy\n";
    cout << "\t4) Check stats\n\n";
    cout << "\t5) Quit\n\n";
    cout << "Your selection: ";
    cin >> menuSelected;
    cin.ignore(INF_FLAG, '\n');
    cout << clearAndGoHome;

    switch (menuSelected) {
    case '1':
    case '2':
    case '3':
    case '4':
        doSelection(menuSelected, hero);
        break;
    default:                    // 5 or anything else (Exit Menu)
        restartCharacter = 'n'; // Skip restarting logic
        break;
    }

    if (restartCharacter != 'n') { // Logic for restarting
        cout << "Go back to menu? (Y/N): ";
        cin >> restartCharacter;
        cin.ignore(INF_FLAG, '\n');
        cout << clearAndGoHome;
    }
}
void program() {
    char restartCharacter;
    Hero user = createHero();
    do {
        menu(restartCharacter, user);
    } while (tolower(restartCharacter) == 'y');
}

void testHeroClass() {
    Hero test = Hero();
    Hero test2 = Hero("test");

    assert(test.getName() == "Unknown");
    assert(test.getStrength() < 10);
    assert(test.getStrength() >= 0);
    assert(test.getCourage() < 10);
    assert(test.getCourage() >= 0);
    assert(test.train(10) == 2);
    assert(test.train(40) == 4);
    assert(test.attendTherapy() < 10);
    for (short i = 0; i < 5; ++i) {
        goOnQuest(test);
        test.train(40);
    }

    assert(test2.getName() == "test");
    assert(test2.getStrength() < 10);
    assert(test2.getStrength() >= 0);
    assert(test2.getCourage() < 10);
    assert(test2.getCourage() >= 0);
    assert(test2.train(0) == 2);
    assert(test2.train(60) == 8);
    assert(test2.attendTherapy() < 10);
    for (short i = 0; i < 5; ++i) {
        goOnQuest(test2);
    }
    test2.train(240);
    for (short i = 0; i < 5; ++i) {
        goOnQuest(test2);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed time to rand
    bool isDebug{true};
    if (isDebug) {
        cout << "Testing Hero class... \n";
        testHeroClass();
        cout << "All tests passed!\n";
    }
    else {
        program();
    }
    return 0;
}

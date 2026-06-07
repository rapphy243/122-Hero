#include "hero.h"
#include "numUtils.h"

Hero::Hero() {
    strength = getRandNumBelow(10);
    courage = getRandNumBelow(10);
    name = "Unknown";
}

Hero::Hero(std::string str) {
    strength = getRandNumBelow(10);
    courage = getRandNumBelow(10);
    name = str;
}

short Hero::getStrength() {
    return strength;
}
short Hero::getCourage() {
    return courage;
}
std::string Hero::getName() {
    return name;
}

bool Hero::setCourage(short value) {
    courage = value;
    return true;
}

short Hero::train(short minutes) {
    short strGained = 2;
    if (minutes > 30) {
        strGained += (minutes - 30) / 5;
    }
    strength += strGained;
    return strGained;
}

short Hero::attendTherapy() {
    short courGained = getRandNumBelow(10);
    courage += courGained;
    return courGained;
}

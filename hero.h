#ifndef hero_H
#define hero_H

#include <string>

class Hero {
    private: 
        short strength;
        short courage;
        std::string name;
        
    public:
        Hero();
        Hero(std::string name);

        short getStrength();
        short getCourage();
        std::string getName();

        bool setCourage(short value);

        short train(short minutes);
        short attendTherapy();
};

#endif

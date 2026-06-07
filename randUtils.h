#ifndef RANDUTILS_H
#define RANDUTILS_H

#include <random>

inline short getRandNumBelow(short number) {
    return static_cast<short>(std::rand() % number);
}

#endif

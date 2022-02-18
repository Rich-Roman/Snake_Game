#ifndef FOOD_H
#define FOOD_H

#include <windows.h>
#include <cstdio>

class Food{
public:
    Food() {

    };

    void genFood(int width, int height){

        location.first = (rand() % (width-3) + 1 );
        location.second = (rand() % (height-3) + 1 );
    };

    pair<int,int> getLocation() {
        return location;
    }

private:
    pair<int, int> location;
};

#endif
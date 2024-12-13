#ifndef pets_h
#define pets_h

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Pets {
public:
    void create();
    void read();
    void update();
    void deletePet();
};

#endif
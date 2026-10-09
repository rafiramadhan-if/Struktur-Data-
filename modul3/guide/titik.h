#ifndef TITIK_H_INCLUDED
#define TITIK_H_INCLUDED

struct titik {
    float x;
    float y;
};

void inputTitik(titik &t);
void tampilTitik(titik t);
float hitungJarak(titik t1, titik t2);

#endif

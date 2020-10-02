#pragma once
#include<sstream>
#include<iostream>
using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int annio;
public:
    Fecha() = default;
    Fecha(int, int, int);
    ~Fecha();

    int getDia() const { return dia; }

    int getMes() const { return mes; }

    int getAnnio() const { return annio; }
};
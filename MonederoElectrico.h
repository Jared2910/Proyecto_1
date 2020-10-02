#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class MonederoElectronico {
private:
	int dinero;
public:
	MonederoElectronico()=default;
	MonederoElectronico(int);
	~MonederoElectronico()=default;

	int getDinero();
	void setDinero(int);

	string desgloceVuelto(string&);
	string toString();

};
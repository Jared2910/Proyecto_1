#include "MonederoElectrico.h"

MonederoElectronico::MonederoElectronico(int dinero)
{
	this->dinero = dinero;
}

int MonederoElectronico::getDinero()
{
	return dinero;
}

void MonederoElectronico::setDinero(int dinero)
{
	this->dinero = dinero;
}

string MonederoElectronico::desgloceVuelto(string& monto)
{
	stringstream s;
	int billetes[] = {2000,1000,500,100,50,25,10,5};
	int dinero = int(stof(monto));
	int total = 0;
	s << "----------Su Vuelto Seria----------" << endl;
	for (int i = 0; i < 8;i++) {
		while (dinero>=billetes[i]) {
			s << billetes[i] <<" colones"<< endl;
			dinero -= billetes[i];
			total += billetes[i];
		}
		cout << endl;
	}
	s << "Total: " << total << endl<<endl;
	return s.str();
}

string MonederoElectronico::toString()
{
	stringstream s;
	s <<this->getDinero() << endl;

	return s.str();
}

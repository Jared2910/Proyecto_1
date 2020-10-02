#pragma once
#include<sstream>
#include<iostream>
#include"ObjetoBase.h"
using namespace std;

class Producto: public ObjetoBase {
protected:
	string nombre;
	float precio;
	int cantidad;

public:
	Producto() = default;
	Producto(string, float, int);
	~Producto()=default;

	string getNombre();
	void setNombre(string nombre);

	virtual float getPrecio()=0;
	void setPrecio(float precio);

	int getCantidad();
	void setCantidad(int cantidad);

	string toString();
};
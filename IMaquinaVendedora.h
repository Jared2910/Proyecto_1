#pragma once
#include<iostream>
#include<sstream>
#include"Producto.h"
using namespace std;

class IMaquinaVendedora {
public:
	virtual string getNombre() = 0;
	virtual string realizarCompra(string id,int cantidad,int montoPago) = 0;
	virtual string toString() = 0;
	virtual Producto* consultar(string id) = 0;
	~IMaquinaVendedora()=default;
};
#pragma once
#include<sstream>
#include<iostream>
#include"Producto.h"
using namespace std;


class IMaquinaAdministradora {
public:
	virtual int getIdentificador() = 0;
	virtual string getNombre()=0;
	virtual void setNombre(string) = 0;
	virtual string toString() = 0;
	virtual void insertar(ObjetoBase*) = 0;
	virtual void agregarProvisiones(string idProducto, int cantidad) = 0;
	virtual void disminuirProvisiones(string idProducto, int cantidad)=0;
	virtual void borrar(string id) = 0;
	virtual Producto* consultar(string id) = 0;
	virtual void ingresarDinero(int) = 0;
	virtual void retirarDinero() = 0;
	~IMaquinaAdministradora()=default;
};
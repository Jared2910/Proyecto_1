#pragma once
#include"Producto.h"

class ProductoNoPerecedero :public Producto{
private:
	float porcentajeDeDescuento;
public:
	ProductoNoPerecedero()= default;
	ProductoNoPerecedero(float,string,float,int);
	~ProductoNoPerecedero() = default;

	// Inherited via Producto
	virtual float getPrecio() override;
};
#pragma once
#include"Producto.h"
#include"fecha.h"
#include<ctime>

class ProductoPerecedero :public Producto {
private:
	Fecha* fechaDeVencimiento;
public:

	ProductoPerecedero() = default;
	~ProductoPerecedero();
	ProductoPerecedero(Fecha* ,string ,float ,int );

	virtual float getPrecio() override;
};

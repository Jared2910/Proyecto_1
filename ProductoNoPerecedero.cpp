#include "ProductoNoPerecedero.h"

ProductoNoPerecedero::ProductoNoPerecedero(float porcentajeDeDescuento, string nombre, float precio, int cantidad) :Producto(nombre,precio,cantidad)
{
	this->porcentajeDeDescuento = porcentajeDeDescuento;
}

float ProductoNoPerecedero::getPrecio()
{
	return (this->precio * this->porcentajeDeDescuento);
}

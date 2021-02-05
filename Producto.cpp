#include "Producto.h"

Producto::Producto(string nombre, float precio, int cantidad)
{
	this->nombre = nombre;
	this->precio = precio;
	this->cantidad = cantidad;
}

string Producto::getNombre()
{
	return nombre;
}

void Producto::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Producto::setPrecio(float precio)
{
	this->precio = precio;
}

int Producto::getCantidad()
{
	return cantidad;
}

void Producto::setCantidad(int cantidad)
{
	this->cantidad = cantidad;
}

string Producto::toString()
{
	stringstream s;
	s << "   Nombre: " << this->getNombre();
	s << "   Precio: " << this->getPrecio();
	s << "   Cantidad: " << this->getCantidad();
	s << "\n---------------------------\n";
	return s.str();
}

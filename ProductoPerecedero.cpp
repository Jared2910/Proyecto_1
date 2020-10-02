#include "ProductoPerecedero.h"

ProductoPerecedero::~ProductoPerecedero()
{
	delete this->fechaDeVencimiento;
}

ProductoPerecedero::ProductoPerecedero(Fecha* fechaDeVencimiento, string nombre, float precio, int cantidad):Producto(nombre,precio,cantidad)
{
	this->fechaDeVencimiento = fechaDeVencimiento;
}

float ProductoPerecedero::getPrecio()
{
	float descuento = 0;
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);

	if ((this->fechaDeVencimiento->getAnnio() - newtime.tm_year) >= 0 ){
		if ((this->fechaDeVencimiento->getMes() - 1 - newtime.tm_mon) >= 0) {
			if ((this->fechaDeVencimiento->getMes()-1-newtime.tm_mon)==1 && (newtime.tm_mday-23)== this->fechaDeVencimiento->getDia()) {
				descuento = this->precio * 0.5;
				return float(descuento);
			}
			if (( newtime.tm_mday - this->fechaDeVencimiento->getDia()) < 7) {
				descuento = this->precio * 0.5;
				return float(descuento);
			}
			return this->precio;
		}
		return this->precio;
	}
	
}

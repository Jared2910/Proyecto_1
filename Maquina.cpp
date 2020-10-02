#include "Maquina.h"

Maquina::Maquina(int identificador, string nombre,IList* productos,int dinero)
{
	this->identificador = identificador;
	this->nombre = nombre;
	this->productos = productos;
	this->monedero = new MonederoElectronico(dinero);
}

Maquina::~Maquina()
{
	this->productos->liberarDatosInternos();
	delete this->productos;
	delete this->monedero;
}

string Maquina::getNombre()
{
	return this->nombre;
}

int Maquina::getIdentificador()
{
	return this->identificador;
}

void Maquina::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Maquina::toString()
{
	stringstream s;
	s << "----------Datos de la maquina----------" << endl;
	s << "Identificador: " << getIdentificador() << endl;
	s << "Nombre: " << getNombre() << endl;
	s << "Dinero en el monedero: " << monedero->toString();
	if (this->productos->getCantidad() > 0) {
		s << "Lista de Productos: \n" << productos->toString();
	}
	else {
		s << "***No hay productos en la maquina***\n";
	}
	return s.str();
}

void Maquina::insertar(ObjetoBase* producto)
{
	this->productos->insertarAlFinal(producto);
}

void Maquina::agregarProvisiones(string idProducto, int cantidad)
{
	IIterador* iter = this->productos->obtenerIterador();
	while (iter->haySiguiente()) {
		Producto* actual = dynamic_cast<Producto*>(iter->actual());
		if (actual->getNombre()==idProducto) {
			actual->setCantidad(actual->getCantidad() + cantidad);
			break;
		}
	}
	delete iter;
}

void Maquina::disminuirProvisiones(string idProducto, int cantidad)
{
	IIterador* iter = this->productos->obtenerIterador();
	while (iter->haySiguiente()) {
		Producto* actual = dynamic_cast<Producto*>(iter->actual());
		if (actual->getNombre() == idProducto) {
			actual->setCantidad(actual->getCantidad() - cantidad);
			break;
		}
	}
	delete iter;
}

void Maquina::borrar(string id)
{
	int cont = 0;
	IIterador* iter = this->productos->obtenerIterador();
	while (iter->haySiguiente()) {
		Producto* actual = dynamic_cast<Producto*>(iter->actual());
		if (actual->getNombre()==id) {
			productos->borrarEnPosicion(cont);
			break;
		}
		cont++;
	}
	delete iter;
}

Producto* Maquina::consultar(string id)
{
	IIterador* iter = this->productos->obtenerIterador();
	Producto* resultado = nullptr;
	while (iter->haySiguiente()) {
		Producto* actual = dynamic_cast<Producto*>(iter->actual());
		if (actual->getNombre()==id) {
			resultado= actual;
			break;
		}
	}
	delete iter;
	return resultado;
}

void Maquina::ingresarDinero(int dinero)
{
	this->monedero->setDinero(monedero->getDinero()+dinero);
}

void Maquina::retirarDinero()
{
	this->monedero->setDinero(0);
}

string Maquina::realizarCompra(string id, int cantidad, int montoPago)
{
	stringstream s;
	Producto* producto = consultar(id);
	monedero->setDinero(+montoPago);
	int dineroCobrar = int(producto->getPrecio() * cantidad);
	if (montoPago<=monedero->getDinero() && cantidad<=producto->getCantidad() && montoPago!=0 && dineroCobrar<= montoPago) {
		string cambio = to_string(montoPago - dineroCobrar);
		ingresarDinero(montoPago);
		disminuirProvisiones(id, cantidad);
		s << "----------Comprando----------" << endl;
		s << "Nombre: " << id << endl;
		s << "Cantidad: " << cantidad << endl;
		s << "Monto Pago: " << montoPago << endl;
		s << "Valor de cada producto: " << producto->getPrecio() << endl;
		s << "-----------------------------" << endl;
		s << "Total: " << dineroCobrar << endl << endl;;
		s<<monedero->desgloceVuelto(cambio);
		
		int vuelto = int(stof(cambio));
		monedero->setDinero(monedero->getDinero()- vuelto);
		s << "Gracias por su compra, que tenga un lindo dia :)" << endl<<endl;
	}
	else {
		s << "***No se puede realizar la compra***" << endl;
	}
	return s.str();
}


#pragma once
#include<iostream>
#include<sstream>
#include"IMaquinaAdministradora.h"
#include"IMaquinaVendedora.h"
#include"IList.h"
#include"ArrayList.h"
#include"Producto.h"
#include"MonederoElectrico.h"
using namespace std;

/*Inversion de dependencia:
Esta se presenta en la clase maquina ya que al inyectarle la dependencia con IList para el arreglo de productos, la clase Maquina
no sabe cual es la clase concreta con la que trabaja, en otra palabras solo esta pensando en una abstraccion.
*/

/*
Principio abierto cerrado:
El principio abierto cerrado se evidencia en la clase maquina ya que al depender de la clase IList no se obliga a la clase maquina a
realizar todos los procedimientos, ya que la clase IList se encarga de la realización de la mayoría de procedimientos que la clase maquina requiera.

*/
class Maquina : public IMaquinaAdministradora,public IMaquinaVendedora{
private:
	int identificador;
	string nombre;
	IList* productos;
	MonederoElectronico* monedero;
public:
	Maquina() = default;
	Maquina(int,string,IList*,int);
	~Maquina();

	virtual string getNombre() override;
	virtual int getIdentificador() override;
	virtual void setNombre(string) override;
	virtual string toString() override;
	virtual void insertar(ObjetoBase* ObjetoBase) override;
	virtual void agregarProvisiones(string idProducto, int cantidad) override;
	virtual void disminuirProvisiones(string idProducto, int cantidad) override;
	virtual void borrar(string id) override;
	virtual Producto* consultar(string id) override;
	virtual void ingresarDinero(int) override;
	virtual void retirarDinero() override;
	virtual string realizarCompra(string id, int cantidad, int montoPago) override;
};
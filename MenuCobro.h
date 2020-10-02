#pragma once
#include"IMaquinaVendedora.h"
#include"Producto.h"
using namespace std;

class MenuCobro {
private:
	IMaquinaVendedora* maquinaVendedora;
	bool confirmarCompra();
	char mostrarOpciones();

	void mostrarProductos();
	void seleccionarProducto();
public:
	MenuCobro(IMaquinaVendedora*);
	~MenuCobro();
	void invocarMenu();

};

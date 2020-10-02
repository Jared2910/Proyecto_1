#include "Bootstrapper.h"
#include"LinkedList.h"

void Bootstrapper::correrAplicacion()
{
	int codigo = 402530813;
	int dinero = 0;
	string nombre = "Eat Wave";
	
	Maquina* maquina = new Maquina(codigo, nombre, new LinkedList(), dinero);

	MenuAdministrador* menuAdministrador = new MenuAdministrador(maquina);
	MenuCobro* menuCobro = new MenuCobro(maquina);
	MenuPrincipal* menuPrincipal = new MenuPrincipal(menuAdministrador, menuCobro);
	
	menuPrincipal->invocarMenu();

	delete maquina;
}

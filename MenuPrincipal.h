#pragma once
#include"MenuAdministrador.h"
#include"MenuCobro.h"
using namespace std;

class MenuPrincipal {
private:
	MenuAdministrador* menuAdministrador;
	MenuCobro* menuCobro;
	char mostrarOpciones();

public:
	MenuPrincipal(MenuAdministrador*,MenuCobro*);
	~MenuPrincipal();
	void invocarMenu();
};
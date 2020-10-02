#include "MenuPrincipal.h"

char MenuPrincipal::mostrarOpciones()
{
	char opcion;
	system("cls");
	cout << "----------Menu Principal----------\n";
	cout << " 1) Menu Admistrador\n";
	cout << " 2) Menu de Compra\n";
	cout << " 3) Salir\n";
	cin >> opcion;
	system("cls");
	return opcion;
}

MenuPrincipal::MenuPrincipal(MenuAdministrador* menuAdministrador, MenuCobro* menuCobro)
{
	this->menuAdministrador = menuAdministrador;
	this->menuCobro = menuCobro;
}

MenuPrincipal::~MenuPrincipal()
{
	delete this->menuAdministrador;
	delete this->menuCobro;
}

void MenuPrincipal::invocarMenu()
{
	char opcion;
	const char OpcionSalida = '3';
	do
	{
		opcion = mostrarOpciones();
		switch (opcion)
		{
		case '1':
			//Menu Administracion
			system("cls");
			this->menuAdministrador->invocarMenu();
			break;
		case '2':
			//Menu Cobro
			this->menuCobro->invocarMenu();
			break;
		case OpcionSalida:
			system("cls");
			cerr << "Hasta luego , tenga un lindo dia :)\n";
			system("pause");
			break;
		default:
			system("cls");
			cerr << "Opcion Invalida\n";
			system("pause");
		}
	} while (opcion != OpcionSalida);
}

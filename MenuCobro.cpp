#include "MenuCobro.h"

char MenuCobro::mostrarOpciones()
{
	system("cls");
	char opcion;
	cout<<"Hola que tal"<<endl;
	cout << "----------Menu Cobro----------\n";
	cout << " 1) Mostrar Productos\n";
	cout << " 2) Seleccionar Productos\n";
	cout << " 3) Salir\n";
	cin >> opcion;
	system("cls");
	return opcion;
}

void MenuCobro::mostrarProductos()
{
	cout<< this->maquinaVendedora->toString();
	system("pause");
}

bool MenuCobro::confirmarCompra()
{
	char opcion;
	cout << "\nSi desea comprar el producto digite 1: "; cin >> opcion;
	if (opcion=='1') {
		return true;
	}
	else {
		return false;
	}
}

void MenuCobro::seleccionarProducto()
{
	string nombre;
	int monto,cantidad;
	cout << "Ingrese el nombre del producto que desea comprar: "; cin >> nombre;
	Producto* prod=this->maquinaVendedora->consultar(nombre);
	if (prod!=nullptr) {
		cout << prod->toString();
		if (confirmarCompra() == true) {
			cout << "Ingrese la cantidad que va a adquirir: "; cin >> cantidad;
			cout << "\nEl subtotal es de: " << prod->getPrecio() * cantidad << " Colones";
			cout << "\nIngrese el monto con el que va a cancelar: "; cin >> monto;
			system("cls");
			cout << this->maquinaVendedora->realizarCompra(nombre, cantidad, monto);
		}
	}
	else {
		system("cls");
		cerr << "Producto inexistente, favor revisar la lista\n";
	}
}

MenuCobro::MenuCobro(IMaquinaVendedora* maquinaVendedora)
{
	this->maquinaVendedora=maquinaVendedora;
}

MenuCobro::~MenuCobro()
{
	delete this->maquinaVendedora;
}

void MenuCobro::invocarMenu()
{
	const char opcionSalida = '3';
	char opcion;
	do
	{
		opcion = mostrarOpciones();
		switch (opcion)
		{
		case '1':
			//Mostrar productos
			this->mostrarProductos();
			break;
		case '2':
			//seleccionar producto para hacer la compra
			system("cls");
			this->seleccionarProducto();
			system("pause");
			break;
		
		case opcionSalida: 
			break;
		default:
			system("cls");
			cerr << "***Opcion Invalida, digite otra opcion" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (opcion!=opcionSalida);
}

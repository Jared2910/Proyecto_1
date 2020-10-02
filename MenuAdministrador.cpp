#include "MenuAdministrador.h"

char MenuAdministrador::mostrarOpciones()
{
	system("cls");
	char opcion;
	cout << "----------Menu Administrador----------\n";
	cout << " 1) Insertar Producto\n";
	cout << " 2) Agregar Provisiones\n";
	cout << " 3) Disminuir Provisiones\n";
	cout << " 4) Borrar Producto\n";
	cout << " 5) Ingresar Dinero\n";
	cout << " 6) Retirar Dinero\n";
	cout << " 7) Datos de la maquina\n";
	cout << " 8) Salir\n";
	cin >> opcion;
	system("cls");
	return opcion;
}

void MenuAdministrador::ingresarProducto()
{
	Producto* producto = crearProducto();
	if (producto!=nullptr) {
		this->maquinaAdministradora->insertar(producto);
		system("pause");
	}
}

Producto* MenuAdministrador::crearProducto()
{
	char opcion;
	cout << "---Tipos de Producto---\n";
	cout << " 1) Producto Perecedero\n";
	cout << " 2) Producto No Perecedero\n";
	cout << " 3) Salir\n";
	cin >> opcion;
	system("cls");
	string nombre;
	float precio;
	int cantidad;
	if (opcion == '1') {
		int dia, mes, annio;
		cout << "Digite la fecha de caducidad del producto de la forma dia/mes/annio : ";
		cin >> dia; cout << "/";
		cin >> mes; cout << "/";
		cin >> annio;
		Fecha* fecha = new Fecha(dia, mes, annio);
		cout << "\nIngrese el nombre del producto: "; cin >> nombre;
		cout << "\nIngrese el precio del producto: "; cin >> precio;
		cout << "\nIngrese la cantidad que hay del producto: "; cin >> cantidad;
		return new ProductoPerecedero(fecha, nombre, precio, cantidad);
	}
	else if (opcion == '2') {
		float descuento;
		cout << "\nIngrese el descuento que se le va a aplicar al producto: "; cin >> descuento; 
		descuento /= 100;
		cout << "\nIngrese el nombre del producto: "; cin >> nombre;
		cout << "\nIngrese el precio del producto: "; cin >> precio;
		cout << "\nIngrese la cantidad que hay del producto: "; cin >> cantidad;
		return new ProductoNoPerecedero(descuento, nombre, precio, cantidad);
	}
	else if (opcion=='3') {
		return nullptr;
	}
}

void MenuAdministrador::agregarProvisiones()
{
	string nombre;
	int cantidad;
	cout << "Ingrese el nombre del producto: " << endl; cin >> nombre;
	cout << "Ingrese la cantidad que va a agregar: " << endl;  cin >> cantidad;
	this->maquinaAdministradora->agregarProvisiones(nombre, cantidad);
}

void MenuAdministrador::disminuirProvisiones()
{
	string idProducto;
	int cantidad;
	cout << "Ingrese el nombre del producto: " << endl; cin >> idProducto;
	cout << "Ingrese la cantidad que va a disminuir: " << endl; cin >> cantidad;
	this->maquinaAdministradora->disminuirProvisiones(idProducto, cantidad);
}

void MenuAdministrador::borrarProducto()
{
	string id;
	cout << "Digite el nombre del producto que desea eliminar: "; cin >> id;
	this->maquinaAdministradora->borrar(id);
}

void MenuAdministrador::ingresarDinero()
{
	int dinero;
	cout << "Digite el dinero que quiere ingresar a la maquina: "; cin >> dinero;
	this->maquinaAdministradora->ingresarDinero(dinero);
	cout << "Los " << dinero << " fueron ingresados correctamente a la maquina\n";
}

void MenuAdministrador::retirarDinero()
{
	this->maquinaAdministradora->retirarDinero();
	cout << "Se retiro el dinero correctamente\n";
}

MenuAdministrador::MenuAdministrador(IMaquinaAdministradora* maquinaAdministradora)
{
	this->maquinaAdministradora = maquinaAdministradora;
}

MenuAdministrador::~MenuAdministrador()
{
	delete maquinaAdministradora;
}

void MenuAdministrador::invocarMenu()
{
	const char OpcionSalida = '8';
	char opcion;
	do
	{
		opcion = mostrarOpciones();
		switch (opcion) 
		{
		case '1':
			//insertar producto
			system("cls");
			this->ingresarProducto();
			break;

		case '2':
			//agregar provisiones
			system("cls");
			this->agregarProvisiones();
			system("pause");
			break;

		case '3':
			//disminuir provisiones
			system("cls");
			this->disminuirProvisiones();
			system("pause");
			break;

		case '4':
			//borrar producto
			system("cls");
			this->borrarProducto();
			system("pause");
			break;

		case '5':
			//ingresar dinero
			system("cls");
			this->ingresarDinero();
			system("pause");
			break;

		case '6':
			//retirar dinero
			system("cls");
			this->retirarDinero();
			system("pause");
			break;
		case'7':
			//datos de la maquina
			system("cls");
			cout<<this->maquinaAdministradora->toString();
			system("pause");
		case OpcionSalida:
			break;
		default:
			cerr << "***Opcion Invalida, digite otra opcion" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (opcion!=OpcionSalida);
}

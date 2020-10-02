#pragma once
#include<iostream>
#include<sstream>
#include"IMaquinaAdministradora.h"
#include"Fecha.h"
#include"ProductoPerecedero.h"
#include"ProductoNoPerecedero.h"
using namespace std;
/*
Responsabilidad Unica:
Aqui tambien se evidencia la responsabilidad unica ya que esta clase se preocupa unicamente de interactuar con las funcionalidades de
administracion de la maquina. De manera Analoga en el MenuCobro ocurre lo mismo, solo se preocupa por administrar las compras 
de la maquina, en ningun momento se unifican estas 2 logicas en una misma clase.
*/
class MenuAdministrador {
private:
	IMaquinaAdministradora* maquinaAdministradora;
	char mostrarOpciones();

	void ingresarProducto();
	Producto* crearProducto();
	void agregarProvisiones();
	void disminuirProvisiones();
	void borrarProducto();
	void ingresarDinero();
	void retirarDinero();

public:
	MenuAdministrador(IMaquinaAdministradora*);
	~MenuAdministrador();
	void invocarMenu();

};
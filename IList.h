#pragma once
#include <iostream>
#include <sstream>
#include"ObjetoBase.h"
#include"IReadOnlyCollection.h"
using namespace std;

/*
Segregaci�n de interfaces:
Al utilizar la interfaz IList la cual sigue una l�gica de listas, se le segrega la esta interfaz a IReadOnlyCollection, y IIterable, para que IList
no tenga que encargarse de la realizaci�n de todos los m�todos, y no preocuparse de m�todos que no necesita. La segregaci�n de interfaces
se podr�a definir como la abstracci�n de una misma l�gica en diferentes clases.
*/
class IList : public IReadOnlyCollection
{
public:
	virtual void insertarAlFinal(ObjetoBase* elemento) = 0;
	virtual void insertarEnPosicion(ObjetoBase* elemento, int posicion) = 0;
	virtual void borrarEnPosicion(int posicion, bool liberarMemoria = false) = 0;
	virtual void liberarDatosInternos() = 0;
	virtual ~IList() = default;
};
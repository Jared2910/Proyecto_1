#pragma once
#include <iostream>
#include <sstream>
#include"ObjetoBase.h"
#include"IReadOnlyCollection.h"
using namespace std;

/*
Segregación de interfaces:
Al utilizar la interfaz IList la cual sigue una lógica de listas, se le segrega la esta interfaz a IReadOnlyCollection, y IIterable, para que IList
no tenga que encargarse de la realización de todos los métodos, y no preocuparse de métodos que no necesita. La segregación de interfaces
se podría definir como la abstracción de una misma lógica en diferentes clases.
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
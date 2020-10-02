#include <iostream>
#include <sstream>
#include "IList.h"
#include"IteradorArrayList.h"
using namespace std;
/*
Responsabilidad Unica: 
Un buen ejemplo pueden ser class ArrayList heredada de IList , esta clase se preocupa unicamente de implementar
logica de colecciones como insertar, borrar ver que hay en una posicion especifica, para este proyecto se esta usando esta clase para
guardar productos y a pesar de que sabemos que solo vamos a trabajar con productos, en ningun lado de la clase ArrayList implementamos
alguna logica de Producto como por ejemplo (Producto* productoMasCaro();); no se implementa porque eso no le concierne a la clase Array.
*/
class ArrayList : public IList
{
private:
	ObjetoBase** datos;
	int capacidadActual;
	int cantidad;
	void asegurarCapacidad();

public:
	ArrayList(int capacidadInicial);
	void insertarAlFinal(ObjetoBase* elemento) override;
	void insertarEnPosicion(ObjetoBase* elemento, int posicion) override;
	void borrarEnPosicion(int posicion, bool liberarMemoria = false) override;
	ObjetoBase* consultarPorPosicion(int posicion) override;
	bool contiene(ObjetoBase* elemento) override;
	int getCantidad() override;
	void liberarDatosInternos() override;
	string toString() override;
	IIterador* obtenerIterador() override;
	~ArrayList();
};
#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <vector>
#include "producto.h"

using namespace std;

class Utilidades{
	private:
		vector<Utilidades> utilidades;
		
	public:
		void mostrarMenuPrincipal();
		void gestionarProductos();
		void reporteConsultas();
		void operacioneVentas();
		void archivo();
};


#endif
#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "producto.h"
#include <vector>

using namespace std;

class Utilidades
{
	private:
		vector<Producto> inventario;
	public:
		Utilidades();
		~Utilidades();
		void mostrarMenuPrincipal();
		void gestionarProductos();
		void reporteConsultas();
		void operacioneVentas();
		void archivo();
		void limpiarPantalla();
		void gotoxy(int, int);
		void cambiarColorTexto(int);
};



#endif

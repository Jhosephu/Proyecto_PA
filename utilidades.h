#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "almacen.h"
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
		void mostrarMenuPrincipal(Almacen &almacen);
		void gestionarProductos(Almacen &almacen);
		void reporteConsultas(Almacen &almacen);
		void operacioneVentas();
		void archivo();
		// Funciones gestionarProductos
		void agregarProductoM(Almacen &almacen);
		void modificarProductoM(Almacen &almacen);
		void buscarProductoM(Almacen &almacen);
		void eliminarProductoM(Almacen &almacen);
		// Extras
		void limpiarPantalla();
		void gotoxy(int, int);
		void printC(int, int, string);
		void printProducto(int, int, Producto*);
		void cambiarColorTexto(int);
};



#endif

#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "almacen.h"
#include "producto.h"
#include "transacciones.h"
#include <vector>

using namespace std;

class Utilidades
{
	private:
		vector<Producto> inventario;
	public:
		Utilidades();
		~Utilidades();
		void mostrarMenuPrincipal(Almacen &almacen, Transacciones &transaccion);
		void gestionarProductos(Almacen &almacen);
		void reporteConsultas(Almacen &almacen, Transacciones &transaccion);
		void operacioneVentas(Almacen &almacen, Transacciones &transaccion);
		void archivo();
		//Funciones EstadoAlmacen
		void reporteEstadoDelAlmacen(Almacen &almacen);
		void reporteProductosConBajoStock(Almacen &almacen);
		void reporteTodosLosProductos(Almacen &almacen);
		void reporteProductosOrdenadosPorPrecio(Almacen &almacen);
		void reporteProductosPorPrefijo(Almacen &almacen);
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
		void printProducto2(int, int, Producto*);
		void cambiarColorTexto(int);
};



#endif

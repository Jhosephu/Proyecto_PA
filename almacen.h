#ifndef ALMACEN_H
#define ALMACEN_H

#include <vector>
#include "producto.h"

class Almacen {
	private:
		vector<Producto> productos;
		
		void insertarOrdenadoPorID(Producto &nuevoProducto);
    	int buscarPorID(int idBuscado);
    	
	public:
		void agregarProducto(Producto &producto);
    	void mostrarProductos();
    	void actualizarPrecioProducto(int id, double nuevoPrecio);
    	void aumentarCantidadProducto(int id, int cantidad);
		void reducirCantidadProducto(int id, int cantidad);
};

#endif
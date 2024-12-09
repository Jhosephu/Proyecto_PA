#ifndef ALMACEN_H
#define ALMACEN_H

#include <vector>
#include <string>
#include "producto.h"

class Almacen {
	private:
		vector<Producto> productos;
		string nombreArchivo;
		
		void insertarOrdenadoPorID(Producto &nuevoProducto);
    	int buscarPorID(int idBuscado);
    	
	public:
		Almacen();
		void cargarDesdeArchivo();
		void cambiarNombreArchivo(string nuevoNombre);
		void agregarProducto(Producto &producto);
    	void mostrarProductos();
    	void actualizarPrecioProducto(int id, float nuevoPrecio);
    	void aumentarCantidadProducto(int id, int cantidad);
		void reducirCantidadProducto(int id, int cantidad);
};

#endif
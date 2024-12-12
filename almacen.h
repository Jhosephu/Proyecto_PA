#ifndef ALMACEN_H
#define ALMACEN_H

#include <vector>
#include <string>
#include "producto.h"

class Almacen {
	private:
		vector<Producto> productos;
		string nombreArchivo;
	public:
		Almacen();
		Almacen(string nA);
		void cargarDesdeArchivo();
		void guardarEnArchivo();
		void cambiarNombreArchivo(string nuevoNombre);
		void agregarProducto(Producto &producto);
		void eliminarProducto(int id);
    	void mostrarProductos();
    	void actualizarPrecioProducto(int id, float nuevoPrecio);
    	void aumentarCantidadProducto(int id, int cantidad);
		void reducirCantidadProducto(int id, int cantidad);
		void insertarOrdenadoPorID(Producto &nuevoProducto);
    	int buscarPorID(int idBuscado);
    	Producto obtenerProductoPorID(int id);
};

#endif

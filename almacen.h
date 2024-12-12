#ifndef ALMACEN_H
#define ALMACEN_H

#include <vector>
#include <string>
#include <map>
#include "producto.h"

class Almacen {
	private:
		vector<Producto> productos;
		map<string, Producto*> indiceNombre;
		string nombreArchivo;

		
		void insertarOrdenadoPorID(Producto &nuevoProducto);
		void actualizarIndiceNombre();
		vector<Producto*> encontrarPorInicioNombre(string nombrePrefijo);
    	
>>>>>>> f594786b0dfd1a9e20ac94dd5f7a3bb25f1cd2a7
	public:
		Almacen();
		Almacen(string nA);
		int buscarPorID(int idBuscado);
		Producto* buscarPorNombre(string nombreBuscado);
		Producto* buscarPorIDs(int id);
		void cargarDesdeArchivo();
		void guardarEnArchivo();
		void cambiarNombreArchivo(string nuevoNombre);
		void agregarProducto(Producto &producto);
		void eliminarProducto(int id);
    	void mostrarProductos();
    	void mostrarProducto(int pos);
    	void mostrarAlgunosProductos(vector<Producto*> productos2);
    	void actualizarPrecioProducto(int id, float nuevoPrecio);
    	void aumentarCantidadProducto(int id, int cantidad);
		void reducirCantidadProducto(int id, int cantidad);
<<<<<<< HEAD
		void insertarOrdenadoPorID(Producto &nuevoProducto);
    	int buscarPorID(int idBuscado);
    	Producto obtenerProductoPorID(int id);
=======
		bool verificarIdEnProductos(int id);
>>>>>>> f594786b0dfd1a9e20ac94dd5f7a3bb25f1cd2a7
};

#endif

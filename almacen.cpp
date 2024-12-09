#include "almacen.h"
#include "producto.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void Almacen::cargarDesdeArchivo(){
	ifstream archivo(nombreArchivo);
	
	if(!archivo.is_open()){
		cout << "ERROR: no se pudo abrir el archivo";
		return;
	}
	
	int ID, cantidad;
	double precio;
	string nombre;
	
	string linea;
	
	
	while(getline(archivo, linea)){
		istringstream stream(linea);
		
		if(stream >> ID >> nombre >> cantidad >> precio){
			Producto prod(ID, nombre, cantidad, precio);
			agregarProducto(prod);
		} else {
			cout << "ERROR: no se puede procesar los datos";
		}
	}
}

void Almacen::cambiarNombreArchivo(string nuevoNombre){
	nombreArchivo = nuevoNombre;
}

void Almacen::insertarOrdenadoPorID(Producto &nuevoProducto) {
	if (productos.empty()) {
		productos.push_back(nuevoProducto);
		return;
	}

	auto it = lower_bound(productos.begin(), productos.end(), nuevoProducto);
	productos.insert(it, nuevoProducto);
}

int Almacen::buscarPorID(int idBuscado) {
	int izquierda = 0;
	int derecha = productos.size() - 1;

	while (izquierda <= derecha) {
		int medio = izquierda + (derecha - izquierda) / 2;

		if (productos[medio].obID() == idBuscado) {
			return medio;
		}

		if (productos[medio].obID() < idBuscado) {
			izquierda = medio + 1;
		} else {
			derecha = medio - 1;
		}
	}
	return -1;
}

void Almacen::agregarProducto(Producto &producto) {
	insertarOrdenadoPorID(producto);
}

void Almacen::mostrarProductos() {
	for (Producto &producto : productos) {
		producto.mostrar();
	}
}

void Almacen::actualizarPrecioProducto(int id, float nuevoPrecio){
	int pos = buscarPorID(id);
	if (pos != -1){
		productos[pos].actualizarPrecio(nuevoPrecio);
	} else {
		cout << "ERROR: No se encontro el Producto" << endl;
	}
}

void Almacen::aumentarCantidadProducto(int id, int cantidad) {
	int pos = buscarPorID(id);
	if (pos != -1){
		productos[pos].aumentarCantidad(cantidad);
	} else {
		cout << "ERROR: No se encontro el Producto" << endl;
	}
}

void Almacen::reducirCantidadProducto(int id, int cantidad) {
	int pos = buscarPorID(id);
	if (pos != -1){
		productos[pos].reducirCantidad(cantidad);
		
		/*
		if (productos[pos].cantidad < 0) {
			cout << "ERROR: No puede reducir a una cantidad menor que 0" << endl;
		} else if (productos[pos].cantidad == 0){
			productos.erase(productos.begin()+pos); // Dudando si dejarlo aqui o controlarlo afuera
		}
		*/
	} else {
		cout << "ERROR: No se encontro el Producto" << endl;
	}
}


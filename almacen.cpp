#include "almacen.h"
#include "producto.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Almacen::Almacen() {
	nombreArchivo = "productos.txt";
}

Almacen::Almacen(string nA) : nombreArchivo(nA) {}

void Almacen::actualizarIndiceNombre() {
	// Limpiar índice existente
	indiceNombre.clear();

	// Reconstruir índice
	for (Producto &producto : productos) {
		indiceNombre[producto.obNombre()] = &producto;
	}
}

vector<Producto*> Almacen::encontrarPorInicioNombre(string nombrePrefijo) {
	std::vector<Producto*> productosEncontrados;

	for (Producto &producto : productos) {
		// Búsqueda por coincidencia parcial (contiene el nombre)
		if (producto.obNombre().find(nombrePrefijo) != string::npos) {
			productosEncontrados.push_back(&producto);
		}
	}

	return productosEncontrados;
}

Producto* Almacen::buscarPorNombre(string nombreBuscado) {
	auto it = indiceNombre.find(nombreBuscado);
	if (it != indiceNombre.end()) {
		return it->second;
	}
	return nullptr;
}

void Almacen::cargarDesdeArchivo(string nArchivo = "") {
	ifstream archivo(nombreArchivo);

	if(!archivo.is_open()) {
		cout << "ERROR: no se pudo abrir el archivo";
		return;
	}

	int id, cantidad;
	float precio;
	string nombre;

	string linea;

	while(getline(archivo, linea)) {
		stringstream ss(linea);

		// Leer ID, cantidad y precio primero
		ss >> id >> cantidad >> precio;
		ss.ignore(); // Ignorar el espacio después del precio
		getline(ss, nombre);

		Producto prod(id, nombre, cantidad, precio);
		agregarProducto(prod);
	}

	archivo.close();
}

void Almacen::guardarEnArchivo(string nArchivo = "") {
	ofstream archivo(nombreArchivo);

	if(!archivo.is_open()) {
		cout << "ERROR: no se pudo abrir el archivo";
		return;
	}

	for (Producto &producto : productos) {
		archivo << producto.obID() << " "
		        << producto.obCantidad() << " "
		        << producto.obPrecio() << " "
		        << producto.obNombre() << std::endl;
	}

	archivo.close();
}

void Almacen::cambiarNombreArchivo(string nuevoNombre) {
	nombreArchivo = nuevoNombre;
}

void Almacen::insertarOrdenadoPorID(Producto &nuevoProducto) {
	if (productos.empty()) {
		productos.push_back(nuevoProducto);
		return;
	}

	auto it = lower_bound(productos.begin(), productos.end(), nuevoProducto);
	productos.insert(it, nuevoProducto);
	actualizarIndiceNombre();
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

Producto* Almacen::buscarPorIDs(int idBuscado) {
	// Búsqueda binaria estándar
	int izquierda = 0;
	int derecha = productos.size() - 1;

	while (izquierda <= derecha) {
		int medio = izquierda + (derecha - izquierda) / 2;

		if (productos[medio].obID() == idBuscado) {
			return &productos[medio];
		}

		if (productos[medio].obID() < idBuscado) {
			izquierda = medio + 1;
		} else {
			derecha = medio - 1;
		}
	}

	return nullptr;
}

void Almacen::agregarProducto(Producto &producto) {
	insertarOrdenadoPorID(producto);
}

void Almacen::eliminarProducto(int id) {
	int pos = buscarPorID(id);
	if(pos != -1) {
		productos.erase(productos.begin()+pos);
		cout << "Producto eliminado correctamente" << endl;
		return;
	} else {
		cout << "ERROR: No se encontro el Producto" << endl;
	}
}

void Almacen::mostrarProductos() {
	for (Producto &producto : productos) {
		producto.mostrar();
	}
}

void Almacen::mostrarProducto(int pos) {
	productos[pos].mostrar();
}

void Almacen::mostrarAlgunosProductos(vector<Producto*> productos2) {
	for (Producto* producto : productos2) {
		producto->mostrar();
	}
}

void Almacen::actualizarPrecioProducto(int id, float nuevoPrecio) {
	int pos = buscarPorID(id);
	if (pos != -1) {
		productos[pos].actualizarPrecio(nuevoPrecio);
	} else {
		cout << "ERROR: No se encontro el Producto" << endl;
	}
}

void Almacen::aumentarCantidadProducto(int id, int cantidad) {
	int pos = buscarPorID(id);
	if (pos != -1) {
		productos[pos].aumentarCantidad(cantidad);
	} else {
		cout << "ERROR: No se encontro el Producto" << endl;
	}
}

void Almacen::reducirCantidadProducto(int id, int cantidad) {
	int pos = buscarPorID(id);
	if (pos != -1) {
		productos[pos].reducirCantidad(cantidad);

		if (productos[pos].obCantidad() < 0) {
			cout << "ERROR: No puede reducir a una cantidad menor que 0" << endl;
			productos[pos].aumentarCantidad(cantidad);
		} else if (productos[pos].obCantidad() == 0) {
			cout << "ADVERTENCIA: Producto ahora sin stock" << endl;
		}

	} else {
		cout << "ERROR: No se encontro el Producto" << endl;
	}
}

Producto Almacen::obtenerProductoPorID(int id) {
    int pos = buscarPorID(id);
	return productos[pos];
}

bool Almacen::verificarIdEnProductos(int id) {
	int pos = buscarPorID(id);
	if(pos != -1) return true;
	return false;
}


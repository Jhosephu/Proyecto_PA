#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using namespace std;

class Producto {
	private:
		int id;
    	string nombre;
    	int cantidad;
    	float precio;	
	public:
		Producto(int i, string n, int c, float p);
		bool operator<(const Producto &otro);
    	bool operator==(const Producto& otro);
		int obID(); // Obtener ID
		string obNombre(); // Obtener Nombre
		int obCantidad(); // Obtener Cantidad
		float obPrecio(); // Obtener Precio
    	void mostrar();
    	void actualizarPrecio(float nuevoPrecio);
    	void aumentarCantidad(int cantidad);
		void reducirCantidad(int cantidad);
};

#endif
#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using namespace std;

class Producto {
	private:
		int id;
    	string nombre;
    	int cantidad;
    	double precio;	
	public:
		bool operator<(const Producto &otro);
    	bool operator==(const Producto& otro);
		int obID(); // Obtener ID
		string obNombre(); // Obtener Nombre
    	void mostrar();
    	void actualizarPrecio(double nuevoPrecio);
    	void aumentarCantidad(int cantidad);
		void reducirCantidad(int cantidad);
};

#endif
#ifndef VENTA_H
#define VENTA_H
#include "producto.h"

#include <bits/stdc++.h>

using namespace std;

class Venta{
	private:
		int id;
		vector<Producto> produtos;
		float total;
		bool pendiente;
		string fecha;
	public:
		Venta(int, vector<Producto>, string);
		void calcularTotal(vector<Producto>);
		void cambiarEstado(bool);
		void mostrarDatos();
		string obtenerFecha();
}

#endif
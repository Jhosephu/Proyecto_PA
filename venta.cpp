#include <bits/stdc++.h>
#include "venta.h"
#include "producto.h"

using namespace std;

Venta::Venta(int i, vector<Producto> p, string f){
	id=i;
	productos=p;
	fecha=f;
	pendiente=true;
	total=0;
    calcularTotal(productos);
}

void Venta::calcularTotal(vector<Producto> productos) {
	total = 0;
   	for (size_t i = 0; i < productos.size(); ++i) {
        total += productos[i].obPrecio();
    }
}

void Venta::cambiarEstado(bool estado) {
    pendiente = estado;
}

void Venta::mostrarDatos() {
    cout << "Venta ID: " << id << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Estado: " << (pendiente ? "Pendiente" : "Finalizada") << endl;
    cout << "Total: " << total << endl;
    cout << "Productos:" << endl;
    for (size_t i = 0; i < productos.size(); ++i) {
        cout << "- " << productos[i].obNombre() << ": " << productos[i].obPrecio() << endl;
    }
}

string Venta::obtenerFecha() {
    	return fecha;
}



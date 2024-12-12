#include <bits/stdc++.h>
#include "venta.h"
#include "producto.h"

using namespace std;

Venta::Venta(int i, string f){
	id = i;
    fecha = f;
}

void Venta::agregarProducto(Producto p, int cantidad) {
    vector<Producto> productoParaVenta;
	productoParaVenta[id] = p;  // Copia para reducir stock de la clase Producto
    productoParaVenta[id].reducirCantidad(cantidad);
    productoParaVenta.push_back(p);
    total += p.obPrecio() * cantidad;
}

void Venta::mostrarVenta() {
    cout << "Venta ID: " << id << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Total: " << total << endl;
    cout << "Productos: " << endl;
    for (auto& producto : productos) {
		cout << "- " << producto.obNombre() << ": " 
             << producto.obPrecio() << endl;
    }
}

void Venta::actualizarStock() {
    for (auto& producto : productos) {
        producto.reducirCantidad(1); // Ejemplo: Reducir en 1 el stock de cada producto
    }
}



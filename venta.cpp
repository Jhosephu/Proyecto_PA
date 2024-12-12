#include <bits/stdc++.h>
#include "venta.h"
#include "producto.h"
#include "almacen.h"

using namespace std;

Venta::Venta() {};

Venta::Venta(int i, Producto p, string f){
	id = i;
	productos.push_back(p);
    fecha = f;
}

void Venta::agregarProducto(Producto p, int cantidad, int idVenta) {
	if (this->id == idVenta) {
        // Si el ID de venta no coincide, reiniciar la venta
        this->id = idVenta;
        this->productos.clear(); // Limpiar los productos anteriores
        this->total = 0;         // Reiniciar el total
    }
	productos.push_back(p);
    unidades = cantidad;
    total += p.obPrecio() * unidades;
}

void Venta::mostrarComprobante() {
    cout << "Venta ID: " << id << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Total: " << total << " USD" << endl;
    cout << "Productos: " << endl;
    for (size_t i = 0; i < productos.size(); i++) {
        cout << "- " << productos[i].obNombre() << endl;
    }
}

void Venta::actualizarStock() {
	Almacen inventario;
	inventario.mostrarProductos();
	int idProducto, cantidad;
	cout << "Ingrese el ID del producto para actualizar su cantidad: ";
	cin >> idProducto;
	cout << "                                        Ingrese la cantidad a agregar: ";
	cin >> cantidad;
	inventario.aumentarCantidadProducto(idProducto, cantidad);
	//cout << "Stock actualizado correctamente.\n"; no actualiza o eso pienso
}




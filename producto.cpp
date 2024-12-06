#include "producto.h"
#include <iostream>

using namespace std;

bool Producto::operator<(const Producto &otro){
	return id < otro.id;
}

bool Producto::operator==(const Producto &otro){
	return id == otro.id;
}

int Producto::obID(){
	return id;
}

string Producto::obNombre(){
	return nombre;
}
void Producto::mostrar(){
	cout << "ID: " << id << "\tNombre: " << nombre << "\tCantidad: "
		<< cantidad << "\tPrecio: " << precio << endl;
}

void Producto::actualizarPrecio(double nuevoPrecio){
	precio = nuevoPrecio;
}

void Producto::aumentarCantidad(int cantidad){
	cantidad += cantidad;
}

void Producto::reducirCantidad(int cantidad){
	cantidad -= cantidad;
}
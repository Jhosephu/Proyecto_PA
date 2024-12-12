#include "producto.h"

#include <iostream>

using namespace std;

Producto::Producto(int i, string n, int c, float p){
	id = i;
	nombre = n;
	cantidad = c;
	precio = p;
}

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

int Producto::obCantidad(){
	return cantidad;
}

float Producto::obPrecio(){
	return precio;
}

void Producto::mostrar(){
	cout << "ID: " << id << "\tNombre: " << nombre << "\tCantidad: "
		<< cantidad << "\tPrecio: " << precio << endl;
}

void Producto::actualizarPrecio(float nuevoPrecio){
	precio = nuevoPrecio;
}

void Producto::aumentarCantidad(int cantidad){
	cantidad += cantidad;
}

void Producto::reducirCantidad(int cantidad){
	cantidad -= cantidad;
}

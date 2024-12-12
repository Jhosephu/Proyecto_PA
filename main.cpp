#include <iostream>
#include "almacen.h"
#include "utilidades.h"

int main() {
	
	Almacen almacen;
	almacen.cargarDesdeArchivo();
	
	Utilidades util; // Crear una instancia de la clase Utilidades
	util.mostrarMenuPrincipal(almacen);// Llamar al metodo que muestra el menu
	
	return 0;// Finalizar el programa
}

#include <iostream>
#include "almacen.h"
#include "utilidades.h"

int main() {
	
	Almacen almacen;
	almacen.cargarDesdeArchivo();
	
	Utilidades util; // Crear una instancia de la clase Utilidades

	util.mostrarMenuPrincipal(almacen);// Llamar al metodo que muestra el menu
	
>>>>>>> f594786b0dfd1a9e20ac94dd5f7a3bb25f1cd2a7
	return 0;// Finalizar el programa
}

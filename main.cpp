#include <iostream>
#include "almacen.h"
#include "utilidades.h"
#include <windows.h>

int main() {
	
	SetConsoleOutputCP(CP_UTF8);
	
	Almacen almacen;
	almacen.cargarDesdeArchivo("");
	
	Utilidades util; // Crear una instancia de la clase Utilidades

	util.mostrarMenuPrincipal(almacen);// Llamar al metodo que muestra el menu
	
	return 0;// Finalizar el programa
}

#include <iostream>
#include "almacen.h"
#include "utilidades.h"

#include "venta.h"
#include "transacciones.h"
#include <windows.h>

using namespace std;

int main() {

	
	
	SetConsoleOutputCP(CP_UTF8);
	
	Almacen almacen;
	almacen.cargarDesdeArchivo("");
	
	Transacciones transaccion;
	
	Utilidades util; // Crear una instancia de la clase Utilidades

	util.mostrarMenuPrincipal(almacen, transaccion);// Llamar al metodo que muestra el menu
	
	return 0;// Finalizar el programa
}

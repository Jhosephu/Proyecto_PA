#include "utilidades.h"
#include "producto.h"


#include<stdlib.h>
#include<windows.h>

#include <iomanip>
#include <string>
#include <iostream>
#include <cstdlib> // Para usar system()
using namespace std;

Utilidades::Utilidades() {
    // Constructor vacio por ahora
}

Utilidades::~Utilidades() {
    // Destructor vacio por ahora
}

void Utilidades::limpiarPantalla() {
    // Borra la pantalla segun el sistema operativo
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux/macOS
#endif
}

void Utilidades::mostrarMenuPrincipal() {
	
    int opcion = 0;
    do {
    	limpiarPantalla();
		
		// Colores para secciones del menú
	    int colorTitulo = 11;   // Amarillo brillante
	    int colorOpciones = 14; // Azul brillante
	    int colorBordes = 8;    // Gris

		system("color 0F");
    	gotoxy(40,5);
    	cambiarColorTexto(colorBordes);
    	cout << "==================================\n";
    	gotoxy(40, 7);
    	cambiarColorTexto(colorTitulo);
        cout << "          MENU PRINCIPAL          \n";
        gotoxy(45, 11);
        cambiarColorTexto(colorOpciones);
        cout << "1. GESTIONAR PRODUCTOS\n";
		gotoxy(45, 13); 
        cout << "2. REPORTE DE CONSULTAS\n";
        gotoxy(45, 15);
        cout << "3. OPERACIONES DE VENTAS\n";
        gotoxy(45, 17);
        cout << "4. ARCHIVOS\n";
        gotoxy(45, 19);
        cout << "5. SALIR DEL SISTEMA\n";
        gotoxy(40, 23);
        cambiarColorTexto(colorBordes);
        cout << "==================================\n";
        gotoxy(43, 25);
        cambiarColorTexto(colorTitulo);
        cout << "Seleccione una opcion: ";
        gotoxy(40,27);
        cambiarColorTexto(colorBordes);
        cout << "==================================\n";
     	gotoxy(67, 25);
     	cambiarColorTexto(colorOpciones);
        cin >> opcion;

        switch (opcion) {
            case 1:
                gestionarProductos();
                break;
            case 2:
                reporteConsultas();
                break;
            case 3:
                operacioneVentas();
                break;
            case 4:
                archivo();
                break;
            case 5:
            	cout << "\n";
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while (opcion != 5);
}

void Utilidades::gestionarProductos() {

	
    int opcion = 0;
    do {
    	limpiarPantalla();
    	
    	// Colores para el menú de productos
        int colorTitulo = 10;   // Verde brillante
        int colorOpciones = 15; // Amarillo brillante
        int colorBordes = 8;    // Gris
    	
    	
    	gotoxy(40,5);
    	cambiarColorTexto(colorBordes);
		cout << "==================================\n";
		gotoxy(40, 7);
		cambiarColorTexto(colorTitulo);
        cout << "        MENU DE PRODUCTOS         \n";
        gotoxy(45, 11);
        cambiarColorTexto(colorOpciones);
        cout << "1. Modificar Producto\n";
        gotoxy(45, 13); 
        cout << "2. Consultar Producto\n";
        gotoxy(45, 15);
        cout << "3. Regresar al Menu Principal\n";
        gotoxy(40, 19);
        cambiarColorTexto(colorBordes);
        cout << "==================================\n";
        gotoxy(45, 21);
        cambiarColorTexto(colorTitulo);
        cout << "Seleccione una opcion: ";
        gotoxy(40, 23);
        cambiarColorTexto(colorBordes);
        cout << "==================================\n";
        gotoxy(68, 21);
        cambiarColorTexto(colorOpciones);
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Opcion de Modificar Producto seleccionada.\n"; // funcion no agregada todavia
                break;
            case 2:
                cout << "Opcion de Consultar Producto seleccionada.\n"; // funcion no agregada todavia
                break;
            case 3:
                cout << "Regresando al Menu Principal...\n";
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while (opcion != 3);
}

void Utilidades::reporteConsultas() {
    int opcion = 0;
    do {
        limpiarPantalla();
        
        int colorTitulo = 14;   // Amarillo brillante
	    int colorOpciones = 5; // Azul brillante
	    int colorBordes = 8;    // Gris
        
    	gotoxy(40,5);
    	cambiarColorTexto(colorBordes);
		cout << "==================================\n";
		gotoxy(40, 7);
		cambiarColorTexto(colorTitulo);
        cout << "          MENU DE CONSULTAS          \n";
        gotoxy(45, 11);
        cambiarColorTexto(colorOpciones);
        cout << "1. Estado del Almacen\n";
        gotoxy(45, 13);
        cout << "2. Estado de Ventas\n";
        gotoxy(45, 15);
        cout << "3. Resumen de Ventas\n";
        gotoxy(45, 17);
        cout << "4. Regresar al Menu Principal\n";
        gotoxy(40, 21);
        cambiarColorTexto(colorBordes);
        cout << "=====================================\n";
        gotoxy(45, 23);
        cambiarColorTexto(colorTitulo);
        cout << "Seleccione una opcion: ";
        gotoxy(40, 25);
        cambiarColorTexto(colorBordes);
        cout << "=====================================\n";
        gotoxy(67, 23);
        cambiarColorTexto(colorOpciones);
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Opcion de Estado del Almacen seleccionada.\n"; // funcion no agregada todavia
                break;
            case 2:
                cout << "Opcion de Estado de Ventas seleccionada.\n"; // funcion no agregada todavia
                break;
            case 3:
                cout << "Opcion de Resumen de Ventas seleccionada.\n"; // funcion no agregada todavia
                break;
            case 4:
                cout << "Regresando al Menu Principal...\n";
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while (opcion != 4);
}

void Utilidades::operacioneVentas() {
    int opcion = 0;
    do {
        limpiarPantalla();
        
        int colorTitulo = 12;   // Amarillo brillante
	    int colorOpciones = 7; // Azul brillante
	    int colorBordes = 8;    // Gris
        
        gotoxy(40,5);
        cambiarColorTexto(colorBordes);
		cout << "==================================\n";
		gotoxy(40, 7);
		cambiarColorTexto(colorTitulo);
        cout << "          MENU DE VENTAS          \n";
        gotoxy(45, 11);
        cambiarColorTexto(colorOpciones);
        cout << "1. Registrar una Venta\n";
        gotoxy(45, 13);
        cout << "2. Emitir Comprobante\n";
        gotoxy(45, 15);
        cout << "3. Actualizar Stock\n";
        gotoxy(45, 17);
        cout << "4. Regresar al Menu Principal\n";
        gotoxy(40, 21);
        cambiarColorTexto(colorBordes);
        cout << "===================================\n";
        gotoxy(45, 23);
        cambiarColorTexto(colorTitulo);
        cout << "Seleccione una opcion: ";
        gotoxy(40, 25);
        cambiarColorTexto(colorBordes);
        cout << "===================================\n";
        gotoxy(67, 23);
        cambiarColorTexto(colorOpciones);
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Opcion de Registrar una Venta seleccionada.\n"; // funcion no agregada todavia
                break;
            case 2:
                cout << "Opcion de Emitir Comprobante seleccionada.\n"; // funcion no agregada todavia
                break;
            case 3:
                cout << "Opcion de Actualizar Stock seleccionada.\n"; // funcion no agregada todavia
                break; 
            case 4:
                cout << "Regresando al Menu Principal...\n";
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while (opcion != 4);
}

void Utilidades::archivo() {
	
    int opcion = 0;
    do {
        limpiarPantalla();

		int colorTitulo = 9;   // Amarillo brillante
	    int colorOpciones = 11; // Azul brillante
	    int colorBordes = 8;    // Gris

		gotoxy(40,5);
		cambiarColorTexto(colorBordes);
        cout << "=====================================\n";
        gotoxy(40, 7);
        cambiarColorTexto(colorTitulo);
        cout << "          MENU DE ARCHIVOS           \n";
        gotoxy(45, 11);
        cambiarColorTexto(colorOpciones);
        cout << "1. Cargar Datos desde Archivo\n";
        gotoxy(45, 13);
        cout << "2. Guardar Datos en Archivo\n";
        gotoxy(45, 15);
        cout << "3. Regresar al Menu Principal\n";
        gotoxy(40, 19);
        cambiarColorTexto(colorBordes);
        cout << "=====================================\n";
        gotoxy(45, 21);
        cambiarColorTexto(colorTitulo);
        cout << "Seleccione una opcion: ";
        gotoxy(40, 23);
        cambiarColorTexto(colorBordes);
        cout << "=====================================\n";
        gotoxy(68, 21);
        cambiarColorTexto(colorOpciones);
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Opcion de Cargar Datos desde Archivo seleccionada.\n"; // funcion no agregada todavia
                break;
            case 2:
                cout << "Opcion de Guardar Datos en Archivo seleccionada.\n"; // funcion no agregada todavia
                break;
            case 3:
                cout << "Regresando al Menu Principal...\n";
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while (opcion != 3);
}

//// FUNCION GOTO PARA COLOCAR LAS COORDENADAS DEL MENU ////
void Utilidades::gotoxy(int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

// Funcion para cambiar el color de texto
void Utilidades::cambiarColorTexto(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

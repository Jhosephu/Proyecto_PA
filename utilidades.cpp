#include "utilidades.h"
#include "producto.h"
#include "venta.h"
#include "transacciones.h"
#include "almacen.h"

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

void Utilidades::mostrarMenuPrincipal(Almacen &almacen) {
	
    int opcion = 0;
    do {
    	limpiarPantalla();
		
		// Colores para secciones del men�
		int colorTitulo = 9;   
	    int colorOpciones = 11; 
	    int colorBordes = 8; 

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
                gestionarProductos(almacen);
                break;
            case 2:
                reporteConsultas(almacen);
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

void Utilidades::gestionarProductos(Almacen &almacen) {

	
    int opcion = 0;
    do {
    	limpiarPantalla();
    	
    	// Colores para el menu de productos
		int colorTitulo = 9;   
	    int colorOpciones = 11; 
	    int colorBordes = 8; 
    	
    	
    	gotoxy(40,5);
    	cambiarColorTexto(colorBordes);
		cout << "==================================\n";
		gotoxy(40, 7);
		cambiarColorTexto(colorTitulo);
        cout << "        MENU DE PRODUCTOS         \n";
        gotoxy(45, 11);
        cambiarColorTexto(colorOpciones);
        cout << "1. Agregar Producto\n";
        gotoxy(45, 13); 
        cout << "2. Modificar Producto\n";
        gotoxy(45, 15); 
        cout << "3. Buscar Producto\n";
        gotoxy(45, 17); 
        cout << "4. Eliminar Producto\n";
        gotoxy(45, 19);
        cout << "5. Regresar al Menu Principal\n";
        gotoxy(40, 23);
        cambiarColorTexto(colorBordes);
        cout << "==================================\n";
        gotoxy(45, 25);
        cambiarColorTexto(colorTitulo);
        cout << "Seleccione una opcion: ";
        gotoxy(40, 27);
        cambiarColorTexto(colorBordes);
        cout << "==================================\n";
        gotoxy(68, 25);
        cambiarColorTexto(colorOpciones);
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarProductoM(almacen);
                break;
            case 2:
                modificarProductoM(almacen);
                break;
            case 3:
                buscarProductoM(almacen);
                break;
            case 4:
                eliminarProductoM(almacen);
                break;
            case 5:
                cout << "Regresando al Menu Principal...\n";
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while (opcion != 5);
}

void Utilidades::reporteConsultas(Almacen &almacen) {
    int opcion = 0;
    do {
        limpiarPantalla();
        
		int colorTitulo = 9;   
	    int colorOpciones = 11; 
	    int colorBordes = 8; 
        
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
	//Almacen almacen;
    //almacen.cargarDesdeArchivo();
	Venta venta;
    Transacciones transacciones;
    int opcion = 0;
    do {
        limpiarPantalla();
        
		int colorTitulo = 9;   
	    int colorOpciones = 11; 
	    int colorBordes = 8; 
        
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
				do{
					int idProducto, cantidad, idVenta;
				    string fecha;
					vector<Producto> productos;
				    cout << "Ingrese el ID de la venta: ";
				    cin >> idVenta;
				    cout << "Ingrese la fecha de la venta: ";
				    cin >> fecha;
				    
				    cout << "Ingrese el ID del producto a vender: ";
				    cin >> idProducto;
				    cout << "Ingrese la cantidad: ";
				    cin >> cantidad;
					
				    int posProducto = almacen.buscarPorID(idProducto);
				    if (posProducto != -1) {
				        Producto producto = almacen.obtenerProductoPorID(idProducto);
				        Venta venta(idVenta, producto, fecha);
				        if (producto.obCantidad() >= cantidad) {
				            venta.agregarProducto(producto, cantidad);
				            transacciones.registrarVenta(venta);
				            almacen.reducirCantidadProducto(idProducto, cantidad);
				            cout << "Venta registrada exitosamente.\n";
				        } else {
				            cout << "Cantidad insuficiente en stock.\n";
				        }
				    } else {
				        cout << "Producto no encontrado.\n";
				    }
				}while(0);
				system("PAUSE");
                break;
            case 2:
            	do{
				    int idVenta;
				    cout << "Ingrese el ID de la venta para emitir comprobante: ";
				    cin >> idVenta;
				
				    Venta *ventas = transacciones.buscarVentaPorId(idVenta);
				    if (ventas) {
				        ventas->mostrarComprobante();
				    }
            	}while(0);
            	system("PAUSE");
                break;
            case 3:
				venta.actualizarStock();
            	system("PAUSE");
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

		int colorTitulo = 9;   
	    int colorOpciones = 11; 
	    int colorBordes = 8;    

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
                //almacen.; // funcion no agregada todavia
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

// fUNCIONES GestionarProductos

void Utilidades::agregarProductoM(Almacen &almacen){
	int x = 40, y = 29;
	int id, cantidad;
	float precio;
	string nombre;
	
	printC(x, y, "Ingrese el ID del Producto: ");
	
	do {
		cin >> id;
		if(almacen.verificarIdEnProductos(id)) printC(x, y, "Ingrese otro ID de Producto: ");
	} while(almacen.verificarIdEnProductos(id));
	
	cin.ignore();
	printC(x, y+2, "Ingrese el nombre del Producto: "); 
	getline(cin, nombre);
	printC(x, y+4, "Ingrese el stock del Producto: "); 
	cin >> cantidad;
	printC(x, y+6, "Ingrese el precio del Producto: "); 
	cin >> precio;
	
	Producto prod(id, nombre, cantidad, precio);
	
	almacen.agregarProducto(prod);
	
	printC(x, y+8, "Producto agregado exitosamente!\n\n");
	
	system("pause");
}

void Utilidades::modificarProductoM(Almacen &almacen) {
    int x = 40, y = 29;
    int id;
    float nuevoPrecio;
    int nuevaCantidad;

    printC(x, y, "Ingrese el ID del Producto a modificar: ");
    cin >> id;

    if (almacen.verificarIdEnProductos(id)) {
        printC(x, y+2, "Ingrese el nuevo precio del Producto: ");
        cin >> nuevoPrecio;
        printC(x, y+4, "Ingrese la nueva cantidad del Producto: ");
        cin >> nuevaCantidad;

        almacen.actualizarPrecioProducto(id, nuevoPrecio);
        almacen.aumentarCantidadProducto(id, nuevaCantidad);

        printC(x, y+6, "Producto modificado exitosamente!\n\n");
    } else {
        printC(x, y+2, "ERROR: No se encontro el Producto con ese ID.\n\n");
    }

    system("pause");
}

void Utilidades::buscarProductoM(Almacen &almacen) {
    int x = 40, y = 29;
    int id;
    string nombre;
    int opcion;

    printC(x, y, "Buscar por:\n");
    printC(x, y+2, "1. ID del Producto\n");
    printC(x, y+4, "2. Nombre del Producto\n");
    printC(x, y+6, "Seleccione una opcion: ");
    cin >> opcion;

    if (opcion == 1) {
        printC(x, y+8, "Ingrese el ID del Producto: ");
        cin >> id;

        Producto* p = almacen.buscarPorIDs(id);
        if (p) {
            printC(x, y+10, "Producto encontrado:\n");
            printProducto(x, y+12, p);
        } else {
            printC(x, y+10, "ERROR: No se encontro el Producto con ese ID.\n\n");
        }
    } else if (opcion == 2) {
        cin.ignore();
        printC(x, y+8, "Ingrese el nombre del Producto: ");
        getline(cin, nombre);

        Producto* producto = almacen.buscarPorNombre(nombre);
        if (producto != nullptr) {
            printC(x, y+10, "Producto encontrado:\n");
            printProducto(x, y+12, producto);
        } else {
            printC(x, y+10, "ERROR: No se encontro el Producto con ese nombre.\n\n");
        }
    } else {
        printC(x, y+8, "Opcion no valida.\n\n");
    }

    system("pause");
}

void Utilidades::eliminarProductoM(Almacen &almacen) {
    int x = 40, y = 29;
    int id;

    printC(x, y, "Ingrese el ID del Producto a eliminar: ");
    cin >> id;

    if (almacen.verificarIdEnProductos(id)) {
        almacen.eliminarProducto(id);
        printC(x, y+2, "Producto eliminado exitosamente!\n\n");
    } else {
        printC(x, y+2, "ERROR: No se encontro el Producto con ese ID.\n\n");
    }

    system("pause");
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

void Utilidades::printC(int x, int y, string text) {
    gotoxy(x, y);
    cout << text;
}

void Utilidades::printProducto(int x, int y, Producto* p) {
    gotoxy(x, y);
    cout << "ID: " << p->obID() << "\tNombre: " << p->obNombre() << "\tCantidad: "
		<< p->obCantidad() << "\tPrecio: " << p->obPrecio() << endl;
}

// Funcion para cambiar el color de texto
void Utilidades::cambiarColorTexto(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

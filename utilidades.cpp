#include "utilidades.h"
#include "producto.h"
#include "almacen.h"
#include "venta.h"
#include "transacciones.h"
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
        cout << "========= MENU PRINCIPAL =========\n";
        cout << "1. Gestionar Productos\n";
        cout << "2. Reporte de Consultas\n";
        cout << "3. Operaciones de Ventas\n";
        cout << "4. Archivos\n";
        cout << "5. Salir del Sistema\n";
        cout << "==================================\n";
        cout << "Seleccione una opcion: ";
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
        cout << "========= MENU DE PRODUCTOS =========\n";
        cout << "1. Modificar Producto\n";
        cout << "2. Consultar Producto\n";
        cout << "3. Regresar al Menu Principal\n";
        cout << "=====================================\n";
        cout << "Seleccione una opcion: ";
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
        cout << "========= MENU DE CONSULTAS =========\n";
        cout << "1. Estado del Almacen\n";
        cout << "2. Estado de Ventas\n";
        cout << "3. Resumen de Ventas\n";
        cout << "4. Regresar al Menu Principal\n";
        cout << "=====================================\n";
        cout << "Seleccione una opcion: ";
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
	Almacen almacen;
    almacen.cargarDesdeArchivo();
    Transacciones transacciones;
    Venta venta;
    int opcion = 0;
    do {
        limpiarPantalla();
        cout << "========= MENU DE VENTAS =========\n";
        cout << "1. Registrar una Venta\n";
        cout << "2. Emitir Comprobante\n";
        cout << "3. Actualizar Stock para devoluciones\n";
        cout << "4. Regresar al Menu Principal\n";
        cout << "==================================\n";
        cout << "Seleccione una opcion: ";
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
        cout << "========= MENU DE ARCHIVOS =========\n";
        cout << "1. Cargar Datos desde Archivo\n";
        cout << "2. Guardar Datos en Archivo\n";
        cout << "3. Regresar al Menu Principal\n";
        cout << "====================================\n";
        cout << "Seleccione una opcion: ";
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


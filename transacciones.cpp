#include<bits/stdc++.h>
#include"venta.h"
#include"transacciones.h"



using namespace std;

Transacciones::Transacciones() {}

// Implementación de métodos de la clase Transacciones
void Transacciones::registrarVenta(Venta venta) {
    ventas.push_back(venta);
}

void Transacciones::listarVentas() {
    if (ventas.empty()) {

        cout << "No hay ventas registradas.\n";
        return;
    }

    cout << "========== LISTA DE VENTAS ==========\n";
    for (size_t i = 0; i < ventas.size(); i++) {
        ventas[i].mostrarComprobante();
        cout << "-------------------------------------\n";
    }
}

Venta* Transacciones::buscarVentaPorId(int id) {
    for (size_t i = 0; i < ventas.size(); i++) {
        if (ventas[i].obtenerId() == id) {
            return &ventas[i];
        }
    }
    cout << "No se encontró una venta con el ID " << id << ".\n";
    return nullptr;
}



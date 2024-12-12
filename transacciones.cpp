#include<bits/stdc++.h>
#include"venta.h"
#include"transacciones.h"

using namespace std;

Transacciones::Transacciones() {}

// Implementación de métodos de la clase Transacciones
void Transacciones::registrarVenta(Venta venta) {
    ventas.push_back(venta);
    cout << "Venta registrada exitosamente.\n";
}

void Transacciones::listarVentas() {
    if (ventas.empty()) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    cout << "========== LISTA DE VENTAS ==========\n";
    for (size_t i = 0; i < ventas.size(); i++) {
        ventas[i].mostrarVenta();
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

void Transacciones::actualizarStockVentas() {
    for (Venta& venta : ventas) {
        venta.actualizarStock();
    }
    cout << "El stock de los productos ha sido actualizado en base a las ventas realizadas.\n";
}


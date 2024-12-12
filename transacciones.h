#ifndef TRANSACCIONES_H
#define TRANSACCIONES_H
#include "venta.h"

#include <string>
using namespace std;

class Transacciones {
    private:
        vector<Venta> ventas;

    public:
        Transacciones();

        void registrarVenta(Venta venta);
        void listarVentas();
        Venta* buscarVentaPorId(int id);
};

#endif

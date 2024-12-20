#ifndef VENTA_H
#define VENTA_H
#include "producto.h"

#include <bits/stdc++.h>

using namespace std;

class Venta {
    private:
        int id;
        vector<Producto> productos; // Aqu� se usan nombres de productos para simplificar
        float total;
        string fecha;
        int unidades;

    public:
    	Venta();
    	
        Venta(int, Producto p, string);

        int obtenerId() const {
            return id;
        }

        string obtenerFecha() const {
            return fecha;
        }

        float obtenerTotal() const {
            return total;
        }
		
		void agregarProducto(Producto p, int cantidad, int id);
        void emitirComprobante() const;
        void actualizarStock();
		void mostrarComprobante();
};

#endif

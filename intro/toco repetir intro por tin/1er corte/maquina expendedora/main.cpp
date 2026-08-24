#include <iostream>
using namespace std;

int main() {
    int dineroIngresado;
    int productoSeleccionado;
    int precioProducto;
    int vueltas;

    cout << "Bienvenido a la máquina expendedora!" << endl;
    cout << "Por favor, ingrese un monto entre $200 y $2500: ";
    cin >> dineroIngresado;

    if (dineroIngresado < 200 || dineroIngresado > 2500) {
        cout << "Monto fuera de rango. Se devuelve el dinero." << endl;
        return 0;
    }

    bool seguir = true;

    do {
        cout << "\nSeleccione un producto:" << endl;
        cout << "1. Papas Fritas $1200" << endl;
        cout << "2. Sandwich Combinado $2500" << endl;
        cout << "3. Pescadito $1800" << endl;
        cout << "4. Empanada $1700" << endl;
        cout << "5. Arepa $2000" << endl;
        cout << "6. Gaseosa $1600" << endl;
        cout << "7. Vaso de té $1000" << endl;
        cout << "8. Dulce $200" << endl;
        cout << "0. Salir y recibir el dinero de vuelta." << endl;
        cout << "Ingrese su selección: ";
        cin >> productoSeleccionado;

        switch (productoSeleccionado) {
            case 1: precioProducto = 1200; break;
            case 2: precioProducto = 2500; break;
            case 3: precioProducto = 1800; break;
            case 4: precioProducto = 1700; break;
            case 5: precioProducto = 2000; break;
            case 6: precioProducto = 1600; break;
            case 7: precioProducto = 1000; break;
            case 8: precioProducto = 200; break;
            case 0:
                cout << "Gracias por usar la máquina. Se devuelve el dinero: $" << dineroIngresado << endl;
                return 0;
            default:
                cout << "Selección inválida. Intente de nuevo." << endl;
                seguir = true;
                continue;
        }

        if (dineroIngresado >= precioProducto) {
            vueltas = dineroIngresado - precioProducto;
            cout << "Compra exitosa! Producto adquirido." << endl;
            cout << "Sus vueltas son: $" << vueltas << endl;

            int monedas500 = vueltas / 500;
            vueltas %= 500;
            int monedas200 = vueltas / 200;
            vueltas %= 200;
            int monedas100 = vueltas / 100;

            cout << "Vueltas en monedas:" << endl;
            cout << "Monedas de $500: " << monedas500 << endl;
            cout << "Monedas de $200: " << monedas200 << endl;
            cout << "Monedas de $100: " << monedas100 << endl;

            seguir = false;
        } else {
            cout << "No tiene suficiente dinero para este producto. Seleccione otro o salga." << endl;
        }

    } while (seguir);

    return 0;
}

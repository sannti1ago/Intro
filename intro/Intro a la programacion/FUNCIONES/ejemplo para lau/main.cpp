#include <iostream>
#include <cmath> // Incluyendo cmath

using namespace std;

// Prototipos de funciones
void consultarSaldo(double saldo);
void depositar(double &saldo, double cantidad);
bool retirar(double &saldo, double cantidad);
bool transferir(double &saldo, double cantidad);
int menu();

int main() {
    double saldo = 1000.0; // Saldo inicial
    int opcion;
    double cantidad;

    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                consultarSaldo(saldo);
                break;
            case 2:
                cout << "Ingrese la cantidad a depositar: ";
                cin >> cantidad;
                cantidad = fabs(cantidad); // Asegurar que la cantidad sea positiva
                depositar(saldo, cantidad);
                break;
            case 3:
                cout << "Ingrese la cantidad a retirar: ";
                cin >> cantidad;
                cantidad = fabs(cantidad); // Evitar valores negativos
                if (!retirar(saldo, cantidad)) {
                    cout << "Fondos insuficientes.\n";
                }
                break;
            case 4:
                cout << "Ingrese la cantidad a transferir: ";
                cin >> cantidad;
                cantidad = fabs(cantidad);
                if (!transferir(saldo, cantidad)) {
                    cout << "Fondos insuficientes para la transferencia.\n";
                }
                break;
            case 5:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}

int menu() {
    int opc;
    cout << "\nSeleccione una opción:\n";
    cout << "1. Consultar saldo\n";
    cout << "2. Depositar dinero\n";
    cout << "3. Retirar dinero\n";
    cout << "4. Transferir dinero\n";
    cout << "5. Salir\n";
    cout << "Opción? ";
    cin >> opc;
    return opc;
}

void consultarSaldo(double saldo) {
    cout << "Su saldo actual es: " << saldo << "\n";
}

void depositar(double &saldo, double cantidad) {
    if (cantidad > 0) {
        saldo += cantidad;
        cout << "Depósito exitoso. Su nuevo saldo es: " << saldo << "\n";
    } else {
        cout << "Cantidad inválida.\n";
    }
}

bool retirar(double &saldo, double cantidad) {
    if (cantidad > 0 && cantidad <= saldo) {
        saldo -= cantidad;
        cout << "Retiro exitoso. Su nuevo saldo es: " << saldo << "\n";
        return true;
    }
    return false;
}

bool transferir(double &saldo, double cantidad) {
    if (cantidad > 0 && cantidad <= saldo) {
        saldo -= cantidad;
        cout << "Transferencia exitosa. Su nuevo saldo es: " << saldo << "\n";
        return true;
    }
    return false;
}

#include <iostream>
using namespace std;

int main() {
    cout << "Este programa calcula una factura de cable." << endl;

    int numeroCuenta;
    char tipoCliente;
    int numCanalesPremium;
    int numConexiones = 0;
    double factura = 0.0;

    while (true) {
        cout << "\nIngrese el número de cuenta: ";
        cin >> numeroCuenta;

        cout << "Ingrese el tipo de cliente: R o r (Residencial), N o n (Negocios): ";
        cin >> tipoCliente;

        if (tipoCliente >= 'a' && tipoCliente <= 'z') {
            tipoCliente = tipoCliente - 'a' + 'A';
        }

        if (tipoCliente == 'R') {
            cout << "Ingrese el número de canales Premium: ";
            cin >> numCanalesPremium;

            factura = 4.50 + 20.50 + (7.50 * numCanalesPremium);

        } else if (tipoCliente == 'N') {
            cout << "Ingrese el número de conexiones de servicio básico: ";
            cin >> numConexiones;
            cout << "Ingrese el número de canales Premium: ";
            cin >> numCanalesPremium;

            factura = 15.00;
            if (numConexiones <= 10) {
                factura += 75.00;
            } else {
                factura += 75.00 + (numConexiones - 10) * 5.00;
            }
            factura += 50.00 * numCanalesPremium;

        } else {
            cout << "Tipo de cliente inválido. Intente de nuevo." << endl;
            continue;
        }

        int parteEntera = (int)factura;
        int parteDecimal = (int)((factura - parteEntera) * 100 + 0.5);

        cout << "Número de cuenta = " << numeroCuenta << " Cantidad a pagar: $"
             << parteEntera << ".";

        if (parteDecimal < 10) cout << "0";
        cout << parteDecimal << endl;
    }

    return 0;
}

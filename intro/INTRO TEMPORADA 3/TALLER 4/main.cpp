#include <iostream>
using namespace std;

int sumaDigitos(int numero) {
    int suma = 0;
    while (numero > 0) {
        suma += numero % 10;
        numero /= 10;
    }
    return suma;
}

int digitoVerificacion(int suma) {
    if (suma % 2 != 0) {
        return 0;
    } else {
        return 1;
    }
}

int generarTarjeta(int numero, int digito) {
    return numero * 10 + digito;
}

int main() {
    int numero;

    cout << "Ingrese un numero de 4 digitos (0 para terminar): ";
    cin >> numero;

    while (numero!=0) {
        int suma    = sumaDigitos(numero);
        int digito  = digitoVerificacion(suma);
        int tarjeta = generarTarjeta(numero, digito);

        cout << "Numero ingresado : " << numero  << endl;
        cout << "Suma de digitos  : " << suma    << endl;
        cout << "Digito de verif. : " << digito  << endl;
        cout << "Numero de tarjeta: " << tarjeta << endl;

        cout << "Ingrese otro numero (0 para terminar): ";
        cin >> numero;
    }
    return 0;
}
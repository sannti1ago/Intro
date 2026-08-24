#include <iostream>
#include <cmath>

using namespace std;

// Prototipos de funciones
bool primo(int n);
void primos(int n);
int MCD(int a, int b);
int MCM(int a, int b);
int contarDigitos(int num);
bool esPerfecto(int num);
int invertir(int num);
int menu();

int main() {
    int opcion, num1, num2;

    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                cout << "Escriba un número para verificar si es primo: ";
                cin >> num1;
                if (primo(num1)) {
                    cout << num1 << " es primo." << endl;
                } else {
                    cout << num1 << " no es primo." << endl;
                }
                break;

            case 2:
                cout << "Escriba un número para imprimir los primos hasta ese número: ";
                cin >> num1;
                primos(num1);
                break;

            case 3:
                cout << "Escriba dos números para calcular su MCD: ";
                cin >> num1 >> num2;
                cout << "El MCD de " << num1 << " y " << num2 << " es " << MCD(num1, num2) << endl;
                break;

            case 4:
                cout << "Escriba dos números para calcular su MCM: ";
                cin >> num1 >> num2;
                cout << "El MCM de " << num1 << " y " << num2 << " es " << MCM(num1, num2) << endl;
                break;

            case 5:
                cout << "Escriba un número para contar sus dígitos: ";
                cin >> num1;
                cout << "El número " << num1 << " tiene " << contarDigitos(num1) << " dígitos." << endl;
                break;

            case 6:
                cout << "Escriba un número para verificar si es perfecto: ";
                cin >> num1;
                if (esPerfecto(num1)) {
                    cout << num1 << " es un número perfecto." << endl;
                } else {
                    cout << num1 << " no es un número perfecto." << endl;
                }
                break;

            case 7:
                cout << "Escriba un número para invertirlo: ";
                cin >> num1;
                cout << "El número invertido es " << invertir(num1) << endl;
                break;

            case 8:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 8);

    return 0;
}

int menu() {
    int opc;
    cout << endl << "Seleccione una opción:" << endl;
    cout << "1. Verificar si un número es primo" << endl;
    cout << "2. Imprimir números primos hasta un número dado" << endl;
    cout << "3. Calcular MCD de dos números" << endl;
    cout << "4. Calcular MCM de dos números" << endl;
    cout << "5. Contar dígitos de un número" << endl;
    cout << "6. Verificar si un número es perfecto" << endl;
    cout << "7. Invertir un número" << endl;
    cout << "8. Salir" << endl;
    cout << "Opción? ";
    cin >> opc;
    return opc;
}

bool primo(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void primos(int n) {
    cout << "Números primos hasta " << n << ": ";
    for (int i = 2; i <= n; ++i) {
        if (primo(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int MCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int MCM(int a, int b) {
    return (a * b) / MCD(a, b);
}

int contarDigitos(int num) {
    int count = 0;
    if (num ==  0) return 1; // Si el número es 0, tiene 1 dígito
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

bool esPerfecto(int num) {
    int suma = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }
    return suma == num;
}

int invertir(int num) {
    int invertido = 0;
    while (num != 0) {
        invertido = invertido * 10 + num % 10;
        num /= 10;
    }
    return invertido;
}
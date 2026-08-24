#include <iostream>
using namespace std;

int main() {
    int filas, columnas, opcion;
    int matriz[50][50];
    bool llena = false;

    cout << "Ingrese el numero de filas (max. 50): ";
    cin >> filas;
    cout << "Ingrese el numero de columnas (max. 50): ";
    cin >> columnas;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Llenar la matriz\n";
        cout << "2. Imprimir la matriz\n";
        cout << "3. Calcular suma, promedio, mayor y menor\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    cout << "Fila " << i + 1 << ", Columna " << j + 1 << ": ";
                    cin >> matriz[i][j];
                }
            }
            llena = true;
        } else if (opcion == 2) {
            if (!llena) {
                cout << "Primero debe llenar la matriz.\n";
            } else {
                cout << "--- Imprimir matriz ---\n";
                for (int i = 0; i < filas; i++) {
                    for (int j = 0; j < columnas; j++) {
                        cout << matriz[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        } else if (opcion == 3) {
            if (!llena) {
                cout << "Primero debe llenar la matriz.\n";
            } else {
                int suma = 0, mayor = matriz[0][0], menor = matriz[0][0];
                int filaMayor = 0, colMayor = 0, filaMenor = 0, colMenor = 0;
                for (int i = 0; i < filas; i++) {
                    for (int j = 0; j < columnas; j++) {
                        suma += matriz[i][j];
                        if (matriz[i][j] > mayor) {
                            mayor = matriz[i][j];
                            filaMayor = i;
                            colMayor = j;
                        }
                        if (matriz[i][j] < menor) {
                            menor = matriz[i][j];
                            filaMenor = i;
                            colMenor = j;
                        }
                    }
                }
                float promedio = (float)suma / (filas * columnas);
                cout << "Suma de todos los elementos: " << suma << endl;
                cout << "Promedio: " << promedio << endl;
                cout << "Numero mayor: " << mayor << ". Fila: " << filaMayor << ", Columna: " << colMayor << endl;
                cout << "Numero menor: " << menor << ". Fila: " << filaMenor << ", Columna: " << colMenor << endl;
            }
        } else if (opcion != 4) {
            cout << "Opcion no valida.\n";
        }
    } while (opcion != 4);

    cout << "Adios :)\n";
    return 0;
}

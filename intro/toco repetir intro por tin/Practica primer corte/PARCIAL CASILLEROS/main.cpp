#include <iostream>

using namespace std;

int main() {
    int numCasilleros;

    cout << "Ingrese el número de casilleros en la institución: ";
    cin >> numCasilleros;

    bool* casilleros = new bool[numCasilleros];

    for (int i = 0; i < numCasilleros; i++) {
        casilleros[i] = false;
    }

    for (int i = 0; i < numCasilleros; i++) {
        casilleros[i] = true;
    }

    for (int estudiante = 2; estudiante <= numCasilleros; estudiante++) {
        for (int casillero = estudiante - 1; casillero < numCasilleros; casillero += estudiante) {
            casilleros[casillero] = !casilleros[casillero];
        }
    }

    int contadorAbiertos = 0;
    cout << "Casilleros abiertos: ";
    for (int i = 0; i < numCasilleros; i++) {
        if (casilleros[i]) {
            cout << (i + 1) << " ";
            contadorAbiertos++;
        }
    }
    cout << endl;
    cout << "Cantidad de casilleros abiertos: " << contadorAbiertos << endl;

    delete[] casilleros;

    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

bool detectarAritmetica(int arr[], int n, int &d) {
    int d1 = arr[1] - arr[0];
    int d2 = arr[2] - arr[1];
    int d3 = arr[3] - arr[2];

    if (d1 == d2 || d1 == d3) d = d1;
    else d = d2;

    int errores = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] != d) errores++;
    }
    return errores <= 2;
}

bool detectarGeometrica(int arr[], int n, double &r) {
    if (arr[0] == 0 || arr[1] == 0) return false;
    double r1 = (double)arr[1] / arr[0];
    double r2 = (double)arr[2] / arr[1];
    double r3 = (double)arr[3] / arr[2];

    if (fabs(r1 - r2) < 0.1 || fabs(r1 - r3) < 0.1) r = r1;
    else r = r2;

|
    int errores = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] == 0) return false;
        double actual = (double)arr[i] / arr[i - 1];
        if (fabs(actual - r) > 0.1) errores++;
    }
    return errores <= 2;
}

int main() {
    int n;
    cout << "Ingrese la cantidad de numeros: ";
    cin >> n;

    int arr[100];
    cout << "Ingrese la secuencia:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int d = 0;
    double r = 0;
    bool esArit = detectarAritmetica(arr, n, d);
    bool esGeom = false;

    if (!esArit) esGeom = detectarGeometrica(arr, n, r);

    if (esArit) {
        cout << "\nPatron detectado: Progresion Aritmetica\n";
        int errores[2], pos[2], cont = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] != d) {
                errores[cont] = arr[i];
                pos[cont] = i + 1;
                cont++;
            }
        }

        if (cont == 0) {
            cout << "No se encontraron errores.\n";
        } else {
            cout << "Numeros incorrectos: ";
            for (int i = 0; i < cont; i++)
                cout << errores[i] << " en la posicion " << pos[i] 
                     << (i < cont - 1 ? ", " : "\n");

            cout << "Numeros corregidos: ";
            for (int i = 0; i < cont; i++) {
                int correcto = arr[0] + d * (pos[i] - 1);
                cout << correcto << (i < cont - 1 ? ", " : "\n");
                arr[pos[i] - 1] = correcto;
            }

            cout << "Secuencia corregida: ";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
        }
    } 
    else if (esGeom) {
        cout << "\nPatron detectado: Progresion Geometrica\n";
        int errores[2], pos[2], cont = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i - 1] == 0) continue;
            double actual = (double)arr[i] / arr[i - 1];
            if (fabs(actual - r) > 0.1) {
                errores[cont] = arr[i];
                pos[cont] = i + 1;
                cont++;
            }
        }

        if (cont == 0) {
            cout << "No se encontraron errores.\n";
        } else {
            cout << "Numeros incorrectos: ";
            for (int i = 0; i < cont; i++)
                cout << errores[i] << " en la posicion " << pos[i] 
                     << (i < cont - 1 ? ", " : "\n");

            cout << "Numeros corregidos: ";
            for (int i = 0; i < cont; i++) {
                int correcto = round(arr[0] * pow(r, pos[i] - 1));
                cout << correcto << (i < cont - 1 ? ", " : "\n");
                arr[pos[i] - 1] = correcto;
            }

            cout << "Secuencia corregida: ";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
        }
    } 
    else {
        cout << "\nNo se detecto ningun patron valido (ni aritmetico ni geometrico).\n";
    }

    return 0;
}

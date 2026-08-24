#include <iostream>
#include <string>
using namespace std;

void mostrarTabla(string nombres[], int edades[], float notas[], int N) {
    cout << "\n--- Información de estudiantes ---\n";
    cout << "Nombre\tEdad\tNota\n";
    for (int i = 0; i < N; i++) {
        cout << nombres[i] << "\t" << edades[i] << "\t" << notas[i] << endl;
    }
}

float calcularPromedio(float notas[], int N) {
    float suma = 0;
    for (int i = 0; i < N; i++) {
        suma += notas[i];
    }
    return suma / N;
}

int indiceNotaMayor(float notas[], int N) {
    int indice = 0;
    for (int i = 1; i < N; i++) {
        if (notas[i] > notas[indice]) {
            indice = i;
        }
    }
    return indice;
}

int indiceEdadMenor(int edades[], int N) {
    int indice = 0;
    for (int i = 1; i < N; i++) {
        if (edades[i] < edades[indice]) {
            indice = i;
        }
    }
    return indice;
}

int contarAprobados(float notas[], int N) {
    int contador = 0;
    for (int i = 0; i < N; i++) {
        if (notas[i] >= 3.0) {
            contador++;
        }
    }
    return contador;
}

int contarMayores(int edades[], int N) {
    int contador = 0;
    for (int i = 0; i < N; i++) {
        if (edades[i] >= 18) {
            contador++;
        }
    }
    return contador;
}

int main() {
    int N;
    cout << "Ingrese el número de estudiantes: ";
    cin >> N;

    string nombres[N];
    int edades[N];
    float notas[N];

    cout << "\n--- Registro de estudiantes ---\n";
    for (int i = 0; i < N; i++) {
        cout << "\nEstudiante " << i + 1 << endl;
        cout << "Nombre: ";
        cin >> nombres[i];
        cout << "Edad: ";
        cin >> edades[i];
        cout << "Nota: ";
        cin >> notas[i];
    }

    mostrarTabla(nombres, edades, notas, N);

    cout << "\n--- Resultados ---\n";
    float promedio = calcularPromedio(notas, N);
    cout << "Promedio de notas: " << promedio << endl;

    int mejor = indiceNotaMayor(notas, N);
    cout << "Estudiante con mayor nota: " << nombres[mejor] << " (" << notas[mejor] << ")\n";

    int menorEdad = indiceEdadMenor(edades, N);
    cout << "Estudiante con menor edad: " << nombres[menorEdad] << " (" << edades[menorEdad] << " años)\n";

    cout << "Cantidad de aprobados: " << contarAprobados(notas, N) << endl;
    cout << "Cantidad de mayores de edad: " << contarMayores(edades, N) << endl;

    return 0;
}

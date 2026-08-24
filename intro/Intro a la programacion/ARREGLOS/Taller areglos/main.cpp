#include <iostream>

using namespace std;

int Diferentes(float arr[], int tam);
float masrepite(float arr[], int tam);
void inicializarSillas(int sillas[], int tam);
void imprimirEstado(int sillas[], int tam);
int reserva(int sillas[], int tam, bool fumador);

int main() {
    int opcion;
    const int tam = 20;
    int sillas[tam];
    inicializarSillas(sillas, tam);

    do {
        cout << "Seleccione una opción:\n";
        cout << "1. Contar elementos diferentes en un arreglo\n";
        cout << "2. Encontrar el elemento que más se repite en un arreglo\n";
        cout << "3. Reservar pasajes en un avion\n";
        cout << "4. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                float arr1[] = {7.5, 4.5, 3.5, 4.5, 8.3, 7.5, 3.5, 7.5};
                int tam1 = sizeof(arr1) / sizeof(arr1[0]);
                cout << "Elementos diferentes: " << Diferentes(arr1, tam1) << endl;
                break;
            }
            case 2: {
                float arr2[] = {7.5, 4.5, 3.5, 4.5, 8.3, 7.5, 3.5, 7.5, 7.5, 7.5, 7.5, 7.5};
                int tam2 = sizeof(arr2) / sizeof(arr2[0]);
                cout << "Elemento que más se repite: " << masrepite(arr2, tam2) << endl;
                break;
            }
            case 3: {
                bool fumador;
                char respuesta;
                do {
                    cout << "¿Es para fumadores? (s/n): ";
                    cin >> respuesta;
                    fumador = (respuesta == 's' || respuesta == 'S');
                    int resultado = reserva(sillas, tam, fumador);
                    if (resultado == 1) {
                        cout << "Reserva realizada en la zona de " << (fumador ? "fumadores" : "no fumadores") << endl;
                    } else if (resultado == 2) {
                        cout << "No hay espacio en la zona de " << (fumador ? "fumadores" : "no fumadores") << endl;
                        cout << "¿Desea reservar en la otra zona? (s/n): ";
                        cin >> respuesta;
                        if (respuesta == 's' || respuesta == 'S') {
                            reserva(sillas, tam, !fumador);
                        }
                    }
                    imprimirEstado(sillas, tam);
                    cout << "¿Desea realizar otra reserva? (s/n): ";
                    cin >> respuesta;
                } while (respuesta == 's' || respuesta == 'S');
                break;
            }
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}

int Diferentes(float arr[], int tam) {
    int count = 0;
    bool encontrado;

    for (int i = 0; i < tam; i++) {
        encontrado = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            count++;
        }
    }
    return count;
}

float masrepite(float arr[], int tam) {
    float maxElemento = arr[0];
    int maxCount = 0;

    for (int i = 0; i < tam; i++) {
        int count = 0;
        for (int j = 0; j < tam; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxElemento = arr[i];
        }
    }
    return maxElemento;
}

void inicializarSillas(int sillas[], int tam) {
    for (int i = 0; i < tam; i++) {
        sillas[i] = 0;
    }
}

void imprimirEstado(int sillas[], int tam) {
    cout << "Estado de las sillas: ";
    for (int i = 0; i < tam; i++) {
        cout << sillas[i] << " ";
    }
    cout << endl;
}

int reserva(int sillas[], int tam, bool fumador) {
    int inicio = fumador ? 10 : 0;
    int fin = fumador ? tam : 10;

    for (int i = inicio; i < fin; i++) {
        if (sillas[i] == 0) {
            sillas[i] = 1;
            return 1;
        }
    }

    inicio = fumador ? 0 : 10;
    fin = fumador ? 10 : tam;

    for (int i = inicio; i < fin; i++) {
        if (sillas[i] == 0) {
            return 2;
        }
    }
    return 0;
}
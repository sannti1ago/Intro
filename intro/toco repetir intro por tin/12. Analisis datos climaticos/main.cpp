#include <iostream>
using namespace std;

int main() {
    int zonas, dias;
    do {
        cout << "Ingrese el numero de zonas (max. 10): ";
        cin >> zonas;
    } while (zonas < 1 || zonas > 10);
    do {
        cout << "Ingrese el numero de dias (max. 10): ";
        cin >> dias;
    } while (dias < 1 || dias > 10);

    float semana1[10][10], semana2[10][10];
    for (int i = 0; i < zonas; i++) {
        for (int j = 0; j < dias; j++) {
            cout << "Semana 1 - Zona " << i + 1 << ", Dia " << j + 1 << ": ";
            cin >> semana1[i][j];
        }
    }
    for (int i = 0; i < zonas; i++) {
        for (int j = 0; j < dias; j++) {
            cout << "Semana 2 - Zona " << i + 1 << ", Dia " << j + 1 << ": ";
            cin >> semana2[i][j];
        }
    }

    int opcion;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Imprimir registros de una semana\n";
        cout << "2. Comparar las dos semanas\n";
        cout << "3. Promedios por zona y por dia\n";
        cout << "4. Deteccion de extremos\n";
        cout << "5. Analisis por diagonales\n";
        cout << "6. Generar transpuesta\n";
        cout << "7. Buscar temperatura\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int s;
                cout << "Ingrese la semana (1 o 2): ";
                cin >> s;
                if (s == 1 || s == 2) {
                    for (int i = 0; i < zonas; i++) {
                        for (int j = 0; j < dias; j++) {
                            cout << (s == 1 ? semana1[i][j] : semana2[i][j]) << " ";
                        }
                        cout << endl;
                    }
                } else cout << "Semana invalida\n";
                break;
            }
            case 2: {
                cout << "\n--- Comparacion de semanas ---\n";
                for (int i = 0; i < zonas; i++) {
                    for (int j = 0; j < dias; j++) {
                        cout << semana1[i][j] + semana2[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case 3: {
                cout << "\nPromedios por zona:\n";
                for (int i = 0; i < zonas; i++) {
                    float suma = 0;
                    for (int j = 0; j < dias; j++) suma += semana1[i][j];
                    cout << "Zona " << i + 1 << ": " << suma / dias << endl;
                }
                cout << "\nPromedios por dia:\n";
                for (int j = 0; j < dias; j++) {
                    float suma = 0;
                    for (int i = 0; i < zonas; i++) suma += semana1[i][j];
                    cout << "Dia " << j + 1 << ": " << suma / zonas << endl;
                }
                break;
            }
            case 4: {
                float maxTemp = semana1[0][0], minTemp = semana1[0][0];
                int zMax = 1, dMax = 1, sMax = 1, zMin = 1, dMin = 1, sMin = 1;
                for (int s = 1; s <= 2; s++) {
                    for (int i = 0; i < zonas; i++) {
                        for (int j = 0; j < dias; j++) {
                            float val = (s == 1 ? semana1[i][j] : semana2[i][j]);
                            if (val > maxTemp) {
                                maxTemp = val; zMax = i + 1; dMax = j + 1; sMax = s;
                            }
                            if (val < minTemp) {
                                minTemp = val; zMin = i + 1; dMin = j + 1; sMin = s;
                            }
                        }
                    }
                }
                cout << "Temperatura maxima: " << maxTemp << " (Zona " << zMax << ", Dia " << dMax << ", Semana " << sMax << ")\n";
                cout << "Temperatura minima: " << minTemp << " (Zona " << zMin << ", Dia " << dMin << ", Semana " << sMin << ")\n";
                break;
            }
            case 5: {
                if (zonas != dias) cout << "La matriz no es cuadrada.\n";
                else {
                    cout << "Diagonal principal: ";
                    for (int i = 0; i < zonas; i++) cout << semana1[i][i] << " ";
                    cout << "\nDiagonal secundaria: ";
                    for (int i = 0; i < zonas; i++) cout << semana1[i][dias - i - 1] << " ";
                    cout << endl;
                    bool constante = false;
                    for (int i = 0; i < zonas; i++) {
                        bool igual = true;
                        for (int j = 1; j < dias; j++) {
                            if (semana1[i][j] != semana1[i][0]) igual = false;
                        }
                        if (igual) {
                            cout << "Zona " << i + 1 << " mantiene temperatura constante.\n";
                            constante = true;
                        }
                    }
                    if (!constante) cout << "Ninguna zona mantiene temperatura constante.\n";
                }
                break;
            }
            case 6: {
                int s;
                cout << "Ingrese la semana (1 o 2): ";
                cin >> s;
                if (s == 1 || s == 2) {
                    cout << "Transpuesta de la semana " << s << ":\n";
                    for (int j = 0; j < dias; j++) {
                        for (int i = 0; i < zonas; i++) {
                            cout << (s == 1 ? semana1[i][j] : semana2[i][j]) << " ";
                        }
                        cout << endl;
                    }
                } else cout << "Semana invalida.\n";
                break;
            }
            case 7: {
                float buscar;
                cout << "Ingrese la temperatura a buscar: ";
                cin >> buscar;
                bool encontrado = false;
                for (int s = 1; s <= 2; s++) {
                    for (int i = 0; i < zonas; i++) {
                        for (int j = 0; j < dias; j++) {
                            float val = (s == 1 ? semana1[i][j] : semana2[i][j]);
                            if (val == buscar) {
                                cout << "Encontrada en Zona " << i + 1 << ", Dia " << j + 1 << ", Semana " << s << endl;
                                encontrado = true;
                            }
                        }
                    }
                }
                if (!encontrado) cout << "Temperatura no encontrada.\n";
                break;
            }
            case 8:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 8);

    return 0;
}
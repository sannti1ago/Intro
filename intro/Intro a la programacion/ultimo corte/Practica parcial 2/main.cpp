#include <iostream>
#include <string>

using namespace std;

const int numeroequipos = 4;
const int numeropartidos = 6;

void capturarequipos(string equipos[]) {
    cout << "Ingrese los nombres de los equipos: " << endl;
    for(int i = 0; i < numeroequipos; i++) {
        cout << "Equipo " << (i + 1) << ": ";
        cin >> equipos[i];
    }
}

void capturarpartidos(int partidos[], string equipos[]) {
    cout << "Ingrese los resultados de los partidos (formato: equipo1 equipo2 goles1 goles2): " << endl;
    for (int i = 0; i < numeropartidos; i++) {
        int equ1, equ2, goles1, goles2;
        cout << "Partido " << (i + 1) << ": ";
        cin >> equ1 >> equ2 >> goles1 >> goles2;

        if(goles1 > goles2) {
            partidos[equ1] += 3;
        } else if(goles1 < goles2) {
            partidos[equ2] += 3;
        } else {
            partidos[equ1] += 1;
            partidos[equ2] += 1;
        }
    }
}

void presentarclasificacion(string equipos[], int puntos[]) {
    cout << "\nClasificación: " << endl;
    for(int i = 0; i < numeroequipos; i++) {
        cout << equipos[i] << ": " << puntos[i] << " puntos" << endl;
    }
}

int main() {
    string equipos[numeroequipos];
    int puntos[numeroequipos] = {0};

    capturarequipos(equipos);
    capturarpartidos(puntos, equipos);
    presentarclasificacion(equipos, puntos);

    return 0;
}
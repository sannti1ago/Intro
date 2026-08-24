#include <iostream>
using namespace std;

const int MAX_MOTORES = 50;
const int MAX_INSUMOS = 20;

int necesario[MAX_INSUMOS];

// a. Costo de produccion de cada motor
void costoProduccion(int datos[MAX_MOTORES][MAX_INSUMOS], float costos[MAX_INSUMOS], float costoProd[MAX_MOTORES], int m, int n) {
    for (int f = 0; f < m; f++) {
        costoProd[f] = 0;
        for (int c = 0; c < n; c++) {
            costoProd[f] += datos[f][c] * costos[c];
        }
    }
}

// b. Insumos totales necesarios para cumplir pedidos del mes
void insumosNecesarios(int datos[MAX_MOTORES][MAX_INSUMOS], int pedidos[MAX_MOTORES], int n, int m) {
    for (int c = 0; c < n; c++) {
        necesario[c] = 0;
        for (int f = 0; f < m; f++) {
            necesario[c] += datos[f][c] * pedidos[f];
        }
    }
}

// c. Costo total por insumo para cumplir pedidos del mes
void costoTotalInsumos(float costos[MAX_INSUMOS], float costoTotal[MAX_INSUMOS], int n) {
    for (int c = 0; c < n; c++) {
        costoTotal[c] = necesario[c] * costos[c];
    }
}

// d. Insumos que faltan para cumplir la produccion mensual
void insumosQueFaltan(int existencia[MAX_INSUMOS], int n) {
    bool hayFaltantes = false;
    for (int c = 0; c < n; c++) {
        int diferencia = necesario[c] - existencia[c];
        if (diferencia > 0) {
            cout << "Insumo " << c << ": faltan " << diferencia << " unidades" << endl;
            hayFaltantes = true;
        }
    }
    if (!hayFaltantes) {
        cout << "Todos los insumos son suficientes." << endl;
    }
}

int main() {
    int m, n;
    cout << "Cantidad de motores: "; cin >> m;
    cout << "Cantidad de insumos: "; cin >> n;

    int datos[MAX_MOTORES][MAX_INSUMOS] = {
        {10,20,30,40,0,60,10,80},
        {0,70,0,50,40,30,0,10},
        {5,10,15,0,10,15,5,0},
        {10,20,10,20,10,0,10,20},
        {4,0,8,0,6,8,4,0},
        {0,6,9,12,15,0,1,24},
        {20,18,0,14,0,10,8,6}
    };
    float costos[MAX_INSUMOS]   = {3.5, 0.1, 2, 1.5, 6, 4.2, 2.5, 1.3};
    int   pedidos[MAX_MOTORES]  = {100, 25, 75, 150, 80, 90, 10};
    int   existencia[MAX_INSUMOS] = {120, 0, 20, 60, 40, 90, 10, 0};

    float costoProd[MAX_MOTORES];
    float costoTotal[MAX_INSUMOS];

    // a
    costoProduccion(datos, costos, costoProd, m, n);
    cout << "\n--- Costo de produccion por motor ---" << endl;
    for (int f = 0; f < m; f++)
        cout << "Motor " << f << ": $" << costoProd[f] << endl;

    // b
    insumosNecesarios(datos, pedidos, n, m);
    cout << "\n--- Insumos necesarios para el mes ---" << endl;
    for (int c = 0; c < n; c++)
        cout << "Insumo " << c << ": " << necesario[c] << " unidades" << endl;

    // c
    costoTotalInsumos(costos, costoTotal, n);
    cout << "\n--- Costo total por insumo ---" << endl;
    for (int c = 0; c < n; c++)
        cout << "Insumo " << c << ": $" << costoTotal[c] << endl;

    // d
    cout << "\n--- Insumos que faltan ---" << endl;
    insumosQueFaltan(existencia, n);

    return 0;
}
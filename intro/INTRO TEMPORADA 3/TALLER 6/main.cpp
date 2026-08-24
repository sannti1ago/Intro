#include <iostream>
using namespace std;

// (25%) Separa paquetes livianos y pesados, retorna cantidad de livianos
int separarPaquetes(int paquetes[], int n, int livianos[], int pesados[], int &cantPesados) {
    int cantLivianos = 0;
    cantPesados = 0;
    for (int i = 0; i < n; i++) {
        if (paquetes[i] < 0)
            livianos[cantLivianos++] = paquetes[i];
        else
            pesados[cantPesados++] = paquetes[i];
    }
    return cantLivianos;
}

// (20%) Ordena paquetes pesados de menor a mayor (burbuja)
void ordenarPesados(int pesados[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (pesados[j] > pesados[j + 1]) {
                int temp = pesados[j];
                pesados[j] = pesados[j + 1];
                pesados[j + 1] = temp;
            }
}

// (20%) Ordena paquetes livianos de mayor a menor en valor relativo
// Ej: -10 > -18 > -25  =>  el menos negativo primero
void ordenarLivianos(int livianos[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (livianos[j] < livianos[j + 1]) {  // mayor valor relativo = menos negativo
                int temp = livianos[j];
                livianos[j] = livianos[j + 1];
                livianos[j + 1] = temp;
            }
}

// (25%) Reordena el arreglo original alternando: pesado, liviano, pesado, liviano...
void reordenarPaquetes(int paquetes[], int n) {
    int livianos[50], pesados[50];
    int cantPesados = 0;
    int cantLivianos = separarPaquetes(paquetes, n, livianos, pesados, cantPesados);

    ordenarPesados(pesados, cantPesados);
    ordenarLivianos(livianos, cantLivianos);

    // Intercalar: pesado, liviano, pesado, liviano...
    int ip = 0, il = 0, k = 0;
    while (ip < cantPesados || il < cantLivianos) {
        if (ip < cantPesados)
            paquetes[k++] = pesados[ip++];
        if (il < cantLivianos)
            paquetes[k++] = livianos[il++];
    }
}

// (10%) Calcula e imprime el mayor paquete liviano y el mayor paquete pesado
void calcularMayores(int livianos[], int cantLivianos, int pesados[], int cantPesados) {
    // Mayor liviano = el menos negativo (valor más alto entre negativos)
    int mayorLiviano = livianos[0];
    for (int i = 1; i < cantLivianos; i++)
        if (livianos[i] > mayorLiviano)
            mayorLiviano = livianos[i];

    // Mayor pesado = el más grande entre positivos
    int mayorPesado = pesados[0];
    for (int i = 1; i < cantPesados; i++)
        if (pesados[i] > mayorPesado)
            mayorPesado = pesados[i];

    cout << "Mayor paquete liviano: " << mayorLiviano << endl;
    cout << "Mayor paquete pesado: "  << mayorPesado  << endl;
}

int main() {
    int n;
    cout << "Ingrese la cantidad de paquetes: ";
    cin >> n;

    int paquetes[100];
    cout << "Ingrese los paquetes (negativos=livianos, positivos=pesados):" << endl;
    for (int i = 0; i < n; i++)
        cin >> paquetes[i];

    // Separar para calcular mayores ANTES de reordenar el arreglo original
    int livianos[50], pesados[50];
    int cantPesados = 0;
    int cantLivianos = separarPaquetes(paquetes, n, livianos, pesados, cantPesados);

    // Reordenar el arreglo
    reordenarPaquetes(paquetes, n);

    // Imprimir resultado
    cout << "\nPaquetes reordenados:" << endl;
    for (int i = 0; i < n; i++)
        cout << paquetes[i] << " ";
    cout << endl;

    // Mayores
    calcularMayores(livianos, cantLivianos, pesados, cantPesados);

    return 0;
}
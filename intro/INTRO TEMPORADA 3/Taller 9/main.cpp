#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_PALABRAS = 500;

struct Palabra {
    string espanol;
    string ingles;
};

Palabra diccionario[MAX_PALABRAS];
int totalPalabras = 0;

int cargarDiccionario() {
    ifstream archivo("palabras.txt");
    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir palabras.txt" << endl;
        return 0;
    }
    int total = 0;
    while (archivo >> diccionario[total].espanol >> diccionario[total].ingles) {
        total++;
    }
    archivo.close();
    return total;
}

string traducirPalabra(string palabra) {
    for (int i = 0; i < totalPalabras; i++) {
        if (diccionario[i].espanol == palabra) {
            return diccionario[i].ingles;
        }
    }
    return "";
}

void traducirArchivo() {
    ifstream entrada("entrada.txt");
    ofstream salida("salida.txt");

    if (!entrada.is_open()) {
        cout << "Error: no se pudo abrir entrada.txt" << endl;
        return;
    }
    if (!salida.is_open()) {
        cout << "Error: no se pudo crear salida.txt" << endl;
        return;
    }

    string palabra;
    bool primeraEnLinea = true;

    while (entrada >> palabra) {
        string traduccion = traducirPalabra(palabra);

        if (!primeraEnLinea) salida << " ";
        primeraEnLinea = false;

        if (traduccion != "") {
            salida << traduccion;
        } else {
            salida << "(" << palabra << ")";
        }

        char sig = entrada.peek();
        if (sig == '\n' || entrada.eof()) {
            salida << "\n";
            primeraEnLinea = true;
        }
    }

    entrada.close();
    salida.close();
}

int main() {
    totalPalabras = cargarDiccionario();

    traducirArchivo();

    ifstream salida("salida.txt");
    string linea;
    while (getline(salida, linea)) {
        cout << linea << endl;
    }
    salida.close();

    return 0;
}
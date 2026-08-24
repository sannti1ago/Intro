#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int numeroObjetivo, numeroUsuario, intentos, conteoMayores, conteoMenores, conteoPares, conteoImpares, conteoPositivos, conteoNegativos;
    char jugarDeNuevo;

    do {
        srand(static_cast<unsigned int>(time(0)));
        numeroObjetivo = rand() % 100 + 1;

        conteoMayores = conteoMenores = conteoPares = conteoImpares = conteoPositivos = conteoNegativos = 0;

        do {
            cout << "Ingrese la cantidad de intentos (debe ser positiva): ";
            cin >> intentos;
        } while (intentos <= 0);

        bool adivinadoCorrectamente = false;

        for (int i = 0; i < intentos; i++) {
            cout << "Intento " << (i + 1) << ": Ingrese su numero: ";
            cin >> numeroUsuario;

            if (numeroUsuario > numeroObjetivo) {
                cout << "El numero es menor." << endl;
                conteoMayores++;
            } else if (numeroUsuario < numeroObjetivo) {
                cout << "El numero es mayor." << endl;
                conteoMenores++;
            } else {
                cout << "¡Felicidades! Adivinaste el numero." << endl;
                adivinadoCorrectamente = true;
                break;
            }

            if (numeroUsuario > 0) conteoPositivos++;
            if (numeroUsuario < 0) conteoNegativos++;
            if (numeroUsuario % 2 == 0) conteoPares++;
            else conteoImpares++;
        }

        cout << "\nResumen de intentos:" << endl;
        cout << "Intentos mayores al numero objetivo: " << conteoMayores << endl;
        cout << "Intentos menores al numero objetivo: " << conteoMenores << endl;
        cout << "Intentos pares: " << conteoPares << endl;
        cout << "Intentos impares: " << conteoImpares << endl;
        cout << "Intentos positivos: " << conteoPositivos << endl;
        cout << "Intentos negativos: " << conteoNegativos << endl;

        if (adivinadoCorrectamente) {
            cout << "¡Adivinaste el numero!" << endl;
        } else {
            cout << "Se acabaron los intentos. El numero era: " << numeroObjetivo << endl;
        }

        cout << "¿Desea jugar de nuevo? (s/n): ";
        cin >> jugarDeNuevo;

    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

    return 0;
}

#include <iostream>
using namespace std;

void printHourglass(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
    }
}

void printDiamond(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        for (int j = i - 1; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        for (int j = i - 1; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
    }
}

int main() {
    int choice;
    bool hourglassSolved = false;
    bool diamondSolved = false;

    do {
        cout << "Bienvenido! ¿Qué enigma deseas resolver?" << endl;
        cout << "1. Reloj de arena" << endl;
        cout << "2. Diamante numérico" << endl;
        cout << "3. Salir" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                if (!hourglassSolved) {
                    int n;
                    cout << "Ingrese un número impar: ";
                    cin >> n;
                    if (n % 2 == 1) {
                        printHourglass(n);
                        hourglassSolved = true;
                    } else {
                        cout << "Por favor, ingrese un número impar." << endl;
                    }
                } else {
                    cout << "El enigma 'Reloj de arena' ya fue resuelto." << endl;
                }
                break;
            case 2:
                if (!diamondSolved) {
                    int n;
                    cout << "Ingrese un número impar: ";
                    cin >> n;
                    if (n % 2 == 1) {
                        printDiamond(n);
                        diamondSolved = true;
                    } else {
                        cout << "Por favor, ingrese un número impar." << endl;
                    }
                } else {
                    cout << "El enigma 'Diamante numérico' ya fue resuelto." << endl;
                }
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (choice != 3);

    return 0;
}

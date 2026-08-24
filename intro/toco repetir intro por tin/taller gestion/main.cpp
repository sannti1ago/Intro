#include <iostream>

using namespace std;

int factorial(int num) {
    int result = 1;
    for(int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n, r;

    cout << "IMPORTANTE: r debe ser menor o igual que n (r <= n)." << endl;

    cout << "Ingrese el primer numero entero positivo (n): ";
    cin >> n;
    cout << "Ingrese el segundo numero entero positivo (r): ";
    cin >> r;

    if(n < 0 || r < 0) {
        cout << "El factorial no esta definido para numeros negativos." << endl;
    } else if (r > n) {
        cout << "No se puede calcular la combinatoria si r > n." << endl;
    } else {
        int fact_n = factorial(n);
        int fact_r = factorial(r);
        int fact_n_r = factorial(n - r);

        int combinatoria = fact_n / (fact_r * fact_n_r);

        cout << "El factorial de " << n << " es: " << fact_n << endl;
        cout << "El factorial de " << r << " es: " << fact_r << endl;
        cout << "La combinatoria C(" << n << ", " << r << ") es: " << combinatoria << endl;
    }

    return 0;
}

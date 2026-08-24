#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int N = 100;

void llenarArreglo(int arr[], int minVal, int maxVal){
    for(int i=0; i<N; i++)
        arr[i] = rand() % (maxVal - minVal + 1) + minVal;
}

int hogarMenorGastoTotal(int luz[], int agua[], int gas[]){
    int indiceMenor = 0;
    int totalMenor = luz[0] + agua[0] + gas[0];
    for(int i=1; i<N; i++){
        int total = luz[i] + agua[i] + gas[i];
        if(total < totalMenor){
            totalMenor = total;
            indiceMenor = i;
        }
    }
    return indiceMenor;
}

void calcularPromedios(int luz[], int agua[], int gas[], double promedios[]){
    double sumaLuz=0, sumaAgua=0, sumaGas=0;
    for(int i=0; i<N; i++){
        sumaLuz  += luz[i];
        sumaAgua += agua[i];
        sumaGas  += gas[i];
    }
    promedios[0] = sumaLuz  / N;
    promedios[1] = sumaAgua / N;
    promedios[2] = sumaGas  / N;
}

int calcularSubsidio(int servicio[], double promedio, int subsidio[]){
    int cantidad = 0;
    for(int i=0; i<N; i++){
        if(servicio[i] < promedio){
            subsidio[cantidad] = i;
            cantidad++;
        }
    }
    return cantidad;
}

int main(){
    srand(time(NULL));

    int luz[N], agua[N], gas[N];
    llenarArreglo(luz,  20000, 200000);
    llenarArreglo(agua, 10000, 300000);
    llenarArreglo(gas,  15000, 150000);

    int idx = hogarMenorGastoTotal(luz, agua, gas);
    cout << "1. Hogar con menor gasto total: " << idx+1 << endl;
    cout << "   Luz:   $" << luz[idx]  << endl;
    cout << "   Agua:  $" << agua[idx] << endl;
    cout << "   Gas:   $" << gas[idx]  << endl;
    cout << "   Total: $" << luz[idx]+agua[idx]+gas[idx] << endl << endl;

    double promedios[3];
    calcularPromedios(luz, agua, gas, promedios);
    cout << "2. Promedios de consumo:" << endl;
    cout << "   Luz:  $" << promedios[0] << endl;
    cout << "   Agua: $" << promedios[1] << endl;
    cout << "   Gas:  $" << promedios[2] << endl << endl;

    int subsidioLuz[N], subsidioAgua[N], subsidioGas[N];
    int cantLuz  = calcularSubsidio(luz,  promedios[0], subsidioLuz);
    int cantAgua = calcularSubsidio(agua, promedios[1], subsidioAgua);
    int cantGas  = calcularSubsidio(gas,  promedios[2], subsidioGas);

    cout << "3. Subsidio por ahorro:" << endl;
    cout << "   Luz:  " << cantLuz  << " hogares" << endl;
    cout << "   Agua: " << cantAgua << " hogares" << endl;
    cout << "   Gas:  " << cantGas  << " hogares" << endl;

    return 0;
}
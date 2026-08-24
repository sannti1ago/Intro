#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    
    cout<< "ingrese numero: ";
    cin>>a;
    
    cout<< "ingrese numero: ";
    cin>>b;

    cout<< "ingrese numero: ";
    cin>>c;
    
    int suma=a+b+c;
    float promedio = suma / 3;
    cout<<"el promedio es de: "<<promedio;
    
    return 0;
}
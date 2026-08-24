#include <iostream>
using namespace std;

int main()
{
    float r;
    
    const float pi=3.14;
    
    cout<<"ingrese el radio: ";
    cin>>r;
    
    float area = pi*r*r;
    cout<<"el area del circulo es de: "<<area;
    
    return 0;
}
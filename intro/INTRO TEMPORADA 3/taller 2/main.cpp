#include <iostream>
using namespace std;

int main(){
    int cantidad;
    string c1,c2,c3;
    
    cout<<"Cuantos colores desea usar en su combinacion entre amarillo, azul y rojo (2-3)? ";
    cin>>cantidad;
    
    if(cantidad==2){
        cout<<"primer color: ";
        cin>>c1;
        cout<<"segundo color: ";
        cin>>c2;
        
        if((c1=="rojo" && c2=="azul")||(c1=="azul" && c2=="rojo")){
            cout<<"Resultado: "<<"morado";
        }
        else if((c1=="rojo" && c2=="amarillo")||(c1=="amarillo" && c2=="rojo")){
            cout<<"Resultado: "<<"naranja";
        }
        else if((c1=="amarillo" && c2=="azul")||(c1=="azul" && c2=="amarillo")){
            cout<<"Resultado: "<<"verde";
        }
    }
    
    else if(cantidad==3){
        cout<<"primer color: ";
        cin>>c1;
        cout<<"segundo color: ";
        cin>>c2;
        cout<<"tercer color: ";
        cin>>c3;
        
        if((c1=="rojo" || c2=="rojo" || c3=="rojo") &&
           (c1=="azul" || c2=="azul" || c3=="azul") &&
           (c1=="amarillo" || c2=="amarillo" || c3=="amarillo")){
            
            cout<<"Resultado: "<<"marron";
        }

    }
    
    return 0;
}

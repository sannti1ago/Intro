#include <iostream>
using namespace std;

void llenarmatriz(int mat[5][3],int fil, int col){
    int valores [5][3]={
        {45,16,22},
        {52,12,19},
        {93,-9,-79},
        {48,47,-39},
        {72,36,89}
    };
    
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            mat[i][j]=valores[i][j];
        }
    }
}

void recorridoFilas(int mat[5][3],int fil,int col){// Imprime la matriz mat recorriéndola por filas.
    cout<<"recorrido por filas:\n";
    for(int j=0;j<col;j++){
        for(int i=0;i<fil;i++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void recorridoColumnas(int mat[5][3],int fil,int col){ // Imprime la matriz mat recorriéndola por columnas.
    cout<<"recorrido por columnas:\n";
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void recorridoFilasInverso(int mat[5][3],int fil,int col){ // Imprime la matriz mat recorriéndola por filas al revés
    cout<<"recorrido por filas inverso:\n";
    for(int i=fil-1;i>=0;i--){
        for(int j=col-1;j>=0;j--){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void recorridoColumnasInverso(int mat[5][3],int fil,int col){ // Imprime la matriz mat recorriéndola por columnas al revés.
    cout<<"recorrido por filas inverso:\n";
    for(int j=col-1;j>=0;j--){
        for(int i=fil-1;i>=0;i--){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    const int fil=5;
    const int col=3;
    int mat[fil][col];
    
    llenarmatriz(mat,fil,col);
    
    recorridoFilas(mat,fil,col);
    recorridoColumnas(mat,fil,col);
    recorridoFilasInverso(mat,fil,col);
    recorridoColumnasInverso(mat,fil,col);
    
    return 0;
}
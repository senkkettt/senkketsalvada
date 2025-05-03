#include <iostream>
using namespace std;

int main(){
    int TAM;          
    float *datcal;   

    cout << "Bienvenido, por favor, ingrese la cantidad de estudiantes: " << endl;
    cin >> TAM;       

    datcal = new float[TAM];

    for (int i = 0; i < TAM; i++){
        cout << "Calificacion del estudiante " << i + 1 << ": ";
        cin >> datcal[i];
    }

    float min = datcal[0];  
    float max = datcal[0];   
    for (int i = 1; i < TAM; i++){
        if(datcal[i] < min)
            min = datcal[i];
        if(datcal[i] > max)
            max = datcal[i];
    }

    cout << "La calificacion minima es: " << min << ", y la calificacion maxima es: " << max << endl;

    delete[] datcal;

    return 0;
}
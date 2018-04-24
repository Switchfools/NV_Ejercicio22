//
//  Second.cpp
//  
//
//  Created by Nicolas Felipe Vergara Duran on 24/04/18.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
using namespace std;
double* linspace(double in, double end, int size){
    double* vector = new double[size];
    double h=(end-in)/size;
    double point=in;
    for(int i=0;i<size;i++){
        vector[i]=point;
        point+=h;
    }
    return vector;
}
double StepIn(double x){
    if(x>=0.75 && x<=1.25){
        return(1);
    }
    else{
        return(0);
    }
}
void EcuacionDiff(){
    double delta_t=0.00001;
    double D=1;
    double T=0.5;
    double delta_x=0.01;
    double max_x=2;
    double min_x=0;
    double mu=1;
    double sigma=0.1;
    double k=D*(delta_t/pow(delta_x,2));
    int size_x=(max_x-min_x)/delta_x;
    int size_t=T/delta_t;
    double* x=linspace(min_x,max_x,size_x);
    double* t=linspace(0,T,size_t);
    double* Solucion_old = new double[size_x];
    double* Solucion_new = new double[size_x];
    //se crea la condición inicial
    
    for(int i=0; i<size_x;i++){
        Solucion_old[i]=exp(-pow(x[i]-mu,2)/(2*pow(sigma,2)));
    }
    int i=0;
    while(Solucion_old[size_x/2]>0.5){
        for(int j=0; j<size_x;j++){
            if(j!=0 && j!=size_x-1){
                Solucion_new[j]=Solucion_old[j]+(k*(Solucion_old[j+1]-2*Solucion_old[j]+Solucion_old[j-1]));
            }
            cout<<t[i]<<" "<<x[j]<<" "<<Solucion_new[j]<<endl;
        }
        for(int j=0; j<size_x;j++){
            Solucion_old[j]=Solucion_new[j];
        }
        i++;
    }
    
}
int main(){
    EcuacionDiff();
    return 0;
}

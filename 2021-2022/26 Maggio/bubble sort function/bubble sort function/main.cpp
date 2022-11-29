//- spostare il riempimento del vettore e il bubble sort ognuno in una funzione

#include <iostream>
#include <cstdlib>

using namespace std;


#define n 20


void ordinare(int ordinare[]){
    int scambio, i=0, j=0;
    for(i=0; i<n; i++){
        for (j=0; j<n-1; j++) {
            if(ordinare[j]>ordinare[j+1]){
                scambio = ordinare[j];
                ordinare[j] = ordinare[j+1];
                ordinare[j+1] = scambio;
            }
        }
    }
}

void generatore(int ordinare[]){
    int i;
    srand(time(NULL));
    for(i=0; i<n; i++){
        ordinare[i]=rand() % 101;
    }
}



int main(int argc, const char * argv[]) {
    
    
    int input[n];
    generatore(input);
    
    for(int i=0; i<n; i++){
        cout<<input[i]<<" ";
    }

    ordinare(input);
    
    
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<input[i]<<" ";
    }
    
    
    
    cout<<endl;
    return 0;
}

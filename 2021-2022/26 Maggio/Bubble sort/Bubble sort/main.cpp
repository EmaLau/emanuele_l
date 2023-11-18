// implementare il bubble sort in C++, per vettore di20 elementi riempito con valori casuali, in main()

#include <iostream>
#include <cstdlib>

using namespace std;


#define n 20


int main(int argc, const char * argv[]) {
    
    
    int ordinare[n], scambio;
    
    srand(time(NULL));

    for(int i=0; i<n; i++){
        ordinare[i]=rand() % 101;
    }
    
    for(int i=0; i<n; i++){
        cout<<ordinare[i]<<" ";
    }
    
    
    for(int i=0; i<n; i++){
        for (int j=0; j<n-1; j++) {
            if(ordinare[j]>ordinare[j+1]){
                scambio = ordinare[j];
                ordinare[j] = ordinare[j+1];
                ordinare[j+1] = scambio;
            }
        }
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<ordinare[i]<<" ";
    }
    
    return 0;
}

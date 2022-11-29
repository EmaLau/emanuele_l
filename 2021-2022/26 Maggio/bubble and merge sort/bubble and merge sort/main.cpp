//- implementare il merge-sort di due vettori non ordinati (i due vettori debbono essere ordinati tramite bubble sort, poi si applica il merge sort classico)
#include <iostream>
#include <cstdlib>
#include <list>

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

void generatore(int ordinare[], int ordinare2[]){
    int i=0;
    srand(time(NULL));
    for(i=0; i<n; i++){
        ordinare[i]=rand() % 101;
        ordinare2[i]=rand() % 101;
    }
}


int main(int argc, const char * argv[]) {
    
    
    int input[n], input2[n];
    
    
    generatore(input, input2);
    
    for(int i=0; i<n; i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<input2[i]<<" ";
    }
    cout<<endl;
    ordinare(input);
    ordinare(input2);
    
    
    list<int> list;
    list.assign(begin(input), end(input));
    
    std::list<int> list2;
    
    list2.assign(begin(input2), end(input2));
    
    
    list2.merge(list);
    cout<<endl;
    
    cout<<endl;
    for(auto it = list2.begin(); it != list2.end(); it++ ){
        cout << *it << " ";
    }
    
    
    
    cout<<endl;
    return 0;
}

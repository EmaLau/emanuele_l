/*Il software deve:
Punto 1 del libro
- dare la scelta di quanti bits trasmettere (da 8 a 32)
- generare una sequenza random di bits da trasmettere
- stampare i dati originali e il polinomio M(x)

Punto 2
- dare la scelta di quale polinomio divisore G(X) utilizzare (stampando i
polinomi riportati dal libro) Punto 3
- generare e stampare il polinomio D(x)Punto 4
- calcolare e stampare il resto della divisione in modulo 2 fra G(X) e D(x)

- definire e stampare il codeword da trasmettere

- generare casualmente due posizioni di bits nei dati da trasmettere, per ognuna
delle due posizioni decidere casualmente, con probabilita' fra 0.1 e 0.3 (valore
esatto scelto da voi) se introdurre un errore invertendo il bit in quella
posizione
- stampare se sono stati introdotti errori e in quale posizione

- scrivere funzione prende in input la codeword/k e stampa se rileva errori o
meno, immediatamente al di sotto della stampa degli errori eventualmente
introdotti del punto precedente
*/




#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

//Emanuele

string divide(int n, int g, string temp, string gen) {
    
    
    //string temp(""); // metti qui il risultato

    for (int i = 0; i < n; i++)
    {
        if (gen[0] == temp[i])
        {
      
            for (int j = 0, k = i; j < g + 1; j++, k++)
            {
                /*if (temp[k] ^ gen[j] == 1) {
                    temp[k] = 1;
                }
                else {
                    temp[k] = 0;
                }*/
                if (temp[k] == gen[j]) {
                    temp[k] = '1';
                }
                else if (temp[k] != gen[j]) {
                    temp[k] = '0';
                }
            }
        }
    }
    return temp;
}

// Amir & Emanuele
string genera_sequenza_bits_da_trasmettere(int nr_bits) {
    string bits(""); // costruttore della classe string
    int random_bit_value = 0;
    srand(time(NULL));
    for (int i = 0; i < nr_bits; i++) {
        random_bit_value = rand() % 2;
        bits.append(std::to_string(random_bit_value));
    }

    return bits;
}

int main(int argc, char** argv) {
    // Ema & Amir
    int nr_bits_da_trasmettere, i;
    /*cout << "Inserire bit da 8 a 32: ";
    cin >> nr_bits_da_trasmettere;*/
    nr_bits_da_trasmettere = 8; // TODO  sistemare
    if (nr_bits_da_trasmettere > 7 && nr_bits_da_trasmettere < 33) {
        cout << "numero bits da trasmettere: " << nr_bits_da_trasmettere << endl;
    }
    else {
        cout << "numero bit da trasmettere fuori range (8-32): " << nr_bits_da_trasmettere << endl;
        system("pause");
    }
    // Amir & Emanuele
    string Mx("");

    // Emanuele
    Mx = genera_sequenza_bits_da_trasmettere(nr_bits_da_trasmettere);
    cout << "Bits da trasmettere (generati casualmente):" << endl;
    for (int i = 0; i < nr_bits_da_trasmettere; i++) { cout << Mx[i]; }
    cout << "" << endl;

    int bits_zero_da_aggiungere_in_coda = 0;
    switch (nr_bits_da_trasmettere) {
        /*case 9:
            bits_zero_da_aggiungere_in_coda = 0;
            cout << "G(x)=x";
            for (i = nr_bits_da_trasmettere; i < nr_bits_da_trasmettere + bits_zero_da_aggiungere_in_coda; i++) {
                Mx[i] = 0;
            }*/

    case 8:
        bits_zero_da_aggiungere_in_coda = 3;
        cout << "G(x)=x^3+x+1" << endl;
        
        for (i = nr_bits_da_trasmettere; i < nr_bits_da_trasmettere + bits_zero_da_aggiungere_in_coda; i++) {
            Mx += "0";
        }

        break;
    default:
        cerr << "caso non ancora implementato\n";
        break;
    };

    for (i = 0; i < nr_bits_da_trasmettere + bits_zero_da_aggiungere_in_coda; i++) {
        if (i == nr_bits_da_trasmettere) {
            cout << "-";
        }
        cout << Mx[i];
    }
    cout << " " << endl;
    string divisore = "1011";
    int lunghezza_divisore = divisore.length();
    cout << "" << endl;
    cout << divisore << endl;
    cout << "" << endl;
    /*string Gx("");
    cout << "Lunghezza Gx" << endl;
    cin >> divisore;
    //Gx
    for (i = 0; i < divisore; i++) {
        cin >> Gx[i];
    }
    cout << " " << endl;
    for (i = 0; i < divisore; i++)
        cout << Gx[i];
  */
    string sender;

    sender = divide(nr_bits_da_trasmettere, lunghezza_divisore, Mx, divisore);

    for (int i = 0; i < lunghezza_divisore; i++)
    {
        Mx[nr_bits_da_trasmettere + i] = sender[nr_bits_da_trasmettere + i];
        cout << sender[nr_bits_da_trasmettere + i] << ' ';
    }

    cout << endl;
    cout << "trasmessi" << endl;
    for (i = 0; i < nr_bits_da_trasmettere + lunghezza_divisore; i++) {
        cout << Mx[i] << ' ';
    }
    cout << endl;









    return 0;
}

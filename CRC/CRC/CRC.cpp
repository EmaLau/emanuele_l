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

    for (int i = 0; i < n; i++)
    {
        if (gen[0] == temp[i])
        {

            for (int j = 0, k = i; j < g + 1; j++, k++)
            {
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




/* void genera_generatore_Gx(int lgx, string& Divisore) {
    Divisore += "1";
    int random_bit_value = 0;
    srand(time(NULL));
    for (int i = 1; i < lgx; i++) {
        random_bit_value = rand() % 2;
        if (random_bit_value == 0)
            Divisore += "0";
        else
            Divisore += "1";
    }
    Divisore += "1";
}*/



// Amir & Emanuele
string genera_sequenza_bits_da_trasmettere(int nr_bits) {
    string bits(""); // costruttore della classe string
    int random_bit_value = 0;
    srand(time(NULL));
    for (int i = 0; i < nr_bits; i++) {
        random_bit_value = rand() % 2;
        bits.append(to_string(random_bit_value));
    }

    return bits;
}

int main(int argc, char** argv) {
    // Ema & Amir
    int nr_bits_da_trasmettere, i;
    string scelta;
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



   /* string Divisore;
    int lunghezza_divisore = 0;
    cout << "(a) Inserire G(x) a mano, (b) generare G(x)" << endl;
    cin >> scelta;
    if (scelta == "a") {
        cin >> Divisore;
        lunghezza_divisore = Divisore.length();
    }
    else if (scelta == "b") {
        cout << "Inserire lunghezza bit di G(x)" << endl;

        cin >> lunghezza_divisore;
        genera_generatore_Gx(lunghezza_divisore, Divisore);
    }
    cout << Divisore << endl;
    */


    
    string divisore;
    cout << "Inserisci Gx" << endl;
    cin >> divisore;
    int lunghezza_divisore = divisore.length();
    if (lunghezza_divisore < nr_bits_da_trasmettere - 2) {
        cout << "Gx Valido" << endl;
        cout << "Gx corrisponde a " << divisore << " e la sua lunghezza e' " << lunghezza_divisore << " Bits" << endl;
    }
    else {
        cout << "Error" << endl;
    }
    int bits_zero_da_aggiungere_in_coda = 0;
    bits_zero_da_aggiungere_in_coda = lunghezza_divisore + 1;
    for (i = nr_bits_da_trasmettere; i < nr_bits_da_trasmettere + bits_zero_da_aggiungere_in_coda; i++)
        Mx += "0";
    



    /*int bits_zero_da_aggiungere_in_coda = 0;
    switch (nr_bits_da_trasmettere) {

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
    cout << " " << endl;*/
    /*string divisore = "1011";
    int lunghezza_divisore = divisore.length();
    cout << "" << endl;
    cout << divisore << endl;
    cout << "" << endl;*/

    string sender;

    sender = divide(nr_bits_da_trasmettere, lunghezza_divisore, Mx, divisore);
    cout << "Bit inviati" << endl;
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


    string receiver;
    cout << "Bit Ricevuti" << endl;
    for (int i = 0; i < lunghezza_divisore + nr_bits_da_trasmettere; i++)
        cout << Mx[i] << ' ';
    cout << endl;
    cout << "Scegli quale bit cambiare tra 0-" <<lunghezza_divisore+nr_bits_da_trasmettere<< endl;
    int b;
    cin >> b;
    if (b >= 0 -1) {
         Mx[b] = - Mx[b];
     }
        receiver = divide(nr_bits_da_trasmettere, lunghezza_divisore, Mx, divisore);
        cout << "Errore" << endl;
        for (int i = 0; i < nr_bits_da_trasmettere + lunghezza_divisore; i++) {
            if (receiver[i] != 0) {
                cout << "Errore individuato" << endl;
                return 0;
            }
        }
        cout << "Errori non individuati" << endl;





    return 0;
}

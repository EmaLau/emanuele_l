/*
 Punto 1 del libro
 - dare la scelta di quanti bits trasmettere (da 8 a 32)
 - generare una sequenza random di bits da trasmettere
 - stampare i dati originali e il polinomio M(x)

 Punto 2
 - dare la scelta di quale polinomio divisore G(X) utilizzare (stampando i polinomi riportati dal libro)
 Punto 3
 - generare e stampare il polinomio D(x)Punto 4
 - calcolare e stampare il resto della divisione in modulo 2 fra G(X) e D(x)

 - definire e stampare il codeword da trasmettere

 - generare casualmente due posizioni di bits nei dati da trasmettere, per ognuna delle due posizioni decidere casualmente, con probabilita' fra 0.1 e 0.3 (valore esatto scelto da voi) se introdurre un errore invertendo il bit in quella posizione
 - stampare se sono stati introdotti errori e in quale posizione

 - scrivere funzione prende in input la codeword/k e stampa se rileva errori o meno, immediatamente al di sotto della stampa degli errori eventualmente introdotti del punto precedente
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include <string>

using namespace std;

string genera_sequenza_bits_da_trasmettere(int nr_bits)
{
    string bits(""); // classe string
    int random_bit_value = 0;
    srand(time(NULL));
    for (int i = 0; i < nr_bits; i++)
    {
        random_bit_value = rand() % 2;
        bits.append(to_string(random_bit_value));
    }

    return bits;
}

string divide(int nr_bits_Mx, int g, string Mx_and_zeros, string gen)
{
    string temp = Mx_and_zeros;
    for (int i = 0; i < nr_bits_Mx; i++)
    {
        if (gen[0] == temp[i])
        {
            for (int j = 0, k = i; j < g + 1; j++, k++)
            {
                if (temp[k] == gen[j])
                    temp[k] = '1';
                else if (temp[k] != gen[j])
                    temp[k] = '0';
            }
        }
    }

    //TODO migliorare il tutto, questa e' una patch che rimette a posto i bits di MX da trasmettere
    for (int i = 0; i < nr_bits_Mx; i++)
        temp[i] = Mx_and_zeros[i];
    return temp;
}

int main(int argc, const char *argv[])
{
    bool testing = true;
    // Ema & Amir
    int nr_bits_da_trasmettere;
    string scelta;
    nr_bits_da_trasmettere = 8;
    /*cout<<"Inserire bits da 8 a 32: "; //TODO
    cin>>nr_bits_da_trasmettere; */
    if (nr_bits_da_trasmettere > 7 && nr_bits_da_trasmettere < 33)
        cout << "numero bits da trasmettere: " << nr_bits_da_trasmettere << endl;
    else
    {
        cout << "Numero bits da trasmettere fuori range (8-32): " << nr_bits_da_trasmettere << endl;
        return 0;
    }
    // Amir & Emanuele
    string Mx("");

    // Emanuele

    if (!testing) {
        Mx = genera_sequenza_bits_da_trasmettere(nr_bits_da_trasmettere);
        cout << endl << "generazione random bit da trasmettere ...";
    } else {   //TODO rimuovere
        cout << endl << "per test FORZO MX, rimuovere"; 
        Mx = "11111111";
        nr_bits_da_trasmettere = Mx.length();
    }
    cout << "Bits da trasmettere:\n" << Mx;

    string divisore;
    if (testing) {
        divisore = "1101";
    } else {
        cout << "Inserisci Gx: ";
        cin >> divisore;
    }
    int lunghezza_divisore = divisore.length();
    
    if (lunghezza_divisore < nr_bits_da_trasmettere - 2) {
        cout << "Gx valido, corrisponde a " << divisore << " e la sua lunghezza e' " << lunghezza_divisore << " Bits" << endl;
    } else {
        cout << "Gx non valido, corrisponde a " << divisore << " e la sua lunghezza e' " << lunghezza_divisore << " Bits, dovrebbe essere massimo " << nr_bits_da_trasmettere - 2 << " Bits" << endl;
        return 0;
    }
    
    int bits_zero_da_aggiungere_in_coda = lunghezza_divisore + 1;
    string Mx_with_zeros = Mx + string(bits_zero_da_aggiungere_in_coda, '0'); // oggetto string anonimo, via costruttore di string

    // Invia
    string temp = divide(nr_bits_da_trasmettere, lunghezza_divisore, Mx_with_zeros, divisore);
    // proviamo a estrarre il CRC da sender
    string CRC = temp.substr(nr_bits_da_trasmettere-1,temp.length()-nr_bits_da_trasmettere);
    string bits_to_send = Mx+CRC;
    cout << endl << "bits to send: " << bits_to_send << " CRC: " << CRC;

    
    //Ricevuti
    
    
    
    return 0;
}

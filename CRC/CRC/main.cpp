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

string divide(int n, int g, string temp, string gen)
{
    for (int i = 0; i < n; i++)
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

    return temp;
}

int main(int argc, const char *argv[])
{
    // Ema & Amir
    int nr_bits_da_trasmettere;
    string scelta;
    nr_bits_da_trasmettere = 8;
    /*cout<<"Inserire bits da 8 a 32: ";
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
    Mx = genera_sequenza_bits_da_trasmettere(nr_bits_da_trasmettere);
    cout << "Bits da trasmettere (generati casualmente): ";
    for (int i = 0; i < nr_bits_da_trasmettere; i++)
        cout << Mx[i];
    cout << endl;

    string divisore;

    cout << "Inserisci Gx: ";
    cin >> divisore;

    int lunghezza_divisore = divisore.length();
    if (lunghezza_divisore < nr_bits_da_trasmettere - 2)
        cout << "Gx valido, corrisponde a " << divisore << " e la sua lunghezza e' " << lunghezza_divisore << " Bits" << endl;
    else
    {
        cout << "Gx non valido, corrisponde a " << divisore << " e la sua lunghezza e' " << lunghezza_divisore << " Bits, dovrebbe essere massimo " << nr_bits_da_trasmettere - 2 << " Bits" << endl;
        return 0;
    }
    int bits_zero_da_aggiungere_in_coda = lunghezza_divisore + 1;
    for (int i = nr_bits_da_trasmettere; i < nr_bits_da_trasmettere + bits_zero_da_aggiungere_in_coda; i++)
        Mx += "0";
    // Invia

    string sender;

    sender = divide(nr_bits_da_trasmettere, lunghezza_divisore, Mx, divisore);

    cout << "CRC" << endl;

    for (int i = 0; i < lunghezza_divisore; i++)
    {
        Mx[nr_bits_da_trasmettere + 1] = sender[nr_bits_da_trasmettere + 1];
        cout << sender[nr_bits_da_trasmettere + 1] << ' ';
    }
    cout << endl;

    cout << "Trasmessi" << endl;
    for (int i = 0; i < nr_bits_da_trasmettere + lunghezza_divisore; i++)
        cout << Mx[i] << ' ';
    cout << endl;

    return 0;
}

//@Author Emanuele Lauro


package com.mycompany.crc_java;

import java.util.*;

public class CRC_Java {

    public static void main(String[] args) {
        new Schermata_CRC();
        Scanner input = new Scanner(System.in);
        boolean testing = false;
        
        int nr_bits_da_trasmettere;
        String scelta;
        
        System.out.print("Inserire i bits da trasmettere (8-32) ");
        nr_bits_da_trasmettere = input.nextInt();
        if(nr_bits_da_trasmettere > 7 && nr_bits_da_trasmettere < 33){
            System.out.print("Numero bits da trasmettere "+ nr_bits_da_trasmettere);
        }else{
            System.out.print("Numero bits da trasmettere fuori range (8-32) "+ nr_bits_da_trasmettere);
            
        }
        
        
        
        
        
    }
}

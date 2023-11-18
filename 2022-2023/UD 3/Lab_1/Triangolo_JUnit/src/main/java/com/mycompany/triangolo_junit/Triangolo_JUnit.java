package com.mycompany.triangolo_junit;

import java.util.Scanner;

/**
 *
 * @author emalau
 */
public class Triangolo_JUnit {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Triangolo TR = new Triangolo();
        System.out.println("inserisci lato a");
        TR.setLato_a(in.nextDouble());
        System.out.println("inserisci base");
        TR.setLato_b(in.nextDouble());
        System.out.println("Inserisci lato c");
        TR.setLato_c(in.nextDouble());
        System.out.println(TR.get_triangolo());
        
    }
}

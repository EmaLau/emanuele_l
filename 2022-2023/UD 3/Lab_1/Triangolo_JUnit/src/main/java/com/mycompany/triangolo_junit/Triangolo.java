package com.mycompany.triangolo_junit;

import static java.lang.Math.*;

/**
 *
 * @author emalau
 */
public class Triangolo {

    double perimetro(double lato_a, double lato_b, double lato_c) {
        double perimetro = lato_a + lato_b + lato_c;
        return perimetro;
    }

    double area(double lato_a, double lato_b, double lato_c) {
        double base = lato_b / 2;
        double area = (base * sqrt((lato_a * lato_a) - (base * base)) / 2);
        return area;

    }


    private double lato_a;
    private double lato_b; //base
    private double lato_c;
    private double perimetro;
    private double area;

    public Triangolo(double lato_a, double lato_b, double lato_c) {
        this.lato_a = lato_a;
        this.lato_b = lato_b;
        this.lato_c = lato_c;
    }

    public void setLato_a(double lato_a) {
        this.lato_a = lato_a;
    }

    public void setLato_b(double lato_b) {
        this.lato_b = lato_b;
    }

    public void setLato_c(double lato_c) {
        this.lato_c = lato_c;
    }

    
    void triangolo() {
        if (lato_a == lato_b && lato_b == lato_c && lato_a == lato_c) { //Trianhgolo Equilatero
            this.area = area(lato_a, lato_b, lato_c);
            this.perimetro = perimetro(lato_a, lato_b, lato_c);
        } else if (lato_b != lato_a && lato_a == lato_c) { //Triangolo Isoscele
            this.area = area(lato_a, lato_b, lato_c);
            this.perimetro = perimetro(lato_a, lato_b, lato_c);
        } else if ((sqrt((lato_c * lato_c) - (lato_b * lato_b)) / 2) == lato_a) { //Triangolo Rettangolo
            this.area = area(lato_a, lato_b, lato_c);
            this.perimetro = perimetro(lato_a, lato_b, lato_c);
        } else { //triangolo scaleno
            this.area = area(lato_a, lato_b, lato_c);
            this.perimetro = perimetro(lato_a, lato_b, lato_c);
        }
    }
    
    public String get_triangolo() {
        return "Il triangolo che hai scelto ha l'area di " + this.area + "e il perimetro di "+ perimetro;
    }

}

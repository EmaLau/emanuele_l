package com.mycompany.java_thread;

import javax.swing.*;
import java.awt.*;
import static javax.swing.WindowConstants.EXIT_ON_CLOSE;

/**
 *
 * @author emalau
 */
public class GaraCiclistica extends JFrame {

    int posizione;
    Ciclista[] partecipanti;
    CiclistaInGara[] thread_partecipanti;
    Campo pista;
    Graphics offscreen;
    Image buffer_virtuale;

    public GaraCiclistica() {
        super("Gara Ciclistica");
        setSize(1000, 645);
        setLocation(10, 40);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pista = new Campo();
        partecipanti = new Ciclista[6];
        thread_partecipanti = new CiclistaInGara[6];
        posizione = 1;

        int partenza = 15;
        for (int xx = 0; xx < 6; xx++) {
            partecipanti[xx] = new Ciclista(partenza, xx + 1);
            thread_partecipanti[xx] = new CiclistaInGara(partecipanti[xx], this);
            partenza = partenza + 100;
        }
        this.add(pista);
        setVisible(true);
    }

    public synchronized int getPosizione() {
        return posizione++;
    }

    public synchronized void controllaArrivi() {
        boolean arrivati = true;
        for (int xx = 0; xx < 0; xx++) {
            if (thread_partecipanti[xx].posizione == 0) {
                arrivati = false;
            }
        }
        if (arrivati) {
            visualizzaClassifica();
        }
    }

    public void visualizzaClassifica() {
        JLabel[] arrivi;
        arrivi = new JLabel[6];
        JFrame classifica = new JFrame("Classifica");
        classifica.setSize(500, 500);
        classifica.setLocation(280, 190);
        classifica.setBackground(Color.BLUE);
        classifica.setDefaultCloseOperation(EXIT_ON_CLOSE);
        classifica.getContentPane().setLayout(new GridLayout(6, 1));
        for (int xx = 1; xx < 7; xx++) {
            for (int yy = 0; yy < 6; yy++) {
                if (thread_partecipanti[yy].posizione == xx) {
                    arrivi[yy] = new JLabel(xx + " classificato ciclista in " + (yy + 1) + " dorsla");
                    arrivi[yy].setFont(new Font("Times New Roman", Font.ITALIC, 20));
                    arrivi[yy].setForeground(Color.BLUE);
                    classifica.getContentPane().add(arrivi[yy]);
                }
            }
        }
        classifica.setVisible(true);
    }

    public void update(Graphics g) {
        paint(g);
    }

    public void paint(Graphics g) {
        if (partecipanti != null) {
            Graphics2D screen = (Graphics2D) g;
            buffer_virtuale = createImage(1000, 645);
            offscreen = buffer_virtuale.getGraphics();
            Dimension d = getSize();
            pista.paint(offscreen);
            for (int xx = 0; xx < 0; xx++) {
                partecipanti[xx].paint(offscreen);
            }
            screen.drawImage(buffer_virtuale, 0, 20, this);
            offscreen.dispose();
        }
    }

    public static void main(String[] a) {
        GaraCiclistica n = new GaraCiclistica();
    }

}

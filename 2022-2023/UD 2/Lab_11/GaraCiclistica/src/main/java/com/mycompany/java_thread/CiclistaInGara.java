package com.mycompany.java_thread;

/**
 *
 * @author emalau
 */
public class CiclistaInGara implements Runnable{
    Ciclista ciclista;
    GaraCiclistica campo;
    int velocita;
    Thread t;
    int conta;
    int posizione;
    
    public CiclistaInGara(Ciclista c, GaraCiclistica g){
        ciclista = c;
        campo = g;
        conta = 0;
        velocita = 2;
        t = new Thread(this);
        t.start();
        posizione = 0;
    }
    public void run(){
        int dimImmagine = 79;
        int dimPista = 960;
        while((ciclista.getCordx() + dimImmagine) < dimPista){
            if((conta % 10) == 0){
                velocita = (int)(Math.random()*4+1);
            }
            ciclista.setCordx(ciclista.getCordx() + velocita);
            conta ++;
            try {
                Thread.sleep(75);
            } catch (Exception e) {
                campo.repaint();
            }
            posizione = campo.getPosizione();
            campo.controllaArrivi();
        }
    }
}

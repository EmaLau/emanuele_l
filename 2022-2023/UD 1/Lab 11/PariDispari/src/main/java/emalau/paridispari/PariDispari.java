package emalau.PariDispari;

import java.util.concurrent.ThreadPoolExecutor;

/**
 *
 * @author emala
 */
public class PariDispari extends Thread {

    private int massimo;
    private boolean pari;
    private int ritardo = 500;

    public PariDispari(int finale, boolean pari) {
        massimo = finale;
        this.pari = pari;
    }

    public void run() {
        String chisono;
        chisono = Thread.currentThread().getName();
        for (int xx = 0; xx < massimo; xx++) {
            if (pari) {
                if (xx % 2 == 0) {
                    System.out.println(chisono + "-pari " + xx);
                }
            } else if (xx % 2 != 0) {
                System.out.println(chisono + "-dispari " + xx);
            }
            try {
                Thread.sleep(ritardo);
            }catch(InterruptedException e){
            System.out.println(e);
        }

        }
    }

    public static void main(String[] args) {
        if(args.length !=1){
            System.out.println("Dovresti passare il numero intero");
            return;
        }
        int n = Integer.parseInt(args[0]);
        Thread TP = new PariDispari(n+1, true);
        Thread TD = new PariDispari(n+1, true);
        System.out.println("-> Contate fino a "+n);
        TP.start();
        TD.start();
        try{
            TP.join();
            TD.join();
        }catch(Exception e){
            System.out.println("<-Fine conteggio!");
        }
        
    }
}

package emalau.provaconta;

/**
 *
 * @author emala
 */
public class Contatore extends Thread {

    private int massimo;
    private boolean pari;
    private Thread PID;
    private int ritardo = 500;

    public Contatore(int finale, boolean pari) {
        massimo = finale;
        this.pari = pari;
        PID = new Thread(this);
        PID.start();
    }
}

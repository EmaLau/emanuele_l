package emalau.provaconta;

/**
 *
 * @author emala
 */
public class ProvaConta {

    public static void main(String[] args) {
        int n = 10;
        System.out.println("->Contate fino a "+n);
        Thread TP = new Contatore(n, true);
        Thread TD = new Contatore(n, true);
    }
}

package emalau.priorita;

/**
 *
 * @author emala
 */
public class Priorita extends Thread{
    
    private String chisono;
    public Priorita(String nome){
        setChisei(nome);
    }
    public String getChisei(){
        return chisono;
    }
    
    public void setChisei(String nome){
        chisono = nome;
    }
    
    public void run(){
        int conta= 0;
        while(conta<5000000){
            conta++;
            if((conta%1000000)==0)
                System.out.println("Thread #"+chisono+", conta = "+conta);
        }
    }

    public static void main(String[] args) {
        Thread TA = new Priorita("IMPORTANTE (10)");
        Thread TB = new Priorita("poco importante");
        TA.setPriority(Thread.MAX_PRIORITY);
        TB.setPriority(Thread.MIN_PRIORITY);
        TA.start();
        TB.start();
    }
}

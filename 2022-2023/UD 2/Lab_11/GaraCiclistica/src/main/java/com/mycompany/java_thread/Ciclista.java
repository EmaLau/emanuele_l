package com.mycompany.java_thread;

import java.awt.*;
import javax.swing.*;

/**
 *
 * @author emalau
 */
public class Ciclista extends JPanel{

    int cordx;
    int cordy;
    Image img;

    public Ciclista(int yy, int xx) {
        cordx = 0;
        cordy = yy;
        setSize(80, 81);
        Toolkit tk = Toolkit.getDefaultToolkit();
        switch (xx) {
            case 1: {
                img = tk.getImage("bici1.JPG");
                break;
            }
            case 2: {
                img = tk.getImage("bici2.JPG");
                break;
            }
            case 3: {
                img = tk.getImage("bici3.JPG");
                break;
            }
            case 4: {
                img = tk.getImage("bici4.JPG");
                break;
            }
            case 5: {
                img = tk.getImage("bici5.JPG");
                break;
            }
            case 6: {
                img = tk.getImage("bici6.JPG");
                break;
            }
        }
        MediaTracker mt = new MediaTracker(this);
        mt.addImage(img, 1);
        try {
            mt.waitForID(1);
        } catch (InterruptedException e) {
        }
    }

    public void setCordx(int n) {
        cordx = n;
    }

    public int getCordx() {
        return cordx;
    }
    
    public void paint(Graphics g){
        g.drawImage(img, cordx, cordy, null);
    }

}

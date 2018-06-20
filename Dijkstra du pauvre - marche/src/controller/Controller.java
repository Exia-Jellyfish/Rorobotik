package controller;

import model.Arc;
import model.Vectlist;

public class Controller {
    private static Vectlist vectlist = new Vectlist();
    int rand;
    public String sequence;
    public char origin;
    public int l;
    public String orders;
    public Controller() {
        sequence = "";
        this.l = 0;
        this.orders = "";
    }

    public void search(char goal){
        sequence = (goal + sequence);
        int length = 1000;

        rand = (int)Math.random()%4;
        Arc ppArc = new Arc('n','a',1000,0);



        if (goal != origin) {
            for (int i = 0; i < 42; i++) {
                if ( vectlist.getArc(i).getTo() == goal && vectlist.getArc(i).getLength() < ppArc.getLength() && !(vectlist.getArc(i).isUsed())) {

                    ppArc = vectlist.getArc(i);
                    vectlist.getArc(i).setUsed(true);

                    if (i < 21) {
                        vectlist.getArc(i + 21).setUsed(true);
                    }
                    else{
                        vectlist.getArc(i - 21).setUsed(true);
                    }

                }

            }
            System.out.println(ppArc.getFrom()+" "+ppArc.getTo()+" "+ ppArc.getDir());
            ppArc.setUsed(true);
            this.orders = this.orders + ppArc.getDir();
            this.l = this.l + ppArc.getLength();
            this.search(ppArc.getFrom());

        }
        else{

        }

        }



    public void sequence(){
        System.out.println(this.sequence+"  length: "+this.l+"\n"+orders+'x');
    }

}

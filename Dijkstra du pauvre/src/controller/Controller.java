package controller;

import model.Arc;
import model.Vectlist;

public class Controller {
    private static Vectlist vectlist = new Vectlist();
    int rand;
    public String sequence;
    public char origin;
    public int l ;
    int bufferl;

    public Controller() {
        sequence = "";
        this.l = 0;
    }

    public void search(char goal){




        sequence = (goal + sequence);
        int length = 1000;


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
            if ( ppArc.getFrom() == 'n' ){
                this.sequence = "impossible";
            }else{
            ppArc.setUsed(true);
            System.out.println(ppArc.getFrom() +" "+ ppArc.getTo());
            this.l = this.l + ppArc.getLength();
            this.search(ppArc.getFrom());
            }


        }
        else{

        }

        }


    public void searchBig(char goal){

        sequence = (goal + sequence);
        int length = 1000;

        rand = (int)Math.random()%2;
        Arc ppArc = new Arc('n','a',0,0);



        if (goal != origin) {
            for (int i = 0; i < 42; i++) {
                if ( vectlist.getArc(i).getTo() == goal && vectlist.getArc(i).getLength() > ppArc.getLength() && !(vectlist.getArc(i).isUsed())) {

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
            if ( ppArc.getFrom() == 'n' ){
                this.sequence = "impossible";
            }else{
                ppArc.setUsed(true);
                System.out.println(ppArc.getFrom() +" "+ ppArc.getTo());
                this.l = this.l + ppArc.getLength();
                this.search(ppArc.getFrom());
            }


        }
        else{

        }

    }


    public void sequence(){
        System.out.println(this.sequence +" "+ this.l);
    }

}

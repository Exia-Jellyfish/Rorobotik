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
    public String nodes;
    char lastNode;
    int bestLength;
    String bestOrders;
    String bestNodes;
    Arc ppArc;
    boolean failed;


    public Controller() {
        sequence = "";
        this.l = 0;
        this.orders = "";
        this.nodes = "";
        this.bestLength = 10000;
        failed = false;

    }

    public void search(char goal){
        sequence = (goal + sequence);
        int length = 1000;

        rand = (int)Math.random()%4;
        ppArc = new Arc('n','a',1000,0,'d');



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
            if (ppArc.getFrom()!= 'n'){
                this.orders = this.orders + ppArc.getDir();
                this.nodes = this.nodes + ppArc.getNode();
                this.l = this.l + ppArc.getLength();
                this.lastNode=ppArc.getFrom();
                this.search(ppArc.getFrom());
            }
            else{this.search(this.lastNode);}

        }
        else{

        }

        }



    public void searchRand(char goal){
        sequence = (goal + sequence);
        int length = 1000;

        rand = (int)((Math.random())*10)%2;
       //System.out.println(rand);



        if (rand == 0){
            ppArc = new Arc('n','a',1000,0,'d');
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
            //System.out.println(ppArc.getFrom()+" "+ppArc.getTo()+" "+ ppArc.getDir());
            ppArc.setUsed(true);
            if (ppArc.getFrom()!= 'n'){
                this.orders = this.orders + ppArc.getDir();
                this.nodes = this.nodes + ppArc.getNode();
                this.l = this.l + ppArc.getLength();
                this.lastNode=ppArc.getFrom();
                this.searchRand(ppArc.getFrom());
            }else{this.failed = true;}


        }
        else{

        }}else{
             ppArc = new Arc('n','a',0,0,'d');
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
                //System.out.println(ppArc.getFrom()+" "+ppArc.getTo()+" "+ ppArc.getDir());
                ppArc.setUsed(true);
                if (ppArc.getFrom()!= 'n'){
                    this.orders = this.orders + ppArc.getDir();
                    this.nodes = this.nodes + ppArc.getNode();
                    this.l = this.l + ppArc.getLength();
                    this.lastNode=ppArc.getFrom();
                    this.searchRand(ppArc.getFrom());
                }else{this.failed = true;}


            }
            else{

            }
        }

    }

    public void setBest(){
        if (this.l < this.bestLength && !this.failed){
            this.bestLength = this.l;
            this.bestOrders = this.orders;
            this.bestNodes = this.nodes;
        }
        vectlist.reset();
        failed = false;

    }


    public void sequence(){
       System.out.println("this is the best route found:\n"+this.bestOrders+" \nLength: "+this.bestLength);
    }

}

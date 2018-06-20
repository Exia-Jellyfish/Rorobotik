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
    Arc[] poss;

    boolean failed;


    public Controller() {
        sequence = "";
        this.l = 0;
        this.orders = "";
        this.nodes = "";
        this.bestLength = 10000;
        failed = false;
        poss = new Arc[4];
    }

    public void search(char goal){

        Arc choice;





        if (goal != this.origin) {
            choice = new Arc('n','a',0,4, 'a');
            int n = 0;
            for (int i = 0; i < 42; i++) {
                if ( vectlist.getArc(i).getTo() == goal ) {

                    poss[n] = vectlist.getArc(i);

                    n++;



                    if (i < 21) {
                        vectlist.getArc(i + 21).setUsed(true);
                    }
                    else{
                        vectlist.getArc(i - 21).setUsed(true);
                    }

                }

            }

            switch (n){
                case 0:
                    System.out.println("Error, n = 0");
                    break;
                case 1:
                    choice = poss[0];
                    break;
                case 2:
                    choice = poss[(int)(Math.random()*10)%2];
                    break;
                case 3:
                    choice = poss[(int)(Math.random()*10)%3];
                    break;
                case 4:
                    choice = poss[(int)(Math.random()*10)%4];
                    break;
                default:
                    System.out.println("Error, default reached");
            }
            //System.out.println(choice.getFrom()+" "+choice.getTo()+" "+ choice.getDir());
            choice.setUsed(true);
            if (choice.getFrom()!= 'n'){
                this.orders = this.orders + choice.getDir();
                this.nodes = this.nodes + choice.getNode();
                this.l = this.l + choice.getLength();
                this.lastNode=choice.getFrom();
                this.search(choice.getFrom());
            }
            else{this.failed = true;}

        }
        else{

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

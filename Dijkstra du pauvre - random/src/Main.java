import controller.*;
import view.Console;


public class Main {
    public static void main(String args[]){
        Console console =  new Console();
        Controller controller = new Controller();
        char origin = console.chooseOr();
        char end = console.chooseEnd();
        controller.origin = origin;
        for (int i = 0 ; i< 5000;i++){
            controller.search(end);
            controller.setBest();
        }
        controller.sequence();
    }
}

/*FGBAFINO  length: 15
ennnwsex
abbabbb*/

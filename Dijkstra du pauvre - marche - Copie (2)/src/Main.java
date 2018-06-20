import controller.*;
import view.Console;


public class Main {
    public static void main(String args[]){
        Console console =  new Console();
        Controller controller = new Controller();
        char origin = console.chooseOr();
        char end = console.chooseEnd();
        controller.origin = origin;
        controller.search(end);
        controller.sequence();
    }
}

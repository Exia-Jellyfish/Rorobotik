import controller.*;



public class Main {
    public static void main(String args[]){

        char or = 'E';
        char dest = 'F';
        Controller controller = new Controller();
        controller.origin = or;
        controller.searchBig(dest);
        controller.sequence();
        /*controller.l = 0;
        controller.search(dest);
        controller.sequence();
        controller.l = 0;
        controller.search(dest);
        controller.sequence();*/
    }
}

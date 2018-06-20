package view;

import java.util.Scanner;

public class Console {

    public char chooseOr(){
        System.out.println("Where are you?");
        Scanner sc = new Scanner(System.in);
        String string = sc.next();
        return string.charAt(0);

    }

    public char chooseEnd(){
        System.out.println("Where do you want to go?");
        Scanner sc = new Scanner(System.in);
        String string = sc.next();
        return string.charAt(0);

    }
}

package model;

public class Arc {
    private char from;
    private char to;
    private int x;
    private int y;
    private int length;
    private boolean used;
    private char dir;

    public char getNode() {
        return node;
    }

    public void setNode(char node) {
        this.node = node;
    }

    private char node;

    public Arc() {
    }

    public boolean isUsed() {
        return used;
    }

    public void setUsed(boolean used) {
        this.used = used;
    }

    public char getDir() {
        return dir;
    }

    public void setDir(char dir) {
        this.dir = dir;
    }

    public Arc(char from, char to, int x, int y, char node) {

        this.from = from;
        this.to = to;
        this.x = x;
        this.y = y;
        this.length = Math.abs(x+y);
        this.used= false;
        this.node = node;

        if(x>0){
            this.dir = 'e';
        }
        else if(x < 0){
            this.dir = 'w';
        }
        else{

        }

        if(y>0){
            this.dir = 's';
        }
        else if(y < 0){
            this.dir = 'n';
        }
        else{

        }

    }

    public char getFrom() {

        return from;
    }

    public void setFrom(char from) {
        this.from = from;
    }

    public char getTo() {
        return to;
    }

    public void setTo(char to) {
        this.to = to;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getLength() {
        return length;
    }

    public void setLength(int length) {
        this.length = length;
    }
}

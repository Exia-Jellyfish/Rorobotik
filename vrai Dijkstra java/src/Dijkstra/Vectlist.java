package Dijkstra;

public class Vectlist {
    private Arc[] list;

    public Arc[] getList() {
        return list;
    }

    public Arc getArc(int i) {
        return list[i];
    }



    public void setList(Arc[] list) {
        this.list = list;
    }

    public Vectlist(){
        this.list = new Arc[42];

        Arc u = new Arc('A','B',2,0,'a');
        list[0] = u;

        Arc ui = new Arc('B','A',-2,0, 'b');
        list[21] = ui;

        Arc v =  new Arc('B','C',5,0,'b');
        list[1] = v;

        Arc vi =  new Arc('C','B',-5,0,'b');
        list[22] = vi;

        Arc w = new Arc('C','D',2,0,'b');
        list[2] = w;

        Arc wi = new Arc('D','C',-2,0,'b');
        list[23] = wi;

        Arc z = new Arc('D','E',2,0,'b');
        list[3] = z;

        Arc zi = new Arc('E','D',-2,0,'a');
        list[24] = zi;

        Arc a = new Arc('A','F',0,-2,'a');
        list[4] = a;

        Arc ai = new Arc('F','A',0,2,'b');
        list[25] = ai;

        Arc b = new Arc('B','G',0,-2,'b');
        list[5] = b;

        Arc bi = new Arc('G','B',0,2,'b');
        list[26] = bi;

        Arc c = new Arc('C', 'H', 0, -2, 'b');
        list[6] = c;

        Arc ci = new Arc('H', 'C', 0, 2 ,'a');
        list[27] = ci;

        Arc d = new Arc('D','J',0,-4,'b');
        list[7] = d;

        Arc di = new Arc('J','D',0,4,'b');
        list[28] = di;
        Arc e = new Arc('E','K',0,-4,'a');
        list[8]=e;

        Arc ei = new Arc('K','E',0,4,'b');
        list[29]=ei;

        Arc f = new Arc('F','G',2,0,'b');
        list[9]=f;

        Arc fi = new Arc('G','F',-2,0,'b');
        list[30]=fi;

        Arc g = new Arc('G','H',5,0,'b');
        list[10] = g;

        Arc gi = new Arc('H','G',-5,0,'a');
        list[31] = gi;

        Arc h =  new Arc('F','I',0,-2,'b');
        list[11] = h;

        Arc hi =  new Arc('I','F',0,2, 'b');
        list[32] = hi;

        Arc i = new Arc('I','J',9,0,'b');
        list[12] = i;

        Arc ii = new Arc('J','I',-9,0,'c');
        list[33] = ii;

        Arc j = new Arc('J','K',2,0,'c');
        list[13] = j;

        Arc ji = new Arc('K','J',-2,0,'b');
        list[34] = ji;

        Arc k = new Arc('I','N',0,-3,'b');
        list[14] = k;

        Arc ki = new Arc('N','I',0,3,'a');
        list[35] = ki;

        Arc l = new Arc('L','M',7,0,'a');
        list[15] = l;

        Arc li = new Arc('M','L',-7,0,'a');
        list[36] = li;

        Arc m = new Arc('J','M',0,-2,'c');
        list[16] = m;

        Arc mi = new Arc('M','J',0,2,'a');
        list[37] = mi;

        Arc n = new Arc('K','P',0,-1,'b');
        list[17] = n;

        Arc ni = new Arc('P','K',0,1,'a');
        list[38] = ni;

        Arc o = new Arc('L','O',0,-3,'a');
        list[18] = o;

        Arc oi = new Arc('O','L',0,3,'b');
        list[39] = oi;

        Arc p = new Arc('N','O',2,0,'a');
        list[19] = p;

        Arc pi = new Arc('O','N',-2,0,'b');
        list[40] = pi;
        Arc q = new Arc('O','P',8,0,'b');
        list[20] = q;

        Arc qi = new Arc('P','O',-8,0,'a');
        list[41] = qi;
    }



}

package Dijkstra;

import java.io.StringReader;
import java.util.ArrayList;

public class Dijkstra {

	// creation du graphe
	public static final int INFINITE = 1000;// Integer.MAX_VALUE;
	public final static int ALPHA_NOTDEF = -999;// on met final psk c'est une constante
	private int x0;
	private int[] S;// ensemble de sommets dont les distances les plus courtes à la source sont
					// connues au départ seulement Source
	private int[] R;// ensemble des prédécesseur des sommets de 0 à N-1;
	private Graphe g0;
	private int[] D;// tableau des valeurs du meilleur raccourci pour se rendre à chaque sommet
	// rajout
	private boolean[] noeudsMarques;
	private static int dimensionDeLaMatrice;// je rajoute ça pour simplifier le code.

	public Dijkstra(int x, Graphe g) {
		x0 = x;
		g0 = g;
		dimensionDeLaMatrice = g0.nbSommet();
		S = new int[dimensionDeLaMatrice];// sommets atteints
		D = new int[dimensionDeLaMatrice];// distances
		noeudsMarques = new boolean[dimensionDeLaMatrice];
		R = new int[dimensionDeLaMatrice];
		calculePlusCourtChemin();
	}

	void calculePlusCourtChemin() {
		int n = 0;
		for (int a = 0; a < dimensionDeLaMatrice; a++) {
			noeudsMarques[a] = false;
			S[a] = -1; // en supposant qu'on numérote les sommets de 0 ou de 1 à n.
			R[a] = -1; // pour les noeuds qui n'ont pas de prédecésseur
		}

		S[n] = x0;
		D[x0] = 0;
		R[x0] = x0;
		initDistMin();
		for (int i = 0; i < dimensionDeLaMatrice; i++) {
			if (!contains(S, i)) {// à revoir
				int t = choixSommet();
				noeudsMarques[t] = true;
				n++;
				S[n] = t;
				majDistMin(t);
			} // end if
		} // end for
			// for (int i=0; i<dimensionDeLaMatrice;i++){
			// System.out.print(" S[i]"+S[i]);
			// }
			// for (int i=0; i<dimensionDeLaMatrice;i++){
			// System.out.print(" R["+i+"]"+R[i]);
			// }
			// System.out.println();
	}

	// implémentation de initDistMin
	private void initDistMin() {
		noeudsMarques[x0] = true;
		for (int i = 0; i < dimensionDeLaMatrice; i++) {
			if (g0.existeArc(x0, i)) {
				D[i] = g0.getU()[x0][i];
				R[i] = x0;
			} else {
				if (x0 != i)
					D[i] = -g0.ALPHA_NOTDEF + 1;
			}
		}
	}

	private void majDistMin(int n) {
		for (int i = 0; i < dimensionDeLaMatrice; i++) {
			if (!contains(S, i)) {
				// D[i] = min(D[i], D[n] + distanceDsGraphe(n,i));
				if (D[n] + distanceDsGraphe(n, i) < D[i]) {
					D[i] = D[n] + distanceDsGraphe(n, i);
					R[i] = n;
				}
			}
		}
	}

	private int distanceDsGraphe(int t, int s) {
		if (g0.existeArc(t, s)) {
			return g0.getU()[t][s];
		} else {
			return INFINITE;
		}
	}

	public int choixSommet() {
		int valeurMin = INFINITE;
		int min = x0;
		for (int i = 0; i < dimensionDeLaMatrice; i++) {
			if (!noeudsMarques[i])
				if (D[i] <= valeurMin) {
					min = i;
					valeurMin = D[i];
				}
		}
		return min;
	}

	// fonction à définir :S.contains(i)
	private boolean contains(int[] S, int i) {
		return noeudsMarques[i];
	}

	public int longueurChemin(int i) {
		return D[i];
	}

	// fonction � d�finir min
	private int min(int i, int j) {
		if (i <= j)
			return i;
		else
			return j;
	}

	public String afficheChemin(int i) {
		int source = x0;
		int antecedant = i;
		String trajet = "";
		ArrayList<Integer> lesNoeudsIntermediaires = new ArrayList<Integer>();
		lesNoeudsIntermediaires.add(i);
		System.out.println("Chemin de " + translate(x0) + " a " + translate(i) + ":");
		while (antecedant != source) {
			System.out.println(translate(antecedant));
			System.out.println(translate(source));
			lesNoeudsIntermediaires.add(antecedant);
			antecedant = R[antecedant];

		}
		// lesNoeudsIntermediaires.add(i);
		lesNoeudsIntermediaires.add(source);
		for (int j = lesNoeudsIntermediaires.size() - 1; j > 0; j--) {

			trajet = trajet + translate(lesNoeudsIntermediaires.get(j));
		}
        System.out.print(trajet);
        return trajet;
	}

	public ArrayList<Character> getChemin(int i) {
		int source = x0;
		int antecedant = i;
		ArrayList<Character> lesNoeudsIntermediaires = new ArrayList<Character>();
		lesNoeudsIntermediaires.add(translate(i));
		while (antecedant != source) {
			lesNoeudsIntermediaires.add(translate(antecedant));
			antecedant = R[antecedant];

		}
		// lesNoeudsIntermediaires.add(i);
		lesNoeudsIntermediaires.add(translate(source));

		return lesNoeudsIntermediaires;

	}

	public char translate(int i){
		switch (i){
			case 0:
				return 'A';

			case 1:
				return 'B';

			case 2:
				return 'C';

			case 3:
				return 'D';

			case 4:
				return 'E';

			case 5:
				return 'F';

			case 6:
				return 'G';

			case 7:
				return 'H';

			case 8:
				return 'I';

			case 9:
				return 'J';

			case 10:
				return 'K';

			case 11:
				return 'L';

			case 12:
				return 'M';

			case 13:
				return 'N';

			case 14:
				return 'O';

			case 15:
				return 'P';

				default:
					return 'X';

		}



	}

	public int trad(char c){
        switch (c){
            case 'A':
                return 0;

            case 'B':
                return 1;

            case 'C':
                return 2;

            case 'D':
                return 3;

            case 'E':
                return 4;

            case 5:
                return 'F';

            case 'G':
                return 6;

            case 'H':
                return 7;

            case 'I':
                return 8;

            case 'J':
                return 9;

            case 'K':
                return 10;

            case 'L':
                return 11;

            case 'M':
                return 12;

            case 'N':
                return 13;

            case 'O':
                return 14;

            case 'P':
                return 15;

            default:
                return 255;

        }

    }

    public String ordres(String trajet, Vectlist list){
        char x;
        char y;
        String ordres = "";
        for(int i = 0; i < trajet.length()-1; i++){
           x = trajet.charAt(i);
           y = trajet.charAt(i+1);

            for (int n = 0; n < 42; n++) {
                if (list.getArc(n).getFrom() == x && (list.getArc(n).getTo() == y)){

                    ordres = ordres + list.getArc(n).getDir();
                }
            }
        }

    return ordres;
    }
}
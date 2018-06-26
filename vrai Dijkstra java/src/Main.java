import java.util.Scanner;

import Arduino.ArduinoConnector;
import Dijkstra.*;
import Dijkstra.Graphe;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter Samuel's current orientation  (n/s/e/w)");

		char o = scan.nextLine().charAt(0);

		System.out.println("Enter the origin");

		char origin = scan.nextLine().charAt(0);

		System.out.println("Enter the destination");

		char destination = scan.nextLine().charAt(0);
		Vectlist vectlist = new Vectlist();
		int N = Graphe.ALPHA_NOTDEF;
		int[][] matDuree = { { N, 1, N, N, N, 1, N, N, N, N, N, N, N, N, N, N },
				{ 1, N, 2, N, N, N, 1, N, N, N, N, N, N, N, N, N }, { N, 2, N, 1, N, N, N, 1, N, N, N, N, N, N, N, N },
				{ N, N, 1, N, 1, N, N, N, N, 2, N, N, N, N, N, N }, { N, N, N, 1, N, N, N, N, N, N, 2, N, N, N, N, N },
				{ 1, N, N, N, N, N, 1, N, 1, N, N, N, N, N, N, N }, { N, 1, N, N, N, 1, N, 2, N, N, N, N, N, N, N, N },
				{ N, N, 1, N, N, N, 2, N, N, N, N, N, N, N, N, N }, { N, N, N, N, N, 1, N, N, N, 4, N, N, N, 2, N, N },
				{ N, N, N, 2, N, N, N, N, 4, N, 1, N, 1, N, N, N }, { N, N, N, N, 2, N, N, N, N, 1, N, N, N, N, N, 2 },
				{ N, N, N, N, N, N, N, N, N, N, N, N, 3, N, 1, N }, { N, N, N, N, N, N, N, N, N, 1, N, 3, N, N, N, N },
				{ N, N, N, N, N, N, N, N, 2, N, N, N, N, N, 1, N }, { N, N, N, N, N, N, N, N, N, N, N, 1, N, 1, N, 4 },
				{ N, N, N, N, N, N, N, N, N, N, 2, N, N, N, 4, N } };

		// création du graphe
		Graphe g0 = new Graphe(matDuree);
		// LA SUITE
		ArduinoConnector arduinoConnector = new ArduinoConnector();
		// creation d'une instance de l'algorithme avec le graphe g0
		Dijkstra dijkstra = new Dijkstra(g0.trad(origin), g0);

		arduinoConnector.sendToArduino(o+dijkstra.ordres(dijkstra.afficheChemin(dijkstra.trad(destination)), vectlist)+'x');
        System.out.println(o+dijkstra.ordres(dijkstra.afficheChemin(dijkstra.trad(destination)), vectlist)+'x');

		// Pour afficher le chemin le plus rapide pour aller de beaulieu a Clemenceau
		// OrderSender sender = new OrderSender(dijkstra.getChemin(destination),
		// Direction.UP);

		// ArduinoConnector.sendToArduino(sender.getFinalOrder());
	}

}

package cs103.dz11;

import java.net.URL;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * 8. Za neusmereni graf koji je dat listom povezanosti u datoteci ulaz.txt 
 * proveriti da li je ciklican.
 */

/**
 *
 * @author milos
 */
public class Main {

    public static void main(String[] args) throws Exception {

        java.io.File file = new java.io.File("ulaz.txt");

        // Test if file exists
        if (!file.exists()) {
            System.out.println("Fajl\"" + file + "\" ne postoji.");
            System.exit(0);
        }

        // Crate a Scanner for the file
        Scanner input = new Scanner(file);
        int NUMBER_OF_VERTICES = input.nextInt();

        ArrayList<AbstractGraph.Edge> edgeList = new ArrayList<>();

        String[] vertices = new String[NUMBER_OF_VERTICES];

        // Read data from file
        input.nextLine();
        for (int j = 0; j < NUMBER_OF_VERTICES; j++) {
            String s = input.nextLine();
            String[] line = s.split("[\\s+]");
            String u = line[0];
            vertices[j] = u; // Add vertex

            // Add edges for vertex u
            for (int i = 1; i < line.length; i++) {
                edgeList.add(new AbstractGraph.Edge(Integer.parseInt(u),
                        Integer.parseInt(line[i])));
            }
        }
        // Crate a graph
        Graph<String> graph = new UnweightedGraph<>(
                edgeList, Arrays.asList(vertices));

        // Display the number of vertices
        System.out.println("Broj čvorova: " + graph.getSize());

        // Display edges
        for (int u = 0; u < NUMBER_OF_VERTICES; u++) {
            System.out.print("Čvor " + graph.getVertex(u) + ":");
            for (Integer e : graph.getNeighbors(u)) {
                System.out.print(" (" + u + ", " + e + ")");
            }
            System.out.println();
        }               
//        AbstractGraph.Tree tree = graph.dfs(0);
        
        System.out.println(graph.isCyclic()?"Cikličan je":"Nije cikličan");        
        

                
        
    }

}

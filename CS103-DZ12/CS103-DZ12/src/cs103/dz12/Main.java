/*
 * 14. Za graf sa slike pronaći najkraće puteve od čvora A do svih ostalih 
 * čvorova u grafu. Graf se učitava iz fajla u kome prva linija sadrži broj 
 * čvorova i broj grana u grafu, a svaka naredna linija sadrži uređene trojke
 * (u,v,w), gde u i v predstavlja granu između ta dva čvora, a w težine. 
 * Program treba da štampa svaki prolaz, do konačnog rešenja.
 * 
 */
package cs103.dz12;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

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
        System.out.println("NUMBER_OF_VERTICES " + NUMBER_OF_VERTICES);
        int NUMBER_OF_EDGES = input.nextInt();
        System.out.println("NUMBER_OF_EDGES " + NUMBER_OF_EDGES);

        List<WeightedEdge> edgeList = new ArrayList<>();
        
        List<String> vertices = new ArrayList<String>(
                Arrays.asList("A","B","C","D","E","F"));        
        
        input.nextLine();
        for (int j = 0; j < NUMBER_OF_EDGES; j++) {
            String s = input.nextLine();
            String[] line = s.split("[\\s+]");
            String u = line[0];
            String v = line[1];
            String w = line[2];

            // Add edges for vertex u            
            edgeList.add(new WeightedEdge(Integer.parseInt(u),
                        Integer.parseInt(v), Integer.parseInt(w)));
            }        
        
        // Create a graph
        WeightedGraph<String> graph = new WeightedGraph<String>(
                edgeList, vertices);        
        WeightedGraph<String>.ShortestPathTree tree = 
                graph.getShortestPath(graph.getIndex("A"));
        tree.printAllPaths();
    }
    
}

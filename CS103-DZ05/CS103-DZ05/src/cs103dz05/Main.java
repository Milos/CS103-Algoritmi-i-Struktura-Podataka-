/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cs103dz05;

import java.util.Arrays;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 *
 * @author milos
 * 
 * === Zadatak 9 === 
 * Kreirati 2 prioritetna reda:
 * {"George", "Jim", "John", "Blake", "Kevin", "Michael"}
 * {"George", "Katie", "Kevin", "Michelle", "Ryan"} 
 * pronaći uniju, razliku i presek. 
 * (Moguće je klonirati skup da bi sačuvali originalni skup od upotrebe ovih metoda). 

 */
public class Main {
    
    public static void main(String[] args) {
        PriorityQueue<String> pqA = new PriorityQueue<String>(Arrays.asList(
                "George", "Jim", "John", "Blake", "Kevin", "Michael"));
        PriorityQueue<String> pqB = new PriorityQueue<String>(Arrays.asList(
                "George", "Katie", "Kevin", "Michelle", "Ryan"));
        
        PriorityQueue<String> unija = new PriorityQueue<String>(pqA);
        PriorityQueue<String> tmp = new PriorityQueue<String>(pqB);

        // Unija        
        String e;
        while ((e = tmp.poll()) != null ) {            
            if (!unija.contains(e)) {
                unija.add(e);
            }            
        }        
        System.out.println("Unija: " + unija);
        
        // Razlika
        PriorityQueue<String> razlika = new PriorityQueue<String>(pqA);
        razlika.removeAll(pqB);
        System.out.println("Razlika: " + razlika);
        
        // Presek
        PriorityQueue<String> presek = new PriorityQueue<String>(pqA);
        presek.retainAll(pqB);
        System.out.println("Presek: " + presek);
    }
    
}

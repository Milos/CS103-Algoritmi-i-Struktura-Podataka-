/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cs103.dz13.pkg1;

import jdk.nashorn.internal.objects.NativeString;

/**
 *
 * @author milos
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static int brojPokusaja = 0;
    public static int brojPoredjenja = 0;

    public static void main(String[] args) {

        System.out.println("Resenje: "+ search("abcabd", "abcabbabbabcabd") + "");
        System.out.println("brojPokusaja " + brojPokusaja);
        System.out.println("brojPoredjenja " + brojPoredjenja);
    }

    public static int search(String pattern, String text) {
        int[] prefixTable = computeLspTable(pattern);
        for (int i = 0; i < prefixTable.length; i++) {
            System.out.println("[" + i + "]: " + prefixTable[i]);
        }
        
        int j = 0;  
        for (int i = 0; i < text.length(); i++) {
            
            while (j > 0 && text.charAt(i) != pattern.charAt(j)) {                
                brojPoredjenja++;
                
                System.out.print("j: " + j+" ");
                System.out.println("i: " + i+" ");
                System.out.println("numGuesses: " + brojPoredjenja+" ");
                
                j = prefixTable[j-1];
                System.out.println("jP   " + j);
                
            }
            if (text.charAt(i) == pattern.charAt(j)) {    
                brojPokusaja++;
                brojPoredjenja++;
                //inkrementiraj if matched
                j++;                
                if (j == pattern.length()) {
                   brojPoredjenja++; //za poslednji karakter
                    return i - (j - 1);
                }
            }
            
        }
        
        return -1;  // Not found

    }

    public static int[] computeLspTable(String pattern) {
        int[] lsp = new int[pattern.length()];
        lsp[0] = 0;  // Base case
        for (int i = 1; i < pattern.length(); i++) {
            // Start by assuming we're extending the previous LSP
            int j = lsp[i - 1];
            while (j > 0 && pattern.charAt(i) != pattern.charAt(j)) {
                j = lsp[j - 1];
            }
            if (pattern.charAt(i) == pattern.charAt(j)) {
                j++;
            }
            lsp[i] = j;
        }
        return lsp;
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * 20. Dato je binarno stablo celih brojeva. Napisati funkciju koja će 
 * izračunati zbir sadržaja listova.
 */
package cs103.dz09;

import java.util.Scanner;

/**
 *
 * @author milos
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Unesi broj listova: ");
        int numberOfNodes = scanner.nextInt();
                             
        System.out.println("Unesi sadržaj (int) root lista: ");
        int data = scanner.nextInt();
        Node node = new Node(data);       
                
        for(int i = 1; i < numberOfNodes; i++) {
            System.out.println("Unesi sadržaj (int) lista " + i + ":");
            int d = scanner.nextInt();
            node.insert(d);
        }
        System.out.println("Zbir sadržaja listova je " + node.sum(node));
    }
    
}
class Node {
    Node left, right;
    int data;
    public Node(int data) {
        this.data = data;
    }
    
    public void insert(int value) {
        
        if (value <= data) {
            if (left == null) {
                left = new Node(value);
            } else {
                left.insert(value);
            }
        } else {
            if (right == null) {
                right = new Node(value);
            } else {
                right.insert(value);
            }
        }
    }
    
    public void printInOrder() {
        if (left == null) {
            left.printInOrder();
        }
        System.out.println(data);
        if (right == null) {
            right.printInOrder();
        }
    }
    
    public int sum(Node node) {
        if (node == null) return 0;
        return node.data + sum(node.left) + sum(node.right);
    }
}
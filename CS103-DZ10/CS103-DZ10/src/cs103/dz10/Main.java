/*
1. Implementirati inorder metod u binarnom stablu pretrage (BST) korišćenjem 
steka umesto rekurzije.
*/

package cs103.dz10;

import java.util.Stack;

/**
 *
 * @author milos
 */

class Node {
    Node left, right;
    int data;
    public Node(int data) {
        this.data = data;
//        left = right = null;
    }
}

class BinaryTree { 
    Node root;
    
    void inorder() {
        if (root == null) {
            return;
        }        
        Stack<Node> stack = new Stack<Node>();
        Node node = root;
         
        while (node != null) {
            stack.push(node);
            node = node.left;            
        }         
        while (stack.size() > 0) {                   
            node = stack.pop();
            System.out.print(node.data + " ");
            if (node.right != null) {
                node = node.right;
                
                while (node != null) {
                    stack.push(node);
                    node = node.left;
                }
            }
        }
    }
    void inorder1() {
        Stack<Node> s = new Stack<Node>();
        Node current = root;
        boolean done = false;
        
        while(!done) {
            if (current != null) {
               s.push(current);
               current = current.left;
            } else {
                if (s.isEmpty()) done = true;
                else {
                    current = s.pop();
                    System.out.print(current.data + " ");
                    current = current.right;
                }
            }
        }
    }
}

public class Main {   
    public static void main(String[] args) {
        BinaryTree stablo = new BinaryTree();
        /*
                1
               / \
              2   3
             / \
            4   5
        */
        stablo.root = new Node(1);
        stablo.root.left = new Node(2);
        stablo.root.right = new Node(3);
        stablo.root.left.left = new Node(4);
        stablo.root.left.right = new Node(5);
        stablo.inorder1();
    }    
}

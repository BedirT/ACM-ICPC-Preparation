import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;



public class Bedir_Java {
    
    public static int GCD_division(int a, int b){ //  Great Common Divisor function with division.
        
        int t;
        while( b != 0 ){
            t = b;
            b = a % b;
            a = t;
        }
        return a;
        
    }
    
    public static int GCD_recursion(int a, int b){ //  Great Common Divisor function with recursion.
        
        if(b == 0){
            return a;
        }else{
            return GCD_recursion(b, a%b);
        }
        
    }
    
    public static int GCD_substitution(int a, int b){ //  Great Common Divisor function with substitution.
        
        while(a != b){
            if(a > b){
                a = a-b;
            }else{
                b = b-a;
            }
        }
        return a;
    }
    
    public static int LCM(int a, int b){  //  Least Common Multiplier function.
        
        return Math.abs(a*b)/GCD_recursion(a, b);
        
    }
    
    public static void main(String[] args) {
        
        System.out.println("GCD - a = 22, b = 44 -> " + GCD_substitution(22, 44));
        System.out.println("GCD - a = 7 , b = 31 -> " + GCD_division(7, 31));
        System.out.println("GCD - a = 18, b = 27 -> " + GCD_recursion(18, 27));
        System.out.println("LCM - a = 12, b = 21 -> " + LCM(12, 21));
        
    }
    
    
}



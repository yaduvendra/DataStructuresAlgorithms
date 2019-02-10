import java.util.*;
import java.lang.*;
import java.io.*;

class DutchFlag {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int q = 0,n = 0;
		
		q = sc.nextInt();
		while(q-- > 0){
		    int c1 = 0, c2 = 0, c3 = 0;
		    n = sc.nextInt();
		    int [] arr = new int[n];
		    for(int i = 0; i<n; i++){
		        arr[i] = sc.nextInt();
		        if(arr[i] == 0){c1++;}
		        else if(arr[i] == 1){c2++;}
		        else if(arr[i] == 2){c3++;}
		    }
		 for(;c1>0;c1--){
		   System.out.print("0 ");  
		 }
		 
		 for(;c2>0;c2--){
		   System.out.print("1 ");   
		 }
		 
		 for(;c3>0;c3--){
		   System.out.print("2 ");  
		 }
		
		    System.out.println();
		}
	}
}

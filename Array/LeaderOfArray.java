import java.util.*;
import java.lang.*;
import java.io.*;

class LeaderOfArray {
	public static void main (String[] args) {
		
		 long startTime = 0;

		
		Scanner sc = new Scanner(System.in);
		int t,n,i=0,j;
		t = sc.nextInt();
		while(t-- > 0){
		  
		  int max = 0;  
		  
		  n = sc.nextInt();
		  
		  startTime = System.nanoTime();
		  
		  int[] arr = new int[n];
		  
		  int[] brr = new int[n];
		  
		  for(i=0;i<n;i++){
		      arr[i] = sc.nextInt();
		  }
		  
		  //startTime = System.nanoTime();
		  
		  max = arr[n-1];
		  
		  for(i=n-2 , j=0 ; i>=0 && j<n; --i){
		      
		      if(arr[i] >= max){
		      brr[j] = max;
		      j++;
		      //System.out.print(max + " ");
		      max = arr[i];
		      }
		  }
		  System.out.print(max + " ");
		  for(i = j-1;  i >= 0 ; i--){
		      System.out.print(brr[i] + " ");
		  }System.out.println();
		  
		}
		
		long endTime   = System.nanoTime();
		double totalTime = endTime - startTime;
		System.out.println(totalTime/1000000000.0);
		System.out.println(totalTime/1000000000);//1000000000.0
	}
}

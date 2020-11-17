package arrays;

import java.util.Scanner;

public class Average {

	public static void main(String[] args) {
	
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the number of students:");
		int n = sc.nextInt();
		int marks[] = new int[n];
		for(int i=0; i<n; i++) {
			marks[i] = sc.nextInt();
		}
		int averageMarks = 0;
		for(int i=0; i<n; i++ ) {
			averageMarks += marks[i];
		}
		averageMarks /= n; 
		System.out.println("The average marks is " + averageMarks);
	}
	
}
 
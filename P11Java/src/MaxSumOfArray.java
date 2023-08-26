import java.util.Scanner;

public class MaxSumOfArray {
	
	static boolean allNegative = true;
	
	static int getMax(int []arr) {
		
		// loop to check that all the numbers are negative or not	
		for(int i = 0; i < arr.length; i++) {
			if(arr[i] > 0) {
				allNegative = false;
				break;
			}
		}
		if(allNegative)
			return 0;
		
		int first = arr[0];
		int second = 0;
		int temp;

		for (int i = 1; i < arr.length; i++)
		{

			if(first > second)
				temp = first;  // temp = 3
			else
				temp = second;

			first = second + arr[i];  // 0 + 50
			second = temp;  // 3
		}
								
		if(first > second)
			return first;
		else
			return second;
	}
	
	public static void main(String[] args) {
		
//		int []arr = { 3, 7, 4, 6, 5 };
//		System.out.println(getMax(arr));
		
//		int []arr = { 3, 50, 4, 6, 5, 5, 20 };  // 75 not 76
//		System.out.println(getMax(arr));
//		
//		int []arr2 = {5, 200, 10, 150, 100, 20, 200}; // 500 not 550
//		System.out.println(getMax(arr2));
//		
//		int []arr2 = { -2, 1, 3, -4, 5 };
//		System.out.println(getMax(arr2));
//		
//		int []arr3 = { 3, 5, -7, 8, 10 };
//		System.out.println(getMax(arr3));
//		
//		int []arr4 = { -3, -5, -7, -8, -10 };
//		System.out.println(getMax(arr4));
		
		
		Scanner in = new Scanner(System.in);
		int size = 0;
		int element;
		System.out.println("Enter number of elements");
		size = in.nextInt();
		int []array = new int[size];
		System.out.println("Enter your elements");
		for(int i = 0; i < array.length; i++) {
			element = in.nextInt();
			array[i] = element;
		}
		System.out.println(getMax(array));


	}

}

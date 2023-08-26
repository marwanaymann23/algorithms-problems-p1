import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


class Array{
	String name;
	int [] arr;
	 
	public Array() {
		name = "";
	}
	
	public Array(String name, int[] arr) {
		this.name = name;
		this.arr = arr;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int[] getArr() {
		return arr;
	}

	public void setArr(int[] arr) {
		this.arr = arr;
	}	
}

public class ArrayMultiplication {
	
	public static Array threeArraysMultiplication(Array arr1, Array arr2, Array arr3) {
		
		int result1 = 0, result2 = 0;
		int [] resultArr1 = new int[arr1.getArr().length];
		int [] resultArr2 = new int[arr1.getArr().length];
		Array resultObj;
		String name;
		
		// (arr1 * arr2) 
		resultArr1[0] = arr1.getArr()[0];
		resultArr1[1] = arr2.getArr()[1];
		result1 += arr1.getArr()[0] * arr1.getArr()[1] * arr2.getArr()[1];
		// (arr1 * arr2) * arr3
		resultArr1[1] = arr3.getArr()[1];
		result1 += resultArr1[0] * arr3.getArr()[0] * arr3.getArr()[1];
		
		// (arr2 * arr3)
		resultArr2[0] = arr2.getArr()[0];
		resultArr2[1] = arr3.getArr()[1];
		result2 += arr2.getArr()[0] * arr2.getArr()[1] * arr3.getArr()[1];
		// arr1 * (arr2 * arr3)
		resultArr2[0] = arr1.getArr()[0];
		result2 += resultArr2[0] * arr1.getArr()[1] * resultArr2[1];
				
		if(result1 <= result2) {
			name = "((" + arr1.getName() + " x " + arr2.getName() + ") x " + arr3.getName() + ")";
			resultObj = new Array(name, resultArr1);
			return resultObj;
		}
		
		// else
		name = "(" + arr1.getName() + " x (" +  arr2.getName() + " x " + arr3.getName() + "))";
		resultObj = new Array(name, resultArr2);
		return resultObj;			
	}
	
	
	public static Array twoArraysMultiplication(Array arr1, Array arr2) {
		
		int [] resultArr1 = new int[arr1.getArr().length];
		Array resultObj = new Array();
		String name;
		
		// arr1 * arr2
		resultArr1[0] = arr1.getArr()[0];
		resultArr1[1] = arr2.getArr()[1];
		
		name = "(" + arr1.getName() + " x " +  arr2.getName() + ")";
		resultObj = new Array(name, resultArr1);
		return resultObj;			
	}
	

	static ArrayList<Array> finalArrayList = new ArrayList<Array>();
	static boolean recursiveCall = false;
	
	public static ArrayList<Array> allArraysMultiplication(Array[] allArrays) {
		
		Array result = new Array();
		if(allArrays.length == 3) {
			result = threeArraysMultiplication(allArrays[0], allArrays[1], allArrays[2]);
			if(!recursiveCall) {
				System.out.println(result.getName());
				System.exit(0);
			}				
			else
				finalArrayList.add(result);
		}
		else if(allArrays.length == 2) {
			result = twoArraysMultiplication(allArrays[0], allArrays[1]);
			if(!recursiveCall) {
				System.out.println(result.getName());
				System.exit(0);
			}
			else
				finalArrayList.add(result);
		}
		
		if(allArrays.length > 3) {
			
			Array[] list1 = Arrays.copyOfRange(allArrays, 0, allArrays.length/2);
			Array[] list2 = Arrays.copyOfRange(allArrays, allArrays.length/2, allArrays.length);
			recursiveCall = true;
			
			allArraysMultiplication(list1);
			allArraysMultiplication(list2);
		}
		return finalArrayList;
	}
	
	public static void Arraychaining(ArrayList<Array> lista) {
		if(lista.size() == 2) {
			Array result = new Array();
			result = twoArraysMultiplication(lista.get(0), lista.get(1));
			System.out.println(result.getName());
			System.exit(0);
		}
		else if(lista.size() == 3) {
			Array result = new Array();
			result = threeArraysMultiplication(lista.get(0), lista.get(1), lista.get(2));
			System.out.println(result.getName());
			System.exit(0);
		}
		else if(lista.size() > 3) {
			//Array [] arrays = (Array[]) lista.toArray();
			Array[] arrays = new Array[lista.size()];
			for(int i = 0; i < lista.size(); i++) {
				arrays[i] = lista.get(i);
			}
			finalArrayList.clear();
			Arraychaining(allArraysMultiplication(arrays));
		}
	}
	
	public static void main(String[] args) {

		int noOfArrays = 0, sizeOfArray = 0, element = 0;		
		System.out.println("Enter number of arrays that you want to multiply");
		Scanner input = new Scanner(System.in);
		noOfArrays = input.nextInt();
		
		Array[] allArrays = new Array[noOfArrays];
		
		System.out.println("Enter the size of the array");
		sizeOfArray = input.nextInt();
		int[] arr1 = new int[sizeOfArray];
		
		for(int i = 0; i < noOfArrays; i++) {
			//System.out.println("Enter the elements of Array " + (i+1));
			
			for(int j = 0; j < sizeOfArray; j++) {
				element = input.nextInt();
				arr1[j] = element;
			}
			// to set the name of each array A1, A2, ...
			Array arrayObj = new Array(("A" + (i+1)), arr1);
			arr1 = new int[sizeOfArray];
			allArrays[i] = arrayObj;
		}
		Arraychaining(allArraysMultiplication(allArrays));
		
	}

}

















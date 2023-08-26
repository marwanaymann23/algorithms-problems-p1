import java.util.ArrayList;
import java.util.Scanner;

public class MatrixMultiplication {

	public static int[][] matrixMultiplication(int [] chain) {
		int size = chain.length;
		int [][] m = new int [size][size];
		int [][]DP = new int [size][size];
		
		for(int i = 0; i < size - 1; i++) {
			m[i][i] = 0;
		}
		
		for (int l = 1; l < size - 1; l++) {
			for (int i = 0; i < (size - 1) - l; i++) {
				int j = i + l;
				m[i][j] = Integer.MAX_VALUE;
					for (int k = i; k < j; k++)
					{
		
					int q = m[i][k] + m[k + 1][j] + (chain[i] * chain[k + 1] * chain[j + 1]);
					if (q < m[i][j]) {
						m[i][j] = q;
		
						DP[i][j] = k;
					}
				}
			}
		}
		return DP;
	}
	
	public static void printOptimalPath(int i,int j, int [][]DP)
    {
        if(i == j) 
        	System.out.print("A" + (i + 1));
        else
            {
        		System.out.print("(");
        		printOptimalPath(i, DP[i][j], DP);
        		System.out.print(" x ");
        		printOptimalPath((DP[i][j] + 1), j, DP);
        		System.out.print(")");
            }
    }
	
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
        String input = scan.nextLine();
        ArrayList<String> splittedInput = new ArrayList<String>();
        
        while (!input.equals("")) {
            String[] first = input.split(" ");
            splittedInput.add(first[0]);
            splittedInput.add(first[1]);
            input = scan.nextLine();
        }
        int[] finalInput = new int[splittedInput.size()];
        
        for (int i = 0; i < splittedInput.size(); i++) {
        	finalInput[i] = Integer.parseInt(splittedInput.get(i));
        }

        int size = finalInput.length / 2;
        int[] chain = new int[size + 1];
        chain[0] = finalInput[0];
        chain[1] = finalInput[1];

        int i = 1, j = i + 1;
        while (i < size) {

            if (finalInput[j] == chain[i]) {
                chain[i + 1] = finalInput[j + 1];
            }
            i++;
            j += 2;
        }

        int [][] result = new int [size][size];
        printOptimalPath(0, result.length - 1, matrixMultiplication(chain));
 
	}

}

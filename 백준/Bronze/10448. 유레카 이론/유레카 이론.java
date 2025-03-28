import java.util.Scanner;

public class Main {
	static int[] triNums = new int[45];
	static boolean getSolution(int num) {
		boolean res = false;
		
		for(int i = 1; i < 45; i++) {
			if(triNums[i] > num) return false;
			for(int j = i; j < 45; j++) {
				for(int k = j; k < 45; k++) {
					int sum = triNums[i] + triNums[j] + triNums[k];
					if(sum == num) return true;
				}
			}
		}
		return res;
	}
	
	static void makeTriNum() {
		int sum = 0;
		for(int i = 0; i < 45; i++) {
			sum += i;
			triNums[i] = sum;
		}
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		int[] k = new int[t];
		
		for(int i = 0; i < t; i++) k[i] = sc.nextInt();
		
		makeTriNum();
		
		for(int i = 0; i < t; i++) {
			if(getSolution(k[i])) System.out.println(1);
			else System.out.println(0);
		}
		
		sc.close();
	}
}

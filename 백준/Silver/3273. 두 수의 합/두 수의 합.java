import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		//수열의 크기 n
		int n = sc.nextInt();
		
		//수열 an
		int[] series = new int[n];
		for(int i = 0; i < n; i++) series[i]= sc.nextInt();
		
		Arrays.sort(series);
		//찾을 값 x
		int x = sc.nextInt();
		
		//problem solving
		int p = 0;
		int q = n - 1;
		
		int cnt = 0;
		while(q > p) {
			int sum = series[p] + series[q];
			if(sum == x) {
				cnt++;
				p++;
			}
			else if(sum > x) {
				q--;
			}
			else p++;
		}
		
		System.out.println(cnt);
	}
}

import java.util.Scanner;
import java.util.Arrays;

public class Main {
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		int[] dwarfs = new int[9];
		int sum = 0;
		
		for(int i = 0; i < 9; i++) {
			dwarfs[i] = sc.nextInt();
			sum += dwarfs[i];
		}
		
		Arrays.sort(dwarfs);
		
		int exceptedDwarfSum = sum - 100;
		//7명의 난쟁이를 무작위로 선택해서 키의 합이 100이 되는 조합을 출력해야 함..
		//how?  2마리 더 해서 제외 키 되는 애들 둘 빼고 다 출력...
		
		outer: for(int i = 0; i < 9; i++) {
			for(int j = i + 1; j < 9; j++) {
				if(exceptedDwarfSum == dwarfs[i] + dwarfs[j]) {
					for(int k = 0; k < 9; k++) {
						if(k == i || k == j) continue;
						System.out.println(dwarfs[k]);
					}
					break outer;
				}
			}
		}
	}
}

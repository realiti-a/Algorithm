import java.io.*;

public class Main {
			
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		//int t = 테스트 케이스의 수;
		int t = Integer.parseInt(br.readLine());
		//매 케이스마다 7개의 자연수 입력.
		for(int i = 0; i < t; i++) {
			String[] inputList = br.readLine().split(" ");
			
			//짝수의 합 구하고, 짝수 중 min 값 출력.
			int sum = 0; 
			int minValue = Integer.MAX_VALUE;
			for(int j = 0; j < inputList.length; j++) {
				int x = Integer.parseInt(inputList[j]);
				
				if(x % 2 != 0) continue;
				sum += x;
				if(x < minValue) minValue = x;
			}
			
			bw.write(sum + " " + minValue + "\n");
		}
		
		bw.flush();
	}
}

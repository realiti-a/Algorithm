import java.io.*;

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String[] inputs = br.readLine().split(" ");
		
		int S1 = Integer.parseInt(inputs[0]);
		int S2 = Integer.parseInt(inputs[1]);
		int S3 = Integer.parseInt(inputs[2]);
		
		int[] cnt = new int[20 + 20 + 40 + 1];
		for(int i = 1; i <= S1; i++) {
			for(int j = 1; j <= S2; j++) {
				for(int k = 1; k <= S3; k++) {
					cnt[i + j + k]++;
				}
			}
		}
		
		int max = 0;
		for(int i = 0; i < cnt.length; i++) {
			max = cnt[i] > cnt[max]? i : max;
		}
		bw.write(max + "");
		
		bw.flush();
	}
}

import java.io.FileInputStream;
import java.io.*;

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int t = Integer.parseInt(br.readLine());
		
		for(int i= 0; i < t;i++) {
			String[] inputs = br.readLine().split(" ");
			
			int h = Integer.parseInt(inputs[0]);
			int w = Integer.parseInt(inputs[1]);
			int n = Integer.parseInt(inputs[2]);
			
			bw.write(String.format("%d%02d\n", n%h == 0 ? h : n % h, n%h == 0 ? n / h : (n / h) + 1));
		}
		bw.flush();
	}
}

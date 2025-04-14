import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		String[] inputStrings = br.readLine().split(" ");
		
		long[] array = new long[n];
		for(int i = 0; i < n; i++) array[i] = Long.parseLong(inputStrings[i]);
		
		Arrays.sort(array);
		if(n % 2 == 0) {
			long result = array[n / 2 - 1];
			bw.write(Long.toString(result)+ "\n");
		}
		else {
			bw.write(Long.toString(array[n / 2]) + "\n");
		}
		
		bw.flush();
		
	}
}

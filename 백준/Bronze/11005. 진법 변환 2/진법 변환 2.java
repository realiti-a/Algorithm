import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String[] inputs = br.readLine().split(" ");
		
		//10진수 수.
		int n = Integer.parseInt(inputs[0]);
		
		//진법.
		int b = Integer.parseInt(inputs[1]);
		
		//캐릭터 배열 준비
		char[] chars = new char[36]; 
		for(int i = 0; i < 36; i++) {
			if(i < 10) chars[i] = (char)(i + '0');
			else chars[i] = (char)(i - 10 + 'A');
		}
		
		String result = "";
		while(n > 0) {
			int mode = n % b;
			result = chars[mode] + result;
			n /= b;
		}
		
		bw.write(result);
		
		bw.flush();
	}
}

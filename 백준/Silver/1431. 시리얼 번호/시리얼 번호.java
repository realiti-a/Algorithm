import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	public static int a = 100;
	public static int getNumber(String a) {
		int result = 0;
		for(int i = 0; i < a.length(); i++) {
			char c = a.charAt(i);
			if(c >= '0' && c <= '9') result += (int)(c - '0');
		}
		return result;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		String[] serials = new String[n];
		
		for(int i = 0; i < n; i++) {
			serials[i] = br.readLine();
		}
		
		Arrays.sort(serials, new Comparator<String>() {

			@Override
			public int compare(String o1, String o2) {
				// TODO Auto-generated method stub
				if(o1.length() != o2.length()) return o1.length() - o2.length();
				int sum1 = getNumber(o1);
				int sum2 = getNumber(o2);
				if(sum1 == sum2) return o1.compareTo(o2);
				return sum1 - sum2;
			}
			
		});
		
		for(int i = 0; i < n; i++) {
			bw.write(serials[i] + "\n");
		}
		
		bw.flush();
	}
}

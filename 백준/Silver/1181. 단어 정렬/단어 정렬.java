import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		String[] arrays = new String[n];
		for(int i = 0; i < n; i++) {
			arrays[i] = br.readLine();
		}
		
		Arrays.sort(arrays, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				// TODO Auto-generated method stub
				if(o1.length() != o2.length()) return Integer.compare(o1.length(), o2.length());
				return o1.compareTo(o2);
			}});
		
		String currentString = "";
		for(int i = 0; i < n; i++) {
			if(currentString.equals(arrays[i])) continue;
			currentString = arrays[i];
			bw.write(arrays[i] + "\n");
		}
		
		bw.flush();
	}
}

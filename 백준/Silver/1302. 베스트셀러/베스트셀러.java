import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		String[] bookNames = new String[n];
		
		for(int i = 0; i < n; i++) {
			String bookName = br.readLine();
			bookNames[i] = bookName;
		}
		
		Arrays.sort(bookNames, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				return o1.compareTo(o2);
			}
		});
		
		int maxCnt = 0;
		int cnt = 0;
		int maxIndex = 0;
		int curIndex = 0;
		
		for(int i = 0; i < n; i++) {
			//System.out.println(bookNames[i]);
			if(bookNames[curIndex].equals(bookNames[i])) {
				cnt++;
				continue;
			}
			if(cnt > maxCnt) {
				maxCnt = cnt;
				maxIndex = i - 1;
			}
			
			curIndex = i;
			cnt = 1;
		}
		
		if(cnt > maxCnt) {
			maxIndex = curIndex;
		}
		
		bw.write(bookNames[maxIndex]);
		bw.flush();
	}
}

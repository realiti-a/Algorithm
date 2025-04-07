import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Iterator;
import java.util.TreeSet;



public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		
		TreeSet<String> office = new TreeSet<String>();
		
		for(int i = 0; i < n; i++) {
			String[] inputs = br.readLine().split(" ");
			
			//bw.write(inputs[0] + "\n");
			//bw.write(inputs[1] + "\n");
			
			if("enter".equals(inputs[1])) {
				if(office.contains(inputs[0])) continue;
				office.add(inputs[0]);
			}else if("leave".equals(inputs[1])) {
				if(office.contains(inputs[0])) office.remove(inputs[0]);
				continue;
			}
		}
		
		Iterator<String> iter = office.descendingIterator();
		
		while(iter.hasNext()) {
			String str = iter.next();
			
			bw.write(str + "\n");
		}
		
		bw.flush();
	}
}

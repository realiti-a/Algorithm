import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < t; i++) {
			String[] inputs = br.readLine().split(" ");
			int a = Integer.parseInt(inputs[0]);
			int b = Integer.parseInt(inputs[1]);
			
			ArrayList<Integer> arr = new ArrayList<Integer>();
			
			int multiple = a;
//			System.out.println(i + "번째 /n");
			while(true) {
				int one = multiple % 10;
//				System.out.println(one);
				if(!arr.isEmpty() && arr.get(0) == one) break;
				arr.add(one);
				multiple = one * (a % 10);
			}
			//프린
			int result = arr.get((b - 1) % arr.size());
			if(result == 0) result += 10;
			bw.write(Integer.toString(result) + "\n");
		}
		bw.flush();
		
	}
}

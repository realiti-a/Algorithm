import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class Main {
		static ArrayList<Integer> changeFormation(int x, int b) {
			ArrayList<Integer> arr = new ArrayList<Integer>();
			while(x > 0) {
				arr.add(Integer.valueOf(x%b));
				x /= b;
			}
			return arr;
		}
		
		static boolean isFelindrom(ArrayList<Integer> arr) {
			int length = arr.size();
			for(int i = 0; i < length; i++) {
				if(arr.get(i) != arr.get(length - i - 1)) return false;
			}
			return true;
		}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		//T개의 테스트 데이터.
		int t = Integer.parseInt(br.readLine());
		//데이터는 64이상, 1,000,000이하의 하나의 정수
		outer: for(int i = 0; i < t; i++){
			//2에서 64사이의 진법으로 표현했을 때 회문이 되는지?
			int x = Integer.parseInt(br.readLine());
			for(int b = 2; b <= 64; b++) {
				if(isFelindrom(changeFormation(x, b))) {
					bw.write("1\n");
					continue outer;
				}
			}
			bw.write("0\n");
			//하나의 데이터에 대한 답을 하나의 줄에 출력
		}
		
		bw.flush();
	}
}

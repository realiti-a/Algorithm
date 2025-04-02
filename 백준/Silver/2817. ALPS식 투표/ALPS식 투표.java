import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.ArrayList;

class Scores{
	char c;
	double votes;
	
	Scores(char c, double votes){
		this.c = c;
		this.votes = votes;
	}
	
}

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		//대회에 참가한 참가자의 수. 
		int x = Integer.parseInt(br.readLine());
		//참가한 스태프의 수.
		int n = Integer.parseInt(br.readLine());
		
		//점수 배열.
		ArrayList<Scores> sc = new ArrayList<Scores>();
		
		//스태프 배열..-> 출력할지 결정하는.
		boolean[] staffs = new boolean[26];
		Arrays.fill(staffs, false);
		//칩 배열.. -> 칩 갯수 저장.
		int[] cnt = new int[26];
		Arrays.fill(cnt, 0);
		for(int i = 0; i < n; i++) {
			String[] inputs = br.readLine().split(" ");
			
			char staff = inputs[0].charAt(0);
			int votes = Integer.parseInt(inputs[1]);
			
			if(votes * 20 < x) continue;
			//점수 배열 생성..
			staffs[staff - 'A'] = true;
			for(int j = 1; j <= 14; j++) {
				double scores = (double)votes / j;
				Scores a = new Scores(staff, scores);
				sc.add(a);
			}
		}
		
		//정렬
		sc.sort(new Comparator<Scores>() {
			public int compare(Scores a, Scores b) {
				return Double.compare(a.votes, b.votes);
			}
		}.reversed());
		
		for(int i = 0; i < 14; i++) {
			Scores a = sc.get(i);
			cnt[(int)(a.c - 'A')]++;
		}
		//칩 갯수 출력
		for(int i = 0; i < 26; i++) {
			if(staffs[i] == false) continue;
			bw.write(String.format("%c %d\n", (char)(i + 'A'), cnt[i]));
		}
		bw.flush();
	}
}

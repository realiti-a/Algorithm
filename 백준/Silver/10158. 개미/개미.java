import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int width = Integer.parseInt(st.nextToken());
		int height = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		int p = Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int time = Integer.parseInt(st.nextToken());
		
		p = (p + time)%(2 * width);
		q = (q + time)%(2 * height);
		
		if(p > width) p = 2 * width - p;
		if(q > height) q = 2 * height - q;
		
		StringBuilder sb = new StringBuilder();
		sb.append(p);
		sb.append(" ");
		sb.append(q);
		
		System.out.println(sb.toString());
	}
}

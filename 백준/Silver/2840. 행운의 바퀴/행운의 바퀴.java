import java.io.*;
import java.util.Arrays;

class Wheel{
	int size;
	char[] wheel;
	int pointer;
	int[] cnt;
	Wheel(int n){
		this.size = n;
		this.wheel = new char[n];
		Arrays.fill(wheel, '?');
		this.pointer = 0;
		cnt = new int[(int)('Z' - 'A' + 1)];
		Arrays.fill(cnt, 0);
	}
	
	char rotation(int n, char c) {
		pointer += n;
		if(wheel[pointer%size] != '?' && wheel[pointer%size] != c) {
			return '!';
		}
		if(wheel[pointer%size] == c) return c;
		if(cnt[(int)(c - 'A')] >= 1) return '!';
		wheel[pointer%size] = c;
		cnt[(int)(c - 'A')]++;
		return c;
	}
	
	char[] printWheel() {
		char[] res = new char[size];
		for(int i = 0; i < size; i++) {
			res[i] = wheel[(((pointer - i) % size) + size) % size];
		}
		return res;
	}
}

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String[] inputs = br.readLine().split(" ");
		int n = Integer.parseInt(inputs[0]);
		int k = Integer.parseInt(inputs[1]);
		
		Wheel wheel = new Wheel(n);
		
		for(int i = 0; i < k; i++) {
			String[] rotationOrder = br.readLine().split(" ");
			int rotation = Integer.parseInt(rotationOrder[0]);
			char c = rotationOrder[1].charAt(0);
			
			if(wheel.rotation(rotation, c) == '!') {
				bw.write("!");
				bw.flush();
				return;
			}
		}
		
		bw.write(String.valueOf(wheel.printWheel()));
		
		bw.flush();
	}
}

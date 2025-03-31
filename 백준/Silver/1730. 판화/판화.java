import java.io.*;

class Direction{
	int[][] direction;
	
	Direction(int n){
		this.direction = new int[n][n];
	}
}

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		//보드의 사이즈.
		int n = Integer.parseInt(br.readLine());
		
		//칼의 이동 방향.
		char[] directionOrder = br.readLine().toCharArray();
		
		Direction rowDirection = new Direction(n);
		Direction colDirection = new Direction(n);
		
		//이동 방향 저장.
		int x = 0; int y = 0;
		for(int i = 0; i < directionOrder.length; i++) {
			char order = directionOrder[i];
			if(order == 'U') {
				if(x - 1 < 0) continue;
				colDirection.direction[x][y] = 1;
				x -= 1;
				colDirection.direction[x][y] = 1;
			}
			else if(order == 'D') {
				if(x + 1 >= n) continue;
				colDirection.direction[x][y] = 1;
				x += 1;
				colDirection.direction[x][y] = 1;
			}
			else if(order == 'L') {
				if(y - 1 < 0) continue; 
				rowDirection.direction[x][y] = 1;
				y -= 1;
				rowDirection.direction[x][y] = 1;
			}
			else if(order == 'R') {
				if(y + 1 >= n) continue;
				rowDirection.direction[x][y] = 1;
				y += 1;
				rowDirection.direction[x][y] = 1;
			}
		}
		
		//포맷 맞춰 출력..
		for(int i = 0; i < n; i++) {
			char[] rowResult = new char[n];
			for(int j = 0; j < n; j++) {
				if(colDirection.direction[i][j] == 1 && rowDirection.direction[i][j] == 1) {
					rowResult[j] = (char)43;
				}
				else if(colDirection.direction[i][j] == 1) {
					rowResult[j] = (char)124;
				}
				else if(rowDirection.direction[i][j] == 1) {
					rowResult[j] = (char)45;
				}
				else rowResult[j] = (char)46;
			}
			bw.write(String.valueOf(rowResult) + "\n");
		}
		bw.flush();
	}
}

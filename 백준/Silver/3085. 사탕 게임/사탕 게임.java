import java.io.*;

public class Main {
	static char[][] board;
	
	static int getMaxLength() {
		int max = 0;
		//char[] colors = {'C', 'P', 'Z', 'Y'};
		
		//세로 방향 max
		for(int y = 0; y < board.length; y++) {
			int cnt = 0;
			char cur = board[y][0];
			for(int x = 0; x < board[y].length; x++) {
				if(board[y][x] == cur) cnt++;
				else {
					max = cnt > max ? cnt : max;
					cnt = 1;
					cur = board[y][x];
				}
			}
			max = cnt > max ? cnt : max;
		}
		
		//가로 방향 max
		for(int x = 0; x < board[0].length; x++) {
			int cnt = 0;
			char cur = board[x][0];
			for(int y = 0; y < board.length; y++) {
				if(board[y][x] == cur) cnt++;
				else {
					max = cnt > max ? cnt : max;
					cnt = 1;
					cur = board[y][x];
				}
			}
			max = cnt > max ? cnt : max;
		}
		return max;
	}
	
	static void changeBoard(int x, int y, int dx, int dy) {
		int nx = x + dx;
		int ny = y + dy;
		
		if(nx < 0 || nx >= board[y].length) return;
		if(ny < 0 || ny >= board.length) return;
		
		char tmp = board[x][y];
		board[x][y] = board[nx][ny];
		board[nx][ny] = tmp;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		board = new char[n][];
		
		for(int i = 0; i < n; i++) {
			board[i] = br.readLine().toCharArray();
		}
		
		int max = 0;
		int dx[] = {-1, 1, 0, 0};
		int dy[] = {0, 0, -1, 1};
		
		for(int y = 0; y < board.length; y++) {
			for(int x = 0; x < board[y].length; x++) {
				for(int i = 0; i < 4; i++) {
					changeBoard(x, y, dx[i], dy[i]);
					
					int currentMax = getMaxLength();
					max = currentMax > max ? currentMax : max;
					
					changeBoard(x, y, -dx[i], -dy[i]);	
				}
				
			}
		}
		
		bw.write(max + "\n");
		bw.flush();
	}
}

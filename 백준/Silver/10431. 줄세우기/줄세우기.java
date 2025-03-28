import java.util.Scanner;

class ElementClass{
	int[] studentHeight;
	
	ElementClass(int[] heights){
		this.studentHeight = heights;
	}
	
	int getSortCount() {
		int cnt = 0;
		
		for(int i = 0; i < studentHeight.length;i++) {
			for(int j = 0; j < i; j++) {
				if(studentHeight[i] < studentHeight[j]) cnt++;
			}
		}
		return cnt;
	}
}

public class Main {
	static int[] result;
	static final int STUDENT_COUNT = 20;
	static ElementClass[] classes;
	
	static void input() throws Exception {
		Scanner sc = new Scanner(System.in);
		
		//테스트 케이스의 수 
		int p = sc.nextInt();
		
		result = new int[p];
		classes = new ElementClass[p];
		
		for(int i = 0; i < p; i++) {
			int number = sc.nextInt();
			if(number != i + 1) throw new Exception("입력 순서 Error");
			
			int[] heights = new int[STUDENT_COUNT];
			for(int j = 0; j < STUDENT_COUNT; j++) {
				heights[j] = sc.nextInt();
			}
			
			classes[i] = new ElementClass(heights);
		}
		
		sc.close();		
	}

	static void output() {
		for(int i = 0; i < result.length; i++) {
			String resultString = String.format("%d %d", i + 1, result[i]);
			System.out.println(resultString);
		}
		
	}
	
	public static void main(String[] args) throws Exception {
		input();
		
		for(int i = 0; i < result.length; i++) {
			result[i] = classes[i].getSortCount();
		}
		
		output();
	
	}
}

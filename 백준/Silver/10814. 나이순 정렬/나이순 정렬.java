import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

class People {
	int age;
	String name;
	int rank;
	
	People(int rank, String name, int age){
		this.age = age;
		this.name = name;
		this.rank = rank;
	}
}

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		
		People[] peoples = new People[n];
		
		for(int i = 0; i <  n; i++) {
			String[] inputs = br.readLine().split(" ");
			int age = Integer.parseInt(inputs[0]);
			String name = inputs[1];
			
			peoples[i] = new People(i, name, age);
		}
		
		Arrays.sort(peoples, new Comparator<People>() {
			@Override
			public int compare(People o1, People o2) {
				// TODO Auto-generated method stub
				if(Integer.compare(o1.age, o2.age) == 0) {
					return Integer.compare(o1.rank, o2.rank);
				}
				return Integer.compare(o1.age, o2.age);
			}
		});
		
		for(int i = 0; i < n; i++) {
			bw.write(peoples[i].age + " " + peoples[i].name + "\n");
		}
		
		bw.flush();
	}
}

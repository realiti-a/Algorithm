import java.util.Scanner;

class Time{
	int hours;
	int minutes;
	int seconds;
	
	Time(){
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	
	Time(String timeString){
		hours = Integer.valueOf(timeString.substring(0, 2)).intValue();
		minutes = Integer.valueOf(timeString.substring(3, 5)).intValue();
		seconds = Integer.valueOf(timeString.substring(6, 8)).intValue();
	}
	
	void setHours(int hours) {
		this.hours = hours;
	}
	
	int getHours() {
		return this.hours;
	}
	
	void setMinutes(int minutes) {
		this.minutes = minutes;
	}
	
	int getMinutes(){
		return this.minutes;
	}
	
	void setSeconds(int seconds) {
		this.seconds = seconds;
	}
	
	int getSeconds() {
		return this.seconds;
	}
	
	void diffSec(int a) {
		if(this.getSeconds() < a) {
			this.diffMin(1);
			this.diffSec(-60);
		}
		this.setSeconds(this.getSeconds() - a);
	}
	
	void diffMin(int a) {
		if(this.getMinutes() < a) {
			this.diffHour(1);
			this.diffMin(-60);
		}
		this.setMinutes(this.getMinutes() - a);
	}
	
	void diffHour(int a) {
		if(this.getHours() < a) {
			this.diffHour(-24);
		}
		this.setHours(this.getHours() - a);
	}
	
	boolean equals(Time b) {
		return this.getHours() == b.getHours()
			&& this.getMinutes() == b.getMinutes()
			&& this.getSeconds() == b.getSeconds();
	}
	
	void getDifference(Time b) {
		if(this.equals(b)) {
			this.diffHour(-24);
		}
		
		this.diffSec(b.getSeconds());
		this.diffMin(b.getMinutes());
		this.diffHour(b.getHours());
	}
	
	String toTimeForm(int a) {
		if(a <= 0) return "00";
		else if(a < 10) return "0" + String.valueOf(a);
		else return String.valueOf(a);
	}
	
	public String toString() {
		String res = this.toTimeForm(hours) + ":"
					+ this.toTimeForm(minutes) + ":"
					+ this.toTimeForm(seconds);
		
		return res;
	}
}
public class Main {
	static String current ;
	static String usingCup;
	
	static void input() throws Exception {
		Scanner sc = new Scanner(System.in);
		
		//입력 작성
		current = sc.nextLine();
		usingCup = sc.nextLine();
		
		sc.close();
	}
	
	static void output(String str) {
		System.out.println(str);
	}
	
	public static void main(String[] args) throws Exception {
		//문서 입력 1줄. 찾고 싶은 문자열 입력 1줄.
		input();
		
		Time currentTime = new Time(current);
		Time usingCupTime = new Time(usingCup);
		
		usingCupTime.getDifference(currentTime);
		
		output(usingCupTime.toString());
	}
}

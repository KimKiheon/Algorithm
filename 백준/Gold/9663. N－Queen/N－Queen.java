import java.util.Scanner;

public class Main {
	static int[] col;
	static int N,ans;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		col=new int[N+1];
		setQueen(1);
		System.out.println(ans);
	}

	static void setQueen(int rowNo) { // rowNo
		if(rowNo>N) {
			ans++;
			return;
		}
		
		for (int i = 1; i <= N; i++) {
			col[rowNo] = i;
			if(!isAvailable(rowNo))continue;
			setQueen(rowNo + 1);
		}
	}

	static boolean isAvailable(int rowNo) {
		for (int i = 1; i < rowNo; i++) { // i : 비교대상 queen의 행
			if (col[i] == col[rowNo] || Math.abs(col[i] - col[rowNo]) == Math.abs(rowNo - i))
				return false;
		}
		return true;
	}
}
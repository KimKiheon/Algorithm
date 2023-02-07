import java.util.Scanner;

public class Main {
    static boolean[] arr;
    static int switchSize, n, gender, number;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        switchSize = sc.nextInt();
        arr = new boolean[switchSize];
        for (int i = 0; i < switchSize; i++) {
            int a;
            a = sc.nextInt();
            if (a == 1) arr[i] = true;
            else arr[i] = false;
        }
        n=sc.nextInt();
        while(n-->0){
            gender=sc.nextInt();
            number=sc.nextInt();
            if(gender==1){
                for(int i=number-1;i<switchSize;i+=number){
                    arr[i]=!arr[i];
                }
            }
            else{
                number--;
                arr[number]=!arr[number];
                for(int i=1;;i++){
                    if (number - i < 0 || switchSize <= number + i||
                            (arr[number-i]!=arr[number+i]))break;
                    arr[number - i] = !arr[number - i];
                    arr[number + i] = !arr[number + i];
                }
            }
        }
        for(int i=1;i<=switchSize;i++){
            if(arr[i-1]) System.out.printf("1 ");
            else System.out.printf("0 ");
            if(i%20==0) System.out.println();
        }
    }
}
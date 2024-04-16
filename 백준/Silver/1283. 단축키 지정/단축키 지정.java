import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
    static String[] arr;
    static String[][] separateString;
    static boolean[] check;

    public static String addBracket(String s, int idx) {
        return s.substring(0, idx) + '[' + s.charAt(idx) + ']' + s.substring(idx + 1);
    }

    public static boolean go(String s, int i, int j, int idx) {
        char c = s.toLowerCase().charAt(idx);
        if (!check[c - 'a']) {
            check[c - 'a'] = true;
            separateString[i][j] = addBracket(separateString[i][j], idx);
            return true;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        arr = new String[n];
        separateString = new String[n][];
        check = new boolean[26];
        for (int i = 0; i < n; i++) {
            arr[i] = br.readLine();
            separateString[i] = arr[i].split(" ");
        }
        for (int i = 0; i < separateString.length; i++) {
            String[] s = separateString[i];
            boolean flag = false;
            for (int j = 0; j < s.length; j++) {
                flag = go(s[j], i, j, 0);
                if(flag) break;
            }
            if (flag) continue;

            for (int j = 0; j < s.length; j++) {
                for (int k = 0; k < s[j].length(); k++) {
                    flag = go(s[j], i, j, k);
                    if (flag) break;
                }
                if (flag) break;
            }
        }
        for(String[] s:separateString){
            for(String ss:s){
                System.out.print(ss+" ");
            }
            System.out.println();
        }
    }
}
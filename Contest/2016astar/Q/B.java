import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        BigInteger[][] C = new BigInteger[201][201];
        for(int i = 0; i < 201; ++i)
            for(int j = 0; j < 201; ++j)
                C[i][j] = BigInteger.ZERO;
        for(int i = 0; i < 201; ++i)
            C[i][0] = BigInteger.ONE;
        for(int i = 1; i < 201; ++i)
            for(int j = 1; j <= i; ++j){
                C[i][j] = C[i - 1][j].add(C[i - 1][j - 1]);
            }
        while(cin.hasNext()){
            Integer n = cin.nextInt();
            BigInteger ans = BigInteger.ZERO;
            for(int i = 0; i <= n / 2; ++i){
                ans = ans.add(C[n - i][i]);
            }
            System.out.println(ans);
        }
    }
}

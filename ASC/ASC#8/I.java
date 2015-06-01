import java.math.*;
import java.util.*;
import java.io.BufferedInputStream;

public class Main {
	public static void main(String[] args){
		Scanner cin = new Scanner (new BufferedInputStream(System.in));
		while(true){
			BigInteger a,b;
			a = cin.nextBigInteger();
			b = cin.nextBigInteger();
			System.out.println(a.gcd(b));
			if(cin.hasNextBigInteger()) System.out.println("");
			else break;
		}
	}
}

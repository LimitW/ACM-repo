import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;

public class Handsome {
  static class Solver {
    class Pair implements Comparable<Pair> {

      int state;
      double value;

      @Override
      public int compareTo(Pair o) {
        return value < o.value ? -1 : (value == o.value ? 0 : 1);
      }
    }

    final int MAGIC = 17;
    int[] primes;
    double[] logPrimes;
    Pair[] table;
    double target;

    boolean isPrime(int x) {
      for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
      }
      return true;
    }

    void genTable(int now, int n, int state, double sum) {
      if (now == n) {
        table[state].state = state;
        table[state].value = sum;
      } else {
        genTable(now + 1, n, state, sum);
        genTable(now + 1, n, state | (1 << now), sum + logPrimes[now]);
      }
    }

    Pair[] binarySearch(double val) {
      int l = 0;
      int r = table.length - 1;
      if (val < table[l].value) {
        return new Pair[] {table[l], table[l]};
      }
      if (val > table[r].value) {
        return new Pair[] {table[r], table[r]};
      }
      while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (table[mid].value < val) {
          l = mid;
        } else {
          r = mid;
        }
      }
      return new Pair[] {table[l], table[r]};
    }

    Pair dfs(int now, int n, int state, double sum) {
      if (now == n) {
        Pair[] tmp = binarySearch(target - sum);
        assert (tmp.length == 2);
        Pair t1 = new Pair(), t2 = new Pair();
        t1.state = tmp[0].state | state;
        t2.state = tmp[1].state | state;
        for (int i = 0; i < n; i++) {
          if ((t1.state & (1 << i)) == (1 << i)) {
            t1.value += logPrimes[i];
          }
          if ((t2.state & (1 << i)) == (1 << i)) {
            t2.value += logPrimes[i];
          }
        }
        return Math.abs(t1.value - target) < Math.abs(t2.value - target) ? t1 : t2;
      } else {
        Pair t1 = dfs(now + 1, n, state, sum);
        Pair t2 = dfs(now + 1, n, state | (1 << now), sum + logPrimes[now]);
        return Math.abs(t1.value - target) < Math.abs(t2.value - target) ? t1 : t2;
      }
    }

    BigInteger getAns(int state, int n) {
      BigInteger A = BigInteger.ONE, B = BigInteger.ONE;
      for (int i = 0; i < n; i++) {
        if ((state & (1 << i)) == (1 << i)) {
          A = A.multiply(BigInteger.valueOf(primes[i]));
        } else {
          B = B.multiply(BigInteger.valueOf(primes[i]));
        }
      }
      return A.compareTo(B) > 0 ? B : A;
    }

    BigInteger solve(int n) {
      primes = new int[n];
      logPrimes = new double[n];
      for (int i = 0, j = 2; i < n; i++) {
        while (!isPrime(j)) {
          j++;
        }
        primes[i] = j;
        logPrimes[i] = Math.log(j);
        target += logPrimes[i] * 0.5;
        j++;
      }
      if (n < MAGIC) {
        table = new Pair[1 << n];
        for (int i = 0; i < table.length; i++) {
          table[i] = new Pair();
        }
        genTable(0, n, 0, 0);
        Arrays.sort(table);
        Pair ans = dfs(n, n, 0, 0);
        return getAns(ans.state, n);
      } else {
        table = new Pair[1 << MAGIC];
        for (int i = 0; i < table.length; i++) {
          table[i] = new Pair();
        }
        genTable(0, MAGIC, 0, 0);
        Arrays.sort(table);
        Pair ans = dfs(MAGIC, n, 0, 0);
        return getAns(ans.state, n);
      }
    }
  }

  public static void main(String[] args) {
    try {
      BufferedReader br = new BufferedReader(new FileReader("handsome.in"));
      PrintWriter pw = new PrintWriter(new FileWriter("handsome.out"));
      String buf = null;
      int cases = 0;
      while ((buf = br.readLine()) != null) {
        int n = Integer.parseInt(buf);
        if (n == 0) break;
        BigInteger ans = new Solver().solve(n);
        pw.printf("Case #%d: %s\n", ++cases, ans.toString());
      }
      br.close();
      pw.close();
    } catch (Exception e) {}
  }

}
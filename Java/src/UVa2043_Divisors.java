import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class UVa2043_Divisors {
	public static int MAX = 100005;
	public static int[] d = new int[MAX];
	public static int[] o = new int[MAX];

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);

		d[1] = 1;
		o[1] = 1;
		for (int i = 2; i < MAX; i++) {
			d[i] = 2;
			o[i] = 1 + i;
			for (int j = 2; j * j <= i; j++)
				if (i % j == 0) {
					d[i]++;
					o[i] += j;
					if (j * j != i) {
						d[i]++;
						o[i] += i / j;
					}
				}

		}

		int cases = Integer.parseInt(in.readLine()), a, b, k;
		long g, h;
		StringTokenizer st;
		while (cases-- > 0) {
			st = new StringTokenizer(in.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			g = h = 0;
			while (a % k != 0)
				a++;

			for (int i = a; i <= b; i += k) {
				g += d[i];
				h += o[i];
			}
			out.printf("%d %d\n", g, h);
		}

		out.close();
	}
}

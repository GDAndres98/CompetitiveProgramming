import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class UVa12608_GarbageCollection {
	public static int MAX = 1005;
	public static int[] x = new int[MAX];
	public static int[] w = new int[MAX];

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);

		int cases = Integer.parseInt(in.readLine()), wM, n, wA;
		long total;
		StringTokenizer st;
		while (cases-- > 0) {
			total = 0;
			wA = 0;
			st = new StringTokenizer(in.readLine());
			wM = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			//FIXME xd
			for (int i = 1; i <= n; i++) {
				st = new StringTokenizer(in.readLine());
				x[i] = Integer.parseInt(st.nextToken());
				w[i] = Integer.parseInt(st.nextToken());

				total += x[i] - x[i - 1];
				wA += w[i];

				if (wA > wM) {
					wA = w[i];
					total += x[i] * 2;
				}

				if (wA == wM) {
					total += x[i];
					wA = 0;
					x[i] = 0;
				}

			}
			
			if(wA>0) {
				total +=x[n];
			}
			

			out.printf("%d\n", total);

		}

		out.close();
	}
}

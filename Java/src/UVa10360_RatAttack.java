import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class UVa10360_RatAttack {
	public static void main(String[] args) throws NumberFormatException, IOException {
		int[][] ratonera = new int[1025][1025];
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		int n = Integer.parseInt(in.readLine());
		int d, m, x, y, r;
		long max;
		StringTokenizer st;
		while (n-- != 0) {
			d = Integer.parseInt(in.readLine());
			m = Integer.parseInt(in.readLine());
			while (m-- != 0) {
				st = new StringTokenizer(in.readLine());
				x = Integer.parseInt(st.nextToken());
				y = Integer.parseInt(st.nextToken());
				r = Integer.parseInt(st.nextToken());
				int initi = Math.max(0, x - d), 
						initj = Math.max(0, y - d), 
						maxi = Math.min(ratonera.length - 1, x + d),
						maxj = Math.min(ratonera.length - 1, y + d);
				for (int i = initi; i <= maxi; i++)
					for (int j = initj; j <= maxj; j++)
						ratonera[i][j] += r;
			}

//			for (int i = 0; i < 100; i++) {
//				for (int j = 0; j < 100; j++) {
//					System.out.print(ratonera[i][j] + " ");
//				}
//				System.out.println();
//			}
			max = x = y = 0;
			for (int i = 0; i < ratonera.length; i++)
				for (int j = 0; j < ratonera.length; j++)

					if (max < ratonera[i][j]) {
						max = ratonera[i][j];
						x = i;
						y = j;
					}
			out.println((x) + " " + (y) + " " + max);

			for (int i = 0; i < ratonera.length; i++)
				Arrays.fill(ratonera[i], 0);

		}
		out.close();
	}
}

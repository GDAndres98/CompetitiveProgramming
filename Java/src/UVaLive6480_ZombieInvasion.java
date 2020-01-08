import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class UVaLive6480_ZombieInvasion {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		int cases = Integer.parseInt(in.readLine()), pueblitos[] = new int[20], sum;
		StringTokenizer st;
		while (cases-- > 0) {
			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < pueblitos.length; i++)
				pueblitos[i] = Integer.parseInt(st.nextToken());

			sum = 0;
			for (int i = pueblitos.length-1; i > 0; i--) {
				pueblitos[i] = pueblitos[i] + sum;
				sum = pueblitos[i] / 2;
				if (pueblitos[i] % 2 == 0)
					pueblitos[i] = 0;
				else
					pueblitos[i] = 1;
			}

			out.print(pueblitos[0] + sum);

			for (int i = 1; i < pueblitos.length; i++) {
				out.print(" " + pueblitos[i]);
			}

			out.println();

		}

		out.close();
	}
}

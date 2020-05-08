import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main{

	static ArrayList<String> words = new ArrayList<String>();
	static HashMap<String, Integer> wordsi = new HashMap<String, Integer>();
	static boolean[][] cantPair;
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(System.out);
	static int indexes[] = new int[5];
	static int n, w, l;

	public static void main(String[] args) throws NumberFormatException, IOException {
		int t = Integer.parseInt(in.readLine());
		for (int cases = 1; cases <= t; cases++) {
			words.clear();
			wordsi.clear();
			StringTokenizer st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			l = Integer.parseInt(st.nextToken());
			cantPair = new boolean[n][n];
			for (int i = 0; i < n; i++)
				words.add(in.readLine().trim().toUpperCase());
			words.sort((x, y) -> {
				if (x.length() == y.length())
					return x.compareTo(y);
				return Integer.compare(y.length(), x.length());
			});

			for (int i = 0; i < n; i++)
				wordsi.put(words.get(i), i);

			for (int i = 0; i < w; i++) {
				st = new StringTokenizer(in.readLine());
				int o = wordsi.get(st.nextToken().toUpperCase());
				int d = wordsi.get(st.nextToken().toUpperCase());
				cantPair[o][d] = true;
				cantPair[d][o] = true;
			}

			out.printf("Set %d:\n", cases);
			for (int i = 0; i < n; i++) 
				printing(i, 0);

			out.println();
		}

		out.close();
	}

	private static void printing(int a, int b) {
		indexes[b] = a;
		for (int i = 0; i < b; i++)
			if (cantPair[a][indexes[i]])
				return;
		if (b + 1 == l) {
			out.print(words.get(indexes[0]));
			for (int i = 1; i <= b; i++) {
				out.print(" " + words.get(indexes[i]));
			}
			out.println();
			return;
		}

		for (int i = a + 1; i < n; i++) {
			printing(i, b + 1);
		}

	}
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class UVa12168_CatvsDog{
	public static int[][] catL = new int[510][2];
	public static int[][] dogL = new int[510][2];
	public static int[] matchR = new int[510];
	public static boolean vis[] = new boolean[510];
	public static int cn;
	public static int dn;
	public static ArrayList<Integer>[] g = new ArrayList[510];

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		int cases = Integer.parseInt(in.readLine()), gatos, perros, v;
		StringTokenizer st;
		String s;
		for (int i = 0; i < g.length; i++)
			g[i] = new ArrayList<Integer>();

		for (int c = 0; c < cases; c++) {
			cn = dn = 0;
			st = new StringTokenizer(in.readLine());
			gatos = Integer.parseInt(st.nextToken());
			perros = Integer.parseInt(st.nextToken());
			v = Integer.parseInt(st.nextToken());

			for (int i = 0; i < v; i++) {
				s = in.readLine();
				st = new StringTokenizer(s);
				if (s.charAt(0) == 'C') {
					catL[cn][0] = Integer.parseInt(st.nextToken().substring(1));
					catL[cn][1] = Integer.parseInt(st.nextToken().substring(1));
					g[cn++].clear();
				} else {
					dogL[dn][0] = Integer.parseInt(st.nextToken().substring(1));
					dogL[dn++][1] = Integer.parseInt(st.nextToken().substring(1));
				}
			}

			for (int i = 0; i < cn; i++)
				for (int j = 0; j < dn; j++)
					if (catL[i][0] == dogL[j][1] || catL[i][1] == dogL[j][0])
						g[i].add(j);

			int result = maxBPM();
			
			out.println(v - result);

		}

		out.close();
	}

	public static int maxBPM() {

		for (int i = 0; i < cn; ++i)
			matchR[i] = -1;

		int result = 0;
		for (int u = 0; u < cn; u++) {

			for (int i = 0; i < cn; ++i)
				vis[i] = false;

			if (bpm(u))
				result++;
		}
		return result;
	}

	static boolean bpm(int u) {
		for (int j = 0; j < g[u].size(); j++) {
			int v = g[u].get(j);
			if (!vis[v]) {

				vis[v] = true;

				if (matchR[v] < 0 || bpm(matchR[v])) {
					matchR[v] = u;
					return true;
				}
			}
		}
		return false;
	}

}
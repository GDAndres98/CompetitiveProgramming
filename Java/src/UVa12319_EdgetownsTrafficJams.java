import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class UVa12319_EdgetownsTrafficJams {
	
	public static final int INF= 1000000;
	public static int n;
//	public static ArrayList<Integer>[] oldG = new ArrayList[110];
	public static ArrayList<Integer>[] newG = new ArrayList[110];
	public static int[][] oldG = new int[110][110];
//	public static int[][] newG = new int[110][110];
	public static int[][] oldMady = new int[110][110];
	public static int[][] newMady = new int[110][110];

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer st;
		int o, d, A, B;
		boolean done;
		for (int i = 0; i < 110; i++) {
//			oldG[i] = new ArrayList<Integer>();
			newG[i] = new ArrayList<Integer>();
		}

		while (true) {
			n = Integer.parseInt(in.readLine());
			if (n == 0)
				break;

			for (int i = 0; i < n; i++) {
//				oldG[i].clear();
				newG[i].clear();
				Arrays.fill(oldG[i], 1000000);
//				Arrays.fill(newG[i], 1000000);
			}

			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(in.readLine());
				o = Integer.parseInt(st.nextToken()) - 1;
				while (st.hasMoreTokens()) {
					d = Integer.parseInt(st.nextToken()) - 1;
//					oldG[o].add(d);
					oldG[o][d] = 1;
				}
			}

			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(in.readLine());
				o = Integer.parseInt(st.nextToken()) - 1;
				while (st.hasMoreTokens()) {
					d = Integer.parseInt(st.nextToken()) - 1;
					newG[o].add(d);
//					newG[o][d]=1;
				}
			}

			floydWarshall(oldG, oldMady);
//			floydWarshall(newG,newMady);

			for (int i = 0; i < n; i++) {
//				dijkstra(oldG, oldMady, i);
				dijkstra(newG, newMady, i);
			}

//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < oldMady[i].length; j++) {
//					System.out.print(oldMady[i][j] + " ");
//				}
//				System.out.println();
//			}
//			System.out.println("---------");
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < newMady[i].length; j++) {
//					System.out.print(newMady[i][j] + " ");
//				}
//				System.out.println();
//			}

			st = new StringTokenizer(in.readLine());
			A = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());

			done = true;
			loop: for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					if (i != j) {
						if (newMady[i][j] > (oldMady[i][j] * A + B))
							done = false;
					}
					if (!done)
						break loop;

				}

			out.println(done ? "Yes" : "No");

		}
		out.close();
	}

	public static void dijkstra(ArrayList<Integer> lAdy[], int[][] mAdy, int v) {
		boolean visitados[] = new boolean[n];
		PriorityQueue<int[]> cola = new PriorityQueue<int[]>(n, new Comparator<int[]>() {
			public int compare(int[] o1, int[] o2) {
				return o1[1] != o2[1] ? (o1[1] < o2[1] ? -1 : 1) : o1[0] - o2[0];
			}
		});
		Arrays.fill(mAdy[v], INF);
		mAdy[v][v] = 0;
		visitados[v] = true;
		cola.add(new int[] { v, 0 });
		for (; !cola.isEmpty();) {
			int[] ult = cola.poll();
			visitados[(int) ult[0]] = true;
			for (int u : lAdy[(int) ult[0]])
				if (!visitados[u] && mAdy[v][u] > mAdy[v][ult[0]] + 1) {
					cola.add(new int[] { u, mAdy[v][u] = mAdy[v][ult[0]] + 1 });
				}

		}
	}

	public static void floydWarshall(int[][] mAdy, int[][] res) {
		int N = n;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				res[i][j] = mAdy[i][j];
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					if (res[i][k] < INF && res[k][j] < INF)
						res[i][j] = Math.min(res[i][j], res[i][k] + res[k][j]);

	}

}

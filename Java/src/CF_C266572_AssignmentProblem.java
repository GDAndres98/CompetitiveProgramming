import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class CF_C266572_AssignmentProblem {
	public static int n;
	public static double tabla[][] = new double[310][310];

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer st;
		n = Integer.parseInt(in.readLine());
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < n; j++) {
				tabla[i][j] = Double.parseDouble(st.nextToken());
			}
		}
		
		asignacion(tabla, n, n);

		out.close();
	}

	static double asignacion(double tabla[][], int filas, int columnas) {
		double[][] copy = new double[filas + 1][columnas + 1];
		for (int i = 0; i < filas; i++)
			for (int j = 0; j < columnas; j++)
				copy[i + 1][j + 1] = tabla[i][j];

		double[] u = new double[filas + 1], v = new double[columnas + 1], minv = new double[columnas + 1];
		int[] p = new int[columnas + 1], camino = new int[columnas + 1];
		boolean vis[] = new boolean[columnas + 1];
		for (int i = 1; i <= filas; i++) {
			Arrays.fill(minv, Double.POSITIVE_INFINITY);
			Arrays.fill(vis, false);
			p[0] = i;
			int J = 0;
			for (;;) {
				vis[J] = true;
				int i0 = p[J];
				double delta = Double.POSITIVE_INFINITY;
				int I = 0;
				for (int j = 1; j <= columnas; j++)
					if (!vis[j]) {
						double cur = copy[i0][j] - u[i0] - v[j];
						if (cur < minv[j]) {
							minv[j] = cur;
							camino[j] = J;
						}
						if (minv[j] < delta) {
							delta = minv[j];
							I = j;
						}
					}
				for (int j = 0; j <= columnas; j++) {
					if (vis[j]) {
						u[p[j]] += delta;
						v[j] -= delta;
					} else
						minv[j] -= delta;
				}

				J = I;
				if (p[J] == 0)
					break;

			}
			for (;;) {
				int I = camino[J];
				p[J] = p[I];
				J = I;
				if (J == 0)
					break;

			}
		}
		System.out.println((long)-v[0]);
		int sol[] = new int[filas + 1];
		
		for (int i = 1; i < p.length; i++) {
			if (p[i] != 0) {
				sol[p[i]] = i;
				System.out.println(p[i] + " " + i);
			}

		}
		return -v[0];
	}
}

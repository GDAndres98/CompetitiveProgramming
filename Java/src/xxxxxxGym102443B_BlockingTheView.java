import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class xxxxxxGym102443B_BlockingTheView {
	public static int[][] a = new int[2][2];
	public static int[][] b = new int[2][2];
	public static int[] v = new int[2];

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer st;
		int n = Integer.parseInt(in.readLine());

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(in.readLine());
			a[0][0] = Integer.parseInt(st.nextToken());
			a[0][1] = Integer.parseInt(st.nextToken());
			a[1][0] = Integer.parseInt(st.nextToken());
			a[1][1] = Integer.parseInt(st.nextToken());
			sortLinePoints(a);	

			b[0][0] = Integer.parseInt(st.nextToken());
			b[0][1] = Integer.parseInt(st.nextToken());
			b[1][0] = Integer.parseInt(st.nextToken());
			b[1][1] = Integer.parseInt(st.nextToken());
			sortLinePoints(b);

			System.out.println(
					Arrays.toString(intLineas(a[0][0], a[0][1], a[1][0], a[1][1], b[0][0], b[0][1], b[1][0], b[1][1])));

			v[0] = Integer.parseInt(st.nextToken());
			v[1] = Integer.parseInt(st.nextToken());

		}

		out.close();
	}

	public static void sortLinePoints(int[][] arr) {
		Arrays.sort(arr, (x, y) -> {
			if (x[0] == y[0])
				return Integer.compare(x[1], y[1]);
			return Integer.compare(x[0], y[0]);
		});
	}

	public static double[] intLineas(double x1, double y1, double x2, double y2, double x3, double y3, double x4,
			double y4) {
		double xa = x2 - x1, xb = x4 - x3, xc = x1 - x3, ya = y2 - y1, yb = y4 - y3, yc = y1 - y3,
				d = yb * xa - xb * ya, n = xb * yc - yb * xc;
		return Math.abs(d) < 1e-11 ? null : new double[] { x1 + xa * n / d, y1 + ya * n / d };
	}

	public static double[] intSegmentos(double x1, double y1, double x2, double y2, double x3, double y3, double x4,
			double y4) { // No se sobrelapan
		double[] p1 = { x1, y1 }, p2 = { x2, y2 }, p3 = { x3, y3 }, p4 = { x4, y4 }, p12[] = { p1, p2 },
				p34[] = { p3, p4 };
		for (double[] p : p12)
			if (distPS(p3, p4, p) < 1e-11)
				return p;
		for (double[] p : p34)
			if (distPS(p1, p2, p) < 1e-11)
				return p;
		double[] p = intLineas(x1, y1, x2, y2, x3, y3, x4, y4);
		return p != null && distPS(p1, p2, p) < 1e-11 && distPS(p3, p4, p) < 1e-11 ? p : null;
	}

	public static double distPS(double[] p1, double[] p2, double[] p) {
		double dP = ds(p1, p2), d1 = ds(p1, p), d2 = ds(p2, p);
		return (d2 + dP < d1 || d1 + dP < d2) ? Math.sqrt(Math.min(d1, d2)) : distPL(p1, p2, p);
	}

	public static double distPL(double[] p1, double[] p2, double[] p) {
		return Math.abs((p2[0] - p1[0]) * (p1[1] - p[1]) - (p2[1] - p1[1]) * (p1[0] - p[0])) / Math.sqrt(ds(p1, p2));
	}

	public static double ds(double[] a, double[] b) {
		return (b[0] - a[0]) * (b[0] - a[0]) + (b[1] - a[1]) * (b[1] - a[1]);
	}
}

/*
 * 3 0 0 5 5 0 1 5 1 1 1 0 0 5 5 1 1 2 2 3 3 0 2 1 1 2 2 3 1 -1 -1
 */

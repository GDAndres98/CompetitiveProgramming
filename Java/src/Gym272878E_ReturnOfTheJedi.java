import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class Gym272878E_ReturnOfTheJedi{
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(System.out);
	private static int n;
	private static double k;
	private static double[] s;
	private static double[] r;

	public static void main(String[] args) throws NumberFormatException, IOException {
		int t = Integer.parseInt(in.readLine());
		StringTokenizer st;
		s = new double[100005];
		r = new double[100005];
		while (t-- > 0) {
			st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
			k = Double.parseDouble(st.nextToken());

			double left = Double.MAX_VALUE;
			double right = Double.MIN_VALUE;

			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < n; i++) {
				s[i] = Double.parseDouble(st.nextToken());
				left = Math.min(s[i], left);
				right = Math.max(s[i], right);
			}

			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < n; i++)
				r[i] = Double.parseDouble(st.nextToken());

			double leftCalc = calcTime(left);
			double rightCalc = calcTime(right);
			double m;

			while (Math.abs(left - right) > 10e-7) {
				double mid1 = left + (right - left) / 3;
				double mid2 = right - (right - left) / 3;
				double mid1c = calcTime(mid1);
				double mid2c = calcTime(mid2);
				if (mid1c < mid2c) {
					right = mid2;
					rightCalc = mid2c;
				} else {
					left = mid1;
					leftCalc = mid1c;
				}
			}
			out.printf(Locale.US, "%.4f\n",leftCalc);
			if(leftCalc<k) {
				out.println("May the Force be with you");
			}
			else
				out.println("It's a trap!");
			
			
			

		}

		out.close();
	}

	public static double calcTime(double x) {
		double y = 0;

		for (int i = 0; i < n; i++)
			y += Math.abs(x - s[i]) * r[i];

		return y;
	}

}

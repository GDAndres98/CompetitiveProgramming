import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class CF_B151_PhoneNumbers {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		int m, n = Integer.parseInt(in.readLine());
		StringTokenizer st;
		String number, names[] = new String[n];
		int[][] taxi, pizza, girl;
		taxi = new int[n][2];
		pizza = new int[n][2];
		girl = new int[n][2];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(in.readLine());
			taxi[i][0] = i;
			pizza[i][0] = i;
			girl[i][0] = i;
			m = Integer.parseInt(st.nextToken());
			names[i] = st.nextToken();

			for (int j = 0; j < m; j++) {
				number = in.readLine().trim().replace("-", "");
				if (isTaxi(number))
					taxi[i][1]++;
				else if (isPizza(number))
					pizza[i][1]++;
				else
					girl[i][1]++;
			}
		}

		Comparator<int[]> comp = new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				if (o1[1] == o2[1])
					return Integer.compare(o1[0], o1[0]);
				else
					return Integer.compare(o2[1], o1[1]);
			}
		};

		Arrays.parallelSort(taxi, comp);
		Arrays.parallelSort(pizza, comp);
		Arrays.parallelSort(girl, comp);

		out.print("If you want to call a taxi, you should call:");
		out.println(printer(taxi, names));
		out.print("If you want to order a pizza, you should call:");
		out.println(printer(pizza, names));
		out.print("If you want to go to a cafe with a wonderful girl, you should call:");
		out.println(printer(girl, names));


		out.flush();
	}

	private static String printer(int[][] arr, String[] names) {
		int max = arr[0][1];
		StringBuilder x = new StringBuilder("");
		for (int i = 0; i < arr.length; i++) {
			if (max == arr[i][1])
				x.append(" " + names[arr[i][0]] + ",");
			else
				break;
		}
		x.replace(x.length() - 1, x.length(), ".");
		return x.toString();

	}

	private static boolean isPizza(String number) {
		for (int i = 1; i < number.length(); i++)
			if (number.charAt(i - 1) <= number.charAt(i))
				return false;
		return true;
	}

	private static boolean isTaxi(String number) {
		char a = number.charAt(0);
		for (int i = 1; i < number.length(); i++)
			if (number.charAt(i) != a)
				return false;
		return true;
	}
}

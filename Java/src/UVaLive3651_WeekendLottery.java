import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class UVaLive3651_WeekendLottery {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		int N, C, K, arr[][];
		StringTokenizer st;
		while (true) {
			st = new StringTokenizer(in.readLine());
			N = Integer.parseInt(st.nextToken());
			if (N == 0)
				break;
			C = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			arr = new int[K][2];
			for (int i = 0; i < K; i++)
				arr[i][1] = i + 1;

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(in.readLine());
				for (int j = 0; j < C; j++)
					arr[Integer.parseInt(st.nextToken()) - 1][0]++;
			}

			Arrays.sort(arr, (x, y) -> {
				if (x[0] != y[0])
					return Integer.compare(x[0], y[0]);
				else
					return Integer.compare(x[1], y[1]);
			});

			out.print(arr[0][1]);
			for (int i = 1; i < arr.length; i++) {
				if (arr[i][0] == arr[0][0])
					out.print(" " + arr[i][1]);
				else
					break;
			}
			out.println();
		}

		out.close();
	}
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class UVa1219_TeamArrangement {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		String players[][] = new String[110][2];
		char[] formationC = new char[] { 'G', 'D', 'M', 'S' };
		int[] formationI = new int[4];
		ArrayList<Integer>[] selection = new ArrayList[4];
		int all[][], cap, xd;

		for (int i = 0; i < selection.length; i++)
			selection[i] = new ArrayList<Integer>();

		StringTokenizer st, st2;
		cap = -2;
		loop: while (true) {

			all = new int[22][2];
			formationI[0] = 1;
			for (int i = 0; i < selection.length; i++)
				selection[i].clear();

			for (int i = 0; i < 22; i++) {
				st = new StringTokenizer(in.readLine());
				if (st.countTokens() == 1)
					break loop;
				all[i][0] = Integer.parseInt(st.nextToken());
				players[all[i][0]][0] = st.nextToken();
				players[all[i][0]][1] = st.nextToken();
				while (st.hasMoreTokens()) {
					st2 = new StringTokenizer(st.nextToken(), "-");
					all[i][1] += 1 - Integer.parseInt(st2.nextToken()) + Integer.parseInt(st2.nextToken());
				}
			}


			st = new StringTokenizer(in.readLine(), "-");
			for (int i = 1; i < formationI.length; i++)
				formationI[i] = Integer.parseInt(st.nextToken());

			Arrays.sort(all, (x, y) -> {
				if (x[0] != y[0])
					return -Integer.compare(y[0], x[0]);
				else
					return Integer.compare(y[1], x[1]);
			});

//			for (int i = 0; i < all.length; i++) {
//				System.out.println(all[i][0] + " " + all[i][1]);
//			}

			cap = -1;
			xd = -1;
			for (int i = 0; i < all.length; i++) {
				for (int j = 0; j < formationC.length; j++)
					if (players[all[i][0]][1].charAt(0) == formationC[j])
						xd = j;
				if (formationI[xd] > 0) {
					if (cap < 0)
						cap = i;
					if (all[cap][1] < all[i][1] || (all[cap][1] == all[i][1]&& all[cap][0] < all[i][0])) {
						cap = i;
					}

					selection[xd].add(all[i][0]);
					formationI[xd]--;
				}
			}
			

			if (cap == -1 || SumAll(formationI) > 0) {
				out.println("IMPOSSIBLE TO ARRANGE");
			} else {
				cap = all[cap][0];
				out.printf("%d %s %s\n", cap, players[cap][0], players[cap][1]);
				for (int i = 0; i < selection.length; i++) {
					for (int j = 0; j < selection[i].size(); j++) {
						if(cap!=selection[i].get(j))
						out.printf("%d %s %s\n", selection[i].get(j), players[selection[i].get(j)][0],
								players[selection[i].get(j)][1]);
					}
				}

			}
			out.println();

		}
		out.close();
	}

	private static int SumAll(int[] formationI) {
		int sum = 0;
		for (int i = 0; i < formationI.length; i++) {
			sum += formationI[i];
		}
		return sum;
	}

}

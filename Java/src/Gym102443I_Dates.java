import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Gym102443I_Dates {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer st;
		int n = Integer.parseInt(in.readLine());
		for (int i = 0; i < n; i++) {
			int d,m,y;
			String x = in.readLine();
			if(x.contains(".")) {
				st = new StringTokenizer(x,".");
				d = Integer.parseInt(st.nextToken());
				m = Integer.parseInt(st.nextToken());
				y = Integer.parseInt(st.nextToken());
			}
			else {
				st = new StringTokenizer(x,"/");
				m = Integer.parseInt(st.nextToken());
				d = Integer.parseInt(st.nextToken());
				y = Integer.parseInt(st.nextToken());
			}
			
			out.printf("%02d.%02d.%04d %02d/%02d/%04d\n",d,m,y,m,d,y);
		}
		
		

		out.close();
	}
}

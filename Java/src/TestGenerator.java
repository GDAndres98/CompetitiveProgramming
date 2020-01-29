import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;

public class TestGenerator {
	public static void main(String[] args) throws FileNotFoundException {
		PrintWriter out = new PrintWriter(new File("case.txt"));
		int n = 999999;
		out.println(n);
		for (int i = 1; i < n; i++) {
			out.print(i+" ");
		}
		out.println();
		for (int i = 1; i <= n; i++) {
			out.print(i+" ");
		}
		out.println();
		out.close();

	}
}

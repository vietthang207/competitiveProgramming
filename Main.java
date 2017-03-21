import java.util.*;
import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.lang.Integer;

public class Main{
	static final BigInteger zero = new BigInteger("0");
	static final BigInteger one = new BigInteger("1");
	static final BigInteger two = new BigInteger("2");
	static final BigInteger minus1 = new BigInteger("-1");

	public static void main (String[] args){
		Scanner sc = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		public InputReader(InputStream st) {
			reader = new BufferedReader(new InputStreamReader(st), 32768);
			tokenizer = null;
		}
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}
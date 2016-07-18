import java.util.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.lang.Integer;
import java.util.Scanner;

public class Uva787{

	public static void main (String[] args){
		Scanner sc = new Scanner(System.in);

		ArrayList<Integer> a = new ArrayList<Integer>();
		while (sc.hasNext()){
			int tmp = sc.nextInt();
			//System.out.println(tmp);
			if (tmp == -999999){

				int n = a.size();
				BigInteger[] bi = new BigInteger[a.size()];
				bi[0] = BigInteger.valueOf(a.get(0));
				for (int i=1; i<n; i++){
					if (!bi[i-1].equals(BigInteger.ZERO)){
						bi[i] = bi[i-1].multiply(BigInteger.valueOf(a.get(i)));
					}
					else {
						bi[i] = BigInteger.valueOf(a.get(i));
					}
				//	System.out.println(bi[i]);
				}
				
				int s = 0, e = a.size();
				int cur = 0;
				BigInteger res = BigInteger.valueOf(-999999);
				
				for (int i=0; i<n; i++){
				//	System.out.println(i+" "+res);
					if (bi[i].compareTo(res)>0) res = bi[i];
					if (a.get(i)==0) continue;

					for (int j=i+1; j<n; j++){
						if (a.get(j)==0){
							i = j+1;
							j = i;
							if (res.compareTo(BigInteger.ZERO)<0) res = BigInteger.ZERO;
						}
						else {
							BigInteger tmpB = bi[j].divide(bi[i]);
							if (tmpB.compareTo(res)>0) {
								res = tmpB;
							}
						}
					}
				//	System.out.println(i+" "+res);
				}
				

				System.out.println(res);
				a.clear();
			}
			else {
				a.add(tmp);
			}
		}

	}
}
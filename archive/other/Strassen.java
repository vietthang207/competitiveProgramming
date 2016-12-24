import java.io.*;
import java.math.*;
import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[][] A = new long[N][N];
        long[][] B = new long[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = sc.nextInt();
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                B[i][j] = sc.nextInt();
            }
        }

        // long[][] C = strassen(N, A, B);
        // long total = 0;
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) {
        //         total += C[i][j];
        //     }
        // }
        System.out.println(strassen(N, A, B));
    }

    public static void add(int size, long[][] a, long[][] b, long[][] c){
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                c[i][j] = a[i][j] + b[i][j];
            }
        }
    }

    public static void sub(int size, long[][] a, long[][] b, long[][] c){
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                c[i][j] = a[i][j] - b[i][j];
            }
        }
    }
	
	public static void cpy(int size, long[][] a, int x, int y, long[][] b){
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                b[i][j] = a[i+x][j+y];
            }
        }
    }

    public static long strassen(int n, long[][] a, long[][] e){
    // if (size == 512) return naive_strassen(size, m1, m2);
    // cout<<n<<" "<<a[0][0]<<" "<<e[0][0]<<endl;
        if (n==1) return a[0][0]*e[0][0];
        
        long[][] tmp1 = new long[n/2][n/2];
        long[][] tmp2 = new long[n/2][n/2];
        long[][] tmp3 = new long[n/2][n/2];
        long p1, p2, p3, p4, p5, p6, p7;

        cpy(n/2, e, 0, n/2, tmp1);	//f
        cpy(n/2, e, n/2, n/2, tmp2);	//h
        sub(n/2, tmp1, tmp2, tmp3);	//f-h
        p1 = strassen(n/2, a, tmp3);	//a(f-h)

		cpy(n/2, a, n/2, n/2, tmp1);	//d
		cpy(n/2, e, n/2, 0, tmp2);	//g
        sub(n/2, tmp2, e, tmp3);	//g-e
        p4 = strassen(n/2, tmp1, tmp3);	//d(g-e)

		cpy(n/2, a, n/2, n/2, tmp1);	//d
        add(n/2, a, tmp1, tmp1);	//a+d
        cpy(n/2, e, n/2, n/2, tmp2);	//h
        add(n/2, e, tmp2, tmp2);	//e+h
        p5 = strassen(n/2, tmp1, tmp2);	//(a+d)(e+h)

		cpy(n/2, a, 0, n/2, tmp1);	//b
        cpy(n/2, a, n/2, n/2, tmp2);	//d
        sub(n/2, tmp1, tmp2, tmp1);	//b-d
        cpy(n/2, e, n/2, 0, tmp2);	//g
        cpy(n/2, e, n/2, n/2, tmp3);	//h
        add(n/2, tmp2, tmp3, tmp2);	//g+h
        p6 = strassen(n/2, tmp1, tmp2);	//(b-d)(g+h)

		cpy(n/2, a, n/2, 0, tmp1);	//c
		sub(n/2, a, tmp1, tmp1);	//(a-c)
        cpy(n/2, e, 0, n/2, tmp2);	//f
        add(n/2, e, tmp2, tmp2);	//e+f
        p7 = strassen(n/2, tmp1, tmp2);	//(a-c)(e+f)
    // cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<" "<<p5<<" "<<p6<<" "<<p7<<endl;

    // add(n/2, a, b, aAddb);
    // add(n/2, c, d, cAddd);
    // p2 = strassen(n/2, aAddb, h);
    // p3 = strassen(n/2, cAddd, e);

        return 2*p1 + 2*p4 + 2*p5 + p6 -p7;
    }
}

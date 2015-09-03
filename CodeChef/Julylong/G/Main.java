import java.io.*;
import java.util.*;
import java.math.BigDecimal; 
 
public class Main{
   public static void main(String[] args) {
      MyScanner sc = new MyScanner();
      out = new PrintWriter(new BufferedOutputStream(System.out));
      
      // Start writing your solution here. -------------------------------------
   
      /*
      int n      = sc.nextInt();        // read input as integer
      long k     = sc.nextLong();       // read input as long
      double d   = sc.nextDouble();     // read input as double
      String str = sc.next();           // read input as String
      String s   = sc.nextLine();       // read whole line as String

      int result = 3*n;
      out.println(result);                    // print via PrintWriter
      */

      // Stop writing your solution here. -------------------------------------
      int n,m,t;
      
      BigDecimal zero=new BigDecimal(0.000000);
      BigDecimal product,bd;
      double temp,prod=1,num=0,denom=0;
      t=sc.nextInt();
      for(int Tt=1;Tt<=t;Tt++)
      {
      	n=sc.nextInt();
      	m=sc.nextInt();
      	denom=0.000000;
      	if(n<=4 && m<=4)
      	{
      		// out.println("Hello");
      		for(int i=1;i<=n;i++)
      		{
      			prod=1.000000;
      			for(int j=1;j<=m;j++)
      			{
      				temp=sc.nextDouble();
      				prod*=temp;
      			}
      			if(i==1)
      				num=prod;
      			denom+=prod;
      		}
      		if(num==0)
      			out.println("0.000000");
      		else
      			out.println(num/denom);
      		continue;
      	}
      	BigDecimal numerator=new BigDecimal(1.000000);
      	BigDecimal denominator=new BigDecimal(0.000000);	
      	for(int i=1;i<=n;i++)
      	{
      		product=BigDecimal.valueOf(1.000000);
      		for(int j=1;j<=m;j++)
      		{
      			temp=sc.nextDouble();
      			bd=BigDecimal.valueOf(temp);
      			product=product.multiply(bd);
      		}
      		if(i==1)
      			numerator=product;
      		denominator=denominator.add(product);
      	}
      	if(numerator.equals(zero))
      	{
      		out.println("0.000000");
      	}
      	else
      	{
      		numerator=numerator.divide(denominator,10,BigDecimal.ROUND_HALF_UP);
      		out.println(numerator);
      	}
      }	 
      out.close();
   }

     

   //-----------PrintWriter for faster output---------------------------------
   public static PrintWriter out;
      
   //-----------MyScanner class for faster input----------
   public static class MyScanner {
      BufferedReader br;
      StringTokenizer st;
 
      public MyScanner() {
         br = new BufferedReader(new InputStreamReader(System.in));
      }
 
      String next() {
          while (st == null || !st.hasMoreElements()) {
              try {
                  st = new StringTokenizer(br.readLine());
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
 
      int nextInt() {
          return Integer.parseInt(next());
      }
 
      long nextLong() {
          return Long.parseLong(next());
      }
 
      double nextDouble() {
          return Double.parseDouble(next());
      }
 
      String nextLine(){
          String str = "";
	  try {
	     str = br.readLine();
	  } catch (IOException e) {
	     e.printStackTrace();
	  }
	  return str;
      }

   }
   //--------------------------------------------------------
}
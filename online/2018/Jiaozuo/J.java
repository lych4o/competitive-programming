import java.math.*;
import java.io.*; 
import java.util.*;

public class Main {
	public static void main(String[]args){
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        while(T-->0){
            int f1 = 0,f2 = 0;


            String a = in.next();
            BigDecimal la;
            BigDecimal b = new BigDecimal(a);
            BigInteger c = new BigInteger(a);     
            
            for(int i = 0; (i++) < 6;){
                if(b.compareTo(BigDecimal.ZERO) == 0)break;
                la = b;
                b = b.subtract((b.multiply(b).subtract(new BigDecimal(a))).divide(new BigDecimal("2").multiply(b),100,BigDecimal.ROUND_HALF_EVEN));
                if(la.subtract(b).doubleValue() < 1e-10)break;
            }

            BigInteger tmp = b.toBigInteger();
            if(tmp.multiply(tmp).compareTo(c) != 0)f1 = 1;



            c = c.multiply(c.subtract(BigInteger.ONE)).divide(new BigInteger("2"));
            b = new BigDecimal(a);
            b = b.multiply(b.subtract(BigDecimal.ONE)).divide(new BigDecimal("2"));
            a = c.toString();

            for(int i = 0; (i++) < 6;){
                if(b.compareTo(BigDecimal.ZERO) == 0)break;
                la = b;
                b = b.subtract((b.multiply(b).subtract(new BigDecimal(a))).divide(new BigDecimal("2").multiply(b),100,BigDecimal.ROUND_HALF_EVEN));
                if(la.subtract(b).doubleValue() < 1e-10)break;
            }
            
            tmp = b.toBigInteger();
            if(tmp.multiply(tmp).compareTo(c) != 0)f2 = 1;



            if(f1 == 0 && f2 == 0)System.out.println("Arena of Valor");
            if(f1 == 0 && f2 == 1)System.out.println("Hearth Stone");
            if(f1 == 1 && f2 == 0)System.out.println("Clash Royale");
            if(f1 == 1 && f2 == 1)System.out.println("League of Legends");
        }

        in.close();
    }
}

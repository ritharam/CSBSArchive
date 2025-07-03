import java.io.*;
import java.net.*;
import java.util.Scanner;
class CRCSend{
	public static void main (String[] args){
	try{
        Scanner scn = new Scanner(System.in);
        System.out.print("Enter the Number of Data Bits :");
        int data_bit = scn.nextInt();
        int[] data = new int[data_bit];
        System.out.println("Enter the Data bits Below");
        for(int i=0;i<data_bit;i++){
            data[i] = scn.nextInt();
        }
        System.out.print("Enter the Number of Divisor Bits :");
        int div_bit = scn.nextInt();
        int[] divisor = new int[div_bit];
        System.out.println("Enter the Divisor bits Below");
        for(int i=0;i<div_bit;i++){
            divisor[i] = scn.nextInt();
        }
        int tot_len = data_bit + div_bit - 1;
        int[] div = new int[tot_len];
        int[] rem = new int[tot_len];
        int[] crc = new int[tot_len];
        for(int i=0;i<data_bit;i++)
        {   div[i] = data[i]; 
            rem[i] = data[i];}
        System.out.print("Dividend after adding 0's :");
        for(int i=0;i<tot_len;i++){System.out.print(div[i]);}
        
        rem = divide(rem,divisor);

        System.out.print("\nThe Generated CRC :");
        for(int i=0;i<tot_len;i++)
        {   crc[i]=(div[i]^rem[i]);
            System.out.print(crc[i]);}
        
        Socket s = new Socket("192.168.1.33",1000);
        PrintStream ps = new PrintStream(s.getOutputStream());
        char[] chars = new char[crc.length];
        for (int i = 0; i < crc.length; i++) {
                chars[i] = (char)(crc[i] + '0');
        }
        String x = new String(chars);
        ps.println(x);
        char[] chars2 = new char[divisor.length];
        for (int i = 0; i < divisor.length; i++) {
                chars2[i] = (char)(divisor[i] + '0');
        }
        x = new String(chars2);
        ps.println(x);
        System.out.println("\nCRC and Divisor Sent Successfully");
	}
	catch(Exception e){System.out.println(e);}
	}
	static int[] divide(int[] rem, int[] divisor){
		int cur = 0;
		while(true){
			for(int i=0;i<divisor.length;i++){
				rem[cur+i] = (rem[cur+i]^divisor[i]);
			}
			while(rem[cur]==0 && cur!=rem.length-1){
                cur++;
            }
			if(rem.length-cur < divisor.length){
                break;
            }
		}
		return rem;
	}
}
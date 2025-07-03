// import java.net.*;
// import java.io.*;
// class TestClient
// {
//     public static void main(String ar[])
//     {
//         try
//         {
//             Socket s=new Socket("192.168.1.116",2000);
//             BufferedReader br=new BufferedReader(new InputStreamReader(s.getInputStream()));
//             String s1=br.readLine();
//             System.out.println(s1);
       
//             PrintStream pr=new PrintStream(s.getOutputStream());
//             pr.println("Thank u");
//         }
//         catch(Exception e)
//         {
//             System.out.println(e);
//         }
       
//     }
// }

import java.net.*;
import java.io.*;
import java.util.Scanner;

class TestClient {
    public static void main(String[] ar) {
        try {
            Socket s = new Socket("192.168.1.116", 2000); 
            BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            PrintStream pr = new PrintStream(s.getOutputStream());
            Scanner scanner = new Scanner(System.in);

            while (true) {
                System.out.print("Client: ");
                String cm = scanner.nextLine();
                pr.println(cm);

                if (cm.equalsIgnoreCase("exit")) {
                    System.out.println("Client ended the chat.");
                    break;
                }
                String sm = br.readLine();
                if (sm == null || sm.equalsIgnoreCase("exit")) {
                    System.out.println("Server disconnected.");
                    break;
                }
                System.out.println("Server: " + sm);
            }
            s.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
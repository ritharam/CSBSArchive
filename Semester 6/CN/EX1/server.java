// import java.net.*;
// import java.io.*;
// class TestServer
// {
//     public static void main(String ar[])
//     {
//         try
//         {
//             ServerSocket ss=new ServerSocket(2000);    
//             System.out.println("\n Waiting...");
//             Socket s=ss.accept();
//             System.out.println("\n Connection Established");
//             PrintStream pr=new PrintStream(s.getOutputStream());
//             pr.println("Welcome");
//             BufferedReader br=new BufferedReader(new InputStreamReader(s.getInputStream()));
//             String s1=br.readLine();
//             System.out.println(s1);
//             Thread.sleep(10000);
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

class TestServer {
    public static void main(String[] ar) {
        try {
            ServerSocket ss = new ServerSocket(2000);
            System.out.println("\n Waiting...");
            Socket s = ss.accept();
            System.out.println("\n Connection Established");

            BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            PrintStream pr = new PrintStream(s.getOutputStream());
            Scanner scanner = new Scanner(System.in);

            while (true) {
                String cm = br.readLine();
                if (cm == null || cm.equalsIgnoreCase("exit")) {
                    System.out.println("Client disconnected.");
                    break;
                }
                System.out.println("Client: " + cm);

                System.out.print("Server: ");
                String sm = scanner.nextLine();
                pr.println(sm);

                if (sm.equalsIgnoreCase("exit")) {
                    System.out.println("Server ended the chat.");
                    break;
                }
            }
            ss.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

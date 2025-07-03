import java.io.*;
import java.net.*;

class CRCReceive {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(1000);
            System.out.println("Waiting for CRC data...");
            Socket s = ss.accept();
            System.out.println("Connection Established!");

            BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            String crc_s = br.readLine();
            String divisor_s = br.readLine();
            System.out.println("Received CRC: " + crc_s);
            System.out.println("Received Divisor: " + divisor_s);

            int[] crc = new int[crc_s.length()];
            char[] crc_chars = crc_s.toCharArray();
            for (int i = 0; i < crc_chars.length; i++) {
                crc[i] = crc_chars[i] - '0';
            }

            int[] divisor = new int[divisor_s.length()];
            char[] divisor_chars = divisor_s.toCharArray();
            for (int i = 0; i < divisor_chars.length; i++) {
                divisor[i] = divisor_chars[i] - '0';
            }

            int[] rem = new int[crc.length];
            for (int i = 0; i < crc.length; i++) {
                rem[i] = crc[i];
            }

            rem = divide(rem, divisor);
            boolean flag = true;
            for (int i = 0; i < rem.length; i++) {
                if (rem[i] != 0) {
                    flag = false;
                    System.out.println("Error detected in CRC data");
                    break;
                }
            }

            if (flag) {
                System.out.println("No ERROR in the received data.");
            }

            ss.close();
            s.close();
        } catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }

    static int[] divide(int[] rem, int[] divisor) {
        int cur = 0;
        while (true) {
            for (int i = 0; i < divisor.length; i++) {
                rem[cur + i] = rem[cur + i] ^ divisor[i];
            }
            while (rem[cur] == 0 && cur != rem.length - 1) {
                cur++;
            }
            if (rem.length - cur < divisor.length) {
                break;
            }
        }
        return rem;
    }
}

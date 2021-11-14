import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int test_case = Integer.parseInt(br.readLine().trim());

        while (test_case-- > 0) {
            int car_price = Integer.parseInt(br.readLine().trim());

            int options = Integer.parseInt(br.readLine().trim());
            while (options-- > 0) {
                st = new StringTokenizer(br.readLine().trim());
                int option_num = Integer.parseInt(st.nextToken());
                int option_price = Integer.parseInt(st.nextToken());

                car_price += option_num * option_price;
            }
            System.out.println(car_price);
        }

        br.close();
    }
}
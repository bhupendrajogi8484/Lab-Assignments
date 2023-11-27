public class assignment2 {
    static boolean isPrime(int num) {
        int flag = 0;
        for (int i = 2; i < num; i++)
            if (num % i == 0) {
                flag = 1;
                break;
            }
        return flag == 0;
    }

    static <T> void count(String type, T[] elements) {
        int even = 0, odd = 0, prime = 0, palin = 0;
        if (type.equals("even")) {
            for (T value : elements)
                if (Integer.parseInt(value.toString()) % 2 == 0)
                    even++;
            System.out.println("Total Even: " + even);
        }
        if (type.equals("odd")) {
            for (T value : elements)
                if (Integer.parseInt(value.toString()) % 2 != 0)
                    odd++;
            System.out.println("Total Odd: " + odd);
        }
        if (type.equals("prime")) {
            for (T value : elements)
                if (isPrime(Integer.parseInt(value.toString())))
                    prime++;
            System.out.println("Total Prime: " + prime);
        }
        if (type.equals("palindrome")) {
            for (T value : elements) {
                StringBuffer rev = new StringBuffer(value.toString());
                if (value.toString().equals(new String(rev.reverse())))
                    palin++;
            }
            System.out.println("Total Palindrome: " + palin);
        }
    }

    public static void main(String[] args) {
        Integer[] iArray = {45, 7, 12, 84, 38, 115, 29, 30, 19};
        count("even", iArray);

        Byte[] bArray = {45, 7, 12, 84, 38, 115, 29, 30, 19};
        count("even", bArray);

        Short[] sArray = {45, 73, 12, 84, 38, 151, 29, 30, 19};
        count("odd", sArray);

        Long[] lArray = {45L, 73L, 12L, 84L, 38L, 151L, 29L, 30L, 19L};
        count("even", lArray);
        count("prime", lArray);
        count("palindrome", sArray);
    }
}

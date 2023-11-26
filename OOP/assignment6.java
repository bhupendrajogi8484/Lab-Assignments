import java.util.Scanner;

class assignment6 {
    static int a;
    static int b, e;
    static String c, d;
    static int arry[] = {1, 2, 3, 4, 5};

    static void input(int a, int b, String c, String d) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter num1: ");
        c = s.nextLine();
        System.out.println("\nEnter num2: ");
        d = s.nextLine();

        try {
            a = Integer.parseInt(c);
            b = Integer.parseInt(d);
        } catch (NumberFormatException e) {
            System.out.println("Error: The numbers must be Integers\nError: " + e);
        }

        try {
            e = a / b;
            System.out.println("\nDivision is: " + e);
        } catch (ArithmeticException el) {
            System.out.println("\nDivision is: " + e);
            System.out.println("Error: The num2 must not be zero\nError: " + el);
        }
    }

    static void accesselement(int arr[]) {
        Scanner s = new Scanner(System.in);
        System.out.println("\nArray is: [1, 2, 3, 4, 5]");
        System.out.println("Enter index of the element you want to access: ");
        a = s.nextInt();

        try {
            System.out.println("Element is: " + arr[a]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Array only has up to 4 index\nError: " + e);
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n1. Divide num1 and num2 ");
            System.out.println("2. Access array elements ");
            System.out.println("3. Exit \n");
            System.out.println("\nEnter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    input(a, b, c, d);
                    break;
                case 2:
                    accesselement(arry);
                    break;
                case 3:
                    break;
                default:
                    System.out.println("Wrong choice!");
                    break;
            }

            System.out.println("\n");

        } while (choice != 3);
    }
}

import java.util.Scanner;

interface Cart {
    void creditCard();

    void paypal();

    void bitcoin();
}

class CreditCard implements Cart {
    String cardnum, expiry, name, otp, amount;
    int cvv;

    public void creditCard() {
        Scanner sc = new Scanner(System.in);
        System.out.println("\nEnter card holder's name: ");
        name = sc.nextLine();
        System.out.println("\nEnter your card number [12 digit]: ");
        cardnum = sc.nextLine();
        System.out.println("\nEnter your card expiry date: ");
        expiry = sc.next();
        System.out.println("\nEnter your card cvv: ");
        cvv = sc.nextInt();
        System.out.println("\nOTP is sent to registered mobile number, please enter your OTP: ");
        otp = sc.next();
        System.out.println("\nPayment completed successfully!");
    }

    public void paypal() {
    }

    public void bitcoin() {
    }
}

class Bitcoin implements Cart {
    String walletId, password, otp, amount;

    public void creditCard() {
    }

    public void paypal() {
    }

    public void bitcoin() {
        Scanner sc = new Scanner(System.in);
        System.out.println("\nEnter bitcoin wallet id: ");
        walletId = sc.nextLine();
        System.out.println("\nEnter bitcoin wallet password: ");
        password = sc.nextLine();
        System.out.println("\nOTP is sent to registered mobile number, please enter your OTP: ");
        otp = sc.nextLine();
        System.out.println("\nScan above code via your bitcoin wallet\npress enter after you complete payment");
        otp = sc.nextLine();
        System.out.println("\nPayment completed successfully!");
    }
}

class Paypal implements Cart {
    String emailId, password, otp, amount;

    public void creditCard() {
    }

    public void paypal() {
        Scanner sc = new Scanner(System.in);
        System.out.println("\nEnter PayPal account email-id: ");
        emailId = sc.nextLine();
        System.out.println("\nEnter account password: ");
        password = sc.nextLine();
        System.out.println("\nOTP is sent to registered mobile number, please enter your OTP: ");
        otp = sc.nextLine();
        System.out.println("\nPayment completed successfully!");
    }

    public void bitcoin() {
    }
}

public class assignment2 {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int choice;
        do {
            System.out.println("\nThanks for shopping from dvvpEmart! Please choose a payment method to proceed to payment\n");
            System.out.println("1. Credit card ");
            System.out.println("2. Paypal ");
            System.out.println("3. Bitcoin ");
            System.out.println("4. Exit \n");
            System.out.println("\nEnter your choice : ");
            choice = s.nextInt();
            switch (choice) {
                case 1:
                    CreditCard b1 = new CreditCard();
                    b1.creditCard();
                    b1.paypal();
                    b1.bitcoin();
                    System.out.println("\n");
                    break;
                case 2:
                    Paypal b2 = new Paypal();
                    b2.creditCard();
                    b2.paypal();
                    b2.bitcoin();
                    System.out.println("\n");
                    break;
                case 3:
                    Bitcoin b3 = new Bitcoin();
                    b3.creditCard();
                    b3.paypal();
                    b3.bitcoin();
                    System.out.println("\n");
                    break;
                case 4:
                    break;
                default:
                    System.out.println(" Wrong choice !");
                    break;
            }
            System.out.println("\n");
        } while (choice != 4);
    }
}

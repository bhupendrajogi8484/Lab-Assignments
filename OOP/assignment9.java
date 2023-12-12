import java.util.Scanner;

class BankAccount {
    String accountHolder;
    double balance;
    double dailyWithdrawalLimit;

    public BankAccount(String accountHolder, double initialBalance, double dailyWithdrawalLimit) {
        this.accountHolder = accountHolder;
        this.balance = initialBalance;
        this.dailyWithdrawalLimit = dailyWithdrawalLimit;
    }

    public void deposit(double amount) {
        balance += amount;
        System.out.println("Deposited: " + amount);
        displayBalance();
    }

    public void withdraw(double amount) {
        if (amount > dailyWithdrawalLimit) {
            System.out.println("Withdrawal amount exceeds daily limit");
        } else if (amount > balance) {
            System.out.println("Insufficient funds");
        } else {
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
            displayBalance();
        }
    }

    public void displayBalance() {
        System.out.println("Current Balance: " + balance);
    }

    public void displayAccountInformation() {
        System.out.println("Account Information:");
        System.out.println("Account Holder: " + accountHolder);
        displayBalance();
        System.out.println("Daily Withdrawal Limit: " + dailyWithdrawalLimit);
    }
}

public class assignment1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter account holder name: ");
        String accountHolder = scanner.nextLine();

        System.out.print("Enter initial balance: ");
        double initialBalance = scanner.nextDouble();

        System.out.print("Enter daily withdrawal limit: ");
        double dailyWithdrawalLimit = scanner.nextDouble();

        BankAccount userAccount = new BankAccount(accountHolder, initialBalance, dailyWithdrawalLimit);

        System.out.println("\nAccount created successfully!");
        userAccount.displayAccountInformation();

        System.out.println("\nChoose an operation:");
        System.out.println("1. Display Account Information");
        System.out.println("2. Deposit");
        System.out.println("3. Withdraw");
        
        int choice = scanner.nextInt();

        switch (choice) {
            case 1:
                userAccount.displayAccountInformation();
                break;
            case 2:
                System.out.print("Enter deposit amount: ");
                double depositAmount = scanner.nextDouble();
                userAccount.deposit(depositAmount);
                break;
            case 3:
                System.out.print("Enter withdrawal amount: ");
                double withdrawalAmount = scanner.nextDouble();
                userAccount.withdraw(withdrawalAmount);
                break;
            default:
                System.out.println("Invalid choice");
        }
    }
}


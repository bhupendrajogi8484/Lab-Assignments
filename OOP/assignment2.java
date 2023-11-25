import java.util.Scanner;

abstract class Publication {
    String title;

    abstract void display();
}

class Book extends Publication {
    String author;
    int pageCount;
    int copies;
    double price;

    void getBookDetails() {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter title of the book: ");
        title = scanner.nextLine();

        System.out.println("Enter author of the book: ");
        author = scanner.nextLine();

        System.out.println("Enter total number of copies: ");
        copies = scanner.nextInt();

        System.out.println("Enter number of pages: ");
        pageCount = scanner.nextInt();

        System.out.println("Enter price of the book: ");
        price = scanner.nextDouble();
    }

    void display() {
        System.out.println("\n Book Details:");
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Pages: " + pageCount);
        System.out.println("Total price for "+copies+" copies: " + price*copies+"\n");
    }
}

class Magazine extends Publication {
    int issueNumber;
    int copiesSold;
    double price;

    void getMagazineDetails() {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter title of the magazine: ");
        title = scanner.nextLine();

        System.out.println("Enter current issue number: ");
        issueNumber = scanner.nextInt();

        System.out.println("Enter number of copies: ");
        copiesSold = scanner.nextInt();

        System.out.println("Enter price of the magazine: ");
        price = scanner.nextDouble();
    }

    void display() {
        System.out.println("Magazine Details:");
        System.out.println("Title: " + title);
        System.out.println("Issue Number: " + issueNumber);
        System.out.println("Copies Sold: " + copiesSold);
        System.out.println("Total price for "+copiesSold+" copies: " + price*copiesSold+"\n");
    }
}

public class assignment2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("1. Book\n2. Magazine\n3. Exit\n");
        System.out.println("Enter your choice: ");
        int choice = scanner.nextInt();

        switch (choice) {
            case 1:
                Book book = new Book();
                book.getBookDetails();
                book.display();
                break;
            case 2:
                Magazine magazine = new Magazine();
                magazine.getMagazineDetails();
                magazine.display();
                break;
            case 3:
                System.out.println("Exiting...");
                break;
            default:
                System.out.println("Invalid choice");
        }
    }
}



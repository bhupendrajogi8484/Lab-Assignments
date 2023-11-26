import java.util.Scanner;

abstract class Shapes {
    double base, height;

    abstract void input();

    abstract void computeArea();
}

class Triangle extends Shapes {
    void input() {
        Scanner sc = new Scanner(System.in);
        System.out.println("\nEnter the Base of triangle: ");
        base = sc.nextDouble();
        System.out.println("\nEnter the Height of triangle: ");
        height = sc.nextDouble();
    }

    void computeArea() {
        System.out.println("\nArea of triangle is: " + (0.5 * base * height));
    }
}

class Rectangle extends Shapes {
    void input() {
        Scanner sc = new Scanner(System.in);
        System.out.println("\nEnter the Base of Rectangle: ");
        base = sc.nextDouble();
        System.out.println("\nEnter the Height of Rectangle: ");
        height = sc.nextDouble();
    }

    void computeArea() {
        System.out.println("\nArea of Rectangle is: " + (base * height));
    }
}

public class assignment4 {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n1.Triangle ");
            System.out.println("2.Rectangle ");
            System.out.println("3.Exit \n");
            System.out.println("\nEnter your choice : ");
            choice = s.nextInt();

            switch (choice) {
                case 1:
                    Triangle t1 = new Triangle();
                    t1.input();
                    t1.computeArea();
                    System.out.println("\n");
                    break;
                case 2:
                    Rectangle t2 = new Rectangle();
                    t2.input();
                    t2.computeArea();
                    System.out.println("\n");
                    break;
                case 3:
                    break;
                default:
                    System.out.println(" Wrong choice !");
                    break;
            }

        } while (choice != 3);

        System.out.println("\n");
    }
}

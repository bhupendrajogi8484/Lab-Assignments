import java.util.Scanner;

abstract class Car {
    public abstract void arrangeParts();
    public abstract void arrangeChassis();
    public abstract void paintBody();
    public abstract void testVehicle();
}

class Sedan extends Car {
    public void arrangeParts() {
        System.out.println("\nArranged parts of Sedan car");
    }

    public void arrangeChassis() {
        System.out.println("Built chassis of Sedan car");
    }

    public void paintBody() {
        System.out.println("Painted body of Sedan car");
    }

    public void testVehicle() {
        System.out.println("Testing car....");
        System.out.println("Sedan Tests completed and passed successfully... ");
    }
}

class SUV extends Car {
    public void arrangeParts() {
        System.out.println("\nArranged parts of SUV car");
    }

    public void arrangeChassis() {
        System.out.println("Built chassis of SUV car");
    }

    public void paintBody() {
        System.out.println("Painted body of SUV car");
    }

    public void testVehicle() {
        System.out.println("Testing car....");
        System.out.println("SUV Tests completed and passed successfully... ");
    }
}

class Hatchback extends Car {
    public void arrangeParts() {
        System.out.println("\nArranged parts of Hatchback car");
    }

    public void arrangeChassis() {
        System.out.println("Built chassis of Hatchback car");
    }

    public void paintBody() {
        System.out.println("Painted body of Hatchback car");
    }

    public void testVehicle() {
        System.out.println("Testing car....");
        System.out.println("Hatchback Tests completed and passed successfully... ");
    }
}

public class assignment2 {
    static void sedan() {
        Sedan car = new Sedan();
        car.arrangeParts();
        car.arrangeChassis();
        car.paintBody();
        System.out.println("Performing tests...\n");
        car.testVehicle();
    }

    static void suv() {
        SUV car = new SUV();
        car.arrangeParts();
        car.arrangeChassis();
        car.paintBody();
        System.out.println("Performing tests...\n");
        car.testVehicle();
    }

    static void hatchback() {
        Hatchback car = new Hatchback();
        car.arrangeParts();
        car.arrangeChassis();
        car.paintBody();
        System.out.println("Performing tests...\n");
        car.testVehicle();
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n1. Sedan ");
            System.out.println("2. SUV ");
            System.out.println("3. Hatchback ");
            System.out.println("4. Exit \n");
            System.out.println("\nEnter your choice: ");
            choice = s.nextInt();

            switch (choice) {
                case 1:
                    sedan();
                    break;
                case 2:
                    suv();
                    break;
                case 3:
                    hatchback();
                    break;
                case 4:
                    break;
                default:
                    System.out.println("Wrong choice!");
                    break;
            }

            System.out.println("\n");

        } while (choice != 4);
    }
}

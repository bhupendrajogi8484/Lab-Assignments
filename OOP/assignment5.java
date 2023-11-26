import java.util.Scanner;

interface Vehicle {
    void gearChange();
    void speedUp();
    void applyBreaks();
}

class Bicycle implements Vehicle {
    Bicycle() {
        System.out.println("Tring Tring! Bicycle Starts!");
    }

    public void speedUp() {
        System.out.println("Bicycle Speed increased.");
    }

    public void gearChange() {
        System.out.println("Bicycle Gear changed by one.");
    }

    public void applyBreaks() {
        System.out.println("Bicycle stopped!");
    }
}

class Car implements Vehicle {
    Car() {
        System.out.println("Car Starts!");
    }

    public void speedUp() {
        System.out.println("Car Speed increased.");
    }

    public void gearChange() {
        System.out.println("Car Gear changed by one.");
    }

    public void applyBreaks() {
        System.out.println("Car stopped!");
    }
}

class Bike implements Vehicle {
    Bike() {
        System.out.println("Bike Starts!");
    }

    public void speedUp() {
        System.out.println("Bike Speed increased.");
    }

    public void gearChange() {
        System.out.println("Bike Gear changed by one.");
    }

    public void applyBreaks() {
        System.out.println("Bike stopped!");
    }
}

public class assignment5 {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n1.Bike ");
            System.out.println("2.Bicycle ");
            System.out.println("3.Car ");
            System.out.println("4.Exit \n");
            System.out.println("\nEnter your choice: ");
            choice = s.nextInt();

            switch (choice) {
                case 1:
                    Bike b1 = new Bike();
                    b1.applyBreaks();
                    b1.gearChange();
                    b1.speedUp();
                    System.out.println("\n");
                    break;
                case 2:
                    Bicycle bi = new Bicycle();
                    bi.applyBreaks();
                    bi.gearChange();
                    bi.speedUp();
                    System.out.println("\n");
                    break;
                case 3:
                    Car c1 = new Car();
                    c1.speedUp();
                    c1.applyBreaks();
                    c1.gearChange();
                    System.out.println("\n");
                    break;
                case 4:
                    break;
                default:
                    System.out.println(" Wrong choice !");
                    break;
            }

        } while (choice != 4);

        System.out.println("\n");
    }
}

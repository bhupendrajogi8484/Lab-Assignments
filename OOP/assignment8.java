import java.io.*;
import java.util.Scanner;

class Student {
    String studentID, name, studentClass, address;
    int rollNo, marks;
    long telephoneNo;
}

public class StudentRecords {

    static Scanner scanner = new Scanner(System.in);

    public static void addRecord(Student student, PrintWriter pw) throws IOException {
        System.out.print("\nEnter Student ID: ");
        student.studentID = scanner.nextLine();

        System.out.print("Enter Name of Student: ");
        student.name = scanner.nextLine();

        System.out.print("Roll No: ");
        student.rollNo = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Class: ");
        student.studentClass = scanner.nextLine();

        System.out.print("Marks: ");
        student.marks = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Address: ");
        student.address = scanner.nextLine();

        System.out.print("Telephone No.: ");
        student.telephoneNo = scanner.nextLong();
        scanner.nextLine();

        saveRecord(student, pw);

        System.out.print("\nRecord added successfully!\nDo you want to add more records? (y/n): ");
        if (scanner.nextLine().equalsIgnoreCase("y")) {
            addRecord(student, new PrintWriter(new BufferedWriter(new FileWriter("SRecords.txt", true))));
        } else {
            showMenu();
        }
    }

    public static void saveRecord(Student student, PrintWriter pw) {
        pw.println(student.studentID);
        pw.println(student.name);
        pw.println(student.rollNo);
        pw.println(student.studentClass);
        pw.println(student.marks);
        pw.println(student.address);
        pw.println(student.telephoneNo);

        pw.close();
    }

    public static void readRecords(Scanner file) throws IOException {
        int i = 1;

        while (file.hasNextLine()) {
            System.out.println("S.No. : " + (i++));
            System.out.println("-------------");
            System.out.println("\nName: " + file.nextLine());
            System.out.println("Student ID: " + file.nextLine());
            System.out.println("Roll No: " + file.nextLine());
            System.out.println("Class: " + file.nextLine());
            System.out.println("Marks: " + file.nextLine());
            System.out.println("Address: " + file.nextLine());
            System.out.println("Tel. No.: " + Long.parseLong(file.nextLine()));
            System.out.println();
        }

        showMenu();
    }

    public static void clearRecords() throws IOException {
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("SRecords.txt")));
        pw.close();
        System.out.println("\nAll Records cleared successfully!");

        for (int i = 0; i < 999999999; i++) {
        }

        showMenu();
    }

    public static void showMenu() throws IOException {
        System.out.println("1 : Add Record\n2 : Display Records\n3 : Clear All Records\n4 : Exit");

        System.out.print("\nEnter Your Choice: ");
        int choice = scanner.nextInt();
        scanner.nextLine();

        switch (choice) {
            case 1:
                addRecord(new Student(), new PrintWriter(new BufferedWriter(new FileWriter("SRecords.txt", true))));
                break;
            case 2:
                readRecords(new Scanner(new File("SRecords.txt")));
                break;
            case 3:
                clearRecords();
                break;
            case 4:
                System.exit(0);
                break;
            default:
                System.out.println("Invalid Choice!");
                showMenu();
        }
    }

    public static void main(String[] args) throws IOException {
        showMenu();
    }
}

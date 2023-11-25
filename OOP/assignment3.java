import java.util.Scanner;

class Emp {
    String emp_name, emp_id, address, email_id, mobile;
    double salary, bp, da, hra, pf, club, net, gross, basic;

    void getdata() {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the Name of the employee:");
        emp_name = s.nextLine();
        System.out.println("Enter the ID of the employee:");
        emp_id = s.nextLine();
        System.out.println("Enter the Address of the employee:");
        address = s.nextLine();
        System.out.println("Enter the mail id of the employee:");
        email_id = s.nextLine();
        System.out.println("Enter the mobile number of the employee:");
        mobile = s.nextLine();
    }

    void display() {
        System.out.println("\nEmployee Name: " + emp_name);
        System.out.println("Employee id :" + emp_id);
        System.out.println("Employee Address:" + address);
        System.out.println("Employee:" + email_id);
        System.out.println("Employee Mobile:" + mobile + "\n");
    }
}

class Programmer extends Emp {
    void salary() {
        System.out.println("\n # Enter the base pay of the Programmer: ");
        Scanner s = new Scanner(System.in);
        basic = s.nextDouble();
        da = 0.97 * basic;
        hra = 0.10 * basic;
        club = 0.01 * basic;
        pf = 0.12 * basic;
        gross = (bp + da + hra);
        net = (gross - pf - club);
        System.out.println("\n-- -- slip of programmer is\n");
        display();
        System.out.println("Basic pay:" + basic);
        System.out.println("DA :" + da);
        System.out.println("HRA :" + hra);
        System.out.println("PF:" + pf);
        System.out.println("Staff club fund:" + club);
        System.out.println("Gross salary :" + gross);
        System.out.println("Net salary :" + net + "\n");
    }
}

class TeamLeader extends Emp {
    void salary() {
        System.out.println("\n # Enter the base pay of the Team Leader: ");
        Scanner s = new Scanner(System.in);
        basic = s.nextDouble();
        da = 0.97 * basic;
        hra = 0.10 * basic;
        club = 0.01 * basic;
        pf = 0.12 * basic;
        gross = (bp + da + hra);
        net = (gross - pf - club);
        System.out.println("\n-- -- slip of Team Leader is\n");
        display();
        System.out.println("Basic pay:" + basic);
        System.out.println("DA :" + da);
        System.out.println("HRA :" + hra);
        System.out.println("PF:" + pf);
        System.out.println("Staff club fund:" + club);
        System.out.println("Gross salary :" + gross);
        System.out.println("Net salary :" + net + "\n");
    }
}

class AssistantProjectManager extends Emp {
    void salary() {
        System.out.println("\n # Enter the base pay of the Assistant project manager: ");
        Scanner s = new Scanner(System.in);
        basic = s.nextDouble();
        da = 0.97 * basic;
        hra = 0.10 * basic;
        club = 0.01 * basic;
        pf = 0.12 * basic;
        gross = (bp + da + hra);
        net = (gross - pf - club);
        System.out.println("\n-- -- slip of Assistant project manager is\n");
        display();
        System.out.println("Basic pay:" + basic);
        System.out.println("DA :" + da);
        System.out.println("HRA :" + hra);
        System.out.println("PF:" + pf);
        System.out.println("Staff club fund:" + club);
        System.out.println("Gross salary :" + gross);
        System.out.println("Net salary :" + net + "\n");
    }
}

class ProjectManager extends Emp {
    void salary() {
        System.out.println("\n # Enter the base pay of the Project manager: ");
        Scanner s = new Scanner(System.in);
        basic = s.nextDouble();
        da = 0.97 * basic;
        hra = 0.10 * basic;
        club = 0.01 * basic;
        pf = 0.12 * basic;
        gross = (bp + da + hra);
        net = (gross - pf - club);
        System.out.println("\n-- -- slip for Project manager is\n");
        display();
        System.out.println("Basic pay:" + basic);
        System.out.println("DA :" + da);
        System.out.println("HRA :" + hra);
        System.out.println("PF:" + pf);
        System.out.println("Staff club fund:" + club);
        System.out.println("Gross salary :" + gross);
        System.out.println("Net salary :" + net + "\n");
    }
}

public class pAssignment3 {
    public static void main(String[] args) {
        int choice;
        Scanner s = new Scanner(System.in);
        System.out.println("1. For Programmer ");
        System.out.println("2. For Team leader ");
        System.out.println("3. For Assistant project manager ");
        System.out.println("4. For Project manager ");
        System.out.println("\nEnter your choice: ");
        choice = s.nextInt();
        switch (choice) {
            case 1:
                Programmer o1 = new Programmer();
                o1.getdata();
                o1.salary();
                break;
            case 2:
                TeamLeader o2 = new TeamLeader();
                o2.getdata();
                o2.salary();
                break;
            case 3:
                AssistantProjectManager o3 = new AssistantProjectManager();
                o3.getdata();
                o3.salary();
                break;
            case 4:
                ProjectManager o4 = new ProjectManager();
                o4.getdata();
                o4.salary();
                break;
            default:
                System.out.println("Wrong choice ");
        }
    }
}

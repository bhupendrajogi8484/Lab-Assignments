import java.util.Scanner;

class Complex {
    double real, img;

    Complex(double real, double img) {
        this.real = real;
        this.img = img;
    }

    void add(Complex x, Complex y) {
        double realResult = x.real + y.real;
        double imgResult = x.img + y.img;
        System.out.println("\nAddition of " + x.real + "+" + x.img + "i and " + y.real + "+" + y.img + "i is " + realResult + "+" + imgResult + "i");
    }

    void sub(Complex x, Complex y) {
        double realResult = x.real - y.real;
        double imgResult = x.img - y.img;
        System.out.println("\nSubtraction of " + x.real + "+" + x.img + "i and " + y.real + "+" + y.img + "i is " + realResult + "+" + imgResult + "i");
    }

    void mul(Complex x, Complex y) {
        double realResult = x.real * y.real - x.img * y.img;
        double imgResult = x.real * y.img + x.img * y.real;
        System.out.println("\nMultiplication of " + x.real + "+" + x.img + "i and " + y.real + "+" + y.img + "i is " + realResult + "+" + imgResult + "i");
    }

    void divide(Complex x, Complex y) {
        double denominator = y.real * y.real + y.img * y.img;
        double realResult = (x.real * y.real + x.img * y.img) / denominator;
        double imgResult = (y.real * x.img - x.real * y.img) / denominator;
        System.out.println("\nDivision of " + x.real + "+" + x.img + "i and " + y.real + "+" + y.img + "i is " + realResult + "+" + imgResult + "i");
    }
}

public class assignment {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.println("Enter Real part of first complex number: ");
        double real1 = s.nextDouble();
        System.out.println("Enter Imaginary part of first complex number: ");
        double img1 = s.nextDouble();
        Complex c1 = new Complex(real1, img1);

        System.out.println("Enter Real part of second complex number: ");
        double real2 = s.nextDouble();
        System.out.println("Enter Imaginary part of second complex number: ");
        double img2 = s.nextDouble();
        Complex c2 = new Complex(real2, img2);

        Complex temp = new Complex(0, 0);
        temp.add(c1, c2);
        temp.sub(c1, c2);
        temp.mul(c1, c2);
        temp.divide(c1, c2);
    }
}

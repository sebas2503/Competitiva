import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    System.out.print("Ingrese un double: ");
    double num = input.nextDouble();

    String formattedNum = String.format("%7.3f", num);

    System.out.println("Numero con formato solicitado: " + formattedNum);
  }
}

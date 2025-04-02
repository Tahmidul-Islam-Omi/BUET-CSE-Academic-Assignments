import java.util.Scanner;
import Factory.*;


public class Bank {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean exit = false;

        System.out.println("Welcome to the Bank Application!");

        while (!exit) {
            System.out.println("Select Customer Type:");
            System.out.println("1. Regular Customer");
            System.out.println("2. Premium Customer");
            System.out.println("3. VIP Customer");
            System.out.println("4. Exit");

            int customerType = scanner.nextInt();

            if (customerType == 4) {
                exit = true;
                System.out.println("Thank you for using the Bank Application. Goodbye!");
                break;
            }

            BankFactory factory = null;

            switch (customerType) {
                case 1:
                    factory = new RegularCustomerFactory();
                    break;
                case 2:
                    factory = new PremiumCustomerFactory();
                    break;
                case 3:
                    factory = new VIPCustomerFactory();
                    break;
                default:
                    System.out.println("Invalid selection. Please restart.");
                    continue;
            }

            System.out.println("Enter principal amount: ");
            double principal = scanner.nextDouble();

            System.out.println("Enter time (in years): ");
            double time = scanner.nextDouble();

            // Create application using the selected factory
            Application application = new Application(factory);

            // Ask the customer whether they want to calculate for Account, Loan, or both
            System.out.println("What would you like to calculate?");
            System.out.println("1. Account Interest");
            System.out.println("2. Loan Interest");
            System.out.println("3. Both");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    double accountInterest = application.account.calculateInterest(principal, time);
                    System.out.println("Interest on Account: " + accountInterest);
                    break;
                case 2:
                    double loanInterest = application.loan.calculateInterest(principal, time);
                    System.out.println("Interest on Loan: " + loanInterest);
                    break;
                case 3:
                    accountInterest = application.account.calculateInterest(principal, time);
                    loanInterest = application.loan.calculateInterest(principal, time);
                    System.out.println("Interest on Account: " + accountInterest);
                    System.out.println("Interest on Loan: " + loanInterest);
                    break;
                default:
                    System.out.println("Invalid selection. Please try again.");
            }

            System.out.println("Would you like to perform another operation? (yes/no)");
            String continueChoice = scanner.next().toLowerCase();

            if (continueChoice.equals("no")) {
                exit = true;
                System.out.println("Thank you for using the Bank Application. Goodbye!");
            }
        }

        scanner.close();
    }
}






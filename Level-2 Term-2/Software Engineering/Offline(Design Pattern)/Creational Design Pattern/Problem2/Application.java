import Account.Account;
import Loan.Loan;
import Factory.BankFactory;


public class Application {
    public Account account;
    public Loan loan;

    public Application(BankFactory factory) {
        account = factory.createAccount();
        loan = factory.createLoan();
    }

    public void calculateInterest(double principal , double time) {
        account.calculateInterest(principal, time);
        loan.calculateInterest(principal, time);
    }
}
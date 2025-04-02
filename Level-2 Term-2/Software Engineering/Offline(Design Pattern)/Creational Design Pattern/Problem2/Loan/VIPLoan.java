package Loan;

public class VIPLoan implements Loan {
    private double interestRate = 10;

    @Override
    public double calculateInterest(double principal, double time) {
        return (principal*time*interestRate) / 100;
    }
}
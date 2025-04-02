package Loan;

public class PremiumLoan implements Loan{

    private double interestRate = 12;

    @Override
    public double calculateInterest(double principal, double time) {
        return (principal * time * interestRate) / 100;
    }

}

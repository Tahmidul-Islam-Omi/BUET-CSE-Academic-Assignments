package Loan;

public class RegularLoan implements Loan {
    private double interestRate = 14;

    @Override
    public double calculateInterest(double principal , double time) {
        return (principal * time * interestRate) / 100;
    }
}
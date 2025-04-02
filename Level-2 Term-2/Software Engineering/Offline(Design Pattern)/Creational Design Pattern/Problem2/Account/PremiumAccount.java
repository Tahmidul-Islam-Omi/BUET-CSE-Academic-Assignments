package Account;

public class PremiumAccount implements Account {
    private double interestRate = 3.5;
    
    @Override
    public double calculateInterest(double principal , double time) {
        return (principal * time * interestRate) / 100;
    }
}
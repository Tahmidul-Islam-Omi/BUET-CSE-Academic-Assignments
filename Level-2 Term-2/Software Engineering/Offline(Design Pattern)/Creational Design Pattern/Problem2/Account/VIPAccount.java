package Account;

public class VIPAccount implements Account {
    private double interestRate = 5;

    @Override
    public double calculateInterest(double principal , double time) {
        return (principal * time * interestRate) / 100;
    }
}

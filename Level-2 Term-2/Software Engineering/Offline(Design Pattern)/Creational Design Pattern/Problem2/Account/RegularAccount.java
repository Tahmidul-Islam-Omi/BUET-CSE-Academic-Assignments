package Account;

public class RegularAccount implements Account {
    private double interestRate = 2.5;

    @Override
    public double calculateInterest(double principal , double time) {
        return (principal * time * interestRate) / 100 ;
    }
}

package Factory;

import Account.Account;
import Loan.Loan;
import Account.PremiumAccount;
import Loan.PremiumLoan;

public class PremiumCustomerFactory implements BankFactory {

    @Override
    public Account createAccount() {
        return new PremiumAccount();
    }
    
    @Override
    public Loan createLoan() {
        return new PremiumLoan();
    }
}
package Factory;

import Account.Account;
import Loan.Loan;
import Account.RegularAccount;
import Loan.RegularLoan;

public class RegularCustomerFactory implements BankFactory {

    @Override
    public Account createAccount() {
        return new RegularAccount();
    }
    
    @Override
    public Loan createLoan() {
        return new RegularLoan();
    }
}

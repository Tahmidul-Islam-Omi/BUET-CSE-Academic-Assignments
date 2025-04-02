package Factory;

import Account.Account;
import Loan.Loan;
import Account.VIPAccount;
import Loan.VIPLoan;

public class VIPCustomerFactory implements BankFactory {

    @Override
    public Account createAccount() {
        return new VIPAccount();
    }
    
    @Override
    public Loan createLoan() {
        return new VIPLoan();
    }
}

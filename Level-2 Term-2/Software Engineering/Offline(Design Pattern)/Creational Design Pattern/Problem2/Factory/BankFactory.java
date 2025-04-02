package Factory;

import Account.Account;
import Loan.Loan;

public interface BankFactory {
    Account createAccount();
    Loan createLoan();
}

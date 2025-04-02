package ServicePackage;
import Controller.*;
import InternetConnection.*;
import Display.*;
import Identification.*;
import Microcontroller.*;
import WebServer.*;
import Ticketing.*;
import Storage.*;

public class PremiumPackage implements ServicePackage {
    TicketingSystemBuilder builder;

    public PremiumPackage(InternetConnection internetConnection, WebServer webServer) {
        builder = new TicketingSystemBuilder();
        builder.setMicrocontroller(new RaspberryPi());
        builder.setDisplay(new TouchScreen());
        builder.setIdentification(new NFC());
        builder.setPaymentTerminal(new PaymentTerminal());
        builder.setInternetConnection(internetConnection);
        builder.setStorage(new InternalStorage());

        builder.setController(new TouchScreenController());
        builder.setWebServer(webServer);
    }

    public String getDetails() {
        return "Premium Package with " + builder.build().getDetails();
    }

}

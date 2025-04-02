package ServicePackage;
import Controller.*;
import InternetConnection.*;
import Display.*;
import Identification.*;
import Microcontroller.*;
import WebServer.*;
import Ticketing.*;
import Storage.*;

public class AdvancedPackage implements ServicePackage {
    TicketingSystemBuilder builder;

    public AdvancedPackage(InternetConnection internetConnection, WebServer webServer) {
        builder = new TicketingSystemBuilder();
        builder.setMicrocontroller(new RaspberryPi());
        builder.setDisplay(new OLED());
        builder.setIdentification(new NFC());
        builder.setPaymentTerminal(new PaymentTerminal());
        builder.setInternetConnection(internetConnection);
        builder.setStorage(new InternalStorage());
        builder.setController(new TouchScreenController());
        builder.setWebServer(webServer);
    }

    public String getDetails() {
        return "Advanced Package with " + builder.build().getDetails();
    }

}
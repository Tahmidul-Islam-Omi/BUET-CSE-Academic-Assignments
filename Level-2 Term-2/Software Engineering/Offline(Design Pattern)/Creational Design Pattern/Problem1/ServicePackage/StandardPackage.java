package ServicePackage;
import Controller.*;
import InternetConnection.*;
import Display.*;
import Identification.*;
import Microcontroller.*;
import WebServer.*;
import Ticketing.*;
import Storage.*;

public class StandardPackage implements ServicePackage {
    TicketingSystemBuilder builder;

    public StandardPackage(InternetConnection internetConnection, WebServer webServer) {
        builder = new TicketingSystemBuilder();
        builder.setMicrocontroller(new ArduinoMega());
        builder.setDisplay(new LED());
        
        builder.setIdentification(new RFID());
        builder.setPaymentTerminal(new PaymentTerminal());
        builder.setInternetConnection(internetConnection);
        builder.setStorage(new SDCard());
        builder.setController(new ExternalController());
        builder.setWebServer(webServer);
    }

    public String getDetails() {
        return "Standard Package with " + builder.build().getDetails();
    }

}
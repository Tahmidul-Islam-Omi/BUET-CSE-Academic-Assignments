package Ticketing;

import Controller.Controller;
import Display.Display;
import Identification.Identification;
import Identification.PaymentTerminal;
import InternetConnection.InternetConnection;
import Microcontroller.Microcontroller;
import Storage.Storage;
import WebServer.WebServer;

public interface Builder {
    void setMicrocontroller(Microcontroller microcontroller);

    void setDisplay(Display display);

    void setIdentification(Identification identification);

    void setPaymentTerminal(PaymentTerminal paymentTerminal);

    void setInternetConnection(InternetConnection internetConnection);

    void setStorage(Storage storage);

    void setController(Controller controller);

    void setWebServer(WebServer webServer);

    TicketingSystem build();
}

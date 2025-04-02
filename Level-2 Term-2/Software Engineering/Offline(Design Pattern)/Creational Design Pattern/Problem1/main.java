import java.util.Scanner;
import InternetConnection.*;
import ServicePackage.*;
import WebServer.*;

public class main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("Choose a package (Basic, Standard, Advanced, Premium): ");
        String packageType = scanner.nextLine();

        System.out.println("Choose internet connection type (WiFi, Ethernet, SIM card): ");
        String connectionType = scanner.nextLine();

        InternetConnection internetConnection = null;

        switch (connectionType) {
            case "WiFi":
                internetConnection = new WiFi();
                break;
            case "Ethernet":
                internetConnection = new Ethernet();
                break;
            case "SIM card":
                internetConnection = new GSM();
                break;
            default:
                System.out.println("Invalid connection type");
                scanner.close();
                return;
        }

        System.out.println("Choose a web server framework (Django, NodeJS, Ruby): ");
        String webServerFramework = scanner.nextLine();

        WebServer webServer = null;

        switch (webServerFramework) {
            case "Django":
                webServer = new Django();
                break;
            case "NodeJS":
                webServer = new NodeJS();
                break;
            case "Ruby":
                webServer = new Ruby();
                break;
            default:
                System.out.println("Not Available");
                return;
        }

        ServicePackage selectedPackage =  PackageFactory.createPackage(packageType, internetConnection, webServer);

        if (selectedPackage == null) {
            System.out.println("Invalid package type");
            return;
        }


        System.out.println("Package Details:");
        System.out.println(selectedPackage.getDetails());
    }
}

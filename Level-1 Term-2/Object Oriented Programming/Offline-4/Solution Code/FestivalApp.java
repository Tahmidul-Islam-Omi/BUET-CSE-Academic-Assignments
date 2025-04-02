import java.awt.*;
import java.util.Scanner;

/* This is the driver class for this project. You need to run this class with three command line arguments corresponding to the name, starting date and maxinum number of allowed events of a festival. For exmaple run the below command from the termincal:
java FestivalApp "CSE Fest 2023" "2023-07-15" 10 */
public class FestivalApp {

    public static void main(String[] args) {
        // Task: The program will be run with three command line arguements related to a festival- (i) the festival's name, (ii) its starting date and (iii) the maximum number of events allowed in the festival. Create a FestivalManager object named 'festivalManager' and initialize it with the values passed from the command line as: FestivalManager festivalManager = new FestivalManager(...); Generate error if the required parameters are not passed from the command line.

        // Write your code here

        if (args.length < 3) {
            System.out.println("Error: Three command line arguments are required.");
            return;
        }

        String festivalName = args[0];
        String startingDate = args[1];
        int maxEventCount = Integer.parseInt(args[2]);
        

        FestivalManager festivalManager = new FestivalManager(festivalName, startingDate, maxEventCount);
        Scanner scanner = new Scanner(System.in);

        //String Choice;java FestivalApp "CSE Fest 2023" "2023-07-20" 10<input.txt

        int choice;
        do {
            // the following lines of code show a menu to take user's choice
            System.out.println("Menu:");
            System.out.println("1. Add an event");
            System.out.println("2. Register student in an event");
            System.out.println("3. View festival details");
            System.out.println("4. View specific event");
            System.out.println("5. View Event on Date");
            System.out.println("6. View event with maximum participants");
            System.out.println("7. View events for students");
            System.out.println("8. Cancel registration");
            System.out.println("9. Exit");
            System.out.print("Enter option: ");

            choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character
            //choice = Integer.parseInt(Choice);

            switch (choice) {
                case 1: // Add an event
                    /*
                     * Task: using the scanner object, read the following information for an event:
                     * (i) name as a string, (ii) starting date as a string in 'YYYY-MM-DD' format,
                     * (iii) location as a string, and (iv) max number of participants allowed in the
                     * event as an integer. Invoke the function 'add event' of 'Festival Manager' to
                     * add the event, i.e., call festivalManager.addEvent(...)
                     */

                    // Write your code here

                    System.out.print("Enter event name: ");
                    String eventName = scanner.nextLine();
                    System.out.print("Enter event date (YYYY-MM-DD): ");
                    String eventStartingDate = scanner.nextLine();
                    System.out.print("Enter event location: ");
                    String eventLocation = scanner.nextLine();
                    System.out.print("Enter maximum participants: ");
                    int maxParticipants = scanner.nextInt();
                    //int maxParticipants = Integer.parseInt(MaxParticipants);

                    scanner.nextLine(); // Consume the newline character

                    Event e = new Event(eventName, eventStartingDate, eventLocation, maxParticipants);

                    festivalManager.addEvent(e);

                    break;

                case 2:// Register a student in an event
                    /*
                     * Task: read the name and id of a student and an event name. Then register the
                     * student in the event by calling the function:
                     * festivalManager.registerStudent(...)
                     */

                    // Write your code here

                    System.out.print("Enter student name: ");
                    String studentName = scanner.nextLine();
                    System.out.print("Enter student ID: ");
                    String studentId = scanner.nextLine();
                    System.out.print("Enter event name: ");
                    String eventToRegister = scanner.nextLine();

                    Student st = new Student(studentName, studentId);

                    festivalManager.registerStudent(eventToRegister, st);

                    break;

                case 3: // View festival details

                    festivalManager.showDetails();

                    break;

                case 4: // View event details
                    /*
                     * Task: read the name of an event and then show the details for the event by
                     * calling the function: festivalManager.showEvent(...);
                     */

                    // Write your code here

                    System.out.print("Enter event name: ");
                    String eventToView = scanner.nextLine();
                    festivalManager.showEvent(eventToView);

                    break;

                case 5:
                    System.out.print("Enter event date: ");
                    String date = scanner.nextLine();
                    festivalManager.showEventsOnDate(date);
                    break;

                case 6: // View event with maximum participants
                    festivalManager.eventWithHighestParticipants();
                    break;

                case 7: // View events for students
                    /*Task: read the id of a student and then show the events the student is participating in by calling the function:  festivalManager.showEventsForStudent(...);*/

                    //Write your code here

                    System.out.print("Enter student ID: ");
                    String studentIdToView = scanner.nextLine();
                    festivalManager.showEventsForStudent(studentIdToView);

                    break;

                case 8: // Cancel registration
                    /* Task: read the id of a student and an event name. Then remove the student from the participant list of the event by calling the function:  festivalManager.cancelRegistration(...); */

                    //Write your code here
                    System.out.print("Enter student id: ");
                    String StudentId = scanner.nextLine();
                    System.out.print("Enter event name: ");
                    String Eventname = scanner.nextLine();
                    festivalManager.cancelRegistration(Eventname, StudentId);

                    //festivalManager.cancelRegistration(Eventname, StudentId);
                    break;

                case 9:
                    System.out.println("Exiting the program.");
                    break;

                default:
                    System.out.println("Invalid option. Please try again.");
            }
            System.out.println();
        } while (choice != 9);

        scanner.close();
    }
}
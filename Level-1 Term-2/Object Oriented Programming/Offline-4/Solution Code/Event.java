import java.util.Objects;

/* This class stores the following information about an event: name, starting date, location and list of students registered for the event. */
public class Event {
    private String eventName;
    private String eventDate; // store in the format YYYY-MM-DD
    private String eventLocation;
    private Student[] registeredStudents;
    int participantsAdded = 0;//variable to keep track of number of participants so far added

    int maximumParticipants = 100;

    //Task: Write code for the constructor below to initialize the member variables properly

    public Event(String eventName, String eventDate, String eventLocation, int maximumParticipants) {
        //write your code here
        this.eventName =eventName;
        this.eventDate = eventDate;
        this.eventLocation = eventLocation;
        this.maximumParticipants = maximumParticipants;
        registeredStudents = new Student[maximumParticipants];
    }

    // Task: Write getters and setters for Event attributes as required

    void setEventName(String eventName) {
        this.eventName = eventName;
    }

    String getEventName() {
        return eventName;
    }

    String getEventDate() {
        return eventDate;
    }


    // Task: Write your code for the function below. This functions adds a participant to this event. Check for the following cases: (i) total participant count does not exceed the maximum participant count, (ii) the studentId is not already added.
    public void addParticipant(Student student) {
        // write your code here
        for(int i=0; i<participantsAdded; i++) {
            if(  registeredStudents[i].getId().equals(student.getId() ) && registeredStudents[i].getId().equals(student.getId()))   {
                System.out.println("Already Registration done!");
                return;
            }
        }

        if(participantsAdded >= maximumParticipants) {
            System.out.println("No slot is empty for Registration");
            return;
        }

        registeredStudents[participantsAdded++] = student;
        System.out.println("Student registration completed.");

    }


    //Task: Write code for the function below. This function shows the details of an event. Make sure your output matches with the supplied sample output.
    public void showDetails() {
        //Write your code here
        System.out.println("Name:" + eventName);
        System.out.println("Date:" + eventDate);
        System.out.println("Location:" + eventLocation);
        System.out.println("Registered Participants:");

        for(int i=0; i<participantsAdded; i++) {
            registeredStudents[i].showDetails();
        }

    }

    //Task: Write code for the function below. This function check whether the studentId in the argument has registered for this event or not. Return true if registered, otherwise return false.
    public boolean isRegistered(String studentId) {
        //Write your code here

        for(int i=0; i<participantsAdded; i++) {
            if(Objects.equals(registeredStudents[i].getId(), studentId)) {
                return true;
            }
        }


        return false;
    }

    // Task: Write code for the function below. This function removes a participant from this event. Check for the following cases: (i) the student Id is not regiseterd.
    public void removeParticipant(String studentId) {
        //Write your code here
        int idx = -1;

        for (int i = 0; i < participantsAdded; i++) {
            if (Objects.equals(registeredStudents[i].getId(), studentId)) {
                idx = i;
                break;
            }
        }

        // Shift elements one position to the left
        for (int i = idx; i < participantsAdded - 1; i++) {
            registeredStudents[i] = registeredStudents[i + 1];
        }

        participantsAdded--;

        System.out.println("Successfully removed id " + studentId + " from event " + eventName);
    }


}


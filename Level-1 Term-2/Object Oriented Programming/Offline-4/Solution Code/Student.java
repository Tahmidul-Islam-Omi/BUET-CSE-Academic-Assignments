/* This class stores some basic information of a student, namely a student's name and id.  */
public class Student {
    private String name;
    private String id;

    public Student(String name, String id) {
        this.name = name;
        this.id = id;
    }

    String getId() {
        return id;
    }

    String getName() {
        return name;
    }

    // Task: Write getters and setters as required
    public void showDetails() {
        System.out.println("  Name: "+name+", Id: "+id);
    }
}
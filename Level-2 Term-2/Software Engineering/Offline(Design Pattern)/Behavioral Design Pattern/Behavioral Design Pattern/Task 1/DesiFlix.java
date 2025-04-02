import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class DesiFlix {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        
        GenreNotifier thrillerNotifier = new GenreNotifier("Thriller");
        GenreNotifier horrorNotifier = new GenreNotifier("Horror");
        GenreNotifier comedyNotifier = new GenreNotifier("Comedy");

        User user1 = new User("Ishrak");
        User user2 = new User("Omi");
        User user3 = new User("Siam");

        
        Map<String, GenreNotifier> notifiers = new HashMap<>();
        notifiers.put("Thriller", thrillerNotifier);
        notifiers.put("Horror", horrorNotifier);
        notifiers.put("Comedy", comedyNotifier);

        Map<String, User> users = new HashMap<>();
        users.put("Ishrak", user1);
        users.put("Omi", user2);
        users.put("Siam", user3);

        String input;
        while (true) {
            try {
            Thread.sleep(1000);
            } catch (InterruptedException e) {
            e.printStackTrace();
            }
            System.out.println("Enter command (add, update, remove, upload, exit):");
            input = scanner.nextLine().toLowerCase();

            if (input.equals("exit")) {
                break;
            }

            switch (input) {
                case "add":
                case "update":
                case "remove":
                    System.out.println("Enter user name:");
                    String userName = scanner.nextLine();
                    System.out.println("Enter genre (Thriller, Horror, Comedy):");
                    String genre = scanner.nextLine();

                    User user = users.get(userName);
                    if (user == null) {
                        System.out.println("User not found!");
                        continue;
                    }

                    switch (input) {
                        case "add":
                            user.addFavoriteGenre(genre);
                            notifiers.get(genre).addSubscriber(user);
                            System.out.println( genre + " genre is added to favorites.");
                            break;
                        case "update":
                            // Assuming update means changing preferences entirely
                            System.out.println("Enter new favorite genres (comma separated):");
                            String[] newGenres = scanner.nextLine().split(",");
                            for (String g : user.getFavoriteGenres()) {
                                notifiers.get(g).removeSubscriber(user);
                            }
                            user.getFavoriteGenres().clear();
                            for (String g : newGenres) {
                                user.addFavoriteGenre(g.trim());
                                notifiers.get(g.trim()).addSubscriber(user);
                            }
                            System.out.println("Genres updated.");
                            break;
                        case "remove":
                            user.removeFavoriteGenre(genre);
                            notifiers.get(genre).removeSubscriber(user);
                            System.out.println(genre + " Genre is removed from favorites.");
                            break;
                    }
                    break;
                case "upload":
                    System.out.println("Enter genre (Thriller, Horror, Comedy):");
                    String uploadGenre = scanner.nextLine();
                    System.out.println("Enter movie name:");
                    String movie = scanner.nextLine();
                    notifiers.get(uploadGenre).notifySubscribers(movie);
                    System.out.println("Movie uploaded and notifications sent.");
                    break;
                default:
                    System.out.println("Invalid command!");
            }
        }

        // Shutdown notifiers
        thrillerNotifier.shutdownNotifier();
        horrorNotifier.shutdownNotifier();
        comedyNotifier.shutdownNotifier();

        scanner.close();
        System.out.println("System exited.");
    }
}

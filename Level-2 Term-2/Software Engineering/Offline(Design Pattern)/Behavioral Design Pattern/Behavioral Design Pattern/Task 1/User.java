import java.util.ArrayList;
import java.util.List;
// Concrete Observer: User
class User implements Observer {
    private String name;
    private List<String> favoriteGenres;

    public User(String name) {
        this.name = name;
        this.favoriteGenres = new ArrayList<>();
    }

    public void addFavoriteGenre(String genre) {
        if (!favoriteGenres.contains(genre)) {
            favoriteGenres.add(genre);
        }
    }

    public void removeFavoriteGenre(String genre) {
        favoriteGenres.remove(genre);
    }

    public List<String> getFavoriteGenres() {
        return favoriteGenres;
    }

    @Override
    public void update(String genre, String movie) {
        if (favoriteGenres.contains(genre)) {
            System.out.println("Hello " + name + ", a new " + genre + " movie has been uploaded. Movie Name: " + movie);
        }
    }
}

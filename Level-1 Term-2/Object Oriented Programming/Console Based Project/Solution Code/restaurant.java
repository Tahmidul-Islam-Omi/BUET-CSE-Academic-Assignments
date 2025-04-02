import java.util.ArrayList;

public class restaurant {
    private String restaurantId;
    private String Name;

    private String Score;

    private String Price;

    private String Zipcode;

    private ArrayList<String> category;

    restaurant(String restaurantId, String Name , String Score , String Price , String Zipcode , ArrayList<String> category) {
        this.restaurantId = restaurantId;
        this.Name = Name;
        this.Score = Score;
        this.Price = Price;
        this.Zipcode = Zipcode;
        this.category = category;
    }

    String getRestaurantId() {
        return restaurantId;
    }

    String  getName() {
        return Name;
    }

    String getScore() {
        return Score;
    }

    String getPrice() {
        return Price;
    }

    String getZipcode() {
        return Zipcode;
    }

    ArrayList<String> getCategory() {
        return category;
    }
}

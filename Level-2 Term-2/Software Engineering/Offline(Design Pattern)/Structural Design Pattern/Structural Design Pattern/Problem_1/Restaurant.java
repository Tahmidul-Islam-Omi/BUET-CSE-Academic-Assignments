import java.util.ArrayList;
import java.util.List;

public class Restaurant implements RestaurantInterface{
    @SuppressWarnings("unused")
    private String restaurantName;
    private List<RestaurantInterface> FoodList = new ArrayList<>();

    Restaurant(String restaurantName) {
        this.restaurantName = restaurantName;
    }

    public void addFood(RestaurantInterface food) {
        FoodList.add(food);
    } 
    public List<RestaurantInterface> getFoodList() {
        return FoodList;
    }

    public void menuDetails() {
        System.out.println("Menu:");
        for(RestaurantInterface food: FoodList) {
            food.menuDetails();
        }
    }

    public int getCost() {
        // Do nothing
        return 0;
    }
    
}

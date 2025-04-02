import java.util.ArrayList;
import java.util.List;

public class ComboItem implements RestaurantInterface {
    private final String comboName;
    private final List<RestaurantInterface> foodItemList;
    private int discountPercentage;
    
    public ComboItem(String comboName) {
        this.comboName = comboName;
        this.foodItemList = new ArrayList<>();
        this.discountPercentage = 0;
    }

    public void addFoodItem(RestaurantInterface FoodItem) {
        foodItemList.add(FoodItem);
    }

    public void removeFoodItem(RestaurantInterface FoodItem) {
        foodItemList.remove(FoodItem);
    }

    public void setDiscount(int discountPercentage) {
        this.discountPercentage = discountPercentage;
    }

    public String getComboName() {
        return comboName;
    }

    public List<RestaurantInterface> getFoodList() {
        return foodItemList;
    }

    public void menuDetails() {
        System.out.println(comboName + ":- ");
        
        foodItemList.forEach(RestaurantInterface::menuDetails);
        
        int totalCost = getCost();
        System.out.println("Total Cost: " + totalCost);

        if(discountPercentage > 0) {
            System.out.println("Discount: " + discountPercentage + "%");
            int discountedCost = calculateDiscountedCost(totalCost);
            System.out.println("Discounted Cost: " + discountedCost);
        }
    }

    private int calculateDiscountedCost(int totalCost) {
        return totalCost - (totalCost * discountPercentage / 100);
    }

    public int getCost() {
        int totalCost = 0;
        for(RestaurantInterface combo: foodItemList) {
            totalCost += combo.getCost();
        }

        return totalCost;
    }
}

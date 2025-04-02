public class FoodItem implements RestaurantInterface {
    private final String name;
    private final int price;

    public FoodItem(String name, int price) {
        this.name = name;
        this.price = price;
    }
    @Override
    public void menuDetails() {
        String priceDisplay = (price == 0) ? "Free" : String.valueOf(price);
        System.out.println(name + " - " + priceDisplay);
    }

    @Override
    public int getCost() {
        return price;
    }

    public String getName() {
        return name;
    }
}

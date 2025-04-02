public class food {
    private  String foodinRestaurantId;

    private String foodinRestaurantName;
    private  String foodcategory;
    private  String foodName;
    private String foodPrice;

    food(String foodinRestaurantId, String foodinRestaurantName , String foodcategory, String foodName , String foodPrice) {
        this.foodinRestaurantId = foodinRestaurantId;
        this.foodinRestaurantName = foodinRestaurantName;
        this.foodcategory = foodcategory;
        this.foodName = foodName;
        this.foodPrice = foodPrice;
    }

    String getFoodinRestaurantId() {
        return foodinRestaurantId;
    }

    String getFoodinRestaurantName() {
        return foodinRestaurantName;
    }

    String getFoodcategory() {
        return foodcategory;
    }

    String getFoodname() {
        return foodName;
    }

    String getFoodprice() {
        return foodPrice;
    }

}

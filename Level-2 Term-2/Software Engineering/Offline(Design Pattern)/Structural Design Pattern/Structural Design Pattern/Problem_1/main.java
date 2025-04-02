import java.util.List;
import java.util.Scanner;
public class main {
    public static void main(String[] args) {

        Restaurant restaurant = new Restaurant("ECE Canteen");

        FoodItem foodItem1 = new FoodItem("Burger" , 300);
        FoodItem foodItem2 = new FoodItem("Fries" , 100);
        FoodItem foodItem3 = new FoodItem("Wedges" , 150);
        FoodItem foodItem4 = new FoodItem("Shawarma" , 200);
        FoodItem foodItem5 = new FoodItem("Drink" , 25);

        restaurant.addFood(foodItem1);
        restaurant.addFood(foodItem2);
        restaurant.addFood(foodItem3);
        restaurant.addFood(foodItem4);
        restaurant.addFood(foodItem5);

        ComboItem comboItem1 = new ComboItem("Combo1");
        comboItem1.addFoodItem(foodItem1);
        comboItem1.addFoodItem(foodItem2);
        comboItem1.addFoodItem(foodItem5);

        ComboItem comboItem2 = new ComboItem("Combo2");
        comboItem2.addFoodItem(foodItem4);
        comboItem2.addFoodItem(foodItem5);

        restaurant.addFood(comboItem1);
        restaurant.addFood(comboItem2);

        restaurant.menuDetails();
        System.out.println();

        List<RestaurantInterface> foodList = restaurant.getFoodList();

        while (true) {
            System.out.println("Press 1 to create a combo, 2 to view menu and 0 to exit.");

            Scanner scanner = new Scanner(System.in);
            int number = scanner.nextInt();
            System.out.println();

            if(number == 0) {
                break;
            }

            else if(number == 1) {
                scanner.nextLine();
                System.out.print("Enter the name of the combo: ");
                String comboname = scanner.nextLine();
                ComboItem combo = new ComboItem(comboname);
                System.out.println();

                while(true) {
                    System.out.println("Available Commands: ");
                    System.out.println("1.Add[item]");
                    System.out.println("2.Remove[item]");
                    System.out.println("3.Free[item]");
                    System.out.println("4.Discount[percentage]");
                    System.out.println("5.Done");
                    System.out.println("6.Exit");
                    System.out.println();

                    System.out.print("Press between 1 to 6: ");

                    int commandNum = scanner.nextInt();

                    if(commandNum == 1) {

                        int i=1;
                        for(RestaurantInterface food: foodList) {
                            System.out.println(i + ".");
                            food.menuDetails();
                            i++;
                        }

                        System.out.println("Enter the Food No you want to add: ");
                        int itemNo = scanner.nextInt();

                        combo.addFoodItem(foodList.get(itemNo-1));
                        
                    }

                    if(commandNum == 2) {
                        int i=1;
                        for(RestaurantInterface food: combo.getFoodList()) {
                            System.out.println(i + ".");
                            food.menuDetails();
                            i++;
                        }

                        System.out.println("Enter the Food No you want to Remove: ");
                        int itemNo = scanner.nextInt();

                        combo.removeFoodItem(combo.getFoodList().get(itemNo-1));
                    }

                    if(commandNum == 3) {
                        int i=1;
                        for(RestaurantInterface food: foodList) {
                            if(food instanceof FoodItem) {
                                System.out.println(i + ".");
                                food.menuDetails();
                                i++;
                            }
                        }

                        System.out.println("Enter the Food No you want to add as free: ");
                        int itemNo = scanner.nextInt();
                        
                        int count = 0;
                        for(RestaurantInterface food: foodList) {
                            if(food instanceof FoodItem) {
                                count++;
                                if(count == itemNo) {
                                    FoodItem freeItem = new FoodItem(((FoodItem)food).getName(), 0);
                                    combo.addFoodItem(freeItem);
                                    break;
                                }
                            }
                        }
                    }

                    if(commandNum == 4) {
                        System.out.print("Enter the discount percentage: ");
                        int amount = scanner.nextInt();
                        combo.setDiscount(amount);
                    }

                    if(commandNum == 5) {
                        combo.menuDetails();
                        restaurant.addFood(combo);
                        System.out.println();
                    }

                    if(commandNum == 6) {
                        break;
                    }
                }
            }

            else if(number == 2) {
                for(RestaurantInterface food: foodList) {
                    food.menuDetails();
                }
                System.out.println();
            }
            
        }
    }
}


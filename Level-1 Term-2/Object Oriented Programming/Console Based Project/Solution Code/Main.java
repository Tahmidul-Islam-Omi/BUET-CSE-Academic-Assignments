import java.io.*;
import java.util.*;

public class Main {

    static ArrayList<restaurant > restaurantsSearch(ArrayList<restaurant> list, String resName) {
        ArrayList<restaurant> temp = new ArrayList<restaurant>();

        for(int i = 0; i < list.size(); i++) {
            String str1 = list.get(i).getName().toLowerCase();
            String str2 = resName.toLowerCase();

            //System.out.println("Debug");
            //System.out.println(str1 + " " + str2);

            if( str1.contains(str2) ) {
                temp.add(list.get(i));
            }
        }

        return temp;
    }

    static ArrayList<restaurant > restaurantsScoreSearch(ArrayList<restaurant> list, double a , double b) {
        ArrayList<restaurant> temp = new ArrayList<restaurant>();

        for(int i = 0; i < list.size(); i++) {

            if( Double.parseDouble (list.get(i).getScore()) >= a && Double.parseDouble (list.get(i).getScore()) <=b ) {
                temp.add(list.get(i));
            }

        }

        return temp;
    }

    static ArrayList<restaurant > restaurantsCategorySearch(ArrayList<restaurant> list, String category) {
        ArrayList<restaurant> temp = new ArrayList<restaurant>();

        for(int i = 0; i < list.size(); i++) {

            ArrayList<String> categories = list.get(i).getCategory();

            for(int j = 0 ; j < categories.size(); j++) {
                String str1 = categories.get(j).toLowerCase();
                String str2 = category.toLowerCase();
                if( str1.contains(str2) ) {
                    temp.add(list.get(i));
                }
            }

        }

        return temp;
    }

    static ArrayList<restaurant > restaurantsPriceSearch(ArrayList<restaurant> list, String price) {
        ArrayList<restaurant> temp = new ArrayList<restaurant>();

        for(int i = 0; i < list.size(); i++) {

            if( price.equalsIgnoreCase(list.get(i).getPrice())  ) {
                temp.add(list.get(i));
            }

        }

        return temp;
    }

    static ArrayList<restaurant > restaurantsZipCodeSearch(ArrayList<restaurant> list, String ZipCode) {
        ArrayList<restaurant> temp = new ArrayList<restaurant>();

        for(int i = 0; i < list.size(); i++) {

            if( list.get(i).getZipcode().equals(ZipCode))  {
                temp.add(list.get(i));
            }

        }

        return temp;
    }

//    static  HashMap<String, Set<String>> DifferentCategoryWiseListofRestaurants (ArrayList<restaurant> list) {
//
//        HashMap<String, Set<String>> mp = new HashMap<>();
//
//        for (int i = 0; i < list.size(); i++) {
//
//            Set<String> RestaurantList = mp.get(list.get(i).getName());
//
//            if (RestaurantList == null) {
//                RestaurantList = new HashSet<>();
//
//                ArrayList<String> categoryList = list.get(i).getCategory();
//
//                RestaurantList.addAll(categoryList);
//
//                mp.put( list.get(i).getName(), RestaurantList);
//            }
//
//            else {
//
//                ArrayList<String> categoryList = list.get(i).getCategory();
//
//                RestaurantList.addAll(categoryList);
//
//            }
//        }
//
//        return mp;
//
//    }

    static HashMap<String, Set<String>> DifferentCategoryWiseListofRestaurants(ArrayList<restaurant> list) {

        HashMap<String, Set<String>> mp = new HashMap<>();

        for (int i = 0; i < list.size(); i++) {

            ArrayList<String> categoryList = list.get(i).getCategory();

            String resName =  list.get(i).getName();

            for(int j=0; j< categoryList.size(); j++) {

                if(mp.get(categoryList.get(j)) == null) {
                    Set<String> restaurantlist = new HashSet<>();
                    restaurantlist.add( resName );

                    mp.put(categoryList.get(j), restaurantlist);
                }

                else {
                    Set<String> restaurantlist = mp.get(categoryList.get(j));
                    restaurantlist.add(resName);
                }
            }

        }

        return mp;
    }

    static ArrayList<food> foodSearchName(ArrayList<food> list , String name) {

        ArrayList<food> temp = new ArrayList<>();

        for(int i=0; i< list.size(); i++) {
            String str1 = list.get(i).getFoodname().toLowerCase();
            String str2 = name.toLowerCase();

            if ( str1.contains(str2)) {
                temp.add(list.get(i));
            }
        }

        return temp;
    }

    static ArrayList<food> foodSearchNameinRestaurant (ArrayList<food> list , String name , String res) {

        ArrayList<food> temp = new ArrayList<>();

        for(int i=0; i< list.size(); i++) {
            String storefoodname = list.get(i).getFoodname().toLowerCase();
            String userfoodname  = name.toLowerCase();

            String storeResname = list.get(i).getFoodinRestaurantName().toLowerCase();
            String userResName = res.toLowerCase();

            if ( storefoodname.contains(userfoodname) && storeResname.contains(userResName)) {
                temp.add(list.get(i));
            }
        }

        return temp;
    }

    static ArrayList<food> foodSearchCategory ( ArrayList<food> list , String Category) {

        ArrayList<food> temp = new ArrayList<>();

        for(int i=0; i< list.size(); i++) {
            String StoreCategory = list.get(i).getFoodcategory().toLowerCase();
            String UserCategory = Category.toLowerCase();

            if ( StoreCategory.contains(UserCategory)) {
                temp.add(list.get(i));
            }
        }

        return temp;
    }

    static ArrayList<food>  foodSearchCategoryinRestaurant ( ArrayList<food> list , String Category , String res) {

        ArrayList<food> temp = new ArrayList<>();

        for(int i=0; i< list.size(); i++) {
            String storeCategory = list.get(i).getFoodcategory().toLowerCase();
            String userCategory  = Category.toLowerCase();

            String storeResname = list.get(i).getFoodinRestaurantName().toLowerCase();
            String userResName = res.toLowerCase();

            if ( storeCategory.contains(userCategory) && storeResname.contains(userResName)) {
                temp.add(list.get(i));
            }
        }

        return temp;
    }

    static ArrayList<food> foodSearchByPrice(ArrayList<food> list , String price1, String price2) {

        ArrayList<food> temp = new ArrayList<food>();

        for(int i = 0; i < list.size(); i++) {


            if( Double.parseDouble(list.get(i).getFoodprice()) >= Double.parseDouble(price1) && Double.parseDouble (list.get(i).getFoodprice()) <= Double.parseDouble(price2) ) {
                temp.add(list.get(i));
            }

        }

        return temp;

    }

    static ArrayList<food> foodSearchByPriceRangeinRestaurant(ArrayList<food> list , String price1, String price2 , String res) {

        ArrayList<food> temp = new ArrayList<food>();

        for(int i = 0; i < list.size(); i++) {

            String storeResname = list.get(i).getFoodinRestaurantName().toLowerCase();
            String userResName = res.toLowerCase();


            if( Double.parseDouble(list.get(i).getFoodprice()) >= Double.parseDouble(price1) && Double.parseDouble (list.get(i).getFoodprice()) <= Double.parseDouble(price2) &&  storeResname.contains(userResName) ) {
                temp.add(list.get(i));
            }

        }

        return temp;

    }

    static ArrayList<food> foodSearchByCostliestItemsinRestaurant( ArrayList<restaurant> reslist , ArrayList<food> menulist , String res) {

        int flag = 1;
        ArrayList<food> temp = new ArrayList<food>();

        for(int i = 0; i < reslist.size(); i++) {
            String storeresname = reslist.get(i).getName().toLowerCase();
            String userResname = res.toLowerCase();
            if(storeresname.contains(userResname)) {
                flag = 0;
                break;
            }
        }

        if(flag == 1) {
            return temp;
        }

        double max = -1;

        for(int i = 0; i < menulist.size(); i++) {

            String storeResname = menulist.get(i).getFoodinRestaurantName().toLowerCase();
            String userResName = res.toLowerCase();

            if(storeResname.contains(userResName)  && Double.parseDouble(menulist.get(i).getFoodprice()) > max) {
                max = Double.parseDouble (menulist.get(i).getFoodprice() );
            }

        }

        for(int i = 0; i < menulist.size(); i++) {

            if(Double.parseDouble(menulist.get(i).getFoodprice()) == max) {
                temp.add(menulist.get(i));
            }

        }

        return temp;

    }

    static HashMap<String, Integer> totalfooditemsinRestaurant (ArrayList<food>list){

        HashMap < String , Integer> map  = new HashMap<String , Integer>();

        for(int i = 0; i < list.size(); i++) {

                if( map.get( list.get(i).getFoodinRestaurantName())  == null)  {
                    map.put( list.get(i).getFoodinRestaurantName() ,1);
                }

                else {
                    int value = map.get( list.get(i).getFoodinRestaurantName() );
                    value = value + 1;
                    map.put( list.get(i).getFoodinRestaurantName() ,value);
                }

        }

        return map;
    }


    public static void main(String[] args) throws IOException {

        final String INPUT_FILE_NAME = "restaurant.txt";
        final String INPUT_FILE_NAME2 = "menu.txt";

        ArrayList<restaurant> restaurants = new ArrayList<restaurant>();
        ArrayList<food> menus = new ArrayList<food>();

        ArrayList<String> restaurantNamelist = new ArrayList<String>();
        restaurantNamelist.add("Empty");

        BufferedReader br = new BufferedReader(new FileReader(INPUT_FILE_NAME));

        while (true) {
            String line = br.readLine();
            if (line == null) break;

            String [] array = line.split(",", -1);

            restaurantNamelist.add(array[1]);

            ArrayList<String>category = new ArrayList<String>();

            for(int i=5; i< array.length; i++) {
                category.add(array[i]);
            }

            restaurant res = new restaurant(array[0], array[1], array[2], array[3], array[4] ,category);
            restaurants.add(res);

        }
        br.close();

        br = new BufferedReader(new FileReader(INPUT_FILE_NAME2));
        while (true) {
            String line = br.readLine();
            if (line == null) break;
            String [] array = line.split(",", -1);

            food fd = new food (array[0], restaurantNamelist.get(Integer.parseInt(array[0])),array[1] , array[2] , array[3]);
            menus.add(fd);

        }

        br.close();

        int restaurantsNum = restaurants.size();
        int menusNum = menus.size();


        Scanner scanner = new Scanner(System.in);
        String Choice;
        int choice = 0;

        do {

            System.out.println("1. Search Restaurants");
            System.out.println("2. Search Food Items");
            System.out.println("3. Add Restaurant");
            System.out.println("4. Add Food Item to the Menu");
            System.out.println("5. Exit System");

            Choice =  scanner.nextLine();

            boolean isAllDigits = Choice.matches("\\d+");

            if(isAllDigits) {
                choice = Integer.parseInt(Choice);

                switch (choice) {

                    case 1:
                        String ChoiceinSearchRestaurants;
                        int choiceinSearchRestaurants = 0;


                        do {
                            System.out.println("1. By Name");
                            System.out.println("2. By Score");
                            System.out.println("3. By Category");
                            System.out.println("4. By Price");
                            System.out.println("5. By Zip Code");
                            System.out.println("6. Different Category Wise List of Restaurants");
                            System.out.println("7. Back to Main Menu");

                            ChoiceinSearchRestaurants = scanner.nextLine();
                            isAllDigits = ChoiceinSearchRestaurants.matches("\\d+");

                            if(isAllDigits) {

                                choiceinSearchRestaurants = Integer.parseInt(ChoiceinSearchRestaurants);

                            switch (choiceinSearchRestaurants) {

                                //By name
                                case 1:
                                    System.out.print("Enter a restaurant Name:");
                                    String resName= scanner.nextLine();

                                    ArrayList<restaurant> list = restaurantsSearch(restaurants , resName);

                                    if(list.isEmpty()) {
                                        System.out.println("No such restaurant with this name");
                                    }

                                    else {

                                        for (int i = 0; i < list.size(); i++) {

                                            System.out.println("Restaurant Id: " + list.get(i).getRestaurantId());
                                            System.out.println("Restaurant Name: " + list.get(i).getName());
                                            System.out.println("Restaurant Score: " + list.get(i).getScore());
                                            System.out.println("Restaurant Price: " + list.get(i).getPrice());
                                            System.out.println("Restaurant Zip Code: " + list.get(i).getZipcode());
                                            System.out.println("Restaurant Categories: "  );
                                            ArrayList<String> Category = list.get(i).getCategory();

                                            for(int j=0; j<Category.size(); j++) {
                                                System.out.println("   " + Category.get(j));
                                            }

                                            System.out.println();

                                        }

                                    }

                                    break;
                                //By Score
                                case 2:

                                    System.out.print("Enter two numbers as range: ");
                                    double num1, num2;
                                    num1 = scanner.nextDouble();
                                    num2 = scanner.nextDouble();

                                    scanner.nextLine();

                                    list = restaurantsScoreSearch(restaurants , num1, num2);

                                    if(list.isEmpty()) {
                                        System.out.println("No such restaurant with this score range");
                                    }

                                    else {

                                        for (int i = 0; i < list.size(); i++) {

                                            System.out.println("Restaurant Id: " + list.get(i).getRestaurantId());
                                            System.out.println("Restaurant Name: " + list.get(i).getName());
                                            System.out.println("Restaurant Score: " + list.get(i).getScore());
                                            System.out.println("Restaurant Price: " + list.get(i).getPrice());
                                            System.out.println("Restaurant Zip Code: " + list.get(i).getZipcode());
                                            System.out.println("Restaurant Categories: "  );
                                            ArrayList<String> Category = list.get(i).getCategory();

                                            for(int j=0; j<Category.size(); j++) {
                                                System.out.println("   " + Category.get(j));
                                            }

                                            System.out.println();

                                        }

                                    }

                                    break;

                                //By Category
                                case 3:
                                    System.out.print("Enter a Category: ");
                                    String category = scanner.nextLine();

                                    list = restaurantsCategorySearch(restaurants , category);

                                    if(list.isEmpty()) {
                                        System.out.println("No such restaurant with this category");
                                    }

                                    else {

                                        for (int i = 0; i < list.size(); i++) {

                                            System.out.println("Restaurant Id: " + list.get(i).getRestaurantId());
                                            System.out.println("Restaurant Name: " + list.get(i).getName());
                                            System.out.println("Restaurant Score: " + list.get(i).getScore());
                                            System.out.println("Restaurant Price: " + list.get(i).getPrice());
                                            System.out.println("Restaurant Zip Code: " + list.get(i).getZipcode());
                                            System.out.println("Restaurant Categories: "  );
                                            ArrayList<String> Category = list.get(i).getCategory();

                                            for(int j=0; j<Category.size(); j++) {
                                                System.out.println("   " + Category.get(j));
                                            }

                                            System.out.println();

                                        }

                                    }

                                    break;

                                //By price
                                case 4:

                                    System.out.println("Enter Price($/$$/$$$):");
                                    String price = scanner.nextLine();

                                    list = restaurantsPriceSearch(restaurants , price);

                                    if(list.isEmpty()) {
                                        System.out.println("No such restaurant with this price.");
                                    }

                                    else {

                                        for (int i = 0; i < list.size(); i++) {

                                            System.out.println("Restaurant Id: " + list.get(i).getRestaurantId());
                                            System.out.println("Restaurant Name: " + list.get(i).getName());
                                            System.out.println("Restaurant Score: " + list.get(i).getScore());
                                            System.out.println("Restaurant Price: " + list.get(i).getPrice());
                                            System.out.println("Restaurant Zip Code: " + list.get(i).getZipcode());
                                            System.out.println("Restaurant Categories: "  );
                                            ArrayList<String> Category = list.get(i).getCategory();

                                            for(int j=0; j<Category.size(); j++) {
                                                System.out.println("   " + Category.get(j));
                                            }

                                            System.out.println();

                                        }

                                    }

                                    break;


                                //By Zip Code
                                case 5:
                                    System.out.print("Enter a Zip Code: ");
                                    String zipCode = scanner.nextLine();

                                    list = restaurantsZipCodeSearch(restaurants , zipCode);

                                    if(list.isEmpty()) {
                                        System.out.println("No such restaurant with this ZipCode.");
                                    }

                                    else {

                                        for (int i = 0; i < list.size(); i++) {

                                            System.out.println("Restaurant Id: " + list.get(i).getRestaurantId());
                                            System.out.println("Restaurant Name: " + list.get(i).getName());
                                            System.out.println("Restaurant Score: " + list.get(i).getScore());
                                            System.out.println("Restaurant Price: " + list.get(i).getPrice());
                                            System.out.println("Restaurant Zip Code: " + list.get(i).getZipcode());
                                            System.out.println("Restaurant Categories: "  );
                                            ArrayList<String> Category = list.get(i).getCategory();

                                            for(int j=0; j<Category.size(); j++) {
                                                System.out.println("   " + Category.get(j));
                                            }

                                            System.out.println();

                                        }

                                    }

                                    break;

                                //Different Category Wise List of Restaurants
                                case 6:

                                    HashMap<String, Set<String>> mp = DifferentCategoryWiseListofRestaurants(restaurants);

                                    for (HashMap.Entry<String, Set<String>> entry : mp.entrySet()) {
                                        System.out.print(entry.getKey() + ": ");

                                        Set<String> restaurantlist = entry.getValue();

                                        StringBuilder result = new StringBuilder();
                                        boolean first = true;

                                        for (String element : restaurantlist) {
                                            if (first) {
                                                result.append(element);
                                                first = false;
                                            }

                                            else {
                                                result.append(", ").append(element);
                                            }
                                        }

                                        System.out.println(result.toString());

                                    }

                                    System.out.println();

                                    break;
                                // main menu
                                case 7:

                                    break;

                                default:
                                    System.out.println("Invalid choice! Please enter any number between 0 & 7.");
                                    break;
                            }

                        }

                        else {
                            System.out.println("Invalid choice! Please enter any number between 0 & 7.");
                        }

                        } while (choiceinSearchRestaurants != 7);

                        break;

                    case 2:

                        do {

                            System.out.println("1. By Name");
                            System.out.println("2. By Name in a Given Restaurant");
                            System.out.println("3. By Category");
                            System.out.println("4. By Category in a Given Restaurant");
                            System.out.println("5. By Price Range");
                            System.out.println("6. By Price Range in a Given Restaurant");
                            System.out.println("7. Costliest Food Item(s) on the Menu in a Given Restaurant");
                            System.out.println("8. List of Restaurants and Total Food Item on the Menu");
                            System.out.println("9. Back to Main Menu");

                            Choice = scanner.nextLine();
                            isAllDigits = Choice.matches("\\d+");

                            if(isAllDigits) {
                                choice = Integer.parseInt(Choice);

                                switch (choice) {
                                    //By name
                                     case 1:

                                         System.out.print("Enter Food Name you want to search: ");

                                         String foodName = scanner.nextLine();

                                         ArrayList<food> menulist = foodSearchName(menus , foodName);

                                         System.out.println();

                                         if(menulist.isEmpty()) {
                                             System.out.println("No such food item with this name");
                                         }

                                         else {

                                             for (int i = 0; i < menulist.size(); i++) {

                                                 System.out.println("Food Name: " + menulist.get(i).getFoodname());
                                                 System.out.println("Food Category: " + menulist.get(i).getFoodcategory());
                                                 System.out.println("Food found in restaurant: " + menulist.get(i).getFoodinRestaurantName());
                                                 System.out.println("Food Price: " + menulist.get(i).getFoodprice());
                                                 System.out.println();

                                             }

                                         }

                                         System.out.println();

                                        break;
                                     // By Name in a Given Restaurant
                                     case 2:

                                         System.out.print("Enter Food Name you want to search: ");
                                         foodName = scanner.nextLine();
                                         System.out.print("Enter Restaurant Name where you want to search " +foodName + ": ");

                                         String resname = scanner.nextLine();

                                         System.out.println();

                                         menulist = foodSearchNameinRestaurant(menus , foodName , resname);

                                         if(menulist.isEmpty()) {
                                             System.out.println("No such food item with this name on the menu of this restaurant");
                                         }

                                         else {

                                             for (int i = 0; i < menulist.size(); i++) {

                                                 System.out.println("Food Name: " + menulist.get(i).getFoodname());
                                                 System.out.println("Food Category: " + menulist.get(i).getFoodcategory());
                                                 System.out.println("Food found in restaurant: " + menulist.get(i).getFoodinRestaurantName());
                                                 System.out.println("Food Price: " + menulist.get(i).getFoodprice());
                                                 System.out.println();

                                             }

                                         }
                                         System.out.println();

                                         break;

                                     //By category
                                     case 3:

                                         System.out.print("Enter Food Item Category: " );
                                         String category = scanner.nextLine();
                                         System.out.println();


                                         menulist = foodSearchCategory(menus , category);

                                         if(menulist.isEmpty()) {
                                             System.out.println("No such food item with this category");
                                         }

                                         else {

                                             for (int i = 0; i < menulist.size(); i++) {

                                                 System.out.println("Food Name: " + menulist.get(i).getFoodname());
                                                 System.out.println("Food Category: " + menulist.get(i).getFoodcategory());
                                                 System.out.println("Food found in restaurant: " + menulist.get(i).getFoodinRestaurantName());
                                                 System.out.println("Food Price: " + menulist.get(i).getFoodprice());
                                                 System.out.println();

                                             }

                                         }
                                         System.out.println();

                                        break;
                                     // By Category in a Given Restaurant
                                     case 4:

                                         System.out.print("Enter a food item Category: ");
                                         category = scanner.nextLine();
                                         System.out.print("Enter a restaurant name: ");
                                         String restaurantName = scanner.nextLine();
                                         System.out.println();

                                         menulist = foodSearchCategoryinRestaurant(menus , category, restaurantName);

                                         if(menulist.isEmpty()) {
                                             System.out.println("No such food item with this category on the menu of this restaurant.");
                                         }

                                         else {

                                             for (int i = 0; i < menulist.size(); i++) {

                                                 System.out.println("Food Name: " + menulist.get(i).getFoodname());
                                                 System.out.println("Food Category: " + menulist.get(i).getFoodcategory());
                                                 System.out.println("Food found in restaurant: " + menulist.get(i).getFoodinRestaurantName());
                                                 System.out.println("Food Price: " + menulist.get(i).getFoodprice());
                                                 System.out.println();

                                             }

                                         }

                                         System.out.println();

                                         break;
                                     //  By Price Range
                                     case 5:

                                         System.out.print("Enter two numbers as price range: ");
                                         String price1 , price2;

                                         price1 = scanner.nextLine();
                                         price2 = scanner.nextLine();
                                         System.out.println();

                                         menulist = foodSearchByPrice(menus , price1, price2);

                                         if(menulist.isEmpty()) {
                                             System.out.println("No such food item with this price range.");
                                         }

                                         else {

                                             for (int i = 0; i < menulist.size(); i++) {

                                                 System.out.println("Food Name: " + menulist.get(i).getFoodname());
                                                 System.out.println("Food Category: " + menulist.get(i).getFoodcategory());
                                                 System.out.println("Food found in restaurant: " + menulist.get(i).getFoodinRestaurantName());
                                                 System.out.println("Food Price: " + menulist.get(i).getFoodprice());
                                                 System.out.println();

                                             }

                                         }

                                         System.out.println();

                                         break;

                                     case 6:

                                         System.out.print("Enter Restaurant Name: ");
                                         restaurantName = scanner.nextLine();

                                         System.out.print("Enter two numbers as range for price in "+ restaurantName + ": ");
                                         price1 = scanner.nextLine();
                                         price2 = scanner.nextLine();
                                         System.out.println();

                                         menulist = foodSearchByPriceRangeinRestaurant(menus , price1, price2 , restaurantName);

                                         if(menulist.isEmpty()) {
                                             System.out.println("No such food item with this price range on the menu of this restaurant.");
                                         }

                                         else {

                                             for (int i = 0; i < menulist.size(); i++) {

                                                 System.out.println("Food Name: " + menulist.get(i).getFoodname());
                                                 System.out.println("Food Category: " + menulist.get(i).getFoodcategory());
                                                 System.out.println("Food found in restaurant: " + menulist.get(i).getFoodinRestaurantName());
                                                 System.out.println("Food Price: " + menulist.get(i).getFoodprice());
                                                 System.out.println();

                                             }

                                         }

                                         System.out.println();


                                         break;

                                     case 7:


                                         System.out.print("Enter a Restaurant Name for searching costliest food item(s): ");
                                         restaurantName = scanner.nextLine();
                                         System.out.println();

                                         menulist = foodSearchByCostliestItemsinRestaurant( restaurants , menus , restaurantName);

                                         if( menulist.isEmpty()) {
                                             System.out.println("Restaurant doesn't exist!");
                                         }

                                         else {


                                             for (int i = 0; i < menulist.size(); i++) {

                                                 System.out.println("Food Name: " + menulist.get(i).getFoodname());
                                                 System.out.println("Food Category: " + menulist.get(i).getFoodcategory());
                                                 System.out.println("Food found in restaurant: " + menulist.get(i).getFoodinRestaurantName());
                                                 System.out.println("Food Price: " + menulist.get(i).getFoodprice());
                                                 System.out.println();

                                             }

                                         }

                                         System.out.println();

                                         break;
                                     case 8:

                                         HashMap < String , Integer> map  = totalfooditemsinRestaurant(menus);

                                         for (HashMap.Entry<String,Integer> entry : map.entrySet()) {
                                             System.out.println(entry.getKey() + ": " + entry.getValue());
                                         }
                                         System.out.println();

                                         break;

                                     case 9:
                                         break;
                                     default:
                                         System.out.println("Invalid choice! Please enter any number between 0 & 9.");
                                         break;

                                }

                            }

                            else {

                                System.out.println("Invalid choice! Please enter any number between 0 & 9.");
                            }


                        }while(choice != 9);


                        break;

                    case 3:
                        System.out.println("You have to provide all information of restaurant in order to add restaurant in restaurant database.");
                        System.out.println("Existing Name: ");

                        for(int i=0; i<restaurants.size(); i++) {
                            System.out.println("    " + restaurants.get(i).getName());
                        }
                        System.out.println("You cannot add these as restaurant name.Remind!");

                        String resName;

                        do {

                            System.out.print("Enter Restaurant Name: " );
                            resName = scanner.nextLine();

                            int flag = 0;

                            for(int i=0; i<restaurants.size(); i++) {
                                if ( Objects.equals(restaurants.get(i).getName(),resName)) {
                                    System.out.println(  resName +" already exists.You cannot add.");
                                    flag = 1;
                                }
                            }

                            if(flag == 0) {
                                break;
                            }

                        }while (true);

                        System.out.print("Enter Restaurant Score: ");
                        String resScore = scanner.nextLine();
                        System.out.print("Enter Restaurant Price($/$$/$$$): ");
                        String resPrice = scanner.nextLine();

                        String resZipCode ;

                        do {

                            System.out.print("Enter Restaurant ZipCode: ");
                            resZipCode = scanner.nextLine();

                            int flag = 0;

                            for(int i=0; i<restaurants.size(); i++) {
                                if ( Objects.equals(restaurants.get(i).getZipcode(),resZipCode)) {
                                    System.out.println( resZipCode + " already exists.You cannot add.");
                                    flag = 1;
                                }
                            }

                            if(flag == 0) {
                                break;
                            }

                        }while (true);

                        System.out.println("How many categories you want to add in " + resName + "(1-3): ");
                        String categoryLen = scanner.nextLine();
                        System.out.print("Enter Unique Category Name successively: ");

                        ArrayList<String> categories = new ArrayList<String>();

                        for(int i=0; i< Integer.parseInt(categoryLen); i++) {
                            String categoryname = scanner.nextLine();
                            categories.add(categoryname);
                        }

                        int lastresId = Integer.parseInt(restaurants.get(restaurants.size() - 1).getRestaurantId());
                        lastresId++;
                        restaurantNamelist.add(resName);

                        restaurant res = new restaurant (Integer.toString(lastresId) , resName,resScore , resPrice, resZipCode, categories );

                        restaurants.add(res);

                        System.out.println("Restaurant added Successfully!");
                        System.out.println();
                        break;

                    case 4:

                        System.out.println("You have to provide all the information of food item in oder to add menu database in existing restaurant.");
                        System.out.println("Existing Restaurant: ");

                        for(int i=0; i<restaurants.size(); i++) {
                            System.out.println("    " + restaurants.get(i).getName());
                        }

                        do {
                            System.out.print("Enter a existing restaurant name where you want to add new food item: ");
                            resName = scanner.nextLine();

                            int flag = 0;

                            for(int i=0; i<restaurants.size(); i++) {
                                if(restaurants.get(i).getName().equals(resName)) {
                                    flag = 1;
                                    break;
                                }
                            }

                            if(flag == 0) {
                                System.out.println("Restaurant doesn't exist.");
                            }

                            if(flag == 1) {
                                break;
                            }

                        }while (true);

                        int resIdx = -1;

                        for(int i=1; i<= restaurantNamelist.size(); i++) {
                            if( restaurantNamelist.get(i).equals(resName)) {
                                resIdx = i;
                                break;
                            }
                        }


                        String foodname;
                        String foodcategory;

                        System.out.println("You cannot add same food in same category in " + resName);
                        System.out.println("Existing food & its category: ");

                        for(int i=0; i< menus.size(); i++) {

                            if( menus.get(i).getFoodinRestaurantName().equals(resName)) {
                                System.out.println("Food Name: " + menus.get(i).getFoodname() + " & Category: " + menus.get(i).getFoodcategory() );
                            }
                        }


                        do {

                            System.out.print("Enter food name: ");
                            foodname = scanner.nextLine();

                            System.out.print("Enter food category: ");
                            foodcategory = scanner.nextLine();

                            int flag = 0;

                            for(int i=0; i< menus.size(); i++) {
                                if( menus.get(i).getFoodinRestaurantName().equals(resName)) {
                                    if (menus.get(i).getFoodname().equals(foodname)) {
                                        if (menus.get(i).getFoodcategory().equals(foodcategory)) {
                                            System.out.println("Already exists in same food in same category!");
                                            flag = 1;
                                        }
                                    }
                                }
                            }

                            if( flag == 0) {
                                break;
                            }

                        }while (true);

                        System.out.print("Enter food Price: ");
                        String foodprice = scanner.nextLine();

                        food fd = new food( Integer.toString(resIdx) , resName , foodcategory , foodname , foodprice);

                        menus.add(fd);

                        System.out.println( foodname +" added successfully in " + resName);
                        System.out.println();

                    case 5:

                        int CurrMenusNum = menus.size();
                        int CurrRestaurantsNum = restaurants.size();

                        if(restaurantsNum  < CurrRestaurantsNum) {
                            BufferedWriter bw = new BufferedWriter(new FileWriter("restaurant.txt"));
                            for(int i=0; i< restaurants.size(); i++) {
                                bw.write( restaurants.get(i).getRestaurantId() + "," + restaurants.get(i).getName() + "," + restaurants.get(i).getScore() + "," + restaurants.get(i).getPrice() + "," + restaurants.get(i).getZipcode() + "," );
                                ArrayList<String>categorylist = restaurants.get(i).getCategory();

                                for(int j=0; j<categorylist.size(); j++) {
                                    bw.write(categorylist.get(j));

                                    if(j != categorylist.size() - 1) {
                                        bw.write(",");
                                    }
                                }

                                bw.write(System.lineSeparator());
                            }
                            bw.close();
                        }

                        if(menusNum < CurrMenusNum) {
                            BufferedWriter bw = new BufferedWriter(new FileWriter("menu.txt"));

                            for(int i=0; i<menus.size(); i++) {
                                bw.write(menus.get(i).getFoodinRestaurantId() +  "," + menus.get(i).getFoodcategory() + "," + menus.get(i).getFoodname() + "," + menus.get(i).getFoodprice());
                                bw.write(System.lineSeparator());
                            }
                            bw.close();
                        }

                        break;

                    default:
                        System.out.println("Invalid choice! Please enter any number between 0 & 5.");
                        break;

                }


            }

            else {
                System.out.println("Invalid choice! Please enter any number between 0 & 5.");
            }

        } while (choice != 5);

        scanner.close();
    }
}
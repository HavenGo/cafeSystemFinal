/* This program is a Cafe Management System with separate owner and customer modes.
   The owner can manage the food and drink menu, add or remove items, and update prices.
   Customers can place orders, with total prices calculated only after exiting the ordering menu.

   This project is done by:
    Name                                 Id number
1. Amir Yimam ...........................ETS0169/16
2. Haven Goitom..........................ETS0667/16
3. Hawdiya Abdella ......................ETS0668/16
4. Hawi Sebsibe .........................ETS0670/16
5. Hayat Khayredin ......................ETS0675/16

*/

#include <iostream>
#include <string>
using namespace std;

void displayFoodMenu(string foodItems[], double foodPrices[], int foodAmount[], int foodCount) {
    if (foodCount == 0) {
        cout << "No food items available.\n";
    } else {
        for (int i = 0; i < foodCount; i++) {
            cout << i + 1 << ". " << foodItems[i] << " - " << foodPrices[i] << " birr (Amount: " << foodAmount[i] << ")\n";
        }
    }
}

void displayDrinkMenu(string drinkItems[], double drinkPrices[], int drinkAmount[], int drinkCount) {
    if (drinkCount == 0) {
        cout << "No drink items available.\n";
    } else {
        for (int i = 0; i < drinkCount; i++) {
            cout << i + 1 << ". " << drinkItems[i] << " - " << drinkPrices[i] << " birr (Amount: " << drinkAmount[i] << ")\n";
        }
    }
}

int main() {
    const int MAX_ITEMS = 30;
    string foodItems[MAX_ITEMS];
    double foodPrices[MAX_ITEMS];
    int foodAmount[MAX_ITEMS];
    int foodCount = 0;

    string drinkItems[MAX_ITEMS];
    double drinkPrices[MAX_ITEMS];
    int drinkAmount[MAX_ITEMS];
    int drinkCount = 0;

    string ownerPassword = "1234";

    cout << "--------------------------------------------\n";
    cout << "Welcome to the Cafe Management System\n";
    cout << "--------------------------------------------\n";

    while (true) {
        string input;
        int choice = 0;
        bool validChoice = false;

        while (!validChoice) {
            cout << "Enter 1 if you are an Owner\nEnter 2 if you are a Customer\nEnter 3 to Exit\n";
            cin >> input;

            validChoice = true;

            for (int i = 0; input[i] != '\0'; i++) {
                if (input[i] < '0' || input[i] > '9') {
                    validChoice = false;
                    break;
                }
            }

            if (validChoice) {
                choice = 0;
                for (int i = 0; input[i] != '\0'; i++) {
                    choice = choice * 10 + (input[i] - '0');
                }
            } else {
                cout << "Invalid input. Please enter a number between 1 and 3.\n";
            }
        }

        if (choice == 3) {
            cout << "Thank you for visiting this Cafe Management System! Have a great day!" << endl;
            break;
        }

        if (choice == 1) {
            string password;
            cout << "Enter owner password: ";
            cin >> password;

            if (password != ownerPassword) {
                cout << "Incorrect password.\n";
                continue;
            }

            while (true) {
                cout << "Owner Menu:\n";
                cout << "Enter 1 ----- Add food item\n";
                cout << "Enter 2 ----- Add drink item\n";
                cout << "Enter 3 ----- View food items\n";
                cout << "Enter 4 ----- View drink items\n";
                cout << "Enter 5 ----- Delete food item\n";
                cout << "Enter 6 ----- Delete drink item\n";
                cout << "Enter 7 ----- Change Password\n";
                cout << "Enter 8 ----- Exit Owner Menu\n";

                validChoice = false;
                while (!validChoice) {
                    cin >> input;

                    validChoice = true;
                    for (int i = 0; input[i] != '\0'; i++) {
                        if (input[i] < '0' || input[i] > '9') {
                            validChoice = false;
                            break;
                        }
                    }

                    if (validChoice) {
                        choice = 0;
                        for (int i = 0; input[i] != '\0'; i++) {
                            choice = choice * 10 + (input[i] - '0');
                        }
                    } else {
                        cout << "Invalid input. Please enter a valid option.\n";
                    }
                }

                if (choice == 8) break;

                if (choice == 7) {
                    string currentPassword, newPassword, confirmPassword;
                    cout << "Enter the current password: ";
                    cin >> currentPassword;

                    if (currentPassword != ownerPassword) {
                        cout << "Incorrect current password.\n";
                    } else {
                        cout << "Enter the new password: ";
                        cin >> newPassword;
                        cout << "Confirm the new password: ";
                        cin >> confirmPassword;

                        if (newPassword == confirmPassword) {
                            ownerPassword = newPassword;
                            cout << "Password changed successfully.\n";
                        } else {
                            cout << "Passwords do not match. Try again.\n";
                        }
                    }
                }

                if (choice == 1 || choice == 2) {
                    string name;
                    double price = 0;
                    int amount = 0;
                    bool duplicate = false;

                    cout << "Enter the item name: ";
                    cin >> name;

                    if (choice == 1) {
                        for (int i = 0; i < foodCount; i++) {
                            if (foodItems[i] == name) {
                                duplicate = true;
                                cout << "This item already exists. Do you want to add the amount to it? (yes or no): ";
                                string response;
                                cin >> response;
                                if (response == "yes") {
                                    cout << "Enter additional amount: ";
                                    cin >> amount;
                                    foodAmount[i] += amount;
                                    cout << "Updated amount of " << name << ": " << foodAmount[i] << "\n";
                                    break;
                                } else {
                                    cout << "No changes made to the item.\n";
                                }
                                break;
                            }
                        }
                        if (duplicate) continue;
                    } else if (choice == 2) {
                        for (int i = 0; i < drinkCount; i++) {
                            if (drinkItems[i] == name) {
                                duplicate = true;
                                cout << "This item already exists. Do you want to add the amount to it? (yes or no): ";
                                string response;
                                cin >> response;
                                if (response == "yes") {
                                    cout << "Enter additional amount: ";
                                    cin >> amount;
                                    drinkAmount[i] += amount;
                                    cout << "Updated amount of " << name << ": " << drinkAmount[i] << "\n";
                                    break;
                                } else {
                                    cout << "No changes made to the item.\n";
                                }
                                break;
                            }
                        }
                        if (duplicate) continue;
                    }

                    cout << "Enter the price: ";
                    cin >> price;

                    cout << "Enter the amount: ";
                    cin >> amount;

                    if (choice == 1 && foodCount < MAX_ITEMS) {
                        foodItems[foodCount] = name;
                        foodPrices[foodCount] = price;
                        foodAmount[foodCount] = amount;
                        foodCount++;
                        cout << "Food item added successfully.\n";
                    } else if (choice == 2 && drinkCount < MAX_ITEMS) {
                        drinkItems[drinkCount] = name;
                        drinkPrices[drinkCount] = price;
                        drinkAmount[drinkCount] = amount;
                        drinkCount++;
                        cout << "Drink item added successfully.\n";
                    } else {
                        cout << "Menu is full! Cannot add more items.\n";
                    }
                } else if (choice == 3 || choice == 4) {
                    if (choice == 3) {
                        cout << "Food Menu:\n";
                        displayFoodMenu(foodItems, foodPrices, foodAmount, foodCount);
                    } else if (choice == 4) {
                        cout << "Drink Menu:\n";
                        displayDrinkMenu(drinkItems, drinkPrices, drinkAmount, drinkCount);
                    }
                }
                else if (choice == 5 || choice == 6) {
                    int itemNum;
                    if (choice == 5) {
                        if (foodCount == 0) {
                            cout << "No food items available.\n";
                        } else {
                            cout << "Food Menu:\n";
                            displayFoodMenu(foodItems, foodPrices, foodAmount, foodCount);
                            cout << "Enter the item number to delete: ";
                            cin >> itemNum;

                            if (itemNum >= 1 && itemNum <= foodCount) {
                                for (int i = itemNum - 1; i < foodCount - 1; i++) {
                                    foodItems[i] = foodItems[i + 1];
                                    foodPrices[i] = foodPrices[i + 1];
                                    foodAmount[i] = foodAmount[i + 1];
                                }
                                foodCount--;
                                cout << "Food item deleted successfully.\n";
                            } else {
                                cout << "Invalid item number.\n";
                            }
                        }
                    } else if (choice == 6) {
                        if (drinkCount == 0) {
                            cout << "No drink items available.\n";
                        } else {
                            cout << "Drink Menu:\n";
                            displayDrinkMenu(drinkItems, drinkPrices, drinkAmount, drinkCount);
                            cout << "Enter the item number to delete: ";
                            cin >> itemNum;

                            if (itemNum >= 1 && itemNum <= drinkCount) {
                                for (int i = itemNum - 1; i < drinkCount - 1; i++) {
                                    drinkItems[i] = drinkItems[i + 1];
                                    drinkPrices[i] = drinkPrices[i + 1];
                                    drinkAmount[i] = drinkAmount[i + 1];
                                }
                                drinkCount--;
                                cout << "Drink item deleted successfully.\n";
                            } else {
                                cout << "Invalid item number.\n";
                            }
                        }
                    }
                }
            }
        } else if (choice == 2) {
            // Customer menu: Order food and drinks
            double totalCost = 0;
            bool ordering = true;

            while (ordering) {
                cout << "Customer Menu:\n";
                cout << "Enter 1 ----- Order food items\n";
                cout << "Enter 2 ----- Order drink items\n";
                cout << "Enter 3 ----- View total price\n";
                cout << "Enter 4 ----- Exit Customer Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1) {
                    if (foodCount == 0) {
                        cout << "No food items available.\n";
                    } else {
                        cout << "Food Menu:\n";
                        displayFoodMenu(foodItems, foodPrices, foodAmount, foodCount);
                        int itemChoice, quantity;
                        cout << "Enter the food item number: ";
                        cin >> itemChoice;
                        cout << "Enter quantity: ";
                        cin >> quantity;

                        if (itemChoice >= 1 && itemChoice <= foodCount && quantity <= foodAmount[itemChoice - 1]) {
                            totalCost += foodPrices[itemChoice - 1] * quantity;
                            foodAmount[itemChoice - 1] -= quantity;
                            cout << "Added to order. Total so far: " << totalCost << " birr.\n";
                        } else {
                            cout << "Invalid selection or insufficient quantity.\n";
                        }
                    }
                } else if (choice == 2) {
                    if (drinkCount == 0) {
                        cout << "No drink items available.\n";
                    } else {
                        cout << "Drink Menu:\n";
                        displayDrinkMenu(drinkItems, drinkPrices, drinkAmount, drinkCount);
                        int itemChoice, quantity;
                        cout << "Enter the drink item number: ";
                        cin >> itemChoice;
                        cout << "Enter quantity: ";
                        cin >> quantity;

                        if (itemChoice >= 1 && itemChoice <= drinkCount && quantity <= drinkAmount[itemChoice - 1]) {
                            totalCost += drinkPrices[itemChoice - 1] * quantity;
                            drinkAmount[itemChoice - 1] -= quantity;
                            cout << "Added to order. Total so far: " << totalCost << " birr.\n";
                        } else {
                            cout << "Invalid selection or insufficient quantity.\n";
                        }
                    }
                } else if (choice == 3) {
                    cout << "Your total is " << totalCost << " birr.\n";
                } else if (choice == 4) {
                    ordering = false;
                    cout << "Thank you for your order!\n";
                } else {
                    cout << "Invalid option. Please try again.\n";
                }
            }
        }
    }

    return 0;
}

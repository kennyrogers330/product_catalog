#include "SearchProduct.cpp"
#include <iostream>

using namespace std;

class ProductManager
{
private:
    Product prod;
public:
    int getMenu(){

        // TODO Add code to display Menu
        // Menu should have 
        // Add Product
        //Search Product By Name
        //Search Product By Category
        //Search Product By Brand
        // Update Product
        // Delete Product
        int choice;
        cout << "Menu:\n1. Add Product\n2. Search Products By Name\n3. Search Products By Brand\n4. Search Products By Category\n5. Update Product\n6. Delete Product\n7. Exit\nEnter your choice: ";
        cin >> choice; 
        
        return choice;
    }

    void addProduct(){
        // TODO add code to add product and 
        // store the product to products.json file by using Product class and FileHandler class
        prod.createProduct();
        FileHandler flHdl;
        flHdl.saveToJsonFile(prod);
    }

    // TODO Add code for Updating a product
    void updateProduct(){
        string userInput;
        cout << "\nEnter the product code: " << endl;
        getline(cin >> ws, userInput);
        FileHandler flHdl;
        bool result = flHdl.updateProductHelper(userInput);
    }

    // TODO Add code for deleting a product
    void deleteProduct(){
        string userInput;
        cout << "\nReady to delete a product....\n\nEnter the code of the product" << endl;
        getline(cin >> ws, userInput);
        FileHandler flHdl;
        flHdl.deleteProductHelper(userInput);
    }
    
};

int main()
{

    // ADD Code for displaying a welcome Menu
    // and handle all required logic to add, search, update, and delete product
   ProductManager pm; 
   Product prod;
   SearchProduct sp;
   vector<Product> result;
   string userInput;
   int choice;
   do{   
    choice = pm.getMenu();
    while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout <<"\nInvalid input. Please enter a number. \n\n";
            choice = pm.getMenu();
        }
    switch(choice) {
        case 1:
            pm.addProduct();
            break;
        case 2:
            cout <<"Enter product name to search: " <<endl;
            getline(cin >> ws, userInput);
            result = sp.searchByName(userInput);
            break;
        case 3:
            cout <<"Enter product brand to search: ";
            getline(cin >> ws, userInput);
            result = sp.searchByBrand(userInput);
            break;
        case 4: 
            cout <<"Enter product category to search: ";
            getline(cin >> ws, userInput);
            result = sp.searchByCategory(userInput);
            break;
        case 5:
            pm.updateProduct();
            break;
        case 6:
            pm.deleteProduct();
            break;
        case 7:
            cout << "GoodBye..." << endl;
            break; 
        default:
            cout <<"\nWrong input!\n\n";
    }
   }while (choice!=7);
    
    return 0;
}



#include <iostream>
#include <string.h>
#include <chrono>
#include <random>
//#include <nlohmann/json.hpp>

using namespace std;
using namespace std::chrono;



class Product{

    private:
    int quantity;
    string name;
    string brand;
    string description;
    string code;
    float price;
    string dosageInstruction;
    string category;
    bool requires_prescription;

    public:

    string getName(){
        //TODO Add code that return the Product Name
        return name;
    }

    string getCode(){
        return code;
    }

    string getBrand(){
        //TODO Add code that return the Product Brand
        return brand;
    }

    string getDecrisption(){
        //TODO Add code that return the Product Description
        return description;
    }

    string getDosageInstraction(){
        //TODO Add code that return the Product Dosage Instruction
        return dosageInstruction;
    }

    string getCategory(){
        //TODO Add code that return the Product Category
        return category;
    }
    
    int getQuantity(){
        //TODO Add code that return the Product Quantity
        return quantity;
    }

    float getPrice(){
        //TODO Add code that return the Product Price
        return price;
    }

    bool getRequiresPrescription(){
        //TODO Add code that return Product Requires Prescription status
        return requires_prescription;
    }


    string generateUniqueCode()
    {
        string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        string uniqueCode = "";
        auto now = system_clock::now();
        auto millis = duration_cast<milliseconds>(now.time_since_epoch());
        mt19937 generator(millis.count());
        uniform_int_distribution<int> distribution(0, 100000);

        // generate 10 characters long unique string

        for (int i = 0; i <= 10; i++)
        {
            int random_index = distribution(generator) % characters.length();
            uniqueCode += characters[random_index];
        }

        return uniqueCode;
    };

    string promptTextField(string promptText){

        // TODO Add code to prompt user for input for any Product string field
        // method takes text to display e.g: "Enter Product Name:"
        // it prompts a user and return user input in form of text. Text can be made by multiple words.
        string userInput;
        cout<< promptText<<endl;
        getline(cin >> ws, userInput);
        // cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        return userInput;
    }

    float promptNumberField(string promptText){
        // TODO Add code to prompt user for input for any Product Numeric field
        // method takes text to display e.g: "Enter Product Name:"
        // it prompts a user and return user input in form of text. Text can be made by multiple words.
        float userInput;
        cout<< promptText << endl;
        cin >> userInput;
        // cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        return userInput;
    }

    bool promptRequirePrescription()
    {
        // TODO Add code to prompt user for choosing if Product requires prescription.
        // User can type 1 or 0. 
        // it prompts a user and return user input in form of boolean. 
        bool userInput;
        cout <<"Does this Product require prescription? (1 for yes, 0 for no):\n";
        cin >> userInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        return userInput;
    }

    void createProduct()
    {

        // TODO Add code that calls promptTextField() method and prompt user for entering product name and update the name field.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        name = promptTextField("Enter Name for the product ");
        
        // TODO Add code that calls promptTextField() method and prompt user for entering product brand and update the brand field.
        brand = promptTextField("Enter Brand for the product ");
        
        // TODO Add code that calls promptTextField() method and prompt user for entering product description and update the decription field.
        description = promptTextField("Enter Description for the product");
        
        // TODO Add code that calls promptTextField() method and prompt user for entering product category and update the category field.
        category = promptTextField("Enter Catagory for the product ");
        
        // TODO Add code that calls promptTextField() method and prompt user for entering product dosageInstruction and update the dosage instruction field.
        dosageInstruction = promptTextField("Enter Dosage Instruction for the product ");
        
        // TODO Add code that calls promptNumberField() method and prompt user for entering product quantity and update the quantity field.
        quantity = promptNumberField("Enter Quantity for the product ");
        
        // TODO Add code that calls promptNumberField() method and prompt user for entering product price and update the price field.
        price = promptNumberField("Enter Price for the product ");
        
        // TODO Add code that calls promptRequirePrescription() method and prompt user for entering product requires presc and update the requiresprescription field.
        requires_prescription = promptRequirePrescription();
        // Add code to generate Unique code for product using generateUniqueCode method
        code = generateUniqueCode();
        
       // cout <<"\n\n" + name +" "+ brand +" "+ description +" "+ category +" "+ dosageInstruction +" "+ code << endl;
      //  cout <<"The quantity is: " << quantity << endl;
      //  cout <<"The Price is: "<< price << endl;
      //  cout <<"Requires quantity: "<< requires_prescription << endl; 
      //  cout <<"\n\n";
    };

    string toJson()
    {
        string productInJson;

      // TODO Add code for converting a product to json form from the private declared attributes.
      // The Output should look like:
      //{"code":"tgtwdNbCnwx","name":"name 1","brand":"br 2","description":"df","dosage_instruction":"dfg","price":123.000000,"quantity":13,"category":"des","requires_prescription":1}
        productInJson = "{\"code\":\""+code+"\",\"name\":\""+name+"\",\"brand\":\""+brand+"\",\"description\":\""+description+"\",\"dosage_instruction\":\""+dosageInstruction+"\",\"price\":"+to_string(price)+",\"quantity\":"+to_string(quantity)+",\"category\":\""+category+"\",\"requires_prescription\":"+to_string(requires_prescription)+"}";
        return productInJson;
    };


    
    void productFromJson(string txt)
    {
        //TODO Add code to convert a json string product to product object
        // string is in the form below
        //{"code":"tgtwdNbCnwx","name":"name 1","brand":"br 2","description":"df","dosage_instruction":"dfg","price":123.000000,"quantity":13,"category":"des","requires_prescription":1}
        // You need to extract value for each field and update private attributes declared above.
        size_t initInd = txt.find("\"code\":\"") + 8;
        size_t finInd = txt.find("\",", initInd);
        code = txt.substr(initInd, finInd - initInd);
       // cout << "\n\n" << code << endl;

        initInd = txt.find("\"name\":\"") + 8;
        finInd = txt.find("\",", initInd);
        name = txt.substr(initInd, finInd - initInd);
       // cout << "\n\n" << name << endl;

        initInd = txt.find("\"brand\":\"") + 9;
        finInd = txt.find("\",", initInd);
        brand = txt.substr(initInd, finInd - initInd);
       // cout << "\n\n" << brand << endl;

        initInd = txt.find("\"description\":\"") + 15;
        finInd = txt.find("\",", initInd);
        description = txt.substr(initInd, finInd - initInd);
       // cout << "\n\n" << description << endl;

        initInd = txt.find("\"dosage_instruction\":\"") + 22;
        finInd = txt.find("\",", initInd);
        dosageInstruction = txt.substr(initInd, finInd - initInd);
       // cout << "\n\n" << dosageInstruction << endl;

        initInd = txt.find("\"price\":") + 8;
        finInd = txt.find(",", initInd);
        price = stod(txt.substr(initInd, finInd - initInd));
       // cout << "\n\n" << price << endl;

        initInd = txt.find("\"quantity\":") + 11;
        finInd = txt.find(",", initInd);
        quantity = stoi(txt.substr(initInd, finInd - initInd));
       // cout << "\n\n" << quantity << endl;

        initInd = txt.find("\"category\":\"") + 12; 
        finInd = txt.find("\",", initInd);
        category = txt.substr(initInd, finInd - initInd);
       // cout << "\n\n" << category << endl;

        initInd = txt.find("\"requires_prescription\":") + 24;
        finInd = txt.find("}", initInd);
        requires_prescription = stoi(txt.substr(initInd, finInd - initInd));
       // cout << "\n\n" << requires_prescription << endl;
    };

        
};

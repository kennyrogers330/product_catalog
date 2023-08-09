#include <sstream>
#include <vector>
#include <string.h>
#include <fstream>
#include <stdio.h>

//Importing Product class
#include "Product.cpp"

using namespace std;

class FileHandler{
    public:
    string filename;

    vector<Product> readJsonFile(){

        // Add code here
        vector<Product> prodList;
        vector<string> prodLines;
        string prodLine;
        Product manProd;
        

        if (filename.empty()){
            filename = "data/products.json";
        }

        cout<<"Reading "<<filename<< " File........."<<endl;

        ifstream prodsFile(filename);

        while (getline(prodsFile, prodLine)){
             
                prodLines.push_back(prodLine);

                if(prodLine.substr(0,1) == "{"){

                    manProd.productFromJson(prodLine);
                    prodList.push_back(manProd);

                }
        }          
        
        cout<<"Finished Reading "<<filename<< " File........."<<endl;
        prodsFile.close();
        return prodList;
    };

    vector<Product> SearchHelper(string key){

        vector<Product> prodList; 
        string prodLine; 
        Product prd;
        if (filename.empty()){
            filename = "data/products.json";
        }

        ifstream prodsFile(filename);
        while (getline(prodsFile, prodLine)){
            size_t initInd = prodLine.find(key);
            if(initInd != std::string::npos){
                prd.productFromJson(prodLine);
                prodList.push_back(prd);
            }
        }
       
        prodsFile.close();
        return prodList;
    };

    bool updateProductHelper(string code){
        vector<Product> prodList; 
        string prodLine; 
        Product prd;
        if (filename.empty()){
            filename = "data/products.json";
        }

        ifstream prodsFile(filename);
        
        ofstream updatesFile("data/updates.json");
        
        bool flag = 0;

        while (getline(prodsFile, prodLine)){
            size_t initInd = prodLine.find("\"code\":\"");
            
            if(initInd != std::string::npos){
                //prd.productFromJson(prodLine);
                //prodList.push_back(prd);
                initInd+=8;
                size_t codePos = prodLine.find("\"", initInd);
                string prodCode = prodLine.substr(initInd, codePos - initInd);
            
            if(prodCode == code){
                  prd.productFromJson(prodLine);
                  cout << "\nUpdating product: " << prd.getCode() << " " << prd.getName() << endl;
                  int choice , qty;
                  string userInput;
                  float price;
                  bool prescription;
                  do{
                    cout << "\n\n1.Update product name\n2.Update product brand\n3.Update product description\n4.Update product dosage instructions\n"
                    << "5.Update product price\n6.Update product quantity\n7.Update Product category\n8.Update prescription requirements of the product\n9.Quit Updating\n\nEnter your choice: ";
                    cin >> choice;
                    while (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout <<"\nInvalid input. Please enter a number. \n\n";
                            cin >> choice;
                        }
                    switch(choice){
                        case 1: 
                            cout << "Enter the new product name " << endl;
                            getline(cin >> ws, userInput);
                            prd.setName(userInput);
                            break;
                        case 2:
                            cout << "Enter the new brand name " << endl;
                            getline(cin >> ws, userInput);
                            prd.setBrand(userInput);
                            break;
                        case 3:
                            cout << "Enter the new product description " << endl;
                            getline(cin >> ws, userInput);
                            prd.setDescription(userInput);
                            break;
                        case 4:
                            cout << "Enter the new dosage instructions for the product " << endl;
                            getline(cin >> ws, userInput);
                            prd.setDosageInstructions(userInput);
                            break;
                        case 5:
                            cout << "Enter the new price for the product " << endl;
                            cin >> price;
                            while (cin.fail())
                                {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout <<"\nInvalid value for price. Please try again " << endl;
                                    cin >> price;
                                }
                            prd.setPrice(price);
                            break;
                        case 6:
                            cout << "Enter the new quantity for the product " << endl;
                            cin >> qty;
                            while (cin.fail())
                                {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout <<"\nInvalid value for quantity. Please try again " << endl;
                                    cin >> qty;
                                }
                            prd.setQuantity(qty);
                            break;
                        case 7:
                            cout << "Enter the new category for the product " << endl;
                            getline(cin >> ws, userInput);
                            prd.setCategory(userInput);
                            break;
                        case 8:
                            cout <<"Does this Product require prescription? (1 for yes, 0 for no) " << endl;
                            cin >> prescription;
                            while (cin.fail())
                                {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout <<"\nInvalid value for a yes/no question. Please try again " << endl;
                                    cin >> prescription;
                                }
                            prd.setRequiresPrescription(prescription);
                            break;
                        case 9:
                            break;
                        default:
                            cout <<"\nInvalid choice...refer to the menu" << endl;
                    }
                }while(choice!=9);
                string updatedRecord = prd.toJson();
                flag = 1;
                updatesFile << updatedRecord << endl;
                continue;
             }
            
            }
            updatesFile << prodLine << endl;
        }
       
        prodsFile.close();
        updatesFile.close();
        
        if(flag){
            remove(filename.c_str());
            rename("data/updates.json", filename.c_str());
            cout<< "\nUpdate process completed. " << endl;
            return 1;
        }
        else{
            cout<< "\n Product with code " << code << " not found. " << endl;
            return 0;
        }
       
    };

    void saveToJsonFile(Product p){

        vector<Product> pList;
        
        pList = readJsonFile();

        pList.push_back(p);

         // Check if the file exists.
        ifstream input_file(filename);

        if (!input_file.good()) {
            // The file does not exist.
            cout << "First Record ........." << endl;

            ofstream jsonFile(filename);

            jsonFile<<"["<<endl;
            jsonFile<< p.toJson()<<endl;
            jsonFile<<"]"<<endl;
            input_file.close();
            jsonFile.close();
            return;
        }

        // Delete the file.
    int ret = remove(filename.c_str());
    
    if (ret != 0) {
        std::cout << "Error deleting file: " << strerror(errno) << "\n";
       
        return ;
    }

    ofstream jsonFile(filename);
    jsonFile<<"["<<endl;
    for(int i=0; i<pList.size(); i++){

        if(i< pList.size() -1){
            jsonFile<< pList.at(i).toJson()<<","<<endl;
        }
        else{
            jsonFile<< pList.at(i).toJson()<<endl;
        }
    }
    jsonFile<<"]"<<endl;      

    jsonFile.close();
    input_file.close();
    }
};
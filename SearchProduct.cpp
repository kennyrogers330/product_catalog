#include "FileHandler.cpp"

class SearchProduct
{
private:
    string filename;

public:
    string searchText;
    FileHandler fHandler;

    string to_lowercase(const string& text) {
        string lowercase_text;
        for (char c : text) {
            lowercase_text += tolower(c);
        }
        return lowercase_text;
    }

    vector<Product> searchByName(string name){

        // TODO
        //Add code to search by name. Searching is not case sensitive it means 
        //for input like: "name" products with names like "Name 1", "Product name" needs to included in the found results.
        vector<Product> prodList;
        string lowecaseVal = to_lowercase(name);
        cout << "Searching Text: "<< lowecaseVal << "..." << endl;
        
        prodList = fHandler.SearchHelper(name);
        
        if(prodList.size() > 0){
          cout << "Result for medication Products in Json Format: \n"<< endl;
          
          for(int i =0; i<prodList.size(); i++){
            cout << prodList.at(i).toJson() << endl;
          }
        }else{
             cout << "The search product was not found..." << endl;
        }

        return prodList; 
    };

    vector<Product> searchByCategory(string categ){

        // TODO
        //Add code to search by category. Searching is not case sensitive it means 
        //for input like: "categ" products with category like "category 1", "Product category" needs to included in the found results.
        
        vector<Product> prodList;
        string lowecaseVal = to_lowercase(categ);
        cout << "Searching Text: "<< lowecaseVal << "..." << endl;
        prodList = fHandler.SearchHelper(categ);

        if(prodList.size() > 0){
          cout << "Result for product category in Json Format: \n"<< endl;
          
          for(int i =0; i<prodList.size(); i++){
            cout << prodList.at(i).toJson() << endl;
            cout << "\n";
          }
        }else{
             cout << "The search product category was not found..." << endl;
        }

        return prodList;

    };

    vector<Product> searchByBrand(string brand){
      // TODO
        //Add code to search by brand. Searching is not case sensitive it means 
        //for input like: "br" products with names like "Brand 1", "brand name" needs to included in the found results.

        vector<Product> prodList;
        string lowecaseVal = to_lowercase(brand);
        cout << "Searching Text: "<< lowecaseVal << "..." << endl;
        prodList = fHandler.SearchHelper(brand);

        if(prodList.size() > 0){
          cout << "Result for brand Products in Json Format: \n"<< endl;
          
          for(int i =0; i<prodList.size(); i++){
            cout << prodList.at(i).toJson() << endl;
            cout << "\n";
          }
        }else{
             cout << "The search product brand was not found..." << endl;
        }

        return prodList;
    };

    void showSearchResult(vector<Product> plist, string sTxt)
    {
        // TODO
        //Add code to display Search results

    }
};
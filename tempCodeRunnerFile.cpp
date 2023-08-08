string promptTextField(string promptText){

        // TODO Add code to prompt user for input for any Product string field
        // method takes text to display e.g: "Enter Product Name:"
        // it prompts a user and return user input in form of text. Text can be made by multiple words.
        string userInput;
        cout<< promptText + "\n";
        getline(cin, userInput);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        return userInput;
    }
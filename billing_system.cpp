#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> // For atexit()
using namespace std;

// Function to delete database file on program exit
void cleanup() {
    remove("database.txt");
    cout << "\nDatabase file deleted. Exiting program...\n";
}

//create class
class shopping {
    private:
        int pcode;
        float price;
        float dis;
        string pname;
    // menu function
    public:
        void menu();
        void admin_menu();
        void buyer();
        void add();
        void edit();
        void rem(); //remove
        void list();
        void receipt();
};

void shopping :: menu() {
    m:
    int choice;
    string email;
    string password;
    //create menu and display message 
    cout << "_________________________________________________" << endl;
    cout << "                                                 " << endl;
    cout << "              Supermarket Main Menu              " << endl;
    cout << "                                                 " << endl;
    cout << "_________________________________________________" << endl;
    cout << "                                                 " << endl;
    cout << "|        1.) Administrator        |\n" << endl;
    cout << "|                                 |\n" << endl;
    cout << "|        2.) Buyer                |\n" << endl;
    cout << "|                                 |\n" << endl;
    cout << "|        3.) Exit                 |\n" << endl;
    //cout << "|                                 |\n" << endl;
    cout << "\nPlease select: ";
    cin >> choice;

    //if-else statement
    switch(choice) {
        case 1:
            cout << "Please Login \n";
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Password: ";
            cin >> password;
            if (email == "admin.kong@gmail.com" && password == "admin1234") {
                admin_menu();
            }
            else {
                cout << "Invalid email or password! Please try again.";
            }
            break;
        case 2:
            buyer();
            break;
        case 3:
            exit(0);
        default:
            cout << "Please select from the given options!";
    }
    goto m;
}

// admin menu function
void shopping :: admin_menu() {
    m:
    int choice;
    cout << "\nAdministrator menu";
    cout << "\n|_______ 1.) Add the product_______|";
    cout << "\n|                                  |";
    cout << "\n|_______ 2.) Modify the product____|";
    cout << "\n|                                  |";
    cout << "\n|_______ 3.) Delete the product____|";
    cout << "\n|                                  |";
    cout << "\n|_______ 4.) Back to main menu_____|";

    cout << "\n\nPlease enter your choice: ";
    cin >> choice;
    //if-else statement
    switch (choice) {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout << "Invalid choice! Please select from the given options.";
    }
    goto m;
}

//add function
void shopping::buyer() {
    m:
    //create menu and display message
    int choice;
    //cout << "  Buyer \n";
    cout << "_________________\n";
    cout << "                         \n";
    cout << "1.) Buy Product \n";
    cout << "                         \n";
    cout << "2.) Go back     \n";
    cout << "Enter your choice: ";
    cin >> choice;
    //if-else statement
    switch (choice) {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout << "Invalid choice! Please select from the given options.";
    }
    goto m;
}

void shopping::add() {
    fstream data;
    int c = 0; // Variable to store the last product code
    float p;
    float d;
    string n;

    // Open the file to find the last product code
    data.open("database.txt", ios::in);
    if (data) {
        while (data >> c >> n >> p >> d) {
            // Loop through the file to find the last product code
        }
        data.close();
    }

    // Increment the product code for the new product
    pcode = c + 1;

    cout << "\n\n Add new product ";
    cout << "\n\n Product code of the product: " << pcode; // Display the auto-generated product code
    cout << "\n\n Name of the product: ";
    cin >> pname;
    cout << "\n\n Price of the product: ";
    cin >> price;
    cout << "\n\n Discount on product: ";
    cin >> dis;

    // Append the new product to the file
    data.open("database.txt", ios::app | ios::out);
    if (data) {
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
        cout << "\n\n Product added successfully!\n";
    } else {
        cout << "\n\n Error opening file!";
    }
}

void shopping::edit() {
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    
    // Temporary vectors to store all products for sorting
    vector<int> all_pcodes;
    vector<string> all_pnames;
    vector<float> all_prices;
    vector<float> all_discounts;
    
    // Show all products first for admin reference
    cout << "\n\n All Current Products:";
    list();  // Call the list function to display all products
    
    cout << "\n\n Modify the record";
    cout << "\n Product code: ";
    cin >> pkey;
    
    data.open("database.txt", ios::in); //open file
    if (!data) {
        cout << "\n\nNo data found! or File doesn't exist!";
    } else {
        // First, read all products into vectors
        while (data >> pcode >> pname >> price >> dis) {
            if (pkey == pcode) {
                // Display current product details before editing
                cout << "\n\n Current Product Details:";
                cout << "\n Product Code: " << pcode;
                cout << "\n Product Name: " << pname;
                cout << "\n Price: " << price;
                cout << "\n Discount: " << dis << "%";
                
                // Get new product details
                cout << "\n\n Enter New Details:";
                cout << "\n Product new code: ";
                cin >> c;
                cout << "\n Name of the product: ";
                cin >> n;
                cout << "\n Price: ";
                cin >> p;
                cout << "\n Discount: ";
                cin >> d;
                
                // Store modified product
                all_pcodes.push_back(c);
                all_pnames.push_back(n);
                all_prices.push_back(p);
                all_discounts.push_back(d);
                
                token++;
            } else {
                // Store unmodified product
                all_pcodes.push_back(pcode);
                all_pnames.push_back(pname);
                all_prices.push_back(price);
                all_discounts.push_back(dis);
            }
        }
        data.close();
        
        // Sort products by product code
        for (int i = 0; i < all_pcodes.size(); i++) {
            for (int j = i + 1; j < all_pcodes.size(); j++) {
                if (all_pcodes[i] > all_pcodes[j]) {
                    // Swap pcodes
                    swap(all_pcodes[i], all_pcodes[j]);
                    // Swap names
                    swap(all_pnames[i], all_pnames[j]);
                    // Swap prices
                    swap(all_prices[i], all_prices[j]);
                    // Swap discounts
                    swap(all_discounts[i], all_discounts[j]);
                }
            }
        }
        
        // Write sorted products to new file
        data1.open("database1.txt", ios::out);
        for (int i = 0; i < all_pcodes.size(); i++) {
            data1 << " " << all_pcodes[i] << " " << all_pnames[i] << " " 
                 << all_prices[i] << " " << all_discounts[i] << "\n";
        }
        data1.close();
        
        remove("database.txt"); //remove file
        rename("database1.txt", "database.txt"); //rename file
        
        if (token == 0) {
            cout << "\n\n Record not found!";
        } else {
            cout << "\n\n Record edited successfully!";
        }
    }
}

void shopping::rem() {
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n Delete product";
    cout << "\n\n Product code: ";
    cin >> pkey;
    data.open("database.txt", ios::in); //open file
    if (!data) {
        cout << "\n\n No data found! or File doesn't exist!";
    } else {
        data1.open("database1.txt", ios::app | ios::out); //create file
        data >> pcode >> pname >> price >> dis; //read file
        /*
        checks if the end-of-file (EOF) has not been reached for the file stream
        It ensures the loop continues reading until all data in the file is processed.
        */
        while (!data.eof()) {
            if (pcode == pkey) {
                cout << "\n\n Product deleted successfully!";
                token++;
            } else {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis; //read file
        }
        data.close();
        data1.close();

        remove("database.txt"); //remove file
        rename("database1.txt", "database.txt"); //rename file

        if (token == 0) {
            cout << "\n\n Record not found!";
        }
    }
}

void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in); //open file
    
    if (!data) {
        cout << "\n\n No data found! or File doesn't exist!";
        return;
    }
    
    cout << "\n\n|_____________________________________________________\n";
    cout << "Product code\t\t Name\t\t Price\n";
    cout << "|_____________________________________________________\n";
    
    // Read all products from the file
    while (data >> pcode >> pname >> price >> dis) {
        cout << pcode << "\t\t\t" << pname << "\t\t" << price << "\n";
    }
    
    data.close();
}

void shopping::receipt() {
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float discount = 0; // Renamed to avoid confusion with class member 'dis'
    float total = 0;
    
    //cout << "\n\n RECEIPT ";
    data.open("database.txt", ios::in); //open file
    if (!data) {
        cout << "\n\n Empty database!\n";
        return; // Added return to exit function
    } 
    
    cout << "\n\n RECEIPT ";
    data.close();
    list(); // Show product list
    
    cout << "\n___________________________________________________\n";
    cout << "\n                Please place the order               ";
    cout << "\n___________________________________________________\n";
    
    do {
        m:
        cout << "\n\n Enter product code: ";
        cin >> arrc[c];
        cout << "\n\n Enter the product quantity: ";
        cin >> arrq[c];
        
        for (int i = 0; i < c; i++) {
            if (arrc[i] == arrc[c]) {
                cout << "\n\n Product code already exists! Please try again.";
                goto m;
            }
        }
        
        c++;
        cout << "\n\n Do you want to buy another product? (y/n): ";
        cin >> choice;
    }
    while (choice == 'y' || choice == 'Y');
    
    cout << "\n\n___________________RECEIPT___________________";
    cout << "\nProduct code\t Product name\t Quantity\t Price\t Amount\t Amount with discount\n";
    
    for (int i = 0; i < c; i++) {
        data.open("database.txt", ios::in);
        while (data >> pcode >> pname >> price >> dis) {
            if (pcode == arrc[i]) {
                amount = price * arrq[i];
                discount = amount - (amount * dis / 100); //discount formula
                total += discount;
                cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" 
                     << price << "\t" << amount << "\t" << discount;
            }
        }
        data.close();
    }
    
    cout << "\n\n___________________________________________________\n";
    cout << "\n Total Amount: " << total;
    cout << "\n\n Thank you for your purchase!";
}

int main() {
    // Register cleanup function to be called on program exit
    atexit(cleanup);
    
    shopping s;
    s.menu(); //call menu function
    return 0;
}
// End of code
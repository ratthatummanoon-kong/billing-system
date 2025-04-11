# Supermarket Billing System

This C++ program is a simple supermarket billing system that allows for admin and buyer interactions with a product database.

## Features

- **Admin Interface**
  - Add new products with auto-incremented product codes
  - Edit existing products
  - Delete products
  - Return to main menu

- **Buyer Interface**
  - View available products
  - Create receipts with multiple items
  - Calculate prices including discounts

- **Data Persistence**
  - Products are stored in a text file database
  - Database is automatically deleted on program exit

## How to Use

### Compiling the Program

```bash
g++ billing_system.cpp -o billing_system
```

### Program Flow

1. **Program Initialization**  
   START  
   ├── Initialize cleanup function to delete database on exit (`atexit`)  
   ├── Create shopping object instance  
   └── Launch main menu  

2. **Main Menu Navigation**  
   Main Menu  
   ├── Option 1: Administrator  
   │   ├── Login with credentials  
   │   │   ├── Email: `admin.kong@gmail.com`  
   │   │   └── Password: `admin1234`  
   │   └── If authenticated → Admin Menu  
   ├── Option 2: Buyer  
   │   └── Buyer Menu  
   └── Option 3: Exit Program  
       └── Trigger cleanup function  

3. **Administrator Functions**  
   Admin Menu  
   ├── Option 1: Add Product  
   │   ├── Auto-generate product code  
   │   ├── Enter product name  
   │   ├── Enter product price  
   │   ├── Enter product discount  
   │   └── Save to `database.txt`  
   ├── Option 2: Modify Product  
   │   ├── Enter product code to modify  
   │   ├── Update product details  
   │   │   ├── New product code  
   │   │   ├── New product name  
   │   │   ├── New price  
   │   │   └── New discount  
   │   ├── Sort products by code  
   │   └── Rewrite database  
   ├── Option 3: Delete Product  
   │   ├── Enter product code to delete  
   │   ├── Filter out deleted product  
   │   └── Rewrite database  
   └── Option 4: Back to Main Menu  

4. **Buyer Functions**  
   Buyer Menu  
   ├── Option 1: Buy Product  
   │   ├── List available products  
   │   ├── Order placement  
   │   │   ├── Enter product code  
   │   │   ├── Enter quantity  
   │   │   └── Add more products (Y/N)  
   │   ├── Generate receipt  
   │   │   ├── Display all purchased items  
   │   │   ├── Calculate individual amounts  
   │   │   │   ├── Raw amount (price × quantity)  
   │   │   │   └── Discounted amount  
   │   │   └── Calculate total amount  
   │   └── Return to Buyer Menu  
   └── Option 2: Back to Main Menu  

5. **Data Management**  
   File Operations  
   ├── `database.txt`  
   │   ├── Format: `[product code] [product name] [price] [discount]`  
   │   ├── Read Operations  
   │   │   ├── List products (list function)  
   │   │   └── Find specific product (edit, rem, receipt functions)  
   │   └── Write Operations  
   │       ├── Add new product (add function)  
   │       ├── Update database (edit function)  
   │       └── Remove product (rem function)  
   └── Program Termination  
       └── Delete `database.txt` file (cleanup function)  

6. **Program Exit**  
   Termination Process  
   ├── User selects Exit from Main Menu  
   │   └── OR  
   ├── Program reaches end of execution  
   └── Cleanup function is called  
       └── Delete `database.txt`  

#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;

struct user
{
  string username;
  string password;
  string role;
};

struct product
{
  string productname;
  float productprice;
  string companyname;
  float discount;
  float discountprice;
};

struct washPrice
{
  int cwp;
  int bwp;
};

struct update
{
  string Update_company;
  string new_product;
  string new_company;
  float new_price;
  float dis;
  float dprice;
};

struct customer
{
  string customername;
  string mod;
  string nam;
  string pro;
  int datee;
};

struct booking
{
  char b;
};

struct totalamount
{
  float num1;
  float num2;
  float amount;
};


void clearScreen();
void mainHeader();
void subMenu(string menuName);
int adminMenu(int chose);
string who(user login[],int max_rec, string lusername);
void addUser(string user_nameA, string pass_wordA, string rolesA, int record, int u_count, user login[]);
void gotoxy(int x, int y);
int adminMenu(int chose);
void addproductsIntoArray(int c_product, product p[], product pro);
void addproducts(int count_pro, product p[]);
void viewAllproducts(product p[], int cou_pro);
int RatelistGenerator();
int sortingMenu();
void addDiscount(int count_product, product p[]);
void ascending_sorting(int count_product, product p[]);
void descending_sorting(int count_product, product p[]);
void updateproduct(int count_product, product p[]);
bool deleteproduct(product p[], int count_product);
void addNewUser(int REC, int usercounts, user login[]);
int EmployerMenu();
void addcustomerIntoArray(customer cinfo, int count_customer, customer cus_data[], int CUSTOMER);
void addcustomer(customer cus_data[],int count_customer,int CUSTOMER);
void addbooking(int c_booking, booking bdata[]);
void addBookingIntoArray(booking binfo, int count_booking, booking bdata[]);
void calculateBill(customer cus_data[],int count_product,product p[],int count_customer,washPrice list);
void addamount(totalamount AmountC[], int count_amount, int CUSTOMER);
void addAmountIntoArray(totalamount a, totalamount AmountC[], int count_amount, int CUSTOMER);
void addEmployeUser(int REC, int usercounts, user login[]);
int CustomerMenu();
void store(product p[], int count_product);
string parsedata(string s, int field);
int load(product p[], int count_product);

main()
{
  const int MAX_RECORDS = 20;
  user login[MAX_RECORDS];
  product p[MAX_RECORDS];
  const int CUSTOMER = 20;
  customer cus_data[CUSTOMER];
  booking bookingdata[CUSTOMER];
  totalamount AmountC[CUSTOMER];
  string loginusername = " ";
  int userCount = 0;
  int choose;
  int count_product = 0;
  int listOption = 0;
  washPrice list;
  int sortingOption = 0;
  int count_customer = 0;
  int count_booking = 0;
  int count_amount = 0;
  
  string w = " ";
  count_product = load(p,count_product);
  while (true)
  {
    addUser("admin", "123", "ADMIN" , MAX_RECORDS, userCount, login);
    system("CLS");
    w = who(login,MAX_RECORDS, loginusername);

    if (w == "ADMIN")
    {
      cout << endl;
      cout << "***|***    Welcome Admin    ***|***" << endl;
      cout << endl;
      int adminOption = 0;

      while (true)
      {
        mainHeader();
        adminOption = adminMenu(choose);
        if (adminOption == 1)
        {
          mainHeader();
          subMenu("ADD NEW PRODUCT");
          addproducts(count_product,p);
          count_product = count_product + 1;
          store(p,count_product);
          cout << endl;
          clearScreen();
        }

        else if (adminOption == 2)
        {
        mainHeader();
        subMenu("RECORD OF PRODUCTS");
        viewAllproducts(p, count_product);
        cout << endl;
        clearScreen();
        }

        else if (adminOption == 3)
        {
          while (true)
          {
            mainHeader();
            listOption = RatelistGenerator();
            if (listOption == 1)
            {
              mainHeader();
              subMenu("Change Rate List Generator");
              gotoxy(0,9);
              cout << "Car Wash Price:";
              gotoxy(0,10);
              cin >> list.cwp;
              gotoxy(22,9);
              cout << "Bike Wash Price:";
              gotoxy(22,10);
              cin >> list.bwp;
              cout << endl;
              clearScreen();
            }

            else if (listOption == 2)
            {
              list.cwp = 1500;
              list.bwp = 500;
              mainHeader();
              subMenu("Old Rate List Generator");
              gotoxy(0,9);
              cout << "Car Wash Price:";
              gotoxy(0,10);
              cout << list.cwp << endl;
              gotoxy(22,9);
              cout << "Bike Wash Price:" ;
              gotoxy(22,10);
              cout << list.bwp << endl;
              cout << endl;
              clearScreen();
            }

            else if (listOption == 3)
            {
              break;
            }

            else
            {
              cout << "YOU ENTERED WRONG OPTION." << endl;
            }

          }
        }  

        else if (adminOption == 4)
        { // Discount and Sorting
          while (true)
          {
            mainHeader();
            sortingOption = sortingMenu();
            if (sortingOption == 1)
            { // Discount
              mainHeader();
              subMenu("Discounts");
              addDiscount(count_product, p);
              clearScreen();
            }

            else if (sortingOption == 2)
            { // Sorting in Ascending order
              mainHeader();
              subMenu("Ascending Order Sorting");
              ascending_sorting(count_product, p);
              clearScreen();
            }

            else if (sortingOption == 3)
            { // sorting in Descending order
              mainHeader();
              subMenu("Descending Order Sorting");
              descending_sorting(count_product, p);
              clearScreen();
            }

            else if (sortingOption == 4)
            {
              break;
            }

            else
            {
              cout << "YOU ENTERED WRONG OPTION." << endl;
            }
          }
        }

        else if (adminOption == 5)
        {
          // Update product
          mainHeader();
          subMenu("Update Product");
          updateproduct(count_product, p);
          cout << endl;
          clearScreen();
        }

        else if (adminOption == 6)
        {
          // Delete product
          mainHeader();
          subMenu("Delete Product");
          if (deleteproduct(p, count_product) == true)
          {
            count_product--;
          }
          else
          {
            gotoxy(14, 11);
            cout << "Invalid Company name." << endl;
          }
          cout << endl;
          clearScreen();
        }

        else if (adminOption == 7)
        {
          // ADD NEW USER
          if (userCount <= MAX_RECORDS)
          {
            mainHeader();
            subMenu("ADD USER");
            addNewUser( MAX_RECORDS,  userCount, login);
            userCount = userCount + 1;
            cout << endl;
            clearScreen();
          }
        }

        else if (adminOption == 8)
        {
          // logout
          break;
        }

        else if (adminOption >= 9 || adminOption <= 0)
        {
          cout << "YOU CHOOSE WRONG OPTION." << endl;
        }
      }    
    }
    
    else if (w == "EMPLOYER")
    {
      cout << endl;
      cout << "***|***    Welcome Employer    ***|***" << endl;
      cout << endl;
      int employerOption = 0;
      while (true)
      {
        mainHeader();
        employerOption = EmployerMenu();

        if (employerOption == 1)
        {
          mainHeader();
          subMenu("Records of Products");
          viewAllproducts(p, count_product);
          clearScreen();
        }

        else if (employerOption == 2)
        {
          mainHeader();
          subMenu("RATE LIST GENERATOR");
          gotoxy(0,9);
          cout << "Car Wash Price:";
          gotoxy(0,10);
          cout << list.cwp << endl;
          gotoxy(22,9);
          cout << "Bike Wash Price:" ;
          gotoxy(22,10);
          cout << list.bwp << endl;
          cout << endl;
          clearScreen();
        }

        else if (employerOption == 3)
        { // Discount and Sorting
          while (true)
          {
            mainHeader();
            sortingOption = sortingMenu();
            if (sortingOption == 1)
            { // Discount
              mainHeader();
              subMenu("Discounts");
              addDiscount(count_product, p);
              clearScreen();
            }

            else if (sortingOption == 2)
            { // Sorting in Ascending order
              mainHeader();
              subMenu("Ascending Order Sorting");
              ascending_sorting(count_product, p);
              clearScreen();
            }

            else if (sortingOption == 3)
            { // sorting in Descending order
              mainHeader();
              subMenu("Descending Order Sorting");
              descending_sorting(count_product, p);
              clearScreen();
            }

            else if (sortingOption == 4)
            {
              break;
            }

            else
            {
              cout << "YOU ENTERED WRONG OPTION." << endl;
            }
          }
        }

        else if(employerOption == 4)
        {
          mainHeader();
          subMenu("Add Customer");
          addcustomer(cus_data, count_customer, CUSTOMER);
          count_customer = count_customer + 1;
          clearScreen();
        }

        else if (employerOption == 5)
        {
          // Booking of Services
          mainHeader();
          subMenu("Add Booking");
          addbooking(count_booking, bookingdata);
          count_booking = count_booking + 1;
          cout << endl;
          clearScreen();
        }

        else if (employerOption == 6)
        {
          // Calculate Bill
          mainHeader();
          subMenu("Calculate Bill");
          calculateBill( cus_data, count_product,p, count_customer,list);
          addamount(AmountC,count_amount, CUSTOMER);
          count_amount=count_amount+1;
        
          clearScreen();
        }

        else if(employerOption == 7)
        {
          mainHeader();
          subMenu("Add Customer User");
          addEmployeUser(MAX_RECORDS,userCount, login);
          userCount = userCount + 1;
          clearScreen();
        }
        
        else if (employerOption == 8)
        { // Logout
          break;
        }

        else
        {
          cout << "YOU CHOOSE WRONG OPTION." << endl;
        }

      }
    }

    else if (w == "CUSTOMER")
    {
      string customername;
      cout << endl;
      cout << "***|***    Welcome Customer    ***|***" << endl;
      cout << endl;
      int customerOption = 0;
      while (true)
      {
        mainHeader();
        customerOption = CustomerMenu();

        if (customerOption == 1)
        {
          mainHeader();
          subMenu("YOUR PROFILE");
          
          cout << "Enter your name:";
          cin >> customername;
          for(int x=0; x<count_customer; x++)
          {
            if(cus_data[x].customername == customername)
            {
              //cout << "Customer Name:" << customerA[x] << endl;
              cout << "Welcome to the Profile menu." << endl;
              
            } 
          }
          clearScreen();
        }

        else if (customerOption == 2)
        { // Records of products
          mainHeader();
          subMenu("RECORDS OF PRODUCTS");
          viewAllproducts(p, count_product);
          clearScreen();
        }

        else if (customerOption == 3)
        { // Rate List Generator
          mainHeader();
          subMenu("RATE LIST GENERATOR");
          gotoxy(0,9);
          cout << "Car Wash Price:";
          gotoxy(0,10);
          cout << list.cwp << endl;
          gotoxy(22,9);
          cout << "Bike Wash Price:" ;
          gotoxy(22,10);
          cout << list.bwp << endl;
          cout << endl;
          clearScreen();
        }

        else if (customerOption == 4)
        { // Booking
          mainHeader();
          subMenu("BOOKING");
          
          for(int x=0; x<count_customer; x++)
          {
            if(cus_data[x].customername == customername)
            {
              cout << "Customer Name:" << cus_data[x].customername << endl;
              cout << "Model:" << cus_data[x].mod << endl;
              cout << "Booking:" << bookingdata[x].b << endl;
            } 
          }
  
          clearScreen();
        }

        else if (customerOption == 5)
        { // Bill
          //customerBill(count_customer, customerA, loginusername, nameA, modelA, cwp, bwp, productA, count_amount, AmountA, usernameA, userCount);
          mainHeader();
          subMenu("Customer Bill");
          for(int x=0; x<count_customer; x++)
          {
            if(cus_data[x].customername == customername)
            {
              cout << "Customer Name: " << cus_data[x].customername << endl;
              cout << "Date: " << cus_data[x].datee << endl;
              cout << "Car/Bike Service: " << cus_data[x].nam << endl;
              cout << "Car/Bike Model: " << cus_data[x].mod << endl;
              cout << "Product: " << cus_data[x].pro << endl;
              cout << "Total Amount: " << AmountC[x].amount << endl;
            } 
          }
          clearScreen();
        }

        else if (customerOption == 6)
        { // Logout
          break;
        }

        else
        {
          cout << "YOU CHOOSE WRONG OPTION." << endl;
        }

      }
    }
        
    else
    {
        gotoxy(15,0);
        cout << "****Login to System****" << endl;
        cout << endl;
        cout << "You entered wrong username or password! " << endl;
        clearScreen();
    }
        
  }    
}

void gotoxy(int x, int y)
{
  COORD coordinates; // coordinates is declared as COORD
  coordinates.X = x; // defining x-axis
  coordinates.Y = y; // defining  y-axis
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void clearScreen()
{ //____clear screen_____
  cout << "Press any key to continue " << endl;
  getch();
  system("CLS");
}

void mainHeader()
{ // Header
  cout << "*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*" << endl;
  cout << "* Service Station Management System *" << endl;
  cout << "*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*" << endl;
  cout << "                                     " << endl;
}

void subMenu(string menuName)
{
  cout << "                                     " << endl;
  cout << "Main menu > " << menuName << endl;
  cout << "___________" << endl;
}

string who(user login[],int max_rec, string lusername)
{
  user u;
  gotoxy(15,0);
  cout << "****Login to System****" << endl;
  cout << endl;
  
  cout << "__________________            __________________" << endl;
  gotoxy(0, 3);
  cout << "Enter username: " << endl;
  cout << "__________________            __________________" << endl;

  gotoxy(30, 3);
  cout << "Enter Password:" << endl;
  gotoxy(0, 6);
  cin >> u.username;
  gotoxy(30, 6);
  cin >> u.password;

  cout << endl;
  cout << endl;
  cout << endl;
  cout << "               ---------------" << endl;
  cout << "               |   Login     |" << endl;
  cout << "               ---------------" << endl;
  clearScreen();

  for (int i = 0; i < max_rec; i++)
  {
    if (login[i].username == u.username && login[i].password == u.password)
    {
      lusername = u.username;
      return login[i].role;
    }
  }
  lusername = " ";
  return "Wrong";
}

void addUser(string user_nameA, string pass_wordA, string rolesA, int record, int u_count, user login[])
{ //___________Add User___________--
  if (u_count <= record)
  {
    login[u_count].username = user_nameA;
    login[u_count].password = pass_wordA;
    login[u_count].role = rolesA;
    // u_count = u_count + 1;
  }
  else
  {
    cout << "No more space to add new users" << endl;
  }
}

int adminMenu(int chose)
{ // Admin Menu

  subMenu("ADMIN");
  cout << "Select one of the following options:" << endl;
  cout << "1.	Add new product." << endl;
  cout << "2.	Records of all products." << endl;
  cout << "3.	Add rate list generator of services." << endl;
  cout << "4.	Add discounts and sorting." << endl;
  cout << "5.	Update product." << endl;
  cout << "6.	Delete product." << endl;
  cout << "7.	Add User." << endl;
  cout << "8.	Exit." << endl;

  // char chose;
  cout << "Chose your option: ";
  cin >> chose;
  clearScreen();
  return chose;
}

void addproducts(int count_pro, product p[])
{ //_________________Add Product________________
  product pro;
  gotoxy(0, 8);
  cout << "_____________" << endl;
  gotoxy(0, 9);
  cout << "Product Name:";
  gotoxy(0, 10);
  cout << "_____________" << endl;

  gotoxy(31, 8);
  cout << "______________" << endl;
  gotoxy(31, 9);
  cout << "Product Price:";
  gotoxy(31, 10);
  cout << "______________" << endl;
 
  gotoxy(63, 8);
  cout << "_____________" << endl;
  gotoxy(63, 9);
  cout << "Company Name:";
  gotoxy(63, 10);
  cout << "_____________" << endl;

  gotoxy(0, 12);
  cin >> pro.productname;

  while (true)
  {
    gotoxy(31, 8);
    cout << "______________" << endl;
    gotoxy(31, 9);
    cout << "Product Price:";
    gotoxy(31, 10);
    cout << "______________" << endl;
    gotoxy(31, 12);
    cin >> pro.productprice;
    if (pro.productprice <= 0)
    {
      gotoxy(31, 13);
      cout << "Again enter the Price." << endl;
    }
    else
    {
      break;
    }
  }
  
  gotoxy(63, 12);
  cin >> pro.companyname;

  addproductsIntoArray(count_pro,p,pro);
}

void addproductsIntoArray(int c_product, product p[], product pro)
{ //______Store product data into array____each time addProduct() function is called. it will store into array
  p[c_product].productname = pro.productname;
  p[c_product].productprice = pro.productprice;
  p[c_product].companyname = pro.companyname;
}

void viewAllproducts(product p[], int cou_pro)
{ //_____________View All product________________
  cout << endl;
  cout << "------------    -----    -------" << endl;
  cout << "Product name\tPrice\tCompany" << endl;
  cout << "------------    -----    -------" << endl;
  for (int i = 0; i < cou_pro; i++)
  {
    cout << p[i].productname << " \t" << p[i].productprice << " \t" << p[i].companyname << endl;
  }
}

int RatelistGenerator()
{
  subMenu("Rate List Generator");
  cout << "1. Change Rate List Generator." << endl;
  cout << "2. Old Rate List Generator." << endl;
  cout << "3. Exit." << endl;

  int chose;
  cout << "Chose your option: ";
  cin >> chose;
  clearScreen();
  return chose;
}

int sortingMenu()
{
  subMenu("Discount and Sorting");
  cout << "1. Discounts on Products." << endl;
  cout << "2. Soritng in Ascending Order." << endl;
  cout << "3. Sorting in Descending Order." << endl;
  cout << "4. Exit." << endl;

  int chose;
  cout << "Chose your option: ";
  cin >> chose;
  clearScreen();
  return chose;
}

void addDiscount(int count_product, product p[])
{ //___________Add Discount____________

  for (int x = 0; x < count_product; x = x + 1)
  {
    if (p[x].productprice < 1500)
    {
      p[x].discount = p[x].productprice * 5 / 100;
      p[x].discountprice = p[x].productprice - p[x].discount;
    }

    else
    {
      p[x].discount = p[x].productprice * 10 / 100;
      p[x].discountprice = p[x].productprice - p[x].discount;
    }
  }
  cout << "------------    -----   ------- -------------" << endl;
  cout << "Product name\tPrice\tCompany\tdiscountprice" << endl;
  cout << "------------    -----   ------- -------------" << endl;
  cout << endl;
  for (int i = 0; i < count_product; i++)
  {
    cout << p[i].productname << " \t" << p[i].productprice << " \t" << p[i].companyname << " \t" << p[i].discountprice << endl;
  }
}

void ascending_sorting(int count_product, product p[])
{ //__________Ascending Order Sorting_________
  for (int i = 0; i < count_product; i++)
  {
    for (int j = i + 1; j < count_product; j++)
    {
      if (p[i].productprice > p[j].productprice)
      {
        float temp = p[i].productprice;
        p[i].productprice = p[j].productprice;
        p[j].productprice = temp;

        string temp_company = p[i].companyname;
        p[i].companyname = p[j].companyname;
        p[j].companyname = temp_company;

        string temp_product = p[i].productname;
        p[i].productname = p[j].productname;
        p[j].productname = temp_product;

        float temp_discount = p[i].discountprice;
        p[i].discountprice = p[j].discountprice;
        p[j].discountprice = temp_discount;
      }
    }
  }

  cout << "------------    -----   ------- -------------" << endl;
  cout << "Product name\tPrice\tCompany\tdiscountprice" << endl;
  cout << "------------    -----   ------- -------------" << endl;
  cout << endl;
  for (int i = 0; i < count_product; i++)
  {
    cout << p[i].productname << " \t" << p[i].productprice << " \t" << p[i].companyname << " \t" << p[i].discountprice << endl;
  }
}

void descending_sorting(int count_product, product p[])
{ //__________Descending Order Sorting_________
  for (int i = 0; i < count_product; i++)
  {
    for (int j = i + 1; j < count_product; j++)
    {
      if (p[i].productprice < p[j].productprice)
      {
        float temp = p[i].productprice;
        p[i].productprice = p[j].productprice;
        p[j].productprice = temp;

        string temp_company = p[i].companyname;
        p[i].companyname = p[j].companyname;
        p[j].companyname = temp_company;

        string temp_product = p[i].productname;
        p[i].productname = p[j].productname;
        p[j].productname = temp_product;

        float temp_discount = p[i].discountprice;
        p[i].discountprice = p[j].discountprice;
        p[j].discountprice = temp_discount;
      }
    }
  }

  cout << "------------    -----   ------- -------------" << endl;
  cout << "Product name\tPrice\tCompany\tdiscountprice" << endl;
  cout << "------------    -----   ------- -------------" << endl;
  cout << endl;
  for (int i = 0; i < count_product; i++)
  {
    cout << p[i].productname << " \t" << p[i].productprice << " \t" << p[i].companyname << " \t" << p[i].discountprice << endl;
  }
}

void updateproduct(int count_product, product p[])
{
  update c;
  bool flag = false;

  cout << "Enter name of the Company you want to update:  ";
  cin >> c.Update_company;

  for (int i = 0; i < count_product; i++)
  {
    if (p[i].companyname == c.Update_company)
    {
      gotoxy(0, 11);
      cout << "Enter new name of Product:";
      gotoxy(33, 11);
      cout << "Enter new price of Product:";
      gotoxy(65, 11);
      cout << "Enter new name of Company:";

      gotoxy(0, 12);
      cin >> c.new_product;
      gotoxy(33, 12);
      cin >> c.new_price;
      if (c.new_price > 1500)
      {
        c.dis = c.new_price * 10 / 100;
        c.dprice = c.new_price - c.dis;
      }
      gotoxy(65, 12);
      cin >> c.new_company;
      cout << endl;

      gotoxy(0, 14);
      cout << "Your product has been updated successfully!!" << endl;

      p[i].productname = c.new_product;
      p[i].productprice = c.new_price;
      p[i].companyname = c.new_company;
      p[i].discountprice = c.dprice;
      flag = true;
    }
    else
    {
      flag = false;
    }
  }

  if (flag == false)
  {
    cout << "Invalid Company Name." << endl;
  }
}

bool deleteproduct(product p[], int count_product)
{
  string company;
  gotoxy(0, 7);
  cout << "Enter the Company name to delete the Product:";
  gotoxy(0, 8);
  cin >> company;
  bool flag = false;
  int index = -1;
  for (int i = 0; i < count_product; i++)
  {
    if (company == p[i].companyname)
    {
      gotoxy(14, 11);
      cout << "Found Company name." << endl;
      index = i;
      flag = true;
      break;
    }

    else
    {
      flag = false;
    }
  }

  if (flag == true)
  {

    for (int x = index; x < count_product - 1; x++)
    {
      p[x].companyname = p[x + 1].companyname;
      p[x].productname = p[x + 1].productname;
      p[x].productprice = p[x + 1].productprice;
    }
    gotoxy(12, 13);
    cout << "The Product is deleted!!" << endl;
    return true;
  }
  return false;
}

void addNewUser(int REC, int usercounts, user login[])
{
  user l;
  l.username;
  l.password;
  l.role;
  gotoxy(0, 8);
  cout << "Enter username........ ";
  gotoxy(30, 8);
  cout << "Enter password........ ";
  gotoxy(60, 8);
  cout << "Enter role........";
  gotoxy(0, 9);
  cin >> l.username;
  gotoxy(30, 9);
  cin >> l.password;
  
  while (true)
  {
    gotoxy(60, 8);
    cout << "Enter role........";
    gotoxy(60, 9);
    cin >> l.role;
    if (l.role != "CUSTOMER" && l.role != "EMPLOYER")
    {
      gotoxy(60,10);
      cout << "Again enter the Role." << endl;
    }
    else
    {
      break;
    }
  }
  
  addUser(l.username, l.password, l.role, REC, usercounts, login);
}

int EmployerMenu()
{ // Employer or User Menu , what user can choose
  subMenu("Employer");
  cout << "Select one of the following options:" << endl;
  cout << "1. Records of all products." << endl;
  cout << "2. Rate list generator of services." << endl;
  cout << "3. Discounts and sorting." << endl;
  cout << "4. Add Customer." << endl;
  cout << "5. Booking of services." << endl;
  cout << "6. Calculate the bill." << endl;
  cout << "7. Add Customer Username and Password." << endl;
  cout << "8. Exit." << endl;
  // cout << "7.	Exit." << endl;

  int chose;
  cout << "Chose your option: ";
  cin >> chose;
  clearScreen();
  return chose;
}

void addcustomerIntoArray(customer cinfo, int count_customer, customer cus_data[], int CUSTOMER)
{
  if (count_customer <= CUSTOMER)
  {
    cus_data[count_customer].customername = cinfo.customername;
    cus_data[count_customer].datee = cinfo.datee;
    cus_data[count_customer].mod = cinfo.mod;
    cus_data[count_customer].nam = cinfo.nam;
    cus_data[count_customer].pro = cinfo.pro;
  }
}

void addcustomer(customer cus_data[],int count_customer,int CUSTOMER)
{
  customer cinfo;
  gotoxy(0,9);
  cout << "Enter the name of Customer: ";
  gotoxy(35,9);
  cout << "Date: ";
  gotoxy(62,9);
  cout << "Car/Bike Service: ";
  gotoxy(0,10);
  gotoxy(0,13);
  cout << "Car/Bike Model: ";
  gotoxy(35,13);
  cout << "Product Name: ";
  gotoxy(0,10);
  cin >> cinfo.customername;
  while (true)
  {
    gotoxy(35,9);
    cout << "Date: ";
    gotoxy(35,10);
    cin >> cinfo.datee;
    if (cinfo.datee < 0 || cinfo.datee >= 32)
    {
      gotoxy(35,11);
      cout << "Again enter the date." << endl;
    }
    else
    {
      break;
    }
      
  }
   
  gotoxy(62,10);
  cin >> cinfo.nam;
  
  gotoxy(0,14);
  cin >> cinfo.mod;
  
  gotoxy(35,14);
  cin >> cinfo.pro;
     
  addcustomerIntoArray(cinfo,count_customer,cus_data,CUSTOMER);
}

void addbooking(int c_booking, booking bdata[])
{
  booking binfo;
  cout << "Booking(Press Y for Yes or N for No for Booking):";
  cin >> binfo.b;

  addBookingIntoArray(binfo, c_booking, bdata);
}

void addBookingIntoArray(booking binfo, int count_booking, booking bdata[])
{
  bdata[count_booking].b = binfo.b;
}

void calculateBill(customer cus_data[],int count_product,product p[],int count_customer,washPrice list)
{
  string customername,product;
  gotoxy(0,9);
  cout <<"1. Customer Name: ";
  gotoxy(22,9);
  cin >> customername;
  for(int x=0; x<count_customer; x++)
  {
    if( cus_data[x].customername == customername)
    {
      gotoxy(0,10);
      cout << "2. Date: " ;
      gotoxy(22,10);
      cout << cus_data[x].datee << endl;
      gotoxy(0,11);
      cout << "3. Car/Bike Service: ";
      gotoxy(22,11);
      cout << cus_data[x].nam << endl;
      if(cus_data[x].nam == "car")
      {
        gotoxy(0,12);
        cout << "4. Price of Service: ";
        gotoxy(22,12);
        cout << list.cwp << endl;
      }
      else
      {
        gotoxy(0,12);
        cout << "4. Price of Service: ";
        gotoxy(22,12);
        cout << list.bwp << endl;
      }
      gotoxy(0,13);
      cout << "5. Car/Bike Model: ";
      gotoxy(22,13);
      cout << cus_data[x].mod << endl;
      gotoxy(0,14);
      cout << "6. Product Name: ";
      gotoxy(22,14);
      cout << cus_data[x].pro << endl;
      product = cus_data[x].pro;
      cout << endl;
    }

  }

  int f;
  for(int i=0; i<count_product; i++)
  {
      if(p[i].companyname == product)
      {
          f=i;
          break;
      }   
      
  }

  if (p[f].productprice < 1500)
  {
      p[f].discount = p[f].productprice * 5 / 100;
      p[f].discountprice = p[f].productprice - p[f].discount;
  }

  else
  {
      p[f].discount = p[f].productprice * 10 / 100;
      p[f].discountprice = p[f].productprice - p[f].discount;
  }

  cout << "------------    -----   ------- -------------" << endl;
  cout << "Product name\tPrice\tCompany\tdiscountprice" << endl;
  cout << "------------    -----   ------- -------------" << endl;
  cout << p[f].productname << " \t" << p[f].productprice << " \t" << p[f].companyname << " \t" << p[f].discountprice << endl;
}

void addAmountIntoArray(totalamount a, totalamount AmountC[], int count_amount, int CUSTOMER)
{
  if (count_amount <= CUSTOMER)
  {
    AmountC[count_amount] = a;
  }
}

void addamount(totalamount AmountC[], int count_amount, int CUSTOMER)
{
  totalamount a;
  gotoxy(0,21);
  cout << "7. Price of Service: ";
  gotoxy(22,21);
  cin >> a.num1;
  gotoxy(0,22);
  cout << "8. Price of Product: ";
  gotoxy(22,22);
  cin >> a.num2;
  a.amount = a.num1 + a.num2;
  gotoxy(0,23);
  cout << "9. Amount: ";

  addAmountIntoArray(a, AmountC, count_amount, CUSTOMER);
  gotoxy(22,23);
  cout << a.amount << endl;
}

void addEmployeUser(int REC, int usercounts, user login[])
{
  user l2;
  gotoxy(0, 8);
  cout << "Enter username........ ";
  gotoxy(30, 8);
  cout << "Enter password........ ";
  gotoxy(60, 8);
  cout << "Enter role........";
  gotoxy(0, 9);
  cin >> l2.username;
  gotoxy(30, 9);
  cin >> l2.password;

  while (true)
  {
    gotoxy(60, 8);
    cout << "Enter role........";
    gotoxy(60, 9);
    cin >> l2.role;
    if (l2.role== "ADMIN" || l2.role == "EMPLOYER")
    {
      gotoxy(60,10);
      cout << "Again enter the Role." << endl;
    }
    else
    {
      break;
    }
  }
  
  addUser(l2.username, l2.password, l2.role, REC, usercounts, login);
}

int CustomerMenu()
{ //_________Customer or user menu, what user can choose_________
  subMenu("CUSTOMER");
  cout << "Select one of the following options:" << endl;
  cout << "1- View Your Profile " << endl;
  cout << "2- View all Products " << endl;
  cout << "3- Rate List Generator of All Services " << endl;
  cout << "4- Booking " << endl;
  cout << "5. Bill" << endl;
  cout << "6- Logout " << endl;

  int option;
  cout << " Choose Your Option : ";
  cin >> option;
  clearScreen();
  return option;
}

void store(product p[], int count_product)
{ //___________FIlehandlinng store data
  fstream myfile;
  myfile.open("str.txt", ios::out);
  for (int x = 0; x < count_product; x++)
  {
    myfile << p[x].productname << "," << p[x].productprice << "," << p[x].companyname << endl;
  }
  myfile.close();
}

int load(product p[], int count_product)
{ //________File handling load data
  string data;
  int x = 0;
  fstream myfile;
  
  myfile.open("str.txt", ios::in);
  while (!(myfile.eof()))
  {
    getline(myfile, data);
    if (data != "")
    {
      p[x].productname = parsedata(data, 1);
     // cout << parsedata(data, 2) << endl;
      p[x].productprice = stoi(parsedata(data, 2));
      p[x].companyname = parsedata(data, 3);
     // cout << product_nameA[x] << product_priceA[x] << company_nameA[x] << endl;
      x++;
      
    }
  }
  //count_product = x - 1;
  myfile.close();
  return x;
}

string parsedata(string s, int field)
{
  string item;
  int comma = 1;
  for (int x = 0; x < s[x] != '\0'; x++)
  {
    if (s[x] == ',')
    {
      comma++;
    }
    else if (comma == field)
    {
      item = item + s[x];
    }
  }
  return item;
}
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
  user *next;
};

user *head = NULL;

struct product
{
  string productname;
  float productprice;
  string companyname;
  float discount;
  float discountprice;
  product *next1;
};

product *head1 = NULL;

struct washPrice
{
  int cwp;
  int bwp;
};

struct customer
{
  string customername;
  string mod;
  string nam;
  string pro;
  int datee;
  customer *next2;
};

customer *head2 = NULL;

struct booking
{
  char b;
  booking *next3;
};

booking *head3 = NULL;

struct totalamount
{
  float num1;
  float num2;
  float amount;
  totalamount *next4;
};

totalamount *head4 = NULL;

void clearScreen();
void mainHeader();
void subMenu(string menuName);
int adminMenu(int chose);
void gotoxy(int x, int y);
string who(int max_rec, string lusername,int userCount);
void addUser(string user_nameA, string pass_wordA, string rolesA);
void addproducts(int count_pro);
void addproductsIntoArray(int c_product,string proname,float proprice,string comname,float dis,float dprice);
product* getLastRecord();
void viewAllproducts(product *record1, int cou_pro);
void printAll();
user* getLastUser(user *temp);
int RatelistGenerator();
int sortingMenu();
void addDiscount();
void viewAlldiscount(product *records);
void printAlldiscount();
void ascending_sorting();
void descending_sorting();
void updateproduct();
bool deleteproduct();
void addNewUser();
int EmployerMenu();
customer *getLastCustomer(customer *temp2);
void addcustomerIntoArray(string cname,int date,string name,string model,string product);
void addcustomer();
booking *getLastBooking(booking *temp3);
void addBookingIntoArray(char book);
void addbooking();
void calculateBill(washPrice list);
totalamount *getLastAmount(totalamount *temp4);
void addAmountIntoArray(float n1,float n2,float a);
void addamount();
void addEmployeUser();
int CustomerMenu();
void store();
void loadData(int count_pro);
string parseData(string record, int field);

void printUser()
{
    user * temp = head;
    while(temp != NULL)
    {
        cout << temp->username << endl;
        cout << temp->password << endl;
        cout << temp->role << endl;
        temp = temp->next;
    }
}

main()
{
  const int MAX_RECORDS = 20;
  string loginusername = " ";
  int userCount = 0;
  int choose;
  int count_product = 0;
  int listOption = 0;
  washPrice list;
  int sortingOption = 0;
  string customername;
  loadData(count_product);
  string w = " ";
  addUser("admin", "123", "ADMIN" );
  while (true)
  {
    system("CLS");
    w = who(MAX_RECORDS,loginusername,userCount);
    cout << w << endl;
    if (w == "ADMIN")
    {
      cout << endl;
      cout << "***|***    Welcome Admin    ***|***" << endl;
      cout << endl;
      int adminOption = 0;

      while(true)
      {
        mainHeader();
        adminOption = adminMenu(choose);
        if (adminOption == 1)
        {
          subMenu("ADD NEW PRODUCT");
          addproducts(count_product);
          //store();
          cout << endl;
          clearScreen();
        }

        if(adminOption == 2)
        {
          mainHeader();
          subMenu("RECORD OF PRODUCTS");
          cout << "------------    -----    -------" << endl;
          cout << "Product name\tPrice\tCompany" << endl;
          cout << "------------    -----    -------" << endl;
          printAll();
          cout << endl;
          clearScreen();
        }

        if(adminOption == 3)
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

        if(adminOption == 4)
        {
          while (true)
          {
            mainHeader();
            sortingOption = sortingMenu();
            if (sortingOption == 1)
            {
              mainHeader();
              subMenu("Discounts");
              printAlldiscount();
              clearScreen();
            }

            else if (sortingOption == 2)
            {
              mainHeader();
              subMenu("Ascending Order Sorting");
              ascending_sorting();
              cout << "------------    -----    -------" << endl;
              cout << "Product name\tPrice\tCompany" << endl;
              cout << "------------    -----    -------" << endl;
              printAll();
              clearScreen();
            }

            else if (sortingOption == 3)
            {
              mainHeader();
              subMenu("Descending Order Sorting");
              descending_sorting();
              cout << "------------    -----    -------" << endl;
              cout << "Product name\tPrice\tCompany" << endl;
              cout << "------------    -----    -------" << endl;
              printAll();
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
        
        if(adminOption == 5)
        {
          mainHeader();
          subMenu("Update Product");
          updateproduct();
          cout << endl;
          clearScreen();
        }

        if(adminOption == 6)
        {
          mainHeader();
          subMenu("Delete Product");
          if (deleteproduct() == true)
          {
            gotoxy(12, 13);
            cout << "The Product is deleted!!" << endl;
          }
          else
          {
            gotoxy(14, 11);
            cout << "Invalid Company name." << endl;
          }
          cout << endl;
          clearScreen();
        }

        if(adminOption == 7)
        {
          mainHeader();
          subMenu("ADD USER");
          addNewUser();
          cout << endl;
          //printUser();
          clearScreen();
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
          cout << "------------    -----    -------" << endl;
          cout << "Product name\tPrice\tCompany" << endl;
          cout << "------------    -----    -------" << endl;
          printAll();
          cout << endl;
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

        else if(employerOption == 3)
        {
          while (true)
          {
            mainHeader();
            sortingOption = sortingMenu();
            if (sortingOption == 1)
            { // Discount
              mainHeader();
              subMenu("Discounts");
              printAlldiscount();
              clearScreen();
            }

            else if (sortingOption == 2)
            { // Sorting in Ascending order
              mainHeader();
              subMenu("Ascending Order Sorting");
              ascending_sorting();
              cout << "------------    -----    -------" << endl;
              cout << "Product name\tPrice\tCompany" << endl;
              cout << "------------    -----    -------" << endl;
              printAll();
              clearScreen();
            }

            else if (sortingOption == 3)
            { // sorting in Descending order
              mainHeader();
              subMenu("Descending Order Sorting");
              descending_sorting();
              cout << "------------    -----    -------" << endl;
              cout << "Product name\tPrice\tCompany" << endl;
              cout << "------------    -----    -------" << endl;
              printAll();
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
          addcustomer();
          clearScreen();
        }

        else if(employerOption == 5)
        {
          mainHeader();
          subMenu("Add Booking");
          addbooking();
          cout << endl;
          clearScreen();
        }

        else if(employerOption == 6)
        {
          mainHeader();
          subMenu("Calculate Bill");
          calculateBill(list);
          addamount();
          clearScreen();
        }

        else if(employerOption == 7)
        {
          mainHeader();
          subMenu("Add Customer User");
          addEmployeUser();
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
      
    else if(w == "CUSTOMER")
    {
      string customername;
      customer *temp2 = head2;
      booking *temp3 = head3;
      totalamount *temp4 = head4;
      bool isFound = false;
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
          while(temp2 != NULL)
          {
            if(temp2->customername == customername)
            {
              //cout << "Customer Name:" << customerA[x] << endl;
              cout << "Welcome to the Profile menu." << endl;
              isFound = true;
              break;
            } 
            temp2 = temp2->next2;
          }
          
          clearScreen();
        }

        else if(customerOption == 2)
        {
          mainHeader();
          subMenu("Records of Products");
          cout << "------------    -----    -------" << endl;
          cout << "Product name\tPrice\tCompany" << endl;
          cout << "------------    -----    -------" << endl;
          printAll();
          cout << endl;
          clearScreen();
        }

        else if(customerOption == 3)
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

        else if(customerOption == 4)
        {
          mainHeader();
          subMenu("BOOKING");
          
          while(temp2 != NULL)
          {
            if(temp2->customername == customername)
            {
              cout << "Customer Name:" << temp2->customername << endl;
              cout << "Model:" << temp2->mod << endl;
              cout << "Booking:" << temp3->b << endl;
              break;
            } 
          }
  
          clearScreen();
        }

        else if(customerOption == 5)
        {
          mainHeader();
          subMenu("Customer Bill");
          while(temp2 != NULL)
          {
            if(temp2->customername == customername)
            {
              cout << "Customer Name: " << temp2->customername << endl;
              cout << "Date: " << temp2->datee << endl;
              cout << "Car/Bike Service: " << temp2->nam << endl;
              cout << "Car/Bike Model: " << temp2->mod << endl;
              cout << "Product: " << temp2->pro << endl;
              cout << "Total Amount: " << temp4->amount << endl;
              break;
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

string who(int max_rec, string lusername,int userCount)
{
  string username,password,role;
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
  cin >> username;
  gotoxy(30, 6);
  cin >> password;
  //addUser("admin", "123", "ADMIN" , max_rec, userCount);
  
  cout << endl;
  cout << endl;
  cout << endl;
  cout << "               ---------------" << endl;
  cout << "               |   Login     |" << endl;
  cout << "               ---------------" << endl;
  clearScreen();
  
  user *temp = head;
  //bool isFound = false;
  while (temp != NULL)
  {
    //cout << temp->username << endl;
    //cout << temp->password << endl;
    if (temp->username == username && temp->password == password)
    {
      lusername = username;
      return temp->role;
    }
    temp = temp->next;
  }
  
  lusername = " ";
  return "Wrong";
}

void addUser(string user_nameA, string pass_wordA, string rolesA)
{ //___________Add User___________--
  user *record = new user;
  
  record->username = user_nameA;
  record->password = pass_wordA;
  record->role = rolesA;
  record->next = NULL;
  if(head == NULL)
  {
    head = record;
  }
  else
  {
    user *temp = getLastUser(head);
    temp->next = record;
  }
}

user* getLastUser(user *temp)
{
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  return temp;
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

void addproducts(int count_pro)
{ //_________________Add Product________________
  string productname,companyname;
  float productprice,discount,discountprice;
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
  cin >> productname;

  while (true)
  {
    gotoxy(31, 8);
    cout << "______________" << endl;
    gotoxy(31, 9);
    cout << "Product Price:";
    gotoxy(31, 10);
    cout << "______________" << endl;
    gotoxy(31, 12);
    cin >> productprice;
    if (productprice <= 0)
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
  cin >> companyname;
  
  if(productprice < 1500)
  {
    discount = productprice * 5/100;
    discountprice = productprice - discount;
  }

  else
  {
    discount = productprice * 10/100;
    discountprice = productprice - discount;
  }


  addproductsIntoArray(count_pro,productname,productprice,companyname,discount,discountprice);
}

void addproductsIntoArray(int c_product,string proname,float proprice,string comname,float dis,float dprice)
{ //______Store product data into array____each time addProduct() function is called. it will store into array
  product *record1 = new product;
  record1->productname = proname;
  record1->productprice = proprice;
  record1->companyname = comname;
  record1->discount = dis;
  record1->discountprice = dprice;
  record1->next1 = NULL;

  if(head1 == NULL)
  {
    head1 = record1;
  }

  else
  {
    product *temp1 = getLastRecord();
    temp1->next1 = record1;
  }
}

product* getLastRecord()
{
  product *temp1 = head1;
  while(temp1->next1 != NULL)
  {
    temp1 = temp1->next1;
  }
  return temp1;
}

void viewAllproducts(product *record1)
{ //_____________View All product________________
  cout << endl;
  cout << record1->productname << " \t" << record1->productprice << " \t" << record1->companyname << endl;
  
}

void printAll()
{
     product * temp1 = head1;
     while (temp1 != NULL)
     {
          viewAllproducts(temp1);
          temp1 = temp1->next1;
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

// void addDiscount()
// { //___________Add Discount____________
//   product *d = head1;
//   while(d != NULL)
//   {
//     if (d->productprice < 1500)
//     {
//       d->discount = d->productprice * 5 / 100;
//       d->discountprice = d->productprice - d->discount;
//     }

//     else
//     {
//       d->discount = d->productprice * 10 / 100;
//       d->discountprice = d->productprice - d->discount;
//     }
//   }
//   // cout << "------------    -----   ------- -------------" << endl;
//   // cout << "Product name\tPrice\tCompany\tdiscountprice" << endl;
//   // cout << "------------    -----   ------- -------------" << endl;
//   // cout << endl;

//   // cout << d->productname << " \t" << d->productprice << " \t" << d->companyname << " \t" << d->discountprice << endl;
  
// }

void printAlldiscount()
{
     product  *temp1 = head1;
     while (temp1 != NULL)
     {
          viewAlldiscount(temp1);
          temp1 = temp1->next1;
     }
     
}

void viewAlldiscount(product *records)
{ //_____________View All product________________
  cout << endl;
  cout << "------------    -----    -------" << endl;
  cout << "Product name\tPrice\tCompany\tdiscountprice" << endl;
  cout << "------------    -----    -------" << endl;
  cout << records->productname << " \t" << records->productprice << " \t" << records->companyname << " \t" << records->discountprice << endl;
  
}

// void printAlldiscount()
// {
//   product * temp1 = head1;
//   while (temp1 != NULL)
//   {
//     viewAlldiscount(temp1);
//     temp1 = temp1->next1;
//   }
     
// }

void ascending_sorting()
{
  product * current = head1;
  product * nextCurrent = current->next1;
  while(current != NULL)
  {
    nextCurrent = current->next1;
    while(nextCurrent != NULL)
    {
      if(current->productprice > nextCurrent->productprice)
      {
        string tempName = current->productname;
        float tempPrice = current->productprice;
        string tempcompany = current->companyname;
        float tempdiscount = current->discountprice;

        current->productname = nextCurrent->productname;
        current->productprice = nextCurrent->productprice;
        current->companyname = nextCurrent->companyname;
        current->discountprice = nextCurrent->discountprice;

        nextCurrent->productname = tempName;
        nextCurrent->productprice = tempPrice;
        nextCurrent->companyname = tempcompany;
        nextCurrent->discountprice = tempdiscount;
      }
      nextCurrent = nextCurrent->next1;
    }
    current = current->next1;
  }
}

void descending_sorting()
{
  product * current = head1;
  product * nextCurrent = current->next1;
  while(current != NULL)
  {
    nextCurrent = current->next1;
    while(nextCurrent != NULL)
    {
      if(current->productprice < nextCurrent->productprice)
      {
        string tempName = current->productname;
        float tempPrice = current->productprice;
        string tempcompany = current->companyname;
        float tempdiscount = current->discountprice;

        current->productname = nextCurrent->productname;
        current->productprice = nextCurrent->productprice;
        current->companyname = nextCurrent->companyname;
        current->discountprice = nextCurrent->discountprice;

        nextCurrent->productname = tempName;
        nextCurrent->productprice = tempPrice;
        nextCurrent->companyname = tempcompany;
        nextCurrent->discountprice = tempdiscount;
      }
      nextCurrent = nextCurrent->next1;
    }
    current = current->next1;
  }
}

void updateproduct()
{
  product *c= head1;
  bool flag = false;
  string update_company,update_product;
  float update_price,update_dis,update_discountprice;
  cout << "Enter name of the Company you want to update:  ";
  cin >> update_company;

  while (c != NULL)
  {
    if (c->companyname == update_company)
    {
      gotoxy(0, 11);
      cout << "Enter new name of Product:";
      gotoxy(33, 11);
      cout << "Enter new price of Product:";
      gotoxy(65, 11);
      cout << "Enter new name of Company:";

      gotoxy(0, 12);
      cin >> update_product;
      gotoxy(33, 12);
      cin >> update_price;
      if (update_price > 1500)
      {
        update_dis = update_price * 10 / 100;
        update_discountprice = update_price - update_dis;
      }
      gotoxy(65, 12);
      cin >> update_company;
      cout << endl;

      gotoxy(0, 14);
      cout << "Your product has been updated successfully!!" << endl;

      c->productname = update_product;
      c->productprice = update_price;
      c->companyname = update_company;
      c->discountprice = update_discountprice;
      flag = true;
    }
    else
    {
      flag = false;
    }
    c=c->next1;
  }

  if (flag == false)
  {
    cout << "Invalid Company Name." << endl;
  }
}

bool deleteproduct()
{
  product *temp1 = head1;
  product *prev = head1;
  string company;
  gotoxy(0, 7);
  cout << "Enter the Company name to delete the Product:";
  gotoxy(0, 8);
  cin >> company;
  while (temp1 != NULL)
  {
    if (company == temp1->companyname)
    {
      gotoxy(14, 11);
      cout << "Found Company name." << endl;
      prev->next1 = temp1->next1;
      delete temp1;
      return 1;
    }

    else
    {
      prev = temp1;
      temp1 = temp1->next1;
    }
  }
  return 0;
}

void addNewUser()
{
  string username;
  string password;
  string role;
  gotoxy(0, 8);
  cout << "Enter username........ ";
  gotoxy(30, 8);
  cout << "Enter password........ ";
  gotoxy(60, 8);
  cout << "Enter role........";
  gotoxy(0, 9);
  cin >> username;
  gotoxy(30, 9);
  cin >> password;
  
  while (true)
  {
    gotoxy(60, 8);
    cout << "Enter role........";
    gotoxy(60, 9);
    cin >> role;
    if (role != "CUSTOMER" && role != "EMPLOYER")
    {
      gotoxy(60,10);
      cout << "Again enter the Role." << endl;
    }
    else
    {
      break;
    }
  }
  
  addUser(username, password, role);
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

void addcustomer()
{
  string customername,nam,mod,pro;
  int datee;
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
  cin >> customername;
  while (true)
  {
    gotoxy(35,9);
    cout << "Date: ";
    gotoxy(35,10);
    cin >> datee;
    if (datee < 0 || datee >= 32)
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
  cin >> nam;
  
  gotoxy(0,14);
  cin >> mod;
  
  gotoxy(35,14);
  cin >> pro;
     
  addcustomerIntoArray(customername,datee,nam,mod,pro);
}

void addcustomerIntoArray(string cname,int date,string name,string model,string product)
{
  customer *record2 = new customer;
  record2->customername = cname;
  record2->datee = date;
  record2->mod = model;
  record2->nam = name;
  record2->pro = product;
  record2->next2 = NULL;

  if(head2 == NULL)
  {
    head2 = record2;
  }

  else
  {
    customer *temp2 = getLastCustomer(head2);
    temp2->next2 = record2;
  }
  
}  

customer *getLastCustomer(customer *temp2)
{
  while(temp2->next2 != NULL)
  {
    temp2 = temp2->next2;
  }
  return temp2;
} 

void addbooking()
{
  char b;
  cout << "Booking(Press Y for Yes or N for No for Booking):";
  cin >> b;

  addBookingIntoArray(b);
}

void addBookingIntoArray(char book)
{
  booking *record3 = new booking;
  record3->b = book;
  record3->next3 = NULL;
  if(head3 == NULL)
  {
    head3 = record3;
  }

  else
  {
    booking *temp3 = getLastBooking(head3);
    temp3->next3 = record3;
  }
}

booking *getLastBooking(booking *temp3)
{
  while(temp3->next3 != NULL)
  {
    temp3 = temp3->next3;
  }
  return temp3;
}

void calculateBill(washPrice list)
{
  product *temp1 = head1;
  customer *temp2 = head2;
  bool isFound = false;
  string customername,product;
  gotoxy(0,9);
  cout <<"1. Customer Name: ";
  gotoxy(22,9);
  cin >> customername;
  while(temp2 != NULL)
  {
    if( temp2->customername == customername)
    {
      isFound = true;
      gotoxy(0,10);
      cout << "2. Date: " ;
      gotoxy(22,10);
      cout << temp2->datee << endl;
      gotoxy(0,11);
      cout << "3. Car/Bike Service: ";
      gotoxy(22,11);
      cout << temp2->nam << endl;
      if(temp2->nam == "car")
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
      cout << temp2->mod << endl;
      gotoxy(0,14);
      cout << "6. Product Name: ";
      gotoxy(22,14);
      cout << temp2->pro << endl;
      product = temp2->pro;
      cout << endl;
      break;
    }
    temp2 = temp2->next2;
  }


  int f;
  while(temp1 != NULL)
  {
    if(temp1->companyname == product)
    {
      f=temp1->productprice;

      if (f < 1500)
      {
        temp1->discount = temp1->productprice * 5 / 100;
        temp1->discountprice = temp1->productprice - temp1->discount;
      }

      else
      {
        temp1->discount = temp1->productprice * 10 / 100;
        temp1->discountprice = temp1->productprice - temp1->discount;
      }
      cout << "hello" << endl;
      cout << "------------    -----   ------- -------------" << endl;
      cout << "Product name\tPrice\tCompany\tdiscountprice" << endl;
      cout << "------------    -----   ------- -------------" << endl;
      cout << temp1->productname << " \t" << temp1->productprice << " \t" << temp1->companyname << " \t" << temp1->discountprice << endl;

      break;
    }   
  }
}

void addamount()
{
  float num1,num2,amount;
  gotoxy(0,21);
  cout << "7. Price of Service: ";
  gotoxy(22,21);
  cin >> num1;
  gotoxy(0,22);
  cout << "8. Price of Product: ";
  gotoxy(22,22);
  cin >> num2;
  amount = num1 + num2;
  gotoxy(0,23);
  cout << "9. Amount: ";

  addAmountIntoArray(num1,num2,amount);
  gotoxy(22,23);
  cout << amount << endl;
}

void addAmountIntoArray(float n1,float n2,float a)
{
  totalamount *record4 = new totalamount;
  record4->num1 = n1;
  record4->num2 = n2;
  record4->amount = a;
  record4->next4 = NULL;

  if(head4 == NULL)
  {
    head4 = record4;
  }
  else
  {
    totalamount *temp4 = getLastAmount(head4);
    temp4->next4 = record4;
  }
}

totalamount *getLastAmount(totalamount *temp4)
{
  while(temp4->next4 != NULL)
  {
    temp4 = temp4->next4;
  }
  return temp4;
}

void addEmployeUser()
{
  string username,password,role;
  gotoxy(0, 8);
  cout << "Enter username........ ";
  gotoxy(30, 8);
  cout << "Enter password........ ";
  gotoxy(60, 8);
  cout << "Enter role........";
  gotoxy(0, 9);
  cin >> username;
  gotoxy(30, 9);
  cin >> password;

  while (true)
  {
    gotoxy(60, 8);
    cout << "Enter role........";
    gotoxy(60, 9);
    cin >> role;
    if (role== "ADMIN" || role == "EMPLOYER")
    {
      gotoxy(60,10);
      cout << "Again enter the Role." << endl;
    }
    else
    {
      break;
    }
  }
  
  addUser(username, password, role);
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

void store()
{ //___________FIlehandlinng store data
  product *temp1 = head1;
  fstream myfile;
  myfile.open("list.txt", ios::out);
  while (temp1->next1 != NULL)
  {
    myfile << temp1->productname << "," << temp1->productprice << "," << temp1->companyname << endl;
    temp1 = temp1->next1;
  }
  myfile.close();
}

string parseData(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount++;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}

void loadData(int count_pro)
{
  float dis,dprice;
  fstream fileVariable;
  fileVariable.open("list.txt", ios::in);
  string record;
  while(!(fileVariable.eof()))
  {
    getline(fileVariable, record);
    string product = parseData(record, 1);
    float price = stof(parseData(record, 2));
    string company = parseData(record, 3);
    dprice = stof(parseData(record,4));
    addproductsIntoArray(count_pro,product,price,company,dis,dprice);
  }
}
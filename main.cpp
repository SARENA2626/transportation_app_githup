#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <vector>
#include <ctime>
#include<cmath>
using namespace std;

/*base class (abstract class) (Uber,bus,metro,flight) inherit from it (Hierarchical inheritance)*/
class Vehicle{
protected:
    string model;
    string brand;
    int number;
    string color;
    int maximumCapacity;
    string currentLocation;
public:
    //default constructor
    Vehicle(){ model=" ";brand=" ";number=0;color=" ";maximumCapacity=0;currentLocation=" ";}
    // Parameterized constructor
    Vehicle(string m,string b,int n,string c,int x,string l):model(m),brand(b),number(n),color(c),maximumCapacity(x),currentLocation(l){}
    //Copy Constructor
    Vehicle (Vehicle& obj){
    model=obj.model;
    brand=obj.brand;
    number=obj.number;
    color=obj.color;
    maximumCapacity=obj.maximumCapacity;
    currentLocation=obj.currentLocation;
    }
    //setter methods
    void setModel(string m){
        model=m;

    }
    void setBrand(string b){
        brand=b;
        }
    void setNumber(int n){
            number=n;
        }
     void setColor (string c){
         color=c;
     }
      void setMaximumCapacity(int x ){
          maximumCapacity=x;

     }
     void setCurrentLocation(string l ){
          currentLocation=l;
     }
     //display data
      void display(){
          cout<<"Model:"<<model<< endl;
          cout<<"Brand:"<<brand<<endl;
          cout<<"Number:"<<number<<endl;
          cout<<"Color:"<<color<<endl;
          cout<<"Maximum Capacity:"<<maximumCapacity<<endl;
          cout<<"Current Location:"<<currentLocation<<endl;
      }
      virtual double price() =0;
      virtual void booking() =0;
      ~Vehicle(){}
};

class metro :public Vehicle {
private:
    string source;
    string destination;
    double price1,totalPrice;
    int numstations;

public:
    metro() : source(""), destination(""), price1(0.0), numstations(0),totalPrice(0.0), Vehicle("","",0,"",0,""){}
    metro(string s, string des, double p, int n, double totalP,string m,string b,int f,string c,int x,string l) : source(s), destination(des), price1(p), numstations(n), totalPrice(totalP), Vehicle(m,b,f,c,x,l) {}
    metro(metro &object): source(object.source),destination(object.destination), price1(object.price1), numstations(object.numstations){
        model=object.model;
        brand=object.brand;
        number=object.number;
        color=object.color;
        maximumCapacity=object.maximumCapacity;
        currentLocation=object.currentLocation;}
    ~metro() {
        cout << "enjoy (:" << endl;
    }

    void viewoffers() {
        cout << "1 - The normal daily ticket offers are:\n 9 stations for 10 L.E \n 16 stations for 12 L.E\n 23 stations for 18 L.E" << endl;
        cout << "2 - The monthly card offer is 70 L.E" << endl;
        cout << "3 - The annual card offer is 500 L.E" << endl;
    }

        double price() {
        string offer;
        int ticketNo,confirmTicket;
        while(true){
        while(confirmTicket!=ticketNo){
        cout<<"how many tickets do you want: ";
        cin>>ticketNo;
        cout<<"please confirm the ticket number do you want: ";
        cin>>confirmTicket;
        if(confirmTicket!=ticketNo){
            cout<<"your entered confirmation is not matching the number of tickets please enter the number of tickets again"<<endl;
        }
        else{
            cout<<"so number of tickets do you want to book is: "<<ticketNo<<endl;
        }
        }
        cout << "Enter the offer you want:\n1 - Monthly\n2 - Annual\n3 - Number of stations" << endl;
        cin >> offer;
        if (offer == "1") {
            price1 = 70;

            totalPrice= ticketNo*price1;
            cout << "The price is: " <<totalPrice<< " L.E" << endl;
            break;  // any break is to exit the loop
        } else if (offer == "2") {
            price1 = 500;
            totalPrice= ticketNo*price1;
            cout << "The price is: " <<totalPrice<< " L.E" << endl;
            break;
        } else if (offer == "3") {
            cout << "Enter the number of stations: ";
            cin >> numstations;
            if (numstations <= 9) {
                price1 = 10;
                totalPrice= ticketNo*price1;
            } else if (numstations <= 16) {
                price1 = 12;
                totalPrice= ticketNo*price1;
            } else if (numstations <= 23) {
                price1 = 18;
                totalPrice= ticketNo*price1;
            } else {
                cout << "Wrong entry" <<endl;
                continue;  // Restart the loop to allow the user to enter a valid number of stations
            }
            cout << "The price is: " <<totalPrice<< " L.E" << endl;
            break;
        }
            else {
            cout << "Wrong entry" << endl;
        }
        }
        return totalPrice;
    }

    void booking() {
        string date,time;
        cout<<"enter the date you want to book your trip in days and month (as 24/3):"<<endl;
        cin>>date;
        cout<<"enter the time you want your trip in hours (as 14:00):"<<endl;
        cin>>time;
        cout<<"enter the source and the destination:"<<endl;
        cout<<"From: ";
        cin>>source;
        cout<<"To: ";
        cin>>destination;
        cout << "so here is your ticket information:" << endl;
        cout << "From: " << source <<endl;
        cout << "To: " << destination <<endl;
        cout << "Date of your trip: " << date<<endl<<"Time of your trip: "<<time<<endl;
    }

    void paying(int paymentMethod, string accountNo, string password, double balance, double price1,string confirm)
    { balance=400; // Assuming initial balance is 400 L.E
        while(true){
        cout << "The price is: " <<totalPrice<< " L.E" << endl;
        cout << "Choose the payment method:\n1 - Cash\n2 - Visa" <<endl;
        cin >> paymentMethod;
        if (paymentMethod == 2) {
            cout << "Enter the account number and the password"<<endl;
            cout<<"account number: ";
            cin>> accountNo;
            cout<<"password: ";
            cin>> password;
            cout<<"Please confirm the password: ";
            cin>>confirm;
            while(password!=confirm){
                cout<<"sorry you entered a wrong password enter the confirmation again: "<<endl;
                cin>>confirm;
            }
                cout<<"so your password is confirmed as: "<<password<<endl;
            if (totalPrice<= balance) {
                balance -= totalPrice;
                cout << "Successful operation" << endl;
                cout<<"your balance now is: "<<balance<<" L.E"<<endl;
             break;
            }else {
                cout << "Your balance is not enough" << endl;
                cout<<"---------Please check your balance or any errors in your visa with the bank--------"<<endl;
                break;
            }
        }
        else if(paymentMethod==1){
            cout<<"The price is: "<<totalPrice<<" L.E"<<endl;
            cout<<"please call 19000 to give you your ticket code and go to the nearest metro station to pay your ticket/s fees in cash"<<endl;
            break;
        }
        else{
            cout<<"sorry not a payment method try to choose a right payment method again"<<endl;
        }
        }
    }
    void choice(){
    string source, destination, date, offer, password,time,accountNo,confirm;
    int numstations, paymentMethod,ticketNo, confirmTicket;
    double price1,totalPrice,balance;
    viewoffers();
    price();
    booking();
    paying(paymentMethod, accountNo, password, balance, price1, confirm);
    }
};

class Uber : public Vehicle {
public:
string c_name;
string plate;
int c_num;
string c_phone;
int rate;
int trip_type;
string destination;
int hours;
int minutes;
int hours_end;
int minutes_end;
char check_end;
int pay_method;
int acc_num;
int visa_pass;
int cost;
int choise_drive;
string contin;

Uber() : cost(100), Vehicle("","",0,"",0,""){}

Uber(int r, string a, string b, string c, string d, string e,string f)
{
    c_num=r;
    c_name=a;
    brand=b;
    model=c;
    color=d;
    plate=e;
    c_phone=f;
}
Uber(Uber& obj) {
c_name = obj.c_name;
plate = obj.plate;
brand=obj.brand;
model=obj.model;
color = obj.color;
c_phone = obj.c_phone;
c_num = obj.c_num;
model=obj.model;
brand=obj.brand;
number=obj.number;
color=obj.color;
maximumCapacity=obj.maximumCapacity;
currentLocation=obj.currentLocation;
}

~Uber() { cout << " "; }
void strat() {
cout << "   * * * * * * * * * * * * *" << endl;
cout << "   *        TransWAy       *" << endl;
cout << "   * * * * * * * * * * * * *" << endl;
cout << "   * * * * * * * * * * * * *" << endl;
cout << "   *        1-RIDE         *" << endl;
cout << "   * * * * * * * * * * * * *" << endl;
cout << "   *       2-comfort       *" << endl;
cout << "   * * * * * * * * * * * * *" << endl;
cout << "   *        3-Moto         *" << endl;
cout << "   * * * * * * * * * * * * *" << endl;
cout << "   *       4-Mini Bus      *" << endl;
cout << "   * * * * * * * * * * * * *" << endl;
cout << "Choose your trip type: " << endl;
cin >> trip_type;
}

void display() {
cout << "\n**" << endl;
cout << "[" << c_num << "]" << endl;
cout << "captain name: " << c_name << endl;
cout << "Model: " << model << endl;
cout << "Brand: " << brand << endl;
cout << "Color: " << color << endl;
cout << "plate number: " << plate << endl;
cout << "phone number: " << c_phone << endl;

}

void request() {
cout << "Enter your location: " << endl;
cin.ignore();
getline(cin, currentLocation);
cout << "\nEnter destination: " << endl;
getline(cin, destination);
cout << "Enter the start time of the trip: " << endl;
cout << "Hours: ";
cin >> hours;
cout << "Minutes: ";
cin >> minutes;
Uber tt(1,"Ahmed ziad","Hundai","sedan" , "red","FJI297","01149070539");
Uber ri1(tt);
Uber ri2(2,"mahmoud saber","sheforle","sedan" ,"Black","MSR597","01546237529");
Uber ri3(3,"Ali gamal","BYD","sedan" ,"Grey","KNC285","01009375936");

Uber com1(1,"wael mostafa","KIA","Fusion","Black","MEU528","01001875936");
Uber com2(2,"Mohamed maged","Nissan","Fusion","BLue","DZW235","01132735877");
Uber com3(3,"Mahmoud ali","Toyota","Fusion","Black","RSH395","01001769265");

Uber moto1(1,"Mmohamed mahrous","Yamaha XForce","Yamaha","Blue","DX283","01002398453");
Uber moto2(2,"Tarek hamed","Kawasaki","Yamaha","Red","ZSC275","01001769265");
Uber moto3(3,"farouk gaafar","Honda PCX125","Yamaha","Gray","WUB275","01135836322");

Uber bus1(1,"Mohamed sherif","Toyota Hiace","Toyota","Whiet","RNC521","01003825294");
Uber bus2(2,"Mohamed hesham","Toyota Diesel","Toyota","Black","YIP429","0113536722");
Uber bus3(3,"Ziad waleed","suzuki","Toyota","Red","SHP835","01135836223");

if (trip_type == 1) {
ri1.display();
ri2.display();
ri3.display();
}

if (trip_type == 2) {
com1.display();
com2.display();
com3.display();
}
if(trip_type == 3)
{


moto1.display();
moto2.display();
moto3.display();
}
if (trip_type == 4) {
bus1.display();
bus2.display();
bus3.display();
}

cout << "\n\nChoose driver from list: " << endl;
cin >> choise_drive;
system("cls");

if (trip_type == 1) {
if (choise_drive == 1) { ri1.display(); }
else if (choise_drive == 2) { ri2.display(); }
else if (choise_drive == 3) { ri3.display(); }
}

if (trip_type == 2) {
if (choise_drive == 1) { com1.display(); }
else if (choise_drive == 2) { com2.display(); }
else if (choise_drive == 3) { com3.display(); }
}

if (trip_type == 3) {
if (choise_drive == 1) { moto1.display(); }
else if (choise_drive == 2) { moto2.display(); }
else if (choise_drive == 3) { moto3.display(); }
}

if (trip_type == 4) {
if (choise_drive == 1) { bus1.display(); }
else if (choise_drive == 2) { bus2.display(); }
else if (choise_drive == 3) { bus3.display(); }
}

}

void End() {
cout << "\n\nYou have reached your destination. Enter (Y) to end your trip: ";
cin >> check_end;
while (check_end != 'Y') {
cout << "Invalid input. Enter (Y) to end your trip: ";
cin >> check_end;
}
cout << "\nEnter the trip end time: " << endl;
cout << "Hours: ";
cin >> hours_end;
cout << "Minutes: ";
cin >> minutes_end;

cost = abs((hours_end - hours) * 120) + abs(((minutes_end - minutes) * 2));
if (trip_type == 2) {
cost *= 2;
}
if (trip_type == 3) {
cost *= 0.5;
}
if (trip_type == 4) {
cost *= 1.75;
}

cout << "Cost: " << cost << endl;
cout << "Select payment method: " << endl;
cout << "1-Cash" << endl << "2-Visa" << endl;
cin >> pay_method;
if (pay_method == 2) {
cout << "Enter the account number: " << endl;
cin >> acc_num;
cout << "Enter password: " << endl;
cin >> visa_pass;
}
cout << "\nThank you" << endl;
cout << "\nEnter any key then Enter to continue: " << endl;
cin >> contin;

system("cls");

}

    void rating() {
        cout << "Rate your trip:" << endl;
        cout << "1-Excellent" << endl;
        cout << "2-Very Good" << endl;
        cout << "3-Good" << endl;
        cout << "4-Fair" << endl;
        cout << "5-Bad" << endl;
        cin >> rate;
        cout << "Thank you for your rating" << endl;
    }

    double price() override {
        // Implementation for price calculation
        // For example, return a fixed price for simplicity
        return 10.0; // Change this to your actual price calculation
    }

    void booking() override {
        // Implementation for booking functionality
        // You can add code here to handle the booking process
        cout << "Booking Uber ride..." << endl;
    }

void choise()
{
strat();
request();
End();
rating();
}

};

class Flight : public Vehicle {
    protected:
        static int totalTickets;
        string origin;
        string destination;
        int adults;
        int children;
        int infants;
        string categories[2] = { "Business Class", "Economy Class" };
        int year;
        int month;
        int day;
    public:
    Flight(): Vehicle("","",0,"",0,"") {
    }
    Flight(string m,string b,int f,string c,int x,string l,string o,string de,int ad,int ch,int in):Vehicle(m,b,f,c,x,l), origin(o),destination(de),adults(ad),children(ch),infants(in){}
    Flight(Flight&obj){
        origin=obj.origin;
        destination=obj.destination;
        adults=obj.adults;
        children=obj.children;
        infants=obj.infants;
        model=obj.model;
        brand=obj.brand;
        number=obj.number;
        color=obj.color;
        maximumCapacity=obj.maximumCapacity;
        currentLocation=obj.currentLocation;
    }

    bool isDateValid(int y, int m, int d) {
        // Get the current date
        time_t now = time(0);
        tm *currentTime = localtime(&now);
        int currentYear = currentTime->tm_year + 1900;
        int currentMonth = currentTime->tm_mon + 1;
        int currentDay = currentTime->tm_mday;

        // Check if the entered date is in the future
        if (y > currentYear  ||(y == currentYear && m > currentMonth) ||(y == currentYear && m == currentMonth && d >= currentDay)) {
            return true;
        }
        else {
            return false;
        }
    }

    void inputFlightDate() {
        bool validDate = false;
        while (!validDate) {
            cout << "Enter the day of your flight: ";
            cin >> day;
            cout << "Enter the month of your flight: ";
            cin >> month;
            cout << "Enter the year of your flight: ";
            cin >> year;

            // Check if the entered date is valid
            if (isDateValid(year, month, day)) {
                validDate = true;
            }
            else {
                cout << "You have entered a past date. Please enter a valid date.\n";
            }
        }
    }


void choosePassengerTY() {
        system("cls");
        cout << "Please fill the following questions for passenger types:" << endl;
        vector<string> passengerTypes = { "Adults", "Children", "Infants" };
        for (int i = 0; i < passengerTypes.size(); i++) {
            string choice;
            cout << "Do you have " << passengerTypes[i] << "? (yes or no): ";
            cin >> choice;
            if (choice == "yes") {
                cout << "Enter the number of " << passengerTypes[i] << ": ";
                int numPassenger;
                cin >> numPassenger;
                if (i == 0) {
                    adults = numPassenger;
                }
                else if (i == 1) {
                    children = numPassenger;
                }
                else {
                    infants = numPassenger;
                }
                totalTickets += numPassenger;
            }
            else {
                if (i == 0) {
                    adults = 0;
                }
                else if (i == 1) {
                    children = 0;
                }
                else {
                    infants = 0;
                }
            }
        }
        system("cls");
    }

    void displayCategories() {
        cout << "Please choose your flight category: \n";
        for (int i = 0; i < 2; i++) {
            cout << i + 1 << "." << categories[i] << endl;
        }
    }

    string getFlightCategory() {
        int choice;
        displayCategories();
        cout << "Enter your choice (1-2): ";
        cin >> choice;
        switch (choice) {
        case 1:
            return categories[0];
        case 2:
            return categories[1];
        default:
            cout << "Invalid choice. Please choose a valid option (1-2).\n";
            return getFlightCategory();
        }
    }
   double price() {
        int adultPrice;
        int childPrice;

        if (categories[0] == "Business Class") {
            adultPrice = 1400;
            childPrice = 1000;
            cout << "Booking through Business Class. Prices: Adults - $1400, Children - $1000\n";
        } else {
            adultPrice = 1000;
            childPrice = 600;
            cout << "Booking through Economy Class. Prices: Adults - $1000, Children - $600\n";
        }
        int infantPrice = 0;

        // Calculate total price
        int total = (adults * adultPrice) + (children * childPrice) + (infants * infantPrice);
        return total;
    }
    void booking() {
        system("cls");
        cout << "Your flight is from: " << origin << endl;
        cout << "To: " << destination << endl;
        cout << "Date of Flight: " << day << "/" << month << "/" << year << endl;
        cout << "Adults: " << adults << endl;
        cout << "Children: " << children << endl;
        cout << "Infants: " << infants << endl;
        cout<<"the total price of your booking : "<< price()<<endl;
    }

    static int getTotalTickets() {
        return totalTickets;
    }


void choice(){
            cout<<"welcome to our flight booking site hope you have the best experience"<<endl;
        cout<<""<<endl<<endl;
    int adults(0),children(0),infants(0),year(0),month(0),day(0);
        cout << "Enter origin location: ";
        cin.ignore();
        getline(cin, origin);
        cout << "Enter destination location: ";
        cin.ignore();
        getline(cin, destination);
        system("cls");

        // Get the current date
        time_t now = time(0);
        tm *currentTime = localtime(&now);
        year = currentTime->tm_year + 1900;
        month = currentTime->tm_mon + 1;
        day = currentTime->tm_mday;

    inputFlightDate();
    choosePassengerTY();
    string category = getFlightCategory();
    booking();
    cout << "Total tickets booked: " << getTotalTickets() << endl;



}
~Flight(){};

};

int Flight::totalTickets = 0;

class Bus : public Vehicle {
public:
    string bus_number;
    vector<string> stations;
    double price_per_station;
    int max_speed;
    string plate_number;
    double number_of_stations;
    Bus(): bus_number(""), stations(vector<string>()), price_per_station(10.0), max_speed(0), plate_number(""), number_of_stations(0.0),
         Vehicle("","",0,"",0,""){}

    Bus(string m, string b, int n, string c, int ms, string pn, int bc, string bn, string l, int p, vector<string> s) :
        Vehicle(m, b, n, c, bc, l),
        bus_number(bn),
        price_per_station(p),
        stations(s),
        max_speed(ms),
        plate_number(pn) {}


    Bus (Bus&obj){
        bus_number =obj.bus_number;
        max_speed=obj.max_speed;
        plate_number=obj.plate_number;
        number_of_stations=obj.number_of_stations;
        model=obj.model;
        brand=obj.brand;
        number=obj.number;
        color=obj.color;
        maximumCapacity=obj.maximumCapacity;
        currentLocation=obj.currentLocation;
    }

    double price() override {
return abs(number_of_stations)*price_per_station;
    }
    void booking() override {}

        void setNumberOfStations(int numberOfStations) {
        number_of_stations = numberOfStations;
    }

    void display() {
        cout << "\t----------------" << endl;
        cout << "\tBus " << bus_number << endl;
        Vehicle::display();
        cout << "\tMax speed : " << max_speed << " km/h" << endl;
        cout << "\tPlate number : " << plate_number << endl;
        cout << "\tPrice per station : " << price_per_station << " EGP" << endl;
        cout << "\tStations : " << endl;
        for (int i = 0; i < stations.size(); i++) {
            cout << "\t\t" << i + 1 << " : " << stations[i] << endl;
        }
    }

    void display_short() {
        cout << "\t----------------" << endl;
        cout << "\tBus " << bus_number << endl;
        cout << "\tStations : ";
        for (int i = 0; i < stations.size(); i++) {
            cout << stations[i];
            if (i != stations.size() - 1) {
                cout << " --> ";
            }
            else {
                cout << endl;
            }
        }
    }

 void Bus_choice();

};

void Bus_choice() {
    Bus M1("2020", "brand1", 123, "blue", 80, "123ABC", 50, "M1", "Cairo", 10,
        {"Maskn", "Helmya", "Abbasia", "Ramsis", "Hosary"});
    Bus M2("2021", "brand2", 124, "black", 80, "456DEF", 50, "M2", "Cairo", 10,
        {"Khafres Gate", "Mashal", "Cairo university", "Abdel Moneim Riad"});
    Bus M3("2022", "brand3", 342, "red", 80, "342RTD", 50, "M3", "Giza", 10,
        {"Cairo university", "Haram", "Hadayiq alahram", "Hosary", "Laylat al-Qader"});
    Bus Cairo_Alex("2023", "brand4", 119, "yellow", 100, "345FRD", 50, "118",
        "Cairo", 100,
        {"Cairo", "Benha", "Alexandria"});
    Bus Giza_Sharm_EL_shaikh("2019", "brand5", 120, "purple", 100, "342ASA", 50,
        "121", "Giza", 100,
        {"Giza", "Hurghada", "Sharm EL-shaikh"});
    Bus Cairo_Dahab("2024", "brand6", 127, "orange", 100, "564DDE", 50, "122",
        "Cairo", 100,
        {"Cairo", "Hurghada", "Dahab"});

    int choice;
    cout << "Choose Options (1-Daily Transportation, 2-Travel Transportation): ";
    cin >> choice;

    if (choice == 1) {
        cout << "\tHere is a list of all our available buses for daily transportation. Please choose a bus" << endl;
        cout << "\t**" << endl;
        cout << "\t1." << endl;
        M1.display_short();
        cout << "\t2." << endl;
        M2.display_short();
        cout << "\t3." << endl;
        M3.display_short();
        cout << "\t7. Go back." << endl;
    }
    else {
        cout << "\tHere is a list of all our available buses for travel transportation. Please choose a bus" << endl;
        cout << "\t**" << endl;
        cout << "\t4." << endl;
        Cairo_Alex.display_short();
        cout << "\t5." << endl;
        Cairo_Dahab.display_short();
        cout << "\t6." << endl;
        Giza_Sharm_EL_shaikh.display_short();
        cout << "\t7. Go back." << endl;
    }

    int bus_choice;
    cout << "Enter the bus number you want to book: ";
    cin >> bus_choice;
    int start_station, end_station;

    if (choice == 1) {
        switch (bus_choice) {
        case 1:
            system("cls");
            M1.display();
            cout << "\tPlease enter the number of your start station : ";
            cin >> start_station;
            cout << "\tPlease enter the number of your end station : ";
            cin >> end_station;
            M1.setNumberOfStations(end_station - start_station);
            system("cls");
            cout << "-->There is a bus that passes every quarter of an hour" << endl;
            cout << "\tYour ride price will be : " << M1.price() << " EGP" << endl;
            cout <<"Thank you for choosing us.";
            break;
        case 2:
            system("cls");
            M2.display();
            cout << "\tPlease enter the number of your start station : ";
            cin >>start_station ;
            cout << "\tPlease enter the number of your end station : ";
            cin >>end_station;
            M2.setNumberOfStations(end_station - start_station);
            system("cls");
            cout << "-->There is a bus that passes every quarter of an hour." << endl;
            cout << "\tYour ride price will be : " << M2.price() << " EGP" << endl;
            cout <<"Thank you for choosing us.";
            break;
        case 3:
            system("cls");
            M3.display();
            cout << "\tPlease enter the number of your start station : ";
            cin >>start_station ;
            cout << "\tPlease enter the number of your end station : ";
            cin >>end_station;
            M3.setNumberOfStations(end_station - start_station);
            system("cls");
            cout << "-->There is a bus that passes every quarter of an hour." << endl;
            cout << "\tYour ride price will be : " << M3.price() << " EGP" << endl;
            cout <<"Thank you for choosing us.";

            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    else {
        switch (bus_choice) {
        case 4:
            system("cls");
            Cairo_Alex.display();
            cout << "\tPlease enter the number of your end station : ";
            cin >> end_station;
            Cairo_Alex.setNumberOfStations(end_station - 1);
            cout << "Meeting point for moving is Ramesses" << endl;
            cout << "Moving hour is 9:00 AM" << endl;
            cout << "The price of the ticket is " << Cairo_Alex.price() << " EGP" << endl;
            cout <<"Thank you for choosing us.";
            break;
        case 5:
            system("cls");
            Cairo_Dahab.display();
            cout << "\tPlease enter the number of your end station : ";
            cin >> end_station;
            Cairo_Dahab.setNumberOfStations(end_station - 1);
            cout << "Meeting point for moving is Ramesses" << endl;
            cout << "Moving hour is 7:00 AM" << endl;
            cout << "The price of the ticket is " << Cairo_Dahab.price() << " EGP" << endl;
            cout <<"Thank you for choosing us.";
            break;
        case 6:
            system("cls");
            Giza_Sharm_EL_shaikh.display();
            cout << "\tPlease enter the number of your end station : ";
            cin >> end_station;
            Giza_Sharm_EL_shaikh.setNumberOfStations(end_station - 1);
            cout << "Meeting point for moving is Bulaq Dakrur" << endl;
            cout << "Moving hour is 6:00 AM" << endl;
            cout << "The price of the ticket is " << Giza_Sharm_EL_shaikh.price() << " EGP" << endl;
            cout <<"Thank you for choosing us.";
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

}

/*Person class*/
class Person{
protected:
    string Username,password,phoneNumber,nationalId;
    int age;
    static int accountNumb;
public :
//Default Constructor
  Person ():Username (""),password(""),phoneNumber(""),nationalId(""),age(0){}
//Parameterized Constructor
Person (string name, string pass,string ph,string tionalId ,int ag): Username (name),password (pass),phoneNumber(ph),nationalId(tionalId),age(ag) {}
//Copy Constructor
Person (Person & obj){
Username = obj.Username;
password=obj.password;
phoneNumber=obj.phoneNumber;
nationalId=obj.nationalId;
age=obj.age;
}

//setter
  void setname(string name){
  Username=name;
  }
  void setpass(string pass){
  password=pass;
  }
  void setphone(string ph){
  phoneNumber=ph;
  }
  void setnationalId(string na){
  nationalId=na;
  }
  void setage(int ag){
  age=ag;
  }

//getter
  string getname(){
  return Username;
  }
  string getpass(){
  return password;
  }
  string getph(){
  return phoneNumber;
  }
  string getnational(){
  return nationalId;
  }
  int getage(){
  return age;
  }
  static int getanumber(){
  //to count the numbers of accounts that made
  return accountNumb;
  }

//registration/
  void registration (){
  system("cls");
  string name,pass,confirmPass,number,national;
  int agein;
  cout<<"\tEnter Login Username: ";
  cin>>name;
  setname(name);
      start:
  cout<<"\tEnter A Strong Password: ";
  cin>>pass;
     if(pass.length()>=8){
     setpass(pass);
     }
     else {
     cout<<"\tEnter Minimum 8 Characters!"<<endl;
     goto start;
     }
  cout<<"\tPlease Enter The Password Again To Confirm It: ";
  cin>>confirmPass;
  while (confirmPass!=pass){
  cout<<"\tError Your Confirm Password Does Not Match The Password !!\n"<<"\tTry Again : ";
  cin>>confirmPass;
  }
  cout<<"\tEnter Your Phone Number: ";
  cin>>number;
  setphone(number);
  cout<<"\tEnter Your National ID: ";
  cin>>national;
  setnationalId(national);
  cout<<"\tEnter your Age: ";
  cin>>agein;
  setage(agein);
  accountNumb++;
    ofstream outfile ("login.txt",ios::app);
    outfile<<getname()<<" : "<<getpass()<<endl;
    outfile.close();
    }

//Login/
  bool loginfun (){
  system("cls");
  string name,pass;
  cout <<"\tEnter Login Username: ";
  cin>>name;
  cout<<"\tEnter Password: ";
  cin>>pass;
    ifstream infile ("login.txt");
    string line;
       while (getline (infile,line)){
       stringstream ss;
       ss<<line;
       string userid,userpass;
       char u;
       ss>>userid>>u>>userpass;
          if (name == userid && pass== userpass){
          setname(name);
          cout <<"\tplease wait";
               for (int i=0;i<3;i++){
               cout<<".";
               Sleep (800);
               }
          return true;
          }
       }
  system("cls");
  cout <<"\tError Incorrect Login ID Or Password!\n\tPlease Try Again"<<endl;
  Sleep(4000);
  return false;
  infile.close();
  }

~ Person (){
}
};

/*Captain Class  inherit from person (is a)*/
class Captain : public Person{
private:
    double kilometers;
    string schedule,type,color;
    double hours;
public:
   // Default constructor
   Captain() :Person("","","","",0), kilometers(0), schedule(""), type(""), color(""), hours(0) {}

   // Parameterized constructor
   Captain(double km, string sch, string t, string c, double hrs,string nam, string pass,string pho,string nit,int ag ) :Person(nam,pass,pho,nit,ag), kilometers(km), schedule(sch), type(t), color(c), hours(hrs) {}

   //Copy constructor
   Captain (Captain & obj){
   kilometers=obj.kilometers;
    schedule=obj.schedule;
    type=obj.type;
    color=obj.color;
    hours=obj.hours;
     Username=obj.Username;
    password=obj.password;
    phoneNumber=obj.phoneNumber;
    nationalId=obj.nationalId;
    age=obj.age;
   }
   //getter
    string getschedule(){
    return schedule;
    }
    string gettype(){
    return type;
    }
    string getcolor(){
    return color;
    }
    int gethours(){
    return hours ;
    }

    // registration for captain (override from person)
    void registration (){
    Person::registration();
    cout <<"\tWhat Is Your Schedule? ";
    cin.ignore();
    getline (cin,schedule);
    cout<<"\tHow Many Hours Do You Want To Work? ";
    cin>>hours;
    cout<<"\tWhat Is Your Vehicle Type? ";
    cin>> type;
    cout<<"\tWhat Is Your "<<type<<"'s Color? ";
    cin >> color;
      string filename=Username+"cap.txt";
      ofstream datafilein (filename);
      datafilein<<"\tName Captain:"<<getname()<<endl
      <<"\tAge: "<<getage()<<endl
      <<"\tPhone Number: "<<getph()<<endl
      <<"\tNational ID: "<<getnational()<<endl
      <<"\tAccount Number: "<<getanumber()<<endl
      <<"\tYour Vehicle Type: "<<gettype()<<endl
      <<"\tYour Vehicle Color : "<<getcolor()<<endl
      <<"\tYour Schedule (Work Days): "<<getschedule()<<endl
      <<"\tNumber Of Hours You Work Per Day:"<<gethours()<<endl;
      datafilein.close();
    system("cls");
    cout<<"\t\tThanks For Registration User Registered Successfully <3\n\n\n-If You Want To Login to Your Account Go to Login"<<endl;
    Sleep(6000);
    }

     //Method to display captain's data
    void displayData(){
    string line;
    string filename=Username+"cap.txt";
      ifstream datafileout(filename);
      cout<<"\t\t\t\t\t##############\n"<<"\t\t\t\t\t*Your Data*\n"<<"\t\t\t\t\t##############\n\n";
      while (getline(datafileout, line)) {
      cout << line << endl;
      }
      cout<<"\t#########################"<<endl;
    }

// Method to calculate salary based on kilometers traveled
double calculateSalary() {
    cout << "Enter The Numbers Of Kilometers Consumed During One Week: " << endl;
    cin >> kilometers;
    double baseSalary = 7000.0;
    double salary = 0.0; // Variable to store the calculated salary

    if (kilometers > 50) {
        salary = baseSalary * 1.2;
        cout << "You have a bonus: " << salary << " LE" << endl;
    }
    else if (kilometers == 50) {
        salary = baseSalary;
        cout << "You have a base salary: " << salary << " LE" << endl;
    }
    else {
        salary = baseSalary * 0.8;
        cout << "You have a discount: " << salary << " LE" << endl;
    }

    return salary; // Return the calculated salary
}

    void options (){
    int opt;
    do{
    system("cls");
    cout<<"Choose Options(1-Captain's Data And Schedule,2-Salary,3-Exit)";
    cin>>opt;
       switch(opt){
       case 1:
         system("cls");
         displayData();
         Sleep(8000);
         break;
       case 2:
         system("cls");
         calculateSalary();
         Sleep(8000);
         break;
       case 3:
         return;
       default:
         cout <<"Error This not an option!!\n";
         Sleep(3000);
       }
    }
    while(opt!=3);

  }

  ~Captain(){}
};

/*User Class inherit from person (is a) and from (Metro,Uber,Flight) (has a) (Association relation)*/
class User : public Person{
private:
    string country;
    string gmail;
    metro m1;
    Uber obj;
    Flight f1;
     //double balance;
public:
    // Default constructor
    User() :Person("","","","",0),country(""),gmail("") {}

   // Parameterized constructor
    User (string nam, string pass,string pho,string nit,int ag,string co,string gm ):Person(nam,pass,pho,nit,ag),country(co),gmail(gm){}

   //Copy constructor
   User (User & obj){
    Username=obj.Username;
    password=obj.password;
    phoneNumber=obj.phoneNumber;
    nationalId=obj.nationalId;
    age=obj.age;
    country=obj.country;
    gmail=obj.gmail;
   }
    //getter
    string getCountry(){
    return country;
    }
    string getGmail (){
    return gmail;
    }
    //setter
    void setCountry (string co){
    country=co;
    }
    void setGmail (string gm){
    gmail=gm;
    }

    // registration for user (override from person)
    void registration (){
    Person::registration();
    string co,gm;
    cout <<"\tWhat Is Your Country: ";
    cin >>co;
    setCountry(co);
    cout <<"\tWhat Is Your Gmail: ";
    cin >>gm;
    setGmail(gm);
      string filename=Username+"user.txt";
      ofstream datafilein (filename);
      datafilein<<"\tName Captain:"<<getname()<<endl
      <<"\tAge: "<<getage()<<endl
      <<"\tPhone Number: "<<getph()<<endl
      <<"\tNational ID: "<<getnational()<<endl
      <<"\tAccount Number: "<<getanumber()<<endl
      <<"\tCountry: "<<getCountry()<<endl
      <<"\tGmail: "<<getGmail()<<endl;
      datafilein.close();
    system("cls");
    cout<<"\t\tThanks For Registration User Registered Successfully <3\n\n\n-If You Want To Login to Your Account Go to Login"<<endl;
    Sleep(6000);
    }

     //Method to display user's data
    void displayData(){
    string line;
    string filename=Username+"user.txt";
      ifstream datafileout(filename);
      cout<<"\t\t\t\t\t##############\n"<<"\t\t\t\t\t*Your Data*\n"<<"\t\t\t\t\t##############\n\n";
      while (getline(datafileout, line)) {
      cout << line << endl;
      }
      cout<<"\t#########################"<<endl;
    }
     // options of the user
    void options (){
    int opt;
    do{
    system("cls");
    cout<<"Choose Options(1-User's data , 2-Metro , 3-Private TransWay , 4-Flight , 5-Bus ,6-Exit)";
    cin>>opt;
       switch(opt){
       case 1:
         system("cls");
         displayData();
         Sleep(8000);
         break;
       case 2:
         system("cls");
         m1.choice();
        Sleep(8000);
         break;
       case 3:
         system("cls");
         obj.choise();
        Sleep(8000);
         break;
         case 4:
         system("cls");
         f1.choice();
         Sleep(8000);
         break;
         case 5:
         system("cls");
         Bus_choice();
         Sleep(8000);
         break;
         case 6:
         return;
       default:
         cout <<"Error This not an option!!\n";
         Sleep(3000);
       }
    }
    while(opt!=6);

  }

  ~User(){}
};

int Person::accountNumb=1000;

int main() {
Captain c1;
Captain c2(2000,"Monday","car","red",7,"Arwa","12345678","0114689435","30416835",18);
Captain c3 (c2);
User u1;
User u2("Sara","12345678","0124342536","30237248",19,"Giza","sarah@gmail.com");
User u3 (u2);
metro m2 ("elharam","Dokki",50.5,200,150,"xx20","yy",700,"yellow",40,"giza");
metro m3 (m2);
Flight f2 ("kk8","ll",28,"black",20,"Alx","giza","Alx",15,4,1);
Flight f3 (f2);
Bus b1;
Bus b2 ("p99","sss",44,"yellow",700,"0888",4,"22","fisal",30,{"Elharam","Giza","Dokki","Elsheikh Zayed"} );
Bus b3 (b2);

bool exit =false ;
int loginas;

//loop to repeat the program till the user want to exit
  do {
  system ("cls");
  int val,enter;
  cout <<"\tWelcome To Transportations Form"<<endl;
  cout <<"\t**********"<<endl;
  cout<<"\t1.Register."<<endl;
  cout<<"\t2.Login."<<endl;
  cout<<"\t3.Exit."<<endl;
  cout<<"\tEnter Choice: "<<endl;
  cin>>val;

     if(val==1){
     system("cls");
     cout<<"What Do You Want To Registration As (1)User-(2)Captain"<<endl;
     cin>>loginas;
         if (loginas==1){
         system("cls");
         u1.registration();
         }
        else if (loginas==2){
         system("cls");
         c1.registration();
         }
        else {
        cout<<"Error!! I Can't Find This Chooes"<<endl;
        }
     }

     else if (val ==2){
     system("cls");
     cout<<"What Do You Want To Login AS (1)User-(2)Captain"<<endl;
     cin>>loginas;
     system("cls");
          if (loginas==1){
             if (u1.loginfun () ){
             u1.options();
             }
          }

          else if (loginas==2){
             if (c1.loginfun () ){
             c1.options();
             }
          }
        else {
        cout<<"Error!! I Can't Find This Chooes"<<endl;
        }
     }
     else if (val ==3){
     system("cls");
     exit=true;
     cout<<"\tGood Luck"<<endl;
     Sleep(3000);
     }
  }
   while (!exit);
return 0;
}


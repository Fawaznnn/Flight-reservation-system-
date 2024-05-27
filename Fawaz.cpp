#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

struct Passenger
{
    string name;
    string passportNumber;
    string CNIC;
    string age;
    string contactNumber;
    string email;
    string cardaddress;
    
    
};

struct Flight 
{
    string PNR;
    string code;
    string name;
    string plane;
    string route;
    string time;
};



const int MAX_FLIGHTS = 25;
Flight availableFlights[MAX_FLIGHTS] = 
{
    {"123", "PF143", "Flight 123", "Boeing 737", "islamabad to Karachi", "11:00"},
    {"456", "PF453", "Flight 456", "Boeing 737", "Islamabad to Multan", "10:00"},
    {"679", "PF234", "Flight 679", "Boeing 777", "Islamabad to Lahore", "12:00"},
    {"677", "PF765", "Flight 677", "Boeing 777", "Islamabad to Faisalabad", "9:00"},
    {"678", "PF673", "Flight 678", "Boeing 737", "Islamabad to Peshawar", "10:00"},
    {"675", "PF184", "Flight 675", "Boeing 747", "Multan to Islamabad", "4:00"},
    {"533", "PF099", "Flight 533", "Boeing 737", "Multan to Karachi", "5:00"},
    {"354", "PF736", "Flight 354", "Boeing 777", "Multan to Lahore", "2:00"},
    {"456", "PF793", "Flight 456", "Boeing 787", "Multan to Faisalabad", "12:00"},
    {"965", "PF247", "Flight 965", "Boeing 747", "Multan to Peshawar", "12:00"},
    {"785", "PF129", "Flight 785", "Boeing 767", "Karachi to Islamabad", "3:00"},
    {"486", "PF583", "Flight 486", "Boeing 737", "Karachi to Lahore", "11:00"},
    {"476", "PF375", "Flight 456", "Boeing 737", "Karachi to Peshawar", "4:00"},
    {"656", "PF349", "Flight 656", "Boeing 777", "Karachi to Multan", "7:00"},
    {"253", "PF473", "Flight 253", "Boeing 737", "Karachi to Faisalabad", "9:00"},
    {"612", "PF284", "Flight 612", "Boeing 747", "Faisalabad to Islamabad", "4:00"},
    {"576", "PF294", "Flight 567", "Boeing 767", "Faisalabad to Lahore", "6:00"},
    {"564", "PF294", "Flight 564", "Boeing 737", "Faisalabad to Karachi", "6:00"},
  	{"670", "PF223", "Flight 670", "Boeing 777", "Faisalabad to Multan", "7:00"},
    {"667", "PF055", "Flight 667", "Boeing 737", "Faisalabad to Peshawar", "11:00"},
    {"476", "PF077", "Flight 456", "Boeing 737", "Peshawar to Islamabad", "12:00"},
    {"564", "PF773", "Flight 564", "Boeing 777", "Peshawar to Karachi", "10:00"},
    {"321", "PF784", "Flight 321", "Boeing 787", "Peshawar to Multan", "4:00"},
    {"700", "PF284", "Flight 700", "Boeing 787", "Peshawar to Faisalabad", "7:00"},
    {"612", "PF929", "Flight 612", "Boeing 777", "Peshawar to Lahore", "3:00"},
        
};



int numFlights = 25;

void bookTicket() 
{
	
	 cout << "\n";
    Passenger passenger;
    cout << "\t\t\t\t\t\tEnter passenger name: ";
    getline(cin, passenger.name);
    
    
     cout << "\n";
    Passenger CNIC;
    cout << "\t\t\t\t\t\tEnter the CNIC of the passeneger : ";
    getline(cin, passenger.CNIC);
    
    
    
      cout << "\n";
    Passenger age;
    cout << "\t\t\t\t\t\tEnter the age of the passeneger : ";
    getline(cin, passenger.age);
    
     
     
	cout << "\n";
	Passenger passportNumber;
    cout << "\t\t\t\t\t\tPlease enter passport number: ";
    getline(cin, passenger.passportNumber);
    
    
    
    cout << "\n";
	Passenger conatactNumber;
    cout << "\t\t\t\t\t\tPlease enter your contact number with country code : ";
    getline(cin, passenger.contactNumber);
    
    
    
    cout << "\n";
	Passenger email;
    cout << "\t\t\t\t\t\tPlease enter your Email address: ";
    getline(cin, passenger.email);
    
    
    
    cout << "\n";
	Passenger cardaddress;
    cout << "\t\t\t\t\t\tPlease enter your credit card number to book your ticket: ";
    getline(cin, passenger.cardaddress);



       cout << "\n";
        cout << "\n";
         cout << "\n";
          cout << "\n";
           cout << "\n";
    cout << "\t\t\t\tAvailable Flights for the following domestic destinations\n";
     cout << "\n";
     
     
    for (int i = 0; i < numFlights; ++i) 
    {
        cout << "PNR: " << availableFlights[i].PNR << " - Flight Code: " << availableFlights[i].code
             << " - Name: " << availableFlights[i].name << " - Plane: " << availableFlights[i].plane
             << " - Route: " << availableFlights[i].route << " - Time: " << availableFlights[i].time << endl;
    }



    string selectedPNR;
    
     cout << "\n";
      cout << "\n";
       cout << "\n";
       
       
    cout << "Enter PNR of the flight you want to book: ";
    cin >> selectedPNR;


    bool found = false;
    for (int i = 0; i < numFlights; ++i)
     {
     	
     	
        if (availableFlights[i].PNR == selectedPNR)
         {
            found = true;
            ofstream bookingsFile("bookings.txt", ios::app);
            if (bookingsFile.is_open()) 
            {
                bookingsFile << selectedPNR << " " << passenger.name << " " << passenger.passportNumber << endl;
                  cout << "\n";
                    cout << "\n";
                       cout << "\n";
                       
                cout << "--------------------------------------------------------------------------------------------------------------\n";
                cout << "\n\t\t\t\t\t---Ticket booked successfully---\n" << endl;
                cout << "--------------------------------------------------------------------------------------------------------------";
                bookingsFile.close();
            }
             else
              {
                cout << "Unable to open bookings file.\n";
              }
            break;
         }
         
         
    }
    if (!found)
     {
        cout << "Flight with PNR " << selectedPNR << " not found.\n";
     }
     
     
}



void cancelTicket()
 {
    string passportOrPNR;
          cout << "\n";
            cout << "\n";
    cout << "\t\t\t\t\tPlease enter passport number or PNR to cancel the ticket: ";
    cin >> passportOrPNR;

    ifstream bookingsFile("bookings.txt");
    ofstream tempFile("temp.txt");
    string line;
    bool found = false;
    while (getline(bookingsFile, line))
	{
	 	
	 	
        istringstream iss(line);
        string PNR, name, passport;
        iss >> PNR >> name >> passport;
        
        if (passportOrPNR == PNR || passportOrPNR == passport)
		 {
		 	cout << "\n";
		 	 cout << "\n";
		      cout << "\n";
		      
		      cout << "--------------------------------------------------------------------------------------------------------------";
            cout << "\n\t\t\t\t\t---Ticket with PNR : " << PNR <<"---" << "\n\t\t\t\t\t---canceled successfull---.\n";
              cout << "--------------------------------------------------------------------------------------------------------------";
            found = true;
         } 
		 
		 
		 else 
		      {
            tempFile << line << endl;
              }
    }
    
    
    bookingsFile.close();
    tempFile.close();

    remove("bookings.txt");
    rename("temp.txt", "bookings.txt");

    if (!found)
	{
        cout << "Ticket with passport number or PNR " << passportOrPNR << " not found.\n";
    }
}

int main() 
{
    int choice;
    
    do 
	{
    	
    	cout << "\n";
          cout << "\n";
    	    cout << "\n";
        cout << "\n\t\t\tWelcome to FN domestic Flight reservation services (Air-Sial)";
        cout << "\n\t\t\t\t\tAIR-SIAL the pride of Pakistan\n";
        
        cout << "\n";
         cout << "\n";
          cout << "\n";
        cout << "------------  Please press 1 from keyboard to book a ticket :\n";
        cout << "------------  Please press 2 from keyboard cancel a ticket :\n";
        cout << "------------  Please press 3 from keyboard to exit from menu :\n";
        
                       cout << "\n";
                         cout << "\n";
        cout << "Enter the number according to given menu please : ";
        cin >> choice;
        cin.ignore();




        switch (choice) 
		{
            case 1:
                bookTicket();
                break;
                
            case 2:
                cancelTicket();
                break;
                
            case 3:
                cout << "Exiting program.\n";
                break;
                
            default:
                cout << "Invalid Input. Please try again.\n";
                
        }
    } 
    
	while (choice != 3);






return 0;

}


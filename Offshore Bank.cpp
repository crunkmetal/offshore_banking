// Demonstrating use of references

// preprocessor directives
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;

// global declarations
string criminalTarget = "Terrorist Dood";
string userIDString;
string currentUserName;
int customerID;
int userChoice = NULL;
int balanceNonTerrorist = 8816;
int balanceTerrorist = 1000;
int joesCoffeeShop = 2021;
int hackedBalance = joesCoffeeShop;
int& rbalance_terrorist = joesCoffeeShop;
int& rhacked_balance = balanceTerrorist;
int userID;
bool isTerroristTarget = false;
vector<string> userNames;

// function prototypes
void pause_1s();
void pause_2s();
void pause_3s();
void welcomeUser();
void possibleUsers();
string getUserID();
void userIDStringToInt(string);
bool userIsATerrorist(int);
int reasonForVisit();
int bankingChoice(int);

int depositFunds();
int withdrawFunds();
int checkBalance();
void playAgain();

// the one and only main function
int main()
{
    // populate vector with  possible user names
    possibleUsers();
    // random seed generator
    srand(static_cast<unsigned int>(time(0)));
    // shuffle bank patrons list
    random_shuffle(userNames.begin(), userNames.end());
    // get user ID
    getUserID();
    // convert userID string to customerID int
    userIDStringToInt(userIDString);
    // check to see if the customer is the target
    userIsATerrorist(userID);
    // display welcome and options to user
    welcomeUser();
	// invoke function giving user bank options
    reasonForVisit();
	// if user has not chosen cancel on previous loop run
    while (userChoice != 4)
    {
    	// invoke function using user's option as a parameter
        bankingChoice(userChoice);
    }
	// invoke function to play again
    playAgain();
	// main() expects an integer for a return value
    return 0;
}

// function adds user names to roster
void possibleUsers()
{
    // push_back method adds the word(s) in quotes to the 'words' vector
    userNames.push_back("Lee-Ann Niacin");
    userNames.push_back("Noah Obregon");
    userNames.push_back("Oliver Spice");
    userNames.push_back("William Tell");
    userNames.push_back("Elijah Woods");
    userNames.push_back("Jameson Hatfields III");
    userNames.push_back("Benjamin Button");
    userNames.push_back("Lucas Treetrucker");
    userNames.push_back("Mason Jarloose");
    userNames.push_back("Ethan Hawk");
    userNames.push_back("Olivia Oldton");
    userNames.push_back("Emma Sonoran");
    userNames.push_back("Ava Vavavaya");
    userNames.push_back("Sophia Laurenthal");
    userNames.push_back("Isabella Fortuna");
    userNames.push_back("Charlotte Webber");
    userNames.push_back("Amelia Spelling");
    userNames.push_back("Mia Aurora");
    userNames.push_back("Harper Colton");
    userNames.push_back("Evelyn Manson");
    userNames.push_back("Don Solo");
}
// function to get user ID
// six digit validation check
string getUserID()
{
	// clear previous transaction values
    userIDString = "";
    userChoice = -1;
    customerID = -1;

    system("CLS");
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
    cout << "\n\t\t\b\bWelcome to Offshore Bank.\n";
    cout << "\n\n\n\n";
    cout << "\t\t\bPlease enter your SDI.\n";
	cout << "\t\t\b\b[ six digit identifier ]";
    cout << "\n\n\n\n\n";
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
    cin >> userIDString;

    // verify user has input six digits
	if(userIDString.length() != 6)
	{
        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\t\b\bWelcome to Offshore Bank.\n";
        cout << "\n\n\n\n";
        cout << "\tWe are Off...\n";
		// pause a lil bit
        pause_1s();
        cout << "\tbut YOU\n";
        // pause a lil bit
        pause_1s();
		cout << "\tyou are WAAAAAAAAAy off.";
        cout << "\n\n\n\n\n";

        cout << "\t\bYou have entered an invalid customer ID.\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
		// pause for a lil bit
        pause_3s();
		// invoke id check function
        getUserID();
	}
	// user input is/are integers check
    for (int i = 0; i < userIDString.length(); i++)
    {
        if(!(isdigit(userIDString[i])))
        {
            system("CLS");
            cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
            cout << "\n\t\t\b\bWelcome to Offshore Bank.\n";
            cout << "\n\n\n\n";
            cout << "\tInteger Input Verification...\n";
            pause_1s();
            cout << "\tYou have entered an invalid customer ID.\n";
            cout << "\n\n\n\n";
            cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        	// pause for a lil bit
            pause_3s();
        	// invoke id check function
            getUserID();
        }
    }
	
    return userIDString;
}
// convert customer ID string to an integer array
void userIDStringToInt(string userIDString)
{
	// convert userInput from string to int
    customerID = stoi(userIDString);
}
// switch for terrorist status
bool userIsATerrorist(int userID)
{
    if (customerID == 100001)
    {
        isTerroristTarget = true;
        return isTerroristTarget;
    }
    else if(userID != 100001 && (userID > 000000 || userID < 1000000))
    {
        return false;
    }
}
// function to personally welcome user
void welcomeUser()
{
	if (customerID == 100001)
	{
        currentUserName = criminalTarget;
        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
        cout << "\n\n\n\n";
        cout << "\n Welcome back " << criminalTarget << "!\n";
        cout << "\n\n\n\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        pause_2s();
    }
    else
    {
        currentUserName = userNames[0];
        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
        cout << "\n\n\n\n";
    	cout << "  Welcome back " << currentUserName << "!\n";
        cout << "\n\n\n\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        pause_2s();
    }
}
// function to ask user about reason for visit
int reasonForVisit()
{
    userChoice = NULL;
    system("CLS");
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
    cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
    cout << "\n\n\n\n";
	
    cout << "1) Check Balance\n";
    cout << "2) Deposit Funds\n";
    cout << "3) Withdraw Funds\n";
    cout << "4) Cancel\n";
	
    cout << "\n\n\n\n";
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
    cin >> userChoice;

    return userChoice;
}
// function branching game loop based on user choice
int bankingChoice(int userChoice)
{
    switch (userChoice) {
    // check user balance
    case 1:

        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
        cout << "\n\n\n\n";
        cout << "Checking Balance...\n";
        cout << "\n\n\n\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        pause_1s();
        checkBalance();
        userChoice = NULL;

        return userChoice;
    case 2:
        // leave some money
        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
        cout << "\n\n\n\n";
        cout << "Deposit processing...\n";
        cout << "\n\n\n\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        pause_1s();
        depositFunds();
        userChoice = NULL;

    	return userChoice;
    case 3:
        userChoice = NULL;

       // get some money
        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
        cout << "\n\n\n\n";
    	
        cout << "Withdrawal processing...\n";

        cout << "\n\n\n\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        pause_1s();
        withdrawFunds();
        return userChoice;
    case 4:
        // exit this screen
        userChoice = NULL;

        main();
        return userChoice;

     // deal with unexpected input
    default: //Optional
        userChoice = NULL;

        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
        cout << "\n\n\n\n";
    	
        cout << "\t[err 3906] invalid choice.\n";
        cout << "\t:: Transaction Cancelled ::\n\n";
        pause_1s();
        cout << "\tPlease try again.\n";
        cout << "\n\n\n\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        pause_2s();
        reasonForVisit();
        return userChoice;

    }
}
// function to check user's bank balance
int checkBalance()
{
	// display balance for any customer who is not the terrorist
    while (customerID != 100001)
    {
        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
        cout << "\n\n\n\n";
        cout << " Your balance is: $" << balanceNonTerrorist << "\n";
        cout << "\n\n\n\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        pause_1s();
        userChoice = NULL;
        reasonForVisit();
        return userChoice;
    }
	// function branch just for the terrorist target
    system("CLS");
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
    cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
    cout << "\n\n\n\n";
    cout << " Your balance is: $" << hackedBalance << "\n";
    cout << "\n\n\n\n";
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
	
    cout << "\n\n\n Encrypted Message:\n";
    cout << " " << criminalTarget << "'s actual balance:\t$" << balanceTerrorist << "\n";
    cout << " Balance that " << criminalTarget << " sees:\t$" << hackedBalance << "\n";
    cout << " Joe's Coffee Shop balance:\t\t$" << joesCoffeeShop << "\n";
    cout << "\n\n";
    system("pause");
	
    // pause_1s();
    userChoice = NULL;
    reasonForVisit();
	
    return userChoice;
}
// function to deposit funds in user's bank account
int depositFunds()
{
    // funds transaction code for non-terrorists
    while (customerID != 100001)
    {
        int depositAmount = 0;
        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
        cout << "\n\n\n\n";

        cout << "\n How much are you depositing today?\n";
        cout << " (Integers only. No decimal points.)\n";

        cout << "\n\n\n\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cin >> depositAmount;
        balanceNonTerrorist += depositAmount;

        // information display after deposit
        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
        cout << " " << currentUserName << ":\n";
        cout << "\n\n\n\n";

        cout << "\tThank you for choosing Offshore Bank\n";
        cout << "\t\t\b\b\b\bThe amount of $" << depositAmount << " has been\n";
        cout << "\t\t\b\bdeposited in your account.\n";

        cout << "\n\n\n\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        pause_3s();
        reasonForVisit();
        return balanceNonTerrorist;
    }
	// TERRORIST CODE FOR DEPOSIT
    // function deposit branch made for the terrorist
    int depositAmount = 0;
    system("CLS");
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
    cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
    cout << "\n\n\n\n";

    cout << "\n How much are you depositing today?\n";
    cout << " (Integers only. No decimal points.)\n";

    cout << "\n\n\n\n";
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
    cin >> depositAmount;
    rbalance_terrorist += depositAmount;
    hackedBalance += depositAmount;

    // information display after deposit
    system("CLS");
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
    cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
    cout << " " << currentUserName << ":\n";
    cout << "\n\n\n\n";

    cout << "\tThank you for choosing Offshore Bank\n";
    cout << "\t\t\b\b\b\bThe amount of $" << depositAmount << " has been\n";
    cout << "\t\t\b\bdeposited in your account.\n";

    cout << "\n\n\n\n";
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";

    cout << "\n\n\n Encrypted Message:\n";
    cout << " " << criminalTarget << "'s actual balance:\t$" << balanceTerrorist << "\n";
    cout << " Balance that " << criminalTarget << " sees:\t$" << hackedBalance << "\n";
    cout << " Joe's Coffee Shop balance:\t\t$" << joesCoffeeShop << "\n";
    cout << "\n\n";
    system("pause");
	
    // pause_3s();
    reasonForVisit();

    return rbalance_terrorist, hackedBalance;
}
// function to withdraw funds from user's bank account
int withdrawFunds()
{
    // funds transaction code for non-terrorists
    while (customerID != 100001)
    {
        int withdrawalAmount = 0;
        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
        cout << "\n\n\n\n";

        cout << "\n How much are you withdrawing today?\n";
        cout << " (Integers only. No decimal points.)\n";

        cout << "\n\n\n\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cin >> withdrawalAmount;
        balanceNonTerrorist -= withdrawalAmount;

        // information display after deposit
        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
        cout << " " << currentUserName << ":\n";
        cout << "\n\n\n\n";

        cout << "\tThank you for choosing Offshore Bank\n";
        cout << "\t\t\b\b\b\bThe amount of $" << withdrawalAmount << " has been\n";
        cout << "\t\t\b\bwithdrawn from your account.\n";

        cout << "\n\n\n\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        pause_3s();
        reasonForVisit();
    	
        return balanceNonTerrorist;
    }
	// TERRORIST CODE
    // function withdrawal branch made for the terrorist
    int withdrawalAmount = 0;
    system("CLS");
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
    cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
    cout << "\n\n\n\n";

    cout << "\n How much are you withdrawing today?\n";
    cout << " (Integers only. No decimal points.)\n";

    cout << "\n\n\n\n";
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
    cin >> withdrawalAmount;

    // information display after terrorist withdrawal input
	// this will allow for unsuspecting target to withdraw small amounts, evading detection
    if (withdrawalAmount < balanceTerrorist)
    {
        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
        cout << " " << currentUserName << ":\n";
        cout << "\n\n\n\n";

        cout << "\tThank you for choosing Offshore Bank\n";
        cout << "\t\t\b\b\b\bThe amount of $" << withdrawalAmount << " has been\n";
        cout << "\t\t\b\b\bwithdrawn from your account.\n";

        cout << "\n\n\n\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        rhacked_balance -= withdrawalAmount;
    	// for deception purposes.
    	// keeps a running (balance) based on additional deposits and withdrawals
        hackedBalance -= withdrawalAmount;

        cout << "\n\n\n Encrypted Message:\n";
        cout << " " << criminalTarget << "'s actual balance:\t$" << balanceTerrorist << "\n";
        cout << " Balance that " << criminalTarget << " sees:\t$" << hackedBalance << "\n";
        cout << " Joe's Coffee Shop balance:\t\t$" << joesCoffeeShop << "\n";
        cout << "\n\n";
        system("pause");
    	
        // pause_3s();
        reasonForVisit();

        return rhacked_balance, hackedBalance;
    }
	// withdrawal function branch to handle withdrawals greater than actual amount in terrorist acct.
    system("CLS");
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
    cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
    cout << " " << currentUserName << ":\n";
    cout << "\n\n\n\n";

    cout << "\t\b There are insufficient funds\n";
    cout << "\t\b in this account.  Please see an Offshore\n";
	cout << "\t\b Bank representative to resolve this\n";
    cout << "\t\b issue.  The amount of $" << withdrawalAmount << " has\n";
    cout << "\t\b NOT been withdrawn from your account.\n";

    cout << "\n\n\n\n";
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
    // pause_3s();
    system("pause");
    reasonForVisit();

    return 0;
}
// function to pause for one second
void pause_1s()
{
    // pause for a lil bit
    chrono::seconds dura(1);
    this_thread::sleep_for(dura);
}
// function to pause for two seconds
void pause_2s()
{
    // pause for a lil bit
    chrono::seconds dura(2);
    this_thread::sleep_for(dura);
}
// function to pause for three seconds
void pause_3s()
{
    // pause for a lil bit
    chrono::seconds dura(3);
    this_thread::sleep_for(dura);
}
// function to start over
void playAgain()
{
    char playAgainResponse;
    system("CLS");
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
    cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
    cout << "\n\n\n\n";
	
    cout << "\n Make another transaction ? (Y or N)\t";

	
    cout << "\n\n\n\n\n";
    cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
    cin >> playAgainResponse;
    // if player does not wish to replay
    if (playAgainResponse == 'N' || playAgainResponse == 'n')
    {
        // exit the application entirely
        exit(0);
    }
    // if player wishes to play again
    if (playAgainResponse == 'Y' || playAgainResponse == 'y')
    {
        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
        cout << "\n\n\n\n";
    	
        cout << "System Timed Out\n";

        cout << "\n\n\n\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        pause_2s();
    	// reset value of non-terrorist balance for sake of gameplay
        balanceNonTerrorist = 8816;
        // invoke start of game loop
		main();
    }
    // handle invalid user input
    else
    {
        system("CLS");
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        cout << "\n\t\b\b\b\b************** OFFSHORE BANK **************\n";
        cout << "\n\n\n\n";
    	
        cout << "\nYou have entered an invalid response.";
        cout << "\n\n\n\n";
        cout << "\n [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] \n";
        pause_2s();
        // invoke function to play again
        playAgain();
    }
}




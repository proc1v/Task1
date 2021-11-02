#include "MenuAdmin.h"
#include "Error.h"
#include "Healpers.h"
#include<iostream>
using namespace std;

void MenuAdmin::ShowMenu()
{
	char userInput;

	do {
		showMainMenu();
		cin >> userInput;
		safeHandleMainMenuInput(userInput);

		cout << endl;
	} while (userInput != '0');
}


void MenuAdmin::showMainMenu()
{
	//clear_screen();

	cout << R"(
 __          __   _              _____       _ _                      
 \ \        / /  | |            |  __ \     | (_)                     
  \ \  /\  / /_ _| |_ ___ _ __  | |  | | ___| |___   _____ _ __ _   _ 
   \ \/  \/ / _` | __/ _ \ '__| | |  | |/ _ \ | \ \ / / _ \ '__| | | |
    \  /\  / (_| | ||  __/ |    | |__| |  __/ | |\ V /  __/ |  | |_| |
     \/  \/ \__,_|\__\___|_|    |_____/ \___|_|_| \_/ \___|_|   \__, |
                                                                 __/ |
                                                                |___/ 
)";
	cout << "\nPlease select an option:\n";
	cout << "1 - Waters list;\n";
	cout << "2 - Klients list;\n";
	cout << "3 - Orders list;\n";
	cout << "4 - Statistics;\n";
	cout << "0 - Exit.\n";
	cout << "Your choice >> ";
}
void MenuAdmin::handleMainMenuInput(char userInput) {
	switch (userInput)
	{
	case '1':
		showWaterMenu();
		break;
	case '2':
		showKlientMenu();
		break;
	case '3':
		showOrderMenu();
		break;
	case '4':
		showStatisticsMenu();
		break;
	case '0':
		break;
	default:
		cout << "Wrong command selected\n";
		break;
	}
}
void MenuAdmin::safeHandleMainMenuInput(char userInput) {
	try
	{
		handleMainMenuInput(userInput);
	}
	catch (Error& error)
	{
		/*ofstream fout("errors.txt");
		fout << error.ToString();
		fout.close();*/

		cout << "Error occurs: " << error.ToString() << endl;
	}
	catch (...)
	{
		cout << "Some error occurs" << endl;
	}
}


void MenuAdmin::showWaterMenu() {
	char userInput;

	clear_screen();

	do {
		cout << "\nWater list\n";
		cout << "\nPlease select an option:\n";
		cout << "1 - Print Water list;\n";
		cout << "2 - Add Water;\n";
		cout << "3 - Delete Water;\n";
		cout << "4 - Find Water;\n";
		cout << "0 - Return to main MenuAdmin.\n";
		cout << "Your choice >> ";

		cin >> userInput;
		safeHandleWaterMenuInput(userInput);

		cout << endl;
	} while (userInput != '0');
}
void MenuAdmin::handleWaterMenuInput(char userInput) {
	switch (userInput)
	{
	case '1':
		command.PrintWaters();
		break;
	case '2':
		command.AddWater();
		break;
	case '3':
		command.DeleteWater();
		break;
	case '4':
		command.FindWater();
	case '0':
		break;
	default:
		cout << "Wrong command selected\n";
		break;
	}
}
void MenuAdmin::safeHandleWaterMenuInput(char userInput) {
	try
	{
		handleWaterMenuInput(userInput);
	}
	catch (Error& error)
	{
		cout << "Error occurs: " << error.ToString() << endl;
	}
	catch (...) {
		cout << "Some error occurs" << endl;
	}
}


void MenuAdmin::showKlientMenu() {
	char userInput;

	clear_screen();

	do {
		cout << "\nKlients list\n";
		cout << "\nPlease select an option:\n";
		cout << "1 - Print Klients list;\n";
		cout << "2 - Add Klient;\n";
		cout << "3 - Delete Klient;\n";
		cout << "4 - Find Klient;\n";
		cout << "0 - Return to main MenuAdmin.\n";
		cout << "Your choice >> ";

		cin >> userInput;
		safeHandleKlientMenuInput(userInput);

		cout << endl;
	} while (userInput != '0');
}
void MenuAdmin::handleKlientMenuInput(char UserInput) {
	switch (UserInput)
	{
	case '1':
		command.PrintKlients();
		break;
	case '2':
		command.AddKlient();
		break;
	case '3':
		command.DeleteKlient();
		break;
	case '4':
		command.FindKlient();
	case '0':
		break;
	default:
		cout << "Wrong command selected\n";
		break;
	}
}
void MenuAdmin::safeHandleKlientMenuInput(char UserInput) {
	try
	{
		handleKlientMenuInput(UserInput);
	}
	catch (Error& error)
	{
		cout << "Error occurs: " << error.ToString() << endl;
	}
	catch (...) {
		cout << "Some error occurs" << endl;
	}
}


void MenuAdmin::showOrderMenu() {
	char userInput;

	clear_screen();

	do {
		cout << "\nOrders list\n";
		cout << "\nPlease select an option:\n";
		cout << "1 - Print Orders list;\n";
		cout << "2 - Add Order;\n";
		cout << "3 - Delete Order;\n";
		cout << "4 - Find Order;\n";
		cout << "0 - Return to main MenuAdmin.\n";
		cout << "Your choice >> ";

		cin >> userInput;
		safeHandleOrderMenuInput(userInput);

		cout << endl;
	} while (userInput != '0');
}
void MenuAdmin::handleOrderMenuInput(char UserInput) {
	switch (UserInput)
	{
	case '1':
		command.PrintOrders();
		break;
	case '2':
		command.AddOrder();
		break;
	case '3':
		command.DeleteOrder();
		break;
	case '4':
		command.FindOrder();
	case '0':
		break;
	default:
		cout << "Wrong command selected\n";
		break;
	}
}
void MenuAdmin::safeHandleOrderMenuInput(char UserInput) {
	try
	{
		handleOrderMenuInput(UserInput);
	}
	catch (Error& error)
	{
		cout << "Error occurs: " << error.ToString() << endl;
	}
	catch (...) {
		cout << "Some error occurs" << endl;
	}
}


void MenuAdmin::showStatisticsMenu() {
	char userInput;

	clear_screen();

	do {
		cout << "\nOrders list\n";
		cout << "\nPlease select an option:\n";
		cout << "1 - Print income;\n";
		cout << "2 - Water statistics;\n";
		cout << "3 - Klient statistics;\n";
		cout << "0 - Return to main MenuAdmin.\n";
		cout << "Your choice >> ";

		cin >> userInput;
		safeHandleStatisticsMenuInput(userInput);

		cout << endl;
	} while (userInput != '0');
}
void MenuAdmin::handleStatisticsMenuInput(char userInput) {
	switch (userInput)
	{
	case '1':
		command.PrintIncome();
		break;
	case '2':
		command.PrintWaterStats();
		break;
	case '3':
		command.PrintKlientStats();
		break;
	case '0':
		break;
	default:
		cout << "Wrong command selected\n";
		break;
	}
}
void MenuAdmin::safeHandleStatisticsMenuInput(char userInput) {
	try
	{
		handleStatisticsMenuInput(userInput);
	}
	catch (Error& error)
	{
		cout << "Error occurs: " << error.ToString() << endl;
	}
	catch (...) {
		cout << "Some error occurs" << endl;
	}
}
#include "MenuUser.h"
#include "Error.h"
#include "Healpers.h"
#include<iostream>
using namespace std;

void MenuUser::ShowMenu() {
	
	char userInput;

	do {
		showMainMenu();
		cin >> userInput;
		safeHandleMainMenuInput(userInput);

		cout << endl;
	} while (userInput != '0');
}

void MenuUser::showMainMenu() {

	clear_screen();

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

	cout << R"(
  _    _                 _____                 _ 
 | |  | |               |  __ \               | |
 | |  | |___  ___ _ __  | |__) |_ _ _ __   ___| |
 | |  | / __|/ _ \ '__| |  ___/ _` | '_ \ / _ \ |
 | |__| \__ \  __/ |    | |  | (_| | | | |  __/ |
  \____/|___/\___|_|    |_|   \__,_|_| |_|\___|_|
)";

	cout << "\nPlease select an option:\n";
	cout << "1 - Waters list;\n";
	cout << "2 - Orders list;\n";
	cout << "0 - Exit.\n";
	cout << "Your choice >> ";
}

void MenuUser::handleMainMenuInput(char userInput) {
	switch (userInput)
	{
	case '1':
		showWaterMenu();
		break;
	case '2':
		showOrderMenu();
		break;
	case '0':
		break;
	default:
		cout << "Wrong command selected\n";
		break;
	}
}

void MenuUser::safeHandleMainMenuInput(char userInput) {
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

void MenuUser::showWaterMenu() {
	char userInput;

	clear_screen();

	do {
		cout << "\nWater list\n";
		cout << "\nPlease select an option:\n";
		cout << "1 - Print Water list;\n";
		cout << "2 - Find Water;\n";
		cout << "0 - Return to main Menu.\n";
		cout << "Your choice >> ";

		cin >> userInput;
		safeHandleWaterMenuInput(userInput);

		cout << endl;
	} while (userInput != '0');
}

void MenuUser::handleWaterMenuInput(char userInput) {
	switch (userInput)
	{
	case '1':
		command.PrintWaters();
		break;
	case '2':
		command.FindWater();
	case '0':
		break;
	default:
		cout << "Wrong command selected\n";
		break;
	}
}

void MenuUser::safeHandleWaterMenuInput(char userInput) {
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

void MenuUser::showOrderMenu() {
	char userInput;

	clear_screen();

	do {
		cout << "\nOrders list\n";
		cout << "\nPlease select an option:\n";
		cout << "1 - Add Order;\n";
		cout << "2 - Find Order;\n";
		cout << "0 - Return to main MenuAdmin.\n";
		cout << "Your choice >> ";

		cin >> userInput;
		safeHandleOrderMenuInput(userInput);

		cout << endl;
	} while (userInput != '0');
}

void MenuUser::handleOrderMenuInput(char userInput) {
	switch (userInput)
	{
	case '1':
		command.AddOrder();
		break;
	case '2':
		command.FindOrder();
	case '0':
		break;
	default:
		cout << "Wrong command selected\n";
		break;
	}
}

void MenuUser::safeHandleOrderMenuInput(char userInput) {
	try
	{
		handleOrderMenuInput(userInput);
	}
	catch (Error& error)
	{
		cout << "Error occurs: " << error.ToString() << endl;
	}
	catch (...) {
		cout << "Some error occurs" << endl;
	}
}
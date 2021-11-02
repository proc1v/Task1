#ifndef MENU_USER_H
#define MENU_USER_H
#include "Command.h"
//#include "Healpers.h"


class MenuUser {
public:
	void ShowMenu();
private:
	Command command;

	//Main menu
	void showMainMenu();
	void handleMainMenuInput(char userInput);
	void safeHandleMainMenuInput(char userInput);

	//Water
	void showWaterMenu();
	void handleWaterMenuInput(char userInput);
	void safeHandleWaterMenuInput(char userInput);

	// Access to klients is denied

	//Order
	void showOrderMenu();
	void handleOrderMenuInput(char userInput);
	void safeHandleOrderMenuInput(char userInput);

	//access to Statistics is denied
};


#endif // !MENU_USER_H

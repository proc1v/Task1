#ifndef MENU_ADMIN_H
#define MENU_ADMIN_H
#include "Command.h"

class MenuAdmin {
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

	//Klient
	void showKlientMenu();
	void handleKlientMenuInput(char userInput);
	void safeHandleKlientMenuInput(char userInput);

	//Order
	void showOrderMenu();
	void handleOrderMenuInput(char userInput);
	void safeHandleOrderMenuInput(char userInput);

	//Statistics
	void showStatisticsMenu();
	void handleStatisticsMenuInput(char userInput);
	void safeHandleStatisticsMenuInput(char userInput);
};

#endif // !MENU_H

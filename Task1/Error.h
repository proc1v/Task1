#ifndef ERROR_H
#define ERROR_H

#include<string>
using namespace std;

enum ErrorCode
{
	WrongId,
	WrongName,
	NegativeValue,
	WrongCommand,
	LatestMemento
};

class Error
{
private:
	ErrorCode code;
public:
	Error(ErrorCode code);
	string ToString();
};

#endif // !ERROR_H


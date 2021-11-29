#include "Error.h"

Error::Error(ErrorCode code)
{
	this->code = code;
}

string Error::ToString()
{
	switch (code)
	{
	case WrongId:
		return "Wrong id";
	case WrongName:
		return "Wrong name";
	case NegativeValue:
		return "Negative value";
	case WrongCommand:
		return "Wrong command";
	case LatestMemento:
		return "No actions left to undo";
	default:
		return "Undefined error";
	}
}
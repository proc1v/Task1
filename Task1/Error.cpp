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
	default:
		return "Undefined error";
	}
}
#include "MissingDetailsException.h"
using namespace System;
String^ MissingDetailsException::Get_message()
{
	String^ err = "Please enter all details";
	return err;
}

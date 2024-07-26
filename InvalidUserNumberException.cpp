#include "InvalidUserNumberException.h"
using namespace System;
String^ InvalidUserNumberException::Get_message() 
{
	String^ err = "Enter valid number of users (MIN : 3) (MAX : 6)";
	return err;
}

#include "InvalidBluffException.h"
using namespace System;
String^ InvalidBluffException::Get_message()
{
	String^ err = "You cannot check your own cards";
	return err;
}

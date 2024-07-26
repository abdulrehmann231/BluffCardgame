#include "InvalidPlay.h"
using namespace System;
String^ InvalidPlay::Get_message()
{
	String^ err = "You must play more than one card at the start of round or you may skip!!";
	return err;
}


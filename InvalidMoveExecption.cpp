#include "InvalidMoveExecption.h"
using namespace System;
String^ InvalidMoveExecption::Get_message()
{
	String^ err = "You must play one card or you may pass";
	return err;
}

#include "MyException.h"
using namespace System;

MyException::MyException()
{
}
void MyException::Set_message(String^ m) {
	message = m;
}
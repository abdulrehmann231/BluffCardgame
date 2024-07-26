#pragma once
#include "MyException.h"
using namespace System;
ref class InvalidUserNumberException : public MyException
{
public:
	String^ Get_message() override;
};


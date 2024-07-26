#pragma once
#include "MyException.h"
ref class InvalidBluffException : MyException
{
public:
	String^ Get_message() override;
};


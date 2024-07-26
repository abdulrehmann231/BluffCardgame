#pragma once
#include "MyException.h"
ref class InvalidPlay : public MyException
{
public:
	String^ Get_message() override;
};


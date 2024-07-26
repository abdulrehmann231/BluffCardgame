#pragma once
#include "MyException.h"
ref class InvalidMoveExecption : public MyException
{
public:
	String^ Get_message() override;
};


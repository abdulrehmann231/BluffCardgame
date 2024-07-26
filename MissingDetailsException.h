#pragma once
#include "MyException.h"
using namespace System;
ref class MissingDetailsException : public MyException
{
public:
	String^ Get_message() override;
};


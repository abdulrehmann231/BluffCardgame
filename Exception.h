#pragma once
using namespace System;
ref class Exception
{
protected:
	String^ message;
public:
	Exception();
	void Set_message(String^ m);
	virtual String^ Get_message() = 0;
};


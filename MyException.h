#pragma once
using namespace System;
ref class MyException
{
protected:
	String^ message;
public:
	MyException();
	void Set_message(String^ m);
	virtual String^ Get_message() = 0;
};


#pragma once
#include<string>
#include<iostream>

class CText
{
	std::string s;
public:
	CText() = default; // default constructor
	CText(const std::string& ss); // constructor
	~CText() = default; // default destructor
	std::string getText() const; // return string
};
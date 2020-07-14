#include "ctext.h"

CText::CText(const std::string& ss)
{// constructor
	s = ss;
}

std::string CText::getText() const
{ // return string
	return s;
}
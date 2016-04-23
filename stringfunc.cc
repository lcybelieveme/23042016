///
///@date   2016-04-23 20:41:46
///
 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.hh"


String::String()
{
	_pstr=new char[1];
}

String::String(const char*s)
{
	_pstr=new char[strlen(s)+1];
	strcpy(_pstr,s);
}

String::String(const String& s)
{
	_pstr=new char[strlen(s._pstr)+1];
	strcpy(_pstr,s._pstr);
}

String::~String()
{
	delete []_pstr;
}

String& String::operator=(const char*s)
{
	delete []_pstr;
	_pstr=new char[strlen(s)+1];
	strcpy(_pstr,s);
	return (*this);
}

String& String::operator=(const String &s)
{
	delete []_pstr;
	_pstr=new char[strlen(s._pstr)+1];
	strcpy(_pstr,s._pstr);
	return *this;
}

String& String::operator+=(const String&s)
{
	strcat(this->_pstr,s._pstr);
	return *this;
}

String& String::operator+=(const char *s)
{
	strcat(this->_pstr,s);
	return *this;
}

char&String::operator[](std::size_t idx)
{
	return _pstr[idx];
}
const char& String::operator[](std::size_t idx)const
{
	return _pstr[idx];
}

std::size_t String::size()const
{
	return strlen(_pstr);
}

const char* String::c_str() const
{
	char *temp;
	temp=new char[strlen(_pstr)+1];
	strcpy(temp,_pstr);
	return temp;
}

bool operator==(const String& s1,const String&s2)
{
	if(strcmp(s1._pstr,s2._pstr)==0) return true;
	else
		return false;
}
bool operator!=(const String& s1,const String&s2)
{
	if(strcmp(s1._pstr,s2._pstr)!=0) return true;
	else
		return false;
}
bool operator<(const String& s1,const String&s2)
{
	if(strcmp(s1._pstr,s2._pstr)<0) return true;
	else
		return false;
}
bool operator>(const String& s1,const String&s2)
{
	if(strcmp(s1._pstr,s2._pstr)>0) return true;
	else
		return false;
}
bool operator<=(const String& s1,const String&s2)
{
	if(strcmp(s1._pstr,s2._pstr)>0) return false;
	else
		return true;
}
bool operator>=(const String& s1,const String&s2)
{
	if(strcmp(s1._pstr,s2._pstr)<0) return false;
	else
		return true;
}

std::ostream& operator<<(std::ostream& os,const String& s1)
{
	os<< s1._pstr;
	return os;
}

std::istream& operator>>(std::istream& is,String& s)
{
	char buf[1024]={0};
	is.get(buf,1023);
	delete []s._pstr;
	s._pstr=new char[strlen(buf)+1];
	strcpy(s._pstr,buf);
	return is;
}

String operator+(const String&s1,const String&s2)
{
	String temp(s1);
	temp+=s2;
	return temp;
}

String operator+(const String&s1,const char*s2)
{
	String temp(s2);
	temp+=s1;
	return temp;
}

String operator+(const char*s1,const String&s2)
{
	String temp(s1);
	temp+=s2;
	return temp;
}

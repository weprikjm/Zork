#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <iostream>
#define MEMORY_CHUNK 32
typedef unsigned int uint;

class MyString
{


public:
//Constructors
	MyString();
	MyString(uint capacity);
	MyString(const char* str);
	MyString(const MyString& mStr);
	~MyString();
//Operators
	bool operator==(const MyString& mStr)const;
	bool operator==(const char* str)const;
	bool operator!=(const MyString& mStr)const;
	bool operator!=(const char* str)const;
	const MyString& operator+=(const MyString& mStr);
	const MyString& operator+=(const char* mStr);
	const MyString& operator=(const MyString& mStr);
	const MyString& operator=(const char* mStr);
//Getters
	const char* c_str()const;
	const uint GetCapacity()const;
//Destruction
	void Clear();

	
private:
	int CalculateSize(const char*)const;
	int GetChunkSizeNeeded(int size)const;
private:
	uint capacity = 0;
	char* str = NULL;

};
#endif
#include "MyString.h"
#include <iostream>
#include <cstring>

void MyString::resize(size_t newCapacity)
{
	capacity_ = newCapacity;
	char* newData = new char[newCapacity];
	strcpy(newData, data_);
	delete[] data_;
	data_ = newData;
}

void MyString::free()
{
	delete[] data_;
	data_ = nullptr;
	len_ = capacity_ = 0;
}

void MyString::copyFrom(const MyString& other)
{
	len_ = other.len_;
	capacity_ = other.capacity_;
	data_ = new char[capacity_];
	strcpy(data_, other.data_);
}

void MyString::moveFrom(MyString&& other) noexcept
{
	len_ = other.len_;
	capacity_ = other.capacity_;
	data_ = other.data_;

	other.capacity_ = other.len_ = 0;
	other.data_ = nullptr;
}

MyString::MyString(const char* str)
{
	if (!str)
	{
		len_ = 0;
		capacity_ = 1;
		data_ = new char[capacity_];
		data_[0] = '\0';
		return;
	}

	len_ = strlen(str);
	capacity_ = len_ * 2;
	data_ = new char[capacity_];
	strcpy(data_, str);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

MyString::~MyString()
{
	free();
}

size_t MyString::getLen() const
{
	return len_;
}

size_t MyString::getCapacity() const
{
	return capacity_;
}

MyString& MyString::append(const MyString& other)
{
	size_t newLen = len_ + other.len_;

	if (newLen >= capacity_)
	{
		resize(newLen * 2);
	}

	strcat(data_, other.data_);
	len_ = newLen;

	return *this;
}

const char* MyString::c_str() const {
	return data_;
}

char& MyString::operator[](size_t idx) {
	return data_[idx];
}

const char& MyString::operator[](size_t idx) const {
	return data_[idx];
}

MyString MyString::reversed() const
{
	MyString res(*this);

	for (size_t i = 0; i < res.len_ / 2; i++)
	{
		std::swap(res[i], res[res.len_ - i - 1]);
	}

	return res;
}

#pragma once
#pragma warning (disable: 4996)

class MyString {
private:
	char* data_;
	size_t len_;
	size_t capacity_;

	void resize(size_t newCapacity);
	void free();
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other) noexcept;

public:
	MyString() = default;
	MyString(const char* str);
	MyString(const MyString& other);
	MyString(MyString&& other) noexcept;

	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other) noexcept;

	~MyString();

	const char* c_str() const;
	size_t getLen() const;
	size_t getCapacity() const;

	MyString& append(const MyString& other);
	char& operator[](size_t idx);
	const char& operator[](size_t idx) const;
	MyString reversed() const;
};

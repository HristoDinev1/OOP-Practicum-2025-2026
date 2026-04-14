#include <iostream>

template<typename T>
class Vector {
private:
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copyFrom(const Vector<T>& other);
	void moveFrom(Vector<T>&& other) noexcept;
	void free();

	void resize(size_t newCapacity);

public:
	Vector();
	Vector(size_t initialCapacity);
	Vector(const Vector<T>& other);
	Vector(Vector<T>&& other) noexcept;
	~Vector();

	Vector<T>& operator=(const Vector<T>& other);
	Vector<T>& operator=(Vector<T>&& other) noexcept;

	size_t getSize() const;
	size_t getCapacity() const;
	bool isEmpty() const;

	void push_back(const T& value);
	void push_back(T&& value);
	void pop_back();
	void clear();

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	T* begin();
	const T* begin() const;
	T* end();
	const T* end() const;
};

template<typename T>
void Vector<T>::copyFrom(const Vector<T>& other) {
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
void Vector<T>::moveFrom(Vector<T>&& other) noexcept {
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template<typename T>
void Vector<T>::free() {
	delete[] data;
	data = nullptr;
	size = capacity = 0;
}

template<typename T>
void Vector<T>::resize(size_t newCapacity) {
	capacity = newCapacity;
	T* newData = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		newData[i] = std::move(data[i]);
	}

	delete[] data;
	data = newData;
}

template<typename T>
Vector<T>::Vector() : data(nullptr), size(0), capacity(0) {}

template<typename T>
Vector<T>::Vector(size_t initialCapacity)
	: size(0), capacity(initialCapacity) {
	data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) {
	copyFrom(other);
}

template<typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept {
	moveFrom(std::move(other));
}

template<typename T>
Vector<T>::~Vector() {
	free();
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
size_t Vector<T>::getSize() const {
	return size;
}

template<typename T>
size_t Vector<T>::getCapacity() const {
	return capacity;
}

template<typename T>
bool Vector<T>::isEmpty() const {
	return size == 0;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
	if (size >= capacity) {
		resize(capacity == 0 ? 2 : capacity * 2);
	}

	data[size++] = value;
}

template<typename T>
void Vector<T>::push_back(T&& value) {
	if (size >= capacity) {
		resize(capacity == 0 ? 2 : capacity * 2);
	}

	data[size++] = std::move(value);
}

template<typename T>
void Vector<T>::pop_back() {
	if (size > 0) {
		size--;
	}
}

template<typename T>
void Vector<T>::clear() {
	size = 0;
}

template<typename T>
T& Vector<T>::operator[](size_t index) {
	return data[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const {
	return data[index];
}

template<typename T>
T* Vector<T>::begin() {
	return data;
}

template<typename T>
const T* Vector<T>::begin() const {
	return data;
}

template<typename T>
T* Vector<T>::end() {
	return data + size;
}

template<typename T>
const T* Vector<T>::end() const {
	return data + size;
}

#pragma once

#include <stdexcept>
#include <iostream>

#define DEFAULT_SIZE 32

class Array {
	private:
		int m_size;
		int *m_data;
	public:
		Array();
		Array(int asize);
		~Array();

		int get(int index);
		void set(int index, int value);
		void resize(int asize);
		int getSize();

		Array(const Array& other);
		void operator++(int);
		void operator--(int);
		void operator+=(const Array& other);
		void operator-=(const Array& other);
		Array operator+(const Array& other);
		Array operator-(const Array& other);
		void operator=(const Array& other) = delete;
		friend std::ostream& operator<<(std::ostream& os, const Array& arr);
};

Array::Array(int asize) {
	if(asize > 0) {
		m_size = asize;
		m_data = new int[m_size];
	}
	else {
		throw std::invalid_argument("Array size cannot be less than one!");
	}
}

Array::Array() {
	Array(DEFAULT_SIZE);
}

Array::~Array() {
	delete[] m_data;
}

int Array::get(int index) {
	if(index >= 0 && index < m_size)
		return m_data[index];
	throw std::invalid_argument("Index out of bounds!");
}

void Array::set(int index, int value) {
	if(index >= 0 && index < m_size)
		m_data[index] = value;
	else
		throw std::invalid_argument("Index out of bounds!");
}

void Array::resize(int asize) {
	if(asize > 0) {
		// Store backup of pointer
		int *old = m_data;
		m_data = new int[asize];

		// Copy over data
		for(int i = 0; i < m_size; i++) {
			m_data[i] = old[i];
		}
		
		// Delete old allocation
		delete[] old;
		
		m_size = asize;
	}
	else {
		throw std::invalid_argument("Array size cannot be less than one!");
	}
}

int Array::getSize() {
	return m_size;
}

// Copy-Konstruktor
Array::Array(const Array& other) {
	m_size = other.m_size;
    m_data = new int[other.m_size];
    for(int i = 0; i < other.m_size - 1; i++)
        m_data[i] = other.m_data[i];
}

void Array::operator++(int) {
	for(int i = 0; i < m_size; i++)
		m_data[i]++;
}

void Array::operator--(int) {
	for(int i = 0; i < m_size; i++)
		m_data[i]++;
}

void Array::operator+=(const Array& other) {
	int minsize = other.m_size < m_size ? other.m_size : m_size;
	for(int i = 0; i < minsize; i++) {
		m_data[i] += other.m_data[i];
	}
}

void Array::operator-=(const Array& other) {
	int minsize = other.m_size < m_size ? other.m_size : m_size;
	for(int i = 0; i < minsize; i++) {
		m_data[i] -= other.m_data[i];
	}
}

Array Array::operator+(const Array& other) {
	Array t(*this);
    int minsize = other.m_size < m_size ? other.m_size : m_size;
    for(int i = 0; i < minsize; i++) {
        t.set(i, t.get(i) + other.m_data[i]);
    }
    return t;
}

Array Array::operator-(const Array& other) {
	Array t(*this);
    int minsize = other.m_size < m_size ? other.m_size : m_size;
    for(int i = 0; i < minsize; i++) {
        t.set(i, t.get(i) - other.m_data[i]);
    }
    return t;
}

std::ostream& operator<<(std::ostream& os, const Array& arr) {
	os << "{";
	for(int i = 0; i < arr.m_size - 1; i++) {
		os << arr.m_data[i] << ", ";
	}
	os << arr.m_data[arr.m_size - 1] << "}";
	return os;
}

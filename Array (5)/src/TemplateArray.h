#pragma once

#include <stdexcept>

#define DEFAULT_SIZE 32

template<class T>
class TemplateArray {
	private:
		int m_size;
		T *m_data;
	public:
		TemplateArray();
		TemplateArray(int asize);
		~TemplateArray();

		T get(int index);
		void set(int index, T value);

		void resize(int asize);
		int getSize();
};

template<class T>
TemplateArray<T>::TemplateArray(int asize) {
	if(asize > 0) {
		m_size = asize;
		m_data = new T[m_size];
	}
	else {
		throw std::invalid_argument("Array size cannot be less than one!");
	}
}

template<class T>
TemplateArray<T>::TemplateArray() {
	TemplateArray(DEFAULT_SIZE);
}

template<class T>
TemplateArray<T>::~TemplateArray() {
	delete[] m_data;
}

template<class T>
T TemplateArray<T>::get(int index) {
	if(index >= 0 && index < m_size)
		return m_data[index];
	throw std::invalid_argument("Index out of bounds!");
}

template<class T>
void TemplateArray<T>::set(int index, T value) {
	if(index >= 0 && index < m_size)
		m_data[index] = value;
	else
		throw std::invalid_argument("Index out of bounds!");
}

template<class T>
void TemplateArray<T>::resize(int asize) {
	if(asize > 0) {
		// Store backup of pointer
		T *old = m_data;
		m_data = new T[asize];

		int s = m_size < asize ? m_size : asize;
		// Copy over data
		for(int i = 0; i < s; i++) {
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

template<class T>
int TemplateArray<T>::getSize() {
	return m_size;
}

#define DEFAULT_SIZE 32

#include <cstdlib>
#include <stdexcept>

class IntArray {
	private:
		int m_size;
		int *m_data;
	public:
		IntArray();
		IntArray(int asize);
		~IntArray();

		int get(int index);
		void set(int index, int value);
		void resize(int asize);
		int getSize();
		//...
};

IntArray::IntArray(int asize) {
	if(asize > 0) {
		m_size = asize;
		m_data = (int *) calloc(m_size, sizeof(int));
		if(m_data == nullptr) {
			throw std::bad_alloc();
		}
	}
	else {
		throw std::invalid_argument("Array size cannot be less than one!");
	}
}

IntArray::IntArray() {
	IntArray(DEFAULT_SIZE);
}

IntArray::~IntArray() {
	free(m_data);
}

int IntArray::get(int index) {
	if(index >= 0 && index < m_size)
		return m_data[index];
	throw std::invalid_argument("Index out of bounds!");
}

void IntArray::set(int index, int value) {
	if(index >= 0 && index < m_size)
		m_data[index] = value;
	else
		throw std::invalid_argument("Index out of bounds!");
}

void IntArray::resize(int asize) {
	if(asize > 0) {
		m_data = (int *) realloc(m_data, asize);
		if(m_data == nullptr) {
			throw std::bad_alloc();
		}
		m_size = asize;
	}
	else {
		throw std::invalid_argument("Array size cannot be less than one!");
	}
}

int IntArray::getSize() {
	return m_size;
}
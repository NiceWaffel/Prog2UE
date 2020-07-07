#pragma once

#include <iostream>
#include <memory>

template <class T>
class Element {
	public:
		Element(T data) {
			m_data = data;
			m_next = nullptr;
		}

		T m_data;
		std::shared_ptr<Element<T>> m_next;
};

template <class T>
class LinkedList {
	public:
		void append(T e);
		void insert(int index, T e);
		void print();
	private:
		std::shared_ptr<Element<T>> m_root;
};

template <class T>
void LinkedList<T>::append(T e) {
	if (!m_root) {
		m_root = std::make_shared<Element<T>>(e);
	}
	else {
		std::shared_ptr<Element<T>> last = m_root;
		while(last->m_next != nullptr) {
			last = last->m_next;
		}
		last->m_next = std::make_shared<Element<T>>(e);
	}
}

template <class T>
void LinkedList<T>::insert(int index, T e) {
	if (!m_root) {
		m_root = std::make_shared<Element<T>>(e);
	}
	else {
		std::shared_ptr<Element<T>> prev = m_root;
		int i = 0;
		while(prev->m_next != nullptr && i < index) {
			prev = prev->m_next;
			i++;
		}
		prev->m_next = std::make_shared<Element<T>>(e);
	}
}

template <class T>
void LinkedList<T>::print() {
	if (m_root) {
		std::shared_ptr<Element<T>> head = m_root;
		std::cout << "{";
		while(head->m_next != nullptr) {
			std::cout << head->m_data << ", ";
			head = head->m_next;
		}
		std::cout << head->m_data << "}" << std::endl;
	
	}
}

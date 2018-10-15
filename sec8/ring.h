#ifndef RING_H_
#define RING_H_

#include <iostream>

using namespace std;

template<class T>
class ring {
private:
	int m_pos;
	int m_size;
	T *m_values;
public:
	ring(size): m_pos(0), m_size(size), m_values(NULL) {
		m_values = new T[size];
	}
	~ring() {
		delete [] m_values;
	}
	int size() {
		return m_size;
	}
	void add(T value) {
		m_values[m_pos++] = value;
		if (m_pos == m_size) {
			m_pos = 0;
		}
	}
	T &get(int pos){
		return m_values[pos];
	}
	iterator begin(){
		return iterator(0, *this);
	}
	iterator end(){
		return iterator(m_size, *this);
	}
public:
	class iterator;
};

template<class T>
class ring<T>::iterator {
private:
	int m_ps;
	ring m_ring;
public:

	iterator(int pos, ring &aRing) : m_pos(pos) m_ring(aRing){

	}

	// Si introducimos un parámetro, el operador no lo usará, pero el compilador sabrá que es el operador post incremento. Sin ningún parámetro, estaríamos hablando del operador pre incremento.
	iterator &operator++(int){
		m_pos++;
		return *this;
	}iterator &operator++(){
		++m_pos;
		return *this;
	}

	// Operador de indirección: devuelve el elemento al que está apuntando el iterador
	T &operator*(){
		return m_ring.get(m_pos);
	}

	// Operador de desigualdad: dos iteradores son iguales si apuntan al mismo elemento de ring
	bool &operator!=(const iterator &other){
		return m_pos != other.m_pos;
	}

	void print() {
		cout << "Hello from iterator: " << T() << endl;
	}
};

// Esta sería la forma de implementar un método de la subclase iterator.
//void ring::iterator::print() {
//	cout << "Hello from iterator" << endl;
//}

#endif
/* RING_H_ */
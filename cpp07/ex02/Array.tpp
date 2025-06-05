/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:40:11 by oprosvir          #+#    #+#             */
/*   Updated: 2025/06/05 21:21:59 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

// Default constructor: empty array
template<typename T>
Array<T>::Array() : _data(NULL), _size(0) {
	std::cout << "default constructor\n";
}

// Constructor with size
template<typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n) {
	std::cout << "size constructor with n = " << n << "\n";
}

// Copy
template<typename T>
Array<T>::Array(const Array& other) {
	std::cout << "copy constructor\n";
	_size = other._size;
	_data = new T[_size];
	for (unsigned int i = 0; i < _size; ++i)
		_data[i] = other._data[i];
}

// Assignment
template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	std::cout << "copy assignment operator\n";
	if (this != &other) {
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
	return *this;
}

// Destructor
template<typename T>
Array<T>::~Array() {
	delete[] _data;
}

template<typename T>
unsigned int Array<T>::size() const {
	return _size;
}

// mutable
template<typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

// const version
template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const Array<T>& arr) {
	for (unsigned int i = 0; i < arr.size(); ++i)
		o << "[" << i << "] = " << arr[i] << std::endl;
	return o;
}

#endif
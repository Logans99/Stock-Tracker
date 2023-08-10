//
// Created by Logan Santos on 3/30/22.
//

#include <iostream>
#include<iomanip>
#include "Pair.hpp"

Pair::Pair(std::string attributeName, std::string attributeValue) {
	_attributeName = attributeName;
	_attributeStringValue = attributeValue;
	_attributeNumberValue = - 1;
	_isNumber = false;
}

Pair::Pair(std::string attributeName, double pairNumber) {
	_attributeName = attributeName;
	_attributeStringValue = "";
	_attributeNumberValue = pairNumber;
	_isNumber = true;
}

bool Pair::isDouble() {
	return _isNumber;
}

double Pair::numberValue() {
	return _attributeNumberValue;
}

std::string Pair::stringValue() {
	return _attributeStringValue;
}

std::string Pair::attributeName() {
	return _attributeName;
}

void Pair::printInJSON(int numberSpace) {
	for (int i = 0; i < numberSpace; i++) {
		std::cout << "\t"; //changed from " "
	}
	std::cout << "\"" << _attributeName << "\"";
	std::cout << ": ";

	if (_isNumber) {

		std::cout <<  std::setprecision(4) << _attributeNumberValue;	///////////////
	}
	else {
		std::cout << "\"" << _attributeStringValue << "\"" ;
	}

	std::cout << ",\n"; // added comma
}
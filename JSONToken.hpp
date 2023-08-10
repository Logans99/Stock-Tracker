//
// Created by Logan Santos on 3/12/22.
//
#include <string>

#ifndef PROJECT3_JSONTOKEN_HPP
#define PROJECT3_JSONTOKEN_HPP


class JSONToken {
public:
	JSONToken(): name{""},
			openBracket{false}, closeBracket{false},
			openBrace{false}, closeBrace{false},
			colon{false}, comma{false}, eof{false}, isNumber{false} {};

	double getValue() {return value ;}
	void setValue(double number) {
		isNumber = true;							// Edited later with Kooshesh
		value = number;
	}

	std::string getName() {return name;}
	void setName(std::string words) {name = words;}

	// Each line is their own getter/setter
	bool &isOpenBracket() {return openBracket; }
	bool &isCloseBracket() {return closeBracket; }

	bool &isOpenBrace() {return openBrace; }
	bool &isCloseBrace() {return closeBrace; }

	bool &isColon() {return colon; }
	bool &isComma() {return comma; }

	bool &isEOF() {return eof; }

	void print();

private:
	double value;
	std::string name;
	bool openBracket, closeBracket, openBrace, closeBrace, colon, comma, eof;

	bool isNumber;
};

#endif //PROJECT3_JSONTOKEN_HPP

//
// Created by Logan Santos on 3/14/22.
//

#include "JSONToken.hpp"
#include <iostream>
#include <iomanip>

void JSONToken::print() {
	if (value != - 1) {
		std::cout << std::fixed << std::setprecision(4) << getValue() << std::endl;
	}
	else if (name != "") {
		std::cout << getName() << std::endl;
	}
	else if (openBracket) {
		std::cout << "[" << std::endl;
	}
	else if (closeBracket) {
		std::cout << "]" << std::endl;
	}
	else if (openBrace) {
		std::cout << "{" << std::endl;
	}
	else if (closeBrace) {
		std::cout << "}" << std::endl;
	}
	else if (colon) {
		std::cout << ":" << std::endl;
	}
	else if (comma) {
		std::cout << "," << std::endl;
	}
	else if (eof) {
		std::cout << "EOF" << std::endl;
	}
	else {
		std::cout << "Unknown token." << std::endl;
	}
}

//
// Created by Logan Santos on 3/12/22.
//
#include "JSONTokenizer.hpp"
#include <iostream>

JSONTokenizer::JSONTokenizer(const std::string &inputFile): inputFileName{inputFile} {
	inputStream.open(inputFile, std::ios::in);
}

JSONToken JSONTokenizer::getToken() {
	if (!inputStream.is_open()) {
		std::cout << "Input stream in JSONTokenizer::getToken is not open. Terminating...\n";
		exit(4);
	}

	char c;
	inputStream >> c;
	if( inputStream.eof() ) {
		JSONToken token;
		token.isEOF() = true;
		return token;
	}

	else if (c == '[') {
		JSONToken token;
		token.isOpenBracket() = true;
		return token;
	}
	else if (c == ']') {
		JSONToken token;
		token.isCloseBracket() = true;
		return token;
	}
	else if (c == '{') {
		JSONToken token;
		token.isOpenBrace() = true;
		return token;
	}
	else if (c == '}') {
		JSONToken token;
		token.isCloseBrace() = true;
		return token;
	}

	else if (c == ':') {
		JSONToken token;
		token.isColon() = true;
		return token;
	}

	else if (c == ',') {
		JSONToken token;
		token.isComma() = true;
		return token;
	}

	else if (c == '"') {
		JSONToken token;
		std::string sol = "";
		inputStream >> c;
		while (c != '"') {
			sol += c;
			inputStream.get(c);
		}
		token.setName(sol);
		return token;
	}

	else if (isdigit(c)) {
		inputStream.putback(c);
		double value;
		inputStream >> value;
		JSONToken token;
		token.setValue(value);
		return token;
	}

	else {
		std::cout << "Unexpected character in input ->" << c << "<-\n";
		std::cout << "Terminating...\n";
		exit(5);
	}
}
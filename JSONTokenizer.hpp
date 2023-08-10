//
// Created by Logan Santos on 3/12/22.
//
#include "JSONToken.hpp"
#include <string>
#include <iostream>
#include <fstream>

#ifndef PROJECT3_JSONTOKENIZER_HPP
#define PROJECT3_JSONTOKENIZER_HPP

class JSONTokenizer {

public:
	explicit JSONTokenizer(const std::string &inputFile);

	JSONToken getToken();

private:
	std::string inputFileName;
	std::fstream inputStream;
};

#endif //PROJECT3_JSONTOKENIZER_HPP

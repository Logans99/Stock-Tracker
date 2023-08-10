//
// Created by Logan Santos on 3/30/22.
//

#ifndef PROJECT3_JSONPARSER_HPP
#define PROJECT3_JSONPARSER_HPP
#include "Pair.hpp"
#include "EntityInstance.hpp"
#include "EntitySet.hpp"
#include "JSONTokenizer.hpp"

class JSONParser {
public:
	JSONParser(std::string nameOfInputFile);
	Pair parseAPair();
	EntityInstance parseJSONObject();
	EntitySet parseJSONEntity();

private:
	JSONTokenizer tokenizer; // the input file name is used to create an instance of JSONTOkenizer
	// please note that there is not an ampersand in front of "tokenizer"
};


#endif //PROJECT3_JSONPARSER_HPP

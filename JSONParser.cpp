//
// Created by Logan Santos on 3/30/22.
//

#include "JSONParser.hpp"

JSONParser::JSONParser(std::string nameOfInputFile):tokenizer(nameOfInputFile) {

}

EntityInstance JSONParser::parseJSONObject() {
	// parseJSONObject is responsible for parsing a JSON object. As such,
	// the first token is expected to be an open brace.
	JSONToken token = tokenizer.getToken();
	if( ! token.isOpenBrace() ) {
		std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
		token.print();
		std::cout << "Terminating..." << std::endl;
		exit(1);
	}
	EntityInstance instance;
	do {
		Pair pair = parseAPair();
		instance.addPair(pair);
		token = tokenizer.getToken();
	} while( token.isComma() );  // after having read a pair, we expect a comma
	// So, the above loop terminates when we did find a comma.
	// that means we have parsed an entire object. In that case, token must contain
	// the close brace of that object.
	if( ! token.isCloseBrace() ) {
		std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
		token.print();
		std::cout << "Terminating..." << std::endl;
		exit(1);
	}
	return instance;
}

Pair JSONParser::parseAPair() {
	JSONToken token = tokenizer.getToken();
	if (token.getName() == "") {
		exit(2);
	}
	std::string tokenName = token.getName();

	token = tokenizer.getToken();			// This is now overwritten
	if (!token.isColon()) {
		exit(3);
	}

	token = tokenizer.getToken();									// This is now overwritten... again
	if (token.getName() == "" && token.getValue() == - 1) {			// -1 is the set check value for when it's not number token
		exit(4);
	}

	if (token.getName() != "") {
		Pair pair(tokenName, token.getName());			// token name is the first parameter token value is the second parameter
		return pair;
	}

	else {
		Pair pair(tokenName, token.getValue());
		return pair;
	}
}

// ParseEntity set parse function go here just like parseJSONObject but for {}
EntitySet JSONParser::parseJSONEntity() {
	JSONToken token = tokenizer.getToken();
	if (!token.isOpenBracket()) {
		std::cout << "Error: JSONParser::parseJSONEntity: Expected an open bracket, but found" << std::endl;
		token.print();
		std::cout << "Terminating..." << std::endl;
		exit(1);
	}
	EntitySet set;
	do {
		EntityInstance instance = parseJSONObject();
		set.addEntity(instance);
		token = tokenizer.getToken();
	} while (token.isComma());  // after having read a pair, we expect a comma
	// So, the above loop terminates when we did find a comma.
	// that means we have parsed an entire object. In that case, token must contain
	// the close bracket of that object.
	if( ! token.isCloseBracket() ) {
		std::cout << "Error: JSONParser::parseJSONEntity: Expected an close bracket, but found" << std::endl;
		token.print();
		std::cout << "Terminating..." << std::endl;
		exit(1);
	}
	return set;
}
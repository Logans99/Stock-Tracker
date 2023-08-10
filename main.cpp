//
// Created by Logan Santos on 3/12/22.
//

#include <string>
#include "JSONParser.hpp"
#include "EquityStats.hpp"
#include <iostream>
#include <cassert>
#include <stack>
#include <vector>

int main(int argc, char *argv[]) {
	std::ifstream inputStream;
	inputStream.open(argv[2], std::ios::in);    // open for reading
	if( ! inputStream.is_open()) {
		std::cout << "Unable top open " << argv[2] << ". Terminating...";
		exit(2);
	}
	inputStream.close();

	// std::vector<std::string> keyValues = {"Date", "Close", "Volume"}; // product to change

	//std::vector<std::string> keyValues = {"Date" , "Volume", "Close", "EMA-12", "EMA-26", "MACD", "Signal"};

	std::vector<std::string> keyValues = {"Date" , "Open", "High", "Low", "Close" , "Volume","EMA-12", "EMA-26", "MACD", "Signal"};

	JSONParser parser(argv[2]);
	EntitySet set = parser.parseJSONEntity();

	EquityStats stat(set);

	stat.average(12);
	stat.average(26);

	stat.expoMoving(12);
	stat.expoMoving(26);

	stat.MACD();

	stat.signal();
	stat.Print(keyValues, argv[1]);
/*
	JSONTokenizer jsonTokenizer(argv[1]); // The Tokenizer opens and reads from the input file.
	JSONToken token = jsonTokenizer.getToken();

	while( ! token.isEOF() ) {					  // Possible Error here
		token.print();
		token = jsonTokenizer.getToken();
	}

 */
	return 0;

}
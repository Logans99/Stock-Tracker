//
// Created by Logan Santos on 3/30/22.
//

#ifndef PROJECT3_ENTITYINSTANCE_HPP
#define PROJECT3_ENTITYINSTANCE_HPP


#include <vector>
#include "Pair.hpp"

class EntityInstance {
public:
	void addPair(Pair &pair); // Add a new pair to this entity.
	int numAttributes();  // how many pairs are in this instance?
	std::vector<std::string> attributeNames();
	void printInJSON();   // prints this object.
	void printInCSV(std::vector<std::string> output);
	// more member functions here when necessary.

	double close();   // an accessor function that return the
	// value associated with an attribute. In this case, the value.
	// of attribute, Close. You will need to add more such functions
	// to this class.

	std::string date();
	double dividends();
	double high();
	double low();
	double open();
	int stockSplits();
	std::string timeStamp();
	int volume();

	double AVG12();
	double AVG26();

	double EMA12();
	double SMA12();
	double EMA26();
	double SMA26();
	double MACD();
	double signal();
	int id();
	std::string action();

private:
	std::vector<Pair> entityPairs;
	// more variables here as necessary.
};


#endif //PROJECT3_ENTITYINSTANCE_HPP

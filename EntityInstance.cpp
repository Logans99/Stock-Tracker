//
// Created by Logan Santos on 3/30/22.
//

#include "EntityInstance.hpp"
#include <iostream>
#include <iomanip>

void EntityInstance::addPair(Pair &pair) {
	entityPairs.push_back(pair);
}

int EntityInstance::numAttributes() {
	return entityPairs.size();
}

void EntityInstance::printInJSON() {
	for (int i = 0; i < entityPairs.size(); i++) {
		//std::cout << " \t";
		entityPairs.at(i).printInJSON(2);
		//std::cout << ",";
	}
}

double EntityInstance::close() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "Close") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

std::string EntityInstance::date() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "Date") {
			return entityPairs.at(i).stringValue();
		}
	}
	return "";
}

double EntityInstance::dividends() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "Dividends") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

double EntityInstance::high() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "High") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

double EntityInstance::low() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "Low") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

double EntityInstance::open() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "Open") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

int EntityInstance::stockSplits() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "Stock Splits") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

std::string EntityInstance::timeStamp() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "Timestamp") {
			return entityPairs.at(i).stringValue();
		}
	}
	return "";
}

int EntityInstance::volume() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "Volume") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

double EntityInstance::AVG12() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "Average-12") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

double EntityInstance::AVG26() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "Average-26") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

double EntityInstance::EMA12() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "EMA-12") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

double EntityInstance::SMA12() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "SMA-12") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

double EntityInstance::EMA26() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "EMA-26") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

double EntityInstance::SMA26() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "SMA-26") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

double EntityInstance::MACD() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "MACD") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

double EntityInstance::signal() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "Signal") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

int EntityInstance::id() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "id") {
			return entityPairs.at(i).numberValue();
		}
	}
	return -1;
}

std::string EntityInstance::action() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs.at(i).attributeName() == "action") {
			return entityPairs.at(i).stringValue();
		}
	}
	return "";
}

void EntityInstance::printInCSV(std::vector<std::string> output) {
	for (int i = 0; i < output.size(); i++) {

		if (output.at(i) == "Close") {
			if (close() != -1) {
				std::cout << std::fixed << std::setprecision(4) << close();
			}
		}
		else if (output.at(i) == "Date") {
			std::cout << date();
		}
		else if (output.at(i) == "Dividends") {
			if (dividends() != -1) {
				std::cout << std::fixed << std::setprecision(0) << dividends();
			}
		}
		else if (output.at(i) == "High") {
			if (high() != -1) {
				std::cout << std::fixed << std::setprecision(4) << high();
			}
		}
		else if (output.at(i) == "Low") {
			if (low() != -1) {
				std::cout << std::fixed << std::setprecision(4) << low();
			}
		}
		else if (output.at(i) == "Open") {
			if (open() != -1) {
				std::cout << std::fixed << std::setprecision(4) << open();
			}
		}
		else if (output.at(i) == "Stock Splits") {
			if (stockSplits() != -1) {
				std::cout << std::fixed << std::setprecision(0) << stockSplits();
			}
		}

		else if (output.at(i) == "Timestamp") {
			std::cout << timeStamp();
		}

		else if (output.at(i) == "Volume") {
			if (volume() != -1) {
				std::cout << std::fixed << std::setprecision(0) << volume();
			}
		}
		else if (output.at(i) == "EMA-12") {
			if (EMA12() != -1) {
				std::cout << std::fixed << std::setprecision(4) << EMA12();
			}
		}
		else if (output.at(i) == "SMA-12") {
			if (SMA12() != -1) {
				std::cout << std::fixed << std::setprecision(4) << SMA12();
			}
		}
		else if (output.at(i) == "EMA-26") {
			if (EMA26() != -1) {
				std::cout << std::fixed << std::setprecision(4) << EMA26();
			}
		}
		else if (output.at(i) == "SMA-26") {
			if (SMA26() != -1) {
				std::cout << std::fixed << std::setprecision(4) << SMA26();
			}
		}
		else if (output.at(i) == "MACD") {
			if (MACD() != -1) {
				std::cout << std::fixed << std::setprecision(4) << MACD();
			}
		}
		else if (output.at(i) == "EMA-12") {
			if (EMA12() != -1) {
				std::cout << std::fixed << std::setprecision(4) << EMA12();
			}
		}

		else if (output.at(i) == "Signal") {
			if (signal() != -1) {
				std::cout << std::setprecision(4) << signal();
			}
		}

		else if (output.at(i) == "id") {
			if (id() != -1) {
				std::cout << std::fixed << std::setprecision(4) << id();
			}
		}

		else if (output.at(i) == "action") {
			std::cout << action();
		}

		else {
			std::cout << output[i] << "not found... no pair" << std::endl;
			exit(1);
		}

		if (i != output.size() - 1) {
			std::cout << ",";
		}
	}
}

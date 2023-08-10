//
// Created by Logan Santos on 3/30/22.
//

#include <iostream>
#include "EntitySet.hpp"

EntitySet::EntitySet() {
}

void EntitySet::addEntity(EntityInstance &instance) {
	instances.push_back(instance);
}

void EntitySet::printInJSON() {
	std::cout << "[\n";

	for (int i = 0; i < instances.size(); i++) {
		std::cout << "\t";
		std::cout << "{\n";
		instances.at(i).printInJSON();

		std::cout << "\t\t" << "\"id\": " << i << std::endl;

		std::cout << "\t}";
		//std::cout << ",";

		if (i != instances.size() - 1) {
			std::cout << ",\n";
		}

		else
			std::cout << "\n";
	}
	std::cout << "]\n";
}

std::vector<EntityInstance> & EntitySet::getEntityInstances() {
	return instances;
}

void EntitySet::printInCSV(std::vector<std::string> output) {
	for (int i = 0; i < output.size(); i++) {
		std::cout << output.at(i);

		if (i != output.size() - 1) {
			std::cout << ",";
		}
	}

	std::cout << "\n";

	for (int i = 0; i < instances.size(); i++) {
		instances.at(i).printInCSV(output);
		std::cout << "\n";
	}
}
//
// Created by Logan Santos on 3/30/22.
//

#ifndef PROJECT3_ENTITYSET_HPP
#define PROJECT3_ENTITYSET_HPP
#include "EntityInstance.hpp"

class EntitySet {
public:
	EntitySet();

	void addEntity(EntityInstance &);
	void printInJSON();    // prints all instances of this Entity.
	std::vector<EntityInstance> & getEntityInstances(); // returns "instances" Pass this by refrence
	// more member functions here.

	void printInCSV(std::vector<std::string> output);

private:
	std::vector<EntityInstance> instances;
};


#endif //PROJECT3_ENTITYSET_HPP

//
// Created by Logan Santos on 4/06/22.
//

#ifndef PROJECT3_EQUITYSTATS_HPP
#define PROJECT3_EQUITYSTATS_HPP
#include "EntitySet.hpp"

class EquityStats {

public:
	void average(int avgDay);
	double averageHelper(int curDay, int avgDay);
	void expoMoving(int avgDay);
	void signal();
	double signalHelper(int curDay);
	void MACD();
	EquityStats(EntitySet);
	void Print(std::vector<std::string> myString, std::string flag);

private:
	EntitySet set;
};


#endif //PROJECT3_EQUITYSTATS_HPP

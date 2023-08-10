//
// Created by Logan Santos on 4/06/22.
//

#include "EquityStats.hpp"

double EquityStats::averageHelper(int curDay, int avgDay) {
	double avg = 0;

	for (int i = curDay - (avgDay - 1); i <= curDay; i++) {
		avg += set.getEntityInstances().at(i).close();
	}

	return avg / avgDay;
}

void EquityStats::average(int avgDay) {

	for (int i = avgDay - 1; i < set.getEntityInstances().size(); i++) {
		double localAvg = averageHelper(i, avgDay);

		if (avgDay == 12) {
			Pair avgPair("Average-12", localAvg);
			set.getEntityInstances().at(i).addPair(avgPair);
		}
		else {
			Pair avg("Average-26", localAvg);
			set.getEntityInstances().at(i).addPair(avg);
		}
	}
}

void EquityStats::expoMoving(int avgDay) {

	double smooth = 2.0 / (1 + avgDay);

	for (int i = avgDay - 1; i < set.getEntityInstances().size(); i++) {

		double closeAmount = set.getEntityInstances().at(i).close();

		if ((set.getEntityInstances().at(i - 1).EMA12() == - 1 && avgDay == 12) || set.getEntityInstances().at(i - 1).EMA26() == - 1 && avgDay == 26) {

			if (avgDay == 12) {
				double regMovingAvg = set.getEntityInstances().at(i).AVG12();
				//double total = closeAmount * smooth + regMovingAvg * (1.0 - smooth);
				Pair pair("EMA-12", regMovingAvg);
				set.getEntityInstances().at(i).addPair(pair);
			}

			// Handles pair if there is no yesterday
			else {
				double regMovingAvg = set.getEntityInstances().at(i).AVG26();
				//double total = closeAmount * smooth + regMovingAvg * (1.0 - smooth);
				Pair pair("EMA-26", regMovingAvg);
				set.getEntityInstances().at(i).addPair(pair);
			}
		}

		// same as above but the yesterdays EMA12/ EMA26
		 else {

			if (avgDay == 12) {
				double regMovingAvg = set.getEntityInstances().at(i - 1).EMA12();
				double total = closeAmount * smooth + regMovingAvg * (1.0 - smooth);
				Pair pair("EMA-12", total);
				set.getEntityInstances().at(i).addPair(pair);
			}

			// EMA 26 will go here
			else {
				double regMovingAvg = set.getEntityInstances().at(i - 1).EMA26();
				double total = closeAmount * smooth + regMovingAvg * (1.0 - smooth);
				Pair pair("EMA-26", total);
				set.getEntityInstances().at(i).addPair(pair);
			}
		 }
	}
}

void EquityStats::MACD() {
	for (int i = 25; i < set.getEntityInstances().size(); i++) {
		// MACD is EMA12 - EMA 26
		double computeEMA12 = set.getEntityInstances().at(i).EMA12();
		double computeEMA26 = set.getEntityInstances().at(i).EMA26();
		double totalMACD = (computeEMA12 - computeEMA26);

		Pair pair("MACD", totalMACD);
		set.getEntityInstances().at(i).addPair(pair);
	}
}

double EquityStats::signalHelper(int curDay) {
	// signal EMA formula with a nine-day moving average. close value for today is current value MACD
	// EMA for yesterday is the sum of the last nine days including curDay MACD
	// smoothing is 0.2

	double sum = 0;

	for (int i = curDay - 8; i <= curDay; i++) {
		sum += set.getEntityInstances().at(i).MACD();
	}

	return sum / 9;
}

void EquityStats::signal() {

	double smooth = 0.2;

	double numSignal = signalHelper(33);

	Pair pair("Signal", numSignal);
	set.getEntityInstances().at(33).addPair(pair);

	for (int i = 34; i < set.getEntityInstances().size(); i++) {  // changed from 34 to 33

		double closeAmount = set.getEntityInstances().at(i).MACD();

		double movingAvg = set.getEntityInstances().at(i - 1).signal();

		double total = closeAmount * smooth + movingAvg * (1.0 - smooth);

		Pair pair("Signal", total);
		set.getEntityInstances().at(i).addPair(pair);

	}
}

EquityStats::EquityStats(EntitySet eqStat) {
	set = eqStat;
}

void EquityStats::Print(std::vector<std::string> myString, std::string flag) {

	if (flag == "-csv") {
		set.printInCSV(myString);
	}

	if (flag == "-json") {
		set.printInJSON();
	}
}

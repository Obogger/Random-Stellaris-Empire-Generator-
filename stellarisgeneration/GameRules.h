#pragma once
#include <string>
#include <iostream>

using namespace std;
class GameRules
{
	public:
		//
		string randomApperanceRace(int gameFrom);
		string apperanceRace;

		int getRace();
		int race; 

		//
		int randomApperanceType(int gameFrom);
		int apperanceType;

		//
		string randomGovernmentType(int race);
		string governmentType;

		int getGovernmentType();
		int governmentTypeNumber;

		//
		int randomOrigin(int government, int type, int race);
		int origin;

		int getOriginSelectionAmount();
		int originAmount;

		//
		string randomTraitQuality(int race);
		string traitQuality;


};
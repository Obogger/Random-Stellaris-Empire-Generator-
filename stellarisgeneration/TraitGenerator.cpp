#include "GameRules.h"

string qualityType[] = { "Failure", "Incapable", "Inferior", "Avrage", "Avrage", "Avrage", "Avrage", "Avrage", "Superior", "Gifted", "Perfect",
"Scrap", "Scrap", "Scrap" , "Avrage", "Avrage", "Avrage", "Avrage", "Avrage", "Excellent", "Excellent", "Excellent" };


int temp1;
int current[20] = { 99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99, };

string GameRules::randomTraitQuality(int race)
{
	if (race == 1)
	{
		temp1 = rand() % 11 + 11;
	}
	else
	{
		temp1 = rand() % 11;
	}
	string awnser = qualityType[temp1];
	return awnser;

}


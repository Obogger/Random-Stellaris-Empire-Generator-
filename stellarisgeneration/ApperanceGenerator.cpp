#include "GameRules.h"


string gameTypeApperanceName[] = { "Humanoid", "Machine", "Mammalian", "Reptilian", "Avian",
"Arthropoid", "Mollusciod", "Fungoid", "Plantoid", "Lithiod", "Necroid", "Aquatic", "Toxoid"
};

int gameTypeApperance[500] = {
13,16,13,18,17,18,18,16,16,16,15,15,15,15,0,0,0,0,0,0,0,0 };

using namespace std;
int race;

string GameRules::randomApperanceRace(int gameFrom)
{
	
	race = rand() % gameTypeApperance[gameFrom];
	string awnser = gameTypeApperanceName[race];

	return awnser;
}
int GameRules::randomApperanceType(int gameFrom)
{
	int awnser = rand() % gameTypeApperance[gameFrom + race];
	return awnser;
}
int GameRules::getRace()
{
	return race;
}

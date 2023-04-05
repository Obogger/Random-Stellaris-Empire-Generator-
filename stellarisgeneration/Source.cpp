#include<iostream>
#include<iomanip>
#include<istream>
#include<cmath>
#include<array>
#include<Windows.h>
#include<istream>
#include<string.h>
#include<vector>
#include<string>
#include<fstream>
#include<random>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>


#include"GameRules.h"

using namespace std;


void randomCalculator(int type);


int randomGovernmentType(int race);
int randomOrigin(int gestalt, int type, int race);
int randomWorldType(int type);
int randomTraitQuality(int race);

int restrictions[] = { 99,99,99,99,99,99,99 };
int game[100];
int gameTypeWorld[500] = { 72 };
int gameTypeTraits[500] = { 300, 60 };
string prompt[] = { "Apperance Race: ", "Apperance Type: ", "Origin: ", "Planet Class: ", "Species Quality: ",
"Traits: ", "Government Type: ", "Government Ethics: " };


int main()
{
	int menuSelector;
	int gameset;
	cin >> gameset;
	randomCalculator(gameset);
	cout << "\n\n\n REDO? \n";
	system("pause");

}
void randomCalculator(int type)
{
	int gameFrom = (type - 1) * 40;
	GameRules gameRule;
	gameRule.apperanceRace = gameRule.randomApperanceRace(gameFrom);
	int race = gameRule.getRace();
	gameRule.apperanceType = gameRule.randomApperanceType(gameFrom);
	gameRule.governmentType = gameRule.randomGovernmentType(gameFrom);
	int governmentType = gameRule.getGovernmentType();
	gameRule.origin = gameRule.randomOrigin(governmentType, type, race);
	gameRule.originAmount = gameRule.getOriginSelectionAmount();
	gameRule.traitQuality = gameRule.randomTraitQuality(race);

	system("cls");
	srand(GetTickCount64());
	bool isGestalt = NULL;
	game[4] = randomWorldType(type);
	cout << prompt[0] << gameRule.apperanceRace << endl;
	cout << prompt[1] << gameRule.apperanceType << endl;
	cout << prompt[2] << ((gameRule.origin) / 4) + 1 << "/" << ((gameRule.originAmount) / 4) - ((gameRule.origin) / 4) + 1
		<< ":" << ((gameRule.origin) - ((gameRule.origin - 1) / 4) * 4) + 1 << endl;
	cout << prompt[3] << game[4] << endl;
	cout << prompt[4] << gameRule.traitQuality << endl;
	cout << prompt[5] << endl;
	cout << prompt[6];
	if (game[12] == 0)
	{
		cout << "Machine Intelligence";
	}
	else if (game[12] == 1)
	{
		cout << "Hivemind";
	}
	else
	{
		cout << "Normal";
	}
	cout << endl << prompt[7] << endl;
	cout << "\n\n\nREDO? \n";
	system("pause");
	system("cls");
	randomCalculator(type);
	return;



}
int randomWorldType(int type)
{
	int awnser = rand() % gameTypeWorld[type - 1] + 1;
	return awnser;
}
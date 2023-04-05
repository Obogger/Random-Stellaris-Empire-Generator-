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

int randomApperanceRace(int gameFrom);
int randomApperanceType(int gameFrom, int race);
int randomGovernmentType(int race);
int randomOrigin(int gestalt, int type, int race);
int randomWorldType(int type);
int randomTraitQuality(int race);

int restrictions[] = { 99,99,99,99,99,99,99 };
int game[100];
int gameTypeOrigin[500] = { 95 };
int gameTypeWorld[500] = { 72 };
int gameTypeTraits[500] = { 300, 60 };
string prompt[] = { "Apperance Race: ", "Apperance Type: ", "Origin: ", "Planet Class: ", "Species Quality: ",
"Traits: ", "Government Type: ", "Government Ethics: " };

string qualityType[] = { "Failure", "Incapable", "Inferior", "Avrage", "Avrage", "Avrage", "Avrage", "Avrage", "Superior", "Gifted", "Perfect",
"Scrap", "Scrap", "Scrap" , "Avrage", "Avrage", "Avrage", "Avrage", "Avrage", "Excellent", "Excellent", "Excellent" };

string gameGestaltEthics[] = { "Progression", "Analysis", "Encroachment", "Connection", "Convalescence", "Logistics",
"Impassive", "Introspective", "Autonomous", "Affective", "Extrospective", "Convergent"
};

string gameEthics[] = { "Fanatic Libertarian", "Fanatic Militarist", "Fanatic Xenophobe", "Fanatic Competitive", "Fanatic Elitist", "Fanatic Materialist",
"Fanatic Anthropocentric", "Fanatic Authoritarian", "Fanatic Pacifist", "Fanatic Xenophile", "Fanatic Cooperative", "Fanatic Pluralist", "Fanatic Spiritualist", "Fanatic Ecocentric",
"Libertarian", "Militarist", "Xenophobe", "Competitive", "Elitist", "Materialist", "Anthropocentric", "Authoritarian", "Pacifist", "Xenophile", "Cooperative",
"Pluralist", "Spiritualist", "Ecocentric" };

string originRestrictions[] = { ":", "G+050+:", "G-:", "M-:", "M-:", ":", ":", "G-:", "G-2-:", ":", "H+:", "G-:", "L+:", "M+:", "G-020-:", "G-020-", ":", "G-:", "M-090-00-", "G-:" };

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
	gameRule.apperanceType = gameRule.randomApperanceType(gameFrom);


	system("cls");
	srand(GetTickCount64());
	string traitQuality;
	bool isGestalt = NULL;
	game[0] = randomApperanceRace(gameFrom);
	game[1] = randomApperanceType(gameFrom, game[0]);
	game[2] = randomGovernmentType(game[0]);
	game[3] = randomOrigin(game[2], type, game[0]);
	game[4] = randomWorldType(type);
	game[5] = randomTraitQuality(game[0]);
	int i = 0;
	int fnatic = 0;
	int normal = 0;
	int current[20] = { 99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99, };
	int c = 0;
	i = 0;
	if (isGestalt == true)
	{
		game[13] = rand() % 6;
		int success = rand() % 3 - 3;
		i = 0;
		int avaiable = 0;
		while (success < 0)
		{
			avaiable = rand() % 6 + 6;
			c = 0;
			for (c = 0; c < 7; c++)
			{
				if (avaiable != current[c])
				{
					if (c == 6)
					{

						current[i] = avaiable;
						if (avaiable < 9)
						{
							current[i + 3] = avaiable + 3;
						}
						else
						{
							current[i + 3] = avaiable - 3;
						}
						success++;
						i++;

					}
				}
				else
				{
					c = 100;
				}
			}
		}
	}
	else
	{
		fnatic = rand() % (3 - fnatic);
		normal = rand() % (6 - fnatic * 2);
		int d = 3;
		while (d > fnatic * 2 + normal)
		{
			fnatic = rand() % 3;
			normal = rand() % (6 - fnatic * 2);
		}
		int success = fnatic;
		i = 0;
		int avaiable = 0;
		c = 0;
		int round = 0;
		while ((success > 0) || (fnatic == 0))
		{
			c = 0;
			avaiable = rand() % 14 + (round * (14));
			if (fnatic == 0)
			{
				c = 100;
				success = normal;
				normal = -99;
				round = 1;
				fnatic = 2;
			}
			for (c; c < 21; c++)
			{
				if (avaiable != current[c] && avaiable != restrictions[c])
				{
					if (c == 20)
					{
						current[i] = avaiable;
						if (avaiable < 7 + (round * (14)))
						{
							current[i + 5] = avaiable + 7 - (round * (21));
							current[i + 10] = avaiable + 14 - (round * (21));
							current[i + 15] = avaiable + 21 - (round * (14));
						}
						else
						{
							current[i + 5] = avaiable - 7 - (round * (14));
							current[i + 10] = avaiable + 7 - (round * (14));
							current[i + 15] = avaiable + 14 - (round * (7));
						}
						success--;
						i++;

					}
				}
				else
				{
					c = 100;
				}
			}
			if (success == 0)
			{
				success = normal;
				normal = -99;
				round = 1;
				fnatic = 2;
			}
		}
	}
	cout << prompt[0] << gameRule.apperanceRace << endl;
	cout << prompt[1] << game[1] << endl;
	cout << prompt[2] << ((game[3]) / 4) + 1 << "/" << ((gameTypeOrigin[0]) / 4) - ((game[3]) / 4) + 1
		<< ":" << ((game[3]) - ((game[3] - 1) / 4) * 4) + 1 << endl;
	cout << prompt[3] << game[4] << endl;
	cout << prompt[4] << qualityType[game[5]] << endl;
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
	if (isGestalt == true)
	{
		cout << gameGestaltEthics[game[13]] << endl;
		for (int c = 0; c < i; c++)
		{
			cout << gameGestaltEthics[current[c]] << endl;
		}
	}
	else
	{
		for (int c = 0; c < i; c++)
		{
			cout << gameEthics[current[c]] << endl;
		}
	}
	cout << "\n\n\nREDO? \n";
	system("pause");
	system("cls");
	randomCalculator(type);
	return;



}
int randomGovernmentType(int race)
{
	int awnser;
	if (race == 1)
	{
		awnser = 1;
	}
	else if (rand() % 100 + 1 <= 10)
	{
		awnser = 2;
	}
	else
	{
		awnser = 0;
	}
	return awnser;
	
}
int randomOrigin(int gestalt, int type, int race)
{
	int awnser = rand() % 20;
	bool isGestalt = gestalt;
	int temp = 0;
	int turn = 0;
	char excep = 'q';
	bool exception = false;
	for (int c = 0; originRestrictions[awnser][c] != ':'; c++)
	{
		if (originRestrictions[awnser][c] != '+' && originRestrictions[awnser][c] != '-')
		{
			if (int(originRestrictions[awnser][c] - 48) < 10)
			{
				temp = temp * 10 + int(originRestrictions[awnser][c] - 48);
				turn++;

			}
			else
			{
				excep = originRestrictions[awnser][c];
				exception = true;
			}
		}
		else
		{
			if (originRestrictions[awnser][c] == '+')
			{

				if (exception == true)
				{
					if (excep == 'G')
					{
						if (isGestalt == false)
						{
							c = -1;
							awnser = rand() % gameTypeOrigin[type - 1];
							awnser = rand() % 20;
						}
					}
					else if (excep == 'M')
					{
						if (race != 1)
						{
							c = -1;
							awnser = rand() % gameTypeOrigin[type - 1];
							awnser = rand() % 20;
						}
					}
					else if (excep == 'H')
					{
						if (gestalt != 2)
						{
							c = -1;
							awnser = rand() % gameTypeOrigin[type - 1];
							awnser = rand() % 20;
						}
					}
					else if (excep == 'L')
					{
						if (race != 9)
						{
							c = -1;
							awnser = rand() % gameTypeOrigin[type - 1];
							awnser = rand() % 20;
						}
					}
					exception = false;
				}
				else if (turn)
				{

				}
				turn = 0;
			}
			else if (originRestrictions[awnser][c] == '-')
			{
				if (exception == true)
				{
					if (excep == 'G')
					{
						if (isGestalt == true)
						{
							c = -1;
							awnser = rand() % gameTypeOrigin[type - 1];
							awnser = rand() % 20;
						}
					}
					else if (excep == 'M')
					{
						if (game[0] == 1)
						{
							c = -1;
							awnser = rand() % gameTypeOrigin[type - 1];
							awnser = rand() % 20;
						}
					}
					else if (excep == 'H')
					{
						if (game[2] == 2)
						{
							c = -1;
							awnser = rand() % gameTypeOrigin[type - 1];
							awnser = rand() % 20;
						}
					}
					else if (excep == 'L')
					{
						if (race == 9)
						{
							c = -1;
							awnser = rand() % gameTypeOrigin[type - 1];
							awnser = rand() % 20;
						}
					}
					exception = false;
				}
				turn = 0;
				//restrictions[i] = temp;
			}
			temp = 0;
		}

	}
	return awnser;
}
int randomWorldType(int type)
{
	int awnser = rand() % gameTypeWorld[type - 1] + 1;
	return awnser;
}
int randomTraitQuality(int race)
{
	int awnser;
	if (race == 1)
	{
		awnser = rand() % 11 + 11;
	}
	else
	{
		awnser = rand() % 11;
	}
	return awnser;
}
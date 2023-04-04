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

using namespace std;


void randomCalculator(int type);

int game[100];
int gameTypeApperance[500] = {
13,16,13,18,17,18,18,16,16,16,15,15,15,15,0,0,0,0,0,0,0,0 };
int gameTypeOrigin[500] = { 95 };
int gameTypeWorld[500] = { 72 };
int gameTypeTraits[500] = { 300, 60 };
string prompt[] = { "Apperance Race: ", "Apperance Type: ", "Origin: ", "Planet Class: ", "Species Quality: ",
"Traits: ", "Government Type: ", "Government Ethics: " };

string qualityType[] = { "Failure", "Incapable", "Inferior", "Avrage", "Avrage", "Avrage", "Avrage", "Avrage", "Superior", "Gifted", "Perfect"
"Scrap", "Scrap", "Scrap" , "Avrage", "Avrage", "Avrage", "Avrage", "Avrage", "Excellent", "Excellent", "Excellent" };


string gameTypeApperanceName[] = { "Humanoid", "Machine", "Mammalian", "Reptilian", "Avian",
"Arthropoid", "Mollusciod", "Fungoid", "Plantoid", "Lithiod", "Necroid", "Aquatic", "Toxoid"
};

string gameGestaltEthics[] = { "Progression", "Analysis", "Encroachment", "Connection", "Convalescence", "Logistics",
"Impassive", "Introspective", "Autonomous", "Affective", "Extrospective", "Convergent"
};

string gameEthics[] = { "Fanatic Libertarian", "Fanatic Militarist", "Fanatic Xenophobe", "Fanatic Competitive", "Fanatic Elitist", "Fanatic Materialist",
"Fanatic Anthropocentric", "Fanatic Authoritarian", "Fanatic Pacifist", "Fanatic Xenophile", "Fanatic Cooperative", "Fanatic Pluralist", "Fanatic Spiritualist", "Fanatic Ecocentric",
"Libertarian", "Militarist", "Xenophobe", "Competitive", "Elitist", "Materialist", "Anthropocentric", "Authoritarian", "Pacifist", "Xenophile", "Cooperative",
"Pluralist", "Spiritualist", "Ecocentric" };

string originRestrictions[] = { ":", "05+19+G-:", "G-:", "M-:", "M-:", ":", ":", "G-", "G-2-:", ":", "H+:", "G-:" };

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
	system("cls");
	srand(GetTickCount64());
	int gameFrom = (type - 1) * 40;
	string traitQuality;

	game[0] = rand() % gameTypeApperance[gameFrom];
	cout << prompt[0] << gameTypeApperanceName[game[0]] << endl;
	game[1] = rand() % gameTypeApperance[gameFrom + game[0] + 1];
	cout << prompt[1] << game[1] << endl;
	game[2] = rand() % gameTypeOrigin[type - 1];
	game[2] = 1;
	int temp = 0;
	int restrictions[] = { 99,99,99,99,99,99,99 };
	int i = 0;
	for(int c = 0; originRestrictions[game[2]][c] != ':' ; c++)
	{
		if (originRestrictions[game[2]][c] != '+'&& originRestrictions[game[2]][c] != '-')
		{
			if (int(originRestrictions[game[2]][c] - 48) / 10 == 0)
			{
				temp = temp * 10 + int(originRestrictions[game[2]][c] - 48);


			}
			else
			{

			}
		}
		else
		{
			if (originRestrictions[game[2]][c] == '+')
			{
				restrictions[i];
			}
			else if(originRestrictions[game[2]][c] == '-')
			{

				restrictions[i] = temp;
			}
			temp = 0;
			i++;
		}

	}
	cout << prompt[2] << ((game[2] - 1) / 4) + 1 << "/" << ((gameTypeOrigin[0]) / 4) - ((game[2] - 1) / 4) + 1
		<< ":" << ((game[2] - 1) - ((game[2] - 1) / 4) * 4) + 1 << endl;

	game[3] = rand() % gameTypeWorld[type - 1] + 1;
	cout << prompt[3] << game[3] << endl;

	if (game[0] == 2)
	{
		traitQuality = qualityType[rand() % 11 + 11];
	}
	else
	{
		traitQuality = qualityType[rand() % 11];
	}
	cout << prompt[4] << traitQuality << endl;
	cout << prompt[5] << endl;
	for (int t = 5; t < 11; t++)
	{
		game[t] = rand() % 300 + 1;
		cout << game[t] << endl;

	}

	cout << endl << endl;
	bool isGestalt = NULL;
	cout << prompt[6];
	if (game[0] == 2)
	{
		cout << "Machine Intelligence";
		isGestalt = true;
	}
	else if (rand() % 100 + 1 <= 10)
	{
		cout << "Hivemind";
		isGestalt = true;
	}
	else
	{
		cout << "Normal";
		isGestalt = false;
	}
	cout << endl << prompt[7] << endl;
	if (isGestalt == true)
	{
		int current[6] = { 99,99,99,99,99,99 };
		cout << gameGestaltEthics[rand() % 6] << endl;
		int success = rand() % 3 - 3;
		int i = 0;
		int avaiable = 0;
		while (success < 0)
		{
			avaiable = rand() % 6 + 6;
			int c = 0;
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
		for (int c = 0; c < i; c++)
		{
			cout << gameGestaltEthics[current[c]] << endl;
		}

	}
	else 
	{
		int fnatic = rand() % 3;
		int normal = rand() % (6 - fnatic * 2);
		int d = 3;
		while (d > fnatic * 2 + normal)
		{
			fnatic = rand() % 3;
			normal = rand() % (6 - fnatic * 2);
		}
		int current[20] = { 99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99, };
		int success = fnatic;
		int i = 0;
		int avaiable = 0;
		int c = 0;
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
				if (avaiable != current[c] || avaiable != restrictions[c])
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
			if (success== 0)
			{
				success = normal;
				normal = -99;
				round = 1;
				fnatic = 2;
			}
		}
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
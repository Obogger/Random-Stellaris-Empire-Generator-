#include "GameRules.h"

string governmentTypes[] = {"Normal", "Machine Intellegence", "Hivemind"};

string gameEthics[] = { "Fanatic Libertarian", "Fanatic Militarist", "Fanatic Xenophobe", "Fanatic Competitive", "Fanatic Elitist", "Fanatic Materialist",
"Fanatic Anthropocentric", "Fanatic Authoritarian", "Fanatic Pacifist", "Fanatic Xenophile", "Fanatic Cooperative", "Fanatic Pluralist", "Fanatic Spiritualist", "Fanatic Ecocentric",
"Libertarian", "Militarist", "Xenophobe", "Competitive", "Elitist", "Materialist", "Anthropocentric", "Authoritarian", "Pacifist", "Xenophile", "Cooperative",
"Pluralist", "Spiritualist", "Ecocentric" };

string gameGestaltEthics[] = { "Progression", "Analysis", "Encroachment", "Connection", "Convalescence", "Logistics",
"Impassive", "Introspective", "Autonomous", "Affective", "Extrospective", "Convergent"
};

int temp;

string GameRules::randomGovernmentType(int race)
{
	if (race == 1)
	{
		temp = 1;
	}
	else if (rand() % 100 + 1 <= 10)
	{
		temp = 2;
	}
	else
	{
		temp = 0;
	}
	string awnser = governmentTypes[temp];
	return awnser;

}
int GameRules::getGovernmentType()
{
	return temp;
}
string GameRules::randomGovernmentEthics(int type)
{
	string GameRules::randomTrait(int type)
	{
		int i = 0;
		int fnatic = 0;
		int normal = 0;
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
	}
}
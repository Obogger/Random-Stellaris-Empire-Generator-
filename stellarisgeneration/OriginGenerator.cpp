#include"GameRules.h"


string originRestrictions[] = { ":", "G+050+:", "G-:", "M-:", "M-:", ":", ":", "G-:", "G-2-:", ":", "H+:", "G-:", "L+:", "M+:", "G-020-:", "G-020-", ":", "G-:", "M-090-00-", "G-:" };
int gameTypeOrigin[500] = { 95 };

int amount;

int GameRules::randomOrigin(int government, int type, int race)
{
	int awnser = rand() % 20;
	bool isGestalt = government;
	int gameset = gameTypeOrigin[type - 1];
	amount = gameset;
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
							awnser = rand() % gameset;
							awnser = rand() % 20;
						}
					}
					else if (excep == 'M')
					{
						if (race != 1)
						{
							c = -1;
							awnser = rand() % gameset;
							awnser = rand() % 20;
						}
					}
					else if (excep == 'H')
					{
						if (government != 2)
						{
							c = -1;
							awnser = rand() % gameset;
							awnser = rand() % 20;
						}
					}
					else if (excep == 'L')
					{
						if (race != 9)
						{
							c = -1;
							awnser = rand() % gameset;
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
							awnser = rand() % gameset;
							awnser = rand() % 20;
						}
					}
					else if (excep == 'M')
					{
						if (government == 1)
						{
							c = -1;
							awnser = rand() % gameset;
							awnser = rand() % 20;
						}
					}
					else if (excep == 'H')
					{
						if (government == 2)
						{
							c = -1;
							awnser = rand() % gameset;
							awnser = rand() % 20;
						}
					}
					else if (excep == 'L')
					{
						if (race == 9)
						{
							c = -1;
							awnser = rand() % gameset;
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
int GameRules::getOriginSelectionAmount()
{
	return amount;
}
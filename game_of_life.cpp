#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "game_of_life.h"
using namespace std;


bool game_of_life::slucajna_vrijednost()
{
	return rand() % 4 == 0;
	
}



void game_of_life::popunjavanje()
{
	
	for (int i = 0; i < REDAKA; ++i)
	{
		for (int j = 0; j < STUPACA; ++j)
		{
			_generacija[i][j] = slucajna_vrijednost();
			if (_generacija[i][j] == 0)
			{
				_generacija[i][j] = '-';
			}
			else if (_generacija[i][j] == 1)
			{
				_generacija[i][j] = '*';
			}
		}
	}
}

game_of_life::game_of_life()
{
	popunjavanje();
}

void game_of_life::iscrtaj()
{
	
	for (int i = 0; i < REDAKA; ++i)
	{
		for (int j = 0; j < STUPACA; ++j)
		{
			cout << _generacija[i][j];
		}
		cout << endl;
	}
}

int game_of_life::broj_susjeda(int n, int m)
{
	int brojac_susjeda = 0;
	
			if (_generacija[n - 1][m] =='*')
			{
				brojac_susjeda++;
			}
			if (_generacija[n + 1][m] == '*')
			{
				brojac_susjeda++;
			}
			if (_generacija[n][m + 1] == '*')
			{
				brojac_susjeda++;
			}
			if (_generacija[n][m - 1] == '*')
			{
				brojac_susjeda++;
			}
			if (_generacija[n - 1][m - 1] == '*')
			{
				brojac_susjeda++;
			}
			if (_generacija[n + 1][m - 1] == '*')
			{
				brojac_susjeda++;
			}
			if (_generacija[n - 1][m + 1] == '*')
			{
				brojac_susjeda++;
			}
			if (_generacija[n + 1][m + 1] == '*')
			{
				brojac_susjeda++;
			}
			
	

			return brojac_susjeda;
}

void game_of_life::sljedeca_generacija()
{

	for (int i = 0; i < REDAKA; ++i)
	{
		for (int j = 0; j < STUPACA; ++j)
		{
			_sljedeca_generacija[i][j] = broj_susjeda(i, j);
			
		}
	}


	for (int i = 0; i < REDAKA; ++i)
	{
		for (int j = 0; j < STUPACA; ++j)
		{
			

			if (_generacija[i][j] == '*')
			{
				if (_sljedeca_generacija[i][j] == 2 || _sljedeca_generacija[i][j] == 3)
				{
					_generacija[i][j] = '*';
				}
				else if (_sljedeca_generacija[i][j] < 2 || _sljedeca_generacija[i][j] > 3)
				{
					_generacija[i][j] = '-';
				}
			}
			else if (_generacija[i][j] == '-')
			{
				if (_sljedeca_generacija[i][j] == 3)
				{
					_generacija[i][j] = '*';
				}
				else
					_generacija[i][j] = '-';
			}
			
		}
		
	}
}



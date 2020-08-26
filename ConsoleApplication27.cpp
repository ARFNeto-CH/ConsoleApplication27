// ConsoleApplication27.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <filesystem>
#include <iostream>
#include <iomanip>
#include <map>

#include "Pasta.h"

using namespace std;
using namespace std::filesystem;

int main()
{
	//string origem = "C:\\Users\\toninho\\source\\repos\\teste_val";
	string origem = "C:\\Users\\toninho\\source\\repos";
	Pasta repos(origem);

	cout << "final: mapa com " << repos.M.size()
		<< " entradas" << endl;
	//repos.apaga_recursivo("a", origem, true);
	for (auto m : repos.M)
	{
		//cout << m.first << endl;
		cout << setw(20) << m.second.nome << ":\t" << 
			setfill(' ') << setw(14) << 
			(m.second.bytes_abaixo + m.second.bytes_aqui) <<
			endl;
	};
	return 0;
}
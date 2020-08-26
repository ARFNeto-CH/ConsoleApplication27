#pragma once
#include <cstdint>
#include <filesystem>
#include <iostream>
#include <map>

#include "Resumo.h"

using namespace std;
using namespace std::filesystem;

class Pasta
{
private:
	path		raiz;
	Resumo		stat;

public:
	map<path, Resumo> M;

public:
	Pasta(const path&);
	Pasta()
	{ 
		Pasta("/");
	};

	Resumo	processa_pasta(path);
	int		apaga_recursivo(string pasta, path origem, bool todas);

public:
	int status()
	{
		return 0;
	};
};


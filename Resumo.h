#pragma once
#include <cstdint>
#include <filesystem>
#include <iostream>
using namespace std;

class Resumo
{
public:
	string		nome;
	string		path;

	uint64_t	bytes_aqui;
	uint64_t	pastas_aqui;
	uint64_t	arquivos_aqui;

	uint64_t	bytes_abaixo;
	uint64_t	pastas_abaixo;
	uint64_t	arquivos_abaixo;

	uint64_t	gatilho; // tamanho
	uint64_t	bytesAcima; // tamanho
	uint64_t	arquivosAcima; // tamanho

	Resumo() : bytes_aqui(0), pastas_aqui(0),
		arquivos_aqui(), gatilho(1),
		bytes_abaixo(0), pastas_abaixo(0),
		arquivos_abaixo(0),
		bytesAcima(0), arquivosAcima(0) {};

	Resumo(uint64_t G) : bytes_aqui(0), pastas_aqui(0),
		arquivos_aqui(), gatilho(G),
		bytes_abaixo(0), pastas_abaixo(0),
		arquivos_abaixo(0),
		bytesAcima(0), arquivosAcima(0) {};

	Resumo operator+ (const Resumo& outro);
	Resumo operator^ (const Resumo& outro);

	int mostra(string msg);
};


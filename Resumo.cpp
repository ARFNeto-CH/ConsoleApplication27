#include "Resumo.h"

int Resumo::mostra(string msg)
{
	cout << "\n\n= = = = = = = = = = = = = = = = = = = =\n\n";
	cout << "\tmostra(" << msg << ")\n" << endl;

	cout << "\t" << nome << endl;
	cout << "\t" << path << endl;

	cout << "\n= = = = = = = = = = = = = = = = = = = =\n";
	// resumo da pasta
	cout << "\tTamanho:\t" << bytes_aqui / (1024 * 1024) << " MB (" <<
		bytes_aqui << " bytes)" << endl;
	cout << "\tContem: \t" <<
		arquivos_aqui << " arquivos,";
	cout << pastas_aqui << " pastas" << endl;
	// resmo das sub pastas
	cout << "\nNos sub-diretorios\n" << endl;

	cout << "\tTamanho:\t" << bytes_abaixo / (1024 * 1024)
		<< " MB (" << bytes_abaixo << " bytes)" << endl;
	cout << "\tContem: \t" <<
		arquivos_abaixo << " arquivos,";
	cout << pastas_abaixo << " pastas" << endl;
	// total geral
	cout << "\nTotal geral para a pasta e sub-pastas\n" << endl;

	cout << "\tTamanho:\t" << (bytes_abaixo + bytes_aqui) / (1024 * 1024)
		<< " MB (" << (bytes_abaixo + bytes_aqui) << " bytes)" << endl;

	cout << "\tContem: \t" <<
		(arquivos_abaixo + arquivos_aqui) << " arquivos, + ";
	cout << (pastas_abaixo + pastas_aqui) << " pastas" << endl;

	cout << "\nTotal de arquivos com tamanho > " <<
		gatilho << " MB\n" << endl;

	cout << "\tTamanho:\t" << bytesAcima / (1024 * 1024) << " MB (" <<
		bytesAcima << " bytes)" << endl;
	cout << "\tEm:     \t" <<
		arquivosAcima << " arquivos" << endl;

	return 0;
};

Resumo Resumo::operator+(const Resumo& outro)
{
    bytes_aqui += outro.bytes_aqui;
    pastas_aqui += outro.pastas_aqui;
    bytes_abaixo += outro.bytes_abaixo;
    pastas_abaixo += outro.pastas_abaixo;
    gatilho = outro.gatilho;
    bytesAcima += outro.bytesAcima;
    arquivosAcima += outro.arquivosAcima;
    return *this;
}; // +

Resumo Resumo::operator^(const Resumo& sub_dir)
{
    // essa operacao inclui os subtotais da pasta
    bytes_abaixo += sub_dir.bytes_aqui + sub_dir.bytes_abaixo;
    pastas_abaixo += sub_dir.pastas_aqui + sub_dir.pastas_abaixo;
    arquivos_abaixo += sub_dir.arquivos_aqui + sub_dir.arquivos_abaixo;
    bytesAcima += sub_dir.bytesAcima;
    arquivosAcima += sub_dir.arquivosAcima;
    return *this;
}

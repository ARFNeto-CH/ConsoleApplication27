#include <string.h>
#include "Pasta.h"

using namespace std;

Pasta::Pasta(const path& origem)
{
	path p = origem;
	cout << "Construindo " << p << endl;
	if (exists(p)) raiz = p;
	if (is_directory(p))
	{
		cout << "progresso:\n";
		M[p] = processa_pasta(p);
		cout << endl;
		M[p].mostra(p.string());
	};
}

int Pasta::apaga_recursivo(string pasta, path origem, bool todas)
{
	// a partir da origem apaga 'pasta' e seu conteudo
	// recursivamente. Se 'todas' for verdade apaga 
	// todas as pastas a partir de origem ao inves
	// de parar na primeira
	Resumo R(3);
	cout << "\n\n\n==> apaga_recursivo(\"" << 
		pasta << "\") a partir de " <<
		origem << " recursivo: " << todas << endl;
	if (empty(origem))
	{
		cout << origem << " vazia" << endl;
		return 0;
	};
	for (const directory_entry& f : directory_iterator{ origem })
	{
		//cout << ".";
		if (is_regular_file(f.path()))
		{
			uint64_t size = file_size(f.path());
			//cout << "F     " << f.path() << " com " <<
			//	size << " bytes" << endl;
			R.bytes_aqui += size;
			R.arquivos_aqui += 1;
			if (size > (R.gatilho * 1024 * 1024))
			{
				R.arquivosAcima += 1;
				R.bytesAcima += size;
			};
		}
		else
		{
			//cout << "D";
			R.pastas_aqui += 1;
			char arquivo[400];
			string nome = f.path().string();
			size_t i = nome.length() - 1;
			for (; nome[i] != '\\'; i -= 1) {};
			nome.copy(arquivo, nome.length() - i, i + 1);
			arquivo[nome.length() - i - 1] = 0;
			if (arquivo == pasta)
			{
				cout << "\n\t==> pasta localizada em " <<
					f.path() << endl;
				if (!todas) break;
			}
			else
			{
				apaga_recursivo(pasta, f.path(), todas);
			};
			//cout << "D ==> '" << arquivo << "'" << endl;
			//R = R ^ processa_pasta(f.path());
		};	// if()
	};	// for()
	//cout << "processa_pasta(): " << p << endl;
	//R.mostra(origem.string());
	//char chint;
	//cout << " Confira o resumo e Tecle algo "; cin >> chint;
	return 0;
};	 

Resumo Pasta::processa_pasta(path p)
{
	Resumo R;
	size_t i = p.string().length() - 1;
	for (; i >= 0; i -= 1)
		if (p.string()[i] == '\\') break;
	size_t t = p.string().length() - 1 - i;
	char arquivo[512];
	p.string().copy(arquivo, t, i + 1);
	arquivo[t] = 0;
	R.nome = arquivo;
	R.path = p.string();
	//cout << "\n\n\n==> processa_pasta(" << p << ")\n" << endl;

	for (const directory_entry& f : directory_iterator{ p })
	{

		if (is_regular_file(f.path()))
		{
			cout << ".";
			uint64_t size = file_size(f.path());
			//cout << "F     " << f.path() << " com " <<
			//	size << " bytes" << endl;
			R.bytes_aqui += size;
			R.arquivos_aqui += 1;
			if (size > (R.gatilho * 1024 * 1024))
			{
				R.arquivosAcima += 1;
				R.bytesAcima += size;
			};
		}
		else
		{
			cout << "D";
			R.pastas_aqui += 1;
			R = R ^ processa_pasta(f.path());
		};	// if()
	};	// for()
	M[p] = R;
	return R;
};	// processa_pasta()

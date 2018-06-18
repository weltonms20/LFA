#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main ()
{
	int qtdEstados;
	int qtdTransicoes;
	int qtdSimbolos;
	int qtdEstadosFinais;

	int estado1;
	int estado2;
	char leitura;
	ifstream myfile;
	string str;
	myfile.open ("automato.txt");


	vector< vector<char> > aux;
	vector<char> aux2 (4,'\0');

	vector<char> alfabeto;
	vector<int> estadosFinais;

	vector<vector< vector<char> >> AFN;
	vector<vector< vector<char> >> AFD; // afd tem 7 possibilidades de estados no máximo, mas pragarantir a gente lê os estados e calcula esse máximo



	for (int i = 0; i < 4; ++i)
	{
		aux.push_back(aux2);
		cout << "ok " << i << endl;
	}
	for (int i = 0; i < 4; ++i)
	{
		AFN.push_back(aux);
		cout << "ok " << i << endl;
	}
	
	for (int i = 0; i < 7; ++i)
	{
		AFD.push_back(aux);
		cout << "ok " << i << endl;
	}


	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				//cout << " " << AFD.at(i).at(j).at(k) << endl;
			}
		}
	}




	if (myfile.is_open() && myfile.good())
    {
        myfile >> str;
        qtdEstados = str.at(0)-'0';
        myfile >> str;
        qtdTransicoes = str.at(0)-'0';
        myfile >> str;
        qtdSimbolos = str.at(0)-'0';
        myfile >> str;
        qtdEstadosFinais = str.at(0)-'0';

		cout << " estados : " << qtdEstados << " - transicoes " << qtdTransicoes << " - simbolos: " << qtdSimbolos << " estados finais  " << qtdEstadosFinais << endl; 

		for (int i = 0; i < qtdSimbolos; ++i)
		{
			myfile >> str;
			alfabeto.push_back(str.at(0));
			cout << alfabeto.at(i);
		}
			cout << endl;
        for (int i = 0; i < qtdTransicoes; ++i)
        {
        	myfile >> str;
        	estado1 = str.at(0)-'0';
        	myfile >> str;
        	leitura = str.at(0);
        	myfile >> str;
        	estado2 = str.at(0)-'0';

        	cout << "oi\0";
			AFN.at(estado1).at(leitura-97).push_back(estado2);
			cout << " " << estado1 << " > " << estado2 << " - lendo: " << leitura << endl; 
        }

        for (int i = 0; i < qtdEstadosFinais; ++i)
        {
        	myfile >> str;
        	estadosFinais.push_back(str.at(0)-'0');
        	cout << "estado final : " << estadosFinais.at(i) << endl;
        }
	}

	cout << "ok" << endl;
	myfile.close();	
	return 0;
}
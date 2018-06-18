#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main ()
{
	int qtdEstados; // qtd = quantidade
	int qtdTransicoes;
	int qtdSimbolos;
	int qtdEstadosFinais;

	int estado1; // estado partida
	int estado2; // estado destino 
	char leitura; // usado para guardar a leitura
	ifstream myfile; // arquivo
	string str; // usado para ler o arquivo
	myfile.open ("automato.txt");


	vector< vector<char> > aux; // cada linha da matriz
	vector<char> aux2; // cada estado é um vetor, pra poder guardar direito

	vector<char> alfabeto; // guarda os simbolos
	vector<int> estadosFinais;// guarda os estados finais

	vector<vector< vector<char> >> AFN;
	vector<vector< vector<char> >> AFD; // afd tem 7 possibilidades de estados no máximo, mas pragarantir a gente lê os estados e calcula esse máximo


//

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

		for (int i = 0; i < qtdSimbolos; ++i) // alocar espaco pra botar os estados destino de acordo com a quantidade de simbolos
		{
			aux.push_back(aux2);
		}
		for (int i = 0; i < qtdEstados; ++i) // alocar cada linha de estados
		{
			AFN.push_back(aux);
		}



		// lendo simbolos do alfabeto
		for (int i = 0; i < qtdSimbolos; ++i)
		{
			myfile >> str;
			alfabeto.push_back(str.at(0));
			cout << alfabeto.at(i);
		}
			cout << endl;

		// lendo as trnaisções e guardando na AFN
        for (int i = 0; i < qtdTransicoes; ++i)
        {
        	myfile >> str;
        	estado1 = str.at(0)-'0';
        	myfile >> str;
        	leitura = str.at(0);
        	myfile >> str;
        	estado2 = str.at(0)-'0';

        	cout << "oi\0";
			AFN.at(estado1).at(leitura-97).push_back(str.at(0));
			cout << " " << estado1 << " > " << estado2 << " - lendo: " << leitura << endl; 
        }

        //lendo os estados finais
        for (int i = 0; i < qtdEstadosFinais; ++i)
        {
        	myfile >> str;
        	estadosFinais.push_back(str.at(0)-'0');
        	cout << "estado final : " << estadosFinais.at(i) << endl;
        }

        // imprimindo a AFN lida 
        for (int i = 0; i < AFN.size(); ++i)
        {
        	for (int j = 0; j < AFN.at(i).size(); ++j)
        	{
        		for (int k = 0; k < AFN.at(i).at(j).size(); ++k)
        		{
        			cout << "estado1 : " << i << " estado2 " << AFN.at(i).at(j).at(k) << " lendo = " << (char)(j+97) << endl;
        		}
        	}
        }
	}

	cout << "ok" << endl;
	myfile.close();	
	return 0;
}
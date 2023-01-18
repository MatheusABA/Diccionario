/*
Aluno: MATHEUS ALEXANDRE	-	RA 181441
*/


#include <bits/stdc++.h>
using namespace std;

// Estrutura da Trie
struct Trie {
	bool fimPalavra;
	unordered_map<char, Trie*> map;	
	string significado;
};

// Fun��o para criar um novo n�
Trie* getNewTrieNode()
{
	Trie* node = new Trie;
	node->fimPalavra = false;
	return node;
}

// Fun��o para inserir palavra junto do seu significado dentro da trie
void inserePalavra(Trie*& raiz, const string& palavra,
			const string& significado)
{

	// Se a raiz � nula
	if (raiz == NULL)
		raiz = getNewTrieNode();

	Trie* temp = raiz;
	for (int i = 0; i < palavra.length(); i++) {
		char x = palavra[i];

		// Cria um novo n� se o caminho n�o existe
		if (temp->map.find(x) == temp->map.end())
			temp->map[x] = getNewTrieNode();

		temp = temp->map[x];
	}

	// Ap�s a �ltima letra, marca fim da palavra e adiciona seu significado
	temp->fimPalavra = true;
	temp->significado = significado;
}

// Fun��o para buscar uma palavra, e se ela existir, mostrar seu significado
string pegaSignificado(Trie* raiz, const string& palavra)
{

	// Se a raiz � nula, o dicionario est� vazio
	if (raiz == NULL)
		return "";

	Trie* temp = raiz;

	// Busca a palavra informada dentro da trie
	for (int i = 0; i < palavra.length(); i++) {
		temp = temp->map[palavra[i]];
		if (temp == NULL)
			return "Palavra nao existe dentro do dicionario";
	}

	// Se fimPalavra for valido da palavra requerida
	// for v�lida com uma j� armazenada dentro da trie, o significado dela �
	// mostrado na tela
	
	if (temp->fimPalavra)
		return temp->significado;
	return "";
}

// Main do c�digo para armazenar/buscar palavra
int main()
{
    // Iniciando com raiz nula
	Trie* raiz = NULL;

    // Construindo dicionario
	inserePalavra(raiz, "sol", "a estrela central do Sistema Solar.");
	
	
	inserePalavra(raiz, "churrasco", "prato feito � base de carne in natura ou processada, assada sobre o fogo ou brasas.");


	inserePalavra(raiz, "piano", "instrumento musical de cordas percussivas.");


	inserePalavra(raiz, "futebol", "esporte de equipe jogado entre dois times de 11 jogadores cada um e um �rbitro.");


	inserePalavra(raiz, "computador", "conjunto de componentes eletr�nicos (m�quina) capaz de executar variados tipos de algoritmos e tratamento de informa��es.");


    // Palavra a ser pesquisada
	string str = "jogo";
	cout << "Significado da palavra "<< str << " : "<< pegaSignificado(raiz, str);

	return 0;
}
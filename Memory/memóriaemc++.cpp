#include <iostream>
#include <cstdlib>
#include <ctime>

// Grupo: Paulo Henrique Hansaul Jorge, Pedro Pradi, Emerson Chow
//
// 				                 -- Observações --
//
// * O uso do loop do while mantém uma estética lógica mais firme ao código, um exemplo disto
// é o fato de que o void embaralha, responsável pela indexação dos valores às cartas, é executado
// antes mesmo da construção visual do tabuleiro;
//
// * Até hoje (25/04) o item a) do TDE -- onde requisitava que fosse possível o usuário entrar
// com o tamanho do tabuleiro e este ser gerado de maneira dinâmica -- não consta no trabalho,
// será apresentado ao professor Alceu e requisitado seu auxílio para o desenvolvimento de tal
// funcionalidade.

using namespace std;
int main()
{
	char virgula, resp = 'y'; // char vírgula é um fix
	int r1, c1, r2, c2, cartas[4][4], i(0); // r e c correspondem as linhas e colunas, coordenadas das cartas
	bool selecionadacarta[4][4];  // A escolha do vetor como bool mantém um padrão, o selecionadacarta define se a carta foi encontrada ou não
	bool gameover = false; // enquanto for true, jogo continua, quando for false, termina
	int jogadas; // contador
	do
	{

		void embaralha(int[][4]);

		jogadas = 0; // Reseta o contador de jogadas
		embaralha(cartas); 	// Chama o método de embaralhar cartas

		// Início do design do indicador de colunas //
		cout << "    1 2 3 4\n"; // Imprime a numeração das colunas
		cout << "  "; // Ajuste na separação da numeração
		for (int i = 0; i <= 8; i++)
		{
			cout << "-"; // Design da divisória
		}
		cout << endl; // endl insere nova linha

	    // Fim do design do indicador de colunas //

		// Início do design do indicador de linhas //
		for (int r = 0; r<4; r++)
		{
			cout << r + 1 << " | "; // Imprime a numeração das linhas
			for (int c = 0; c<4; c++)
			{
				cout << "* "; // Imprime as cartas não reveladas
				selecionadacarta[r][c] = false; // Já prepara um outro array com cada posição do tabuleiro
			}
			cout << endl;
		}
		// Fim do design do indicador de linhas //

		cout << endl;

		do
		{
			do
			{
				cout << "Insira a linha,coluna da primeira carta desejada. \n";
				cin >> r1 >> virgula >> c1;
				if (selecionadacarta[r1 - 1][c1 - 1] == true) // Verifica se a carta está virada
				{
					cout << "Esta carta ja esta virada! Selecione outra! \n";
				}
			} while (selecionadacarta[r1 - 1][c1 - 1] != false);
			do
			{
				cout << "Insira a lina,coluna da segunda carta desejada. \n";
				cin >> r2 >> virgula >> c2;
				if (selecionadacarta[r2 - 1][c2 - 1] == true)
				{
					cout << "Esta carta ja esta virada! Selecione outra! \n";
				}
				if ((r1 == r2) && (c1 == c2))
				{
					cout << "Voce nao pode virar a mesma carta novamente!";
					continue;
				}
			} while (selecionadacarta[r2 - 1][c2 - 1] != false);
			
			r1--;
			c1--;
			r2--;
			c2--;

			// Início da repetição do design com a(s) carta(s) encontrada(s) //
			cout << "    1 2 3 4\n";
			cout << "  ";
			for (int i = 0; i <= 8; i++)
			{
				cout << "-";
			}
			cout << endl;

			for (int r = 0; r<4; r++)
			{
				cout << r + 1 << " | ";
				for (int c = 0; c<4; c++)
				{
					if ((r == r1) && (c == c1))
					{
						cout << cartas[r][c] << " "; // Se encontrou, imprime a primeira
					}
					else if ((r == r2) && (c == c2))
					{
						cout << cartas[r][c] << " "; // Se encontrou, imprime a segunda
					}
					else if (selecionadacarta[r][c] == true)
					{
						cout << cartas[r][c] << " ";
					}
					else
					{
						cout << "* "; // Nada? Mantém igual
					}
				}
				cout << endl;
			}
			// Fim da repetição do design com a(s) carta(s) encontrada(s)//

			//Faz a verificação se o par foi encontrado ou não
			if (cartas[r1][c1] == cartas[r2][c2])
			{
				cout << "Par Encontrado! Pressione ENTER" << endl;

				selecionadacarta[r1][c1] = true; //Carta 1 do par
				selecionadacarta[r2][c2] = true; //Carta 2 do par
			}else{
				cout << "Nao forma um par! Tente novamente";
			}
			cin.get();
	
			//Finaliza a primeira tentativa
			
			// Da um espaço de 5 linhas
			for (int i = 0; i<5; i++){
				cout << endl;
			}
			
	
			// Início da repetição do design //
			cout << "    1 2 3 4\n";
			cout << endl;
			for (int r = 0; r<4; r++)
			{
				cout << r + 1 << " | ";
				for (int c = 0; c<4; c++)
				{
					if (selecionadacarta[r][c] == true)
					{
						cout << cartas[r][c] << " ";
					}
					else
					{
						cout << "* ";
					}
				}
				cout << endl;
			}
			// Fim da repetição do design //
			
			gameover = true; // Mantém o jogo rodando, quando for false o jogo termina
			
			// Faz a verificação se todas as 16 cartas foram descobertas
			for (int r = 0; r<4; r++)
			{
				for (int c = 0; c<4; c++)
				{
					if (selecionadacarta[r][c] == false)
					{
						gameover = false; // Termina o jogo
						break;
					}
				}
				if (gameover == false)
				{
					break;
				}
			}
			
			jogadas++; // Contador de jogadas
			
			 // DAQUI PRA FRENTE, REPETE //
			 
		} while (gameover != true); // Aqui define-se o loop até que o jogo acabe
		cout << "Voce ganhou!!!" << endl;
		cout << jogadas << " jogadas ate a vitoria." << endl << endl;
		cout << "Jogar novamente? (s=Sim/n=Nao) : ";
		resp = cin.get();
	} while (resp == 's' || resp == 'S'); // Verifica se o jogador quer jogar novamente
	cin.get();
	return 0;
}
void embaralha(int carta[][4]) // Embaralha as cartas, atribuindo valores ao tabuleiro de forma aleatória, mas mantendo pores.
{
	int start[16] = { 1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8 }; // Montagem do array fixo do tabuleiro
	for (int s = 0; s <= 20; s++) // Loop pelos possíveis pares
	{
		for (int x = 0; x<16; x++)
		{
			srand((unsigned)time(NULL));
			int i = rand() % 15 + 1; // Define i aleatório
			int temp = start[x]; 
			start[x] = start[i]; // troca
			start[i] = temp; // segura o valor da carta em si
		}
	}
	int i = 0;
	for (int r = 0; r<4; r++) // Este loop define o valor para a carta
	{
		for (int c = 0; c<4; c++)
		{
			carta[r][c] = start[i]; // 
			//cout << cards[r][c]; <-- Tirar o comentário para imprimir todas as cartas do tabuleiro antes do tabuleiro em si!
			i = i + 1;
		}
		cout << endl;
	}
}





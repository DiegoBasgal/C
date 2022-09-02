#include <iostream>
#include <cstdlib>
#include <ctime>

// Grupo: Paulo Henrique Hansaul Jorge, Pedro Pradi, Emerson Chow
//
// 				                 -- Observa��es --
//
// * O uso do loop do while mant�m uma est�tica l�gica mais firme ao c�digo, um exemplo disto
// � o fato de que o void embaralha, respons�vel pela indexa��o dos valores �s cartas, � executado
// antes mesmo da constru��o visual do tabuleiro;
//
// * At� hoje (25/04) o item a) do TDE -- onde requisitava que fosse poss�vel o usu�rio entrar
// com o tamanho do tabuleiro e este ser gerado de maneira din�mica -- n�o consta no trabalho,
// ser� apresentado ao professor Alceu e requisitado seu aux�lio para o desenvolvimento de tal
// funcionalidade.

using namespace std;
int main()
{
	char virgula, resp = 'y'; // char v�rgula � um fix
	int r1, c1, r2, c2, cartas[4][4], i(0); // r e c correspondem as linhas e colunas, coordenadas das cartas
	bool selecionadacarta[4][4];  // A escolha do vetor como bool mant�m um padr�o, o selecionadacarta define se a carta foi encontrada ou n�o
	bool gameover = false; // enquanto for true, jogo continua, quando for false, termina
	int jogadas; // contador
	do
	{

		void embaralha(int[][4]);

		jogadas = 0; // Reseta o contador de jogadas
		embaralha(cartas); 	// Chama o m�todo de embaralhar cartas

		// In�cio do design do indicador de colunas //
		cout << "    1 2 3 4\n"; // Imprime a numera��o das colunas
		cout << "  "; // Ajuste na separa��o da numera��o
		for (int i = 0; i <= 8; i++)
		{
			cout << "-"; // Design da divis�ria
		}
		cout << endl; // endl insere nova linha

	    // Fim do design do indicador de colunas //

		// In�cio do design do indicador de linhas //
		for (int r = 0; r<4; r++)
		{
			cout << r + 1 << " | "; // Imprime a numera��o das linhas
			for (int c = 0; c<4; c++)
			{
				cout << "* "; // Imprime as cartas n�o reveladas
				selecionadacarta[r][c] = false; // J� prepara um outro array com cada posi��o do tabuleiro
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
				if (selecionadacarta[r1 - 1][c1 - 1] == true) // Verifica se a carta est� virada
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

			// In�cio da repeti��o do design com a(s) carta(s) encontrada(s) //
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
						cout << "* "; // Nada? Mant�m igual
					}
				}
				cout << endl;
			}
			// Fim da repeti��o do design com a(s) carta(s) encontrada(s)//

			//Faz a verifica��o se o par foi encontrado ou n�o
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
			
			// Da um espa�o de 5 linhas
			for (int i = 0; i<5; i++){
				cout << endl;
			}
			
	
			// In�cio da repeti��o do design //
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
			// Fim da repeti��o do design //
			
			gameover = true; // Mant�m o jogo rodando, quando for false o jogo termina
			
			// Faz a verifica��o se todas as 16 cartas foram descobertas
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
			 
		} while (gameover != true); // Aqui define-se o loop at� que o jogo acabe
		cout << "Voce ganhou!!!" << endl;
		cout << jogadas << " jogadas ate a vitoria." << endl << endl;
		cout << "Jogar novamente? (s=Sim/n=Nao) : ";
		resp = cin.get();
	} while (resp == 's' || resp == 'S'); // Verifica se o jogador quer jogar novamente
	cin.get();
	return 0;
}
void embaralha(int carta[][4]) // Embaralha as cartas, atribuindo valores ao tabuleiro de forma aleat�ria, mas mantendo pores.
{
	int start[16] = { 1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8 }; // Montagem do array fixo do tabuleiro
	for (int s = 0; s <= 20; s++) // Loop pelos poss�veis pares
	{
		for (int x = 0; x<16; x++)
		{
			srand((unsigned)time(NULL));
			int i = rand() % 15 + 1; // Define i aleat�rio
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
			//cout << cards[r][c]; <-- Tirar o coment�rio para imprimir todas as cartas do tabuleiro antes do tabuleiro em si!
			i = i + 1;
		}
		cout << endl;
	}
}





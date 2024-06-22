#include <iostream>
#include <vector>

#define MAX 1000

using namespace std;

// Estrutura para representar uma direção
struct Dir
{
    int row, col;
};

// Função para inicializar o labirinto
void setLab(int lab[MAX][MAX], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // Apenas um exemplo, você deve preencher o labirinto de acordo com o problema
            lab[i][j] = 0; // 0 representa caminho livre e 1 representa parede
        }
    }
    // Aqui devemos garantir que há um corredor horizontal na última linha
    for (int j = 0; j < col; j++)
    {
        lab[row - 1][j] = 0;
    }
}

// Função que simula o movimento do robô
int play(int lab[4][4], int count[MAX], int row, int col)
{
    // Direções: esquerda, cima, direita, baixo
    Dir directions[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int k = -1;
    int currDir = 0; // Começamos indo para a esquerda
    int currRow = row - 1;
    int currCol = col - 1;

    while (true)
    {
        int steps = 0;
        // Movendo-se na direção atual até encontrar uma parede
        while (true)
        {
            int nextRow = currRow + directions[currDir].row;
            int nextCol = currCol + directions[currDir].col;
            if (lab[nextRow][nextCol] == 1)
            {
                break; // Encontrou uma parede ou chegou na borda do labirinto
            }
            currRow = nextRow;
            currCol = nextCol;
            steps++;
        }
        k++;
        count[k] = steps;

        // Tentativa de virar 90 graus à direita
        currDir = (currDir + 1) % 4;
        int nextRow = currRow + directions[currDir].row;
        int nextCol = currCol + directions[currDir].col;
        if (lab[nextRow][nextCol] == 1)
        {
            break; // Não pode virar, então terminou
        }
    }

    return k;
}

int myPlay(int lab[7][7], int count[MAX], int row, int col)
{

    Dir direction[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int currDir = 0;
    int currRow = row - 1;
    int currCol = col - 1;
    int nextRow;
    int nextCol;
    int k = -1;
    while (true)
    {
        int steps = 0;
        while (true)
        {
            int nextRow = currRow + direction[currDir].row;
            int nextCol = currCol + direction[currDir].col;
            if (lab[nextRow][nextCol] == 1)
            {
                break;
            }
            currRow = nextRow;
            currCol = nextCol;
            steps++;

        }
        k++;
        count[k] = steps;
        currDir = (currDir + 1) % 4;
        nextRow = currRow + direction[currDir].row;
        nextCol = currCol + direction[currDir].col;
        if (lab[nextRow][nextCol] == 1)
        {
            break;
        }

    }

    return k;
}

int main()
{
    int row = 7, col = 7;
    int lab[7][7] = {{1, 1, 1, 1, 1, 1, 1}, {1, 1, 0, 0, 0, 0, 1}, {1, 1, 0, 1, 1, 0, 1}, {1, 1, 0, 1, 1, 0, 1},{1, 1, 0, 1, 0, 0, 1}, {1, 1, 0, 1, 1, 1, 1}, {1, 1, 0, 0, 0, 0, 1}};
    int count[MAX];

    // Leitura das dimensões do labirinto
    // cin >> row >> col;
    // setLab(lab, row, col);

    // Executar a simulação do robô
    int k = myPlay(lab, count, row, col);

    for (int i = 0; i <= k; i++)
    {
        cout << count[i] << " ";
    }
    cout << endl;

    return 0;
}

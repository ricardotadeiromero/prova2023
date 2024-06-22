#include <iostream>
#include <ctype.h>

using namespace std;

struct astronomic {
    int id;
    double shine;
    char colour;
};

int main() {

    struct astronomic stars[10];
    int count = 0;
    char colour;
    cout << "Quantas estrelas deseja cadastrar?" << endl;
    cin >> count;
    for(int i=0; i<count; i++){
        cout << "Informe o codigo da estrela: " << endl;
        cin >> stars[i].id;
        cout << "Informe o brilho da estrela: " << endl;
        cin >> stars[i].shine;

        cout << "Informe a cor da estrela: " << endl << "A - azul" << endl << "V - vermelho" << endl << "B - branco" << endl;
        cin >> colour;
        stars[i].colour = toupper(colour);
    }

    cout << "   CODIGO " << " | " << " BRILHO " << " | " << " COR " << endl;
    for(int i=0; i<count; i++){
        cout << i+1 << " " << stars[i].id << " " << stars[i].shine << " " << stars[i].colour << endl;
    }


    return 0;
}
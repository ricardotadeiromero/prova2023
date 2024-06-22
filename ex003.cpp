#include <iostream>
#define MAX 1000
using namespace std;

int main() {
    int array[MAX], odds[MAX];
    int len = -1, lenOdd = -1, odd = 0;
    do {
        len++;
        cin >> array[len];
    } while (array[len]);

    for (int i = 0; i < len; i++) {
        if (array[i] % 2 != 0) {
            odd++;
            if ((i > 0 && array[i - 1] % 2 != 0) ||
                (i < len - 1 && array[i + 1] % 2 != 0)) {
                lenOdd++;
                odds[lenOdd] = array[i];
            }
        }
    }

    cout << "Quantidade de numeros impares: " << odd << endl;
    for (int i = 0; i <= lenOdd; i++) {
        cout << odds[i] << " ";
    }

    return 0;
}
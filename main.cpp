#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> calcularFuncionFallo(const string& cadena) {
    int n = cadena.length();
    vector<int> f(n + 1);

    int t = 0;
    f[1] = 0;

    for (int s = 1; s < n; s++) {
        while (t > 0 && cadena[s] != cadena[t]) {
            t = f[t];
        }

        if (cadena[s] == cadena[t]) {
            t = t + 1;
            f[s + 1] = t;
        } else {
            f[s + 1] = 0;
        }
    }

    return f;
}

/* KMP:
   busca un patron dentro de un texto usando la funcion de fallo */
void KMP(const string& texto, const string& patron) {
    vector<int> f = calcularFuncionFallo(patron);

    int n = texto.length();
    int m = patron.length();

    int i = 0; // indice texto
    int j = 0; // indice patron

    while (i < n) {
        if (texto[i] == patron[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Patron encontrado en la posicion: " << i - j << endl;
            j = f[j]; // sigue buscando mas coincidencias
        }
        else if (i < n && texto[i] != patron[j]) {
            if (j > 0) {
                j = f[j];
            } else {
                i++;
            }
        }
    }
}

int main()
{string patron;
    cout << "Ingrese el patron: ";
    cin >> patron;

    vector<int> falla = calcularFuncionFallo(patron);

    cout << "Funcion de fallo:\n";
    for (int i = 1; i <= patron.length(); i++) {
        cout << falla[i] << " ";
    }
    cout << endl;

    string texto;
    cout << "\nIngrese el texto: ";
    cin >> texto;


    KMP(texto, patron);

    return 0;
}
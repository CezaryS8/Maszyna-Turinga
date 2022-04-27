// Emulator maszyny turinga dla różnicy właściwej
// Autor: Cezary Skorupski 
// 2021

#include <iostream>

using namespace std;

string generujTasma(int m, int n);
bool sigma(int qt, int wt);
void wyswietl(string x);
int obliczRoznicaW();

int q = 0;
char w = 'B';
string t;
int qi = 0;

int main()
{
    int m, n;
    cout << "\t\tEmulator maszyny Turinga\t" << endl;
    cout << " Obliczający różnicę właściwą: m-n dla m >= n, 0 dla m < n" << endl << endl;
    cout << "\t\t\tPostać MT" << endl;
    cout << " M=({q0, q1, q2, q3, q4, q5, q6}, {0,1}, {0,1,B}, δ, q0, B, 0)" << endl << endl;
    cout << " Tablica przejść (δ): " << endl;
    cout << " ---------------------------------------" << endl;
    cout << " | δ  |     0    |     1    |     B    |" << endl;
    cout << " ---------------------------------------" << endl;
    cout << " | q0 | (q1,B,P) | (q5,B,P) |     -    |" << endl;
    cout << " | q1 | (q1,0,P) | (q2,1,P) |     -    |" << endl;
    cout << " | q2 | (q3,1,L) | (q2,1,P) | (q4,B,L) |" << endl;
    cout << " | q3 | (q3,0,L) | (q3,1,L) | (q0,B,P) |" << endl;
    cout << " | q4 | (q4,0,L) | (q4,B,L) | (q6,0,P) |" << endl;
    cout << " | q5 | (q5,B,P) | (q5,B,P) | (q6,B,P) |" << endl;
    cout << " | q5 |     -    |     -    |     -    |" << endl;
    cout << " ---------------------------------------" << endl;

    cout << " Podaj m: ";
    cin >> m;
    cout << " Podaj n: ";
    cin >> n;
 
    if (m < 0 || n < 0) {
        cout << "\n Podane wartości muszą być nieujemne :(" << endl;
        return 1;
    }

    t = generujTasma(m, n);

    cout << "\n Wygenerowana taśma wejściowa: " << t << endl;

    t = 'q' + t;
    w = t[1];
   
    int st; int isFirst = 1;
    cout << "\n Ciąg opisów chwilowych MT:" << endl;
    do {
        if (isFirst)
            isFirst = 0;
        else 
            cout << " |- ";
        wyswietl(t);
        st = sigma(q, w);
    } while (st);

    cout << "\n\n Wynik (różnica właściwa) wynosi: " << obliczRoznicaW() << endl;

    if (st == 0)
        cout << "\n Wejście zostało zaakceptowane" << endl;
    else
        cout << " Wejście nie zostało zaakceptowane" << endl;

    return 0;
}

int obliczRoznicaW() {
    int len = t.size();
    int w = 0;
    for (int i = 0; i < len; i++) {
        if (t[i] == '0')
            w++;
    }
    return w;
}

void wyswietl(string x) {
    string wy = "";
    int i = x.length() - 1;
    while (x[i] == 'B')
        i--;
    for (int j = 0; j <= i; j++) {
       
        if (x[j] == 'q') {
            wy += "[";
            wy += x[j];
            wy += (q + '0');
            wy += "]";
        }
        else
            wy += x[j];

    }
    cout << wy;
}

void P() {
    qi++;
    if (qi+1 >= t.length())
        t += 'B';
  
    w = t[qi + 1];
    t[qi] = 'q';
}
void L() {
    swap(t[qi], t[qi - 1]);
    qi--;

    w = t[qi + 1]; 
}

string generujTasma(int m, int n) {
    string w = "1";
    for (int i = 0; i < m; i++)
        w = '0' + w;
    for (int i = 0; i < n; i++)
        w += '0';
    return w;
}

bool sigma(int qt, int wt) {
    switch (qt) {
        case 0:
            if (wt == '0') {
                q = 1;
                t[qi] = 'B';
                P();
                return 1;
            }
            else if (wt == '1') {
                q = 5;
                t[qi] = 'B';
                P();
                return 1;
            }
            else
                return 0;
            
            break;

        case 1:
            if (wt == '0') {
                q = 1;
                t[qi] = '0';
                P();
                return 1;
            }
            else if (wt == '1') {
                q = 2;
                t[qi] = '1';
                P();
                return 1;
            }
            else 
                return 0;
            break;

        case 2:
            if (wt == '0') {
                q = 3;
                t[qi+1] = '1';
                L();
                return 1;
            }
            else if (wt == '1') {
                q = 2;
                t[qi] = '1';
                P();
                return 1;
            }
            else {
                q = 4;
                t[qi + 1] = 'B';
                L();
                return 1;
            }
            break;

        case 3:
            if (wt == '0') {
                q = 3;
                t[qi + 1] = '0';
                L();
                return 1;
            }
            else if (wt == '1') {
                q = 3;
                t[qi + 1] = '1';
                L();
                return 1;
            }
            else {
                q = 0;
                t[qi] = 'B';
                P();
                return 1;
            }
            break;

        case 4:
            if (wt == '0') {
                q = 4;
                t[qi + 1] = '0';
                L();
                return 1;
            }
            else if (wt == '1') {
                q = 4;
                t[qi + 1] = 'B';
                L();
                return 1;
            }
            else {
                q = 6;
                t[qi] = '0';
                P();
                return 1;
            }
            break;

        case 5:
            if (wt == '0') {
                q = 5;
                t[qi] = 'B';
                P();
                return 1;
            }
            else if (wt == '1') {
                q = 5;
                t[qi] = 'B';
                P();
                return 1;
            }
            else {
                q = 6;
                t[qi] = 'B';
                P();
                return 1;
            }
            break;

        case 6:
            return 0;
            break;
    }
    return 0;

}

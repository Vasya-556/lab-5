#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void task1();
void task2();
string input(int x);
void inBit(string A, string B, int n, int k, int* bit);
void determine(string U, int* Abit, int* Bbit, int n);

int main()
{
	cout << "Task1:" << endl;
	task1();
	cout << "Task2:" << endl;
	task2();
}

void task1() {

    char A[3] = { 'a', 'b', 'c' };
    char B[3] = { 'q', 'w', 'e' };
    char C[2] = { '1', '2' };

    string D[18];

    int j = 0;

    for (int ia = 0; ia < 3; ia++)
    {
        for (int ic = 0; ic < 2; ic++) 
        {
            for (int ib = 0; ib < 3; ib++) 
            {
                D[j] = "";
                D[j] += A[ia];
                D[j] += C[ic];
                D[j] += B[ib];
                j++;
            }
        }
    }

    for (int i = 0; i < 18; i++)
    {
        cout << D[i] << "\t";
    }
    cout << endl;
}

void task2() {
    int n, ka, kb;
    string U, A, B;
    cout << "Enter n: "; cin >> n;
    cout << "Enter ka: "; cin >> ka;
    cout << "Enter kb: "; cin >> kb;
    cout << "Enter U: ";
    U = input(n);
    cout << "Enter A: ";
    A = input(ka);
    cout << "Enter B: ";
    B = input(kb);
    int Abit[100];
    int Bbit[100];

    sort(U.begin(), U.end());
    
    inBit(U, A, n, ka, Abit);
    inBit(U, B, n, kb, Bbit);
        
    determine(U,Abit,Bbit,n);
}

string input(int x) {
    string tmp;
    do
    {
        cin >> tmp;
    } while (tmp.length() != x);
    return tmp;
}

void inBit(string A,string B, int n, int k, int* bit) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j  < k; j ++)
            if (A[i] == B[i]){
                bit[i] = 1;
                break;
            }
            else
                bit[i] = 0;
}

void determine(string U, int* Abit, int* Bbit, int n) {
    const int N = n;
    string A, B, SnotA, SAandB, SAorB, SAdiffB, SAxorB;
    int* notA = new int[n];
    int* AandB = new int[n];
    int* AorB = new int[n];
    int* AdiffB = new int[n];
    int* AxorB = new int[n];

    for (int i = 0; i < n; i++){
        if (Abit[i] == 1) A += U[i];
        if (Bbit[i] == 1) B += U[i];
        notA[i] = 1 - Abit[i];
        if (notA[i] == 1) SnotA += U[i];
        AandB[i] = (Abit[i] == 1 && Bbit[i] == 1) ? 1 : 0;
        if (AandB[i] == 1) SAandB += U[i];
        AorB[i] = (Abit[i] == 1 || Bbit[i] == 1) ? 1 : 0;
        if (AorB[i] == 1) SAorB += U[i];
        AdiffB[i] = (Abit[i] == 1 && Bbit[i] == 0) ? 1 : 0;
        if (AdiffB[i] == 1) SAdiffB += U[i];
        AxorB[i] = Abit[i] ^ Bbit[i];
        if (AxorB[i] == 1) SAxorB += U[i];
    }

    cout << "U:             " << U << endl;
    cout << "A:             ";
    for (int i = 0; i < n; i++) cout << Abit[i];
    cout << "\t" << A << endl;
    cout << "B:             ";
    for (int i = 0; i < n; i++) cout << Bbit[i];
    cout << "\t" << B << endl;
    cout << "notA:          ";
    for (int i = 0; i < n; i++) cout << notA[i];
    cout << "\t" << SnotA << endl;
    cout << "AandB:         "; 
    for (int i = 0; i < n; i++) cout << AandB[i];
    cout << "\t" << SAandB << endl;
    cout << "AorB:          "; 
    for (int i = 0; i < n; i++) cout << AorB[i];
    cout << "\t" << SAorB << endl;
    cout << "AdifferenceB:  ";
    for (int i = 0; i < n; i++) cout << AdiffB[i];
    cout << "\t" << SAdiffB << endl;
    cout << "AxorB:         ";
    for (int i = 0; i < n; i++) cout << AxorB[i];
    cout << "\t" << SAxorB << endl;

    delete[] notA;
    delete[] AandB;
    delete[] AorB;
    delete[] AdiffB;
    delete[] AxorB;
}
#include <iostream>
#include <cstring>
#include <ctime>

#include "StringSet.h"
#include "WordSet.h"
#include "BitArrSet.h"
#include "ListSet.h"

#define N_MAX 26
using namespace std;

void generateUniqueRandomString(char s[]) {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 5; ++i) {
        int index = rand() % alphabet.size();
        s[i] = alphabet[index];
        alphabet.erase(index, 1);
    }
    s[5] = '\0';
}

bool InAlphabet(char c) {
    bool flag = false;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 26; ++i) {
        if (c == alphabet[i]) flag = true;
    }
    return flag;
}

string StringCheck() {
    char str[N_MAX + 1];
    int k;
    bool flag = true;

    while(flag) {
        k = 0;
        cin >> str;
        for (int i = 0; i < strlen(str); i++) {
            if (!InAlphabet(str[i])) {
                k += 1;
                break;
            }
        }
        if (k == 0) flag = false;
        else cout << "Input is incorrect! Try again!\n";
    }
    return str;
}

int main() {
    srand(time(0));
    char A[N_MAX + 1];
    char B[N_MAX + 1];
    char C[N_MAX + 1];
    char D[N_MAX + 1];

    cout << "This program illustrates an object-oriented approach to the task of processing sets.\n";
    cout << "Select the input operation mode: manual (M) or automatic (A):\n";

    char key[100];
    int flag = 0;

    do {
        cin >> key;
        if (strcmp(key, "M") == 0 || strcmp(key, "m") == 0 || strcmp(key, "A") == 0 || strcmp(key, "a") == 0) {
            flag = 1;
        }
        if (flag != 1) cout << "Input is incorrect! Try again!\n";
    } while (flag == 0);

    if (strcmp(key, "M") == 0 || strcmp(key, "m") == 0) {
        cout << "Enter your sets using capital letters.\n";
        cout << "A:\n";
        strcpy(A, StringCheck().c_str());
        cout << "B:\n";
        strcpy(B, StringCheck().c_str());
        cout << "C:\n";
        strcpy(C, StringCheck().c_str());
        cout << "D:\n";
        strcpy(D, StringCheck().c_str());
    } else {
        generateUniqueRandomString(A);
        generateUniqueRandomString(B);
        generateUniqueRandomString(C);
        generateUniqueRandomString(D);
    }

    cout << "\nInitial sets:\n";
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
    cout << D << '\n' << endl;

    ///String sets
    cout << "String sets result:\n";
    clock_t start1 = clock();

    StringSet sE = StringSet();
    for (int i = 0; i < 100000; ++i) {
        StringSet sA(A);
        StringSet sB(B);
        StringSet sC(C);
        StringSet sD(D);
        sE = sA / sB / sC | sD;
    }

    sE.Print();

    clock_t end1 = clock();
    double duration1 = double(end1 - start1) / CLOCKS_PER_SEC;
    cout << "Time: " << duration1 << " sec\n" << endl;

    ///Word sets
    cout << "Word sets result:\n";
    clock_t start2 = clock();

    WordSet wE = WordSet();
    for (int i = 0; i < 100000; ++i) {
        WordSet wA(A);
        WordSet wB(B);
        WordSet wC(C);
        WordSet wD(D);
        wE = wA / wB / wC | wD;
    }
    wE.Print();

    clock_t end2 = clock();
    double duration2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Time: " << duration2 << " sec\n" << endl;

    ///BitArray sets
    cout << "Bit array sets result:\n";
    clock_t start3 = clock();

    BitArrSet bE = BitArrSet();
    for (int i = 0; i < 100000; ++i) {
        BitArrSet bA(A);
        BitArrSet bB(B);
        BitArrSet bC(C);
        BitArrSet bD(D);
        bE = bA / bB / bC | bD;
    }

    bE.Print();

    clock_t end3 = clock();
    double duration3 = double(end3 - start3) / CLOCKS_PER_SEC;
    cout << "Time: " << duration3 << " sec\n" << endl;

    ///List sets
    cout << "List sets result:\n";
    clock_t start4 = clock();

    ListSet lE = ListSet();
    for (int i = 0; i < 100000; ++i) {
        ListSet lA(A);
        ListSet lB(B);
        ListSet lC(C);
        ListSet lD(D);
        lE = lA / lB / lC | lD;
    }
    lE.Print();

    clock_t end4 = clock();
    double duration4 = double(end4 - start4) / CLOCKS_PER_SEC;
    cout << "Time: " << duration4 << " sec\n" << endl;

    cout << "Power of result set: " << lE.GetPower() << "." << endl;
    return 0;
}

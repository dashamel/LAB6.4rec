#include <iostream>
#include <cmath>
using namespace std;

int MinMod(int mas[], int n, int i, int minMod)
{
    if (i >= n) 
        return minMod;

    minMod = min(minMod, abs(mas[i]));

    return MinMod(mas, n, i + 1, minMod);
}

int Sumzero(int mas[], int n, int i, bool foundZero)
{
    if (i >= n || foundZero) 
        return 0;

    int current = mas[i] == 0 ? 0 : abs(mas[i]);

    foundZero = foundZero || (mas[i] == 0);

    return current + Sumzero(mas, n, i + 1, foundZero);
}

void Modifmas(int mas[], int n, int i, int j) 
{
    if (i >= n - 1) 
        return;

    if (j < n - i - 1) 
    { 
        if (mas[j] % 2 != 0) 
        {
            int tmp = mas[j];
            mas[j] = mas[j + 1];
            mas[j + 1] = tmp;
        }
        Modifmas(mas, n, i, j + 1); 
    }
    else {
        Modifmas(mas, n, i + 1, 0); 
    }
}

void PrintArray(int mas[], int n, int i)
{
    if (i >= n)
    {
        cout << endl;
        return;
    }
    cout << mas[i] << " ";
    PrintArray(mas, n, i + 1); 
}
   
int main() 
{
    int n;
    cout << "Count elements n: "; 
    cin >> n;

    int* mas = new int[n];

    cout << "Elements of mas: ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> mas[i];
    }

    int minMod = MinMod(mas, n, 0, abs(mas[0]));
    cout << "Min element in abs: " << minMod << endl;

    int sumMod = Sumzero(mas, n, 0, false);
    cout << "Summ: " << sumMod << endl;

    Modifmas(mas, n, 0, 0);
    cout << "Modifmas: ";
    PrintArray(mas, n, 0);

    delete[] mas;

    return 0;
}

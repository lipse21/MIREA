#include <iostream>  
#include <algorithm> // для swap
using namespace std;

bool check(int* a, int n) {  // функция, которая проверяет массив на соответствие условию
    for (int i = 0; i < n; i++) {
        if (a[i] == i + 1) // если шарик № i вытащили по счёту i, то возвращаем true (i+1) потому-что начинаем с 0 элемента
            return true;
    }
    return false;
}

int perestanovka(int t, int n, int* a) { // функция, которая выводит ответ на задачу
    int cnt = 0; // счётчик подхожящих вариантов
    if (t == n) { // если массив перестановок готов
        if (check(a, n)) // то проверяем его нашей функцией
            cnt++; // если все круто то +1
    }
    else {
        for (int j = t; j < n; ++j) { // начинаем процесс перестановок
            swap(a[t], a[j]);
            cnt += perestanovka(t + 1, n, a); // рекурсивный вызов
            swap(a[t], a[j]); 
        }
    }
    return cnt;
}

int main() {
    setlocale(LC_ALL, "Russian"); // чтобы консоль русские букчвы нормально писала
    cout << "Введите количество шариков - ";
    int n;
    cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    } // заполняем массив числаи от 1 до n

    
    int tcnt = perestanovka(0, n, a); // переменная для ответа
    cout << "Возможное кол-во вариантов - "<<tcnt << endl;

    delete[] a; // очищаем память

    return 0;
}

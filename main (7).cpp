#include <iostream>
#include <cmath> // для математичних функцій
using namespace std;

//  Прототипи 
void task_Proc3();      // Завдання 1 — Proc3: Mean(X,Y,AMean,GMean)
void task_Integer21();  // Завдання 2 — Integer21 
void task_Proc51();     // Завдання 3 — Proc51: TriangleType(a,b,c)
void showMenu();        // Меню вибору користувача

// Підфункції для Integer21
bool inputSeconds(int &N);    // введення з перевіркою
int calcSeconds(int N);       // обчислення
void outputSeconds(int seconds); // виведення результату

// Підфункції для Proc3 
void Mean(double X, double Y, double &AMean, double &GMean);

// Підфункції для Proc51 
int TriangleType(double a, double b, double c);

int main() {
    int choice;
    do {
        showMenu();
        cout << "Оберіть завдання (1-3) або 0 для виходу: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: task_Proc3(); break;
            case 2: task_Integer21(); break;
            case 3: task_Proc51(); break;
            case 0: cout << "Вихід із програми.\n"; break;
            default: cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
        cout << endl;
    } while (choice != 0);

    return 0;
}

//  Визначення функцій

//  Завдання 1: Proc3 
void Mean(double X, double Y, double &AMean, double &GMean) {
    AMean = (X + Y) / 2;
    GMean = sqrt(X * Y);
}

void task_Proc3() {
    cout << " Завдання 1: Proc3 (Mean) \n";
    double A, B, C, D;
    cout << "Введіть 4 додатних числа A, B, C, D: ";
    cin >> A >> B >> C >> D;

    if (A <= 0 || B <= 0 || C <= 0 || D <= 0) {
        cout << "Помилка: усі числа мають бути додатними.\n";
        return;
    }

    double AMean, GMean;
    Mean(A, B, AMean, GMean);
    cout << "(A,B): AMean=" << AMean << ", GMean=" << GMean << endl;

    Mean(A, C, AMean, GMean);
    cout << "(A,C): AMean=" << AMean << ", GMean=" << GMean << endl;

    Mean(A, D, AMean, GMean);
    cout << "(A,D): AMean=" << AMean << ", GMean=" << GMean << endl;
}

//  Завдання 2: Integer21 
// 1. Введення даних
bool inputSeconds(int &N) {
    cout << "Введіть кількість секунд з початку доби: ";
    cin >> N;
    if (cin.fail() || N < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
    return true;
}

// 2. Обчислення результату
int calcSeconds(int N) {
    return N % 60; // залишок секунд з останньої хвилини
}

// 3. Виведення результату
void outputSeconds(int seconds) {
    cout << "Кількість секунд з початку останньої хвилини: " << seconds << endl;
}

// 4. Головна процедура для Integer21
void task_Integer21() {
    cout << " Завдання 2: Integer21 \n";
    int N;
    if (!inputSeconds(N)) {
        cout << "Помилка: введено некоректні дані!\n";
        return;
    }

    int result = calcSeconds(N);
    outputSeconds(result);
}

//  Завдання 3: Proc51 
int TriangleType(double a, double b, double c) {
    if (a + b <= c || a + c <= b || b + c <= a)
        return 999; // трикутник не існує

    double maxSide = max(a, max(b, c));
    double sumSq = a * a + b * b + c * c - maxSide * maxSide;

    // Теорема косинусів
    if (fabs(a * a + b * b + c * c - 2 * maxSide * maxSide) < 1e-6)
        return 0; // прямокутний
    else if (a * a + b * b + c * c > 2 * maxSide * maxSide)
        return 1; // гострокутний
    else
        return -1; // тупокутний
}

void task_Proc51() {
    cout << " Завдання 3: Proc51 (TriangleType) \n";
    double a, b, c;
    cout << "Введіть сторони трикутника a, b, c: ";
    cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "Помилка: сторони мають бути додатні.\n";
        return;
    }

    int t = TriangleType(a, b, c);
    if (t == 999)
        cout << "Трикутник не існує.\n";
    else if (t == 1)
        cout << "Трикутник гострокутний.\n";
    else if (t == 0)
        cout << "Трикутник прямокутний.\n";
    else
        cout << "Трикутник тупокутний.\n";
}

// ===== Меню =====
void showMenu() {
    cout << "-----------------------------------\n";
    cout << "        МЕНЮ ЛР №4       \n";
    cout << "1 - Proc3\n";
    cout << "2 - Integer21\n";
    cout << "3 - Proc51\n";
    cout << "0 - Вихід\n";
    cout << "-----------------------------------\n";
}

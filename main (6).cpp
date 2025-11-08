#include <iostream>
#include <cmath> // для математичних функцій
using namespace std;

//  Прототипи функцій
void task_Proc3();      // Завдання 1 — Proc3: Mean(X,Y,AMean,GMean)
void task_Integer21();  // Завдання 2 — Integer21
void task_Proc51();     // Завдання 3 — Proc51: TriangleType(a,b,c)
void showMenu();        // Меню вибору користувача

//  Головна функція
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
// Процедура обчислює середнє арифметичне та геометричне двох чисел
void Mean(double X, double Y, double &AMean, double &GMean) {
    AMean = (X + Y) / 2;
    GMean = sqrt(X * Y);
}

void task_Proc3() {
    cout << "Завдання 1: Proc3 (Mean)\n";
    double A, B, C, D;
    cout << "Введіть 4 додатних числа A, B, C, D: ";
    cin >> A >> B >> C >> D;

    if (A <= 0 || B <= 0 || C <= 0 || D <= 0) {
        cout << "Помилка: всі числа мають бути додатними.\n";
        return;
    }

    double AMean, GMean;
    // (A, B)
    Mean(A, B, AMean, GMean);
    cout << "Для (A,B): AMean=" << AMean << ", GMean=" << GMean << endl;
    // (A, C)
    Mean(A, C, AMean, GMean);
    cout << "Для (A,C): AMean=" << AMean << ", GMean=" << GMean << endl;
    // (A, D)
    Mean(A, D, AMean, GMean);
    cout << "Для (A,D): AMean=" << AMean << ", GMean=" << GMean << endl;
}

//  Завдання 2: Integer21 
// Визначити кількість секунд з початку останньої хвилини
void task_Integer21() {
    cout << " Завдання 2: Integer21 \n";
    int N;
    cout << "Введіть кількість секунд з початку доби: ";
    cin >> N;

    if (N < 0) {
        cout << "Помилка: кількість секунд має бути невід’ємною.\n";
        return;
    }

    int seconds = N % 60;
    cout << "Кількість секунд з початку останньої хвилини: " << seconds << endl;
}

//  Завдання 3: Proc51 
// Функція визначає тип трикутника:
//  1 — гострокутний, 0 — прямокутний, -1 — тупокутний
int TriangleType(double a, double b, double c) {
    if (a + b <= c || a + c <= b || b + c <= a)
        return 999; // не існує трикутника

    // Сортуємо сторони для зручності
    double maxSide = max(a, max(b, c));
    double sumSq = a * a + b * b + c * c - maxSide * maxSide;

    double diff = fabs(sumSq - maxSide * maxSide);

    // За теоремою косинусів
    if (fabs(a * a + b * b + c * c - 2 * maxSide * maxSide) < 1e-6)
        return 0; // прямокутний
    else if (a * a + b * b + c * c > 2 * maxSide * maxSide)
        return 1; // гострокутний
    else
        return -1; // тупокутний
}

void task_Proc51() {
    cout << " Завдання 3: Proc51 \n";
    double a, b, c;
    cout << "Введіть сторони трикутника a, b, c: ";
    cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "Помилка: сторони мають бути додатні.\n";
        return;
    }

    int t = TriangleType(a, b, c);

    if (t == 999)
        cout << "Трикутник із таких сторін не існує.\n";
    else if (t == 1)
        cout << "Трикутник гострокутний.\n";
    else if (t == 0)
        cout << "Трикутник прямокутний.\n";
    else
        cout << "Трикутник тупокутний.\n";
}

//  Меню 
void showMenu() {
    cout << "-----------------------------------\n";
    cout << "        Меню лр №4       \n";
    cout << "1 - Proc3: Середні арифметичне та геометричне\n";
    cout << "2 - Integer21: Секунди останньої хвилини\n";
    cout << "3 - Proc51: Тип трикутника\n";
    cout << "0 - Вихід\n";
    cout << "-----------------------------------\n";
}

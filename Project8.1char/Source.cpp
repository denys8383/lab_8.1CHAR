#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Функція Count приймає рядок s та рядок символів targets. Вона підраховує кількість символів із targets у рядку s.
int Count(char* s, const char* targets)
{
    int count = 0;  // Лічильник кількості символів.
    int pos = 0;    // Позиція у рядку s.
    char* t;        // Вказівник для знаходження символів targets у рядку s.

    // Цикл, який шукає символи targets у рядку s.
    while ((t = strpbrk(s + pos, targets)) != nullptr)
    {
        pos = t - s + 1;  // Оновлення позиції наступного пошуку.
        count++;          // Збільшення лічильника.
    }

    return count;
}

// Функція Change приймає рядок s та замінює символи '+', '-', та '=' на два символи '*'.
// Заміщений рядок повертається як результат, а оригінальний рядок s змінюється.
char* Change(char* s)
{
    char* t = new char[3 * strlen(s) + 1];  // Створення нового рядка для результату.
    int pos1 = 0;                           // Позиція у вхідному рядку s.
    int pos2 = 0;                           // Позиція у новому рядку t.

    // Цикл, який обробляє кожен символ у вхідному рядку s.
    while (s[pos1] != '\0')
    {
        if (strchr("+-=", s[pos1]) != nullptr)
        {
            // Заміна лише якщо символ - '+', '-', або '='.
            t[pos2++] = '*';
            t[pos2++] = '*';
        }
        else
        {
            // Копіювання символу без змін.
            t[pos2++] = s[pos1];
        }

        pos1++;  // Перехід до наступного символу у вхідному рядку.
    }

    // Нуль-термінування нового рядка t.
    t[pos2] = '\0';

    // Копіювання модифікованого рядка назад у вхідний рядок s.
    strcpy(s, t);

    return t;  // Повертається новий рядок з результатом.
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;

    // Введення рядка з консолі.
    cin.getline(str, 100);

    const char targets[] = "+-=";

    // Виклик функції Count для підрахунку кількості символів у введеному рядку.
    int totalCharacterCount = Count(str, targets);

    // Виведення результату підрахунку кількості символів.
    cout << "String contains " << totalCharacterCount << " symbols '+' '-' i '=' " << endl;

    // Створення динамічного масиву dest для результату функції Change.
    char* dest = new char[151];

    // Виклик функції Change для модифікації рядка str та отримання результату у dest.
    dest = Change(str);

    // Виведення модифікованого рядка (параметр) та модифікованого рядка (результат).
    cout << "Modified string (param): " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    // Звільнення пам'яті, виділеної для dest.
    delete[] dest;

    return 0;
}

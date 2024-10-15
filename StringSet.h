#ifndef PROJECT_STRINGSET_H
#define PROJECT_STRINGSET_H

class StringSet {
private: // Закрытая часть класса — данные
    static int UnivPower, SetsCount; // мощность универсума и счётчик множеств
    static char *Universum;
    int Power; // мощность множества
    char Tag; // тег
    char *Data; // память для множества
    static bool Contains(char *s, char c);

public: // Открытая часть — функции для работы с множеством
    StringSet operator|(const StringSet &) const; // объединение

    StringSet operator&(const StringSet &) const; // пересечение

    StringSet operator/(const StringSet &) const; // разность

    StringSet operator~() const; // дополнение до универсума

    StringSet &operator&=(const StringSet &B);

    StringSet &operator|=(const StringSet &B);

    StringSet &operator/=(const StringSet &B);

    StringSet &operator=(const StringSet &B); // оператор присваивания

    void Print(); // вывод множества на экран
    int GetPower() { return Power; } // получение мощности
    StringSet(char *elements); // конструктор множества
    StringSet(const StringSet &); // конструктор копии
    StringSet();

    ~StringSet() {
        delete[] Data;
    }
};

#endif //PROJECT_STRINGSET_H

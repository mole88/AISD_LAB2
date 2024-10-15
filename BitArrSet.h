#ifndef PROJECT_BITARRSET_H
#define PROJECT_BITARRSET_H

class BitArrSet {
private: // Закрытая часть класса — данные
    static int UnivPower, SetsCount; // мощность универсума и счётчик множеств
    static char *Universum;
    int Power; // мощность множества
    char Tag; // тег
    bool *Data; // память для множества

public: // Открытая часть — функции для работы с множеством
    BitArrSet operator|(const BitArrSet &) const; // объединение

    BitArrSet operator&(const BitArrSet &) const; // пересечение

    BitArrSet operator/(const BitArrSet &) const; // разность

    BitArrSet operator~(); // дополнение до универсума

    BitArrSet &operator&=(const BitArrSet &B);

    BitArrSet &operator|=(const BitArrSet &B);

    BitArrSet &operator/=(const BitArrSet &B);

    BitArrSet &operator=(const BitArrSet &B); // оператор присваивания

    static int CountElements(bool *arr);

    static unsigned int CharToInd(char c);

    static char IndToChar(unsigned int ind);

    static void ToBitArray(char *str, bool *arr);

    static void ToString(bool *arr, char *str);

    static void ZeroArr(bool *arr);

    void Print(); // вывод множества на экран
    int GetPower() { return Power; } // получение мощности
    BitArrSet(char *elements); // конструктор множества
    BitArrSet(const BitArrSet &); // конструктор копии
    BitArrSet();

    ~BitArrSet() {
        delete[] Data;
    }
};

#endif //PROJECT_BITARRSET_H

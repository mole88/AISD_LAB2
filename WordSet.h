#ifndef PROJECT_WORDSET_H
#define PROJECT_WORDSET_H

class WordSet {
private: // Закрытая часть класса — данные
    static int UnivPower, SetsCount; // мощность универсума и счётчик множеств
    static char *Universum;
    int Power; // мощность множества
    char Tag; // тег
    unsigned int Data; // память для множества

public: // Открытая часть — функции для работы с множеством
    WordSet operator|(const WordSet &) const; // объединение

    WordSet operator&(const WordSet &) const; // пересечение

    WordSet operator/(const WordSet &) const; // разность

    WordSet operator~() const; // дополнение до универсума

    WordSet &operator&=(const WordSet &B);

    WordSet &operator|=(const WordSet &B);

    WordSet &operator/=(const WordSet &B);

    WordSet &operator=(const WordSet &B); // оператор присваивания

    static int CountElements(unsigned int word);

    static unsigned int CharToInd(char c);

    static char IndToChar(unsigned int ind);

    static unsigned int ToBitWord(char *s);

    void ToString(unsigned int word, char *str);

    void Print(); // вывод множества на экран
    int GetPower() { return Power; } // получение мощности
    WordSet(char *elements); // конструктор множества
    WordSet(const WordSet &); // конструктор копии
    WordSet();

};

#endif //PROJECT_WORDSET_H

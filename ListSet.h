#ifndef PROJECT_LISTSET_H
#define PROJECT_LISTSET_H

struct Node {
    char Element;
    Node *Next;

    Node(char element, Node *next = nullptr);
};

class ListSet {
private:
    static int UnivPower, SetsCount; // мощность универсума и счётчик множеств
    static char *Universum;
    int Power; // мощность множества
    char Tag; // тег
    Node *Head; // указатель на первый элемент множества

public:
    // Конструкторы и деструктор
    ListSet(const char *elements);

    ListSet(const ListSet &other);

    ListSet();

    ~ListSet();

    // Операторы для работы с множествами
    ListSet operator|(const ListSet &other) const;

    ListSet operator&(const ListSet &other) const;

    ListSet operator/(const ListSet &other) const;

    ListSet operator~() const;

    ListSet &operator&=(const ListSet &other);

    ListSet &operator|=(const ListSet &other);

    ListSet &operator/=(const ListSet &other);

    ListSet &operator=(const ListSet &other);

    // Вспомогательные функции
    void AddElement(char element);

    bool Contains(char element) const;

    void Clear();

    void Print() const;

    int GetPower() { return Power; }

};

#endif //PROJECT_LISTSET_H

#include <iostream>
#include "ListSet.h"

Node::Node(char element, Node *next) {
    Element = element;
    Next = next;
}

int ListSet::UnivPower = 26;
int ListSet::SetsCount = 0;
char *ListSet::Universum = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Конструкторы и деструктор класса ListSet
ListSet::ListSet(const char *elements) : Tag('A' + SetsCount++) {
    Power = 0;
    Head = nullptr;
    while (*elements) {
        AddElement(*elements++);
    }
}

ListSet::ListSet(const ListSet &N) : Tag('A' + SetsCount++) {
    Power = N.Power;
    Head = nullptr;
    Node *current = N.Head;
    while (current) {
        AddElement(current->Element);
        current = current->Next;
    }
}

ListSet::ListSet() : Tag('A' + SetsCount++) {
    Power = 0;
    Head = nullptr;
}

ListSet::~ListSet() {
    Clear();
}

// Операции над множествами
ListSet ListSet::operator|(const ListSet &other) const {
    ListSet result = *this;
    Node *current = other.Head;
    while (current) {
        result.AddElement(current->Element);
        current = current->Next;
    }
    return result;
}

ListSet ListSet::operator&(const ListSet &other) const {
    ListSet result;
    Node *current = Head;
    while (current) {
        if (other.Contains(current->Element)) {
            result.AddElement(current->Element);
        }
        current = current->Next;
    }
    return result;
}

ListSet ListSet::operator/(const ListSet &other) const {
    ListSet result;
    Node *current = Head;
    while (current) {
        if (!other.Contains(current->Element)) {
            result.AddElement(current->Element);
        }
        current = current->Next;
    }
    return result;
}

ListSet ListSet::operator~() const {
    ListSet result;
    for (int i = 0; i < UnivPower; ++i) {
        char element = Universum[i];
        if (!Contains(element)) {
            result.AddElement(element);
        }
    }
    return result;
}

// Операторы присваивания и модификации
ListSet &ListSet::operator&=(const ListSet &other) {
    *this = *this & other;
    return *this;
}

ListSet &ListSet::operator|=(const ListSet &other) {
    *this = *this | other;
    return *this;
}

ListSet &ListSet::operator/=(const ListSet &other) {
    *this = *this / other;
    return *this;
}

ListSet &ListSet::operator=(const ListSet &other) {
    if (this != &other) {
        Clear();
        Node *current = other.Head;
        while (current) {
            AddElement(current->Element);
            current = current->Next;
        }
    }
    return *this;
}

void ListSet::AddElement(char element) {
    if (!Contains(element)) {
        if (Head == nullptr) { // если список пуст, то элемент становится первым
            Head = new Node(element, nullptr);
        } else { // иначе находим конец списка и добавляем туда элемент
            Node *current = Head;
            while (current->Next != nullptr) {
                current = current->Next;
            }
            current->Next = new Node(element, nullptr);
        }
        Power++;
    }
}

bool ListSet::Contains(char element) const {
    Node *current = Head;
    while (current) {
        if (current->Element == element) {
            return true;
        }
        current = current->Next;
    }
    return false;
}

void ListSet::Clear() {
    while (Head) {
        Node *tmp = Head;
        Head = Head->Next;
        delete tmp;
    }
    Power = 0;
}

// Функция вывода множества
void ListSet::Print() const {
    Node *current = Head;
    while (current != nullptr) {
        std::cout << current->Element;
        current = current->Next;
    }
    std::cout << std::endl;
}

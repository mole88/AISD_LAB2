#include <cstring>
#include <iostream>
#include "WordSet.h"

int WordSet::UnivPower = 26;
int WordSet::SetsCount = 0;
char *WordSet::Universum = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

unsigned int WordSet::CharToInd(char c) {
    return c - 'A';
}

char WordSet::IndToChar(unsigned int ind) {
    return (char) (ind + 'A');
}

unsigned int WordSet::ToBitWord(char *s) {
    unsigned int word = 0;
    for (int i = 0; s[i]; ++i) {
        word |= (1u << CharToInd(s[i]));
    }
    return word;
}

void WordSet::ToString(unsigned int word, char *str) {
    int off = 0;
    for (int i = 0; i < UnivPower; ++i) {
        unsigned int t = (1u << i);
        if ((word & t) == t) {
            str[off++] = IndToChar(i);
        }
    }
    str[off] = '\0';
}

int WordSet::CountElements(unsigned int word) {
    int count = 0;
    for (int i = 0; i < UnivPower; ++i) {
        unsigned int t = (1u << i);
        if ((word & t) == t) {
            count++;
        }
    }
    return count;
}

WordSet::WordSet() : Tag('A' + SetsCount++) {
    Power = 0;
    Data = 0;
}

WordSet::WordSet(char *elements) : Tag('A' + SetsCount++) {
    Data = 0;
    if (elements != nullptr) {
        Power = strlen(elements);
        Data = ToBitWord(elements);
    } else
        Power = 0;
}

WordSet::WordSet(const WordSet &original) : Tag('A' + SetsCount++) {
    Power = original.Power;
    Data = original.Data;
}

WordSet &WordSet::operator&=(const WordSet &B) {
    Data &= B.Data;
    Power = CountElements(Data);
    return *this;
}

WordSet WordSet::operator&(const WordSet &B) const {
    WordSet curSetCopy(*this);
    return curSetCopy &= B;
}

WordSet &WordSet::operator|=(const WordSet &B) {
    Data |= B.Data;
    Power = CountElements(Data);
    return *this;
}

WordSet WordSet::operator|(const WordSet &B) const {
    WordSet curSetCopy(*this);
    return curSetCopy |= B;
}

WordSet &WordSet::operator/=(const WordSet &B) {
    Data &= ~B.Data;
    Power = CountElements(Data);
    return *this;
}

WordSet WordSet::operator/(const WordSet &B) const {
    WordSet curSetCopy(*this);
    return curSetCopy /= B;
}

WordSet WordSet::operator~() const {
    WordSet curSetCopy(*this);
    curSetCopy.Power = UnivPower - curSetCopy.Power;
    curSetCopy.Data = ~curSetCopy.Data;

    return curSetCopy;
}

WordSet &WordSet::operator=(const WordSet &B) {
    if (this != &B) {
        Power = B.Power;
        Data = B.Data;

        Tag = 'A' + SetsCount++;
    }
    return *this;
}

void WordSet::Print() {
    char str[UnivPower];
    ToString(Data, str);
    std::cout << str << std::endl;
}

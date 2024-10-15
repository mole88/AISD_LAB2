#include "BitArrSet.h"
#include <cstring>
#include <iostream>

int BitArrSet::UnivPower = 26;
int BitArrSet::SetsCount = 0;
char *BitArrSet::Universum = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

unsigned int BitArrSet::CharToInd(char c) {
    return c - 'A';
}

char BitArrSet::IndToChar(unsigned int ind) {
    return (char) (ind + 'A');
}

void BitArrSet::ToBitArray(char *str, bool *arr) {
    for (int i = 0; str[i]; ++i) {
        arr[CharToInd(str[i])] = true;
    }
}

void BitArrSet::ToString(bool *arr, char *str) {
    int off = 0;
    for (int i = 0; i < UnivPower; ++i) {
        if (arr[i]) {
            str[off++] = IndToChar(i);
        }
    }
    str[off] = '\0';
}

void BitArrSet::ZeroArr(bool *arr) {
    for (int i = 0; i < UnivPower; ++i) {
        arr[i] = false;
    }
}

BitArrSet::BitArrSet() : Tag('A' + SetsCount++) {
    Power = 0;
    Data = new bool[UnivPower];
}

BitArrSet::BitArrSet(char *elements) : Tag('A' + SetsCount++) {
    Power = strlen(elements);
    Data = new bool[UnivPower];
    ZeroArr(Data);
    ToBitArray(elements, Data);
}

BitArrSet::BitArrSet(const BitArrSet &B) : Tag('A' + SetsCount++) {
    Power = B.Power;
    Data = new bool[UnivPower];
    memcpy(Data, B.Data, UnivPower);
}

int BitArrSet::CountElements(bool *arr) {
    int count = 0;
    for (int i = 0; i < UnivPower; ++i)
        if (arr[i]) count++;

    return count;
}

void BitArrSet::Print() {
    char *str = new char[UnivPower];
    ToString(Data, str);

    std::cout << str << std::endl;
}

BitArrSet &BitArrSet::operator&=(const BitArrSet &B) {
    for (int i = 0; i < UnivPower; ++i)
        Data[i] = Data[i] && B.Data[i];

    Power = CountElements(Data);
    return *this;
}

BitArrSet BitArrSet::operator&(const BitArrSet &B) const {
    BitArrSet curSetCopy(*this);
    return curSetCopy &= B;
}

BitArrSet &BitArrSet::operator|=(const BitArrSet &B) {
    for (int i = 0; i < UnivPower; ++i)
        Data[i] = Data[i] || B.Data[i];

    Power = CountElements(Data);
    return *this;
}

BitArrSet BitArrSet::operator|(const BitArrSet &B) const {
    BitArrSet curSetCopy(*this);
    return curSetCopy |= B;
}

BitArrSet &BitArrSet::operator/=(const BitArrSet &B) {
    for (int i = 0; i < UnivPower; ++i)
        Data[i] = Data[i] && !B.Data[i];

    Power = CountElements(Data);
    return *this;
}

BitArrSet BitArrSet::operator/(const BitArrSet &B) const {
    BitArrSet curSetCopy(*this);
    return curSetCopy /= B;
}

BitArrSet BitArrSet::operator~() {
    for (int i = 0; i < UnivPower; ++i)
        Data[i] = !Data[i];

    Power = CountElements(Data);
    return *this;
}

BitArrSet &BitArrSet::operator=(const BitArrSet &B) {
    if (this != &B) {
        Power = B.Power;
        memcpy(Data, B.Data, UnivPower);
        Tag = 'A' + SetsCount++;
    }
    return *this;
}

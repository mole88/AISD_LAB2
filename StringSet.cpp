#include "StringSet.h"
#include <cstring>
#include <iostream>

int StringSet::UnivPower = 26;
int StringSet::SetsCount = 0;
char *StringSet::Universum = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

StringSet::StringSet() : Tag('A' + SetsCount++) {
    Power = 0;
    Data = new char[UnivPower + 1];
    Data[0] = '\0';
}

StringSet::StringSet(char *elements) : Tag('A' + SetsCount++) {
    Data = new char[UnivPower + 1];

    if (elements != nullptr) {
        Power = strlen(elements);
        strcpy(Data, elements);
    } else {
        Power = 0;
        Data[0] = '\0';
    }
}

StringSet::StringSet(const StringSet &original) : Tag('A' + SetsCount++) {
    Power = original.Power;
    Data = new char[UnivPower + 1];
    strcpy(Data, original.Data);
}

StringSet &StringSet::operator&=(const StringSet &B) {
    StringSet curSetCopy(*this);
    Power = 0;
    for (int i = 0; i < curSetCopy.Power; ++i) {
        for (int j = 0; j < B.Power; ++j) {
            if (curSetCopy.Data[i] == B.Data[j])
                Data[Power++] = curSetCopy.Data[i];
        }
    }
    Data[Power] = '\0';
    return *this;
}

StringSet StringSet::operator&(const StringSet &B) const {
    StringSet curSetCopy(*this);
    return (curSetCopy &= B);
}

bool StringSet::Contains(char *s, char c) {
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == c)
            return true;
    }
    return false;
}

StringSet &StringSet::operator|=(const StringSet &B) {
    StringSet curSetCopy(*this);
    for (int i = 0; i < B.Power; ++i) {
        if (!Contains(curSetCopy.Data, B.Data[i]))
            Data[Power++] = B.Data[i];
    }
    Data[Power] = '\0';
    return *this;
}

StringSet StringSet::operator|(const StringSet &B) const {
    StringSet curSetCopy(*this);
    return curSetCopy |= B;
}

StringSet &StringSet::operator/=(const StringSet &B) {
    StringSet curSetCopy(*this);
    Power = 0;
    for (int i = 0; i < curSetCopy.Power; ++i) {
        if (!Contains(B.Data, curSetCopy.Data[i]))
            Data[Power++] = curSetCopy.Data[i];
    }
    Data[Power] = '\0';

    return *this;
}

StringSet StringSet::operator/(const StringSet &B) const {
    StringSet curSetCopy(*this);
    return curSetCopy /= B;
}

StringSet StringSet::operator~() const {
    StringSet result(*this);
    result.Power = 0;
    for (int i = 0; i < UnivPower; ++i) {
        if (!Contains(Data, Universum[i]))
            result.Data[result.Power++] = Universum[i];
    }
    result.Data[result.Power] = '\0';

    return result;
}

StringSet &StringSet::operator=(const StringSet &B) {
    if (this != &B) {
        char *dst(Data), *src(B.Data);
        Power = B.Power;
        while ((*dst++ = *src++));

        Tag = 'A' + SetsCount++;
    }
    return *this;
}

void StringSet::Print() {
    std::cout << Data << std::endl;
}

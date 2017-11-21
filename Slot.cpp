#include "Slot.h"
Slot::Slot():discs(DISC_NUM_AT_START)
{}



Slot::Slot(const Slot &s):discs(s.getNumOfDiscs())
{}


int Slot::getNumOfDiscs() const
{
    return discs;
}


void Slot::setNumOfDiscs(const int n)
{
    discs = n;
}

Slot::~Slot()
{
}

void Slot::operator++(int)
{
    discs++;
}
void Slot::operator++()
{
    discs++;
}
void Slot::operator--(int)
{
    discs--;
}
void Slot:: operator--()
{
    discs--;
}

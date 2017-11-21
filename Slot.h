#ifndef _SLOT_H
#define _SLOT_H

class Slot
{
public:
    Slot();
    Slot(const Slot &s);
    ~Slot();
    int getNumOfDiscs() const;
    void setNumOfDiscs(const int n);
    void operator++(int);
    void operator++();
    void operator--(int);
    void operator--();
private:
    const int DISC_NUM_AT_START = 4;
    int discs;
};


#endif

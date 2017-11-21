#ifndef _SLOT_H
#define _SLOT_H

class Slot
{
public:
    Slot();                 //c'tor
    Slot(const Slot &s);    //copy c'tor
    ~Slot();                //d'tor
    int getNumOfDiscs() const;
    void setNumOfDiscs(const int n);
    void operator++(int);   //inc number of discs
    void operator++();      //inc number of discs
    void operator--(int);   //dec number of discs
    void operator--();      //dec number of discs
private:
    const int DISC_NUM_AT_START = 4;
    int discs;  //number of discs in slot
};


#endif

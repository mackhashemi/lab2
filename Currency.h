/** @file Currency.h */
#ifndef _CURRENCY_H
#define _CURRENCY_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

typedef enum {
    INVALID,  // used for uninitialized objects

    US_DOLLAR,
    EURO,
    POUND,
    CA_DOLLAR,
    AUS_DOLLAR,
    BITCOIN,
    YUAN,
    RUPEE,
    PESO,
    FRANC,

    MAX_CURRENCY_TYPE, // includes INVALID

} e_currency_type;


// Table of names for currency and fractions
typedef struct {
    e_currency_type c;
    string symbol;
    string name_whole;
    string name_fract;
} currency_name_t;


// table to use for displaying various attributes for each currency
currency_name_t currency_name[MAX_CURRENCY_TYPE] = {
    {INVALID,    "     x ",       "xxxx",   "xxxx"},
    {US_DOLLAR,  "USD  $ ",       "Dollar", "cent"},
    {EURO,       "     \u20AC ",  "Euro",   "cent"},
    {POUND,      "     \u00A3 ",  "Pound",  "pence"},
    {CA_DOLLAR,  "CAD  $ ",       "Dollar", "cent"},
    {AUS_DOLLAR, "AUD  $ ",       "Dollar", "cent"},
    {BITCOIN,    "BTC    ",       "BTC",    "mBTC"},
    {YUAN,       "YUAN   ",       "Yuan",   "Fen"},
    {RUPEE,      "     \u20B9 ",  "Rupee",  "Pie"},
    {PESO,       "     \u20B1 ",  "Peso",   "Real"},
    {FRANC,      "     \u20A3 ",  "Franc",  "Centime"}
};

class Currency {

private:

    e_currency_type type;
    int whole;
    int fract;

public:

    // Default constructor
    Currency();

    // Parametrized constructor
    Currency(const e_currency_type in_type,
             const int in_whole, const int in_fract);

    // Overloaded operators
    Currency operator =(const Currency &right);
    Currency operator +(const Currency &right);
    Currency operator +=(const Currency &right);
    Currency operator -(const Currency &right);
    Currency operator -=(const Currency &right);
    friend ostream &operator << (ostream &output, const Currency &c);

    // other methods
    bool isValid() const;
    bool isSameType(const Currency c);

}; // class Currency

#include "Currency.cpp"

#endif // _CURRENCY_H

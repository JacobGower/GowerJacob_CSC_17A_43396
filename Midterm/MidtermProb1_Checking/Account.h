/* 
 * File:   Account.h
 * Author: Jacob Gower
 *
 * Created on April 26, 2021, 9:23 PM
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H
struct Account{
    //Include size for dynamic arrays in the structure so they can be passed
    //between functions
    int     chckSze,      //Size for the Checks Array
            dpstSze;      //Size for the Deposit Array
    string     name,      //String to hold User Name
            address;      //String to hold User Address
    string  acctNum;      //Static Character Array to hold Account Number
    float    ogBlnc,      //Starting balance for the Account
            newBlnc,      //New Balance after withdrawals and deposits
            *checks,      //Dynamic pointer to Array for one month's checks
             *dpsts;      //Dynamic pointer to Array for one month's deposits
};



#endif /* ACCOUNT_H */


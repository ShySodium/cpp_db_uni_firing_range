#ifndef iostream
#include <iostream>
#endif

#ifndef vector
#include <vector>
#endif

#ifndef string
#include <string>
#endif

#include "./class.h"


#pragma once

using namespace std;

#define print_var_name(x) cout<< (#x)
#define return_var_name(x) (#x)

int search_symbol()
{
    int choice;
    cout<< "1. Search by" << endl;
    cout<< "2. Search <" << endl;
    cout<< "3. Search >" << endl;
    cout<< "Select: "; cin>> choice;
    return choice;
}

/*
template<typename vec_type, typename target_type>
void search_record(vector<vec_type> vec, string target_var, int target_symbol, target_type target_value)
{
    if (target_symbol == 1)
    {
        for (auto x: vec)
        {
            if (return_var_name(x.search_for_var_type(target_value)) == typeid(target_value).name())
            {
                if (x.search_for_var(target_var) == target_value)
                {
                    x.print_header();
                    cout<< endl;
                    x.print_class();
                }
            }
        }
    }
}
*/

vector<string> split_str(string target, char delim)
{
    vector<string> vec;
    vec.clear();
    string temp;
    for (int i=0; i<target.length(); i++)
    {
        if (target[i] != delim)
        {
            temp += target[i];
        }
        else
        {
            vec.push_back(temp);
            temp = "";
        }
        if (i + 1 == target.length())
        {
            vec.push_back(temp);
        }
    }
    return vec;
}

/*
    // Checks if first date given is earlier than the second date
    // Date format DD.MM.YYYY stored in a string vector
*/
bool date_earlier(vector<string> date_a, vector<string> date_b)
{
    if (date_a[2] < date_b[2]) // if first date has lower year, true
    {
        return true;
    }
    if (date_a[2] == date_b[2]) // if years are equal
    {
        if (date_a[1] < date_b[1]) // if first date has lower month, ture
        {
            return true;
        }
        if (date_a[1] == date_b[1]) // if months are equal
        {
            if (date_a[0] < date_b[0]) // if first date has lower day, true
            {
                return true;
            }
        }
    }
    return false; // if above conditions fail, first date is either equal or later than second date
}

/*
    // Check if first time given is earlier than the second time
    // Time format is HH:MM:SS stored in a string vector
*/
bool time_earlier(vector<string> time_a, vector<string> time_b)
{
    if (time_a[0] < time_b[0]) // if first time has lower hour, true
    {
        return true;
    }
    if (time_a[0] == time_b[0]) // if hours are equal
    {
        if (time_a[1] < time_b[1]) // if first time has lower minute, true
        {
            return true;
        }
        if (time_a[1] == time_b[1]) // if minutes are equal
        {
            if (time_a[2] < time_b[2]) // if first time has lower second, true
            {
                return true;
            }
        }
    }
    return false; // if above conditions fial, first time is either equal or later than second time
}
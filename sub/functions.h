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

/*
    Returns the type of operation via which the user wants to search for database records
*/
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

/*
    // Splits string using a given delimiter
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

/*
    // Returns the length of longest entry in the given column
*/

/*
template<typename vec_type>
int max_length_table_string(vector<vec_type> vec, string var)
{
    int max = 0;
    if (var == "name")
    {
        for (auto x: vec)
        {
            if (x.name.length() > max) max = x.name.length();
        }
        return max;
    }
    if (var == "first_name")
    {
        for (auto x: vec)
        {
            if (x.first_name.length() > max) max = x.first_name.length();
        }
    }
}
*/
/*
int max_length_caliber_string(vector<Caliber> caliber, string var)
{
    int max = 0;
    if (var == "name")
    {
        for (auto x: caliber)
        {
            if (x.name.length() > max) max = x.name.length();
        }
        return max;
    }
}
*/
/*
    // Checks if given string is correctly formated for database entry
*/
/*
template<typename vec_type>
bool string_correct(vector<vec_type> vec, string str, string var)
{
    if (str == "")
    {
        cout<< "Input can't be empty" << endl;
        return false;
    }
    for (int i=0; i<str.length(); i++)
    {
        if (str[i] == ' ')
        {
            cout<< "Input can't have empty spaces, use '_' instead" << endl;
            return false;
        }

    }
    int max_length = max_length_table_string(vec, var);
    if (str.length() > max_length)
    {
        cout<< "Input too long, max length " << max_length << endl;
        return false;
    }
    return true;
}
*/
/*
    // Normalizes string for database entry
    // Max length is the length of the longest
    // entry in given column
*/
/*
template<typename vec_type>
string normalize_string_caliber(vector<vec_type> vec, string name, string var)
{
    int target_length = max_length_table_string(vec, var);
    while (name.length() < target_length)
    {
        name += '*';
    }
    return name;
}
*/

/*
    // Returns max length of given Caliber column
*/
int string_max_length_caliber(vector<Caliber> caliber, string var)
{
    int max_length = 0;
    if (var == "name")
    {
        for (auto x: caliber)
        {
            if (x.name.length() > max_length)
            {
                max_length = x.name.length();
            }
        }
    }
    return max_length;
}

/*
    // Normalizes given string for database entry into Caliber table
*/
string normalize_string_caliber(vector<Caliber> caliber, string str, string var)
{
    int max_length = string_max_length_caliber(caliber, var);
    while (str.length() < max_length)
    {
        str += '*';
    }
    return str;
}

/*
    Check if string is correctly inputed for database entry into Caliber table
*/
bool string_correct_caliber(vector<Caliber> caliber, string str, string var)
{
    if (str == "")
    {
        cout<< "Input can't be empty" << endl;
        return false;
    }
    for (int i=0; i<str.length(); i++)
    {
        if (str[i] == ' ')
        {
            cout<< "Input can't have empty spaces, use '_' instead" << endl;
            return false;
        }
    }
    int max_length = string_max_length_caliber(caliber, var);
    if (str.length() > max_length)
    {
        cout<< "Input too long, max length " << max_length << endl;
        return false;
    }
    return true;
}

/*
    // Checks if price given in string is correctly formated
    // Works for float, should also work for int
*/
bool price_correct(string price)
{
    if (price[0] == '-' && price.length() > 1)
    {
        cout<< "Price can't be negative"<< endl;
        return false;
    }
    bool found_period = false;
    for (int i=0; i<price.length(); i++)
    {
        if (price[i] == '.' && found_period)
        {
            cout<< "Price can't have multiple periods" << endl;
            return false;
        } 
        if (price[i] == '.' && !found_period)
        {
            found_period = true;
        }

        if ((price[i] < '0' || price[i] > '9') && price[i] != '.')
        {
            cout<< "Price must be a number" << endl;
            return false;
        }
    }
    return true;
}


/*
    // Returns max length of given Caliber column
*/
int string_max_length_client(vector<Client> client, string var)
{
    int max_length = 0;
    if (var == "first_name")
    {
        for (auto x: client)
        {
            if (x.first_name.length() > max_length)
            {
                max_length = x.first_name.length();
            }
        }
    }
    else if (var == "last_name")
    {
        for (auto x: client)
        {
            if (x.last_name.length() > max_length)
            {
                max_length = x.last_name.length();
            }
        }
    }
    else if (var == "phone_dir")
    {
        for (auto x: client)
        {
            if (x.phone_dir.length() > max_length)
            {
                max_length = x.phone_dir.length();
            }
        }
    }
    else if (var == "phone_num")
    {
        for (auto x: client)
        {
            if (x.phone_num.length() > max_length)
            {
                max_length = x.phone_num.length();
            }
        }
    }
    return max_length;
}

/*
    // Normalizes given string for database entry into Client table
*/
string normalize_string_client(vector<Client> client, string str, string var)
{
    int max_length = string_max_length_client(client, var);
    while (str.length() < max_length)
    {
        str += '*';
    }
    return str;
}

/*
    Check if string is correctly inputed for database entry into Client table
*/
bool string_correct_client(vector<Client> client, string str, string var)
{
    if (str == "")
    {
        cout<< "Input can't be empty" << endl;
        return false;
    }
    if (str[0] < 'A' || str[0] > 'Z')
    {
        cout<< "Input must start with a capital letter" << endl;
        return false;
    }
    for (int i=0; i<str.length(); i++)
    {
        if (str[i] == ' ')
        {
            cout<< "Input can't have empty spaces, use '_' instead" << endl;
            return false;
        }
        if (i>0 && (str[i] < 'a' || str[i] > 'z'))
        {
            cout<< "Only the first letter of the input is to be a capital letter" << endl;
            return false;
        }
    }

    int max_length = string_max_length_client(client, var);
    if (str.length() > max_length)
    {
        cout<< "Input too long, max length " << max_length << endl;
        return false;
    }
    return true;
}

/*
    Check if string is correctly inputed for database entry into Client table
*/
bool string_correct_client_phone(string phone, string var)
{
    if (phone == "")
    {
        cout<< "Input can't be empty" << endl;
        return false;
    }
    if (var == "dir")
    {
        if (phone.size() <= 1)
        {
            cout<< "Directional number must be of valid size" << endl;
            return false;
        }
        if (phone.size() > 3)
        {
            cout<< "A maximum of 3 symbols is allowed" << endl;
            return false;
        }
        if (phone[0] != '+')
        {
            cout<< "Directional number must start with with '+'" << endl;
            return false;
        }
        for (int i=1; i<phone.size(); i++)
        {
            if (phone[i] < '0' || phone[i] > '9')
            {
                cout<< "Directional number can only consist of numbers after '+'" << endl;
                return false;
            }
        }
    }
    else if (var == "num")
    {
        if (phone.size() != 9)
        {
            cout<< "Phone number must have 9 numbers" << endl;
            return false;
        }
        for (int i=0; i<9; i++)
        {
            if (phone[i] < '0' || phone[i] > '9')
            {
                cout<< "Only numbers are allowed in phone numbers" << endl;
                return false;
            }
        }
    }
    return true;
}

/*
    Check if string is correctly inputed for database entry into Client table
*/
bool string_correct_client_pesel(string pesel)
{
    if (pesel.size() != 11)
    {
        cout<< "PESEL must have a length of 11" << endl;
        return false;
    }

    for (int i=0; i<11; i++)
    {
        if (pesel[i] < '0' || pesel[i] > '9')
        {
            cout<< "PESEL can only contain numbers" << endl;
            return false;
        }
    }
    return true;
}

/*
    // Returns max length of given Gun column
*/
int string_max_length_gun(vector<Gun> gun, string var)
{
    int max_length = 0;
    if (var == "name")
    {
        for (auto x: gun)
        {
            if (x.name.length() > max_length)
            {
                max_length = x.name.length();
            }
        }
    }
    return max_length;
}

/*
    // Normalizes given string for database entry into Gun table
*/
string normalize_string_gun(vector<Gun> gun, string str, string var)
{
    int max_length = string_max_length_gun(gun, var);
    while (str.length() < max_length)
    {
        str += '*';
    }
    return str;
}

/*
    Check if string is correctly inputed for database entry into Gun table
*/
bool string_correct_gun_name(vector<Gun> gun, string str, string var)
{
    if (str == "")
    {
        cout<< "Input can't be empty" << endl;
        return false;
    }

    for (int i=0; i<str.length(); i++)
    {
        if (str[i] == ' ')
        {
            cout<< "Input can't have empty spaces, use '_' instead" << endl;
            return false;
        }
    }
    int max_length = string_max_length_gun(gun, var);
    if (str.length() > max_length)
    {
        cout<< "Input too long, max length " << max_length << endl;
        return false;
    }
    return true;
}

int string_max_length_manufacturer(vector<Manufacturer> manufacturer)
{
    int max_length = 0;
    for (auto x: manufacturer)
    {
        if (x.name.length() > max_length)
        {
            max_length = x.name.length();
        }
    }
    return max_length;
}

string normalize_string_manufacturer(vector<Manufacturer> manufacturer, string str)
{
    int max_length = string_max_length_manufacturer(manufacturer);
    while (str.length() < max_length)
    {
        str += "*";
    }
    return str;
}

bool string_correct_manufacturer(vector<Manufacturer> manufacturer, string str)
{
    if (str == "")
    {
        cout<< "Input can't be empty" << endl;
        return false;
    }
    int max_length = string_max_length_manufacturer(manufacturer);
    if (str.length() > max_length)
    {
        cout<< "Input too long, max length " << max_length << endl;
        return false; 
    }
    return true;
}

bool string_correct_visit_date(vector<Visit> visit, string str)
{
    if (str.length() != 10)
    {
        cout<< "Date must be 10 symbols long" << endl;
        return false;
    }
    if (str[2] != '.' || str[5] != '.')
    {
        cout<< "Incorrect date format, format is DD.MM.YYYY" << endl;
        return false;
    }
    vector<string> date = split_str(str, '.');
    string day = date[0];
    string month = date[1];
    string year = date[2];
    if (year < "2022")
    {
        cout<< "The firing range wasn't open before 2022" << endl;
        return false;
    }
    if (day < "01") // if day is below 1, false
    {
        cout<< "Day can't go below 1" << endl;
        return false;
    }
    if (month < "01") // if month is below 1, false
    {
        cout<< "Month can't go below 1" << endl;
        return false;
    }
    if (month > "12") // if month is above 12, false
    {
        cout<< "Month can't go above 12" << endl;
        return false;
    }
    if (month == "02") // check for leap year
    {
        int year_int = (int(year[0])-'0')*1000 + (int(year[1])-'0')*100 + (int(year[2])-'0')*10 + int(year[3])-'0';
        cout<< endl << endl << year_int << endl << endl;
        if ((year_int % 4 == 0 && year_int % 100 == 0 && year_int % 400 == 0) || (year_int % 4 == 0 && year_int % 100 != 0)) // leap year
        {
            if (day > "29")
            {
                cout<< "On leap years, the day can't go above 29" << endl;
                return false;
            }
        }
        if (day > "28")
        {
            cout<< "On non-leap years, the day can't go above 28" << endl;
            return false;
        }
    }
    else if (month == "1" || month == "3" || month == "5" || month == "7" || month == "8" || month == "10" || month == "12")
    {
        if (day > "31")
        {
            cout<< "During this month, the day can't go above 31" << endl;
            return false;
        }
    }
    else
    {
        if (day > "30")
        {
            cout<< "During this month, the day can't go above 30" << endl;
            return false;
        }
    }
    return true;
}

bool string_correct_visit_time(vector<Visit> visit, string str)
{
    if (str.length() != 8)
    {
        cout<< "Time must be 8 symbols long" << endl;
        return false;
    }
    if (str[2] != ':' || str[5] != ':')
    {
        cout<< "Incorrect time format, format is HH:MM:SS" << endl;
        return false;
    }   
    vector<string> time = split_str(str, ':');
    string hour = time[0];
    string minute = time[1];
    string second = time[2];
    if (hour < "00" || hour > "24")
    {
        cout<< "Incorrect hour format" << endl;
        return false;
    }
    if (minute < "00" || minute > "60")
    {
        cout<< "Incorrect minute format" << endl;
        return false;
    }
    if (second < "00" || second > "60")
    {
        cout<< "Incorrect second format" << endl;
        return false;
    }
    return true;
}
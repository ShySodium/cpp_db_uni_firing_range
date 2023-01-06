#ifndef iostream
#include <iostream>
#endif

#ifndef string
#include <string>
#endif

#ifndef vector
#include <vector>
#endif

#include "class.h"

using namespace std;

template<typename vec_type>
void print_table(vec_type vec)
{
    vec[0].print_header();
    cout<< endl;
    for (auto x: vec)
    {
        x.print_class();
        cout<< endl;
    }
}

template<typename target_var>
void print_caliber_record(vector<Caliber> caliber, string search_by, int target_symbol, target_var target_value)
{
    caliber[0].print_header();
    cout<< endl;
    for (auto x: caliber)
    {
        switch(target_symbol)
        {
            case 1: // ==
            if (search_by == "id")
            {
                if (x.id == int(target_value))
                {
                    x.print_class();
                    cout<< endl;
                }
            }
            else if (search_by == "name")
            {
                if (x.name == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            }
            else if (search_by == "price")
            {
                if (x.price == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            }
            break;

            case 2: // <
                if (search_by == "id")
                {
                    if (x.id < target_value)
                    {
                        x.print_class();
                        cout<< endl;
                    }
                }   
                else if (search_by == "name")
                {
                    cout<< "Action not supported";
                    cout<< endl;
                    break;
                }
                else if (search_by == "price")
                {
                    if (x.price < target_value)
                    {
                     x.print_class();
                     cout<< endl;
                    }
                }
                break;

            case 3: // >
                if (search_by == "id")
                {
                    if (x.id > target_value)
                    {
                        x.print_class();
                        cout<< endl;
                    }
                }   
                else if (search_by == "name")
                {
                    cout<< "Action not supported";
                    cout<< endl;
                    break;
                }
                else if (search_by == "price")
                {
                    if (x.price > target_value)
                    {
                     x.print_class();
                     cout<< endl;
                    }
                }
                break;
        }
    }
}

void print_caliber_record_id(vector<Caliber> caliber, int target_symbol, int target_value)
{
    caliber[0].print_header();
    cout<< endl;

    for (auto x: caliber)
    {
        switch(target_symbol)
        {
            case 1:
                if (x.id == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
                break;

            case 2:
                if (x.id < target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
                break;
        
            case 3:
                if (x.id > target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
                break;
        }   
    }
}

void print_caliber_record_name(vector<Caliber> caliber, int target_symbol, string target_value)
{
    caliber[0].print_header();
    cout<< endl;
    for (auto x: caliber)
    {
        switch(target_symbol)
        {
            case 1:
                if (x.name == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
        }
    }
}

void print_caliber_record_price(vector<Caliber> caliber, int target_symbol, float target_value)
{
    caliber[0].print_header();
    cout<< endl;

    for (auto x: caliber)
    {
        switch(target_symbol)
        {
            case 1:
                if (x.price == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
                break;

            case 2:
                if (x.price < target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
                break;
        
            case 3:
                if (x.price > target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
                break;
        }   
    }
}

void print_client_record_id(vector<Client> client, int target_symbol, int target_value)
{
    client[0].print_header();
    cout<< endl;

    for (auto x: client)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.id == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 2:
            {
                if (x.id < target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 3:
            {
                if (x.id > target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_client_record_first_name(vector<Client> client, int target_symbol, string target_value)
{
    client[0].print_header();
    cout<< endl;

    for (auto x: client)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.first_name == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_client_record_last_name(vector<Client> client, int target_symbol, string target_value)
{
    client[0].print_header();
    cout<< endl;

    for (auto x: client)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.last_name == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_client_record_pesel(vector<Client> client, int target_symbol, string target_value)
{
    client[0].print_header();
    cout<< endl;

    for (auto x: client)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.pesel == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_caliber_record_phone_dir(vector<Client> client, int target_symbol, string target_value)
{
    client[0].print_header();
    cout<< endl;

    for (auto x: client)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.phone_dir == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_caliber_record_phone_num(vector<Client> client, int target_symbol, string target_value)
{
    client[0].print_header();
    cout<< endl;

    for (auto x: client)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.phone_num == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_gun_record_id(vector<Gun> gun, int target_symbol, int target_value)
{
    gun[0].print_header();
    cout<< endl;

    for (auto x: gun)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.id == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 2:
            {
                if (x.id < target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 3:
            {
                if (x.id > target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_gun_record_name(vector<Gun> gun, int target_symbol, string target_value)
{
    gun[0].print_header();
    cout<< endl;

    for (auto x: gun)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.name == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_gun_record_caliber_id(vector<Gun> gun, int target_symbol, int target_value)
{
    gun[0].print_header();
    cout<< endl;

    for (auto x: gun)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.caliber_id == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_gun_record_manufacturer_id(vector<Gun> gun, int target_symbol, int target_value)
{
    gun[0].print_header();
    cout<< endl;
    
    for (auto x: gun)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.manufacturer_id == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_manufacturer_record_id(vector<Manufacturer> manufacturer, int target_symbol, int target_value)
{
    manufacturer[0].print_header();
    cout<< endl;

    for (auto x: manufacturer)
    {
        switch(target_symbol)
        {
            case 1:
                if (x.id == target_value)
                {
                    x.print_class();
                    cout<< endl;
                } break;

            case 2:
            {
                if (x.id < target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 3:
            {
                if (x.id > target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_manufacturer_record_name(vector<Manufacturer> manufacturer, int target_symbol, string target_value)
{
    manufacturer[0].print_header();
    cout<< endl;

    for (auto x: manufacturer)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.name == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_visit_record_id(vector<Visit> visit, int target_symbol, int target_value)
{
    visit[0].print_header();
    cout<< endl;

    for (auto x: visit)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.id == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 2:
            {
                if (x.id < target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 3:
            {
                if (x.id > target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_visit_record_client_id(vector<Visit> visit, int target_symbol, int target_value)
{
    visit[0].print_header();
    cout<< endl;

    for (auto x: visit)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.client_id == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_visit_record_gun_id(vector<Visit> visit, int target_symbol, int target_value)
{
    visit[0].print_header();
    cout<< endl;

    for (auto x: visit)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.gun_id == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_visit_record_amount_shot(vector<Visit> visit, int target_symbol, int target_value)
{
    visit[0].print_header();
    cout<< endl;

    for (auto x: visit)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.amount_shot == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 2:
            {
                if (x.amount_shot < target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 3:
            {
                if (x.amount_shot > target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_visit_record_accuracy(vector<Visit> visit, int target_symbol, float target_value)
{
    visit[0].print_header();
    cout<< endl;

    for (auto x: visit)
    {
        switch(target_symbol)
        {
            case 1:
            {
                if (x.accuracy == target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 2:
            {
                if (x.accuracy < target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 3:
            {
                if (x.accuracy > target_value)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_visit_record_date(vector<Visit> visit, int target_symbol, string target_value)
{
    vector<string> target_date = split_str(target_value, '.');

    visit[0].print_header();
    cout<< endl;

    for (auto x: visit)
    {
        vector<string> visit_date = split_str(x.date, '.');
        switch(target_symbol)
        {
            case 1:
            {
                if (visit_date == target_date)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 2:
            {
                if (date_earlier(visit_date, target_date))
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 3:
            {
                if (date_earlier(target_date, visit_date))
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_visit_record_time(vector<Visit> visit, int target_symbol, string target_value)
{
    vector<string> target_time = split_str(target_value, ':');

    visit[0].print_header();
    cout<< endl;

    for (auto x: visit)
    {
        vector<string> visit_time = split_str(x.time, ':');
        switch(target_symbol)
        {
            case 1:
            {
                if (visit_time == target_time)
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 2:
            {
                if (time_earlier(visit_time, target_time))
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;

            case 3:
            {
                if (time_earlier(target_time, visit_time))
                {
                    x.print_class();
                    cout<< endl;
                }
            } break;
        }
    }
}

void print_joined_tables_gun(vector<Gun> gun, vector<Manufacturer> manufacturer, vector<Caliber> caliber)
{
    float price;
    cout<< "Gun id\tName\t\t\tCaliber\t\t\tManufacturer\t\t\tPrice" << endl;
    for (auto x: gun)
    {
        cout<< x.id << "\t" << x.name << "\t";
        for (auto y: caliber)
        {
            if (x.caliber_id == y.id)
            {
                cout<< y.name << "\t";
                price = y.price;
                break;
            }
        }
        for (auto z: manufacturer)
        {
            if (x.manufacturer_id == z.id)
            {
                cout<< z.name << "\t";
                break;
            }
        }
        cout<< price << endl;
    }
}

void print_joined_tables_visit(vector<Caliber> caliber, vector<Client> client, vector<Gun> gun, vector<Manufacturer> manufacturer, vector<Visit> visit)
{
    float price;
    cout<< "Visit id\tFirst name\tLast name\tPhone number\tPESEL\t\tTime\t\tDate\t\tGun name\t\tCaliber\t\t\tManufacturer\t\t\tAccuracy\tAmount shot\tPrice" << endl;
    for (auto vis: visit)
    {
        cout<< vis.id << "\t\t";
        for (auto cli: client)
        {
            if (vis.client_id == cli.id)
            {
                cout<< cli.first_name << "\t" << cli.last_name << "\t" << cli.phone_dir << " " << cli.phone_num << "\t" << cli.pesel << "\t";
                break;
            }
        }
        cout<< vis.time << "\t" << vis.date << "\t";
        for (auto gun: gun)
        {
            if (vis.gun_id == gun.id)
            {
                cout<< gun.name << "\t";
                for (auto cal: caliber)
                {
                    if (gun.caliber_id == cal.id)
                    {
                        cout<< cal.name << "\t";
                        price = cal.price;
                        break;
                    }
                }
                for (auto man: manufacturer)
                {
                    if (gun.manufacturer_id == man.id)
                    {
                        cout<< man.name << "\t";
                        break;
                    }
                }
                break;
            }
        }
        cout<< vis.accuracy << "\t\t" << vis.amount_shot << "\t\t" << price;
        cout<< endl;
    }
}
#ifndef iostream
#include <iostream>
#endif

#ifndef string
#include <string>
#endif

#ifndef vector
#include <vector>
#endif

#ifndef fstream
#include <fstream>
#endif

#include "class.h"
#include "functions.h"

using namespace std;

void delete_record_caliber(int target_id, vector<Caliber> &caliber, vector<Gun> gun)
{
    /*
        // Check if caliber is foreign key to existing gun
        // Terminate operation if yes
        // Continue if not
    */
    for (auto x: gun)
    {
        if (x.caliber_id == target_id)
        {
            cout<< "Can't delete caliber that's a foreign key to existing gun" << endl;
            return;
        }
    }

    /*
        // Redo caliber vector without deleted record
    */
    fstream file;
    string path = "./db/caliber.txt";
    file.open(path.c_str(), ios::in);
    caliber.clear();
    while (!file.eof())
    {
        int id;
        file>> id;

        string name;
        file>> name;

        float price;
        file>> price;

        if (id != target_id)
        {
            Caliber temp(id, name, price);
            caliber.push_back(temp);
        }
    }
    file.close();

    /*
        // Output redone vector into file
    */
    file.open(path.c_str(), ios::out);
    int counter = 1;
    for (auto x: caliber)
    {
        if (counter++ != caliber.size())
        {
            file<< x.id << "\t" << x.name << "\t" << x.price << endl;
        }
        else
        {
            file<< x.id << "\t" << x.name << "\t" << x.price;
        }
    }
    file.close();

    cout<< "Record with id " << target_id << " deleted" << endl;
}

void delete_record_client(int target_id, vector<Client> &client)
{
    /*
        // Redo client vector without deleted record
    */
    fstream file;
    string path = "./db/client.txt";
    file.open(path.c_str(), ios::in);
    client.clear();
    while(!file.eof())
    {
        int id;
        file>> id;

        string first_name;
        file>> first_name;

        string last_name;
        file>> last_name;

        string pesel;
        file>> pesel;

        string phone_dir;
        file>> phone_dir;

        string phone_num;
        file>> phone_num;

        if (id != target_id)
        {
            Client temp(id, first_name, last_name, pesel, phone_dir, phone_num);
            client.push_back(temp);
        }
    }
    file.close();

    /*
        Output redone vector into file
    */
    file.open(path.c_str(), ios::out);
    int counter = 1;
    for (auto x: client)
    {
        if (counter++ != client.size())
        {
            file<< x.id << "\t" << x.first_name << "\t" << x.last_name << "\t" << x.pesel << "\t" << x.phone_dir << "\t" << x.phone_num << endl;
        }
        else
        {
            file<< x.id << "\t" << x.first_name << "\t" << x.last_name << "\t" << x.pesel << "\t" << x.phone_dir << "\t" << x.phone_num;
        }
    }

    cout<< "Record with id " << target_id << " deleted" << endl;
}

void delete_record_gun(int target_id, vector<Gun> &gun)
{
    /*
        Redo gun vector without deleted record
    */
    fstream file;
    string path = "./db/gun.txt";
    file.open(path.c_str(), ios::in);
    gun.clear();
    while(!file.eof())
    {
        int id;
        file>> id;

        string name;
        file>> name;

        int caliber_id;
        file>> caliber_id;

        int manufacturer_id;
        file>> manufacturer_id;

        if (id != target_id)
        {
            Gun temp(id, name, caliber_id, manufacturer_id);
            gun.push_back(temp);
        }
    }
    file.close();

    /*
        Output redone vector into file
    */
    file.open(path, ios::out);
    int counter = 1;
    for (auto x: gun)
    {
        if (counter++ != gun.size())
        {
            file<< x.id << "\t" << x.name << "\t" << x.caliber_id << "\t" << x.manufacturer_id << endl;
        }
        else
        {
            file<< x.id << "\t" << x.name << "\t" << x.caliber_id << "\t" << x.manufacturer_id;
        }
    }

    cout<< "Record with id " << target_id << " deleted" << endl;
}

void delete_record_manufacturer(int target_id, vector<Manufacturer> &manufacturer)
{
    /*
        Redo manufacturer vector without deleted record
    */
    fstream file;
    string path = "./db/manufacturer.txt";
    file.open(path.c_str(), ios::in);
    manufacturer.clear();
    while(!file.eof())
    {
        int id;
        file>> id;

        string name;
        file>> name;

        if (id != target_id)
        {
            Manufacturer temp(id, name);
            manufacturer.push_back(temp);
        }
    }
    file.close();

    /*
        // Output redone vector to file
    */
    file.open(path, ios::out);
    int counter = 1;
    for (auto x: manufacturer)
    {
        if (counter++ != manufacturer.size())
        {
            file<< x.id << "\t" << x.name << endl;
        }
        else
        {
            file<< x.id << "\t" << x.name;
        }
    }

    cout<< "Record with id " << target_id << " deleted" << endl;
}

void delete_record_visit(int target_id, vector<Visit> &visit)
{
    /*
        Redo visit vector without deleted record
    */
    fstream file;
    string path = "./db/visit.txt";
    file.open(path.c_str(), ios::in);
    visit.clear();
    while(!file.eof())
    {
        int id;
        file>> id;

        int client_id;
        file>> client_id;

        int gun_id;
        file>> gun_id;

        int amount_shot;
        file>> amount_shot;

        float accuracy;
        file>> accuracy;

        string date;
        file>> date;

        string time;
        file>> time;

        if (id != target_id)
        {
            Visit temp(id, client_id, gun_id, amount_shot, accuracy, date, time);
            visit.push_back(temp);
        }
    }
    file.close();

    /*
        // Output redone vector to file
    */
    file.open(path, ios::out);
    int counter = 1;
    for (auto x: visit)
    {
        if (counter++ != visit.size())
        {
            file<< x.id << "\t" << x.client_id << "\t" << x.gun_id << "\t" << x.amount_shot << "\t" << x.accuracy << "\t" << x.date << "\t" << x.time << endl;
        }
        else
        {
            file<< x.id << "\t" << x.client_id << "\t" << x.gun_id << "\t" << x.amount_shot << "\t" << x.accuracy << "\t" << x.date << "\t" << x.time;
        }
    }

    cout<< "Record with id " << target_id << " deleted" << endl;
}
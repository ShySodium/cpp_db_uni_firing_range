#ifndef iostream
#include <iostream>
#endif

#ifndef fstream
#include <fstream>
#endif

#ifndef vector
#include <vector>
#endif

#ifndef string
#include <string>
#endif

#include "class.h"


using namespace std;

/*
    //Reads the 
*/
void read_file_to_caliber_vec(string path, vector<Caliber> &caliber)
{
    fstream file;
    file.open(path, ios::in);
    if (!file.good())
    {
        cout<< "Error reading file";
        caliber.clear();
        file.close();
    }
    else
    {
        while (!file.eof())
        {
            int id;
            file>> id;

            string name;
            file>> name;

            float price;
            file>> price;

            Caliber temp(id, name, price);
            caliber.push_back(temp);
        }
        file.close();
    } 
}

void read_file_to_client_vec(string path, vector<Client> &client)
{
    fstream file;
    file.open(path, ios::in);
    if (!file.good())
    {
        cout<< "Error reading file";
        client.clear();
        file.close();
    }
    else
    {
        while (!file.eof())
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

            Client temp(id, first_name, last_name, pesel, phone_dir, phone_num);
            client.push_back(temp);
        }
        file.close();
    }
}

void read_file_to_gun_vec(string path, vector<Gun> &gun)
{
    fstream file;
    file.open(path, ios::in);
    if (!file.good())
    {
        cout<< "Error reading file";
        gun.clear();
        file.close();
    }

    else
    {
        while (!file.eof())
        {
            int id;
            file>> id;

            string name;
            file>> name;

            int caliber_id;
            file>> caliber_id;

            int manufacturer_id;
            file>> manufacturer_id;

            Gun temp(id, name, caliber_id, manufacturer_id);
            gun.push_back(temp);
        }
        file.close();
    }
}

void read_file_to_manufacturer_vec(string path, vector<Manufacturer> &manufacturer)
{
    fstream file;
    file.open(path, ios::in);
    if (!file.good())
    {
        cout<< "Error reading file";
        manufacturer.clear();
        file.close();
    }
    else
    {
        while (!file.eof())
        {
            int id;
            file>> id;

            string name;
            file>> name;

            Manufacturer temp(id, name);
            manufacturer.push_back(temp);
        }
        file.close();
    }
}

void read_file_to_visit_vec(string path, vector<Visit> &visit)
{
    fstream file;
    file.open(path, ios::in);
    if (!file.good())
    {
        cout<< "Error reading file";
        visit.clear();
        file.close();
    }
    else
    {
        while (!file.eof())
        {
            int id;
            file>> id;

            int cliend_id;
            file>> cliend_id;

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

            Visit temp(id, cliend_id, gun_id, amount_shot, accuracy, date, time);
            visit.push_back(temp);
        }
        file.close();
    }
}
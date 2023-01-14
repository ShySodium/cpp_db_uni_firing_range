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

void modify_record_caliber(int target_id, string name, float price, vector<Caliber> &caliber)
{
    fstream file;
    string path = "./db/caliber.txt";
    file.open(path.c_str(), ios::out);
    for (int i=0; i<caliber.size(); i++)
    {
        if (caliber[i].id == target_id)
        {
            caliber[i].print_header();
            cout<< endl << "OLD: "; caliber[i].print_class();
            caliber[i].name = name;
            caliber[i].price = price;
            cout<< endl << "NEW: "; caliber[i].print_class();
            cout<< endl;
        }
        file<< "\n" << caliber[i].id << "\t" << caliber[i].name << "\t" << caliber[i].price;
    }
    file.close();
}

void modify_record_client(int target_id, string first_name, string last_name, string pesel, string phone_dir, string phone_num, vector<Client> &client)
{
    fstream file;
    string path = "./db/client.txt";
    file.open(path.c_str(), ios::out);
    for (int i=0; i<client.size(); i++)
    {
        if (client[i].id == target_id)
        {
            client[i].print_header();
            cout<< endl << "OLD: "; client[i].print_class();
            client[i].first_name = first_name;
            client[i].last_name = last_name;
            client[i].pesel = pesel;
            client[i].phone_dir = phone_dir;
            client[i].phone_num = phone_num;
            cout<< endl << "NEW: "; client[i].print_class();
            cout<< endl;
        }
        file<< "\n" << client[i].id << "\t" << client[i].first_name << "\t" << client[i].last_name << "\t" << client[i].pesel << "\t" << client[i].phone_dir << "\t" << client[i].phone_num;
    }
    file.close();
}

void modify_record_gun(int target_id, string name, int caliber_id, int manufacturer_id, vector<Gun> &gun)
{
    fstream file;
    string path = "./db/gun.txt";
    file.open(path.c_str(), ios::out);
    for (int i=0; i<gun.size(); i++)
    {
        if (gun[i].id == target_id)
        {
            gun[i].print_header();
            cout<< endl << "OLD: "; gun[i].print_class();
            gun[i].name = name;
            gun[i].caliber_id = caliber_id;
            gun[i].manufacturer_id = manufacturer_id;
            cout<< endl << "NEW: "; gun[i].print_class();
            cout<< endl;
        }
        file<< "\n" << gun[i].id << "\t" << gun[i].name << "\t" << gun[i].caliber_id << "\t\t" << gun[i].manufacturer_id;
    }
    file.close();
}

void modify_record_manufacturer(int target_id, string name, vector<Manufacturer> &manufacturer)
{
    fstream file;
    string path = "./db/manufacturer.txt";
    file.open(path.c_str(), ios::out);
    for (int i=0; i<manufacturer.size(); i++)
    {
        if (manufacturer[i].id == target_id)
        {
            manufacturer[i].print_header();
            cout<< endl << "OLD: "; manufacturer[i].print_class();
            manufacturer[i].name = name;
            cout<< endl << "NEW: "; manufacturer[i].print_class();
            cout<< endl;
        }
        file<< "\n" << manufacturer[i].id << "\t" << manufacturer[i].name;
    }
    file.close();
}

void modify_record_visit(int target_id, int client_id, int gun_id, int amount_shot, float accuracy, string date, string time, vector<Visit> &visit)
{
    fstream file;
    string path = "./db/visit.txt";
    file.open(path.c_str(), ios::out);
    for (int i=0; i<visit.size(); i++)
    {
        if (visit[i].id == target_id)
        {
            visit[i].print_header();
            cout<< endl << "OLD: "; visit[i].print_class();
            visit[i].client_id = client_id;
            visit[i].gun_id = gun_id;
            visit[i].amount_shot = amount_shot;
            visit[i].accuracy = accuracy;
            visit[i].date = date;
            visit[i].time = time;
            cout<< endl << "NEW: "; visit[i].print_class();
            cout<< endl;
        }
        file<< "\n" << visit[i].id << "\t" << visit[i].client_id << "\t" << visit[i].gun_id << "\t" << visit[i].amount_shot << "\t" << visit[i].accuracy << "\t" << visit[i].date << "\t" << visit[i].time;
    }
    file.close();
}
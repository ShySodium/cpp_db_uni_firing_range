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

void add_record_caliber(int id, string name, float price, vector<Caliber> &caliber)
{
    fstream file;
    string path = "./db/caliber.txt";
    file.open(path.c_str(), ios::app);
    file<< "\n" << id << "\t" << name << "\t" << price;
    file.close();

    Caliber temp(id, name, price);
    caliber.push_back(temp);

    caliber[0].print_header();
    cout<< "\n" << id << "\t" << name << "\t" << price << endl;
    cout<< "Record added" << endl;
}

void add_record_client(int id, string first_name, string last_name, string pesel, string phone_dir, string phone_num, vector<Client> &client)
{
    fstream file;
    string path = "./db/client.txt";
    file.open(path.c_str(), ios::app);
    file<< "\n" << id << "\t" << first_name << "\t" << last_name << "\t" << pesel << "\t" << phone_dir << "\t" << phone_num;
    file.close();

    Client temp(id, first_name, last_name, pesel, phone_dir, phone_num);
    client.push_back(temp);

    client[0].print_header();
    cout<< "\n" << id << "\t" << first_name << "\t" << last_name << "\t" << pesel << "\t" << phone_dir << "\t\t" << phone_num << endl;
    cout<< "Record added" << endl;
}

void add_record_gun(int id, string name, int caliber_id, int manufacturer_id, vector<Gun> &gun)
{
    fstream file;
    string path = "./db/gun.txt";
    file.open(path.c_str(), ios::app);
    file<< "\n" << id << "\t" << name << "\t" << caliber_id << "\t" << manufacturer_id;
    file.close();

    Gun temp(id, name, caliber_id, manufacturer_id);
    gun.push_back(temp);

    gun[0].print_header();
    cout<< "\n" << id << "\t" << name << "\t" << caliber_id << "\t\t" << manufacturer_id << endl;
    cout<< "Record added" << endl;
}

void add_record_manufacturer(int id, string name, vector<Manufacturer> &manufacturer)
{
    fstream file;
    string path = "./db/manufacturer.txt";
    file.open(path.c_str(), ios::app);
    file<< "\n" << id << "\t" << name;
    file.close();

    Manufacturer temp(id, name);
    manufacturer.push_back(temp);

    manufacturer[0].print_header();
    cout<< "\n" << id << "\t" << name << endl;
    cout<< "Record added" << endl;
}

void add_record_visit(int id, int client_id, int gun_id, int amount_shot, float accuracy, string date, string time, vector<Visit> &visit)
{
    fstream file;
    string path = "./db/visit.txt";
    file.open(path.c_str(), ios::app);
    file<< "\n" << id << "\t" << client_id << "\t" << gun_id << "\t" << amount_shot << "\t" << accuracy << "\t" << date << "\t" << time;
    file.close();

    Visit temp(id, client_id, gun_id, amount_shot, accuracy, date, time);
    visit.push_back(temp); 

    visit[0].print_header();
    cout<< "\n" << id << "\t" << client_id << "\t" << gun_id << "\t" << amount_shot << "\t" << accuracy << "\t" << date << "\t" << time << endl;
    cout<< "Record added" << endl;
}
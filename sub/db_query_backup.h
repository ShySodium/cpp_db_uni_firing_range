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
#include "functions.h"
#include "db_load.h"

void backup_create_caliber(vector<Caliber> caliber)
{
    fstream file;
    string path = "./db/backup/user/caliber.txt";
    file.open(path.c_str(), ios::out);
    for (auto x: caliber)
    {
        file<< "\n" << x.id << "\t" << x.name << "\t" << x.price;
    }
    file.close();
    cout<< "Caliber backup created";
}

void backup_create_client(vector<Client> client)
{
    fstream file;
    string path = "./db/backup/user/client.txt";
    file.open(path.c_str(), ios::out);
    for (auto x: client)
    {
        file<< "\n" << x.id << "\t" << x.first_name << "\t" << x.last_name << "\t" << x.pesel << "\t" << x.phone_dir << "\t" << x.phone_num;
    }
    file.close();
    cout<< "Client backup created";
}

void backup_create_gun(vector<Gun> gun)
{
    fstream file;
    string path = "./db/backup/user/gun.txt";
    file.open(path.c_str(), ios::out);
    for (auto x: gun)
    {
        file<< "\n" << x.id << "\t" << x.name << "\t" << x.caliber_id << "\t" << x.manufacturer_id;
    }
    file.close();
    cout<< "Gun backup created";
}

void backup_create_manufacturer(vector<Manufacturer> manufacturer)
{
    fstream file;
    string path = "./db/backup/user/manufacturer.txt";
    file.open(path.c_str(), ios::out);
    for (auto x: manufacturer)
    {
        file<< "\n" << x.id << "\t" << x.name;
    }
    file.close();
    cout<< "Manufacturer backup created";
}

void backup_create_visit(vector<Visit> visit)
{
    fstream file;
    string path = "./db/backup/user/visit.txt";
    file.open(path.c_str(), ios::out);
    for (auto x: visit)
    {
        file<< "\n" << x.id << "\t" << x.client_id << "\t" << x.gun_id << "\t" << x.amount_shot << "\t" << x.accuracy << "\t" << x.date << "\t" << x.time;
    }
    file.close();
    cout<< "Visit backup created";
}

void backup_restore_caliber(vector<Caliber> &caliber, string source)
{
    string path = "./db/backup/" + source + "/caliber.txt";
    caliber.clear();
    read_file_to_caliber_vec(path.c_str(), caliber);

    fstream file;
    path = "./db/caliber.txt";
    file.open(path.c_str(), ios::out);
    for (auto x: caliber)
    {
        file<< "\n" << x.id << "\t" << x.name << "\t" << x.price;
    }
    file.close();
    cout<< "Caliber restored from " << source << " backup";
}

void backup_restore_client(vector<Client> &client, string source)
{
    string path = "./db/backup/" + source + "/client.txt";
    client.clear();
    read_file_to_client_vec(path.c_str(), client);

    fstream file;
    path = "./db/client.txt";
    file.open(path.c_str(), ios::out);
    for (auto x: client)
    {
        file<< "\n" << x.id << "\t" << x.first_name << "\t" << x.last_name << "\t" << x.pesel << "\t" << x.phone_dir << "\t" << x.phone_num;
    }
    file.close();
    cout<< "Client restored from " << source << " backup";
}

void backup_restore_gun(vector<Gun> &gun, string source)
{
    string path = "./db/backup/" + source + "/gun.txt";
    gun.clear();
    read_file_to_gun_vec(path.c_str(), gun);

    fstream file;
    path = "./db/gun.txt";
    file.open(path.c_str(), ios::out);
    for (auto x: gun)
    {
        file<< "\n" << x.id << "\t" << x.name << "\t" << x.caliber_id << "\t" << x.manufacturer_id;
    }
    file.close();
    cout<< "Gun restored from " << source << " backup";
}

void backup_restore_manufacturer(vector<Manufacturer> &manufacturer, string source)
{
    string path = "./db/backup/" + source + "/manufacturer.txt";
    manufacturer.clear();
    read_file_to_manufacturer_vec(path.c_str(), manufacturer);

    fstream file;
    path = "./db/manufacturer.txt";
    file.open(path.c_str(), ios::out);
    for (auto x: manufacturer)
    {
        file<< "\n" << x.id << "\t" << x.name;
    }
    file.close();
    cout<< "Manufacturer restored from " << source << " backup";
}

void backup_restore_visit(vector<Visit> &visit, string source)
{
    string path = "./db/backup/" + source + "/visit.txt";
    visit.clear();
    read_file_to_visit_vec(path.c_str(), visit);

    fstream file;
    path = "./db/visit.txt";
    file.open(path.c_str(), ios::out);
    for (auto x: visit)
    {
        file<< "\n" << x.id << "\t" << x.client_id << "\t" << x.gun_id << "\t" << x.amount_shot << "\t" << x.accuracy << "\t" << x.date << "\t" << x.time;
    }
    file.close();
    cout<< "Visit restored from " << source << " backup";
}
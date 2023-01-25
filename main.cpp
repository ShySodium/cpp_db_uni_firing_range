//Include all the sub files
#include "./sub/functions.h"
#include "./sub/class.h"
#include "./sub/db_load.h"
#include "./sub/db_query_print.h"
#include "./sub/db_query_add.h"
#include "./sub/db_query_delete.h"
#include "./sub/db_query_modify.h"
#include "./sub/db_query_backup.h"

#ifndef iostream
#include <iostream>
#endif

#ifndef vector
#include <vector>
#endif

#ifndef string
#include <string>
#endif

using namespace std;

bool interface(vector<Caliber> &caliber, vector<Client> &client, vector<Gun> &gun, vector<Manufacturer> &manufacturer, vector<Visit> &visit)
{
    cout<< endl;
    cout<<
        "+------------------------+" << endl <<
        "| FIRING RANGE INTERFACE |" << endl <<
        "+------------------------+" << endl;
    int choice;
    cout<< "1. Read table / record" << endl; // done
    cout<< "2. Add record" << endl; // done
    cout<< "3. Delete record" << endl; // done
    cout<< "4. Modify record" << endl; // done
    cout<< "5. Misc queries" << endl;
    cout<< "6. Backup" << endl; // done
    cout<< "7. Credits" << endl; // done
    cout<< "8. Exit" << endl; // done
    cout<< "Select: "; cin>> choice;
    cout<< endl << "+-------------------------+" << endl << endl;

    switch(choice)
    {
        case 1: // read table / record
        {
            int choice;
            cout<< "1. Read all tables" << endl; // done
            cout<< "2. Read specified table" << endl; // done
            cout<< "3. Read specified record" << endl; // done
            cout<< "4. Read joined tables" << endl; // done
            cout<< "5. Go back" << endl; // done
            cout<< "Select: "; cin>> choice;
            cout<< endl << "+-------------------------+" << endl << endl;
            
            switch(choice)
            {
                case 1: // read all tables
                {
                    cout<< "-----------------" << endl;
                    cout<< "Caliber" << endl;
                    print_table(caliber);
                    cout<< "-----------------" << endl;
                    cout<< "Client" << endl;
                    print_table(client);
                    cout<< "-----------------" << endl;
                    cout<< "Gun" << endl;
                    print_table(gun);
                    cout<< "-----------------" << endl;
                    cout<< "Manufacturer" << endl;
                    print_table(manufacturer);
                    cout<< "-----------------" << endl;
                    cout<< "Visit" << endl;
                    print_table(visit);
                    cout<< "-----------------" << endl;
                } break;

                case 2: // read specific table
                {
                    cout<< "1. Caliber" << endl; // done
                    cout<< "2. Client" << endl; // done
                    cout<< "3. Gun" << endl; // done
                    cout<< "4. Manufacturer" << endl; // done
                    cout<< "5. Visit" << endl; // done
                    cout<< "6. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // read caliber
                        {
                            cout<< "-----------------" << endl;
                            print_table(caliber);
                            cout<< "-----------------" << endl;
                        } break;

                        case 2: // read client
                        {
                            cout<< "-----------------" << endl;
                            print_table(client);
                            cout<< "-----------------" << endl;
                        } break;

                        case 3: // read gun
                        {
                            cout<< "-----------------" << endl;
                            print_table(gun);
                            cout<< "-----------------" << endl;
                        } break;

                        case 4: // read manufacturer
                        {
                            cout<< "-----------------" << endl;
                            print_table(manufacturer);
                            cout<< "-----------------" << endl;
                        } break;

                        case 5: // read visit
                        {
                            cout<< "-----------------" << endl;
                            print_table(visit);
                            cout<< "-----------------" << endl;
                        } break;
                        
                        case 6: // read specific table go back
                        {
                            cout<< "Returning..." << endl;
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!" << endl;
                            return true;
                        } break;
                    }
                } break;
                
                case 3: // read specific record
                {
                    cout<< "Search table:" << endl;
                    cout<< "1. Caliber" << endl; // done
                    cout<< "2. Client" << endl; // done
                    cout<< "3. Gun" << endl; // done
                    cout<< "4. Manufacturer" << endl; // done
                    cout<< "5. Visit" << endl; // done
                    cout<< "6. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // read specific record caliber
                        {
                            cout<< "Search Caliber by: " << endl;
                            cout<< "1. Id" << endl; // done
                            cout<< "2. Name" << endl; // done
                            cout<< "3. Price" << endl; // done
                            cout<< "4. Go back" << endl; // done
                            cout<< "Select: "; cin>> choice;
                            cout<< endl << "+-------------------------+" << endl << endl;

                            switch(choice)
                            {
                                case 1: // search caliber by id
                                {
                                    int target_symbol = search_symbol(); // 1 = ==, 2 = <, 3 = >
                                    int target_value_int;
                                    cout<< "Search by id: "; cin>> target_value_int;
                                    //search_record(caliber, "id", target_symbol, target_value);
                                    //print_caliber_record(caliber, "id", target_symbol, target_value_int);
                                    print_caliber_record_id(caliber, target_symbol, target_value_int);
                                } break;

                                case 2: // search caliber by name
                                {
                                    int target_value_int;
                                    string target_value_str;
                                    cout<< "Search by name: " << endl;
                                    int counter = 1;
                                    for (auto x: caliber)
                                    {
                                        cout<< counter++ << ".\t" << x.name << endl;
                                    }
                                    cout<< "Select: "; cin>> target_value_int;
                                    cout<< endl << "+-------------------------+" << endl << endl;
                                    target_value_str = caliber[target_value_int - 1].name;
                                    print_caliber_record_name(caliber, 1, target_value_str);
                                } break;

                                case 3: // search caliber by price
                                {
                                    int target_symbol = search_symbol(); // 1 = ==, 2 = <, 3 = >
                                    float target_value_float;
                                    cout<< "Search by price: "; cin>> target_value_float;
                                    print_caliber_record_price(caliber, target_symbol, target_value_float);
                                } break;

                                case 4: // search caliber by go back
                                {
                                    cout<< "Returning..." << endl;
                                    return true;
                                } break;

                                default:
                                {
                                    cout<< "Unknown value!" << endl;
                                    return true;
                                } break;
                            }
                        } break;

                        case 2: // read specific record client
                        {
                            cout<< "Search Client by: " << endl;
                            cout<< "1. Id" << endl; // done
                            cout<< "2. First name" << endl; // done
                            cout<< "3. Last namee" << endl; // done
                            cout<< "4. PESEL" << endl; // done
                            cout<< "5. Phone directional" << endl; // done
                            cout<< "6. Phone number" << endl; // done
                            cout<< "7. Go back" << endl; // done
                            cout<< "Select: "; cin>> choice;
                            cout<< endl << "+-------------------------+" << endl << endl;

                            switch(choice)
                            {
                                case 1: // search client by id
                                {
                                    int target_symbol = search_symbol(); // 1 = ==, 2 = <, 3 = >
                                    int target_value_int;
                                    cout<< "Search by id: "; cin>> target_value_int;
                                    print_client_record_id(client, target_symbol, target_value_int);
                                } break;

                                case 2: // search client by first name
                                {
                                    string target_value_str;
                                    int target_value_int;
                                    int counter = 1;
                                    for (auto x: client)
                                    {
                                        cout<< counter++ << ".\t" << x.first_name << endl;
                                    }
                                    cout<< "Select: "; cin>> target_value_int;
                                    cout<< endl << "+-------------------------+" << endl << endl;
                                    target_value_str = client[target_value_int - 1].first_name;
                                    print_client_record_first_name(client, 1, target_value_str);
                                } break;

                                case 3: // search client by last name
                                {
                                    string target_value_str;
                                    int target_value_int;
                                    int counter = 1;
                                    for (auto x: client)
                                    {
                                        cout<< counter++ << ".\t" << x.last_name << endl;
                                    }
                                    cout<< "Select: "; cin>> target_value_int;
                                    cout<< endl << "+-------------------------+" << endl << endl;
                                    target_value_str = client[target_value_int - 1].last_name;
                                    print_client_record_last_name(client, 1, target_value_str);
                                } break;

                                case 4: // search client by pesel
                                {
                                    int choice;
                                    string target_value_str;
                                    cout<< "Search by PESEL: "; cin>> target_value_str;
                                    print_client_record_pesel(client, 1, target_value_str);
                                } break;

                                case 5: // search client by phone directional
                                {
                                    string target_value_str;
                                    cout<< "Search by phone directional (i.e. +48): "; cin>> target_value_str;
                                    print_caliber_record_phone_dir(client, 1, target_value_str);
                                } break;

                                case 6: // search client by phone number;
                                {
                                    string target_value_str;
                                    cout<< "Search by phone number (i.e. 111222333): "; cin>> target_value_str;
                                    print_caliber_record_phone_num(client, 1, target_value_str);
                                } break;

                                case 7: // search client go back
                                {
                                    cout<< "Returning..." << endl;
                                    return true;
                                } break;

                                default:
                                {
                                    cout<< "Unknown value!" << endl;
                                    return true;
                                } break;
                            }

                        } break;

                        case 3: // read specific record gun
                        {
                            int choice;
                            cout<< "Search Gun by:" << endl;
                            cout<< "1. Id" << endl; // done
                            cout<< "2. Name" << endl; // done
                            cout<< "3. Caliber" << endl; // done
                            cout<< "4. Manufacturer" << endl; // done
                            cout<< "5. Go back" << endl; // done
                            cout<< "Select: "; cin>> choice;
                            cout<< endl << "+-------------------------+" << endl << endl;

                            switch(choice)
                            {
                                case 1: // search gun by id
                                {
                                    int target_symbol = search_symbol(); // 1 = ==, 2 = <, 3 = >
                                    int target_value_int;
                                    cout<< "Search by id: "; cin>> target_value_int;
                                    print_gun_record_id(gun, target_symbol, target_value_int);
                                } break;

                                case 2: // search gun by name
                                {
                                    int target_value_int;
                                    string target_value_str;
                                    int counter = 1;

                                    for (auto x: gun)
                                    {
                                        cout<< counter++ << ".\t" << x.name << endl;
                                    }
                                    cout<< "Select: "; cin>> target_value_int;
                                    cout<< endl << "+-------------------------+" << endl << endl;
                                    target_value_str = gun[target_value_int - 1].name;
                                    print_gun_record_name(gun, 1, target_value_str);
                                } break;

                                case 3: // search gun by caliber id
                                {
                                    int target_value_int;
                                    int counter = 1;

                                    for (auto x: caliber)
                                    {
                                        cout<< counter++ << ".\t" << x.name << endl;
                                    }
                                    cout<< "Select: "; cin>> target_value_int;
                                    cout<< endl << "+-------------------------+" << endl << endl;
                                    print_gun_record_caliber_id(gun, 1, target_value_int);
                                } break;
                                
                                case 4: // search gun by manufacturer id
                                {
                                    int target_value_int;
                                    int counter = 1;
                                    for (auto x: manufacturer)
                                    {
                                        cout<< counter++ << ".\t" << x.name << endl;
                                    }
                                    cout<< "Select: "; cin>> target_value_int;
                                    cout<< endl << "+-------------------------+" << endl << endl;
                                    print_gun_record_manufacturer_id(gun, 1, target_value_int);
                                } break;

                                case 5: // search gun go back
                                {
                                    cout<< "Returning..." << endl;
                                    return true;
                                } break;

                                default:
                                {
                                    cout<< "Unknown value!" << endl;
                                    return true;
                                } break;
                            }
                        } break;

                        case 4: // read specific record manufacturer
                        {
                            int choice;
                            cout<< "Search Manufacturer by:" << endl;
                            cout<< "1. Id" << endl; // done
                            cout<< "2. Name" << endl; // done
                            cout<< "3. Go back" << endl; // done
                            cout<< "Select: "; cin>> choice;
                            cout<< endl << "+-------------------------+" << endl << endl;

                            switch(choice)
                            {
                                case 1: // search manufacturer by id
                                {
                                    int target_symbol = search_symbol(); // 1 = ==, 2 = <, 3 = >
                                    int target_value_int;
                                    cout<< "Search by id: "; cin>> target_value_int;
                                    print_manufacturer_record_id(manufacturer, target_symbol, target_value_int);
                                } break;

                                case 2: // Search manufacurer by name
                                {
                                    int target_value_int;
                                    string target_value_str;
                                    int counter = 1;

                                    for (auto x: manufacturer)
                                    {
                                        cout<< counter++ << ".\t" << x.name << endl;
                                    }
                                    cout<< "Select: "; cin>> target_value_int;
                                    cout<< endl << "+-------------------------+" << endl << endl;
                                    target_value_str = manufacturer[target_value_int - 1].name;
                                    print_manufacturer_record_name(manufacturer, 1, target_value_str);
                                } break;

                                case 3: // search manufacturer go back
                                {
                                    cout<< "Returning..." << endl;
                                    return true;
                                } break;

                                default:
                                {
                                    cout<< "Unknown value!" << endl;
                                    return true;
                                } break;
                            }
                        } break;

                        case 5: // read specific record visit
                        {
                            int choice;
                            cout<< "Search visit by: " << endl;
                            cout<< "1. Id" << endl; // done
                            cout<< "2. Client id" << endl; // done
                            cout<< "3. Gun id" << endl; // done
                            cout<< "4. Amount shot" << endl; // done
                            cout<< "5. Accuracy" << endl; // done
                            cout<< "6. Date" << endl; // done
                            cout<< "7. Time" << endl; // done
                            cout<< "8. Go back"<< endl; // done
                            cout<< "Select: "; cin>> choice;
                            cout<< endl << "+-------------------------+" << endl << endl;

                            switch(choice)
                            {
                                case 1: // search visit by id
                                {
                                    int target_symbol = search_symbol(); // 1 = ==, 2 = <, 3 = >
                                    int target_value_int;
                                    cout<< "Search by id: "; cin>> target_value_int;
                                    print_visit_record_id(visit, target_symbol, target_value_int);
                                } break;

                                case 2: // search visit by client id
                                {
                                    int target_value_int;
                                    string target_value_str;
                                    int counter = 1;

                                    for (auto x: client)
                                    {
                                        x.print_class();
                                        cout<< endl;
                                    }
                                    cout<< "Select: "; cin>> target_value_int;
                                    cout<< endl << "+-------------------------+" << endl << endl;
                                    print_visit_record_client_id(visit, 1, target_value_int);
                                } break;

                                case 3: // search visit by gun id
                                {
                                    int target_value_int;
                                    int counter = 1;

                                    for (auto x: gun)
                                    {
                                        cout<< counter++ << ".\t" << x.name << endl;
                                    }
                                    cout<< "Select: "; cin>> target_value_int;
                                    cout<< endl << "+-------------------------+" << endl << endl;
                                    print_visit_record_gun_id(visit, 1, target_value_int);
                                } break;

                                case 4: // search visit by amount shot
                                {
                                    int target_symbol = search_symbol(); // 1 = ==, 2 = <, 3 = >
                                    int target_value_int;
                                    cout<< "Search by amount shot: "; cin>> target_value_int;
                                    print_visit_record_amount_shot(visit, target_symbol, target_value_int);
                                } break;

                                case 5: // search visit by accuracy
                                {
                                    int target_symbol = search_symbol(); // 1 = ==, 2 = <, 3 = >
                                    float target_value_float;
                                    cout<< "Search by accuracy (i.e. 0.5 for 50%): "; cin>> target_value_float;
                                    print_visit_record_accuracy(visit, target_symbol, target_value_float);
                                } break;

                                case 6: // search visit by date
                                {
                                    int target_symbol = search_symbol(); // 1 = ==, 2 = <, 3 = >
                                    string target_value_str;
                                    cout<< "Search by date (DD.MM.YYYY): "; cin>> target_value_str;
                                    print_visit_record_date(visit, target_symbol, target_value_str);
                                } break;

                                case 7: // search visit by time
                                {
                                    int target_symbol = search_symbol(); // 1 = ==, 2 = <, 3 = >
                                    string target_value_str;
                                    cout<< "Search by time (HH:MM:SS): "; cin>>target_value_str;
                                    print_visit_record_time(visit, target_symbol, target_value_str);
                                } break;

                                case 8: // search visit go back
                                {
                                    cout<< "Returning..." << endl;
                                    return true;
                                } break;

                                default:
                                {
                                    cout<< "Unknown value!" << endl;
                                    return true;
                                } break;
                            }

                        } break;

                        case 6: // read specific record go back
                        {
                            cout<< "Returning..." << endl;
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!" << endl;
                            return true;
                        } break;
                    }
                } break;

                case 4: // read joined tables
                {
                    int choice;
                    cout<< "Read joined table:" << endl;
                    cout<< "1. Gun" << endl;
                    cout<< "2. Visit" << endl;
                    cout<< "3. Go back" << endl;
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // read joined tables visit
                        {
                            print_joined_tables_gun(gun, manufacturer, caliber);
                        } break;

                        case 2: // read joined tables visit
                        {
                            print_joined_tables_visit(caliber, client, gun, manufacturer, visit);
                        } break;

                        case 3: // read joined tables go back
                        {
                            cout<< "Returning..." << endl;
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!" << endl;
                            return true;
                        } break;
                    }
                }

                case 5: // read table / record go back
                {
                    cout<< "Returning...";
                    return true;
                } break;

                default:
                {
                    cout<< "Unknown value!";
                    return true;
                }
            }
        } break;

        case 2: // add record
        {
            int choice;
            cout<< "Add record to:" << endl;
            cout<< "1. Caliber" << endl; // done
            cout<< "2. Client" << endl; // done
            cout<< "3. Gun" << endl; // done
            cout<< "4. Manufacturer" << endl; // done
            cout<< "5. Visit" << endl; // done
            cout<< "6. Go back" << endl; // done
            cout<< "Select: "; cin>> choice;
            cout<< endl << "+-------------------------+" << endl << endl;

            switch(choice)
            {
                case 1: // add record to caliber
                {
                    string name = "";
                    while(!string_correct_caliber(caliber, name, "name"))
                    {
                        cout<< "Name (BACK to exit): ";
                        cin.sync();
                        getline(cin, name);
                        cout<< endl;
                        if (name == "BACK") return true;
                    }
                    cout<< endl;
                    
                    string price_str = "-1";
                    while (!price_correct(price_str))
                    {
                        cout<< "Price (BACK to exit): ";
                        cin.sync();
                        getline(cin, price_str);
                        cout<< endl;
                        if (price_str == "BACK") return true;
                    }

                    name = normalize_string_caliber(caliber, name, "name");
                    float price = stof(price_str);
                    int id = caliber[caliber.size()-1].id + 1;
                    add_record_caliber(id, name, price, caliber);
                } break;

                case 2: // add record to client
                {
                    string first_name = "";
                    while (!string_correct_client(client, first_name, "first_name"))
                    {
                        cout << "First name (BACK to exit): ";
                        cin.sync();
                        getline(cin, first_name);
                        cout<< endl;
                        if (first_name == "BACK") return true;
                    }
                    cout<< endl;

                    string last_name = "";
                    while (!string_correct_client(client, last_name, "last_name"))
                    {
                        cout<< "Last name (BACK to exit): ";
                        cin.sync();
                        getline(cin, last_name);
                        cout<< endl;
                        if (last_name == "BACK") return true;
                    }
                    cout<< endl;

                    string phone_dir = "";
                    while (!string_correct_client_phone(phone_dir, "dir"))
                    {
                        cout<< "Phone directional (BACK to exit): ";
                        cin.sync();
                        getline(cin, phone_dir);
                        cout<< endl;
                        if (phone_dir == "BACK") return true;
                    }
                    cout<< endl;

                    string phone_num = "";
                    while (!string_correct_client_phone(phone_num, "num"))
                    {
                        cout<< "Phone number (BACK to exit): ";
                        cin.sync();
                        getline(cin, phone_num);
                        cout<< endl;
                        if (phone_num == "BACK") return true;
                    }
                    cout<< endl;

                    string pesel = "";
                    while(!string_correct_client_pesel(pesel))
                    {
                        cout<< "PESEL (BACK to exit): ";
                        cin.sync();
                        getline(cin, pesel);
                        cout<< endl;
                        if (pesel == "BACK") return true;
                    }

                    first_name = normalize_string_client(client, first_name, "first_name");
                    last_name = normalize_string_client(client, last_name, "last_name");
                    phone_dir = normalize_string_client(client, phone_dir, "phone_dir");
                    phone_num = normalize_string_client(client, phone_num, "phone_num");
                    int id = client[client.size()-1].id + 1;
                    add_record_client(id, first_name, last_name, pesel, phone_dir, phone_num, client);
                } break;

                case 3: // add record to gun
                {
                    string name = "";
                    while(!string_correct_gun_name(gun, name, "name"))
                    {
                        cout<< "Gun name (BACK to exit): ";
                        cin.sync();
                        getline(cin, name);
                        cout<< endl;
                        if (name == "BACk") return true;
                    }
                    cout<< endl;

                    int caliber_id = 0;
                    int counter = 1;
                    int max = caliber[caliber.size() - 1].id;
                    while(caliber_id <= 0 || caliber_id > max)
                    {
                        counter = 1;
                        for (auto x: caliber)
                        {
                            cout<< counter++ << ".\t" << x.name << "\t" << x.price << endl;
                        }
                        cout<< "If desired caliber isn't present, go back and add it to the database" << endl;
                        cout<< "Select (0 to exit): "; cin>> caliber_id;
                        cout<< endl;
                        if (caliber_id == 0) return true;
                    }
                    cout<< endl;

                    int manufacturer_id = 0;
                    max = manufacturer[manufacturer.size() - 1].id;
                    while (manufacturer_id <= 0 || manufacturer_id > max)
                    {
                        counter = 1;
                        for (auto x: manufacturer)
                        {
                            cout<< counter++ << ".\t" << x.name << endl;
                        }
                        cout<< "If deisred manufacturer isn't present go back and add them to the database" << endl;
                        cout<< "Select (0 to exit): "; cin>> manufacturer_id;
                        cout<< endl;
                        if (manufacturer_id == 0) return true;
                    }

                    name = normalize_string_gun(gun, name, "name");
                    int id = gun[gun.size() - 1].id + 1;
                    add_record_gun(id, name, caliber_id, manufacturer_id, gun);
                } break;

                case 4: // add record to manufacturer
                {
                    string name = "";
                    while(!string_correct_manufacturer(manufacturer, name))
                    {
                        cout<< "Manufacturer name (BACK to exit): ";
                        cin.sync();
                        getline(cin, name);
                        cout<< endl;
                        if (name == "BACK") return true; 
                    }
                    
                    name = normalize_string_manufacturer(manufacturer, name);
                    int id = manufacturer[manufacturer.size() - 1].id + 1;
                    add_record_manufacturer(id, name, manufacturer);
                } break ;

                case 5: // add record to visit
                {
                    int counter = 1;
                    int client_id = 0;
                    int max = client[client.size() - 1].id;
                    while(client_id <= 0 || client_id > max)
                    {
                        counter = 1;
                        for (auto x: client)
                        {
                            cout<< counter++ << ".\t" << x.first_name << "\t" << x.last_name << "\t" << x.phone_dir << " " << x.phone_num << "\t" << x.pesel << endl;
                        }
                        cout<< "If desired client isn't present, go back and add them to the database" << endl;
                        cout<< "Select (0 to exit): "; cin>> client_id;
                        cout<< endl;
                        if (client_id == 0) return true;
                    }
                    cout<< endl;

                    int gun_id = 0;
                    max = gun[gun.size() - 1].id;
                    while(gun_id <= 0 || gun_id > max)
                    {
                        print_joined_tables_gun(gun, manufacturer, caliber);
                        cout<< "If desired gun isn't present, go back and add it to the database" << endl;
                        cout<< "Select (0 to exit): "; cin>> gun_id;
                        if (gun_id == 0) return true;
                    }
                    cout<< endl;

                    int amount_shot = -1;
                    while(amount_shot < 0)
                    {
                        cout<< "Amount shot can't be negative" << endl;
                        cout<< "Amount shot (-1 to exit): "; cin>> amount_shot;
                        if (amount_shot == -1) return true;
                    }
                    cout<< endl;

                    float accuracy = -1;
                    while((accuracy < 0 || accuracy > 1))
                    {
                        cout<< "Accuracy must be between 0 and 1 (i.e. 0.5 for 50%)" << endl;
                        cout<< "Precision of 2 symbols after period" << endl;
                        cout<< "Accuracy (-1 to exit): "; cin>> accuracy;
                        if (accuracy == -1) return true;
                        string accuracy_str = to_string(accuracy);
                        accuracy_str = accuracy_str.substr(0, 4);
                        if (accuracy_str.length() > 4) accuracy = -1; // to enforce precision limit
                    }
                    cout<< endl;

                    string date = "";
                    while(!string_correct_visit_date(visit, date))
                    {
                        cout<< "Date format DD.MM.YYYY" << endl;
                        cout<< "Date (BACK to exit): ";
                        cin.sync();
                        getline(cin, date);
                        if (date == "BACK") return true;
                    }
                    cout<< endl;

                    string time = "";
                    while(!string_correct_visit_time(visit, time))
                    {
                        cout<< "Time format HH:MM:SS" << endl;
                        cout<< "Time (BACL to exit): ";
                        cin.sync();
                        getline(cin, time);
                        if (time == "BACK") return true;
                    }

                    int id = visit[visit.size() - 1].id + 1;
                    add_record_visit(id, client_id, gun_id, amount_shot, accuracy, date, time, visit);
                } break;

                case 6: // add record go back
                {
                    cout<< "Returning...";
                    return true;
                } break;

                default:
                {
                    cout<< "Unknown value!";
                    return true;
                } break;
            }
        } break;

        case 3: // delete record
        {
            int choice;
            cout<< "Delete record from:" << endl;
            cout<< "1. Caliber" << endl; // done
            cout<< "2. Client" << endl; // done
            cout<< "3. Gun" << endl; // done
            cout<< "4. Manufacturer" << endl; // done
            cout<< "5. Visit" << endl; // done
            cout<< "6. Go back" << endl; // done
            cout<< "Select: "; cin>> choice;
            cout<< endl << "+-------------------------+" << endl << endl;

            switch(choice)
            {
                case 1: // delete record from caliber
                {
                    int choice;
                    cout<< "Delete record from Caliber according to: " << endl;
                    cout<< "1. Manual id input" << endl; // done
                    cout<< "2. List" << endl; // done
                    cout<< "3. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // delete record caliber manual id
                        {
                            int target_id;
                            cout<< "Id to delete (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                            delete_record_caliber(target_id, caliber, gun);
                        } break;

                        case 2: // delete record caliber list
                        {
                            int target_id;
                            for (auto x: caliber)
                            {
                                x.print_class();
                                cout<< endl;
                            }
                            cout<< "Select (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                            delete_record_caliber(target_id, caliber, gun);
                        } break;

                        case 3: // delete record caliber go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }
                } break;

                case 2: // delete record from client
                {
                    int choice;
                    cout<< "Delete record from Client according to: " << endl;
                    cout<< "1. Manual id input" << endl; //done
                    cout<< "2. List" << endl; // done
                    cout<< "3. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // delete record client manual id
                        {
                            int target_id;
                            cout<< "Id to delete (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                            delete_record_client(target_id, client); 
                        } break;

                        case 2: // delete record client list
                        {
                            int target_id;
                            for (auto x: client)
                            {
                                x.print_class();
                                cout<< endl;
                            }
                            cout<< "Select (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                            delete_record_client(target_id, client);
                        } break;

                        case 3: // delete record caliber go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }
                } break;

                case 3: // delete record from Gun
                {
                    int choice;
                    cout<< "Delete record from Gun according to: " << endl;
                    cout<< "1. Manual id input" << endl; // done
                    cout<< "2. List" << endl; // done
                    cout<< "3. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // delete record gun manual id
                        {
                            int target_id;
                            cout<< "Id to delete (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                            delete_record_gun(target_id, gun); 
                        } break;

                        case 2: // delete record gun list
                        {
                            int target_id;
                            print_joined_tables_gun(gun, manufacturer, caliber);
                            cout<< "Select (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                            delete_record_gun(target_id, gun);
                        } break;

                        case 3: // delete record caliber go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }
                } break;

                case 4: // delete record from manufacturer
                {
                    int choice;
                    cout<< "Delete record from Manufacturer according to: " << endl;
                    cout<< "1. Manual id input" << endl; // done
                    cout<< "2. List" << endl; // done
                    cout<< "3. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // delete record manufacturer manual id
                        {
                            int target_id;
                            cout<< "Id to delete (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                            delete_record_manufacturer(target_id, manufacturer); 
                        } break;

                        case 2: // delete record manufacturer list
                        {
                            int target_id;
                            for (auto x: manufacturer)
                            {
                                x.print_class();
                                cout<< endl;
                            }
                            cout<< "Select (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                            delete_record_manufacturer(target_id, manufacturer);
                        } break;

                        case 3: // delete record caliber go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }
                } break ;

                case 5: // delete record from visit
                {
                    int choice;
                    cout<< "Delete record from Visit according to: " << endl;
                    cout<< "1. Manual id input" << endl; // done
                    cout<< "2. List" << endl; // done
                    cout<< "3. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // delete record visit manual id
                        {
                            int target_id;
                            cout<< "Id to delete (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                            delete_record_visit(target_id, visit); 
                        } break;

                        case 2: // delete record visit list
                        {
                            int target_id;
                            print_joined_tables_visit(caliber, client, gun, manufacturer, visit);
                            cout<< "Select (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                            delete_record_visit(target_id, visit);
                        } break;

                        case 3: // delete record visit go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }
                }

                case 6: // delete record go back
                {
                    cout<< "Returning...";
                    return true;
                } break;

                default:
                {
                    cout<< "Unknown value!";
                    return true;
                } break;
            }
        } break;

        case 4 : // modify record
        {
            int choice;
            cout<< "Modify record from:" << endl;
            cout<< "1. Caliber" << endl; // done
            cout<< "2. Client" << endl; // done
            cout<< "3. Gun" << endl; // done
            cout<< "4. Manufacturer" << endl; // done
            cout<< "5. Visit" << endl;
            cout<< "6. Go back" << endl; // done
            cout<< "Select: "; cin>> choice;
            cout<< endl << "+-------------------------+" << endl << endl;

            switch(choice)
            {
                case 1: // modify record caliber
                {
                    int choice, target_id = 0;
                    cout<< "Modify record from Client according to: " << endl;
                    cout<< "1. Manual id input" << endl; // done
                    cout<< "2. List" << endl; // done
                    cout<< "3. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // modify record caliber manual id
                        {
                            cout<< "Id to modify (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                        } break;

                        case 2: // modify record caliber list
                        {
                            for (auto x: caliber)
                            {
                                x.print_class();
                                cout<< endl;
                            }
                            cout<< "Select (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                        } break;

                        case 3: // modify record caliber go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }

                    string name;
                    float price;
                    for (auto x: caliber)
                    {
                        if (x.id == target_id)
                        {
                            name = x.name;
                            price = x.price;
                            break;
                        }
                    }

                    cout<< "Select field to modify:" << endl;
                    cout<< "1. All" << endl; // done
                    cout<< "2. Name" << endl; // done
                    cout<< "3. Price" << endl; // done
                    cout<< "4. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // modify field caliber all
                        {
                            string name = "";
                            while(!string_correct_caliber(caliber, name, "name"))
                            {
                                cout<< "Name (BACK to exit): ";
                                cin.sync();
                                getline(cin, name);
                                cout<< endl;
                                if (name == "BACK") return true;
                            }
                            cout<< endl;
                    
                            string price_str = "-1";
                            while (!price_correct(price_str))
                            {
                                cout<< "Price (BACK to exit): ";
                                cin.sync();
                                getline(cin, price_str);
                                cout<< endl;
                                if (price_str == "BACK") return true;
                            }

                            name = normalize_string_caliber(caliber, name, "name");
                            float price = stof(price_str);
                            modify_record_caliber(target_id, name, price, caliber);
                        } break;

                        case 2: // modify field caliber name
                        {
                            name = "";
                            while(!string_correct_caliber(caliber, name, "name"))
                            {
                                cout<< "Name (BACK to exit): ";
                                cin.sync();
                                getline(cin, name);
                                cout<< endl;
                                if (name == "BACK") return true;
                            }

                            name = normalize_string_caliber(caliber, name, "name");
                            modify_record_caliber(target_id, name, price, caliber);
                        } break;

                        case 3: // modify field caliber price
                        {
                            string price_str = "-1";
                            while (!price_correct(price_str))
                            {
                                cout<< "Price (BACK to exit): ";
                                cin.sync();
                                getline(cin, price_str);
                                cout<< endl;
                                if (price_str == "BACK") return true;
                            }

                            price = stof(price_str);
                            modify_record_caliber(target_id, name, price, caliber);
                        }

                        case 4: // modify field caliber go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }
                } break;

                case 2: // modify record client
                {
                    int choice, target_id = 0;
                    cout<< "Modify record from Client according to: " << endl;
                    cout<< "1. Manual id input" << endl; //done
                    cout<< "2. List" << endl; // done
                    cout<< "3. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // modify record client manual id
                        {
                            cout<< "Id to modify (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                        } break;

                        case 2: // modify record client list
                        {
                            for (auto x: client)
                            {
                                x.print_class();
                                cout<< endl;
                            }
                            cout<< "Select (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                        } break;

                        case 3: // modify record client go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }

                    string first_name;
                    string last_name;
                    string pesel;
                    string phone_dir;
                    string phone_num;
                    for (auto x: client)
                    {
                        if (x.id == target_id)
                        {
                            first_name = x.first_name;
                            last_name = x.last_name;
                            pesel = x.pesel;
                            phone_dir = x.phone_dir;
                            phone_num = x.phone_num;
                            break;
                        }
                    }

                    cout<< endl;
                    cout<< "Select field to modify:" << endl;
                    cout<< "1. All" << endl; // done
                    cout<< "2. First name" << endl; // done
                    cout<< "3. Last name" << endl; // done
                    cout<< "4. PESEL" << endl; // done
                    cout<< "5. Phone directional" << endl; // done
                    cout<< "6. Phone number" << endl; // done
                    cout<< "7. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;


                    switch(choice)
                    {
                        case 1: // modify field client all
                        {
                            first_name = "";
                            while (!string_correct_client(client, first_name, "first_name"))
                            {
                                cout << "First name (BACK to exit): ";
                                cin.sync();
                                getline(cin, first_name);
                                cout<< endl;
                                if (first_name == "BACK") return true;
                            }
                            cout<< endl;

                            last_name = "";
                            while (!string_correct_client(client, last_name, "last_name"))
                            {
                                cout<< "Last name (BACK to exit): ";
                                cin.sync();
                                getline(cin, last_name);
                                cout<< endl;
                                if (last_name == "BACK") return true;
                            }
                            cout<< endl;
    
                            phone_dir = "";
                            while (!string_correct_client_phone(phone_dir, "dir"))
                            {
                                cout<< "Phone directional (BACK to exit): ";
                                cin.sync();
                                getline(cin, phone_dir);
                                cout<< endl;
                                if (phone_dir == "BACK") return true;
                            }
                            cout<< endl;

                            phone_num = "";
                            while (!string_correct_client_phone(phone_num, "num"))
                            {
                                cout<< "Phone number (BACK to exit): ";
                                cin.sync();
                                getline(cin, phone_num);
                                cout<< endl;
                                if (phone_num == "BACK") return true;
                            }
                            cout<< endl;

                            pesel = "";
                            while(!string_correct_client_pesel(pesel))
                            {
                                cout<< "PESEL (BACK to exit): ";
                                cin.sync();
                                getline(cin, pesel);
                                cout<< endl;
                                if (pesel == "BACK") return true;
                            }

                            first_name = normalize_string_client(client, first_name, "first_name");
                            last_name = normalize_string_client(client, last_name, "last_name");
                            phone_dir = normalize_string_client(client, phone_dir, "phone_dir");
                            phone_num = normalize_string_client(client, phone_num, "phone_num");
                            modify_record_client(target_id, first_name, last_name, pesel, phone_dir, phone_num, client);
                        } break;

                        case 2: // modify field client first name
                        {
                            first_name = "";
                            while (!string_correct_client(client, first_name, "first_name"))
                            {
                                cout << "First name (BACK to exit): ";
                                cin.sync();
                                getline(cin, first_name);
                                cout<< endl;
                                if (first_name == "BACK") return true;
                            }

                            first_name = normalize_string_client(client, first_name, "first_name");
                            modify_record_client(target_id, first_name, last_name, pesel, phone_dir, phone_num, client);
                        } break;

                        case 3: // modify field client last_name
                        {
                            last_name = "";
                            while (!string_correct_client(client, last_name, "last_name"))
                            {
                                cout<< "Last name (BACK to exit): ";
                                cin.sync();
                                getline(cin, last_name);
                                cout<< endl;
                                if (last_name == "BACK") return true;
                            }

                            last_name = normalize_string_client(client, last_name, "last_name");
                            modify_record_client(target_id, first_name, last_name, pesel, phone_dir, phone_num, client);
                        } break;

                        case 4: // modify field client pesel
                        {
                            pesel = "";
                            while(!string_correct_client_pesel(pesel))
                            {
                                cout<< "PESEL (BACK to exit): ";
                                cin.sync();
                                getline(cin, pesel);
                                cout<< endl;
                                if (pesel == "BACK") return true;
                            }

                            modify_record_client(target_id, first_name, last_name, pesel, phone_dir, phone_num, client);
                        } break;

                        case 5: // modify field client phone directional
                        {
                            phone_dir = "";
                            while (!string_correct_client_phone(phone_dir, "dir"))
                            {
                                cout<< "Phone directional (BACK to exit): ";
                                cin.sync();
                                getline(cin, phone_dir);
                                cout<< endl;
                                if (phone_dir == "BACK") return true;
                            }
                            
                            phone_dir = normalize_string_client(client, phone_dir, "phone_dir");
                            modify_record_client(target_id, first_name, last_name, pesel, phone_dir, phone_num, client);
                        } break;

                        case 6: // modify field client phone number
                        {
                            phone_num = "";
                            while (!string_correct_client_phone(phone_num, "num"))
                            {
                                cout<< "Phone number (BACK to exit): ";
                                cin.sync();
                                getline(cin, phone_num);
                                cout<< endl;
                                if (phone_num == "BACK") return true;
                            }

                            phone_num = normalize_string_client(client, phone_num, "phone_num");
                            modify_record_client(target_id, first_name, last_name, pesel, phone_dir, phone_num, client);
                        } break;
                        case 7: // modify field caliber go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }
                } break;
                
                case 3: // modify record gun
                {
                    int choice, target_id = 0;
                    cout<< "Modify record from Gun according to: " << endl;
                    cout<< "1. Manual id input" << endl; //done
                    cout<< "2. List" << endl; // done
                    cout<< "3. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // modify record gun manual id
                        {
                            cout<< "Id to modify (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                        } break;

                        case 2: // modify record gun list
                        {
                            for (auto x: gun)
                            {
                                x.print_class();
                                cout<< endl;
                            }
                            cout<< "Select (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                        } break;

                        case 3: // modify record gun go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }

                    string name;
                    int caliber_id;
                    int manufacturer_id;
                    for (auto x: gun)
                    {
                        if (x.id == target_id)
                        {
                            name = x.name;
                            caliber_id = x.caliber_id;
                            manufacturer_id = x.manufacturer_id;
                            break;
                        }
                    }

                    cout<< endl;
                    cout<< "Select field to modify:" << endl;
                    cout<< "1. All" << endl; // done
                    cout<< "2. Name" << endl; // done
                    cout<< "3. Caliber" << endl; // done
                    cout<< "4. Manufacturer" << endl; // done
                    cout<< "5. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // modify field gun all
                        {
                            name = "";
                            while(!string_correct_gun_name(gun, name, "name"))
                            {
                                cout<< "Gun name (BACK to exit): ";
                                cin.sync();
                                getline(cin, name);
                                cout<< endl;
                                if (name == "BACk") return true;
                            }
                            cout<< endl;

                            caliber_id = 0;
                            int counter = 1;
                            int max = caliber[caliber.size() - 1].id;
                            while(caliber_id <= 0 || caliber_id > max)
                            {
                                counter = 1;
                                for (auto x: caliber)
                                {
                                    cout<< counter++ << ".\t" << x.name << "\t" << x.price << endl;
                                }
                                cout<< "If desired caliber isn't present, go back and add it to the database" << endl;
                                cout<< "Select (0 to exit): "; cin>> caliber_id;
                                cout<< endl;
                                if (caliber_id == 0) return true;
                            }
                            cout<< endl;

                            manufacturer_id = 0;
                            max = manufacturer[manufacturer.size() - 1].id;
                            while (manufacturer_id <= 0 || manufacturer_id > max)
                            {
                                counter = 1;
                                for (auto x: manufacturer)
                                {
                                    cout<< counter++ << ".\t" << x.name << endl;
                                }
                                cout<< "If deisred manufacturer isn't present go back and add them to the database" << endl;
                                cout<< "Select (0 to exit): "; cin>> manufacturer_id;
                                cout<< endl;
                                if (manufacturer_id == 0) return true;
                            }

                            name = normalize_string_gun(gun, name, "name");
                            modify_record_gun(target_id, name, caliber_id, manufacturer_id, gun);
                        } break;

                        case 2: // modify field gun name
                        {
                            name = "";
                            while(!string_correct_gun_name(gun, name, "name"))
                            {
                                cout<< "Gun name (BACK to exit): ";
                                cin.sync();
                                getline(cin, name);
                                cout<< endl;
                                if (name == "BACk") return true;
                            }

                            name = normalize_string_gun(gun, name, "name");
                            modify_record_gun(target_id, name, caliber_id, manufacturer_id, gun);
                        } break;

                        case 3: // modify field gun caliber_id
                        {
                            caliber_id = 0;
                            int counter = 1;
                            int max = caliber[caliber.size() - 1].id;
                            while(caliber_id <= 0 || caliber_id > max)
                            {
                                counter = 1;
                                for (auto x: caliber)
                                {
                                    cout<< counter++ << ".\t" << x.name << "\t" << x.price << endl;
                                }
                                cout<< "If desired caliber isn't present, go back and add it to the database" << endl;
                                cout<< "Select (0 to exit): "; cin>> caliber_id;
                                cout<< endl;
                                if (caliber_id == 0) return true;
                            }

                            modify_record_gun(target_id, name, caliber_id, manufacturer_id, gun);
                        } break;

                        case 4: // modify field gun manufacturer_id
                        {
                            manufacturer_id = 0;
                            int max = manufacturer[manufacturer.size() - 1].id;
                            int counter;
                            while (manufacturer_id <= 0 || manufacturer_id > max)
                            {
                                counter = 1;
                                for (auto x: manufacturer)
                                {
                                    cout<< counter++ << ".\t" << x.name << endl;
                                }
                                cout<< "If deisred manufacturer isn't present go back and add them to the database" << endl;
                                cout<< "Select (0 to exit): "; cin>> manufacturer_id;
                                cout<< endl;
                                if (manufacturer_id == 0) return true;

                                modify_record_gun(target_id, name, caliber_id, manufacturer_id, gun);
                            }
                        } break;

                        case 5: // modify field gun go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }
                } break;

                case 4: // modify record manufacturer
                {
                    int choice, target_id = 0;
                    cout<< "Modify record from Manufacturer according to: " << endl;
                    cout<< "1. Manual id input" << endl; //done
                    cout<< "2. List" << endl; // done
                    cout<< "3. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // modify record manufacturer manual id
                        {
                            cout<< "Id to modify (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                        } break;

                        case 2: // modify record manufacturer list
                        {
                            for (auto x: manufacturer)
                            {
                                x.print_class();
                                cout<< endl;
                            }
                            cout<< "Select (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                        } break;

                        case 3: // modify record manufacturer go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }

                    cout<< endl;
                    cout<< "Select field to modify:" << endl;
                    cout<< "1. Name" << endl; // done
                    cout<< "2. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // modify record manufacturer name
                        {
                            string name = "";
                            while(!string_correct_manufacturer(manufacturer, name))
                            {
                                cout<< "Manufacturer name (BACK to exit): ";
                                cin.sync();
                                getline(cin, name);
                                cout<< endl;
                                if (name == "BACK") return true; 
                            }
                    
                            name = normalize_string_manufacturer(manufacturer, name);
                            modify_record_manufacturer(target_id, name, manufacturer);
                        } break;

                        case 2: // modify record manufacturer go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }
                } break;

                case 5: // modify record visit
                {
                    int choice, target_id = 0;
                    cout<< "Modify record from Visit according to: " << endl;
                    cout<< "1. Manual id input" << endl; //done
                    cout<< "2. List" << endl; // done
                    cout<< "3. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // modify record visit manual id
                        {
                            cout<< "Id to modify (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                        } break;

                        case 2: // modify record visit list
                        {
                            print_joined_tables_visit(caliber, client, gun, manufacturer, visit);
                            cout<< "Select (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                        } break;

                        case 3: // modify record visit go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }

                    int client_id;
		            int gun_id;
		            int amount_shot;
		            float accuracy;
		            string date;
		            string time;
                    for (auto x: visit)
                    {
                        if (x.id == target_id)
                        {
                            client_id = x.client_id;
                            gun_id = x.gun_id;
                            amount_shot = x.amount_shot;
                            accuracy = x.accuracy;
                            date = x.date;
                            time = x.time;
                        }
                    }

                    cout<< endl;
                    cout<< "Select field to modify:" << endl;
                    cout<< "1. All" << endl; // done
                    cout<< "2. Client" << endl; // done
                    cout<< "3. Gun" << endl; // done
                    cout<< "4. Amount shot" << endl; // done
                    cout<< "5. Accuracy" << endl; // done
                    cout<< "6. Date" << endl; // done
                    cout<< "7. Time" << endl; // done
                    cout<< "8. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // modify field visit all
                        {
                            int counter = 1;
                            client_id = 0;
                            int max = client[client.size() - 1].id;
                            while(client_id <= 0 || client_id > max)
                            {
                                counter = 1;
                                for (auto x: client)
                                {
                                    cout<< counter++ << ".\t" << x.first_name << "\t" << x.last_name << "\t" << x.phone_dir << " " << x.phone_num << "\t" << x.pesel << endl;
                                }
                                cout<< "If desired client isn't present, go back and add them to the database" << endl;
                                cout<< "Select (0 to exit): "; cin>> client_id;
                                cout<< endl;
                                if (client_id == 0) return true;
                            }
                            cout<< endl;

                            gun_id = 0;
                            max = gun[gun.size() - 1].id;
                            while(gun_id <= 0 || gun_id > max)
                            {
                                print_joined_tables_gun(gun, manufacturer, caliber);
                                cout<< "If desired gun isn't present, go back and add it to the database" << endl;
                                cout<< "Select (0 to exit): "; cin>> gun_id;
                                if (gun_id == 0) return true;
                            }
                            cout<< endl;

                            amount_shot = -1;
                            while(amount_shot < 0)
                            {   
                                cout<< "Amount shot can't be negative" << endl;
                                cout<< "Amount shot (-1 to exit): "; cin>> amount_shot;
                                if (amount_shot == -1) return true;
                            }
                            cout<< endl;

                            accuracy = -1;
                            while((accuracy < 0 || accuracy > 1))
                            {
                                cout<< "Accuracy must be between 0 and 1 (i.e. 0.5 for 50%)" << endl;
                                cout<< "Precision of 2 symbols after period" << endl;
                                cout<< "Accuracy (-1 to exit): "; cin>> accuracy;
                                if (accuracy == -1) return true;
                                string accuracy_str = to_string(accuracy);
                                accuracy_str = accuracy_str.substr(0, 4);
                                if (accuracy_str.length() > 4) accuracy = -1; // to enforce precision limit
                            }
                            cout<< endl;

                            date = "";
                            while(!string_correct_visit_date(visit, date))
                            {
                                cout<< "Date format DD.MM.YYYY" << endl;
                                cout<< "Date (BACK to exit): ";
                                cin.sync();
                                getline(cin, date);
                                if (date == "BACK") return true;
                            }
                            cout<< endl;

                            time = "";
                            while(!string_correct_visit_time(visit, time))
                            {
                                cout<< "Time format HH:MM:SS" << endl;
                                cout<< "Time (BACL to exit): ";
                                cin.sync();
                                getline(cin, time);
                                if (time == "BACK") return true;
                            }

                            modify_record_visit(target_id, client_id, gun_id, amount_shot, accuracy, date, time, visit);
                        } break;

                        case 2: // modify field visit client_id
                        {
                            int counter = 1;
                            client_id = 0;
                            int max = client[client.size() - 1].id;
                            while(client_id <= 0 || client_id > max)
                            {
                                counter = 1;
                                for (auto x: client)
                                {
                                    cout<< counter++ << ".\t" << x.first_name << "\t" << x.last_name << "\t" << x.phone_dir << " " << x.phone_num << "\t" << x.pesel << endl;
                                }
                                cout<< "If desired client isn't present, go back and add them to the database" << endl;
                                cout<< "Select (0 to exit): "; cin>> client_id;
                                cout<< endl;
                                if (client_id == 0) return true;
                            }

                            modify_record_visit(target_id, client_id, gun_id, amount_shot, accuracy, date, time, visit);
                        } break;

                        case 3: // modify field visit gun_id
                        {
                            gun_id = 0;
                            int max = gun[gun.size() - 1].id;
                            while(gun_id <= 0 || gun_id > max)
                            {
                                print_joined_tables_gun(gun, manufacturer, caliber);
                                cout<< "If desired gun isn't present, go back and add it to the database" << endl;
                                cout<< "Select (0 to exit): "; cin>> gun_id;
                                if (gun_id == 0) return true;
                            }

                            modify_record_visit(target_id, client_id, gun_id, amount_shot, accuracy, date, time, visit);
                        } break;

                        case 4: // modify field visit amount_shot
                        {
                            amount_shot = -1;
                            while(amount_shot < 0)
                            {   
                                cout<< "Amount shot can't be negative" << endl;
                                cout<< "Amount shot (-1 to exit): "; cin>> amount_shot;
                                if (amount_shot == -1) return true;
                            }

                            modify_record_visit(target_id, client_id, gun_id, amount_shot, accuracy, date, time, visit);
                        } break;

                        case 5: // modify field visit accuracy
                        {
                            accuracy = -1;
                            while((accuracy < 0 || accuracy > 1))
                            {
                                cout<< "Accuracy must be between 0 and 1 (i.e. 0.5 for 50%)" << endl;
                                cout<< "Precision of 2 symbols after period" << endl;
                                cout<< "Accuracy (-1 to exit): "; cin>> accuracy;
                                if (accuracy == -1) return true;
                                string accuracy_str = to_string(accuracy);
                                accuracy_str = accuracy_str.substr(0, 4);
                                if (accuracy_str.length() > 4) accuracy = -1; // to enforce precision limit
                            }

                            modify_record_visit(target_id, client_id, gun_id, amount_shot, accuracy, date, time, visit);
                        } break;

                        case 6: // modify field visit date
                        {
                            date = "";
                            while(!string_correct_visit_date(visit, date))
                            {
                                cout<< "Date format DD.MM.YYYY" << endl;
                                cout<< "Date (BACK to exit): ";
                                cin.sync();
                                getline(cin, date);
                                if (date == "BACK") return true;
                            }

                            modify_record_visit(target_id, client_id, gun_id, amount_shot, accuracy, date, time, visit);
                        } break;

                        case 7: // modify field visit time
                        {
                            time = "";
                            while(!string_correct_visit_time(visit, time))
                            {
                                cout<< "Time format HH:MM:SS" << endl;
                                cout<< "Time (BACL to exit): ";
                                cin.sync();
                                getline(cin, time);
                                if (time == "BACK") return true;
                            }

                            modify_record_visit(target_id, client_id, gun_id, amount_shot, accuracy, date, time, visit);
                        } break;

                        case 8: // modify field visit go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }
                } break;
                case 6: // modify record go back
                {
                    cout<< "Returning...";
                    return true;
                } break;

                default:
                {
                    cout<< "Unknown value!";
                    return true;
                } break;
            }
        } break;

        case 5: // misc queries
        {
            int choice;
            cout<< "Misc. queries" << endl;
            cout<< "1. Add shots to visit" << endl; // done
            cout<< "2. Poly" << endl;
            cout<< "3. Go back" << endl; // done
            cout<< "Select: "; cin>> choice;

            switch(choice)
            {
                case 1: // add shots to visit
                {
                    int choice, target_id = 0;
                    cout<< "Add shots to Visit according to: " << endl;
                    cout<< "1. Manual id input" << endl; //done
                    cout<< "2. List" << endl; // done
                    cout<< "3. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // add shots visit manual id
                        {
                            cout<< "Id to modify (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                        } break;

                        case 2: // add shots visit list
                        {
                            print_joined_tables_visit(caliber, client, gun, manufacturer, visit);
                            cout<< "Select (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                        } break;

                        case 3: // add shots visit go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }

                    int added_shots = -1;
                    while(added_shots < 0)
                    {   
                        cout<< "Added shots can't be negative" << endl;
                        cout<< "Added shots (-1 to exit): "; cin>> added_shots;
                        if (added_shots == -1) return true;
                    }
                    cout<< endl;

                    float accuracy = -1;
                    while((accuracy < 0 || accuracy > 1))
                    {
                        cout<< "Accuracy must be between 0 and 1 (i.e. 0.5 for 50%)" << endl;
                        cout<< "Precision of 2 symbols after period" << endl;
                        cout<< "Accuracy (-1 to exit): "; cin>> accuracy;
                        if (accuracy == -1) return true;
                        string accuracy_str = to_string(accuracy);
                        accuracy_str = accuracy_str.substr(0, 4);
                        if (accuracy_str.length() > 4) accuracy = -1; // to enforce precision limit
                    }

                    float num = added_shots + accuracy;
                    
                    fstream file;
			        string path = "./db/visit.txt";
			        file.open(path.c_str(), ios::out);
                    
                    for (int i=0; i<visit.size(); i++)
                    {
                        if (visit[i].id == target_id)
                        {
                            visit[i]+num;
                        }
                        file<< "\n" << visit[i].id << "\t" << visit[i].client_id << "\t" << visit[i].gun_id << "\t" << visit[i].amount_shot << "\t" << visit[i].accuracy << "\t" << visit[i].date << "\t" << visit[i].time;
                    }
                } break;

                case 2: // polymorphisim
                {
                    int choice, target_id = 0;
                    cout<< "Add shots to Visit according to (doesn't change the actual values, only serves to showcase polymorphisim): " << endl;
                    cout<< "1. Manual id input" << endl; //done
                    cout<< "2. List" << endl; // done
                    cout<< "3. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // polymorphisim manual id
                        {
                            cout<< "Id to modify (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                        } break;

                        case 2: // polymorphisim list
                        {
                            print_joined_tables_visit(caliber, client, gun, manufacturer, visit);
                            cout<< "Select (0 to exit): "; cin>> target_id;
                            if (target_id == 0) return true;
                        } break;

                        case 3: // polymorphisim go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }

                    int added_shots = -1;
                    while(added_shots < 0)
                    {   
                        cout<< "Added shots can't be negative" << endl;
                        cout<< "Added shots (-1 to exit): "; cin>> added_shots;
                        if (added_shots == -1) return true;
                    }
                    cout<< endl;

                    float accuracy = -1;
                    while((accuracy < 0 || accuracy > 1))
                    {
                        cout<< "Accuracy must be between 0 and 1 (i.e. 0.5 for 50%)" << endl;
                        cout<< "Precision of 2 symbols after period" << endl;
                        cout<< "Accuracy (-1 to exit): "; cin>> accuracy;
                        if (accuracy == -1) return true;
                        string accuracy_str = to_string(accuracy);
                        accuracy_str = accuracy_str.substr(0, 4);
                        if (accuracy_str.length() > 4) accuracy = -1; // to enforce precision limit
                    }

                    float num = added_shots + accuracy;

                    for (int i=0; i<visit.size(); i++)
                    {
                        if (visit[i].id == target_id)
                        {
                            Visit_poly visit_poly_temp(visit[i].id, visit[i].amount_shot, visit[i].accuracy);
                            Forced_class_that_only_exists_to_tick_a_checkbox* poly = &visit_poly_temp;
                            poly->add(num);

                            poly->print_header();
                            cout<< endl;
                            poly->print_class();
                        }
                    }
                } break;

                case 3: // misc queries go back
                {
                    cout<< "Returning...";
                    return true;
                } break;

                default:
                {
                    cout<< "Unknown value!";
                    return true;
                } break;
            }
        } break;

        case 6: // backup
        {
            int choice;
            cout<< "Backup options" << endl;
            cout<< "1. Restore backup" << endl;
            cout<< "2. Create backup" << endl; // done
            cout<< "3. Go back" << endl; // done
            cout<< "Select: "; cin>> choice;
            cout<< endl << "+-------------------------+" << endl << endl;

            switch(choice)
            {
                case 1: // restore backup
                {
                    int choice;
                    cout<< "Restore backup from:" << endl;
                    cout<< "1. Original backup" << endl;
                    cout<< "2. User created backup" << endl;
                    cout<< "3. Go back" << endl;
                    cout<< "Select: "; cin>> choice;

                    switch(choice)
                    {
                        case 1: // restore backup original
                        {
                            int choice;
                            cout<< "Select table to restore from original backup" << endl;
                            cout<< "1. All" << endl; // done
                            cout<< "2. Caliber" << endl; // done
                            cout<< "3. Client" << endl; // done
                            cout<< "4. Gun" << endl; // done
                            cout<< "5. Manufacturer" << endl; // done
                            cout<< "6. Visit" << endl; // done
                            cout<< "7. Go back" << endl; // done
                            cout<< "Select: "; cin>> choice;
                            cout<< endl << "+-------------------------+" << endl << endl;

                            switch(choice)
                            {
                                case 1: // restore backup all
                                {
                                    backup_restore_caliber(caliber, "original");
                                    cout<< endl;
                                    backup_restore_client(client, "original");
                                    cout<< endl;
                                    backup_restore_gun(gun, "original");
                                    cout<< endl;
                                    backup_restore_manufacturer(manufacturer, "original");
                                    cout<< endl;
                                    backup_restore_visit(visit, "original");
                                    cout<< endl;
                                } break;

                                case 2: // restore backup caliber
                                {
                                    backup_restore_caliber(caliber, "original");
                                    cout<< endl;
                                } break;

                                case 3: // restore backup client
                                {
                                    backup_restore_client(client, "original");
                                    cout<< endl;
                                } break;

                                case 4: // restore backup gun
                                {
                                    backup_restore_gun(gun, "original");
                                    cout<< endl;
                                } break;

                                case 5: // restore backup manufacturer
                                {
                                    backup_restore_manufacturer(manufacturer, "original");
                                    cout<< endl;
                                } break;

                                case 6: // restore buckup visit
                                {
                                    backup_restore_visit(visit, "original");
                                    cout<< endl;
                                } break;

                                case 7: // restore backup go back
                                {
                                    cout<< "Returning...";
                                    return true;
                                } break;

                                default:
                                {
                                    cout<< "Unknown value!";
                                    return true;
                                } break;
                            }
                        } break;

                        case 2: // restore backup user
                        {
                            int choice;
                            cout<< "Select table to restore from user backup" << endl;
                            cout<< "1. All" << endl; // done
                            cout<< "2. Caliber" << endl; // done
                            cout<< "3. Client" << endl; // done
                            cout<< "4. Gun" << endl; // done
                            cout<< "5. Manufacturer" << endl; // done
                            cout<< "6. Visit" << endl; // done
                            cout<< "7. Go back" << endl; // done
                            cout<< "Select: "; cin>> choice;
                            cout<< endl << "+-------------------------+" << endl << endl;

                            switch(choice)
                            {
                                case 1: // restore backup all
                                {
                                    backup_restore_caliber(caliber, "user");
                                    cout<< endl;
                                    backup_restore_client(client, "user");
                                    cout<< endl;
                                    backup_restore_gun(gun, "user");
                                    cout<< endl;
                                    backup_restore_manufacturer(manufacturer, "user");
                                    cout<< endl;
                                    backup_restore_visit(visit, "user");
                                    cout<< endl;
                                } break;

                                case 2: // restore backup caliber
                                {
                                    backup_restore_caliber(caliber, "user");
                                    cout<< endl;
                                } break;

                                case 3: // restore backup client
                                {
                                    backup_restore_client(client, "user");
                                    cout<< endl;
                                } break;

                                case 4: // restore backup gun
                                {
                                    backup_restore_gun(gun, "user");
                                    cout<< endl;
                                } break;

                                case 5: // restore backup manufacturer
                                {
                                    backup_restore_manufacturer(manufacturer, "user");
                                    cout<< endl;
                                } break;

                                case 6: // restore buckup visit
                                {
                                    backup_restore_visit(visit, "user");
                                    cout<< endl;
                                } break;

                                case 7: // restore backup go back
                                {
                                    cout<< "Returning...";
                                    return true;
                                } break;

                                default:
                                {
                                    cout<< "Unknown value!";
                                    return true;
                                } break;
                            }
                        } break;

                        case 3: // restore backup go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }
                } break;

                case 2: // create backup
                {
                    int choice;
                    cout<< "Select table to backup" << endl;
                    cout<< "1. All" << endl; // done
                    cout<< "2. Caliber" << endl; // done
                    cout<< "3. Client" << endl; // done
                    cout<< "4. Gun" << endl; // done
                    cout<< "5. Manufacturer" << endl; // done
                    cout<< "6. Visit" << endl; // done
                    cout<< "7. Go back" << endl; // done
                    cout<< "Select: "; cin>> choice;
                    cout<< endl << "+-------------------------+" << endl << endl;

                    switch(choice)
                    {
                        case 1: // create backup all
                        {
                            backup_create_caliber(caliber);
                            cout<< endl;
                            backup_create_client(client);
                            cout<< endl;
                            backup_create_gun(gun);
                            cout<< endl;
                            backup_create_manufacturer(manufacturer);
                            cout<< endl;
                            backup_create_visit(visit);
                        } break;

                        case 2: // create backup caliber
                        {
                            backup_create_caliber(caliber);
                        } break;

                        case 3: // create backup client
                        {
                            backup_create_client(client);
                        } break;

                        case 4: // create backup gun
                        {
                            backup_create_gun(gun);
                        } break;

                        case 5: // create backup manufacturer
                        {
                            backup_create_manufacturer(manufacturer);
                        } break;

                        case 6: // create buckup visit
                        {
                            backup_create_visit(visit);
                        } break;

                        case 7: // backup go back
                        {
                            cout<< "Returning...";
                            return true;
                        } break;

                        default:
                        {
                            cout<< "Unknown value!";
                            return true;
                        } break;
                    }
                } break;

                case 3: // backup go back
                {
                    cout<< "Returning...";
                    return true;
                } break;

                default:
                {
                    cout<< "Unknown value!";
                    return true;
                } break;
            }
        } break;

        case 7: // credits
        {
            cout<< "Author: Kacper Klimkowski" << endl;
            cout<< "Speical thanks to:" << endl;
            cout<< "\tStack Overflow forum" << endl;
            cout<< "\tcplusplus.com" << endl;
        } break;

        case 8: // interface exit
        {
            cout<< "Exiting...";
            return false;
        } break;
        
        default:
        {
            cout<< "Unknown value!";
            return true;
        }
    }
    return true;
}

int main()
{
    //Load database to vectors to simulate tables
    string path;

    vector<Caliber> caliber;
    path = "./db/caliber.txt";
    read_file_to_caliber_vec(path.c_str(), caliber);
    
    vector<Client> client;
    path = "./db/client.txt";
    read_file_to_client_vec(path.c_str(), client);

    vector<Gun> gun;
    path = "./db/gun.txt";
    read_file_to_gun_vec(path.c_str(), gun);

    vector<Manufacturer> manufacturer;
    path = "./db/manufacturer.txt";
    read_file_to_manufacturer_vec(path.c_str(), manufacturer);

    vector<Visit> visit;
    path = "./db/visit.txt";
    read_file_to_visit_vec(path.c_str(), visit);

    //cout<< typeid(visit).name();
    bool active = true;
    while (active)
    {
        active = interface(caliber, client, gun, manufacturer, visit);
    }
}
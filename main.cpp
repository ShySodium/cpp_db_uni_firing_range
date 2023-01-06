//Include all the sub files
#include "./sub/functions.h"
#include "./sub/class.h"
#include "./sub/db_load.h"
#include "./sub/db_querry.h"


#ifndef iostream
#include <iostream>
#endif

#ifndef vector
#include <vector>
#endif

using namespace std;

int interface(vector<Caliber> &caliber, vector<Client> &client, vector<Gun> &gun, vector<Manufacturer> &manufacturer, vector<Visit> &visit)
{
    cout<< endl;
    cout<<
        "+-------------------------+" << endl <<
        "| FIRING RANGE INTEREFACE |" << endl <<
        "+-------------------------+" << endl;
    int choice;
    cout<< "1. Read table / record" << endl; // done
    cout<< "2. Add record" << endl;
    cout<< "3. Delete record" << endl;
    cout<< "4. Modify record" << endl;
    cout<< "5. Exit" << endl;
    cout<< "Select: "; cin>> choice;

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
                            return interface(caliber, client, gun, manufacturer, visit);
                        } break;

                        default:
                        {
                            cout<< "Unknown value!" << endl;
                            return interface(caliber, client, gun, manufacturer, visit);
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
                                    return interface(caliber, client, gun, manufacturer, visit);
                                } break;

                                default:
                                {
                                    cout<< "Unknown value!" << endl;
                                    return interface(caliber, client, gun, manufacturer, visit);
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
                                    return interface(caliber, client, gun, manufacturer, visit);
                                } break;

                                default:
                                {
                                    cout<< "Unknown value!" << endl;
                                    return interface(caliber, client, gun, manufacturer, visit);
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
                                    print_gun_record_manufacturer_id(gun, 1, target_value_int);
                                } break;

                                case 5: // search gun go back
                                {
                                    cout<< "Returning..." << endl;
                                    return interface(caliber, client, gun, manufacturer, visit);
                                } break;

                                default:
                                {
                                    cout<< "Unknown value!" << endl;
                                    return interface(caliber, client, gun, manufacturer, visit);
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
                                    target_value_str = manufacturer[target_value_int - 1].name;
                                    print_manufacturer_record_name(manufacturer, 1, target_value_str);
                                } break;

                                case 3: // search manufacturer go back
                                {
                                    cout<< "Returning..." << endl;
                                    return interface(caliber, client, gun, manufacturer, visit);
                                } break;

                                default:
                                {
                                    cout<< "Unknown value!" << endl;
                                    return interface(caliber, client, gun, manufacturer, visit);
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
                                    return interface(caliber, client, gun, manufacturer, visit);
                                } break;

                                default:
                                {
                                    cout<< "Unknown value!" << endl;
                                    return interface(caliber, client, gun, manufacturer, visit);
                                } break;
                            }

                        } break;

                        case 6: // read specific record go back
                        {
                            cout<< "Returning..." << endl;
                            return interface(caliber, client, gun, manufacturer, visit);
                        } break;

                        default:
                        {
                            cout<< "Unknown value!" << endl;
                            return interface(caliber, client, gun, manufacturer, visit);
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
                            return interface(caliber, client, gun, manufacturer, visit);
                        } break;

                        default:
                        {
                            cout<< "Unknown value!" << endl;
                            return interface(caliber, client, gun, manufacturer, visit);
                        } break;
                    }
                }

                case 5: // read table / record go back
                {
                    cout<< "Returning...";
                    return interface(caliber, client, gun, manufacturer, visit);
                } break;

                default:
                {
                    cout<< "Unknown value!";
                    return interface(caliber, client, gun, manufacturer, visit);
                }
            }
        } break;
        case 5: // interface exit
        {
            cout<< "Exiting...";
            return 0;
        } break;
        
        default:
        {
            cout<< "Unknown value!";
            return interface(caliber, client, gun, manufacturer, visit);
        }
    }
    return interface(caliber, client, gun, manufacturer, visit);
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
    interface(caliber, client, gun, manufacturer, visit);
}
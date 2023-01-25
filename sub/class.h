#ifndef iostream
#include <iostream>
#endif

#ifndef string
#include <string>
#endif

#ifndef cmath
#include <cmath>
#endif

#ifndef fstream
#include <fstream>
#endif

#pragma once

using namespace std;

class Caliber {
	public:
		int id;
		string name;
		float price;

		Caliber(int id, string name, float price)
		{
			this->id = id;
			this->name = name;
			this->price = price;
		}

		int length()
		{
			return 3;
		}
		
		void print_header()
		{
			cout<< "id\tname\t\t\tprice";
		}
		void print_class()
		{
			cout<< id << "\t" << name << "\t" << price;
		}
		void print_record()
		{
			cout<< "id\tname\t\t\tprice";
			cout<< endl;
			cout<< id << "\t" << name << "\t" << price;
		}

		string search_for_var_type(string target_var)
		{
			if (target_var ==  "id") return "id";
			if (target_var == "name") return "name"; 
			if (target_var == "price") return "price";
			return ">?#$";
		}

		template <typename var_type>
		var_type search_for_var(string target_var)
		{
			if (target_var == "id") return id;
			if (target_var == "name") return name;
			if (target_var == "price") return price;
			return 0;
		}
};

class Client {
	public:
		int id;
		string first_name;
		string last_name;
		string pesel;
		string phone_dir;
		string phone_num;

		Client(int id, string first_name, string last_name, 
				string pesel, string phone_dir, string phone_num)
		{
			this->id = id;
			this->first_name = first_name;
			this->last_name = last_name;
			this->pesel = pesel;
			this->phone_dir = phone_dir;
			this->phone_num = phone_num;
		}

		int length()
		{
			return 6;
		}

		void print_header()
		{
			cout<< "id\tfirst_name\tlast_name\tpesel\t\tphone_dir\tphone_num";
		}
		void print_class()
		{
			cout<< id << "\t" << first_name << "\t" << last_name << "\t" << pesel << "\t"
				<< phone_dir << "\t\t" << phone_num;
		}

		
};

class Gun {
	public:
		int id;
		string name;
		int caliber_id;
		int manufacturer_id;

		Gun(int id, string name, int caliber_id, int manufacturer_id)
		{
			this->id = id;
			this->name = name;
			this->caliber_id = caliber_id;
			this->manufacturer_id = manufacturer_id;
		}

		int length()
		{
			return 4;
		}

		void print_header()
		{
			cout<< "id\tname\t\t\tcaliber_id\tmanufacturer_id";
		}
		void print_class()
		{
			cout<< id << "\t" << name << "\t" << caliber_id << "\t\t" << manufacturer_id;
		}
};

class Manufacturer {
	public:
		int id;
		string name;

		Manufacturer(int id, string name)
		{
			this->id = id;
			this->name = name;
		}

		int length()
		{
			return 2;
		}

		void print_header()
		{
			cout<< "id\tname";
		}
		void print_class()
		{
			cout<< id << "\t" << name;
		}
};



class Visit{
	public:
		int id;
		int client_id;
		int gun_id;
		int amount_shot;
		float accuracy;
		string date;
		string time;

		Visit(int id, int client_id, int gun_id, int amount_shot, float accuracy,
				string date, string time)
		{
			this->id = id;
			this->client_id = client_id;
			this->gun_id = gun_id;
			this->amount_shot = amount_shot;
			this->accuracy = accuracy;
			this->date = date;
			this->time = time;
		}

		int length()
		{
			return 7;
		}
		void print_header()
		{
			cout<< "id\tclient_id\tgun_id\tamount_shot\taccuracy\tdate\t\ttime";
		}
		void print_class()
		{
			cout<< id << "\t" << client_id << "\t\t" << gun_id << "\t" << amount_shot << "\t\t" << accuracy << "\t\t"
				<< date << "\t" << time;
		}

		void operator+(float num)
		{
			int added_shots = int(num);
			float with_accuracy = num - added_shots;

			int old_score = amount_shot * accuracy;
			int added_score = added_shots * with_accuracy;
			amount_shot += added_shots;
			float acc = (old_score + added_score) / float(amount_shot);
			accuracy = ceil(acc * 100) / 100;
		}
};

class Forced_class_that_only_exists_to_tick_a_checkbox {
	public:
		virtual void add(float num) = 0;
		virtual void print_header() = 0;
		virtual void print_class() = 0;
		~Forced_class_that_only_exists_to_tick_a_checkbox()
		{

		}
		class Forced_class_that_only_exists_to_tick_a_checkbox_inner {
			virtual void sub(float num) = 0;
		};
};

class Visit_poly: public Forced_class_that_only_exists_to_tick_a_checkbox{
	public:
		int id;
		int amount_shot;
		float accuracy;

		Visit_poly(int id, int amount_shot, float accuracy)
		{
			this->id = id;
			this->amount_shot = amount_shot;
			this->accuracy = accuracy;
		}

		~Visit_poly()
		{
			
		}

		void add(float num)
		{
			int added_shots = int(num);
			float with_accuracy = num - added_shots;

			int old_score = amount_shot * accuracy;
			int added_score = added_shots * with_accuracy;
			amount_shot += added_shots;
			float acc = (old_score + added_score) / float(amount_shot);
			accuracy = ceil(acc * 100) / 100;
		}

		void print_header()
		{
			cout<< "Visit ID\tAmount shot\tAccuracy";
		}

		void print_class()
		{
			cout<< this->id << "\t\t" << this->amount_shot << "\t\t" << this->accuracy;
		}
};
/*
class Ranking: public Accu {
	public:
		int client_id;
		int amount_shot;
		float accuracy;
		string date_start;
		string date_end;

		Ranking(int client_id, int amount_shot, float accuracy, string date_start, string date_end)
		{
			this->client_id = client_id;
			this->amount_shot = amount_shot;
			this->accuracy = accuracy;
			this->date_start = date_start;
			this->date_end = date_end;
		}

		void operator+(float num)
		{
			int added_shots = int(num);
			float with_accuracy = num - added_shots;

			int old_score = amount_shot * accuracy;
			int added_score = added_shots * with_accuracy;
			
			amount_shot += added_shots;
			accuracy = (old_score + added_score) / amount_shot;
		}
};
*/
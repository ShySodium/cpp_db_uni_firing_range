#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
    //Checks if first char is a letter
    //True if yes, false if no
*/
bool is_char_letter(char fir_let)
{
    int ascii = fir_let;
    if (ascii >= 65 && ascii <= 122) return true;
    return false;
}

/*
    //Reads contents of .txt files to various vectors
    //.txt files simulate a database and vectors the tables
*/
vector<string> read_file_to_vec(string path)
{
    vector<string> vec;
    fstream file;
    file.open(path, ios::in);
    if (!file.good())
    {
        cout<< "Error reading file";
        vec.clear();
        vec.push_back("Error reading file");
        file.close();
        return vec;
    }

    //Reads file and puts puts it into vector 
    int end_of_header = false;
    while (!file.eof())
    {
        string temp;
        file>> temp;
        if (temp == "1") end_of_header = true;
        //Combines the name of the caliber into one when needed
        //i.e. "5.56×45 NATO" into one string instead of "5.56×45" and "NATO"
        if (is_char_letter(temp[0]) && end_of_header)  
        {
            int position = vec.size()-1;
            string replace = vec[position] + " " + temp;
            vec[position] = replace;
        }
        else
        {
            vec.push_back(temp);
        }
    }
    file.close();
    return vec;
}
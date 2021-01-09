#pragma once
#include <iostream>
#include <ctime>
#include <list>
#include <fstream>
#include <iterator>
#include <string>

namespace meow_mur
{
    class Exception {
    private:
        int warning;
    public:
        Exception() {
            warning = 0;
        };
        Exception(int error) {
            warning = error;
        }
        void Print()
        {
            if (this->warning == 3)
            {
                std::cout << "The list is empty!" << std::endl;
            }
        }
    };

    class exam
    {
    public:
        int id;
        std::string name;
        int result;
    public:
        exam() : name(" "), result(0.0)
        {
            id++;
        }
        exam(std::string n) : name(n), result(0.0)
        {
            id++;
        }
        exam(std::string n, int r) : name(n), result(r)
        {
            id++;
        }
        exam(std::string n, int r, int Id) : name(n), result(r), id(Id) { }
        ~exam()
        { }
        std::string get_name()
        {
            return this->name;
        }
        int get_id()
        {
            return this->id;
        }
        int get_result()
        {
            return this->result;
        }
        bool operator< (exam ex)
        {
            return this->name < ex.name;
        }
        bool operator==(exam ex)
        {
            return (this->name == ex.name) && (this->result == ex.result);
        }
        friend std::fstream& operator <<(std::fstream& file, exam& item);
        friend std::ostream& operator <<(std::ostream &out, exam &ex);
        exam& operator= (exam ex)
        {
            this->name = ex.name;
            this->result = ex.result;
            return *this;
        }
    };

    std::fstream& operator<<(std::fstream& file, meow_mur::exam& item) {
        try {
            if (!file.is_open()) throw 1;
        }
        catch (int i) {
            meow_mur::Exception eax(i);
            eax.Print();
        }
        file << item.get_name();
        file << " ";
        file << item.get_result();
        file << " ";
        file << item.get_id();
        file << " ";
        file << "\n";

        return file;
    }

    std::ostream& operator <<(std::ostream &out, exam &ex)
    {
        return out << "name: " << ex.get_name() << "\t" << "Result: " << ex.get_result() << std::endl;
    }
}

namespace meow_mur
{
    class Algorithm
    {
    public:
        void algorithm_1(std::string substring)
        {
            std::fstream file;
            int fl = 0;
            char c;
            file.open("T2.txt", std::ios::in);
            file.seekg(0, std::ios_base::beg);
            try
            {
                if (!file.is_open())
                {
                    throw 1;
                }
            }
            catch (int i)
            {
                meow_mur::Exception eax(i);
                eax.Print();
                return;
            }
            int n = 0;
            while (!file.eof()) 
            {
                file.get(c);
                if (c == substring[0]) 
                {
                    n++;
                    for (int j = 1; !file.eof() && j < substring.length(); j++) 
                    {
                        file.get(c);
                        if (c == substring[j])n++;
                        else break;
                    }
                }
                if (n == substring.length())
                {
                    fl++;
                    break;
                }
                else n = 0;
            }
            file.close();
            std::fstream f1;
            f1.open("uk_place.txt", std::ios::out);
            f1 << "Kol-vo:" << fl;
            f1.close();
        }

        void algorithm_2(std::list<meow_mur::exam>::iterator begin, std::list<meow_mur::exam>::iterator end) {
            int i1 = 0, i2 = 0;
            while (begin != end) 
            {
                begin++;
                if (begin == end) break;
                i1++;
                if ((*begin).result > 3)
                {
                    i2++;
                }
            }
            if (i1 == i2) std::cout << "Condition is met" << std::endl;
            else std::cout << "Condition isn't met" << std::endl;
        }
        void algorithm_3(std::list<meow_mur::exam>::iterator begin, std::list<meow_mur::exam>::iterator end) {
            std::fstream file;
            file.open("1txt.txt", std::ios::out);
            try {
                if (!file.is_open()) throw 1;
            }
            catch (int i)
            {
                Exception ex(i);
                ex.Print();
            }
            while (begin != end) 
            {
                    file << (*begin).get_name();
                    file << " ";
                    file << (*begin).get_result();
                    file << " ";
                    file << (*begin).get_id();
                    file << " ";
                    file << "\n";
                    begin++;
            }
            file.close();
        }
    };
}
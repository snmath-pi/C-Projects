#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>
#include <sstream>
using namespace std;

const char *HOST = "localhost";
const char *USER = ""; // enter your mysql username here
const char *PW = "";   // enter your password here
const char *DB = "";   // enter the db you want to use

class Hostel
{
private:
    string Name;
    int Bed, Fee;

public:
    Hostel(string name, int bed, int fee)
    {
        Name = name;
        Bed = bed;
        Fee = fee;
    }

    string getName()
    {
        return Name;
    }
    int getBed()
    {
        return Bed;
    }
    int getFee()
    {
        return Fee;
    }
};
int main()
{

    MYSQL *conn;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, HOST, USER, PW, DB, 3306, NULL, 0))
    {
        cout << "Error: " << mysql_error(conn) << '\n';
    }
    else
    {
        cout << "Logged in Database" << '\n';
    }
    Sleep(3000);

    Hostel h("3star", 5, 5000);

    int intB = h.getBed();
    stringstream ss;
    ss << intB;
    string strB = ss.str();
    int intF = h.getFee();
    ss << intF;
    string strF = ss.str();
    string insert_values = "INSERT INTO hostel (Name, Bed, Fee) VALUES ('" + h.getName() + "','" + strB + "', '" + strF + "')";
    if (mysql_query(conn, insert_values.c_str()))
    {
        cout << "Error: " << mysql_error(conn) << '\n';
    }
    else
    {
        cout << "Data Inserted!" << '\n';
    }

    bool exit_loop = false;
    while (!exit_loop)
    {
        system("cls");
        cout << "Welcome to Hostel Management System" << '\n';
        cout << "***********************************" << '\n';
        cout << "1. Reserve a Bed" << '\n';
        cout << "2. Exit: " << '\n';
        cout << "Enter you choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter Student Name: ";
            string get_input_name;
            cin >> get_input_name;
            int total;
            string check = "SELECT Bed FROM hostel Name = '" + h.getName() + "'";
            if (mysql_query(conn, check.c_str()))
            {
                cout << "Error: " << mysql_error(conn) << '\n';
            }
            else
            {
                MYSQL_RES *res;
                res = mysql_store_result(conn);
                if (res)
                {
                    MYSQL_ROW row = mysql_fetch_row(res);
                    if (row)
                    {
                        total = atoi(row[0]);
                    }
                }
                mysql_free_result(res);
            }
            if (total > 0)
            {
                total--;
                stringstream zs;
                zs << total;
                string temp_s = zs.str();
                string update = "UPDATE hostel SET Bed = '" + temp_s + "', WHERE Name='" + h.getName() + "'";
                if (mysql_query(conn, update.c_str()))
                {
                    cout << "Error: " << mysql_error(conn) << '\n';
                }
                else
                {
                    cout << "Bed is reserved successfully in" << h.getName() << " Hostel for Student" << get_input_name << '\n';
                    cout << "Please pay " << h.getFee() << " Rupees." << '\n';
                }
            }
            else
            {
                cout << "Sorry No Bed Available!\n";
            }
            Sleep(4000);
        }
        else if (choice == 2)
        {
            exit_loop = true;
            cout << "Good Luck!\n";
            Sleep(4000);
        }
        else
        {
            cout << "Invalid Input!\n";
            Sleep(4000);
        }
    }

    mysql_close(conn);
    return 0;
}

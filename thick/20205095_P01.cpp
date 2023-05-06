#include <bits/stdc++.h>

using namespace std;

/*

2020-01-02
2020-01-03
2020-01-04
*
TR00000005 C000000002 2020-01-03 12:10:36 80
TR00000010 C000000002 2020-01-02 04:33:22 50
TR00000004 C000000001 2020-01-04 11:23:54 50
TR00000009 C000000001 2020-01-04 00:38:06 40
TR00000006 C000000001 2020-01-04 21:09:44 40
TR00000002 C000000001 2020-01-04 09:11:09 90
TR00000007 C000000002 2020-01-02 18:30:25 100
TR00000003 C000000001 2020-01-03 22:23:23 30
TR00000004 C000000001 2020-01-04 10:53:54 30
TR00000001 C000000002 2020-01-02 23:25:24 100
TR00000008 C000000001 2020-01-04 17:17:49 20
TR00000008 C000000001 2020-01-04 17:47:49 100
TR00000002 C000000001 2020-01-04 08:41:09 80
TR00000006 C000000001 2020-01-04 20:39:44 50
***
TOTAL_QTY
QTY_CUSTOMER C000000001
QTY_CUSTOMER C000000002
TOTAL_TRIPS
***


*/

struct Date {
  int year;
  int month;
  int day;

  Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
  }
};

struct Time {


    int hour;
    int minute;
    int second;

    Time(int hour, int minute, int second) {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }

    int diff(){
        return 3600*hour + 60*minute + second;
    }

    void addDate(int date){
        hour = 24 + hour;
    }

//   int addSecond(int second) {
//     int dayafter = 0;
//     this->second += second;
//     if (this->second >= 60) {
//       this->minute += this->second / 60;
//       this->second %= 60;
//     }
//     if (this->minute >= 60) {
//       this->hour += this->minute / 60;
//       this->minute %= 60;
//     }
//     if (this->hour >= 24) {
//       int hour = this->hour;
//       this->hour %= 24;
//       dayafter += hour / 24;
//     }
//     return dayafter;
//   }


};

vector<Date> date;
unordered_map<string, int> mapDate;

int totalQTY = 0;
unordered_map<string, int> qtyCustomer; //qtyCustomer[customercode] -> sum
unordered_map<string, int> travelTimeTrip; // size of this map is Total trips

//database
unordered_map<string, vector< pair <Date, Time> > > DB;

void input(){
    string x;
    do {
        cin >> x;
        if (x == "*") break;
        else {
            int year = atoi(x.substr(0, 4).c_str());
            int month = atoi(x.substr(5, 2).c_str());
            int day = atoi(x.substr(8, 2).c_str());
            date.push_back(Date(year, month, day));
            mapDate[x]=date.size() -1;
        }
    } while(x != "*");

    //information
    string tripcode;
    do {
        cin >> tripcode;
        if (tripcode == "***") break;
        else {
            string customer, datestr, timestr;
            int qty;
            cin >> customer >> datestr >> timestr;
            cin >> qty;
            //processing

            int year = atoi(datestr.substr(0, 4).c_str());
            int month = atoi(datestr.substr(5, 2).c_str());
            int day = atoi(datestr.substr(8, 2).c_str());

            Date d = Date(year, month,day);

            int hour = atoi(timestr.substr(0, 2).c_str());
            int minute = atoi(timestr.substr(3, 2).c_str());
            int second = atoi(timestr.substr(6, 2).c_str());

            Time t = Time(hour, minute, second);

            DB[tripcode].push_back(make_pair(d, t));

            //totalQty update
            totalQTY += qty;

            //qtyCustomer update
            qtyCustomer[customer] += qty;

            //update travelTimeTrip
            travelTimeTrip[tripcode] += 0;//need edit
        }
    } while(tripcode != "***");

    string query;
    do {
        cin >> query;
        if (query == "***") break;
        else {
            if (query == "TOTAL_QTY"){
                cout <<totalQTY<<endl;
            } else if (query == "QTY_CUSTOMER"){
                string customer;
                cin >> customer;
                cout << qtyCustomer[customer] << endl;
            } else if (query == "QTY_MAX_PERIOD"){
                
            } else if (query == "TOTAL_TRIPS"){
                cout << travelTimeTrip.size() <<endl;
            } else if (query == "TRAVEL_TIME_TRIP"){
                string travel;
                cin >> travel;
                cout << travelTimeTrip[travel] <<endl;
            } else if (query == "MAX_CONFLICT_TRIPS"){
                
            }
        }
    } while(query != "***");

}

int main(int argc, char const *argv[])
{
    input();
    return 0;
}

#include<iostream>
#include<fstream>
//#include "Admin.h";
#include "Appointment.h";
#include "Doctor.h";
#include "Patient.h";
#include "User.h";
//#include "Hospital.h";
using namespace std;


class Hospital{
private:
    string city;
    string hospitalname;

    public:
        int no_of_hospitals = 15;
        Hospital()
        {}
            Hospital (string c , string h)
            {
                city = c;
                hospitalname = h;
            }

            void setcity(string c)
            {
                city = c;
            }
            void sethospitalname(string hn)
            {

                hospitalname = hn;
            }

            string getcity()
            {
                return city;
            }

            string getHospitalName()
	{
		return hospitalname;
	}

};





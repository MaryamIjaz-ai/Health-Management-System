
#pragma once
#include <iostream>
#include<fstream>
#include<sstream>
#include <string>
#include "admin.h";
#include "Appointment.h";
#include "Doctor.h";
#include "patient.h";
#include "User.h";
#include "Hospital.h";
using namespace std;
class User{
private:
string cnic;
string name;
string phone_no;
string password;
int age;

User(){
    cnic = "NULL";
    name= "NULL";
    age =0;
    phone_no= "NULL";
    password="NULL";
}
string getCnic(){
    return cnic;
}
string getName(){
    return name;
}
string getPhoneno(){
    return phone_no;
}
string getPass(){
    return password;
}
int getAge(){
    return age;
}
void setName( string n){
    name= n;
}
void getCnic( string c){
    cnic = c;
}
void setPhoneno( string p){
    phone_no=p;
}
void setPass(string pass){
    pass= password;
}
void setAge( int a){
    age =a;
}

void PatientstoreData(string name, string cnic, string user_name, string pass)    //function to store the data of patients in a file
	{
		fstream patientfile;
		patientfile.open("Patient.txt", ios::app);
		if (patientfile.is_open())
		{

			patientfile << name;
			patientfile << " ";
			patientfile << cnic;
			patientfile << " ";
			patientfile << user_name;
			patientfile << " ";
			patientfile << pass;
			patientfile << endl;

		}
	}

	bool CheckCnicPatient(string cnic)
	{
		string word, patientname, patientcnic, patientUsername, patientPassword;
		fstream patientfile;
		patientfile.open("Patient.txt", ios::in);

		while (!patientfile.eof())
		{
			getline(patientfile, word);
			stringstream w(word);
			w >> patientname;
			w >> patientcnic;
			if (patientcnic == cnic)
			{
				return true;
				break;
			}

		}
		return false;
	}

	bool CheckUsernamePatient(string user_name)
	{
		string word, patientUsername, patientPassword, patientname, patientcnic;
		fstream patientfile;
		patientfile.open("Patient.txt", ios::in);
		while (!patientfile.eof())
		{
			getline(patientfile, word);
			stringstream w(word);
			w >> patientname;
			w >> patientcnic;
			w >> patientUsername;
			w >> patientPassword;
			if (patientUsername == user_name)
			{
				return true;
				break;
			}

		}
		return false;

	}

	bool CheckPasswordPatient(string pass)
	{
		string word, patientUsername, patientPassword, patientname, patientcnic;
		fstream patientfile;
		patientfile.open("Patient.txt", ios::in);
		while (!patientfile.eof())
		{
			getline(patientfile, word);
			stringstream w(word);
			w >> patientname;
			w >> patientcnic;
			w >> patientUsername;
			w >> patientPassword;
			if (patientPassword == pass)
			{
				return true;
				break;
			}

		}
		return false;
	}

	///---------------------------------------------------------------------------------------------//

		//////////////////////////////////// Function For Doctors //////////////////////////////////////


	

	// checks for verifying 
	bool checkPhoneno(string no)
	{
		for (int i = 0; i < no.length(); i++)
		{
			if (no[i] > '0' || no[i] < '9')
			{
				return true;
			}
			return false;
		}
	}

	bool CheckCnicDoctor(string cnic)
	{
		string word, doctorname, doctorcnic, doctorUsername, doctorPassword, doctorno, doctoremail;
		fstream doctorfile;
		doctorfile.open("Doctor.txt", ios::in);

		while (!doctorfile.eof())
		{
			getline(doctorfile, word);
			stringstream w(word);
			w >> doctorname;
			w >> doctorcnic;
			if (doctorcnic == cnic)
			{
				return true;
				break;
			}

		}
		return false;
	}

	bool CheckEmailDoctor(string email)
	{
		string word, doctorname, doctorcnic, doctorUsername, doctorPassword, doctorno, doctoremail;
		fstream doctorfile;
		doctorfile.open("Doctor.txt", ios::in);

		while (!doctorfile.eof())
		{
			getline(doctorfile, word);
			stringstream w(word);
			w >> doctorname;
			w >> doctorcnic;
			w >> doctoremail;
			if (doctoremail == email)
			{
				return true;
				break;
			}

		}
		return false;
	}

	// storing doctors data
	void DoctorstoreData(string name, string cnic, string email, string phoneno, string username, string pass, string city, string hospital, string specification, int stime, int etime, int experience)    //function to store the data of doctors in a file
	{
		fstream doctorfile;
		doctorfile.open("Doctor.txt", ios::app);
		if (doctorfile.is_open())
		{

			doctorfile << name;
			doctorfile << " ";
			doctorfile << cnic;
			doctorfile << " ";
			doctorfile << email;
			doctorfile << " ";
			doctorfile << phoneno;
			doctorfile << " ";
			doctorfile << username;
			doctorfile << " ";
			doctorfile << pass;
			doctorfile << " ";
			doctorfile << city;
			doctorfile << " ";
			doctorfile << hospital;
			doctorfile << " ";
			doctorfile << stime;
			doctorfile << " ";
			doctorfile << etime;
			doctorfile << " ";
			doctorfile << experience;
			doctorfile << " ";
			doctorfile << specification;
			doctorfile << endl;
		}
	}


	bool CheckUsernameDoctor(string user_name)
	{
		string word, doctorUsername, doctorPassword, doctorname, doctorcnic, doctoremail, doctorphoneno;
		fstream docotorfile;
		docotorfile.open("Doctor.txt", ios::in);
		while (!docotorfile.eof())
		{
			getline(docotorfile, word);
			stringstream w(word);
			w >> doctorname;
			w >> doctorcnic;
			w >> doctoremail;
			w >> doctorphoneno;
			w >> doctorUsername;
			if (doctorUsername == user_name)
			{
				return true;
				break;
			}

		}
		return false;

	}

	bool CheckPasswordDoctor(string pass)
	{
		string word, doctorUsername, doctorPassword, doctorname, doctorcnic, doctoremail, doctorphoneno;
		fstream docotorfile;
		docotorfile.open("Doctor.txt", ios::in);
		while (!docotorfile.eof())
		{
			getline(docotorfile, word);
			stringstream w(word);
			w >> doctorname;
			w >> doctorcnic;
			w >> doctoremail;
			w >> doctorphoneno;
			w >> doctorUsername;
			w >> doctorPassword;
			if (doctorPassword == pass)
			{
				return true;
				break;
			}

		}
		return false;

	}


	///---------------------------------------------------------------------------------------------//

	//////////////////////////////////// Function For Admin //////////////////////////////////////

	// checks 
	bool CheckUsernameAdmin(string user_name)
	{
		string word, adminUsername, adminPassword;
		fstream adminfile;
		adminfile.open("Admin.txt", ios::in);
		while (!adminfile.eof())
		{
			getline(adminfile, word);
			stringstream w(word);
			w >> adminUsername;
			if (adminUsername == user_name)
			{
				return true;
				break;
			}

		}
		return false;

	}

	bool CheckPasswordAdmin(string pass)
	{
		string word, adminUsername, adminPassword;
		fstream adminfile;
		adminfile.open("Admin.txt", ios::in);
		while (!adminfile.eof())
		{
			getline(adminfile, word);
			stringstream w(word);
			w >> adminUsername;
			w >> adminPassword;
			if (adminPassword == pass)
			{
				return true;
				break;
			}

		}
		return false;

	}

};



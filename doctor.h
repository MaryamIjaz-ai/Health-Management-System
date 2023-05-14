#pragma once
#include<iostream>

#include "User.h"
#include "Appointment.h"
using namespace std;
class Doctor : public User         // inheritance from user class
{
private:
	Appointment* A = new Appointment;   // aggregation with appointment
	string name, cnic, pass, username, email, phoneno, specification, city, hospital;
	int stime, etime, experience;

public:

	string getName()
	{
		return name;
	}
	string getcnic()
	{
		return cnic;
	}
	string getpass()
	{
		return pass;
	}
	string getusername()
	{
		return username;
	}

	Appointment* getA()
	{
		return A;
	}
	void setDoctor()
	{

	}

void setReview(string doc, string pat, string r)
	{
		review = r;
		fstream doctorfile;
		doctorfile.open("Review.txt", ios::app);
		if (doctorfile.is_open())
		{
			doctorfile << doc;
			doctorfile << " ";
			doctorfile << pat;
			doctorfile << " ";
			doctorfile << r;
			doctorfile << "-Stars";
			doctorfile << endl;
		}

	}

	void displayReviewDoctor(string doc)
	{
		string word, docname, rev, patname;
		fstream doctorfile;
		doctorfile.open("Review.txt", ios::in);
		cout << endl << endl << "    **Reviews**" << endl;
		int c = 0;
		while (!doctorfile.eof())
		{
			getline(doctorfile, word);
			stringstream s(word);
			s >> docname;
			s >> patname;
			s >> rev;
			if (docname == doc)
			{
				cout << patname << "     ->  " << rev << endl;
				c++;
			}
		}
		if (c == 0)
		{
			cout << "    No reviews yet." << endl << endl;
		}
	}


	void checkDoctorSpecification(string specialization)
	{
		string word, doctorname, doctorcnic, doctorUsername, doctorPassword, doctorno, doctoremail, doctorphoneno, city, hospital, stime, etime, experience, specification;
		fstream doctorfile;
		doctorfile.open("Doctor.txt", ios::in);

		while (!doctorfile.eof())
		{
			getline(doctorfile, word);
			stringstream w(word);
			w >> doctorname;
			w >> doctorcnic;
			w >> doctoremail;
			w >> doctorphoneno;
			w >> doctorUsername;
			w >> doctorPassword;
			w >> city;
			w >> hospital;
			w >> stime;
			w >> etime;
			w >> experience;
			w >> specification;
			if (specification == specialization)
			{
				cout <<"    " <<specification << "    " << doctorname << "    " << doctoremail << "   " << doctorphoneno << "   " << city << "   " << hospital << "   " << stime << "  -  " << etime << endl;
			}

		}
	}



	void checkDoctorCity(string c)
	{
		string word, doctorname, doctorcnic, doctorUsername, doctorPassword, doctorno, doctoremail, doctorphoneno, city, hospital, stime, etime, experience, specification;
		fstream doctorfile;
		doctorfile.open("Doctor.txt", ios::in);

		while (!doctorfile.eof())
		{
			getline(doctorfile, word);
			stringstream w(word);
			w >> doctorname;
			w >> doctorcnic;
			w >> doctoremail;
			w >> doctorphoneno;
			w >> doctorUsername;
			w >> doctorPassword;
			w >> city;
			w >> hospital;
			w >> stime;
			w >> etime;
			w >> experience;
			w >> specification;
			if (city == c)
			{
				cout << city << " " << doctorname << " " << doctoremail << " " << doctorphoneno << " " << specification << " " << hospital << " " << stime << "-" << etime << endl;
			}

		}
	}


	void checkDoctorHosp(string h)
	{
		string word, doctorname, doctorcnic, doctorUsername, doctorPassword, doctorno, doctoremail, doctorphoneno, city, hospital, stime, etime, experience, specification;
		fstream doctorfile;
		doctorfile.open("Doctor.txt", ios::in);

		while (!doctorfile.eof())
		{
			getline(doctorfile, word);
			stringstream w(word);
			w >> doctorname;
			w >> doctorcnic;
			w >> doctoremail;
			w >> doctorphoneno;
			w >> doctorUsername;
			w >> doctorPassword;
			w >> city;
			w >> hospital;
			w >> stime;
			w >> etime;
			w >> experience;
			w >> specification;
			if (hospital == h)
			{
				cout << hospital << " " << doctorname << " " << doctoremail << " " << doctorphoneno << " " << specification << " " << city << " " << stime << "-" << etime << endl;
			}

		}
	}


	void checkDoctorDetails()
	{
		string word, doctorname, doctorcnic, doctorUsername, doctorPassword, doctorno, doctoremail, doctorphoneno, city, hospital, stime, etime, experience, specification;
		fstream doctorfile;
		doctorfile.open("Doctor.txt", ios::in);

		while (!doctorfile.eof())
		{
			getline(doctorfile, word);
			stringstream w(word);
			w >> doctorname;
			w >> doctorcnic;
			w >> doctoremail;
			w >> doctorphoneno;
			w >> doctorUsername;
			w >> doctorPassword;
			w >> city;
			w >> hospital;
			w >> stime;
			w >> etime;
			w >> experience;
			w >> specification;

			cout << doctorname << "    " << doctoremail << "     " << doctorphoneno << "     " << specification << "      " << hospital << "             " << city << "       " << stime << "-" << etime << endl;


		}
	}

};
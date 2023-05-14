#include<iostream>
using namespace std;
#include"Admin.h"
#include"Doctor.h"
#include"patient.h"

class Appointment
{
private:
	int time;
	string day;
	string doctorname;
	string doctorcnic;
	string mode;
	string patientname;
	string patientcnic;

public:


	int Payment(string mod)
	{
		int pay;
		if (mod == "    Video_Consultation")
		{
			cout << mod << endl;
			cout << "-     Total Bill: 1500rs" << endl; //hardcoded the values
			cout << "         1. Pay Online now." << endl;
			cout << "         2. Pay Later." << endl;
			cout << "         0. Cancel Appointmnet" << endl;
			cout << "    Choose: ";
			cin >> pay;
			while (pay < 0 || pay>2)
			{
				cout << "    Invalid." << endl;
				cout << "    Choose: ";
				cin >> pay;
			}
			if (pay == 1)
			{
				cout << "    Online Payment Completed." << endl << endl;
				return 1;
			}
			else if (pay == 2)
			{
				cout << "    Bill: 1500rs" << endl;
				cout << "    Payment Pending." << endl << endl;
				return 2;
			}
			else if (pay == 0)
			{
				return 0;
			}
		}
    
    else if (mod == "    In-Person_Consultation")
		{
			cout << mod << endl;
			cout << "     Total Bill: 2500rs" << endl;
			cout << "        1. Pay Online now." << endl;
			cout << "        2. Pay Later." << endl;
			cout << "        0. Cancel Appointmnet" << endl;
			cout << "    Choose: ";
			cin >> pay;
			while (pay < 0 || pay>2)
			{
				cout << "    Invalid." << endl;
				cout << "    Choose: ";
				cin >> pay;
			}
			if (pay == 1)
			{
				cout << "    Online Payment Completed." << endl << endl;
				return 1;
			}
			else if (pay == 2)
			{
				cout << "    Bill: 2500rs" << endl;
				cout << "    Payment Pending." << endl << endl;
				return 2;
			}
			else if (pay == 0)
			{
				return 0;
			}
		}
	}
else if (mod == "    In-Person_Consultation")
		{
			cout << mod << endl;
			cout << "     Total Bill: 2500rs" << endl;
			cout << "        1. Pay Online now." << endl;
			cout << "        2. Pay Later." << endl;
			cout << "        0. Cancel Appointmnet" << endl;
			cout << "    Choose: ";
			cin >> pay;
			while (pay < 0 || pay>2)
			{
				cout << "    Invalid." << endl;
				cout << "    Choose: ";
				cin >> pay;
			}
			if (pay == 1)
			{
				cout << "    Online Payment Completed." << endl << endl;
				return 1;
			}
			else if (pay == 2)
			{
				cout << "    Bill: 2500rs" << endl;
				cout << "    Payment Pending." << endl << endl;
				return 2;
			}
			else if (pay == 0)
			{
				return 0;
			}
		}
	}

	void Bookings(string docname, string patname, string patcnic)
	{
		string word, doctname, doctcnic, doctorUsername, doctorPassword, doctorno, doctoremail, doctorphoneno, city, hospital, experience, specification;
		int stime, etime;
		fstream doctorfile;
		doctorfile.open("Doctor.txt", ios::in);

		while (!doctorfile.eof())
		{
			getline(doctorfile, word);
			stringstream w(word);
			w >> doctname;
			w >> doctcnic;
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
			if (doctname == docname)
			{
				int numt;
				int mod;
				int selday;

				do
				{
					cout << "     *Working Days*" << endl;
					cout << "     1.Monday \n     2.Tuesday \n     3.Wednesday \n     4.Thursday \n     5.Friday \n     6.Saturday" << endl << "    Choose: ";
					cin >> selday;
				} while (selday < 1 || selday>6);
				if (selday == 1)
				{
					day = "Monday";
				}
				else if (selday == 2)
				{
					day = "Tuesday";
				}
				else if (selday == 3)
				{
					day = "Wednesday";
				}
				else if (selday == 4)
				{
					day = "Thursday";
				}
				else if (selday == 5)
				{
					day = "Friday";
				}
				else if (selday == 6)
				{
					day = "Saturday";
				}

				cout << "    **Time Slots**" << endl;
				int i = 0;
				/*cout<<stime;
				cout<<	etime;*/
				while (stime + i <= etime)
				{
					cout << i + 1 << "    . " << stime + i << " PM" << endl;
					i++;
				}
				do
				{
					cout << "    Select a Time Slot (e.g. 1): ";
					cin >> numt;
				} while (stime + numt - 1 >= etime);
				do
				{
					cout << "    Select Mode of appointmnet: " << endl << "    1. Video Consultation.  (Rs.1500) " << endl << "    2. In-Person Consultation.  (Rs.2500) " << endl << "    Choose: ";
					cin >> mod;
				} while (mod < 1 || mod > 2);
				if (mod == 1)
				{
					mode = "    Video_Consultation";
				}
				else
				{
					mode = "    In-Person_Consultation";

				}
				time = stime + numt - 1;
				doctorname = doctname;
				doctorcnic = doctcnic;
				patientname = patname;
				patientcnic = patcnic;


				int pay = Payment(mode);
				if (pay == 1)
				{
					fstream appfile;
					appfile.open("Appointments.txt", ios::app);
					if (appfile.is_open())
					{
						appfile << doctorname;
						appfile << " ";
						appfile << doctorcnic;
						appfile << " ";
						appfile << patientname;
						appfile << " ";
						appfile << patientcnic;
						appfile << " ";
						appfile << day;
						appfile << " ";
						appfile << time;
						appfile << " ";
						appfile << mode;
						appfile << " ";
						appfile << "Payment:Done";
						appfile << endl;
					}
					cout << endl << "    *** Appointment Made Successful ***" << endl;
					cout << day << "  " << time << "-" << time + 1 << " PM" << "  Payment: Done" << endl << endl;
				}
				else if (pay == 2)
				{
					fstream appfile;
					appfile.open("Appointments.txt", ios::app);
					if (appfile.is_open())
					{
						appfile << doctorname;
						appfile << " ";
						appfile << doctorcnic;
						appfile << " ";
						appfile << patientname;
						appfile << " ";
						appfile << patientcnic;
						appfile << " ";
						appfile << day;
						appfile << " ";
						appfile << time;
						appfile << " ";
						appfile << mode;
						appfile << " ";
						appfile << "Payment:Pending";
						appfile << endl;
					}
					cout << endl << "    *** Appointment Made Successful ***" << endl;
					cout << day << "  " << time << "-" << time + 1 << " PM" << "  Payment: Pending" << endl << endl;
				}
				else
				{
					cout << "    ///Appointment Cancelled.///" << endl << endl;
				}
				break;
			}
		}
	}

	void displayDoctorAppointment(string docn)
	{
		string word, doctname, doctcnic, doctorUsername, doctorPassword, doctorno, doctoremail, doctorphoneno, city, hospital, experience, specification;
		string patname, patcnic, days, times, modes;
		fstream doctorfile;
		int c = 0;
		doctorfile.open("Appointments.txt", ios::in);
		cout << endl << "    ** Appointments for this week **" << endl;
		while (!doctorfile.eof())
		{
			getline(doctorfile, word);
			stringstream w(word);
			w >> doctname;
			w >> doctcnic;
			w >> patname;
			w >> patcnic;
			w >> days;
			w >> times;
			w >> modes;
			if (doctname == docn)
			{
				cout << patname << "    " << days << "          " << times << "           " << modes << endl << endl;
				c++;
			}
		}
		if (c == 0)
		{
			cout << "    No Appointmnets" << endl << endl;
		}
	}

	void displayPatientAppointment(string patn)
	{
		string word, doctname, doctcnic, doctorUsername, doctorPassword, doctorno, doctoremail, doctorphoneno, city, hospital, experience, specification;
		string patname, patcnic, days, times, modes;
		fstream doctorfile;
		int c = 0;
		doctorfile.open("Appointments.txt", ios::in);
		cout << endl << "    ** Appointments **" << endl;
		while (!doctorfile.eof())
		{
			getline(doctorfile, word);
			stringstream w(word);
			w >> doctname;
			w >> doctcnic;
			w >> patname;
			w >> patcnic;
			w >> days;
			w >> times;
			w >> modes;
			if (patname == patn)
			{
				cout  <<patname << "      " << days << "      " << times << "        " << modes << endl << endl;
				c++;
			}
		}
		if (c == 0)
		{
			cout << "    No Appointmnets" << endl << endl;
		}
	}

	void displayAppointment()
	{
		string word, doctname, doctcnic, doctorUsername, doctorPassword, doctorno, doctoremail, doctorphoneno, city, hospital, experience, specification;
		string patname, patcnic, days, times, modes;
		fstream doctorfile;
		int c = 0;
		doctorfile.open("Appointments.txt", ios::in);
		cout << endl << "    ** Appointments **" << endl;
		while (!doctorfile.eof())
		{
			getline(doctorfile, word);
			stringstream w(word);
			w >> doctname;
			w >> doctcnic;
			w >> patname;
			w >> patcnic;
			w >> days;
			w >> times;
			w >> modes;
			cout << patname << "          " << doctname << "          " << days << "          " << times << "          " << modes << endl << endl;
			c++;
		}
		if (c == 0)
		{
			cout << "    No Appointmnets" << endl << endl;
		}
	};





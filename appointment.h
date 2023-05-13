#include<iostream>
using namespace std;

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
};
#include<iostream>

#include "admin.h";
#include "Appointment.h";
#include "Doctor.h";
#include "patient.h";
#include "User.h";
#include "Hospital.h"
using namespace std;

int main()
{
	Doctor D;// doctor object
	patient P;//patient object
	Hospitals H;// hospital object
	Admin A;// admin object
	Appointment App; //Appointment object
	int choice = 0, choose = 0, choice1;;//some variables for chooice input
	string name, cnic, user_name, pass, confirm_pass, phoneno, email, specification, currHos, currcity;
	string docname, choosedoctor, patname;// other input variables for name cnic and etc

	char ch = ' ', ch1 = ' ', c = ' ', c1 = ' ';
	int age, u_c = 0, l_c = 0, num = 0, special_char = 0;
	int experience = 0;
	string workinghospital, workingcity, workinghours;
	int stime, etime, workingexperience;
	int schoose;
	string star;

	// an array of hospital names
	string hospitalname[15] = { "  Shifa_International_Hospital" ,"    Maroof_Hospital" ,"    Noori_Hospital","    Kulsum_Hospital","    PIMS" ,"    Jinnah_Hospital", "    Lahore_General_Hospital","    Mayo_Hospital", "    Aadil_Hospital" ,"    MidCity_Hospital" ,"    Aga_KHan_Hospital" ,"    Pateil_Hospital", "    Memon_Hospital", "    Ziauddin_Hospital" ,"    A.O_Hospital" };

	Hospitals* Hos = new Hospitals[15];

	for (int i = 0; i < 5; i++)
	{
		Hos[i].setCity("Islamabad");
		Hos[i].setHospitalName(hospitalname[i]);
	}
	for (int i = 5; i < 10; i++)
	{
		Hos[i].setCity("Lahore");
		Hos[i].setHospitalName(hospitalname[i]);
	}
	for (int i = 10; i < 15; i++)
	{
		Hos[i].setCity("Karachi");
		Hos[i].setHospitalName(hospitalname[i]);
	}

do
	{    //  implementing  menu 
		do
		{
			cout << "    -----------------------------------" << endl;
			cout << "                 HOSPITAL MANAGEMENT SYSTEM         " << endl;
			cout << "    -----------------------------------" << endl;
			cout << "      What category do you belong to" << endl;
			cout << "       1.Doctor" << endl;
			cout << "       2.Patient" << endl;
			cout << "       3.Admin" << endl;
			cout << "      Press 0 to exit." << endl;
			cout << endl << "      CHOOSE: ";
			cin >> choice;
		} while (choice < 0 || choice > 3);
		if (choice == 1)
		{
			cout << endl << endl << "     ------------------------------ " << endl;
			cout << "          WELCOME TO OLADOC  " << endl;
			cout<< "     ------------------------------ " << endl;
			cout  << "      Do you want to: " << endl;
			cout << "        1.Register" << endl;
			//cout << "        2.Login" << endl;
			cout << endl << "     CHOOSE: ";
			cin >> choose;

			if (choose == 1)
			{
				cout << "     ......................................." << endl;
				cout << "          ***/Doctor Registration/*****     " << endl;
				cout << "     ......................................." << endl;
				cout << "    Enter Name:";
				cin >> name;
				cout << "    Enter Mobile No:";
				cin >> phoneno;
				if (D.checkPhoneno(phoneno))
				{
					cout << "    Invalid Phone no" << endl;
					do
					{
						cout << "    Enter Mobile No:";
						cin >> phoneno;
					} while (!D.checkPhoneno(phoneno));

				}
				do
				{
					cout << "    Enter CNIC: ";
					cin >> cnic;
					while (cnic.length() != 13)
					{
						cout << "     --**CNIC not valid**--" << endl;
						cout << "    Enter CNIC: ";
						cin >> cnic;
					}
				} while (D.CheckCnicDoctor(cnic));

				cout << "    Enter email: ";
				cin >> email;
				if (D.CheckEmailDoctor(email))
				{
					cout << "     This email already exists " << endl;
					do
					{
						cout << "    Enter email: ";
						cin >> email;
					} while (!D.CheckEmailDoctor(email));
				}
				cout << "    Username: ";
				cin >> user_name;
				cout << "    Password: ";
				cout << "    Password (8 characters): ";
				while (ch != 13)            //13 is ascci code for enter
				{
					ch = _getch();
					if (ch != 13 && ch != 0)
					{
						pass += ch;
						cout << "*";
					}
				}

				//checks for password 
				for (int i = 0; i < pass.length(); i++)
				{
					if (pass[i] >= 65 && pass[i] <= 90)
					{
						u_c++;
					}
					else if (pass[i] >= 97 && pass[i] <= 122)
					{
						l_c++;
					}
					else if (pass[i] >= '0' && pass[i] <= '9')
					{
						num++;
					}
					else
					{
						special_char++;
					}
				}
				while (pass.length() != 8 || u_c == 0 || l_c == 0 || num == 0 || special_char == 0)
				{
					cout << endl << "     --**Password not valid**--" << endl;

					if (u_c == 0)
					{
						cout << "     --**Weak Password**--" << endl;
						cout << "    Add an upper case character" << endl;
					}
					else if (l_c == 0)
					{
						cout << "     --**Weak Password**--" << endl;
						cout << "    Add an lower case character" << endl;
					}
					else if (num == 0)
					{
						cout << "     --**Weak Password**--" << endl;
						cout << "    Add a digit " << endl;
					}
					else
					{
						cout << "     --**Weak Password**--" << endl;
						cout << "    Add a special character" << endl;
					}

					cout << "    Password: ";
					while (ch1 != 13)            //13 is ascci code for enter
					{
						ch1 = _getch();
						if (ch1 != 13 && ch1 != 0)
						{
							pass += ch1;
							cout << "*";
						}
					}
				}

				cout << endl << "    Confirm Password: ";
				while (c != 13)            //13 is ascci code for enter
				{
					c = _getch();
					if (c != 13 && c != 0)
					{
						confirm_pass += c;
						cout << "*";
					}
				}
				for (int i = 0; i < pass.length(); i++)
				{
					for (int j = 0; j < confirm_pass.length(); j++)
					{
						if (pass[i] != confirm_pass[i])
						{
							cout << "    * Passwords do not match *" << endl;
							cout << "    Confirm Password:";
							while (c1 != 13)            //13 is ascci code for enter
							{
								c1 = _getch();
								if (c1 != 13 && c1 != 0)
								{
									confirm_pass += c1;
									cout << "*";
								}
							}

						}
					}
				}


				system("cls");
				for (int i = 0; i < 13; i++)
				{
					cout << '\n';
				}
				cout << "      *** Successfull Registration ***" << endl;
				//using namespace std::this_thread;
				//using namespace std::chrono_literals;
				//using std::chrono::system_clock;
//
				//sleep_for(10ns);
				//sleep_until(system_clock::now() + 1s);

				system("cls");
				cout << "    Fill out your personal details " << endl;
				cout<<"     .............................." << endl;
				cout << "     Choose your specifictaion: " << endl;
				cout << "       1.Gynecologist" << endl;
				cout << "       2.Detmatologist" << endl;
				cout << "       3.Oncologist" << endl;
				cout << "       4.Orthopedic" << endl;
				cout << endl << "    CHOICE: ";
				cin >> schoose;
				while (schoose < 1 || schoose > 4)
				{
					cout << "    Invalid Choice" << endl;
					cin >> schoose;
				}
				if (schoose == 1)
				{
					specification = "    Gynecologist";
				}
				else if (schoose == 2)
				{
					specification = "    Detmatologist";
				}
				else if (schoose == 3)
				{
					specification = "    Oncologist";
				}
				else if (schoose == 4)
				{
					specification = "    Orthopedic";
				}


				int citychoose;
				cout << endl << endl << "    Choose City: " << endl;
				cout << "     1.Islamabad" << endl << "     2.Karachi" << endl << "     3.Lahore" << endl << "    Choose: ";
				cin >> citychoose;
				while (citychoose < 1 || citychoose>3)
				{
					cout << "    Invalid Choice" << endl;
					cin >> citychoose;
				}
				if (citychoose == 1)
				{
					workingcity = "    Islamabad";
					cout << endl;
					cout << "      // Choose Hospital //   " << endl << endl;
					for (int i = 0; i < Hos[0].no_of_hospitals; i++)
					{
						if (Hos[i].getCity() == "Islamabad")
						{
							cout << Hos[i].getHospitalName() << endl;
						}
					}
					cout << "    Write exact Hospital name showed that you work in: ";
					cin >> workinghospital;

				}
				else if (citychoose == 2)
				{
					workingcity = "    Karachi";
					cout << endl;
					cout << "      //Choose Hospital//   " << endl << endl;
					for (int i = 0; i < Hos[0].no_of_hospitals; i++)
					{
						if (Hos[i].getCity() == "Karachi")
						{
							cout << Hos[i].getHospitalName() << endl;
						}
					}
					cout << "    Write exact Hospital name showed that you work in: ";
					cin >> workinghospital;
				}
				else if (citychoose == 3)
				{
					workingcity = "    Lahore";
					cout << endl;
					cout << "      // Choose Hospital //   " << endl << endl;
					for (int i = 0; i < Hos[0].no_of_hospitals; i++)
					{
						if (Hos[i].getCity() == "Lahore")
						{
							cout << Hos[i].getHospitalName() << endl;
						}
					}
					cout << "    Write exact Hospital name showed that you work in: ";
					cin >> workinghospital;
				}

				cout << endl << "    Enter your working time in 24 hour clock" << endl;
				cout << "    Starting Time: ";
				cin >> stime;
				while (stime > 23 || stime < 0)
				{
					cout << "    Invalid Input" << endl;
					cout << "    Enter again: ";
					cin >> stime;
				}
				cout << "    Ending Time: ";
				cin >> etime;
				while (etime > 23 || etime < 0)
				{
					cout << "    Invalid Input" << endl;
					cout << "    Enter again: ";
					cin >> stime;
				}

				cout << endl << endl;
				cout << "    Enter your years of experience: ";
				cin >> workingexperience;
				D.DoctorstoreData(name, cnic, email, phoneno, user_name, pass, workingcity, workinghospital, specification, stime, etime, workingexperience);
			}


		//	else if (choose == 2)
		//	{
		//	cout << "     ......................................." << endl;
		//		cout << "        ***/ Doctor Login /*****" << endl;
		//		cout << "     ......................................." << endl;

		//		do
		//		{
		//			cout << "    Enter Username: ";
		//			cin >> user_name;

		//			if (D.CheckUsernameDoctor(user_name))
		//			{
		//				cout << "    Password (8 characters): ";
		//				cin >> pass;
		//			}
		//		} while (!D.CheckUsernameDoctor(user_name));

		//		do
		//		{
		//			if (!D.CheckPasswordDoctor(pass))
		//			{
		//				pass = { NULL };
		//				cout << endl << "    Wrong Password" << endl;
		//				cout << "    Password (8 characters): ";
		//				cin >> pass;
		//			}
		//		} while (!D.CheckPasswordDoctor(pass));

		//		cout << endl << endl << endl;
		//		cout << "    1. View Appointments" << endl;
		//		cout << "    2. Cancel Appointment" << endl;

		//		cout << "    Choose: ";
		//		cin >> schoose;
		//		while (schoose < 1 || schoose>2)
		//		{
		//			cout << "   Invalid input" << endl;
		//			cout << "   choose again : " << endl;
		//			cin >> schoose;
		//		}
		//		switch (schoose)
		//		{
		//		case 1:
		//			cout << "    Enter your Name: ";
		//			cin >> docname;
		//			App.displayDoctorAppointment(docname);

		//			break;
		//		case 2:
		//			//////////////////////////////////////////////////////////////////////////

		//			break;
		//		default:
		//			break;
		//		}


			}


    }
}
else if (choice == 2)
		{
		 cout << endl << endl << "     ------------------------------ " << endl;
		 cout << "           HOSPITAL MANAGEMENT SYSTEM  " << endl;
		 cout << "     ------------------------------ " << endl;
			cout << "    Do you want to: " << endl;
			cout << "     1.Register" << endl;
			//cout << "     2.Login" << endl;
			cout << "    CHOOSE" << endl;
			cin >> choose;
			if (choose == 1)
			{
				cout << "     ......................................." << endl;
				cout << "          ***/ Patient Registration /*****" << endl;
				cout << "     ......................................." << endl;
				cout << "    Enter name:";
				cin >> name;
				cout << "    Enter age:";
				cin >> age;
				if (age >= 18)
				{
					do
					{
						cout << "    Enter CNIC: ";
						cin >> cnic;
						while (cnic.length() != 13)
						{
							cout << "    --**CNIC not valid**--" << endl;
							cout << "    Enter CNIC: ";
							cin >> cnic;
						}
					} while (P.CheckCnicPatient(cnic));


				}

				cout << "    Username: ";
				cin >> user_name;
				cout << "    Password (8 characters): ";
				while (ch != 13)            //13 is ascci code for enter
				{
					ch = _getch();
					if (ch != 13 && ch != 0)
					{
						pass += ch;
						cout << "*";
					}
				}

				//checks for password 
				for (int i = 0; i < pass.length(); i++)
				{
					if (pass[i] >= 65 && pass[i] <= 90)
					{
						u_c++;
					}
					else if (pass[i] >= 97 && pass[i] <= 122)
					{
						l_c++;
					}
					else if (pass[i] >= '0' && pass[i] <= '9')
					{
						num++;
					}
					else
					{
						special_char++;
					}
				}
				while (pass.length() != 8 || u_c == 0 || l_c == 0 || num == 0 || special_char == 0)
				{
					cout << endl << "    --Password not valid--" << endl;

					if (u_c == 0)
					{
						cout << "    --Weak Password--" << endl;
						cout << "    Add an upper case character" << endl;
					}
					else if (l_c == 0)
					{
						cout << "    --Weak Password--" << endl;
						cout << "    Add an lower case character" << endl;
					}
					else if (num == 0)
					{
						cout << "    --Weak Password--" << endl;
						cout << "    Add a digit " << endl;
					}
					else
					{
						cout << "    --Weak Password--" << endl;
						cout << "    Add a special character" << endl;
					}

					cout << "    Password: ";
					while (ch1 != 13)            //13 is ascci code for enter
					{
						ch1 = _getch();
						if (ch1 != 13 && ch1 != 0)
						{
							pass += ch1;
							cout << "*";
						}
					}
				}

				cout << endl << "    Confirm Password: ";
				while (c != 13)            //13 is ascci code for enter
				{
					c = _getch();
					if (c != 13 && c != 0)
					{
						confirm_pass += c;
						cout << "*";
					}
				}
				for (int i = 0; i < pass.length(); i++)
				{
					for (int j = 0; j < confirm_pass.length(); j++)
					{
						if (pass[i] != confirm_pass[i])
						{
							cout << "    * Passwords do not match *" << endl;
							cout << "    Confirm Password:";
							while (c1 != 13)            //13 is ascci code for enter
							{
								c1 = _getch();
								if (c1 != 13 && c1 != 0)
								{
									confirm_pass += c1;
									cout << "*";
								}
							}

						}
					}
				}
				P.PatientstoreData(name, cnic, user_name, pass);

				int c, choice1;
				cout << endl << endl << "    ******// Registration Complete //******" << endl << endl;
				cout << endl << endl << "     ---------------------------------------- " << endl;


                
				cout << "          WELCOME TO APPOINTMENT SECTION  " << endl;
				cout << "     ------------------------------------------- " << endl;
				cout << "    Press:" << endl;
				cout << "      1. To Book Appointment" << endl;
				cout << "      2. To view Doctor Details" << endl;
				cout << "    CHOOSE: ";
				cin >> c;
				while (c < 1 || c>2)
				{
					cout << "    invalid input " << endl;
					cout << "    Enter Again: ";
					cin >> c;
				}
				switch (c)
				{
				case 1:


					cout << endl << "    ////**********////" << endl;
					cout << "    Press: " << endl;
					cout << "     1. Select Doctor by Specialisation" << endl;
					cout << "     2. Select Doctor by City" << endl;
					cout << "     3. Select Doctor by Hospital" << endl;
					cout << "   CHOOSE: ";
					cin >> choice1;
					while (choice1 < 1 || choice1 > 3)
					{
						cout << "    Invalid input" << endl;
						cout << "    Enter Again: ";
						cin >> choice1;
					}
					if (choice1 == 1)
					{
						int schoose;
						string speciality[4] = { "Gynecologist", "Detmatologist", "Oncologist", "Orthopedic" };
						string specialization;
						cout << "    SELECT SPECIFICATION  " << endl;
						cout << "    Press: " << endl;
						for (int i = 0; i < 4; i++)
						{
							cout << i + 1 << ". " << speciality[i] << endl;
						}
						cout << "    CHOOSE: ";
						cin >> schoose;
						while (schoose < 1 || schoose>4)
						{
							cout << "    Invalid input" << endl;
							cout << "    Enter Again: ";
							cin >> schoose;
						}
						specialization = speciality[schoose - 1];

						D.checkDoctorSpecification(specialization);

						int time;
						cout << endl << endl;
						cout << "    Enter exact name of doctor you want to book an appointmant with: ";
						cin >> choosedoctor;
						D.displayReviewDoctor(choosedoctor);
						App.Bookings(choosedoctor, name, cnic);
					}

					else if (choice1 == 2)
					{
						int citychoose;
						string listcities[3] = { "Karachi", "Islamabad", "Lahore" };
						string city;
						cout << endl << "      SELECT CITY   " << endl;
						for (int i = 0; i < 3; i++)
						{
							cout << i + 1 << ". " << listcities[i] << endl;
						}
						cout << "   Choose: ";
						cin >> citychoose;
						while (citychoose < 1 || citychoose>3)
						{
							cout << "    Inavlid Input" << endl;
							cout << "    Enter again: ";
							cin >> citychoose;
						}
						city = listcities[citychoose - 1];

						D.checkDoctorCity(city);
						cout << endl << endl;
						cout << "    Enter exact name of doctor you want to book an appointmant with: ";
						cin >> choosedoctor;
						D.displayReviewDoctor(choosedoctor);
						App.Bookings(choosedoctor, name, cnic);

					}

					else if (choice1 == 3)
					{
						int hospitalchoose;
						string hospital;
						cout << endl << "      SELECT HOSPITAL   " << endl;
						for (int i = 0; i < 15; i++)
						{
							cout << i + 1 << ". " << Hos[i].getHospitalName() << endl;
						}
						cout << "    Choose: ";
						cin >> hospitalchoose;
						while (hospitalchoose < 1 || hospitalchoose>15)
						{
							cout << "    Inavlid Input" << endl;
							cout << "    Enter again: ";
							cin >> hospitalchoose;
						}
						hospital = Hos[hospitalchoose - 1].getHospitalName();
						cout << endl << endl;
						D.checkDoctorHosp(hospital);

						cout << "    Enter exact name of doctor you want to book an appointmant with: ";
						cin >> choosedoctor;
						D.displayReviewDoctor(choosedoctor);
						App.Bookings(choosedoctor, name, cnic);

					}
					cout << "    Please rate the Doctor" << endl;
					cout << "    1-5 Star:  " << endl;
					cin >> star;
					D.setReview(choosedoctor, name, star);

					break;
				case 2:
					cout << "           * DOCTOR DETAILS *" << endl;
					cout << "NAME            EMAIL               PHONENO            SPECIFICATION   HOSPITAL              CITY            WORKING HOURS   " << endl;

					D.checkDoctorDetails();
					break;

				}

			}
			else if (choose == 2)
			{
			    cout << "     ......................................." << endl;
				cout << "          ***/ Patient Login /*****" << endl;
				cout << "     ......................................." << endl;
				do
				{
					cout << "    Enter Username: ";
					cin >> user_name;

					if (P.CheckUsernamePatient(user_name))
					{
						cout << "    Password (8 characters): ";
						cin >> pass;
					}
				} while (!P.CheckUsernamePatient(user_name));

				do
				{
					if (!P.CheckPasswordPatient(pass))
					{
						pass = { NULL };
						cout << endl << "    Wrong Password" << endl;
						cout << "    Password (8 characters): ";
						cin >> pass;
					}
				} while (!P.CheckPasswordPatient(pass));


				do
				{
					cout << endl << endl << "     ------------------------------ " << endl;
					cout << "          WELCOME TO Appointment Section  " << endl;
					cout << "     ------------------------------ " << endl;
					cout << endl << endl << endl;
					cout << "    1. Book Appointments." << endl;
					cout << "    2. View Appointments." << endl;
					/////////////////////////
					cout << "    0. exit." << endl;
					cout << "    Choose: ";
					cin >> schoose;
					while (schoose < 0 || schoose>2)
					{
						cout << "    Incorrect input." << endl;
						cout << "    Choose: ";
						cin >> schoose;
					}
					if (schoose == 1)
					{
						cout << "    Enter your Name: ";
						cin >> name;
						cout << endl << "    ////**********////" << endl;
						cout << "   Press: " << endl;
						cout << "   1. Select Doctor by Specialisation" << endl;
						cout << "   2. Select Doctor by City" << endl;
						cout << "   3. Select Doctor by Hospital" << endl;
						cout << "   CHOOSE: ";
						cin >> choice1;
						while (choice1 < 1 || choice1 > 3)
						{
							cout << "    Invalid input" << endl;
							cout << "    Enter Again: ";
							cin >> choice1;
						}
						if (choice1 == 1)
						{
							int schoose;
							string speciality[4] = { "Gynecologist", "Detmatologist", "Oncologist", "Orthopedic" };
							string specialization;
							cout << "    SELECT SPECIFICATION  " << endl;
							cout << "    Press: " << endl;
							for (int i = 0; i < 4; i++)
							{
								cout << i + 1 << ". " << speciality[i] << endl;
							}
							cout << "    CHOOSE: ";
							cin >> schoose;
							while (schoose < 1 || schoose>4)
							{
								cout << "    Invalid input" << endl;
								cout << "    Enter Again: ";
								cin >> schoose;
							}
							specialization = speciality[schoose - 1];

							D.checkDoctorSpecification(specialization);

							int time;
							cout << endl << endl;
							cout << "    Enter exact name of doctor you want to book an appointmant with: ";
							cin >> choosedoctor;
							D.displayReviewDoctor(choosedoctor);
							App.Bookings(choosedoctor, name, cnic);
						}

						else if (choice1 == 2)
						{
							int citychoose;
							string listcities[3] = { "    Karachi", "    Islamabad", "    Lahore" };
							string city;
							cout << endl << "      SELECT CITY   " << endl;
							for (int i = 0; i < 3; i++)
							{
								cout << i + 1 << ". " << listcities[i] << endl;
							}
							cout << "    Choose: ";
							cin >> citychoose;
							while (citychoose < 1 || citychoose>3)
							{
								cout << "    Inavlid Input" << endl;
								cout << "    Enter again: ";
								cin >> citychoose;
							}
							city = listcities[citychoose - 1];

							D.checkDoctorCity(city);
							cout << endl << endl;
							cout << "    Enter exact name of doctor you want to book an appointmant with: ";
							cin >> choosedoctor;
							D.displayReviewDoctor(choosedoctor);
							App.Bookings(choosedoctor, name, cnic);

						}

						else if (choice1 == 3)
						{
							int hospitalchoose;
							string hospital;
							cout << endl << "      SELECT HOSPITAL   " << endl;
							for (int i = 0; i < 15; i++)
							{
								cout << i + 1 << ". " << Hos[i].getHospitalName() << endl;
							}
							cout << "    Choose: ";
							cin >> hospitalchoose;
							while (hospitalchoose < 1 || hospitalchoose>15)
							{
								cout << "    Inavlid Input" << endl;
								cout << "    Enter again: ";
								cin >> hospitalchoose;
							}
							hospital = Hos[hospitalchoose - 1].getHospitalName();
							cout << endl << endl;
							D.checkDoctorHosp(hospital);

							cout << "    Enter exact name of doctor you want to book an appointmant with: ";
							cin >> choosedoctor;
							D.displayReviewDoctor(choosedoctor);
							App.Bookings(choosedoctor, name, cnic);

						}
						cout << "    Please rate the Doctor" << endl;
						cout << "    1-5 Star:  " << endl;
						cin >> star;
						D.setReview(choosedoctor, name, star);

					}
					else if (schoose == 2)
					{
						cout << "    Enter your Name: ";
						cin >> patname;
						App.displayPatientAppointment(patname);
					}

				} while (schoose != 0);
			}
		}



		else if (choice == 3)
		{
			cout << "    ***/ Admin Login /*****" << endl;
			do
			{
				cout << "    Enter Username: ";
				cin >> user_name;

				if (A.CheckUsernameAdmin(user_name))
				{
					cout << "    Password (8 characters): ";
					cin >> pass;
				}
			} while (!A.CheckUsernameAdmin(user_name));

			do
			{
				if (!A.CheckPasswordAdmin(pass))
				{
					pass = { NULL };
					cout << endl << "    Wrong Password" << endl;
					cout << "    Password (8 characters): ";
					cin >> pass;
				}
			} while (!A.CheckPasswordAdmin(pass));

			cout << endl << endl << endl;

			int c1;
			cout << "    1. View Doctor Details \n    2. View Patient Details \n    3. View Appointments\n    4. Cancel Appointments\nChoose: ";
			cin >> c1;
			while (c1 < 1 || c1>4)
			{
				cout << "    Inavlid Input\n Enter Again: ";
				cin >> c1;
			}
			string n;
			switch (c1)
			{
			case 1:
				D.checkDoctorDetails();
				break;
			case 2:
				cout << "NAME         CNIC          USERNAME " << endl;
				P.checkPatientDetails();
				break;
			case 3:
				App.displayAppointment();
				break;
			case 4:
				App.displayAppointment();
				cout << "    Enter name of the doctor whos appointment you want to delete" << endl;
				cin >> n;
				cout << "    ** Appointment Deleted **" << endl;
				break;
			default:
				break;
			}


		}



	} while (choice != 0);
}
#pragma once
#include<iostream>
#include"patient.h"

class Payment { 
private:
	int totalBill;
	string EGateway;
public:
	Payment()
	{

	}
	int setbill(int totalBill)
	{
		totalBill = totalBill;
	}
	string setgateway(string EGateway)
	{
		EGateway = EGateway;
	}
	int getbill()
	{
		return totalBill;
	}};
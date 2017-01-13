// Stock.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

#define TenMins 5
class msg
{
public:
	DWORD timeStamp;
	DWORD price;
	string label;
};

struct greater1{
	bool operator()(const msg& a, const msg& b)const{
		return a.timeStamp < b.timeStamp;
	}
};

class StockManager{
	map<string,vector<msg*>>stockPrice;

public:
	void addStock(msg* m);
	vector<msg*> getAvgStockLast10Minutes(string stockName);
};

void StockManager::addStock(msg* m)
{
	if (m == nullptr){
		return;
	}
	auto msgs = stockPrice.find(m->label);
	if (msgs != stockPrice.end())
	{
		msgs->second.insert(msgs->second.begin(), m);
	}
	else
	{
		stockPrice[m->label].push_back(m);
	}

}


vector<msg*> StockManager::getAvgStockLast10Minutes(string label){
	auto msgs = stockPrice.find(label);
	
	if (msgs == stockPrice.end())
		return vector<msg*>();

	vector<msg*>returnMsgs;
	DWORD current = GetTickCount();
	for (auto it = msgs->second.begin(); it != msgs->second.end(); it++){
		DWORD diff = (GetTickCount() - (*it)->timeStamp) / 1000;
		if (diff > TenMins)
		{
			break;
		}
		returnMsgs.push_back(*it);
	}

	return returnMsgs;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "enter the stock details: " << endl;
	StockManager manager;
	for (int i = 0; i < 5; i++)
	{
		string stockName;
		vector<msg*> msgs;
		cout << "enter the stock Name: " << endl;
		cin >> stockName;

		int price;
		do{
			msg* m = new msg();
			cout << "Enter price: ";
			cin >> price;
			m->price = price;
			m->timeStamp = GetTickCount();
			m->label = stockName;
			manager.addStock(m);
			if (i == 0)
				Sleep(400);
		} while (price != -1);

	}
	vector<msg*>v = manager.getAvgStockLast10Minutes("stock1");
	for (auto it = v.begin(); it != v.end(); it++){
		cout << "label: " << (*it)->label << "  price:  " << (*it)->price << "  TimeStamp:  " << (*it)->timeStamp << endl;
	}

	return 0;
}


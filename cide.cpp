#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct fileInfo
{
	string date;
	double adj_close, open, percent_change;
};


int main()
{
	vector<fileInfo> stock; // vector pof type fileinfo

	ifstream infile;
	string data, date, open, adj_close;
	int length;

	infile.open("MSFT.csv");
	if (!infile)
	{
		cout << "File open failure!";
		return 0;
	}
	//cout << "Opened successfully" << endl;

	//cout << "Date\t\tOpen\t\tHigh\t\tLow\t\t Close\t\tAdj Close\tVolume"<< endl; 

	getline(infile, data, '\n');
	while (infile.good())
	{
		getline(infile, date, ',');

		if (date != "")
		{
			//showing the Date
			cout << date << "\t";
			stock.push_back(i) == date; 
			// getting value called open
			getline(infile, open, ',');

			//showing the Open
			cout << open << "\t";

			// getting value called High
			getline(infile, data, ',');

			// getting value called Low
			getline(infile, data, ',');

			// getting value called close
			getline(infile, data, ',');

			// getting value called adj_close
			getline(infile, adj_close, ',');

			//showing Adj close
			cout << adj_close << "\n";

			// getting value called volume
			getline(infile, data, '\n');




		}



	}

	//cout << "data: " << data[3] << endl;

	return 0;
}


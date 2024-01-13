// https://www.geeksforgeeks.org/passing-vector-function-cpp/ 


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;






struct fileInfo
{
	string date;
	float adj_close, open, percent_change;
	int num_of_days;
};



void bubble_sort(vector<fileInfo>& bubble_stock)
{

	string temp_date;

	float temp_adj_close, temp_open, temp_percant_change;


	int size;

	size = bubble_stock.size();


	for (int b1 = 0; b1 < size; b1++)
	{
		for (int b2 = b1 + 1; b2 < size; b2++)
		{
			if (bubble_stock[b1].percent_change < bubble_stock[b2].percent_change)
			{
				// sorting dates
				temp_date = bubble_stock[b1].date;
				bubble_stock[b1].date = bubble_stock[b2].date;
				bubble_stock[b2].date = temp_date; 

				// sorting open
				temp_open = bubble_stock[b1].open;
				bubble_stock[b1].open = bubble_stock[b2].open;
				bubble_stock[b2].open = temp_open;


				// sorting adj close
				temp_adj_close = bubble_stock[b1].adj_close;
				bubble_stock[b1].adj_close = bubble_stock[b2].adj_close;
				bubble_stock[b2].adj_close = temp_adj_close;

				// soriting percent change
				temp_percant_change = bubble_stock[b1].percent_change;
				bubble_stock[b1].percent_change = bubble_stock[b2].percent_change;
				bubble_stock[b2].percent_change = temp_percant_change;



			}

		}



	}



	
}


int main()
{
	vector<fileInfo> stock; // vector of type fileinfo

	fileInfo getting_data;

	ifstream infile;
	string data, date, open, adj_close;
	int length, i = 0;

	infile.open("MSFT.csv");
	if (!infile)
	{
		cout << "File open failure!" << endl;
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

			getting_data.date = date;

			// getting value called open
			getline(infile, open, ',');
			getting_data.open = stof(open);
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
			getting_data.adj_close = stof(adj_close);
			//showing Adj close
			cout << adj_close << "\n";

			// getting value called volume
			getline(infile, data, '\n');

			//formula for getting percent change
			getting_data.percent_change = ((getting_data.adj_close / getting_data.open) * 100);


			i++;
			getting_data.num_of_days = i;

			stock.push_back(getting_data);
		}



	}

	cout << endl;

	/*cout << "open from the lol: " << getting_data.date << "\t" << getting_data.open << "\t" << getting_data.adj_close << "\t" << getting_data.percent_change << "\t i = " <<
		getting_data.num_of_days << endl << "stock 5: " << stock[4].date  << endl;*/

	int size;
	size = stock.size();

	bubble_sort(stock);


	cout << "work";

	for (int k = 0; k < size; k++)
	{
		//cout << "date\topen\tadj close\tPercent change\n";
		cout << stock[k].date << "\t" << stock[k].open << "\t" << stock[k].adj_close << "\t" << stock[k].percent_change << endl;


	}

	return 0;
}


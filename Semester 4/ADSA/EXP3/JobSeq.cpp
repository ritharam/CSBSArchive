#include <iostream>
using namespace std;

struct JobSeq
{
	int Job;
	int Profit;
	int Deadline;
};

int main()
{
	int n, Total = 0;
	cout << "Enter the number of elements : ";
	cin >> n;
	JobSeq jobs[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Job " << i + 1 << endl;
		jobs[i].Job = i;
		cout << "Enter Profit " << i + 1 << " :";
		cin >> jobs[i].Profit;
		cout << "Enter Deadline " << i + 1 << " :";
		cin >> jobs[i].Deadline;
	}
	// Maximum
	int m = jobs[0].Deadline;
	for (int i = 0; i < n; i++)
	{
		if (jobs[i].Deadline > m)
			m = jobs[i].Deadline;
	}
	// Descending Order
	JobSeq temp;
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (jobs[i].Profit < jobs[i + 1].Profit)
			{
				temp = jobs[i];
				jobs[i] = jobs[i + 1];
				jobs[i + 1] = temp;
			}
		}
	}
	// Enter into slot
	JobSeq Slots[m];
	for (int i = 0; i < m; i++)
	{
		Slots[i].Profit = 0;
		Slots[i].Job = 0;
		Slots[i].Deadline = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = jobs[i].Deadline; j > 0; j--)
		{
			if (Slots[j - 1].Deadline == 0)
			{
				Slots[j - 1] = jobs[i];
				break;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		cout << "Slot No. : " << i + 1 << " ";
		cout << "Job No. : " << Slots[i].Job + 1 << " ";
		cout << "Profit : " << Slots[i].Profit << " " << endl;
		Total += Slots[i].Profit;
	}
	cout << "Total Profit : " << Total;
	return 0;
}

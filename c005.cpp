//Test Data will make int type overflow, so without the limit of memory, use long long int.
#include <iostream>

using namespace std;

int main()
{
	int times;
	cin >> times; // The amount of test data.

	for (int i = 0; i < times; i++)
	{
		int farmers;// amount of farmers.
		cin >> farmers;
		long long int bonus = 0;
		for (int j = 0; j < farmers; j++)
		{
			long long int area, animals, eco_level;
			cin >> area >> animals >> eco_level; // Bonus = (Area / Animals) * Eco_Level * Animals = Area * Eco_Level.
			bonus += area * eco_level;
		}
		cout << bonus << '\n';// output the total bonus of 1 test data
	}
	return 0;
}

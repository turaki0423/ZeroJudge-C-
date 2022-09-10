#include <iostream>
#include <vector>

using namespace std;

int move_right(int current_pos, vector<int> pos_arr)
{
	if (current_pos == pos_arr.size() - 1 || (pos_arr[current_pos + 1] > pos_arr[current_pos]))
		return current_pos;
	return move_right(current_pos + 1, pos_arr);
}

int move_left(int current_pos, vector<int> pos_arr)
{
	if (current_pos == 0 || (pos_arr[current_pos - 1] > pos_arr[current_pos]))
		return current_pos;
	return move_left(current_pos - 1, pos_arr);
}

int end(int current_pos, vector<int> pos)
{
	int heightLoss_right = (current_pos >= pos.size() - 1) ? -99 : (pos[current_pos] - pos[current_pos + 1]);
	int heightLoss_left = (current_pos == 0) ? -99 : (pos[current_pos] - pos[current_pos - 1]);
	if (heightLoss_left < 0 && heightLoss_right < 0)
		return current_pos;
	return (heightLoss_left > heightLoss_right) ? move_left(current_pos, pos) : move_right(current_pos, pos);
}

int main()
{
	int amount;
	cin >> amount;
	vector<int> pos_height(0, amount);
	int temp_input_pos;
	int landing_pos;
	for (int i = 0; i < amount; i++)
	{
		cin >> temp_input_pos;
		pos_height.push_back(temp_input_pos);
	}
	cin >> landing_pos;
	landing_pos -= 1;
	cout << end(landing_pos, pos_height) + 1;
	return 0;
}

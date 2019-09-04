#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;

#define CARSUM 10000
#define ALLTIME 24*3600


struct carRecord {
	string ID;
	int TimeStamp;
};

bool cmp(int a, int b) {
	int abs_a = a > 0 ? a : (-1)*a;
	int abs_b = b > 0 ? b : (-1)*b;
	return abs_a < abs_b;
}

bool rec_cmp(carRecord a, carRecord b) {
	if (a.ID == b.ID) {
		return cmp(a.TimeStamp, b.TimeStamp);
	}
	else {
		return a.ID < b.ID;
	}
}

int Q1095(int argc, char const *argv[])
{
	// N is the number of records, K is the number of requests
	int N, K;
	cin >> N >> K;

	// Each record is stored in the corresponding vector according to its car ID
	vector<carRecord> rec_list(N);

	for (int i = 0; i < N; i++)
	{
		int h, m, s;
		string temp_id;
		string action;
		cin >> temp_id;
		scanf("%d:%d:%d", &h, &m, &s);
		cin >> action;

		// Notice that the negative number represent the in time
		// while the positive ones means out
		int TimeStamp = h * 3600 + m * 60 + s;
		if (action == "in") {
			TimeStamp *= -1;
		}

		rec_list[i].ID = temp_id;
		rec_list[i].TimeStamp = TimeStamp;
	}

	sort(rec_list.begin(), rec_list.end(), rec_cmp);

	vector<int> compareList;
	for (int i = 0; i < K; i++) {
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int compare = h * 3600 + m * 60 + s;
		compareList.push_back(compare);
	}

	int MaxParkingTime = 0;
	vector<string> LongParkCar;
	vector<int> car_time;
	car_time.resize(ALLTIME, 0);

	string carID = rec_list[0].ID;
	int tempPT = 0;
	for (int i = 0; i < N - 1; i++) {
		if (rec_list[i].TimeStamp <= 0 && rec_list[i + 1].TimeStamp > 0 && rec_list[i].ID == rec_list[i + 1].ID) {
			if (carID != rec_list[i].ID) {
				tempPT = 0;
				carID = rec_list[i].ID;
			}
			tempPT += rec_list[i].TimeStamp + rec_list[i + 1].TimeStamp;
			car_time[rec_list[i + 1].TimeStamp]--;
			car_time[(-1)*rec_list[i].TimeStamp]++;
			i++;

			if (tempPT > MaxParkingTime) {
				MaxParkingTime = tempPT;
				LongParkCar.clear();
				LongParkCar.push_back(carID);
			}
			else if (tempPT == MaxParkingTime) {
				LongParkCar.push_back(carID);
			}
		}
	}

	for (int i = 1; i < ALLTIME; i++) {
		car_time[i] += car_time[i - 1];
	}

	for (int i = 0; i < compareList.size(); i++) {
		cout << car_time[compareList[i]] << endl;
	}

	sort(LongParkCar.begin(), LongParkCar.end());
	for (int i = 0; i < LongParkCar.size(); i++) {
		cout << LongParkCar[i] << " ";
	}
	int h, m, s;
	h = MaxParkingTime / 3600;
	m = (MaxParkingTime % 3600) / 60;
	s = MaxParkingTime % 60;

	printf("%02d:%02d:%02d\n", h, m, s);
	system("pause");

	return 0;
}

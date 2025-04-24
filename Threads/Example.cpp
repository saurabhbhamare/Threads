#include<iostream>
#include<map>
#include<string>
#include<thread>
#include<chrono>
#include<vector>
using namespace std::chrono_literals;


void RefreshForecast(std::map<std::string, int>& data)
{
	while (true)
	{
		for (auto& item : data)
		{
			item.second++;
			//std::cout << item.first << ":" << item.second << std::endl;
		}
		std::this_thread::sleep_for(4000ms);
		//std::cout << "Temperature refreshed" << std::endl;
	}
}
void Function1()
{	
	for (int i = 0; i < 100; i++)
	{
		std::cout << '+';
	}
}
void Function2()
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << '-';
	}
}
int main()
{
	std::map<std::string, int> data
	{
		{"Madrid",20},
		{"New York",14},
		{"Milan",22},
		{"New Delhi",27}
	};

	std::thread backgroundWorker(RefreshForecast,std::ref( data));
	std::thread function1(Function1);
	std::thread function2(Function2);
	std::string city;
	std::cin >> city;

	for (auto item : data)
	{
		if (item.first == city)
		{
			std::cout << "temperature for the " << city << "is : " << item.second << std::endl;
		}
	}

	backgroundWorker.join();
}
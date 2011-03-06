#ifndef H_videoStore
#define H_videoStore

#include <iostream>
#include <string>
#include "customerList.h"
#include "videoList.h"

using namespace std;

class videoStore
{
public:

	void readVideoFile();

	void readCustomerFile();

	void addVideo();

	void addCustomer();

	bool isCustomer();

	bool videoInStock();

	videoCheckIn();

	videoCheckOut();

	void videoInfo();

	void customerInfo();

	void printAllVideos();

	void printAllVideoInfo();

	void printAllCustomers();

private:

	videoList videos;

	customerList customers;
};

#endif

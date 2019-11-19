#include "bike.h"
bike::bike(){
	char* bike_name;
	int bike_number;
}
bike::bike(int wheels,int maxSpeed){
	this->wheel_number = wheels;
	this->max_speed = maxSpeed;
}
bike::bike(int wheels,int maxSpeed,char* bikeName,int bikeNumber){
	this->wheel_number = wheels;
	this->max_speed = maxSpeed;
	this->bike_name = bikeName;
	this->bike_number = bikeNumber;
}
bike::bike(int wheels,int maxSpeed,char* bikeName,int bikeNumber,bool hasName){
        this->wheel_number = wheels;
        this->max_speed = maxSpeed;
        this->bike_name = bikeName;
        this->bike_number = bikeNumber;
	this->has_name = hasName;
}
int bike::get_bike_number(){
	return bike_number;
}
char* bike::get_bike_name(){
	return bike_name;
}
const char* bike::get_class_name(){
	return "bike";
}
void bike::set_bike_name(char* bikeName){
	bike_name = bikeName;
}
void bike::set_bike_number(int bikeNumber){
	bike_number = bikeNumber;
}


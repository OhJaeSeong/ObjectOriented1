#include "car.h"

car::car(){
	char* car_name;
}
car::car(int wheels, int maxSpeed){
	this->wheel_number = wheels;
	this->max_speed = maxSpeed;
}
car::car(int wheels,int maxSpeed, char* carName){
	this->wheel_number = wheels;
	this->max_speed = maxSpeed;
	this->car_name = carName;
}
car::car(int wheels,int maxSpeed, char* carName, bool hasName){
	this->wheel_number = wheels;
	this->max_speed = maxSpeed;
	this->car_name = carName;
	this->has_name = hasName;
}
char* car::get_car_name(){
	return car_name;
}
const char* car::get_class_name(){
	return "car";
}
void car::set_car_name(char* carName){
	car_name = carName;
}


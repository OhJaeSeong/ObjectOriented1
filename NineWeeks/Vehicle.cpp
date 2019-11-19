#include "Vehicle.h"

Vehicle::Vehicle(){
	int wheel_number;
	int max_speed;
	bool has_name;	
}
Vehicle::Vehicle(int wheels,int maxspeed){
       this->wheel_number = wheels;
	this->max_speed = maxspeed;
}
Vehicle::Vehicle(int wheels,int maxSpeed,bool hasName){
	this->wheel_number = wheels;
	this->max_speed = maxSpeed;
	this->has_name = hasName;
}
int Vehicle::get_wheel_number(){
	return wheel_number;
}
int Vehicle::get_max_speed(){
	return max_speed;
}
bool Vehicle::get_has_name(){
	return has_name;
}
const char* Vehicle::get_class_name(){
	return "Vehicle";
}
void Vehicle::set_wheel_number(int wheels){
	wheel_number = wheels;
}
void Vehicle::set_max_speed(int maxSpeed){
	max_speed = maxSpeed;
}
void Vehicle::set_has_name(bool hasName){
	has_name = hasName;
}


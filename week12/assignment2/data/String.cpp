#include "String.h"
#include "Object.h"

String::String(const std::string& str){
	this->_val = str;
}

std::string String::val(){
	return this->_val;
}

void String::set_val(const std::string& str){
	this->_val = str;
}

json_object* String::parse(const char * str, int length, char base){
	int& ex = json_object::_index;
	std::string result = "";
	while(ex < length){
		switch (str[ex]){	  
      		  case '\'':
         		return new String(result);	 
      		  default:
        	   	result += str[ex];
         		break;
		}
		ex++;
	}
	return NULL;
}

json_object::_type String::type(){
	return STRING;
}

std::string String::to_string(){
	return '\'' + this->_val+'\'';
}

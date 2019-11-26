#include "json_object.h"
#include "json_list.h"
#include "json_dict.h"
#include "data/Integer.h"
#include "data/String.h"

int json_object::_index = 0;
json_object* json_object::parse(const char * str, int length){
	json_object* st = NULL;
	while(_index < length){
		if(str[_index] == '{'){
			_index++;
			st = json_dict::parse(str,length);
		}
		else if(str[_index] == '['){
			_index++;
			st = json_list::parse(str,length);
		}
		else if(str[_index] == '\''){
			_index++;
			st = String::parse(str,length,'\'');		
		}
		else{
			if(str[_index] >= '0' && str[_index] <= '9'){
				st = Integer::parse(str,length);
			}
		}
		_index++;
	}
	_index = 0;
	return st;
}

json_object* json_object::parse(const std::string& parsed){
	return parse(parsed.c_str(), parsed.length());
}

#include "json_list.h"
#include "json_dict.h"
#include "json_object.h"
#include "data/Integer.h"
#include "data/String.h"
json_list::json_list(){
	v = std::vector<json_object*>();
}

json_object* json_list::parse(const char* str, int length){
	int& ex = json_object::_index;
	json_object* value = NULL;
	json_list* list = new json_list();
	while(ex < length){
		if(str[ex] == '\''){
			ex++;
			value = String::parse(str,length,'\'');
		}
		else if(str[ex] == ','){
			if(value != NULL){
				list->v.push_back(value);
				value = NULL;
			}
		}
		else if(str[ex] == '['){
			ex++;
			value = json_list::parse(str,length);
		}
		else if(str[ex] ==']'){
			if(value != NULL){
				list->v.push_back(value);
			}
			return list;
		}
		else if(str[ex] == '{'){
			value = json_dict::parse(str,length);
		}
		else if('0' <= str[ex] && '9' >= str[ex]){
			value = Integer::parse(str,length);
			ex -= 1;
		}
		ex++;
	}
	return NULL;
}

json_object* json_list::operator[](int key) const{
	return v[key];
}

json_object::_type json_list::type(){
	return json_object::LIST;
}

std::string json_list::to_string(){
	std::string s = "[";
	if(v.size() == 0){
		return "[]";
	}
	else{
		for(int k = 0; k < v.size() -1; k++){
			s += v[k]->to_string() + ", ";
		}
		s += v[v.size() - 1]->to_string()+"]";
		return s;
	}
}

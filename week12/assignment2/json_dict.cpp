#include "json_dict.h"
#include "json_list.h"
#include "json_object.h"
#include "data/Integer.h"
#include "data/String.h"

json_dict::json_dict(){

}

json_object* json_dict::parse(const char * str,int length){
	int num = 0;
	int& ex = json_object::_index;
	json_dict *dict = new json_dict();
	json_object *key = NULL;
	json_object *value = NULL;
	bool isKey = true;
	while(ex < length){
		if(str[ex] == '\''){
			ex++;
			if(isKey){
				key = String::parse(str,length,'\'');
			}
			else{
				value = String::parse(str,length,'\'');
			}
		}
		else if(str[ex] == ':'){
			isKey = false;
		}
		else if(str[ex] == ','){
			num = dict->find(key);
			if(num != -1){
				dict->v[num].second = value;
			}
			else{
				dict->put(key,value);
			}
			isKey = true;
		}
		else if(str[ex] == '['){
			ex++;
			value = json_list::parse(str,length);
		}
		else if(str[ex] == '{'){
			ex++;
			value = json_dict::parse(str,length);
		}
		else if(str[ex] == '}'){
			num = dict->find(key);
			if(num != -1){
				dict->v[num].second = value;
			}
			else{
				dict->put(key,value);
			}
			return dict;
		}
		else if(str[ex] == ' '){
		}
		else{
			if(isKey){
				key = Integer::parse(str,length);
			}
			else{
				value = Integer::parse(str,length);
				ex--;
			}
		}
		ex++;
	}
	return dict;
}
void json_dict::put(json_object* key, json_object* val){
	v.push_back({key,val});
}

int json_dict::find(json_object* key){
	std::string target = key->to_string();
	for(int k = 0; k < v.size(); k++){
		if(v[k].first->to_string() == target){
			return k;
		}
	}
	return -1;
}

json_object* json_dict::operator[](json_object* key) const{
	if(key->type() == json_object::INT){
		return operator[](atoi(key->to_string().c_str()));
	}
	else if(key->type() == json_object::STRING){
		return operator[](key->to_string());
	}

	return NULL;
}

json_object* json_dict::operator[](const std::string& key) const{
   std::string _key = '\'' + key + '\'';
   for (std::pair<json_object*, json_object*> _tmp : v){
      if (_tmp.first->to_string() == _key){
         return _tmp.second;
      }
   }
   return NULL;
}

json_object* json_dict::operator[](int key) const{
   for (std::pair<json_object*, json_object*> _tmp : v){
      int _key = atoi(_tmp.first->to_string().c_str());
      if (_key == key){
         return _tmp.second;
      }
   }
   return NULL;
}

json_object::_type json_dict::type(){
	return DICT;
}
std::string json_dict::to_string(){
	if(v.size() == 0){
		return "{}";
	}
	else{
		std::string s = "{";
		for(int j = 0; j < v.size()-1; j++){
			s += v[j].first->to_string()+": "+ v[j].second->to_string();
			s += ", ";
		}
		s += v[v.size() - 1].first->to_string() + ": " + v[v.size() - 1].second->to_string() + '}';
		return s;
	}
}

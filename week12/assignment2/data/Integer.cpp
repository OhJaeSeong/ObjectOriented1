#include "Integer.h"

Integer::Integer(int value){
   _val = value;
}

int Integer::val(){
   return _val;
}

void Integer::set_val(const int& value){
   _val = value;
}

json_object::_type Integer::type(){
   return INT;
}

std::string Integer::to_string(){
   return std::to_string(_val);
}

json_object* Integer::parse(const char * str, int length){
   int start = _index;
   while (str[_index] >= '0' && str[_index] <= '9') {
      _index++;
   }
   std::string s = std::string(str);
   int last = _index - start;
   return new Integer(std::stoi(s.substr(start, last)));
}

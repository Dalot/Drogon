//this file is generated by program(drogon_ctl) automatically,don't modify it!
#include "ListParameters.h"
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>
#include <deque>
#include <queue>
std::string ListParameters::genText(const DrTemplateData& ListParameters_view_data)
{
	std::stringstream ListParameters_tmp_stream;
	ListParameters_tmp_stream << "<!DOCTYPE html>\n";
	ListParameters_tmp_stream << "<html>\n";
    auto para=ListParameters_view_data.get<std::map<std::string,std::string>>("parameters");
	ListParameters_tmp_stream << "<head>\n";
	ListParameters_tmp_stream << "    <meta charset=\"UTF-8\">\n";
	ListParameters_tmp_stream << "    <title>";
{
    auto & val=ListParameters_view_data["title"];
    if(val.type()==typeid(const char *)){
        ListParameters_tmp_stream<<*any_cast<const char *>(&val);
    }else if(val.type()==typeid(std::string)||val.type()==typeid(const std::string)){
        ListParameters_tmp_stream<<*any_cast<const std::string>(&val);
    }
}
	ListParameters_tmp_stream << "</title>\n";
	ListParameters_tmp_stream << "</head>\n";
	ListParameters_tmp_stream << "<body>\n";
	ListParameters_tmp_stream << "    ";
 if(para.size()>0){
	ListParameters_tmp_stream << "    <H1>Parameters</H1>\n";
	ListParameters_tmp_stream << "    <table border=\"1\">\n";
	ListParameters_tmp_stream << "      <tr>\n";
	ListParameters_tmp_stream << "        <th>name</th>\n";
	ListParameters_tmp_stream << "        <th>value</th>\n";
	ListParameters_tmp_stream << "      </tr>\n";
	ListParameters_tmp_stream << "      ";
 for(auto iter:para){
	ListParameters_tmp_stream << "      <tr>\n";
	ListParameters_tmp_stream << "        <td>";
ListParameters_tmp_stream<<iter.first;
	ListParameters_tmp_stream << "</td>\n";
	ListParameters_tmp_stream << "        <td>";
 ListParameters_tmp_stream<<iter.second;
	ListParameters_tmp_stream << "</td>\n";
	ListParameters_tmp_stream << "      </tr>\n";
	ListParameters_tmp_stream << "      ";
}
	ListParameters_tmp_stream << "    </table>\n";
	ListParameters_tmp_stream << "    ";
 }else{
	ListParameters_tmp_stream << "    <H1>no parameter</H1>\n";
	ListParameters_tmp_stream << "    ";
}
	ListParameters_tmp_stream << "</body>\n";
	ListParameters_tmp_stream << "</html>\n";
return ListParameters_tmp_stream.str();
}
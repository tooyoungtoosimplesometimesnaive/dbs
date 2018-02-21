#include <iostream>
#include <string>
#include <fstream>

#include "db.h"

void db::set(std::string key, std::string value)
{
	std::ofstream out;
	out.open(file_name, fstream::app);
	out << key;
	out << db::DELIMITER;
	out << value;
	out << db::RECORD_DELIMITER;
}

std::string db::get(std::string key)
{
	return "";
}

void db::write_info()
{
	for (auto it = kv.begin(); it != kv.end(); it++)
	{
		//write to a file;
		// it -> first, it-> second
	}
}

void db::load_info()
{
}




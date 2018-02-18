#ifndef DB_H
#define DB_H

#include <string>
#include <fstream>

class db {
public:
	db(std::string fn) : file_name("./.dbs/" + fn) 
	{
		std::fstream file;
		file.open(file_name, fstream::out);
		file.close();
	}

	void set(std::string key, std::string value);
	std::string get(std::string key);
	void info();

private:
	std::string file_name;
}

#endif


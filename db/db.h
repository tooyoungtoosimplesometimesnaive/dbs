#ifndef DB_H
#define DB_H

#include <string>
#include <fstream>

class db {
public:
	static std::string DELIMITER = "%";
	static std::string RECORD_DELIMITER = "%";
	db(std::string fn) : file_name("./.dbs/" + fn) 
	{
		std::fstream file;
		file.open(file_name, fstream::out);
		file.close();
	}

	~db()
	{
		write_info();
	}
	void set(std::string key, std::string value);
	std::string get(std::string key);

private:

	void write_info();
	void load_info();
	// key: the string of key, value: position (offset)
	std::unordered_map<std::string, int> kv;
	std::string file_name;
}

#endif


#ifndef DB_H
#define DB_H

#include <string>
#include <fstream>

class db {
public:
	static std::string DELIMITER = "%";
	static std::string RECORD_DELIMITER = "%";

	static std::string PATH = "./.dbs/";
	static std::string INFO_FILE = ".info.kv";
	static std::string INFO_START_OFFSET = ".info.start_offset";
	static std::string DEFAULT_FILE_NAME = ".default.db";

	db()
	{
		file_name = PATH + DEFAULT_FILE_NAME;
		load_info();
	}

	db(std::string fn)
	{
		load_info();
		// std::fstream file;
		// file.open(file_name, fstream::out);
		// file.close();
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

	// The starting offset every time we start the app.
	int start_offset;
}

#endif


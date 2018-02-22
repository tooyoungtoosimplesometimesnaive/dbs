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
	int length = key.size() + value.size() + 2;
	start_offset += length;
	kv[key] = start_offset;
}

std::string db::get(std::string key)
{
	int p = kv[key];
	std::ifstream i(file_nakme);
	i.seekg(p);

	return "";
}

void db::write_info()
{
	std::ofstream o(db::PATH + db::INFO_FILE);
	for (auto it = kv.begin(); it != kv.end(); it++)
	{
		//write to a file;
		// it -> first, it-> second
		o << it->first << " " << it->second << "\n";
	}
	o.close();

	// write to offset:
	std::ofstream o2(db::PATH + db::INFO_START_OFFSET);
	o2 << start_offset;
	o2.close();
}

void db::load_info()
{
	std::string f = db::PATH + db::INFO_FILE;
	std::ifstream i(f);
	while (i) {
		std::string k;
		int v;
		i >> k >> v;
		kv[k] = v;
	}
	if (i) {
		i.close();
	}

	std::ifstream i2(db::PATH + db::INFO_START_OFFSET);
	if (i2) {
		i2 >> start_offset;
	} else {
		start_offset = 0;
	}

}


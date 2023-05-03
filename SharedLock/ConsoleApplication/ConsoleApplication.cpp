#include <iostream>
#include <map>
#include <shared_mutex>
#include <string>
#include <thread>
#include <vector>
std::shared_mutex rw_mutex;
std::map<std::string, int> string_map;


void insert(const std::string& key, int value) {
	std::unique_lock<std::shared_mutex> lock(rw_mutex);
	string_map[key] = value;
	std::cout << "Inserted [" << key << ": " << value << "]" << std::endl;
}


// shared_lock 配合着shared_mutex互斥量的可以多个进行读取，但是如果是std::mutex 就是没有起作用了，不管读写都要等
bool find(const std::string& key) {
	std::shared_lock<std::shared_mutex> lock(rw_mutex);
	auto it = string_map.find(key);
	if (it != string_map.end()) {
		std::cout << "Found [" << key << ": " << it->second << "]" << std::endl;
		return true;
	}
	else {
		std::cout << "Key not found: " << key << std::endl;
		return false;
	}
}
int main() {
	// 初始化映射
	string_map = {
		{"apple", 1},
		{"banana", 2},
		{"orange", 3},
	};
	// 创建插入和查找线程
	std::vector<std::thread> threads;
	for (int i = 0; i < 5; ++i) {
		threads.push_back(std::thread(insert, "key" + std::to_string(i), i));
		threads.push_back(std::thread(find, "key" + std::to_string(i)));
	}
	// 等待所有线程完成
	for (auto& t : threads) {
		t.join();
	}
	return 0;
}
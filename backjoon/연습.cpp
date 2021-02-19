#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
	map<string, int>m;
	m.insert(make_pair("a", 1));
	m.insert(make_pair("b", 2));
	m.insert(make_pair("c", 3));
	m.insert(make_pair("d", 4));
	m.insert(make_pair("e", 5));
	m["f"] = 6;
	m.erase("b");
	m.erase("f");
	if (!m.empty())cout << "m.size():" << m.size()<<endl;
	cout << "c:" << m.find("c")->first << endl;
	cout << "c_second:" << m.find("c")->second << endl;
	cout << endl;
	cout << "c count:" << m.count("c") << endl;
	cout << "traverse" << endl;
	for (auto it = m.begin();it != m.end();it++) {
		cout << "key:" << it->first << "value:" << it->second << endl;
	}
	
}
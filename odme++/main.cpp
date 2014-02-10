#include <odme.h>
#include <iostream>

using namespace std;

int main()
{
	std::string hi;
	odme *master = new odme("odme");
	master->connect("irc.efnet.com");
	cout << "test123\n";
	cin >> hi;
	return 0;
}
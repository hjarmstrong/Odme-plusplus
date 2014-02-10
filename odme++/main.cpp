#include <odme.h>
#include <iostream>

using namespace std;

int main()
{
	std::string hi;
	odme *master = new odme("odme", "irc.efnet.com");
	master->join("#testingodme");
	cout << "test123\n";
	cin >> hi;
	return 0;
}
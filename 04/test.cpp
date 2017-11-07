
#include "std_lib_facilities.h"

using namespace std;

int main() {

	const int a =1;
	constexpr int b =2;

	vector<int> v = {5, 7, 9, 8, 4, 3};
	vector<int> v1(6);

    for (int i=0; i<v.size(); ++i)
        cout << v[i] << "\n";

    cout << "\n\n";

    v.push_back(14);
	for (int x: v)                          // range for loop
        cout << x << "\n";

	return 0;
}

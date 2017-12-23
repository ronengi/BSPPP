#include "Chrono.hpp"
#include "std_lib_facilities.h"

using namespace Chrono;

int main() {

    Date today = Date{2000, Month::feb, 29};
    cout << today << '\n';

    Date tomorrow = today;

    tomorrow.add_year(3);
    cout << tomorrow << '\n';

    tomorrow.add_month(2);
    cout << tomorrow << '\n';

    tomorrow.add_month(10);
    cout << tomorrow << '\n';

    tomorrow.add_day(10);
    cout << tomorrow << '\n';

}

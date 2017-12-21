#include "Chrono.hpp"
#include "std_lib_facilities.h"


namespace Chrono {

    // member function definitions

    Date::Date(int yy, Month mm, int dd)
        : y{yy}, m{mm}, d{dd}
    {
        if(!is_date(yy, mm, dd)) throw Invalid{};
    }

    const Date& default_date() {
        static Date dd{2001, Month::jan, 1};    // start of 21 century
        return dd;
    }

    Date::Date()
        : y{default_date().year()},
        m{default_date().month()},
        d{default_date().day()}
    {
    }

    void Date::add_day(int n) {
        for(int i = 0; i < n; ++i) {
            ++d;
            if (!is_date(y, m, d)) {
                d = 1;
                add_month(1);
            }
        }
    }

    void Date::add_month(int n) {
        for(int i = 0; i < n; ++i) {
            if (m == Month::dec) {
                m = Month::jan;
                add_year(1);
            }
            else
                m = Month(int(m) + 1);
        }
        if (!is_date(y, m, d))
            d = last_day_of_month(y, m);
    }

    void Date::add_year(int n) {
        y += n;
        if (!is_date(y, m, d))
            d = last_day_of_month(y, m);
    }


    // helper functions

    bool is_date(int y, Month m, int d) {
        if (y <= 0)
            return false;
        if (m < Month::jan  || Month::dec < m)
            return false;
        if (d <= 0)
            return false;
        int days_in_month = last_day_of_month(y, m);
        if (d > days_in_month)
            return false;
        return true;
    }


    int last_day_of_month(int y, Month m) {
        if (y <= 0)
            throw Invalid{};
        if (m < Month::jan  || Month::dec < m)
            throw Invalid{};

        int days_in_month = 31;
        switch(m) {
        case Month::feb:
            days_in_month = leap_year(y) ? 29 : 28;
            break;
        case Month::apr: case Month::jun: case Month::sep: case Month::nov:
            days_in_month = 30;
            break;
        }

        return days_in_month;
    }


    bool leap_year(int y) {
        if ((y % 4) == 0) {
            if ((y % 100) == 0) {
                if ((y % 400) == 0)
                    return true;
                return false;
            }
            return true;
        }
        return false;
    }


    bool operator==(const Date& a, const Date& b) {
        return a.year() == b.year()
            && a.month() == b.month()
            && a.day() == b.day();
    }


    bool operator!=(const Date& a, const Date& b) {
        return !(a==b);
    }


    ostream& operator<<(ostream& os, const Date& d) {
        return os << '(' << d.year()
            << ',' << int(d.month())
            << ',' << d.day() << ')';
    }


    istream& operator>>(istream& is, Date& dd) {
        int y, m, d;
        char c1, c2, c3, c4;
        is >> c1 >> y >> c2 >> m >> c3 >> d >> c4;
        if (!is)    return is;
        if (c1 != '(' || c2 != ',' || c3 != ',' || c4 != ')') {
            is.clear(ios_base::failbit);
            return is;
        }
        dd = Date(y, Month(m), d);
        return is;
    }



    Day day_of_week(const Date& d) {}


    Date next_Sunday(const Date& d) {}


    Date next_weekday(const Date& d) {}

}

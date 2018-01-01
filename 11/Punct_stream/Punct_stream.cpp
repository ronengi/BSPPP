#include "Punct_stream.hpp"


Punct_stream& Punct_stream::operator>>(string& s) {
    while (!(buffer >> s)) {
        if (buffer.bad() || !source.good())
            return *this;
        buffer.clear();

        string line;
        getline(source, line);              // get a line from source

        for (char& ch : line) {
            if (is_whitespace(ch))
                ch = ' ';
            else if (!sensitive)
                ch = tolower(ch);
        }

        buffer.str(line);               // put string into stream
    }
    return *this;
}

bool Punct_stream::is_whitespace(char c) {
    for (char w : white)
        if (c ==w)
            return true;
    return false;
}

Punct_stream::operator bool() {
    return !(source.fail() || source.bad()) && buffer.good();
}

#include <string>
#include <cctype>
using namespace std;

class RunLengthEncoding
{
public:
    static string decode(const string &text)
    {
        string result;
        string current_number;
        int total_length = 0;
        char c;

        for (int i = 0; i < text.length(); i++)
        {
            c = text[i];
            if (isdigit(c))
            {
                current_number += c;
            }
            else
            {
                if (current_number.length() > 2)
                    return "TOO LONG";

                int count = current_number.empty() ? 1 : stoi(current_number);
                total_length += count;

                if (total_length > 50)
                    return "TOO LONG";

                result.append(count, c);
                current_number.clear();
            }
        }

        return result;
    }

    string decodeDepreciated(string text)
    {
        int n = text.length();
        string res = "";
        string temp;
        int i;
        for (i = 0; i < n; i++)
        {

            int count = 0;
            int index = i;

            while (isdigit(text[i]))
            {
                count = count * 10 + (text[i] - '0');
                i++;
            }

            temp = text[i];
            if (res.size() + count > 50)
            {
                return "TOO LONG";
            }
            for (int j = 0; j < count - 1; j++)
            {
                temp += text[i];
            }

            res = res + temp;
        }
        return res;
    }
};
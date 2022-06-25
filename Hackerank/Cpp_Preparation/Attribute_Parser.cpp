#include <sstream>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N, Q;

    map<string, string> data;
    cin >> N >> Q;
    cin.ignore();
    string cur = "", attr_name, attr_value;

    for (int i = 0; i < N; i++)
    {
        string line, tag, extract;
        getline(cin, line);
        stringstream ss(line);

        while (getline(ss, extract, ' '))
        {
            if (extract[0] == '<')
            {

                if (extract[1] != '/')
                {
                    tag = extract.substr(1);
                    if (tag[tag.length() - 1] == '>')
                    {
                        tag.pop_back();
                    }

                    if (cur.size() > 0)
                    {
                        cur += "." + tag;
                    }
                    else
                    {
                        cur = tag;
                    }
                }
                else
                {
                    tag = extract.substr(2, (extract.find('>')) - 2);

                    int pcc = cur.find("." + tag);

                    if (pcc != string::npos)
                    {
                        cur = cur.substr(0, pcc);
                    }
                    else
                    {
                        cur = "";
                    }
                }
            }

            else if (extract[0] == '"')
            {
                int pcc = extract.find_last_of('"');
                attr_value = extract.substr(1, pcc - 1);
                data[attr_name] = attr_value;
            }
            else
            {
                if (extract != "=")
                {
                    attr_name = cur + "~" + extract;
                }
                // cout << attr_name << endl;
            }
        }
    }

    for (int i = 0; i < Q; i++)
    {
        string query;
        getline(cin, query);

        map<string, string>::iterator itm = data.find(query);

        if (itm != data.end())
        {
            cout << itm->second << endl;
        }
        else
        {
            cout << "Not Found!" << endl;
        }
    }
}
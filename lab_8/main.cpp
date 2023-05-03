#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
using namespace std;

struct Comparer
{
    bool operator()(const pair<string, int> &left, const pair<string, int> &right) const
    {
        if (left.second != right.second)
        {
            return left.second < right.second;
        }
        else
        {
            return left.first > right.first;
        }
    }
};

int main()
{
    int ok = -1;
    string sep = ", .!?";
    string word = "";
    ifstream infile("input.txt");
    string sentence;
    map<string, int> map;

    if (infile)
    {                              // check if file was opened successfully
        getline(infile, sentence); // read entire line into the string
    }
    cout << "\n";
    for (auto x : sentence)
    {
        if (x >= 'A' && x <= 'Z')
            x += 32;
        ok = 0;
        for (int i = 0; i < sep.size(); i++)
        {
            if (x == sep[i])
            {
                ok = 1;
                break;
            }
        }
        if (ok == 1)
        {
            if (word != "")
                map[word]++; // put word in map and increase value
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    if (word != "")
        map[word]++; // add the last word of the sentence

    std::priority_queue<pair<string, int>, vector<pair<string, int>>, Comparer> q;
    for (auto &pair : map)
    {
        q.push(pair);
    }

    while (!q.empty())
    {
        std::pair<string, int> pair = q.top();
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        q.pop();
    }

    // std::map<std::string, int>::iterator it = map.begin();
    // while (it != map.end())
    // {
    //     std::cout << "Key:" << it->first << ", Value: " << it->second << std::endl;
    //     ++it;
    // }
    infile.close(); // close file when done
    return 0;
}
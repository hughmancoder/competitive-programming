#include <bits/stdc++.h>
using namespace std;


int getDistance(pair<int, int> i, pair<int, int> j)
{
    return (i.first - j.first) * (i.first - j.first) + (i.second - j.second) * (i.second - j.second);
}

// Time Complexity O(n^3)
// Space Complexity O(n), if you flatten out group, its effectively distance. And distance is 2n

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> distances;
    vector<vector<pair<int, int>>> groups;

    // getting all possible distance O(n)
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        distances.push_back({a, b});
    }

    // Creating the best match. It is always optimal to try and match the cloest point to eachother O((n/2)+1) -> O(n)
    // Charlie : think Kruskals MST which is greedy

    //Final complexity is essentially O(n^3)
    while (!distances.empty())
    {

        // important because if the number of distances is odd, then ythat needs to be in a group by itself
        if (distances.size() == 1)
        {
            vector<pair<int, int>> temp;
            temp.push_back(distances[0]);
            groups.push_back(temp);
            distances.pop_back();
            continue;
        }

        pair<int, int> a;
        pair<int, int> b;
        int minDistance = INT_MAX;


        // finding best match O(n^2) 
        for (auto i : distances)
        {
            for (auto j : distances)
            {
                if (i != j)
                {
                    int val = getDistance(i, j);
                    if (val < minDistance)
                    {
                        a = i;
                        b = j;
                        minDistance = val;
                    }
                }
            }
        }

        // Removing the two best matches from the original distance vector
        // O(n)
        for (int j = 0; j < distances.size(); j++)
        {
            if (distances[j] == a)
            {
                distances.erase(distances.begin() + j);
            }
        }

        // O(n)
        for (int j = 0; j < distances.size(); j++)
        {
            if (distances[j] == b)
            {
                distances.erase(distances.begin() + j);
            }
        }

        vector<pair<int, int>> temp;
        temp.push_back(a);
        temp.push_back(b);
        groups.push_back(temp);
    }


    
    // At this point, you have merged n into at most n/2+1 amount of groups
    int minDistance = INT_MAX;

    // For every group, Aprox  O(n)
    for (auto group : groups)
    {
        // For every group, Aprox  O(n)
        for (auto group2 : groups)
        {
            // not the same group
            if (group != group2)
            {
                // O(2 * 2) || O(2*1)
                for (auto i : group)
                {
                    for (auto j : group2)
                    {
                        // find the minimum distance amongst all groups
                        minDistance = min(minDistance, getDistance(i,j));
                    }
                }
            }
        }
    }
    cout << minDistance << endl;

    return 0;
}
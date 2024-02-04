#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CorporationSalary {
public:
    long totalSalary(vector<string> relations) {
        int n = relations.size();
        vector<long> salaries(n, -1);
        long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += getSalary(i, relations, salaries);
        }

        return sum;
    }

private:
    long getSalary(int i, const vector<string>& relations, vector<long>& salaries) {
        if (salaries[i] != -1) {
            return salaries[i];
        }
        
        long salary = 0;
        for (int j = 0; j < relations[i].size(); j++) {
            if (relations[i][j] == 'Y') {
                salary += getSalary(j, relations, salaries);
            }
        }
        if (salary == 0) {
            salary = 1;
        }
        salaries[i] = salary;
        return salary;
    }
};


#include <vector>
#include <algorithm>

class FairWorkload {
public:
    int getMostWork(std::vector<int> folders, int workers) {
        int left = 0; // max cost of folders
        int right = 0; // total cost of folders
        for (int i = 0; i < folders.size(); i++) {
            right += folders[i];
            left = std::max(left, folders[i]);
        }

        // the optimal partition (max_load or mid) should be somewhere in between left and right
        while (left < right) {
            int mid = (left + right) / 2;
            if (is_valid_partition(folders, workers, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool is_valid_partition(const std::vector<int>& folders, int workers, int max_load) {
        int total_folders = 0;
        int workers_assigned = 1;

        for (int i = 0; i < folders.size(); i++) {
            int folder_count = folders[i];
            total_folders += folder_count;
            if (total_folders > max_load) {
                workers_assigned++;
                total_folders = folder_count;
            }
        }
        // partition is valid if we can assign the folders to workers
        return workers_assigned <= workers;
    }
};
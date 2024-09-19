#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool can_add_closest_point(const vector<int>& points) {
    int n = points.size();
    
    // Iterate through each pair of consecutive points
    for (int i = 0; i < n - 1; ++i) {
        int p1 = points[i];
        int p2 = points[i + 1];
        
        // Calculate midpoint
        if ((p1 + p2) % 2 == 0) { // Check if midpoint is an integer
            int midpoint = (p1 + p2) / 2;
            
            // Check if this midpoint is not in the existing set
            if (find(points.begin(), points.end(), midpoint) == points.end()) {
                bool valid = true;
                
                // Check if midpoint is closest to both p1 and p2
                for (int pt : points) {
                    if (pt != p1 && pt != p2) {
                        if (abs(midpoint - pt) < abs(p1 - pt) || abs(midpoint - pt) < abs(p2 - pt)) {
                            valid = false;
                            break;
                        }
                    }
                }
                
                if (valid) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i];
        }
        
        if (can_add_closest_point(points)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

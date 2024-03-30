#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

/* int main() {
    int n, m;
    cout << "\nEnter number of cards:";
    cin >> n;
    cout << "\nEnter max flips of cards:";
    cin >> m;
    

    vector<int> A(n), B(n);
    cout << "\nEnter face up cards:";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    //Print A vector
    cout << "\nFace up cards: ";
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }

    cout << "\nEnter face down cards:";
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    cout << "\nFace down cards: ";
    for (int i = 0; i < n; ++i) {
        cout << B[i] << " ";
    }
    cout <<"\n";

    // Sort the-th card by the difference between A[i] and B[i]
    vector<pair<int, int>> diff(n);
    for (int i = 0; i < n; ++i) {
        diff[i] = {A[i] - B[i], i};
    }
    sort(diff.begin(), diff.end());
    //print diff
    cout << "\nDiff: ";
    for (int i = 0; i < n; ++i) {
        cout << diff[i].first << " ";
    }

    // Calculate the initial range
    int initial_range = 0;
    for (int i = 0; i < n; ++i) {
        initial_range = max(initial_range, B[i] - A[i]);
    }
    cout <<"\nInitial range: " << initial_range << endl;

    // Initialize the answer with the initial range
    int answer = initial_range;

    // Flip at most m cards
    for (int i = 0; i < m; ++i) {
        int idx = diff[i].second;
        answer = min(answer, max(initial_range, B[idx]) - min(initial_range, A[idx]));
    }

    cout << answer << endl;
    return 0;
 }*/
void print_set(set<int> s)
{
    for(int x: s)
    {
        cout<<x<<" "; 
    }
    cout<<endl;
}
/*
cpcs https://leetcode.com/discuss/interview-question/4467674/CAN-ANYONE-SOLVE-THIS/2186314
8
1
99
*/
/* int solution(const vector<int> &a, const vector<int> &b, int m) {
    const int n = a.size();
    set<int> s, fixed;
    set<pair<int, int>> smaller, largea, largeb;
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            smaller.insert({a[i], i});//1.0x 2.1x 9.4
        } else if (a[i] == b[i]) {
            fixed.insert(a[i]);//{3 4}
        } else {
            largea.insert({a[i], i});
            largeb.insert({b[i], i});
        }
        s.insert(a[i]);
        s.insert(b[i]);//1 2 3| 4 5 6 9 11 16 17
    }
    int r = INT_MAX;
    set<pair<int, int>> topa, topb;
    for (int x : s) {
        // we want all values >= x
        while (!smaller.empty() && smaller.begin()->first < x) {
            if (m-- == 0) return r;
            fixed.insert(b[smaller.begin()->second]);//3 4
            smaller.erase(smaller.begin());
        }
        if (!fixed.empty() && *fixed.begin() < x) return r;
        if (!largea.empty() && largea.begin()->first < x) return r;
        if (!topa.empty() && topa.begin()->first < x) return r;
        while (!largeb.empty() && largeb.begin()->first < x) {
            const int ind = largeb.begin()->second;
            fixed.insert(a[ind]);
            largea.erase({a[ind], ind});
            largeb.erase(largeb.begin());
        }
        while (!topb.empty() && topb.begin()->first < x) {
            const int ind = topb.begin()->second;
            fixed.insert(a[ind]);
            topa.erase({a[ind], ind}); 
            topb.erase(topb.begin());
        }
        while (topa.size() > m) {
            largea.insert(*topa.begin());
            const int ind = topa.begin()->second;
            largeb.insert({b[ind], ind});
            topa.erase(topa.begin());
            topb.erase({b[ind], ind});
        }
        while (topa.size() < m && !largea.empty()) {
            topa.insert(*largea.rbegin());//17.2 16.3
            const int ind = largea.rbegin()->second;
            topb.insert({b[ind], ind});// 5.2 6.3
            largea.erase({a[ind], ind});
            largeb.erase({b[ind], ind});
        }
        int m = INT_MIN;
        if (!smaller.empty()) {
            m = max(m, smaller.rbegin()->first);//9
        }
        if (!fixed.empty()) {
            m = max(m, *fixed.rbegin());//9
        }
        if (!largea.empty()) {
            m = max(m, largea.rbegin()->first);
        }
        if (!topb.empty()) {
            m = max(m, topb.rbegin()->first);//9
        }
        r = min(r, m - x);//9-1=8x 9-2=7 9-3=6
    }
    
    return r;
} */
/*
aalsanie
From java https://leetcode.com/discuss/interview-question/4467674/CAN-ANYONE-SOLVE-THIS/2186381
*/
//int minimizeRange(vector<int> A, vector<int> B, int n, int m) {
// int solution(vector<int> A, vector<int> B, int m) {
//     vector<pair<int, int>> differences;
//     // priority_queue<pair<int, int>> differences;
//     int minVal = std::numeric_limits<int>::max();
//     int maxVal = std::numeric_limits<int>::min();
//     int n = A.size();

//     for (int i = 0; i < n; i++) {
//         minVal = min(minVal, A[i]);
//         maxVal = max(maxVal, A[i]);
//         differences.push_back(make_pair(abs(A[i] - B[i]), i));
//     }
//     //sort in descending order
//     sort(differences.begin(), differences.end(), greater<pair<int,int>>());
//     //print differences
//     cout << "Differences: ";
//     for(auto p : differences){  
//         cout << p.first << " " << p.second << endl;
//     }

//     for (int i = 0; i < m; i++) {
//         int diff = differences[i].first;
//         int index = differences[i].second;
//         if (diff > 0) {
//             maxVal = max(maxVal, B[index]);
//             minVal = min(minVal, B[index]); 
//         }
//     }

//     return maxVal - minVal;
// }

/*
bing chat 4
https://www.reddit.com/r/leetcode/comments/18sm9nq/comment/kq4rsbk/?utm_source=share&utm_medium=web2x&context=3
*/
int solution(vector<int> A, vector<int> B, int m) {
    int n = A.size();
    // Create a sorted list of tuples (value, position, type A/B)
    vector<pair<int, pair<int, char>>> sortedCards;
    for (int i = 0; i < n; ++i) {
        sortedCards.push_back({A[i], {i, 'A'}});
        sortedCards.push_back({B[i], {i, 'B'}});
    }
    sort(sortedCards.begin(), sortedCards.end());
    //print the sorted cards
    cout << "Sorted cards: " << endl;  
    string sorted;
    std::ostringstream sorted_ss;
    for(auto card : sortedCards){
        sorted_ss << card.second.second << ": " << card.first << " " << card.second.first << "| " ;
    }
    sorted_ss << endl;
    sorted = sorted_ss.str();

    // Initialize pointers and counters
    int l = 0, r = 0, countA = 0;
    // vector<int> freqA(n, 0);
    unordered_map<int, int> freqA;

    int minRange = INT_MAX;

    // Sliding window approach
    int next_entry = 0;
    int next_entry_loff = 0;
    int next_entry_r = sorted.find(':', 0);
    //cout << next_entry_r << endl;
    int next_entry_l = sorted.find(':', 0);
    while (r < sortedCards.size()) {
        if (sortedCards[r].second.second == 'A') {
            countA++;
        }
        freqA[sortedCards[r].second.first]++;
        cout << string(sizeof(sorted), '=') << endl ;
        cout << sorted;
        cout << string(next_entry_loff, '_') <<"l: " << l<< endl ;
        cout << string(next_entry, '_') <<"r: " << r << endl;

        // Move the left pointer
        //Wait till we have seen all the indices and we have seen minimum number
        // of cards from A that cant be flipped. Remaining can be exchanged for B
        while (freqA.size() == n && countA >= n - m) {
            minRange = min(minRange, sortedCards[r].first - sortedCards[l].first);
            cout << "In window. CountA " << countA <<". Current range " << sortedCards[r].first - sortedCards[l].first << ". Minimum range " << minRange<< endl; 
            freqA[sortedCards[l].second.first]--;
            if (freqA[sortedCards[l].second.first] == 0) {
                freqA.erase(sortedCards[l].second.first); 
            }
            if (sortedCards[l].second.second == 'A') {
                countA--;
            }
            l++;
            next_entry_l = sorted.find(':', next_entry_l + 1);
            next_entry_loff = next_entry_l - 2;
        }

        r++;
        next_entry_r = sorted.find(':', next_entry_r+1);
        // cout << next_entry_r << endl;
        next_entry = next_entry_r - 2;
        cout << string(sizeof(sorted), '=') << endl ;
    }

    // cout << minRange << endl;
    return minRange;
}
int main() {
    cout << solution({1, 2, 17, 16, 9}, {3, 4, 5, 6, 11}, 2) << endl;
    cout << solution({1, 100}, {99999, 100000}, 2) << endl;
    cout << solution({1, 100}, {99999, 100000}, 1) << endl;
    return 0;
}



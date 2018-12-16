// Example program
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

#define checkEqual(a, b) { \
    if (a != b) { \
        cout << "line " << __LINE__ << " not equal!" << endl; \
        throw std::exception(); \
    } \
}

void vectorExample() {
    vector<int> v = {3, 5, 1, 2, 4};
    v.insert(v.begin() + 2, 6); // 3, 5, 6, 1, 2, 4
    v.erase(v.begin()); // 5, 6, 1, 2, 4
    v.push_back(7); // 5, 6, 1, 2, 4, 7
    checkEqual(v[1], 6);
    ostringstream oss;
    copy(v.begin(), v.end() - 1, ostream_iterator<int>(oss, ","));
    oss << v.back();
    checkEqual(oss.str(), "5,6,1,2,4,7");
    int index = find(v.begin(), v.end(), 2) - v.begin();
    checkEqual(index, 3);
    v[index] = 22;
    for (auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

void dequeExample() {
    deque<int> d = {3, 5, 1, 2, 4};
    d.insert(d.begin() + 2, 6); // 3, 5, 6, 1, 2, 4 // n
    d.erase(d.begin()); // 5, 6, 1, 2, 4 // n
    d.push_back(7); // 5, 6, 1, 2, 4, 7
    d.push_front(8); // 8, 5, 6, 1, 2, 4, 7
    checkEqual(d[2], 6); // 1
    ostringstream oss;
    copy(d.begin(), d.end() - 1, ostream_iterator<int>(oss, ","));
    oss << d.back();
    checkEqual(oss.str(), "8,5,6,1,2,4,7");
    int index = find(d.begin(), d.end(), 2) - d.begin(); // n
    checkEqual(index, 4);
    d[index] = 22;
    for (auto& e : d) {
        cout << e << " ";
    }
    cout << endl;
}

void stackExample() {
    stack<int> s;
    vector<int> v = {3, 4, 6, 5, 1, 2};
    for (auto& i : v) {
        s.push(i);
    }
    ostringstream oss;
    while (!s.empty()) {
        oss << s.top() << " ";
        s.pop();
    }
    checkEqual(oss.str(), "2 1 5 6 4 3 ");
}

void queueExample() {
    queue<int> q;
    vector<int> v = {3, 4, 6, 5, 1, 2};
    for (auto& i : v) {
        q.push(i);
    }
    ostringstream oss;
    while (!q.empty()) {
        oss << q.front() << " ";
        q.pop();
    }
    checkEqual(oss.str(), "3 4 6 5 1 2 ");
}

int kMin(priority_queue<int, vector<int>, greater<int>>& q, int k) {
    while (--k > 0 && !q.empty()) {
        q.pop();
    }
    return q.top();
}

void priorityQueueExample() {
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> v = {3, 4, 6, 5, 1, 2};
    for (auto& i : v) {
        q.push(i);
    }
    /*ostringstream oss;
    while (!q.empty()) {
        oss << q.top() << " ";
        q.pop();
    }
    checkEqual(oss.str(), "1 2 3 4 5 6 ");*/
    checkEqual(kMin(q, 2), 2);
}

void listExample() {
    list<int> l = {3, 5, 1, 2, 6, 4};
    auto it = l.begin();
    advance(it, 2);
    l.insert(it, 7); // insert before 1 // const is 1
    it = l.erase(it); // 1
    l.erase(it);
    ostringstream oss;
    copy(l.begin(), l.end(), ostream_iterator<int>(oss, ","));
    checkEqual(oss.str(), "3,5,7,6,4,");
    auto it2 = find(l.begin(), l.end(), 5);
    checkEqual(*it2, 5);
}

void setExample() {
    set<int> s = {2, 4, 5, 6, 1};
    auto it = s.find(5);
    it = s.erase(it);
    s.insert(7);
    ostringstream oss;
    copy(s.begin(), s.end(), ostream_iterator<int>(oss, ","));
    checkEqual(oss.str(), "1,2,4,6,7,");
}

void multiSetExample() {
    multiset<int> s = {1, 2, 2, 4, 5, 5, 6, 1};
    auto it = s.find(5);
    it = s.erase(it); //just remove single instance
    s.insert(7);
    s.erase(1); //remove all instances
    ostringstream oss;
    copy(s.begin(), s.end(), ostream_iterator<int>(oss, ","));
    checkEqual(oss.str(), "2,2,4,5,6,7,");
    checkEqual(s.count(2),2);
}

void mapExample() {
    map<int, string> m = {{2, "b"}, {4, "d"}, {5, "e"}, {6, "f"}, {1, "a"}};
    auto it = m.find(2);
    checkEqual(it->second, "b");
    m.erase(it);
    ostringstream oss;
    for (it = m.begin(); it != m.end(); ++it) {
        oss << it->second << ",";
    }
    checkEqual(oss.str(), "a,d,e,f,");
}

void multiMapExample() {
    multimap<int, string> m = {{2, "b"}, {3, "d"}, {2, "e"}, {2, "f"}, {1, "a"}};
    auto it = m.find(2);
    checkEqual(it->second, "b");
    m.erase(it);
    checkEqual(m.count(2), 2);
    ostringstream oss;
    for (it = m.begin(); it != m.end(); ++it) {
        oss << it->second << ",";
    }
    checkEqual(oss.str(), "a,e,f,d,");
}

void unorderedMapExample() {
    unordered_map<char, int> m = {{'h', 0}, {'e', 1}, {'l', 2}, {'l', 3}, {'o', 4}};
    auto it = m.find('l');
    checkEqual(it->second, 2); // duplicate will not insert successfully.
    m['o'] = 5;
    m.insert(make_pair('w', 4));
    ostringstream oss;
    for (it = m.begin(); it != m.end(); ++it) {
        oss << it->first << ",";
    }
    checkEqual(oss.str(), "h,e,o,w,l,"); // better not to iterate the hash map, although it is supported in STL
}

void unorderedMultimapExample() {
    unordered_multimap<char, int> m = {{'h', 0}, {'e', 1}, {'l', 2}, {'l', 3}, {'o', 4}};
    checkEqual(m.count('l'), 2);
    auto it = m.find('l');
    checkEqual(it->second, 3);
    m.insert(make_pair('w', 5));
    ostringstream oss;
    for (it = m.begin(); it != m.end(); ++it) {
        oss << it->first << ",";
    }
    cout << oss.str();
    checkEqual(oss.str(), "o,h,e,w,l,l,"); // better not to iterate the hash map, although it is supported in STL
}

int main()
{
  vectorExample();
  dequeExample();
  stackExample();
  queueExample();
  priorityQueueExample();
  listExample();
  setExample();
  multiSetExample();
  mapExample();
  multiMapExample();
  unorderedMapExample();
  unorderedMultimapExample();
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Page {
    int id;
    int loading_time;
    int last_access_time;
    int r_bit;
    int m_bit;
};

int nru_replace(vector<Page>& pages) {
    int oldest_time = pages[0].last_access_time;
    int oldest_index = 0;
    for (int i = 1; i < pages.size(); i++) {
        if (pages[i].last_access_time < oldest_time && pages[i].r_bit == 0 && pages[i].m_bit == 0) {
            oldest_time = pages[i].last_access_time;
            oldest_index = i;
        }
    }
    return oldest_index;
}

int fifo_replace(vector<Page>& pages) {
    int oldest_time = pages[0].loading_time;
    int oldest_index = 0;
    for (int i = 1; i < pages.size(); i++) {
        if (pages[i].loading_time < oldest_time) {
            oldest_time = pages[i].loading_time;
            oldest_index = i;
        }
    }
    return oldest_index;
}

int lru_replace(vector<Page>& pages) {
    int oldest_time = pages[0].last_access_time;
    int oldest_index = 0;
    for (int i = 1; i < pages.size(); i++) {
        if (pages[i].last_access_time < oldest_time) {
            oldest_time = pages[i].last_access_time;
            oldest_index = i;
        }
    }
    return oldest_index;
}

int second_chance_replace(vector<Page>& pages, int& clock_hand) {
    while (true) {
        Page& page = pages[clock_hand];
        if (page.r_bit == 0) {
            clock_hand = (clock_hand + 1) % pages.size();
            return page.id;
        }
        page.r_bit = 0;
        clock_hand = (clock_hand + 1) % pages.size();
    }
}

int main() {
    vector<Page> pages = {{0, 126, 280, 1, 0},
                          {1, 230, 265, 0, 1},
                          {2, 140, 270, 0, 0},
                          {3, 110, 285, 1, 1}};
    int clock_hand = 0;
    cout << "NRU replaces page " << nru_replace(pages) << endl;// r,m = 0 and least loaded
    cout << "FIFO replaces page " << fifo_replace(pages) << endl;// least loaded
    cout << "LRU replaces page " << lru_replace(pages) << endl;// least refernce
    cout << "Second chance replaces page " << second_chance_replace(pages, clock_hand) << endl;// least reference and r = 0
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

vector<int> re[maxn];

struct node {
    int nid;
    vector<pair<int, int> > tsk;

    bool operator<(const node& a) const {
        if (tsk.size() != a.tsk.size()) {
            return tsk.size() < a.tsk.size();
        }

        return nid < a.nid;
    }
} nodes[maxn];

int n, m, g;
int fi, ai, nai, pai, paai, paari;
int cnt = 1;

void solve1() {
    set<node> ans;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < re[i].size(); ++j) {
            ans.insert(nodes[re[i][j]]);
        }
    }

    for (int i = 1; i <= fi; ++i) {
        set<node>::iterator it = ans.begin();
        node tmp = *it;
        ans.erase(it);

        cout << tmp.nid << " ";

        nodes[tmp.nid].tsk.push_back({cnt, ai});
        ++cnt;
        ans.insert(nodes[tmp.nid]);
    }
}

void solve2() {
    set<node> ans;
    for (int i = 0; i < re[nai].size(); ++i) {
        ans.insert(nodes[re[nai][i]]);
    }

    if (ans.empty()) {
        for (int i = 1; i <= fi; ++i) {
            cout << 0 << " ";
        }

        return;
    }

    for (int i = 1; i <= fi; ++i) {
        set<node>::iterator it = ans.begin();
        node tmp = *it;
        ans.erase(it);

        cout << tmp.nid << " ";

        nodes[tmp.nid].tsk.push_back({cnt, ai});
        ++cnt;
        ans.insert(nodes[tmp.nid]);
    }
}

void solve3() {
    set<node> ans;
    if (nai) {
        for (int i = 0; i < re[nai].size(); ++i) {
            ans.insert(nodes[re[nai][i]]);
        }
    } else {
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < re[i].size(); ++j) {
                ans.insert(nodes[re[i][j]]);
            }
        }
    }

    if (ans.empty()) {
        for (int i = 1; i <= fi; ++i) {
            cout << 0 << " ";
        }

        return;
    }

    set<node>::iterator it = ans.begin();
    vector<node> toDel;
    for (it; it != ans.end(); ++it) {
        for (int j = 0; j < (*it).tsk.size(); ++j) {
            if ((*it).tsk[j].second == paai) {
                toDel.push_back(*it);
                break;
            }
        }
    }

    if (ans.size() == toDel.size()) {
        if (paari) {
            for (int i = 1; i <= fi; ++i) {
                cout << 0 << " ";
            }
            return;
        }
    } else {
        for (int j = 0; j < toDel.size(); ++j) {
            ans.erase(toDel[j]);
        }
    }

    bool flag = false;
    for (int i = 1; i <= fi; ++i) {
        if (ans.empty()) {
            if (paari) {
                cout << 0 << " ";
                continue;
            } else {
                flag = true;
                if (nai) {
                    for (int j = 0; j < re[nai].size(); ++j) {
                        ans.insert(nodes[re[nai][j]]);
                    }
                } else {
                    for (int k = 1; k <= m; ++k) {
                        for (int j = 0; j < re[k].size(); ++j) {
                            ans.insert(nodes[re[k][j]]);
                        }
                    }
                }
            }
        }

        it = ans.begin();
        node tmp = *it;
        ans.erase(it);

        cout << tmp.nid << " ";

        nodes[tmp.nid].tsk.push_back({cnt, ai});
        ++cnt;

        if (ai != paai || flag) {
            ans.insert(nodes[tmp.nid]);
        }
    }
}

void solve4() {
    set<node> ans;

    vector<int> can;
    if (nai) {
        bool flag = false;
        for (int i = 0; i < re[nai].size(); ++i) {
            for (int j = 0; j < nodes[re[nai][i]].tsk.size(); ++j) {
                if (nodes[re[nai][i]].tsk[j].second == pai) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                can.push_back(nai);
                break;
            }
        }
    } else {
        for (int i = 1; i <= m; ++i) {
            bool flag = false;

            for (int j = 0; j < re[i].size(); ++j) {
                for (int k = 0; k < nodes[re[i][j]].tsk.size(); ++k) {
                    if (nodes[re[i][j]].tsk[k].second == pai) {
                        flag = true;
                        break;
                    }
                }

                if (flag) {
                    can.push_back(i);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < can.size(); ++i) {
        for (int j = 0; j < re[can[i]].size(); ++j) {
            ans.insert(nodes[re[can[i]][j]]);
        }
    }

    if (ans.empty()) {
        for (int i = 1; i <= fi; ++i) {
            cout << 0 << " ";
        }
        return;
    }

    for (int i = 1; i <= fi; ++i) {
        set<node>::iterator it = ans.begin();
        node tmp = *it;
        ans.erase(it);

        cout << tmp.nid << " ";

        nodes[tmp.nid].tsk.push_back({cnt, ai});
        ++cnt;
        ans.insert(nodes[tmp.nid]);
    }
}

void solve5() {
    set<node> ans;

    vector<int> can;
    if (nai) {
        bool flag = false;
        for (int i = 0; i < re[nai].size(); ++i) {
            for (int j = 0; j < nodes[re[nai][i]].tsk.size(); ++j) {
                if (nodes[re[nai][i]].tsk[j].second == pai) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                can.push_back(nai);
                break;
            }
        }
    } else {
        for (int i = 1; i <= m; ++i) {
            bool flag = false;

            for (int j = 0; j < re[i].size(); ++j) {
                for (int k = 0; k < nodes[re[i][j]].tsk.size(); ++k) {
                    if (nodes[re[i][j]].tsk[k].second == pai) {
                        flag = true;
                        break;
                    }
                }

                if (flag) {
                    can.push_back(i);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < can.size(); ++i) {
        for (int j = 0; j < re[can[i]].size(); ++j) {
            ans.insert(nodes[re[can[i]][j]]);
        }
    }

    if (ans.empty()) {
        for (int i = 1; i <= fi; ++i) {
            cout << 0 << " ";
        }
        return;
    }

    set<node>::iterator it = ans.begin();
    if (paai) {
        vector<node> toDel;
        for (it; it != ans.end(); ++it) {
            for (int j = 0; j < (*it).tsk.size(); ++j) {
                if ((*it).tsk[j].second == paai) {
                    toDel.push_back(*it);
                    break;
                }
            }
        }

        if (ans.size() == toDel.size()) {
            if (paari) {
                for (int i = 1; i <= fi; ++i) {
                    cout << 0 << " ";
                }
                return;
            }
        } else {
            for (int j = 0; j < toDel.size(); ++j) {
                ans.erase(toDel[j]);
            }
        }
    }

    bool flag = false;
    for (int i = 1; i <= fi; ++i) {
        if (paai and ans.empty()) {
            if (paari) {
                cout << 0 << " ";
                continue;
            } else {
                flag = true;
                if (nai) {
                    for (int j = 0; j < re[nai].size(); ++j) {
                        ans.insert(nodes[re[nai][j]]);
                    }
                } else {
                    for (int k = 0; k < can.size(); ++k) {
                        for (int j = 0; j < re[can[k]].size(); ++j) {
                            ans.insert(nodes[re[can[k]][j]]);
                        }
                    }
                }
            }
        }

        it = ans.begin();
        node tmp = *it;
        ans.erase(it);

        cout << tmp.nid << " ";

        nodes[tmp.nid].tsk.push_back({cnt, ai});
        ++cnt;

        if (ai != paai || flag) {
            ans.insert(nodes[tmp.nid]);
        }
    }
}

int main() {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    cin >> n >> m;

    for (int i = 1, li; i <= n; ++i) {
        cin >> li;
        re[li].push_back(i);

        nodes[i].nid = i;
    }

    cin >> g;
    for (int i = 1; i <= g; ++i) {
        cin >> fi >> ai >> nai >> pai >> paai >> paari;

        if (!nai and !pai and !paai) {
            solve1();
            cout << '\n';
        } else if (!pai and !paai) {
            solve2();
            cout << '\n';
        } else if (!pai) {
            solve3();
            cout << '\n';
        } else {
            solve5();
            cout << '\n';
        }
    }
    return 0;
}

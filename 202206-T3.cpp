#include <bits/stdc++.h>
using namespace std;

struct role {
    string roleName;
    map<string, int> ops;
    map<string, int> cats;
    map<string, int> src;
} roles[510];
map<string, int> idx;

// 用户关联了哪些角色
map<string, vector<string> > usrRole;

bool check(string userName, string op, string cat, string src) {
    int id = idx[userName];

    // role r = roles[id];  加上这个就超时！
    if (!roles[id].ops.count("*") and !roles[id].ops.count(op)) {
        return false;
    }

    if (!roles[id].cats.count("*") and !roles[id].cats.count(cat)) {
        return false;
    }

    if (!roles[id].src.empty() and !roles[id].src.count(src)) {
        return false;
    }

    return true;
}

int n, m, q;

int main() {
    ios::sync_with_stdio(false);
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> roles[i].roleName;
        idx[roles[i].roleName] = i;

        int nv;
        cin >> nv;
        for (int j = 1; j <= nv; ++j) {
            string op;
            cin >> op;

            roles[i].ops[op] = 1;
        }

        int no;
        cin >> no;
        for (int j = 1; j <= no; ++j) {
            string cat;
            cin >> cat;

            roles[i].cats[cat] = 1;
        }

        int nn;
        cin >> nn;
        for (int j = 1; j <= nn; ++j) {
            string src;
            cin >> src;

            roles[i].src[src] = 1;
        }
    }

    for (int i = 1; i <= m; ++i) {
        string roleName;
        cin >> roleName;

        int ns;
        cin >> ns;
        for (int j = 1; j <= ns; ++j) {
            string type, user;
            cin >> type >> user;

            usrRole[user].push_back(roleName);
        }
    }

    for (int i = 1; i <= q; ++i) {
        string userName, op, cat, src;
        cin >> userName;

        int ng;
        cin >> ng;
        vector<string> grp;
        for (int j = 1; j <= ng; ++j) {
            string g;
            cin >> g;

            grp.push_back(g);
        }

        cin >> op >> cat >> src;

        bool flag = false;
        for (int j = 0; j < usrRole[userName].size(); ++j) {
            if (check(usrRole[userName][j], op, cat, src)) {
                flag = true;
                break;
            }
        }

        if (flag) {
            cout << 1 << '\n';
            continue;
        }

        for (int j = 0; j < ng; ++j) {
            string roleName = grp[j];
            for (int k = 0; k < usrRole[roleName].size(); ++k) {
                if (check(usrRole[roleName][k], op, cat, src)) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                break;
            }
        }

        if (flag) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}

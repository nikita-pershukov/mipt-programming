#include "!_All_include.h"
#include "ahocorasick.h"
#include "flow.h"
#include "graph.h"
#include "kmp.h"
#include "treap.h"

enum Algoritm {
    TARJAN = 0,
    DIJKSTRA = 2,
    BELLMAN_FORD = 3,
    FLOYD_WARSHALL = 4,
    KRUSCAL = 7,
    MAX_FLOW = 9,
    DIJKSTRA_BIN_HEAP = 11,
    TREAP = 12,
    KMP_ALG = 13,
    AHO_CORASICK = 14
};

void start()
{
    srand (time(NULL));
    int count = 1;
    for (int i = 0; i < count; ++i) {
        int id;
        std::cin >> id;
        switch (id) {
        case TARJAN: {
            int n;
            std::cin >> n;
            graph<int, int, 1> g(n);
            std::cin >> g;
            g.Tarjan();
            break;
        }
        case DIJKSTRA: {
            int n;
            std::cin >> n;
            graph<int, int, 1> g(n);
            std::cin >> g;
            int src;
            std::cin >> src;
            g.Dijkstra(src);
            break;
        }
        case BELLMAN_FORD: {
            int n;
            std::cin >> n;
            graph<int, int, 1> g(n);
            std::cin >> g;
            int src;
            std::cin >> src;
            g.BellmanFord(src);
            break;
        }
        case FLOYD_WARSHALL: {
            int n;
            std::cin >> n;
            graph<int, int, 1> g(n);
            std::cin >> g;
            g.FloydWarshall();
            break;
        }
        case KRUSCAL: {
            int n;
            std::cin >> n;
            graph<int, int, 0> g(n);
            std::cin >> g;
            g.Kruskal();
            break;
        }
        case MAX_FLOW: {
            int n;
            std::cin >> n;
            minCostFlow f(n);
            int t, s;
            std::cin >> t;
            std::cin >> s;
            std::cin >> f;
            std::pair<double, double> ans = f.Flow(t, s, kInf);
            std::cout << ans.first << ' ' << ans.second;
            break;
        }
        case DIJKSTRA_BIN_HEAP: {
            int n;
            std::cin >> n;
            graph<int, int, 1> g(n);
            std::cin >> g;
            int src;
            std::cin >> src;
            g.DijkstraBinomialHeap(src);
            break;
        }
        case TREAP: {
            int n;
            std::cin >> n;
            int k;
            std::cin >> k;
            treap<int, int>* t = new treap<int,int>;
            for(int i = 1; i <= n; ++i) {
                t->Insert(i);
            }
            int index = (k - 1) % t->GetSize();
            while (t->GetSize() != 1) {
                std::cout << t->FindIndex(index) << " ";
                t->Erase(t->FindIndex(index));
                index = (index + k - 1) % t->GetSize();
            }
            std::cout << t->GetValue();
            break;
        }
        case KMP_ALG: {
            std::string s;
            std::cin >> s;
            std::string text;
            std::cin >> text;
            std::vector<int> res = KMP(s, text);
            for(int i = 0; i < (int) res.size(); ++i)
                std::cout << res[i] << " ";
        }
        case AHO_CORASICK: {
            ahoCorasick g;
            std::string s;
            int count;
            std::cin >> count;
            for (int i = 0; i < count; ++i) {
                std::cin >> s;
                g.AddString(s);
            }
            std::string content;
            while (std::getline(std::cin, s)) {
                content += s;
                content.push_back('\n');
            }
            auto res = g.CountEntry(content);
            for (auto it : res) {
                std::cout << it.first << ' ';
                for (auto it2 : it.second)
                    std::cout << it2 << ' ';
                std::cout << std::endl;
            }
            break;
        }
        }
    }
}

int main()
{
    start();
    return 0;
}


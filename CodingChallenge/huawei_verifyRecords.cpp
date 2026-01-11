#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
* 细胞增殖
生物学家小明正在研究一种特殊的细胞，这种细胞的增殖模式十分奇特。
他通过显微镜长期观察，记录下了 N 个不同时间点的细胞种群数量。

小明提出了一个理论模型：他认为这些细胞的增殖可能遵循一种规律，即种群数量会等于某个“增殖基数” B 的 t 次方与一个“稳定基数” S 的和，其中 
t 代表增殖周期（一个正整数）。完整的公式为：C = Bt + S。

现在，小明整理出了 M 组假说，每组假说包含一个增殖基数 Bj 和一个稳定基数 Sj。
他希望您能帮他验证，对于每一组假说 (Bj,Sj)，在他的 N 条观测记录中：
1. 总共有多少条记录符合 Ci = Bjt +Sj 的模式（t 可以取任意正整数）？
2. 在所有符合该模式的记录中，单个增殖周期（即固定的 t 值）所能对应的最高重复观测次数是多少？我们称之为“增殖峰值”。
时间限制：C/C++ 5秒，其他语言10秒
空间限制：C/C++ 512M，其他语言1024M
输入描述：
输入第一行包含两个正整数 N 和 M，分别代表观测记录的数量和假说的数量。
(1 \le N \le 100000, 1 \le M \le 200000)

第二行包含 N 个整数，表示 N 条细胞种群数量的观测记录 C_i。数据保证按从小到大的顺序排列。
(1 \le C_i \le 10^9)

接下来 M 行，每行包含两个整数 B_j 和 S_j，代表一组假说的增殖基数和稳定基数。
(0 \le B_j, S_j \le 10^7)
输出描述：
输出共 M 行，每行对应一组假说的验证结果。

每行输出两个整数，以空格隔开，分别代表：
1.  符合该假说模式的总观测记录数。
2.  该假说模式下的增殖峰值。
*/
int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<unsigned int> record(N);
        unordered_map<unsigned int, unsigned int> cnt;
        cnt.reserve((size_t)N * 2);
        unsigned int maxRecord = 0;

        for (int i = 0; i < N; ++i) {
            cin >> record[i];
            if (record[i] > maxRecord)
                maxRecord = record[i];
            ++cnt[record[i]];
        }

        for (int i = 0; i < M; ++i) {
            unsigned int B, S;
            cin >> B >> S;

            unsigned long long validRecords = 0;
            unsigned int maxCount = 0;

            if (B <= 1) {
                auto it = cnt.find(S + B);
                unsigned int c = (it == cnt.end()) ? 0 : it->second;
                validRecords = c;
                maxCount = c;
            }
            else {
                // enumerate S + B^k
                unsigned long long pow = B; // B^1
                while (true) {
                    unsigned long long x = (unsigned long long)S + pow;
                    if (x > maxRecord) break;

                    auto it = cnt.find((unsigned int)x);
                    if (it != cnt.end()) {
                        validRecords += it->second;
                        if (it->second > maxCount) maxCount = it->second;
                    }

                    // pow *= B with overflow check
                    if (pow > (unsigned long long)maxRecord / B) break;
                    pow *= B;
                }
            }

            std::cout << validRecords << " " << maxCount << "\n";
        }
    }
}

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cstdlib>
#include <ctime>

class SubArray {
    public:
        int ops_cnt, s, e, sum;
        SubArray(int s, int e, int sum, int ops_cnt) {
            this->s = s;
            this->e = e;
            this->sum = sum;
            this->ops_cnt = ops_cnt;
        }
        friend bool operator < (const SubArray& a, const SubArray& b) {
            return a.sum < b.sum;
        }
        friend std::ostream& operator << (std::ostream& os, const SubArray& sa) {
            return os << sa.s << ", " << sa.e << ", " << sa.sum;
        }
};

class MSA {
private:
    int *arr, n;

    SubArray mid_crossing_sa(int s, int mid, int e) {
        int l = mid,
            r = mid + 1,
            lsum = arr[l],
            rsum = arr[r],
            ops_cnt = 2,
            sum = lsum;

        for (int i = mid - 1; i >= s; i--) {
            ops_cnt++;
            sum += arr[i];
            if (sum > lsum) {
                lsum = sum;
                l = i;
            }
        }

        sum = rsum;
        for (int i = mid + 2; i <= e; i++) {
            ops_cnt++;
            sum += arr[i];
            if (sum > rsum) {
                rsum = sum;
                r = i;
            }
        }

//        std::cout << lsum << " " << rsum << " " << lsum + rsum << std::endl;
        return SubArray(l, r, lsum + rsum, ops_cnt);
    }

    SubArray msa_dc(int s, int e) {
        if (s == e)
            return SubArray(s, s, arr[s], 1);

        int mid = (s + e) / 2;
        SubArray sa1 = msa_dc(s, mid);
        SubArray sa2 = msa_dc(mid + 1, e);
        SubArray mcsa = mid_crossing_sa(s, mid, e);

        int ops_cnt = sa1.ops_cnt + sa2.ops_cnt + mcsa.ops_cnt;

//        std::cout << "3 sa: " << "(" << sa1 << "), (" << sa2 << "), (" << mcsa << ")" << std::endl;
        sa1 = std::max(std::max(sa1, sa2), mcsa);
        sa1.ops_cnt = ops_cnt;

        return sa1;
    }
public:
    MSA() {
        n = 0;
        while (n < 1) {
            std::cout << "Enter the number of values in the array: ";
            std::cin >> n;
        }

        arr = new int[n];
        /*std::cout << "Enter the array elements: ";
        for (int i = 0; i < n; i++)
            std::cin >> arr[i];*/

        std::cout << "Randomly generating array: ";
        std::srand(std::time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = std::rand();
            if (arr[i] > 3 * (RAND_MAX / 5))
                arr[i] *= -1;
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    ~MSA() {
        delete arr;
    }

    void print_results(const SubArray& sa) {
        std::cout << "Maximum sub array (" << sa << "): ";
        for (int i = sa.s; i <= sa.e; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
        
        std::cout << "Sum is " << sa.sum << "\n" << std::endl;
    }

    int solve_forced() {
        std::cout << "Brute force method" << std::endl;
        int s, e, max_sum, ops_cnt = 0;
        s = e = -1;
        max_sum = std::numeric_limits<int>::min();

        for (int i = 0; i < n; i++) {
            ops_cnt++;
            for (int j = i; j < n; j++) {
                int sum = 0;
                ops_cnt++;
                for (int k = i; k <= j; k++) {
                    ops_cnt++;
                    sum += arr[k];
                }
                if (sum > max_sum) {
                    s = i;
                    e = j;
                    max_sum = sum;
                }
            }
        }
        
        print_results(SubArray(s, e, max_sum, ops_cnt));

        return ops_cnt;
    }
    
    int solve_heuristic() {
        std::cout << "Heuristic method" << std::endl;
        int s, e, max_sum, ops_cnt = 0;
        s = e = -1;
        max_sum = std::numeric_limits<int>::min();

        // heuristic: use sum from previous calc for next calc
        for (int i = 0; i < n; i++) {
            int sum = 0;
            ops_cnt++;
            for (int j = i; j < n; j++) {
                ops_cnt++;
                sum += arr[j];
                if (sum > max_sum) {
                    s = i;
                    e = j;
                    max_sum = sum;
                }
            }   
        }
        
        print_results(SubArray(s, e, max_sum, ops_cnt));

        return ops_cnt;
    }

    int solve_dc() {
        std::cout << "Divide and conquer approach" << std::endl;

        SubArray msa = msa_dc(0, n-1);

        print_results(msa);

        return msa.ops_cnt;
    }
};

int main() {
    using namespace std;
    MSA msa;
    int forced = msa.solve_forced();
    int heu = msa.solve_heuristic();
    int dc = msa.solve_dc();

    cout << "Number of active operations" << endl;
    cout << "Brute force (O(n³)) | " << forced << endl;
    cout << "Heuristic (O(n²)) | " << heu << endl;
    cout << "Divide & Conquer (O(nlogn)) | " << dc << endl;
    return 0;
}
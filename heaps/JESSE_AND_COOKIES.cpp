// Jesse and Cookies
// https://www.hackerrank.com/challenges/jesse-and-cookies/problem
// status: solved

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void swap(int &l, int &r){
    int temp = l;
    l= r;
    r = temp;
}

void min_heapify(vector<int> &A, int i){
    int smallest;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < A.size() && A[i] > A[left])
        smallest = left;
    else 
        smallest = i;
    
    if(right < A.size() && A[smallest] > A[right])
        smallest = right;

    if(smallest != i){
        swap(A[smallest], A[i]);
        min_heapify(A, smallest);
    }
}

void build_heap(vector<int> &A){
    for(int i = (A.size()-2)/2 ; i >= 0 ; i--){
        min_heapify(A, i);
    }
}

int get_min(vector<int> &A){
    return A.front();
}

int delete_min(vector<int> &A){
    int min = A.front();
    A[0] = A.back();
    A.pop_back();
    min_heapify(A, 0);
    return min;
}

void insert(vector<int> &A, int x){
    A.push_back(x);
    int i = A.size()-1;
    int parent = (i-1)/2;
    while(i > 0){
        if(A[i] < A[parent]){
            swap(A[i], A[parent]);
            i = parent;
            parent = (i-1)/2;
        }
        else break;
    }
}
/*
 * Complete the cookies function below.
 */
int cookies(int k, vector<int> A) {
    build_heap(A);
    int ops = 0;
    int sweetness = get_min(A);
    while(A.size() > 1 && k > sweetness){
        int least = delete_min(A);
        int s_least = delete_min(A);
        insert(A, 1*least + 2*s_least);
        sweetness = get_min(A);
        ops++;
    }
    if(sweetness >= k)
        return ops;
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<int> A(n);

    for (int A_itr = 0; A_itr < n; A_itr++) {
        int A_item = stoi(A_temp[A_itr]);

        A[A_itr] = A_item;
    }

    int result = cookies(k, A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

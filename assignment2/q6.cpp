//A
#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

class Sparse {
    int rows, cols, terms;
    Term *data;
public:
    Sparse(int r, int c, int t) {
        rows = r; cols = c; terms = t;
        data = new Term[t];
    }
    void read() {
        for (int i = 0; i < terms; i++)
            cin >> data[i].row >> data[i].col >> data[i].val;
    }
    void transpose() {
        Term *tdata = new Term[terms];
        int k = 0;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < terms; j++) {
                if (data[j].col == i) {
                    tdata[k].row = data[j].col;
                    tdata[k].col = data[j].row;
                    tdata[k].val = data[j].val;
                    k++;
                }
            }
        }
        cout << "Transpose:" << endl;
        for (int i = 0; i < terms; i++)
            cout << tdata[i].row << " " << tdata[i].col << " " << tdata[i].val << endl;
    }
};

int main() {
    int r, c, t;
    cin >> r >> c >> t;
    Sparse s(r, c, t);
    s.read();
    s.transpose();

  

  //B
  #include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

class Sparse {
    int rows, cols, terms;
    Term *data;
public:
    Sparse(int r, int c, int t) {
        rows = r; cols = c; terms = t;
        data = new Term[t];
    }
    void read() {
        for (int i = 0; i < terms; i++)
            cin >> data[i].row >> data[i].col >> data[i].val;
    }
    void add(Sparse &s) {
        if (rows != s.rows || cols != s.cols) return;
        int i = 0, j = 0, k = 0;
        Term *sum = new Term[terms + s.terms];
        while (i < terms && j < s.terms) {
            if (data[i].row < s.data[j].row || 
               (data[i].row == s.data[j].row && data[i].col < s.data[j].col)) 
                sum[k++] = data[i++];
            else if (s.data[j].row < data[i].row || 
               (s.data[j].row == data[i].row && s.data[j].col < data[i].col)) 
                sum[k++] = s.data[j++];
            else {
                sum[k] = data[i];
                sum[k++].val = data[i++].val + s.data[j++].val;
            }
        }
        while (i < terms) sum[k++] = data[i++];
        while (j < s.terms) sum[k++] = s.data[j++];
        cout << "Addition:" << endl;
        for (int x = 0; x < k; x++)
            cout << sum[x].row << " " << sum[x].col << " " << sum[x].val << endl;
    }
};

int main() {
    int r, c, t1, t2;
    cin >> r >> c >> t1;
    Sparse s1(r, c, t1);
    s1.read();
    cin >> r >> c >> t2;
    Sparse s2(r, c, t2);
    s2.read();
    s1.add(s2);
}

  

  //C
  #include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

struct Sparse {
    int rows, cols, num;   
    Element *e;
};

// Function to create sparse matrix
Sparse createSparse() {
    Sparse s;
    cout << "Enter number of rows, cols and non-zero elements: ";
    cin >> s.rows >> s.cols >> s.num;
    s.e = new Element[s.num];

    cout << "Enter row, column and value of non-zero elements:\n";
    for (int i = 0; i < s.num; i++) {
        cin >> s.e[i].row >> s.e[i].col >> s.e[i].val;
    }
    return s;
}

// Display sparse matrix in triplet form
void display(const Sparse &s) {
    cout << "\nRow\tCol\tVal\n";
    for (int i = 0; i < s.num; i++) {
        cout << s.e[i].row << "\t" << s.e[i].col << "\t" << s.e[i].val << "\n";
    }
}

// Multiplication of two Sparse matrices
Sparse multiply(const Sparse &s1, const Sparse &s2) {
    if (s1.cols != s2.rows) {
        cout << "Multiplication not possible\n";
        return {0,0,0,nullptr};
    }

    Sparse result;
    result.rows = s1.rows;
    result.cols = s2.cols;
    result.e = new Element[s1.num * s2.num]; // worst case
    int k = 0;

    for (int i = 0; i < s1.rows; i++) {
        for (int j = 0; j < s2.cols; j++) {
            int sum = 0;
            for (int a = 0; a < s1.num; a++) {
                if (s1.e[a].row == i) {
                    for (int b = 0; b < s2.num; b++) {
                        if (s2.e[b].col == j && s1.e[a].col == s2.e[b].row) {
                            sum += s1.e[a].val * s2.e[b].val;
                        }
                    }
                }
            }
            if (sum != 0) {
                result.e[k++] = {i, j, sum};
            }
        }
    }
    result.num = k;
    return result;
}

int main() {
    cout << "Create first sparse matrix:\n";
    Sparse s1 = createSparse();

    cout << "Create second sparse matrix:\n";
    Sparse s2 = createSparse();

    cout << "\nFirst matrix (Triplet form):";
    display(s1);

    cout << "\nSecond matrix (Triplet form):";
    display(s2);

    cout << "\nMultiplication Result (Triplet form):";
    Sparse mul = multiply(s1, s2);
    if (mul.e != nullptr) display(mul);

    return 0;
}
}

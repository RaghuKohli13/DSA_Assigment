//Q5(A)

#include <iostream>
using namespace std;

class Diagonal {
    int *arr, n;
public:
    Diagonal(int n) {
        this->n = n;
        arr = new int[n];
    }
    void set(int i, int j, int x) {
        if (i == j) arr[i - 1] = x;
    }
    int get(int i, int j) {
        if (i == j) return arr[i - 1];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Diagonal d(4);
    d.set(1,1,5); d.set(2,2,8); d.set(3,3,9); d.set(4,4,12);
    d.display();

//Q5(B)
  #include <iostream>
  using namespace std;

class TriDiagonal {
    int *arr, n;
public:
    TriDiagonal(int n) {
        this->n = n;
        arr = new int[3*n - 2];
    }
    void set(int i, int j, int x) {
        if (i - j == 0) arr[n - 1 + i - 1] = x;
        else if (i - j == 1) arr[i - 2] = x;
        else if (j - i == 1) arr[2*n - 1 + i - 1] = x;
    }
    int get(int i, int j) {
        if (i - j == 0) return arr[n - 1 + i - 1];
        else if (i - j == 1) return arr[i - 2];
        else if (j - i == 1) return arr[2*n - 1 + i - 1];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    TriDiagonal t(4);
    t.set(1,1,5); t.set(1,2,8); t.set(2,1,3); t.set(2,2,9);
    t.set(2,3,6); t.set(3,2,7); t.set(3,3,4); t.set(3,4,2);
    t.set(4,3,1); t.set(4,4,10);
    t.display();
}

  //Q5(C)
  #include <iostream>
  using namespace std;

class LowerTri {
    int *arr, n;
public:
    LowerTri(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) arr[i*(i-1)/2 + j - 1] = x;
    }
    int get(int i, int j) {
        if (i >= j) return arr[i*(i-1)/2 + j - 1];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    LowerTri l(4);
    l.set(1,1,5); l.set(2,1,8); l.set(2,2,9);
    l.set(3,1,6); l.set(3,2,7); l.set(3,3,4);
    l.set(4,1,2); l.set(4,2,1); l.set(4,3,3); l.set(4,4,10);
    l.display();
}
}

//Q5(D)

#include <iostream>
using namespace std;

class UpperTri {
    int *arr, n;
public:
    UpperTri(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i <= j) arr[j*(j-1)/2 + i - 1] = x;
    }
    int get(int i, int j) {
        if (i <= j) return arr[j*(j-1)/2 + i - 1];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    UpperTri u(4);
    u.set(1,1,5); u.set(1,2,8); u.set(1,3,6); u.set(1,4,2);
    u.set(2,2,9); u.set(2,3,7); u.set(2,4,1);
    u.set(3,3,4); u.set(3,4,3);
    u.set(4,4,10);
    u.display();
}


//Q5(E)

#include <iostream>
using namespace std;

class Symmetric {
    int *arr, n;
public:
    Symmetric(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) arr[i*(i-1)/2 + j - 1] = x;
        else arr[j*(j-1)/2 + i - 1] = x;
    }
    int get(int i, int j) {
        if (i >= j) return arr[i*(i-1)/2 + j - 1];
        return arr[j*(j-1)/2 + i - 1];
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Symmetric s(4);
    s.set(1,1,5); s.set(2,1,8); s.set(2,2,9); s.set(3,1,6);
    s.set(3,2,7); s.set(3,3,4); s.set(4,1,2); s.set(4,2,1);
    s.set(4,3,3); s.set(4,4,10);
    s.display();
}

#include <bits/stdc++.h>

using namespace std;

/*
    Very Terrible Implementation (my rating -> cakewalk)

    Question ->
    Preface:
    Matrix multiplication forms the core step of popular algorithms
    (like Matrix Exponentiation) used to solve recurrences, etc.
    This assumes a far greater importance when most of the users are
    from the domain of maths. Hence, developers often tend to define
    operators which would work on Matrices in order to increase expressibilty
    and hence popularity of the concept among its targeted audience.

    Statement:

    In a far away Galaxy of Tilky Way, there was a planet Tarth where the
    sport of Tompetitive Toding was very popular. According to legends,
    there lived a setter known for his love for tedious, messy and terrible
    implementation questions.

    Tyam Kandu is at it again. Since morning he had just set a floor on
    fire, trolled a few thousands of users and gave irreparable sarcastic
    burns to half the staff of Tirecti. Hence, to curb this menace and chaos,
    the HR decided to bind Kandu with the most terrible, most disgusting, most
    messy implementation questions of all.

    "Implement Matrix Multiplication Operators." the words of doom echoed
    through the office.

    He has to implement the following 2 operators -

    "+ ⟹ A+B is defined as Ans=(A*B)+A where A*B is matrix multiplication
    of matrices A and B, and + operator adds the two matrices."

    "- ⟹ A-B is defined as Ans=(A*B)-A where * is defined same as above, and - is matrix subtraction.
    Since he is your buddy, you must help him implement it and be free again."

    "Recall that the result of matrix multiplication of two N×N matrices A and B is
    "another N×N matrix C such that Ci,j (the element in i′th row and j′th column) is defined
    "as Ci,j=∑k=Nk=1Ai,k∗Bk,j.

    Both, A and B, are square matrices and are hence compatible with both the operators. In other words,
    it is always possible to operate with * and + operators on the matrices in input.

*/


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        vector<vector<int>> b(n, vector<int>(n));
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> b[i][j];
        string op;
        cin >> op;
        int con = op == "*+" ? 1 : -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int current = 0;
                for (int k = 0; k < n; k++)
                    current += a[i][k] * b[k][j];
                cout << current + (con * a[i][j]) << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

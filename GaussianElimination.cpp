#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double EPS = 1e-10; // ���e�덷

	double mat[3][4];
	for (int i = 0; i < 3; i++) {
		std::cin >> mat[i][0] >> mat[i][1] >> mat[i][2] >> mat[i][3];
	}


    // �O�i����
    for (int k = 0; k < 3; k++) {
        int pivot = k;
        for (int i = k + 1; i < 3; i++) {
            if (abs(mat[i][k]) > abs(mat[pivot][k])) pivot = i;
        }
        std:swap(mat[pivot], mat[k]);

        if (abs(mat[k][k]) < EPS) {
            // ���Ȃ��܂��͈�ӂłȂ�
            printf("���Ȃ��܂��͈�ӂłȂ�\n");
            return 0;
        }

        for (int i = k + 1; i < 3; i++) {
            double f = mat[i][k] / mat[k][k];
            for (int j = k + 1; j < 4; j++) {
                mat[i][j] -= f * mat[k][j];
            }
            mat[i][k] = 0;
        }
    }

    // ��ޑ��
    double x[3];
    for (int i = 2; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < 3; j++) {
            sum += mat[i][j] * x[j];
        }
        x[i] = (mat[i][3] - sum) / mat[i][i];
    }

    // ���̏o��
    printf("%lf\n", x[0]);
    printf("%lf\n", x[1]);
    printf("%lf\n", x[2]);
}

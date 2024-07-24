#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Khai báo các hàm xử lý
void taoMaTran(vector<vector<int>> &matrix, int m, int n, int a, int b);
void xuatMaTran(const vector<vector<int>> &matrix, int m, int n);
void tongGiaTriTungDong(const vector<vector<int>> &matrix, int m, int n);
void phanTuLonNhatTungCot(const vector<vector<int>> &matrix, int m, int n);
void xuatBien(const vector<vector<int>> &matrix, int m, int n);
void phanTuCucDai(const vector<vector<int>> &matrix, int m, int n);
void xuatDongChan(const vector<vector<int>> &matrix, int m, int n);
void sapXepTangTungDong(vector<vector<int>> &matrix, int m, int n);

int main() {
	int m, n, a, b;
	cout << "Cau 1: ";
	cout << "\t Nhap so dong (m): ";
	cin >> m;
	cout << "\t Nhap so cot (n): ";
	cin >> n;
	cout << "\t Nhap can duoi (a): ";
	cin >> a;
	cout << "\t Nhap can tren (b): ";
	cin >> b;

	// Khởi tạo ma trận
	vector<vector<int>> matrix(m, vector<int>(n));

	// Sinh số ngẫu nhiên
	srand(time(0));

	// Tạo và xuất ma trận
	taoMaTran(matrix, m, n, a, b);
	cout << "Ma tran: \n";
	xuatMaTran(matrix, m, n);

	// Tính và xuất tổng giá trị từng dòng
	cout << "\nCau 2: Tong gia tri tung dong: \n";
	tongGiaTriTungDong(matrix, m, n);

	// Xuất phần tử lớn nhất trên từng cột
	cout << "\nCau 3: Phan tu lon nhat tung cot: \n";
	phanTuLonNhatTungCot(matrix, m, n);

	// Xuất các phần tử thuộc các đường biên
	cout << "\nCau 4: Phan tu duong bien tren, duoi, trai, phai: \n";
	xuatBien(matrix, m, n);

	// Xuất phần tử cực đại
	cout << "\nCau 5: Phan tu cuc dai: \n";
	phanTuCucDai(matrix, m, n);

	// Xuất dòng chỉ chứa số chẵn
	cout << "\nCau 8: Dong chi chua so chan: \n";
	xuatDongChan(matrix, m, n);

	// Sắp xếp ma trận tăng theo từng dòng
	sapXepTangTungDong(matrix, m, n);
	cout << "\nCau 9: Ma tran sau khi sap xep tung dong tang dan: \n";
	xuatMaTran(matrix, m, n);

	cout << "\n \t ____Nhan phim bat ky de thoat____";
	cin.ignore();
	cin.get();

	return 0;
}

// Tạo ma trận với các phần tử ngẫu nhiên từ a đến b
void taoMaTran(vector<vector<int>> &matrix, int m, int n, int a, int b) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			matrix[i][j] = a + rand() % (b - a + 1);
		}
	}
}

// Xuất ma trận
void xuatMaTran(const vector<vector<int>> &matrix, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

// Tính và xuất tổng giá trị từng dòng
void tongGiaTriTungDong(const vector<vector<int>> &matrix, int m, int n) {
	for (int i = 0; i < m; ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			sum += matrix[i][j];
		}
		cout << "Dong " << i << ": " << sum << endl;
	}
}

// Xuất phần tử lớn nhất trên từng cột
void phanTuLonNhatTungCot(const vector<vector<int>> &matrix, int m, int n) {
	for (int j = 0; j < n; ++j) {
		int max = matrix[0][j];
		for (int i = 1; i < m; ++i) {
			if (matrix[i][j] > max) {
				max = matrix[i][j];
			}
		}
		cout << "Cot " << j << ": " << max << endl;
	}
}

// Xuất các phần tử thuộc các đường biên
void xuatBien(const vector<vector<int>> &matrix, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
				cout << matrix[i][j] << " ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
}

// Xuất phần tử cực đại
void phanTuCucDai(const vector<vector<int>> &matrix, int m, int n) {
	int max = matrix[0][0];
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] > max) {
				max = matrix[i][j];
			}
		}
	}
	cout << max << endl;
}

// Xuất dòng chỉ chứa số chẵn
void xuatDongChan(const vector<vector<int>> &matrix, int m, int n) {
	bool foundEvenRow = false;
	for (int i = 0; i < m; ++i) {
		bool isEvenRow = true;
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] % 2 != 0) {
				isEvenRow = false;
				break;
			}
		}
		if (isEvenRow) {
			foundEvenRow = true;
			for (int j = 0; j < n; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	if (!foundEvenRow) {
		cout << "Khong co dong nao chi chua so chan.\n";
	}
}

// Sắp xếp ma trận tăng theo từng dòng
void sapXepTangTungDong(vector<vector<int>> &matrix, int m, int n) {
	for (int i = 0; i < m; ++i) {
		sort(matrix[i].begin(), matrix[i].end());
	}
}

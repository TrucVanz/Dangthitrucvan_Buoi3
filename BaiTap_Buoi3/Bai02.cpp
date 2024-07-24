#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Hàm tạo ma trận vuông chứa số nguyên ngẫu nhiên
void taoMaTran(vector<vector<int>>& maTran, int n) {
	srand(time(0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			maTran[i][j] = rand() % 100; // Số nguyên ngẫu nhiên từ 0 đến 99
		}
	}
}

// Hàm xuất ma trận
void xuatMaTran(const vector<vector<int>>& maTran) {
	for (const auto& hang : maTran) {
		for (int giaTri : hang) {
			cout << giaTri << " ";
		}
		cout << endl;
	}
}

// Hàm xuất các phần tử trên đường chéo chính
void xuatDuongCheoChinh(const vector<vector<int>>& maTran) {
	for (int i = 0; i < maTran.size(); ++i) {
		cout << maTran[i][i] << " ";
	}
	cout << endl;
}

// Hàm xuất các phần tử thuộc đường chéo song song với đường chéo chính
void xuatDuongCheoSongSong(const vector<vector<int>>& maTran) {
	int n = maTran.size();
	for (int k = 1; k < n; ++k) {
		// Dưới đường chéo chính
		for (int i = k, j = 0; i < n && j < n; ++i, ++j) {
			cout << maTran[i][j] << " ";
		}
		cout << endl;
		// Trên đường chéo chính
		for (int i = 0, j = k; i < n && j < n; ++i, ++j) {
			cout << maTran[i][j] << " ";
		}
		cout << endl;
	}
}

// Hàm tìm phần tử lớn nhất thuộc tam giác trên của đường chéo chính
int timMaxTamGiacTren(const vector<vector<int>>& maTran) {
	int maxVal = maTran[0][0];
	int n = maTran.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (maTran[i][j] > maxVal) {
				maxVal = maTran[i][j];
			}
		}
	}
	return maxVal;
}

// Hàm sắp xếp ma trận tăng dần theo kiểu zic zắc
void sapXepZigZag(vector<vector<int>>& maTran) {
	int n = maTran.size();
	vector<int> temp;
	for (const auto& hang : maTran) {
		temp.insert(temp.end(), hang.begin(), hang.end());
	}
	sort(temp.begin(), temp.end());

	int index = 0;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; ++j) {
				maTran[i][j] = temp[index++];
			}
		}
		else {
			for (int j = n - 1; j >= 0; --j) {
				maTran[i][j] = temp[index++];
			}
		}
	}
}

// Hàm sắp xếp đường chéo chính tăng dần từ trên xuống dưới
void sapXepDuongCheoChinh(vector<vector<int>>& maTran) {
	int n = maTran.size();
	vector<int> duongCheo;
	for (int i = 0; i < n; ++i) {
		duongCheo.push_back(maTran[i][i]);
	}
	sort(duongCheo.begin(), duongCheo.end());
	for (int i = 0; i < n; ++i) {
		maTran[i][i] = duongCheo[i];
	}
}

int main() {
	int n = 5;
	vector<vector<int>> maTran(n, vector<int>(n));

	taoMaTran(maTran, n);
	cout << "Cau 1: Ma Tran duoc tao ngau nhien:" << endl;
	xuatMaTran(maTran);

	cout << "\nCau 2: Cac phan tu tren duong cheo chinh:" << endl;
	xuatDuongCheoChinh(maTran);

	cout << "\nCau 3: Cac phan tu tren duong cheo song song:" << endl;
	xuatDuongCheoSongSong(maTran);

	int maxVal = timMaxTamGiacTren(maTran);
	cout << "\nCau 4: Phan tu lon nhat thuoc tam giac tren cua duong cheo chinh: " << maxVal << endl;

	sapXepZigZag(maTran);
	cout << "\nCau 5: Ma Tran sap xep theo kieu zigzag:" << endl;
	xuatMaTran(maTran);

	sapXepDuongCheoChinh(maTran);
	cout << "\nCau 6: Ma Tran voi duong cheo chinh sap xep tang dan:" << endl;
	xuatMaTran(maTran);

	cout << "\n\t ___Nhan phim bat ky de thoat___";
	cin.ignore();
	cin.get();
	return 0;
}

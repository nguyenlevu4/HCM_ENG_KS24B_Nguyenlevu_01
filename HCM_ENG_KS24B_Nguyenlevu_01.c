#include <stdio.h>

int main() {
	int n;

	int arr[n];
	int choice;
	do {
		printf("\n-------------MENU--------------\n");
		printf("1. nhap so phan cho mang\nn");
		printf("2. in cac gia tri cac phan theo mang gia tri\n");
		printf("3. dem luong so nguyen to trong mang\n");
		printf("4. tim gia tri nho thu 2 trong mang\n");
		printf("5. them phan tu vao vi tri ngau nhien\n");
		printf("6. xoa phan tu tai vi tri cu the\n");
		printf("7. xap sep mang theo thu tu giam dan\n");
		printf("8. tim kiem phan tu trong mang\n");
		printf("10. dao nguoc so trong mang");
		printf("nhap lua chon cua ban(1-10): \n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Nhap so phan tu cho mang: \n");
			scanf("%d", &n);
			printf("Nhap cac phan tu cua mang:\n");
			for (int i = 0; i < n; i++) {
				printf("arr[%d] = ", i);
				scanf("%d", &arr[i]);
			}
			break;
		case 2:
			printf("Gia tri cac phan tu trong mang:\n");
			for (int i = 0; i < n; i++) {
				printf("arr[%d] = %d\n", i, arr[i]);
			}
			break;

		case 4:
			int min = arr[0], max = arr[0];
			for (int i = 1; i < n; i++) {
				if (arr[i] < min) min = arr[i];
			}
			printf("Gia tri nho thu hai: %d\n", min+1);
			break;
		case 5: {
			int newValue;
			printf("Nhap gia tri can them: ");
			scanf("%d", &newValue);
			arr[n] = newValue;
			n++;
			printf("Da them phan tu vao mang.\n");
			break;
		}
		case 6: {
			int a;
			printf("Nhap vi tri can xoa (0 - %d): ", n - 1);
			scanf("%d", &a);
			if (a >= 0 && a < n) {
				for (int i = a; i < n - 1; i++) {
					arr[i] = arr[i + 1];
				}
				n--;
				printf("Da xoa phan tu tai vi tri %d.\n", a);
			} else {
				printf("Vi tri khong hop le.\n");
			}
			break;
		}
		case 7:
			for(int i=0; i < n; i++) {
				int key = arr[i];
				int j=i-1;
				while(j>=0 && arr[i]>key) {
					arr[j+1]=arr[i];
					j--;
				}
				arr[j+1]=key;
			}
			printf("mang theo thu tu giam dan");
			for(int i=1; i < n; i++) {
				printf("%d ",arr[i]);
			}
			printf("\n");
		case 8:
			int b, c = 0;
			printf("Nhap gia tri can tim: ");
			scanf("%d", &b);
			for (int i = 0; i < n; i++) {
				if (arr[i] == b) {
					printf("Gia tri %d xuat hien o vi tri %d.\n", b, i);
					c = 1;
					break;
				}
			}
			if (!c) {
				printf("Khong tim thay gia tri %d trong mang.\n", b);
			}
			break;
	
			case 10:
				for(int i=1; i < n; i++) {
					int key = arr[i];
					int j=i-1;
					while(j<=0 && arr[i]>key) {
						arr[j+1]=arr[i];
						j++;
					}
					arr[j+1]=key;
				}
				printf("mang theo thu tu giam dan");
				for(int i=1; i < n; i++) {
					printf("%d ",arr[i]);
				}
				printf("\n");

			case 0:
				printf("Thoat chuong trinh.\n");
				break;

			default:
				printf("Lua chon khong hop le.\n");
				break;
			}
		}
		while (choice != 0);

		return 0;
	}
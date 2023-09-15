/*                   BAI TAP LON MON KY THUAT LAP TRINH 
DE TAI 07: VIET CHUONG TRINH QUAN LY VIEC CHO THUE SAN CO NHAN TAO CUA MOT HO KINH DOANH
	NHOM THUC HIEN: 08 - BAT DAU TU 05/09/21 DEN KET THUC 19/09/21                    */

//----------------------------------------------------------------------------------------------------------------
// KHAI BAO THU VIEN
#include <stdio.h>
#include <conio.h>



//----------------------------------------------------------------------------------------------------------------
// KHAI BAO CONSTANT VA STRUCT
#define _CRT_SECURE_NO_WARNINGS
struct KHACHTHUE
{
	char sdt[11];
	char maKhach[6], hoTen[25];
};
struct SANCO
{
	char maSan[5];
	int loaiSan;
};
struct SANPHAM
{
	int giaBan;
	char maSP[5], tenSP[20], donViTinh[10];
};
struct DATE
{
	int ngay, thang, nam;
};
struct TIME
{
	int gio, phut;
};
struct HOADON
{
	SANCO maSan;
	KHACHTHUE maKhach;
	DATE ngayThue;
	TIME gioBatDau, gioKetThuc;
	int soHoaDon, tongTien;
};
struct CTHOADON
{
	SANPHAM maSP;
	int soLuong, thanhTien;
};
//----------------------------------------------------------------------------------------------------------------
// KHAI BAO NGUYEN HAM
void docFileKhachThue(char *tenfile,KHACHTHUE kt[], int &sophantu);
void xuatThongTinKT(KHACHTHUE kt);
void docFileSanCo(char *tenfile, SANCO sc[], int &sophantu);
void xuatThongTinSC(SANCO sc);


//----------------------------------------------------------------------------------------------------------------
void main()
{
	KHACHTHUE dskt[100];
	SANCO dssc[100];
	int sophantu = 0;
	docFileKhachThue("DataKT.txt",dskt,sophantu);
	docFileSanCo("DataSC.txt",dssc,sophantu);
	for(int i= 0; i<sophantu ;i++)
	{
		xuatThongTinKT(dskt[i]);
		xuatThongTinSC(dssc[i]);
	}
		
	getch();
}



//----------------------------------------------------------------------------------------------------------------
// HAM CON

//doc file
void docFileKhachThue(char *tenfile, KHACHTHUE kt[], int &sophantu)
{
	FILE* f=fopen(tenfile,"rt");
	if(f==NULL)//kiem tra tep rong
		return;
	int i = 0;
	while(!feof(f))
	{
		fscanf(f,"\n%[^-]-%[^-]-%[^\n]",&kt[i].sdt,&kt[i].maKhach,&kt[i].hoTen);
		i++;
	}
	sophantu = i;
	fclose(f);
}
void xuatThongTinKT(KHACHTHUE kt)
{
	printf("%s - %s - %s\n",kt.sdt, kt.maKhach, kt.hoTen);
}

void docFileSanCo(char *tenfile, SANCO sc[], int &sophantu)
{
	FILE* f=fopen(tenfile,"rt");
	if(f==NULL)//kiem tra tep rong
		return;
	int i = 0;
	while(!feof(f))
	{
		fscanf(f,"\n%[^-]-%[^-]-%[^\n]",&sc[i].maSan,&sc[i].loaiSan);
		i++;
	}
	sophantu = i;
	fclose(f);
}
void xuatThongTinSC(SANCO sc)
{
	printf("%s - %d\n",sc.maSan,sc.loaiSan);
	printf("%s - %d\n",sc.maSan,sc.loaiSan);//hehe
}


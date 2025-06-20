#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct Layanan {
    string nama;
    int harga;
};

struct Tamu {
    string nama;
    string nomorKTP; 
    string noKamar;
    string tipeKamar;
    int durasiInap;
    int total;
    vector<Layanan> layananTambahan;
};

struct Special {
    string nama;
    string nomorKTP; 
    string package;
};

struct Kamar {
    string tipe;
    int harga;
};

struct Ruangan {
    string nama;
    int harga;
};

struct Rating {
    string noKamar;
    string tipeKamar;
    int nilai;
    string komentar;
};

struct TransaksiSelesai {
    string nama;
    string nomorKTP;
    string noKamar;
    string tipeKamar;
    int durasiInap;
    int total;
    string jenisTransaksi;
    string package;
    vector<Layanan> layananTambahan;
};

struct SpecialTransaksiSelesai {
    string nama;
    string nomorKTP;
    string package;
    int total;
};

class Hotel {
private:
    vector<Tamu> daftarTamu;
    vector<Special> daftarSpecial;
    vector<TransaksiSelesai> transaksiRoomSelesai;
    vector<SpecialTransaksiSelesai> transaksiSpecialSelesai;
    vector<Rating> daftarRating;
    
    string admin = "admin";
    string passAdmin = "kitaadmin";
    string pengunjung = "pengunjung";
    string passPengunjung = "kitapengunjung";
    
    //Kamar
    bool d001 = true; 
    bool d002 = true;
    bool d003 = true;
    bool d004 = true;
    bool d005 = true;
    bool e001 = true; 
    bool e002 = true;
    bool e003 = true;
    bool e004 = true;
    bool e005 = true;
    bool f001 = true;
    bool f002 = true;
    bool f003 = true;
    bool f004 = true;
    bool f005 = true;
    bool es001 = true; 
    bool es002 = true;
    bool es003 = true;
    bool es004 = true;
    bool es005 = true;
    bool p001 = true;
    bool p002 = true;
    bool p003 = true;
    bool p004 = true;
    bool p005 = true;
    
    // Special Package
    bool a001 = true;
    bool a002 = true;
    bool a003 = true;
    bool g001 = true;
    bool g002 = true;
    bool g003 = true;
    bool ab001 = true;
    bool ab002 = true;
    bool ab003 = true;
    bool pk001 = true;
    bool pk002 = true;
    bool pk003 = true;
    bool u001 = true;
    bool u002 = true;
    bool u003 = true;
    
public:
	
	void beriRating(string noKamar, string tipeKamar) {
        Rating r;
        r.noKamar = noKamar;
        r.tipeKamar = tipeKamar;
        
        system("cls");
        cout << "\n------------------------------------------------\n";
        cout << "           BERI RATING KAMAR " << noKamar << "         \n";
        cout << "------------------------------------------------\n";
        
        do {
            cout << "Berikan rating (1-5): ";
            cin >> r.nilai;
            if (r.nilai < 1 || r.nilai > 5) {
                cout << "Rating harus antara 1-5!\n";
            }
        } while (r.nilai < 1 || r.nilai > 5);
        
        cout << "Masukkan komentar (opsional): ";
        cin.ignore();
        getline(cin, r.komentar);
        
        daftarRating.push_back(r);
        
        cout << "\nTerima kasih atas rating Anda!\n";
        system("pause");
    }
    
    void tampilkanRating() {
        system("cls");
        cout << "\n------------------------------------------------\n";
        cout << "           DAFTAR RATING KAMAR         \n";
        cout << "------------------------------------------------\n";
        
        if (daftarRating.empty()) {
            cout << "Belum ada rating kamar.\n";
            system("pause");
            return;
        }
        
        vector<string> tipeKamar;
        vector<int> totalRating;
        vector<int> jumlahRating;
        
        for (int i = 0; i < daftarRating.size(); i++) {
            bool found = false;
            for (int j = 0; j < tipeKamar.size(); j++) {
                if (tipeKamar[j] == daftarRating[i].tipeKamar) {
                    totalRating[j] += daftarRating[i].nilai;
                    jumlahRating[j]++;
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                tipeKamar.push_back(daftarRating[i].tipeKamar);
                totalRating.push_back(daftarRating[i].nilai);
                jumlahRating.push_back(1);
            }
        }
        
        cout << "\nRata-rata Rating per Tipe Kamar:\n";
        cout << "----------------------------------------\n";
        for (int i = 0; i < tipeKamar.size(); i++) {
            double rata = static_cast<double>(totalRating[i]) / jumlahRating[i];
            cout << tipeKamar[i] << ": " << fixed << setprecision(1) << rata << "/5 (" 
                 << jumlahRating[i] << " rating)\n";
        }
        
        cout << "\nDetail Rating:\n";
        cout << "----------------------------------------\n";
        for (int i = 0; i < daftarRating.size(); i++) {
            cout << "Kamar: " << daftarRating[i].noKamar << " (" << daftarRating[i].tipeKamar << ")\n";
            cout << "Rating: " << daftarRating[i].nilai << "/5\n";
            if (!daftarRating[i].komentar.empty()) {
                cout << "Komentar: " << daftarRating[i].komentar << "\n";
            }
            cout << "----------------------------------------\n";
        }
        
        system("pause");
    }
    
    void cariPengunjung() {
	    system("cls");
	
	    if (daftarTamu.empty()) {
	        cout << "Tidak ada tamu yang terdaftar.\n";
	        system("pause");
	        return;
	    }
	
	    string nomorKTP;
	    cout << "Masukkan nomor KTP tamu: ";
	    cin.ignore();
	    getline(cin, nomorKTP);
	
	    bool ditemukan = false;
	    for (size_t i = 0; i < daftarTamu.size(); ++i) {
	        Tamu tamu = daftarTamu[i]; 
	
	        if (tamu.nomorKTP == nomorKTP) {
	            cout << "\n------------------------------------------\n";
	            cout << "              Detail Tamu                \n";
	            cout << "------------------------------------------\n";
	            cout << "Nama        : " << tamu.nama << endl;
	            cout << "Nomor KTP   : " << tamu.nomorKTP << endl;
	            cout << "Nomor Kamar : " << tamu.noKamar << endl;
	            cout << "Tipe Kamar  : " << tamu.tipeKamar << endl;
	            cout << "Durasi Inap : " << tamu.durasiInap << " malam\n";
	            cout << "------------------------------------------\n";
	            ditemukan = true;
	            break;
	        }
	    }
	
	    if (!ditemukan) {
	        cout << "Tamu dengan nomor KTP " << nomorKTP << " tidak ditemukan.\n";
	    }
	
	    system("pause");
	}

    void cariKamar() {
        system("cls");
        string noKamar;
        cout << "Masukkan nomor kamar (contoh: D001, E002): ";
        cin >> noKamar;

        for (size_t i = 0; i < noKamar.length(); ++i) {
            noKamar[i] = toupper(noKamar[i]);
        }

        bool ditemukan = false;
        bool statusKamar = false;

        if (noKamar == "D001") { 
			statusKamar = d001; 
			ditemukan = true; 
		} else if (noKamar == "D002") { 
			statusKamar = d002; 
			ditemukan = true; 
		} else if (noKamar == "D003") { 
			statusKamar = d003; 
			ditemukan = true; 
		} else if (noKamar == "D004") { 
			statusKamar = d004; 
			ditemukan = true; 
		} else if (noKamar == "D005") { 
			statusKamar = d005; 
			ditemukan = true; 
		} else if (noKamar == "E001") { 
			statusKamar = e001; 
			ditemukan = true; 
		} else if (noKamar == "E002") { 
			statusKamar = e002; 
			ditemukan = true; 
		} else if (noKamar == "E003") { 
			statusKamar = e003; 
			ditemukan = true; 
		} else if (noKamar == "E004") { 
			statusKamar = e004; 
			ditemukan = true; 
		} else if (noKamar == "E005") { 
			statusKamar = e005; 
			ditemukan = true; 
		} else if (noKamar == "F001") { 
			statusKamar = f001; 
			ditemukan = true; 
		} else if (noKamar == "F002") { 
			statusKamar = f002; 
			ditemukan = true; 
		} else if (noKamar == "F003") { 
			statusKamar = f003; 
			ditemukan = true; 
		} else if (noKamar == "F004") { 
			statusKamar = f004; 
			ditemukan = true; 
		} else if (noKamar == "F005") { 
			statusKamar = f005; 
			ditemukan = true; 
		} else if (noKamar == "ES001") { 
			statusKamar = es001; 
			ditemukan = true; 
		} else if (noKamar == "ES002") { 
			statusKamar = es002; 
			ditemukan = true; 
		} else if (noKamar == "ES003") { 
			statusKamar = es003; 
			ditemukan = true; 
		} else if (noKamar == "ES004") { 
			statusKamar = es004; 
			ditemukan = true; 
		} else if (noKamar == "ES005") { 
			statusKamar = es005; 
			ditemukan = true; 
		} else if (noKamar == "P001") { 
			statusKamar = p001; 
			ditemukan = true; 
		} else if (noKamar == "P002") { 
			statusKamar = p002; 
			ditemukan = true; 
		} else if (noKamar == "P003") { 
			statusKamar = p003; 
			ditemukan = true; 
		} else if (noKamar == "P004") { 
			statusKamar = p004; 
			ditemukan = true; 
		} else if (noKamar == "P005") { 
			statusKamar = p005; 
			ditemukan = true; 
		}
        

        if (ditemukan) {
            cout << "\nStatus Kamar " << noKamar << " : ";
            cout << (statusKamar ? "Tersedia" : "Tidak Tersedia") << endl;

            if (!statusKamar) {
                bool tamuDitemukan = false;
                for (size_t i = 0; i < daftarTamu.size(); ++i) {
                    if (daftarTamu[i].noKamar == noKamar) {
                        cout << "\n------------------------------------------\n";
                        cout << "      Detail Tamu        \n";
                        cout << "------------------------------------------\n";
                        cout << "Nama        : " << daftarTamu[i].nama << endl;
                        cout << "Nomor KTP   : " << daftarTamu[i].nomorKTP << endl;
                        cout << "Durasi Inap : " << daftarTamu[i].durasiInap << " malam\n";
                        cout << "------------------------------------------\n";
                        tamuDitemukan = true;
                        break;
                    }
                }
                if (!tamuDitemukan) {
                    cout << "Kamar dipesan tetapi data tamu tidak ditemukan.\n";
                }
            }
        } else {
            cout << "Nomor kamar tidak valid.\n";
        }
        system("pause");
    }
    
    void SortbyName() {
    system("cls");
    
    if (daftarTamu.empty()) {
        cout << "Tidak ada tamu yang terdaftar.\n";
        system("pause");
        return;
    }

   
    for (int i = 0; i < daftarTamu.size() - 1; ++i) {
        for (int j = 0; j < daftarTamu.size() - i - 1; ++j) {
            if (daftarTamu[j].nama > daftarTamu[j + 1].nama) {
                Tamu temp = daftarTamu[j];
                daftarTamu[j] = daftarTamu[j + 1];
                daftarTamu[j + 1] = temp;
            }
        }
    }

    cout << "\n------------------------------------------------\n";
    cout << "           Daftar Tamu (Sort by Name)         \n";
    cout << "------------------------------------------------\n";
    for (size_t i = 0; i < daftarTamu.size(); ++i) {
        Tamu tamu = daftarTamu[i]; 
        cout << "------------------------------------------\n";
        cout << "Nama        : " << tamu.nama << endl;
        cout << "Nomor KTP   : " << tamu.nomorKTP << endl;
        cout << "Nomor Kamar : " << tamu.noKamar << endl;
        cout << "Tipe Kamar  : " << tamu.tipeKamar << endl;
        cout << "Durasi Inap : " << tamu.durasiInap << " malam\n";
    }
	cout << "------------------------------------------\n";
    system("pause");
}

	void SortbyNumber() {
    system("cls");
    
    if (daftarTamu.empty()) {
        cout << "Tidak ada tamu yang terdaftar.\n";
        system("pause");
        return;
    }

    for (int i = 0; i < daftarTamu.size() - 1; ++i) {
        for (int j = 0; j < daftarTamu.size() - i - 1; ++j) {
            if (daftarTamu[j].noKamar > daftarTamu[j + 1].noKamar) {
                Tamu temp = daftarTamu[j];
                daftarTamu[j] = daftarTamu[j + 1];
                daftarTamu[j + 1] = temp;
            }
        }
    }

    cout << "\n------------------------------------------------\n";
    cout << "       Daftar Tamu (Sort by Room Number)       \n";
    cout << "------------------------------------------------\n";
    for (size_t i = 0; i < daftarTamu.size(); ++i) {
        Tamu tamu = daftarTamu[i]; 
        cout << "------------------------------------------\n";
        cout << "No. Kamar  : " << tamu.noKamar << endl;
        cout << "Nama       : " << tamu.nama << endl;
        cout << "Tipe Kamar : " << tamu.tipeKamar << endl;
        cout << "Durasi     : " << tamu.durasiInap << " malam\n";
    }
    cout << "------------------------------------------\n";
    system("pause");
    
}

    void laporan() {
	    system("cls");
	    cout << "\n------------------------------------------------\n";
	    cout << "           LAPORAN HOTEL THE ALANA         \n";
	    cout << "------------------------------------------------\n";
	    cout << "\nDaftar Tamu yang Menginap:\n";
	    
	    if (daftarTamu.empty()) {
	        cout << "Tidak ada tamu yang menginap.\n";
	        cout << "--------------------------------------------------\n";

	    } else {
	        for (size_t i = 0; i < daftarTamu.size(); ++i) {
	            Tamu tamu = daftarTamu[i]; 
	            cout << "------------------------------------------\n";
	            cout << "Nama        : " << tamu.nama << endl;
	            cout << "Nomor KTP   : " << tamu.nomorKTP << endl;
	            cout << "Nomor Kamar : " << tamu.noKamar << endl;
	            cout << "Tipe Kamar  : " << tamu.tipeKamar << endl;
	            cout << "Durasi Inap : " << tamu.durasiInap << " malam\n";
	        }
	    }
	    
	    cout << "\nDaftar Paket Khusus yang Dipesan:\n";
	    if (daftarSpecial.empty()) {
	        cout << "Tidak ada paket khusus yang dipesan.\n";
	        cout << "--------------------------------------------------\n";

	    } else {
	        for (size_t i = 0; i < daftarSpecial.size(); ++i) {
	            Special special = daftarSpecial[i]; 
	            cout << "------------------------------------------\n";
	            cout << "Nama        : " << special.nama << endl;
	            cout << "Nomor KTP   : " << special.nomorKTP << endl;
	            cout << "Paket       : " << special.package << endl;
	        }
	    }
	    
	    cout << "\n------------------------------------------------\n";
	    cout << "\nStatus Kamar:\n";
	    cout << "\n------------------------------------------------\n";
	    cout << "Deluxe Room:\n";
	    cout << "D001: " << (d001 ? "Tersedia" : "Terisi") 
			 << " | D002: " << (d002 ? "Tersedia" : "Terisi") 
	         << " | D003: " << (d003 ? "Tersedia" : "Terisi") 
			 << " | D004: " << (d004 ? "Tersedia" : "Terisi") 
	         << " | D005: " << (d005 ? "Tersedia" : "Terisi") << endl;
	         
	    cout << "\nExecutive Club:\n";
	    cout << "E001: " << (e001 ? "Tersedia" : "Terisi") 
			 << " | E002: " << (e002 ? "Tersedia" : "Terisi") 
	         << " | E003: " << (e003 ? "Tersedia" : "Terisi") 
			 << " | E004: " << (e004 ? "Tersedia" : "Terisi") 
	         << " | E005: " << (e005 ? "Tersedia" : "Terisi") << endl;
	         
	    cout << "\nFamily Room:\n";
	    cout << "F001: " << (f001 ? "Tersedia" : "Terisi") 
			 << " | F002: " << (f002 ? "Tersedia" : "Terisi") 
	         << " | F003: " << (f003 ? "Tersedia" : "Terisi") 
			 << " | F004: " << (f004 ? "Tersedia" : "Terisi") 
	         << " | F005: " << (f005 ? "Tersedia" : "Terisi") << endl;
	         
	    cout << "\nExecutive Suite:\n";
	    cout << "ES001: " << (es001 ? "Tersedia" : "Terisi") 
			 << " | ES002: " << (es002 ? "Tersedia" : "Terisi") 
	         << " | ES003: " << (es003 ? "Tersedia" : "Terisi") 
			 << " | ES004: " << (es004 ? "Tersedia" : "Terisi") 
	         << " | ES005: " << (es005 ? "Tersedia" : "Terisi") << endl;
	         
	    cout << "\nPresidential Suite:\n";
	    cout << "P001: " << (p001 ? "Tersedia" : "Terisi") 
			 << " | P002: " << (p002 ? "Tersedia" : "Terisi") 
	         << " | P003: " << (p003 ? "Tersedia" : "Terisi") 
			 << " | P004: " << (p004 ? "Tersedia" : "Terisi") 
	         << " | P005: " << (p005 ? "Tersedia" : "Terisi") << endl;
	         
	    cout << "\n------------------------------------------------\n";
	    
	    cout << "\n------------------------------------------------\n";
	    cout << "\nStatus Special Package & Event:\n";
	    cout << "\n------------------------------------------------\n";
	    
	    cout << "Amartapura Plenary Hall:\n";
	    cout << "A001: " << (a001 ? "Tersedia" : "Terisi") 
			 << " | A002: " << (a002 ? "Tersedia" : "Terisi") 
	         << " | A003: " << (a003 ? "Tersedia" : "Terisi") << endl;
	         
	    cout << "\nGround Floor Meeting Room\:\n";
	    cout << "G001: " << (g001 ? "Tersedia" : "Terisi") 
			 << " | G002: " << (g002 ? "Tersedia" : "Terisi") 
	         << " | G003: " << (g003 ? "Tersedia" : "Terisi")<< endl;
	         
	    cout << "\nAbiyasa:\n";
	    cout << "AB001: " << (ab001 ? "Tersedia" : "Terisi") 
			 << " | AB002: " << (ab002 ? "Tersedia" : "Terisi") 
	         << " | AB003: " << (ab003 ? "Tersedia" : "Terisi") << endl;
	         
	    cout << "\nPerikesit:\n";
	    cout << "PK001: " << (pk001 ? "Tersedia" : "Terisi") 
			 << " | PK002: " << (pk002 ? "Tersedia" : "Terisi") 
	         << " | PK003: " << (pk003 ? "Tersedia" : "Terisi") << endl;
	         
	    cout << "\nUtari:\n";
	    cout << "U001: " << (u001 ? "Tersedia" : "Terisi") 
			 << " | U002: " << (u002 ? "Tersedia" : "Terisi") 
	         << " | U003: " << (u003 ? "Tersedia" : "Terisi") << endl;
	         
	    cout << "\n------------------------------------------------\n";
	    system("pause");
	}
	
	void laporanTransaksiSelesai() {
	    system("cls");
	    cout << "\n------------------------------------------------\n";
	    cout << "           LAPORAN TRANSAKSI SELESAI         \n";
	    cout << "------------------------------------------------\n";
	
	    cout << "\nDaftar Transaksi Room :\n";
	    if (transaksiRoomSelesai.empty()) {
	        cout << "Tidak ada transaksi room yang selesai.\n";
	        
	    } else {
	        for (size_t i = 0; i < transaksiRoomSelesai.size(); ++i) {
	            TransaksiSelesai ts = transaksiRoomSelesai[i];
	            
	            cout << "------------------------------------------\n";
	            cout << "Nama        : " << ts.nama << endl;
	            cout << "Nomor KTP   : " << ts.nomorKTP << endl;
	            cout << "Nomor Kamar : " << ts.noKamar << endl;
	            cout << "Tipe Kamar  : " << ts.tipeKamar << endl;
	            cout << "Durasi Inap : " << ts.durasiInap << " malam\n";
	            cout << "Total       : Rp " << ts.total << endl;
	            
	            if (!ts.layananTambahan.empty()) {
	                cout << "Layanan Tambahan:\n";
	                for (size_t j = 0; j < ts.layananTambahan.size(); ++j) {
	                    Layanan layanan = ts.layananTambahan[j];
	                    cout << "- " << layanan.nama << ": Rp " << layanan.harga << endl;
	                }
	            }
	        }
	    }
	
	    cout << "\nDaftar Transaksi Special Package :\n";
		    if (transaksiSpecialSelesai.empty()) {
		        cout << "Tidak ada transaksi special package yang selesai.\n";
		    } else {
		        for (size_t i = 0; i < transaksiSpecialSelesai.size(); ++i) {
		            SpecialTransaksiSelesai sts = transaksiSpecialSelesai[i];
		            cout << "------------------------------------------\n";
		            cout << "Nama        : " << sts.nama << endl;
		            cout << "Nomor KTP   : " << sts.nomorKTP << endl;
		            cout << "Package     : " << sts.package << endl;
		            cout << "Total       : Rp " << sts.total << endl;
		        }
		    }
		
		    cout << "\n------------------------------------------------\n";
		    system("pause");
	}
	
	void HapusLaporanT() {
	    system("cls");
	    cout << "\n------------------------------------------------\n";
	    cout << "           HAPUS LAPORAN TRANSAKSI         \n";
	    cout << "------------------------------------------------\n";
	    
	    if (transaksiRoomSelesai.empty() && transaksiSpecialSelesai.empty()) {
	        cout << "Tidak ada laporan transaksi yang tersedia.\n";
	        system("pause");
	        return;
	    }
	    
	    cout << "Pilih jenis transaksi yang ingin dihapus:\n";
	    cout << "1. Transaksi Kamar\n";
	    cout << "2. Transaksi Special Package\n";
	    cout << "3. Hapus Semua Transaksi\n";
	    cout << "0. Kembali\n";
	    cout << "Pilihan : ";
	    
	    int pilihan;
	    cin >> pilihan;
	    
	    switch(pilihan) {
	        case 1: {
	            if (transaksiRoomSelesai.empty()) {
	                cout << "Tidak ada transaksi kamar yang tersedia.\n";
	                break;
	            }
	            
	            cout << "\nMasukkan nomor KTP untuk menghapus transaksi: ";
	            string nomorKTP;
	            cin.ignore();
	            getline(cin, nomorKTP);
	            
	            bool ditemukan = false;
	            for (size_t i = 0; i < transaksiRoomSelesai.size(); i++) {
	                if (transaksiRoomSelesai[i].nomorKTP == nomorKTP) {
	                    transaksiRoomSelesai.erase(transaksiRoomSelesai.begin() + i);
	                    cout << "Transaksi kamar dengan KTP " << nomorKTP << " berhasil dihapus.\n";
	                    ditemukan = true;
	                    break;
	                }
	            }
	            
	            if (!ditemukan) {
	                cout << "Transaksi kamar dengan KTP " << nomorKTP << " tidak ditemukan.\n";
	            }
	            break;
	        }
	        
	        case 2: {
	            if (transaksiSpecialSelesai.empty()) {
	                cout << "Tidak ada transaksi special package yang tersedia.\n";
	                break;
	            }
	            
	            cout << "\nMasukkan nomor KTP untuk menghapus transaksi: ";
	            string nomorKTP;
	            cin.ignore();
	            getline(cin, nomorKTP);
	            
	            bool ditemukan = false;
	            for (size_t i = 0; i < transaksiSpecialSelesai.size(); i++) {
	                if (transaksiSpecialSelesai[i].nomorKTP == nomorKTP) {
	                    transaksiSpecialSelesai.erase(transaksiSpecialSelesai.begin() + i);
	                    cout << "Transaksi special package dengan KTP " << nomorKTP << " berhasil dihapus.\n";
	                    ditemukan = true;
	                    break;
	                }
	            }
	            
	            if (!ditemukan) {
	                cout << "Transaksi special package dengan KTP " << nomorKTP << " tidak ditemukan.\n";
	            }
	            break;
	        }
	        
	        case 3: {
	            char konfirmasi;
	            cout << "\nApakah Anda yakin ingin menghapus SEMUA transaksi? (y/n): ";
	            cin >> konfirmasi;
	            
	            if (tolower(konfirmasi) == 'y') {
	                transaksiRoomSelesai.clear();
	                transaksiSpecialSelesai.clear();
	                cout << "Semua transaksi berhasil dihapus.\n";
	            } else {
	                cout << "Penghapusan dibatalkan.\n";
	            }
	            break;
	        }
	        
	        case 0:
	            return;
	            
	        default:
	            cout << "Pilihan tidak valid.\n";
	            break;
	    }
	    
	    system("pause");
	}


    void menuAdmin() {
        int pil;
        do {
            cout << "\n------------------------------------------------\n";
            cout << "      Selamat Datang Admin        \n";
            cout << "------------------------------------------------\n";
            cout << "1. Cari Pengunjung\n";
            cout << "2. Cari Kamar\n";
            cout << "3. Sort by Nama Pengunjung\n";
            cout << "4. Sort by No.Kamar\n";
            cout << "5. Lihat Laporan\n";
            cout << "6. Lihat Laporan Transaksi Selesai\n";
            cout << "7. Hapus Laporan Transaksi\n";
            cout << "8. Lihat Rating Kamar\n";
            cout << "0. Keluar\n";
            cout << "------------------------------------------------\n";
            cout << "Silahkan pilih (1-4): ";
            cin >> pil;

            switch (pil)
            {
                case 1:
                    cariPengunjung();
                    break;
                case 2:
                    cariKamar();
                    break;
                case 3:
                	SortbyName();
                	break;
                case 4:
                	SortbyNumber();
                	break;
                case 5:
                    laporan();
                    break;
                case 6:
                	laporanTransaksiSelesai();
                break;
                case 7:
                	HapusLaporanT();
                	break;
                case 8:
                	tampilkanRating();
                	break;
                default:
                    cout << "Pilihan Anda Tidak Ada.\n";
                    break;
            }
        } while (pil != 0);
        
        
    }

    void login() {
        int login;
        string username, password;
        
        do {
        	cout << "\n************************************************************************************" << endl;
            cout << "*      \\\\////\\\\\\\\//                                               \\\\////\\\\\\\\//     *" << endl;
            cout << "*      //\\\\\\\\////\\\\    \\\\//    \\\\//     //\\\\     \\\\//    \\\\//     //\\\\\\\\////\\\\     *" << endl;
            cout << "*      \\\\////\\\\\\\\//    //\\\\    //\\\\     \\\\//     //\\\\    //\\\\     \\\\////\\\\\\\\//     *" << endl;
            cout << "*      //\\\\\\\\////\\\\    \\\\//    \\\\//     //\\\\     \\\\//    \\\\//     //\\\\\\\\////\\\\     *" << endl;
            cout << "*      \\\\////\\\\\\\\//    //\\\\    //\\\\     \\\\//     //\\\\    //\\\\     \\\\////\\\\\\\\//     *" << endl;
            cout << "*      //\\\\\\\\////\\\\                                               //\\\\\\\\////\\\\     *" << endl;
            cout << "*      \\\\////\\\\\\\\//                                               \\\\////\\\\\\\\//     *" << endl;
            cout << "*      //\\\\\\\\////\\\\                                               //\\\\\\\\////\\\\     *" << endl;
    
            cout << "************************************************************************************" << endl;
            cout << "@      \\\\//    \\\\//                                               \\\\//    \\\\//     @" << endl;
            cout << "@      //\\\\    //\\\\   ~~~@  H O T E L   T H E   A L A N A  @~~~   //\\\\    //\\\\     @" << endl;
            cout << "@      \\\\//    \\\\//                    BY ASTON                   \\\\//    \\\\//     @" << endl;
            cout << "@      //\\\\    //\\\\                                               //\\\\    //\\\\     @" << endl;
            cout << "====================================================================================" << endl;
            cout << "\n------------------------------------------------\n";
            cout << "      Selamat Datang di Hotel The Alana         \n";
            cout << "------------------------------------------------\n";
            cout << "1. Admin\n";
            cout << "2. Pengunjung\n";
            cout << "0. Keluar\n";
            cout << "------------------------------------------------\n";
            cout << "Silahkan pilih (1-2): ";
            cin >> login;

            switch (login) {
            case 1:
            	cout << "\n------------------------------------------------";
            	cout << "\n**Username dan Password Tidak Boleh Ada Spasi";
            	cout << "\n------------------------------------------------\n";
                cout << "Masukkan Username : ";
                cin >> username;
                cout << "Masukkan Password : ";
                cin >> password;
                if (username == admin && password == passAdmin) {
                    system("cls");
                    menuAdmin();
                    system("pause");
                } else {
                    cout << "Username dan Password tidak sesuai.\n";
                }
                break;
                
            case 2:
            	cout << "\n------------------------------------------------";
            	cout << "\n**Username dan Password Tidak Boleh Ada Spasi";
            	cout << "\n------------------------------------------------\n";
                cout << "Masukkan Username : ";
                cin >> username;
                cout << "Masukkan Password : ";
                cin >> password;
                if (username == pengunjung && password == passPengunjung) {
                    system("cls");
                    menu();
                    system("pause");
                } else {
                    cout << "Username dan Password tidak sesuai.\n";
                }
                break;
                
            default:
                cout << "Terima Kasih Telah Berkunjung.\n";
                break;
            }

        } while (login != 0);
    }

    void informasi() {
    	system("cls");
        cout << "\n------------------------------------------------\n";
        cout << "           Informasi Hotel The Alana         \n";
        cout << "------------------------------------------------\n";
        cout << "Telephone  : +62274888800\n";
        cout << "Website    : www.alanahotels.com\n";
        cout << "Email      : yogyakartainfo@alanahotels.com\n";
        cout << "Lokasi     : Jalan Palagan Tentara Pelajar KM 7\n";
        cout << "             Sleman, Yogyakarta 55581, Indonesia\n";
        cout << "------------------------------------------------\n";
        system("pause");
    }

    void room() {
    	system("cls");
        int pilRoom;

        do {
            
            cout << "\n------------------------------------------------\n";
            cout << "           Room Hotel The Alana         \n";
            cout << "------------------------------------------------\n";
            cout << "1. Tipe-tipe Kamar dan Fasilitasnya\n";
            cout << "2. Cek Ketersediaan Kamar\n";
            cout << "3. Urutkan Kamar (dari yang Termurah)\n";
            cout << "4. Urutkan Kamar (dari yang termahal)\n";
            cout << "0. Kembali ke Menu Utama\n";
            cout << "------------------------------------------------\n";
            cout << "Pilih menu : ";
            cin >> pilRoom;
            
            if (pilRoom == 1) {
            	system("cls");
                cout << "-------------------------------------------------------\n";
                cout << "       Tipe-tipe Kamar Hotel The Alana\n";
                cout << "-------------------------------------------------------\n";
                cout << "1. Deluxe Room     	 -     	 Rp. 800.000,-\n";
                cout << "   Ukuran Kamar : 32 meter persegi\n";
                cout << "   Fasilitas :\n";
                cout << "   - Queen Bed 		         - Tea / Coffee Maker\n";
                cout << "   - International TV Channels	 - Wi-Fi, Writing Desk,\n";
                cout << "   - Smoking Room		 - Non-Smoking Room,\n";
                cout << "   - Shower		         - Toiletries\n";
                cout << "   - In-Room Safe\n";
                cout << "-------------------------------------------------------\n";
                cout << "2.  Executive Club     	 -     	 Rp. 1.100.000,-\n";
                cout << "   Ukuran Kamar : 34 meter persegi\n";
                cout << "   Special Benefits :\n";
                cout << "   - Akses Executive Lounge\n";
                cout << "   Fasilitas :\n";
                cout << "   - Queen Bed                   - Tea / Coffee Maker\n"; 
                cout << "   - Shower                      - Refrigerator\n";
                cout << "   - Minibar                     - Toiletries\n";
                cout << "   - Bathrobes                   - Hair Dryer\n";
                cout << "   - Iron & Ironing Board        - Wi-fi\n";
                cout << "   - International TV Channels,  - Writing Desk\n";
                cout << "   - Dining Area                 - Extra Bed Available\n";
                cout << "   - Non-Smoking Room            - In-Room Safe\n";
                cout << "-------------------------------------------------------\n";
                cout << "3. Family Room     	 -     	 Rp. 1.700.000,-\n";
                cout << "   Ukuran Kamar : 40 meter persegi\n";
                cout << "   Fasilitas :\n";
                cout << "   - Queen Bed                   - Tea / Coffee Maker\n";
                cout << "   - Shower                      - Refrigerator\n";
                cout << "   - Toiletries                  - Hair Dryer\n";
                cout << "   - International TV Channels   - Wi-Fi\n";
                cout << "   - Writing Desk                - Extra Bed Available\n";
                cout << "   - Smoking Room                - Non-Smoking Room\n";
                cout << "   - In-Room Safe\n";
                cout << "-------------------------------------------------------\n";
                cout << "4. Executive suite room     	 -     	 Rp. 2.200.000,-\n";
                cout << "   Ukuran Kamar : 64 meter persegi\n";
                cout << "   Special Benefits :\n";
                cout << "   - Daybed\n";
                cout << "   - Akses Executive Lounge\n";
                cout << "   Fasilitas :\n";
                cout << "   - Queen Bed                   - Tea / Coffee Maker\n"; 
                cout << "   - Shower                      - Refrigerator\n";
                cout << "   - Minibar                     - Toiletries\n";
                cout << "   - Bathtub                     - Hair Dryer\n";
                cout << "   - Bathrobes                   - Iron & Ironing Board\n";
                cout << "   - International TV Channel    - Wi-Fi\n";
                cout << "   - Writing Desk                - Dining Area\n";
                cout << "   - Non-Smoking Room            - Extra Bed Available\n";
                cout << "   - In-Room Safe\n";
                cout << "-------------------------------------------------------\n";
                cout << "5. Presidential Suite     	 -     	 Rp. 3.500.000,-\n";
                cout << "   Ukuran Kamar : 128 meter persegi\n";
                cout << "   Special Benefits :\n";
                cout << "   - City View                   - Jacuzzi\n";
                cout << "   - Akses Executive Lounge\n";
                cout << "   Fasilitas :\n";
                cout << "   - King Bed                    - Tea / Coffee Maker\n"; 
                cout << "   - Shower                      - Refrigerator\n";
                cout << "   - Minibar                     - Toiletries\n";
                cout << "   - Bathrobes                   - Hair Dryer\n";
                cout << "   - Iron & Ironing Board        - Wi-Fi\n";
                cout << "   - International TV Channels   - Writing Desk\n";
                cout << "   - Dining Area                 - Extra Bed Available\n";
                cout << "   - Smoking Room                - Non-Smoking Room\n";
                cout << "   - In Room Safe\n";
                cout << "-------------------------------------------------------\n";
                system("pause");
                
            } else if (pilRoom == 2) {
            	system("cls");
                cout << "--------------------------------------------------\n";
                cout << "       Cek Ketersediaan Kamar\n";
                cout << "--------------------------------------------------\n";
                cout << "1. Deluxe Room\n";
                cout << "   - D001  : " << (d001 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - D002  : " << (d002 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - D003  : " << (d003 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - D004  : " << (d004 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - D005  : " << (d005 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "--------------------------------------------------\n";
                cout << "2. Executive Club\n";
                cout << "   - E001  : " << (e001 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - E002  : " << (e002 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - E003  : " << (e003 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - E004  : " << (e004 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - E005  : " << (e005 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "--------------------------------------------------\n";
                cout << "3. Family Room\n";
                cout << "   - F001  : " << (f001 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - F002  : " << (f002 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - F003  : " << (f003 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - F004  : " << (f004 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - F005  : " << (f005 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "--------------------------------------------------\n";
                cout << "4. Executive Suits Room\n";
                cout << "   - ES001  : " << (es001 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - ES002  : " << (es002 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - ES003  : " << (es003 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - ES004  : " << (es004 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - ES005  : " << (es005 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "--------------------------------------------------\n";
                cout << "5. Presidential Suite\n";
                cout << "   - P001  : " << (p001 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - P002  : " << (p002 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - P003  : " << (p003 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - P004  : " << (p004 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - P005  : " << (p005 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "--------------------------------------------------\n";
				system("pause");
				
				} else if (pilRoom == 3) {
			    system("cls");
			
			    vector<Kamar> kamarList;

			    Kamar k1; 
				k1.tipe = "Deluxe Room"; 
				k1.harga = 800000; 
				kamarList.push_back(k1);
				
			    Kamar k2; 
				k2.tipe = "Executive Club"; 
				k2.harga = 1100000; 
				kamarList.push_back(k2);
				
			    Kamar k3; 
				k3.tipe = "Family Room"; 
				k3.harga = 1700000; 
				kamarList.push_back(k3);
				
			    Kamar k4; 
				k4.tipe = "Executive Suite"; 
				k4.harga = 2200000; 
				kamarList.push_back(k4);
				
			    Kamar k5; 
				k5.tipe = "Presidential Suite"; 
				k5.harga = 3500000; 
				kamarList.push_back(k5);
			
			    for (int i = 0; i < kamarList.size() - 1; ++i) {
			        for (int j = 0; j < kamarList.size() - i - 1; ++j) {
			            if (kamarList[j].harga > kamarList[j + 1].harga) {
			                Kamar temp = kamarList[j];
			                kamarList[j] = kamarList[j + 1];
			                kamarList[j + 1] = temp;
			            }
			        }
			    } 
			
			    cout << "--------------------------------------------------\n";
			    cout << "     Daftar Kamar Hotel dari yang Termurah\n";
			    cout << "--------------------------------------------------\n";
			    for (int i = 0; i < kamarList.size(); ++i) {
			        cout << kamarList[i].tipe << " => Rp. " << kamarList[i].harga << ",-\n";
			    }
			    cout << "--------------------------------------------------\n";
			    system("pause");
			    
			} else if (pilRoom == 4) {
			system("cls");
    
    	vector<Kamar> kamarList;
    
    	Kamar k1; 
		k1.tipe = "Deluxe Room"; 
		k1.harga = 800000; 
		kamarList.push_back(k1);
		
    	Kamar k2; 
		k2.tipe = "Executive Club"; 
		k2.harga = 1100000; 
		kamarList.push_back(k2);
		
    	Kamar k3; 
		k3.tipe = "Family Room"; 
		k3.harga = 1700000; 
		kamarList.push_back(k3);
		
    	Kamar k4; 
		k4.tipe = "Executive Suite"; 
		k4.harga = 2200000; 
		kamarList.push_back(k4);
		
		Kamar k5; 
		k5.tipe = "Presidential Suite"; 
		k5.harga = 3500000; 
		kamarList.push_back(k5);

    	for (int i = 0; i < kamarList.size() - 1; ++i) {
        	for (int j = 0; j < kamarList.size() - i - 1; ++j) {
            	if (kamarList[j].harga < kamarList[j + 1].harga) {
                	Kamar temp = kamarList[j];
                	kamarList[j] = kamarList[j + 1];
                	kamarList[j + 1] = temp;
            	}
        	}
    	}
    	
		cout << "--------------------------------------------------\n";
    	cout << "     Daftar Kamar Hotel dari yang Termahal\n";
    	cout << "--------------------------------------------------\n";
		for (int i = 0; i < kamarList.size(); ++i) {
        	cout << kamarList[i].tipe << " => Rp. " << kamarList[i].harga << ",-\n";
    	}
    	
    	cout << "--------------------------------------------------\n";
    	system("pause");
	
            } else if (pilRoom == 0) {
            	system("cls");
            	return;
			}
			system("cls");
        } while (pilRoom != 0);
    }

    void bookingRoom() {
        Tamu t;
        system("cls");
        cout << "--------------------------------------------------\n";
        cout << "           Booking Room \n";
        cout << "--------------------------------------------------\n";
        cout << "Masukkan nama: ";
        cin.ignore();
        getline(cin, t.nama);
        cout << "Masukkan nomor KTP: ";
        getline(cin, t.nomorKTP);
        cout << "Pilih tipe kamar (Deluxe, Executive Club, Family, Executive Suite, Presidential): ";
        getline(cin, t.tipeKamar);
        cout << "Durasi inap (malam): ";
        cin >> t.durasiInap;

        if (t.tipeKamar == "Deluxe" || t.tipeKamar == "deluxe") {
		    if (d001) { 
                t.noKamar = "D001";
                d001 = false; 
            } else if (d002) { 
                t.noKamar = "D002"; 
                d002 = false; 
            } else if (d003) { 
                t.noKamar = "D003"; 
                d003 = false; 
            } else if (d004) { 
                t.noKamar = "D004"; 
                d004 = false; 
            } else if (d005) { 
                t.noKamar = "D005"; 
                d005 = false; 
            } else { 
                cout << "Maaf, semua kamar Deluxe penuh.\n"; 
                return; 
            }
            
        } else if (t.tipeKamar == "Executive Club" || t.tipeKamar == "Executive Club") {
		    if (e001) { 
                t.noKamar = "E001"; 
                e001 = false; 
            } else if (e002) { 
                t.noKamar = "E002"; 
                e002 = false; 
            } else if (e003) { 
                t.noKamar = "E003"; 
                e003 = false; 
            } else if (e004) { 
                t.noKamar = "E004"; 
                e004 = false; 
            } else if (e005) { 
                t.noKamar = "E005"; 
                e005 = false; 
            } else { 
                cout << "Maaf, semua kamar Executive Club penuh.\n"; 
                return; 
            }
            
		} else if (t.tipeKamar == "Family" || t.tipeKamar == "family") {
		    if (f001) { 
                t.noKamar = "F001"; 
                f001 = false; 
            } else if (f002) { 
                t.noKamar = "F002"; 
                f002 = false; 
            } else if (f003) { 
                t.noKamar = "F003"; 
                f003 = false; 
            } else if (f004) { 
                t.noKamar = "F004"; 
                f004 = false; 
            } else if (f005) { 
                t.noKamar = "F005"; 
                f005 = false; 
            } else { 
                cout << "Maaf, semua kamar Family penuh.\n"; 
                return; 
            }
            
        } else if (t.tipeKamar == "Executive Suite" || t.tipeKamar == "Executive Suite") {
		    if (es001) { 
                t.noKamar = "ES001"; 
                es001 = false; 
            } else if (es002) { 
                t.noKamar = "ES002"; 
                es002 = false; 
            } else if (es003) { 
                t.noKamar = "ES003"; 
                es003 = false; 
            } else if (es004) { 
                t.noKamar = "ES004"; 
                es004 = false; 
            } else if (es005) { 
                t.noKamar = "ES005"; 
                es005 = false; 
            } else { 
                cout << "Maaf, semua kamar Executive Suite penuh.\n"; 
                return; 
            }
            
		} else if (t.tipeKamar == "Presidential" || t.tipeKamar == "presidential") {
		    if (p001) {
                t.noKamar = "P001"; 
                p001 = false; 
            } else if (p002) { 
                t.noKamar = "P002"; 
                p002 = false; 
            } else if (p003) { 
                t.noKamar = "P003"; 
                p003 = false; 
            } else if (p004) { 
                t.noKamar = "P004"; 
                p002 = false; 
            } else if (p005) { 
                t.noKamar = "P005"; 
                p005 = false; 
            } else {
                cout << "Maaf, semua kamar Presidential penuh.\n"; return; 
            }
            
		} else {
		    cout << "Tipe kamar tidak valid.\n";
		    return;
		}
		cout << "--------------------------------------------------\n\n";


        daftarTamu.push_back(t);
        cout << "----------------------------------------\n";
        cout << "Booking Room berhasil!\n";
        cout << "----------------------------------------\n";
        cout << "Detail Booking : \n";
        cout << "Nama       : " << t.nama << endl;
        cout << "Tipe Kamar : " << t.tipeKamar << endl;
        cout << "No. Kamar  : " << t.noKamar << endl;
        cout << "----------------------------------------\n";
        system("pause");
    }

    void service() {
    	int pilservice;
	    system("cls");
	
	    if (daftarTamu.empty()) {
	        cout << "Anda harus booking kamar terlebih dahulu sebelum memilih layanan.\n";
	        system("pause");
	        return;
	    }
	
	    string nomorKTP;
	    cout << "Masukkan nomor KTP Anda: ";
	    cin.ignore();
	    getline(cin, nomorKTP);
	
	    int indeksTamu = -1;
	    for (int i = 0; i < daftarTamu.size(); i++) {
	        if (daftarTamu[i].nomorKTP == nomorKTP) {
	            indeksTamu = i;
	            break;
	        }
	    }
	
	    if (indeksTamu == -1) {
	        cout << "Tamu dengan nomor KTP tersebut tidak ditemukan.\n";
	        system("pause");
	        return;
	    }
	
	    do {
	        cout << "-------------------------------------------------\n";
	        cout << "            SERVICE & FACILITIES HOTEL\n";
	        cout << "-------------------------------------------------\n";
	        cout << "1. Restoran & Coffee Shop        200.000\n";
	        cout << "2. Spa dan Pusat Kebugaran       150.000\n";
	        cout << "3. Layanan Antar-Jemput Bandara   75.000\n";
	        cout << "4. Laundry dan Dry Cleaning       30.000\n";
	        cout << "5. Rental Mobil/Transportasi     300.000\n";
	        cout << "6. Penyewaan Sepeda / Skuter      40.000\n";
	        cout << "0. Keluar\n";
	        cout << "-------------------------------------------------\n\n";
	        cout << "Pilih Fasilitas Tambahan (1-4): ";
	        cin >> pilservice;
	
	        Layanan layanan;
	
	        if (pilservice == 1) {
	            layanan.nama = "Restoran & Coffee Shop";
	            layanan.harga = 200000;
	            daftarTamu[indeksTamu].layananTambahan.push_back(layanan);
	            cout << "Berhasil Menambahkan Fasilitas Restoran & Coffee Shop\n\n";
	            
	        } else if (pilservice == 2) {
	            layanan.nama = "Spa dan Pusat Kebugaran";
	            layanan.harga = 150000;
	            daftarTamu[indeksTamu].layananTambahan.push_back(layanan);
	            cout << "Berhasil Menambahkan Fasilitas Spa dan Pusat Kebugaran\n\n";
	            
	        } else if (pilservice == 3) {
	            layanan.nama = "Layanan Antar-Jemput Bandara";
	            layanan.harga = 75000;
	            daftarTamu[indeksTamu].layananTambahan.push_back(layanan);
	            cout << "Berhasil Menambahkan Fasilitas Layanan Antar-Jemput Bandara\n\n";
	            
	        } else if (pilservice == 4) {
	            layanan.nama = "Laundry dan Dry Cleaning";
	            layanan.harga = 30000;
	            daftarTamu[indeksTamu].layananTambahan.push_back(layanan);
	            cout << "Berhasil Menambahkan Fasilitas Laundry dan Dry Cleaning\n\n";
	            
	        } else if (pilservice == 5) {
	            layanan.nama = "Rental Mobil/Transportasi ";
	            layanan.harga = 300000;
	            daftarTamu[indeksTamu].layananTambahan.push_back(layanan);
	            cout << "Berhasil Menambahkan Fasilitas Rental Mobil/Transportasi \n\n";
	            
	        }  else if (pilservice == 6) {
	            layanan.nama = "Penyewaan Sepeda / Skuter ";
	            layanan.harga = 40000;
	            daftarTamu[indeksTamu].layananTambahan.push_back(layanan);
	            cout << "Berhasil Menambahkan Fasilitas Penyewaan Sepeda / Skuter\n\n";
	            
	        } else if (pilservice != 0) {
	            cout << "Pilihan tidak valid\n";
	        }
	
	    } while (pilservice != 0);
	
	    system("pause");	
    }

    void special() {
    	system("cls");
        int pilspecial;
        
        do {
        	
        	cout << "\n------------------------------------------------\n";
            cout << "           Special Package & Event         \n";
            cout << "------------------------------------------------\n";
            cout << "1. Tipe-tipe Ruangan Special Package & Event\n";
            cout << "2. Cek Ketersediaan Ruangan\n";
            cout << "3. Urutkan Package (dari yang Termurah)\n";
            cout << "4. Urutkan Package (dari yang Termahal)\n";
            cout << "0. Kembali ke Menu Utama\n";
            cout << "------------------------------------------------\n";
            cout << "Pilih menu (1-4): ";
            cin >> pilspecial;
            
            if (pilspecial == 1) {
            	system("cls");
				cout << "-------------------------------------------------\n";
            	cout << "            Special Package & Event\n";
            	cout << "-------------------------------------------------\n";
            	cout << "1. Amartapura Plenary Hall         200.000.000\n";
            	cout << "2. Ground Floor Meeting Room       400.000\n";
            	cout << "3. Abiyasa                         600.000\n";
            	cout << "4. Parikesit                       800.000\n";
            	cout << "5. Utari                           1.000.000\n";
            	cout << "-------------------------------------------------\n\n";
            	system("pause");
            	
			} else if (pilspecial == 2) {
				system("cls");
            	cout << "-------------------------------------------------\n";
            	cout << "            Cek Ketersediaan Ruangan\n";
            	cout << "-------------------------------------------------\n";
                cout << "1. Amartapura Plenary Hall\n";
                cout << "   - A001  : " << (a001 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - A002  : " << (a002 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - A003  : " << (a003 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "--------------------------------------------------\n";
                cout << "2. Ground Floor Meeting Room\n";
                cout << "   - G001  : " << (g001 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - G002  : " << (g002 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - G003  : " << (g003 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "--------------------------------------------------\n";
                cout << "3. Abiyasa\n";
                cout << "   - AB001  : " << (ab001 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - AB002  : " << (ab002 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - AB003  : " << (ab003 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "--------------------------------------------------\n";
                cout << "4. Perikesit\n";
                cout << "   - PK001  : " << (pk001 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - PK002  : " << (pk002 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - PK003  : " << (pk003 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "--------------------------------------------------\n";
                cout << "5. Utari\n";
                cout << "   - U001  : " << (u001 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - U002  : " << (u002 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "   - U003  : " << (u003 ? "Tersedia" : "Tidak Tersedia") << endl;
                cout << "--------------------------------------------------\n";
                system("pause");
                
            } else if (pilspecial == 3) {
	            system("cls");
	
	            vector<Ruangan> daftarRuangan;
	            Ruangan r1; 
				r1.nama = "Amartapura Plenary Hall"; 
				r1.harga = 200000000; 
				daftarRuangan.push_back(r1);
				
	            Ruangan r2; 
				r2.nama = "Ground Floor Meeting Room"; 
				r2.harga = 400000; 
				daftarRuangan.push_back(r2);
				
	            Ruangan r3; 
				r3.nama = "Abiyasa"; 
				r3.harga = 600000; 
				daftarRuangan.push_back(r3);
				
	            Ruangan r4; 
				r4.nama = "Parikesit"; 
				r4.harga = 800000; 
				daftarRuangan.push_back(r4);
				
	            Ruangan r5; 
				r5.nama = "Utari"; 
				r5.harga = 1000000; 
				daftarRuangan.push_back(r5);
	
	            for (int i = 0; i < daftarRuangan.size() - 1; ++i) {
	                for (int j = 0; j < daftarRuangan.size() - i - 1; ++j) {
	                    if (daftarRuangan[j].harga > daftarRuangan[j + 1].harga) {
	                        Ruangan temp = daftarRuangan[j];
	                        daftarRuangan[j] = daftarRuangan[j + 1];
	                        daftarRuangan[j + 1] = temp;
	                    }
	                }
	            }
	
	            cout << "-------------------------------------------------\n";
	            cout << "  Urutan Ruangan Event Berdasarkan Harga Termurah\n";
	            cout << "-------------------------------------------------\n";
	            for (int i = 0; i < daftarRuangan.size(); ++i) {
	                cout << i + 1 << ". " << daftarRuangan[i].nama << " => Rp. " << daftarRuangan[i].harga << ",-\n";
	            }
	            cout << "-------------------------------------------------\n";
	            system("pause");
	            
            
            } else if (pilspecial == 4) {
	            system("cls");
	
	            vector<Ruangan> daftarRuangan;
	            Ruangan r1; 
				r1.nama = "Amartapura Plenary Hall"; 
				r1.harga = 200000000; 
				daftarRuangan.push_back(r1);
				
	            Ruangan r2; 
				r2.nama = "Ground Floor Meeting Room"; 
				r2.harga = 400000; 
				daftarRuangan.push_back(r2);
				
	            Ruangan r3; 
				r3.nama = "Abiyasa"; 
				r3.harga = 600000; 
				daftarRuangan.push_back(r3);
				
	            Ruangan r4; 
				r4.nama = "Parikesit"; 
				r4.harga = 800000; 
				daftarRuangan.push_back(r4);
				
	            Ruangan r5; 
				r5.nama = "Utari"; 
				r5.harga = 1000000; 
				daftarRuangan.push_back(r5);
	
	            for (int i = 0; i < daftarRuangan.size() - 1; ++i) {
	                for (int j = 0; j < daftarRuangan.size() - i - 1; ++j) {
	                    if (daftarRuangan[j].harga > daftarRuangan[j + 1].harga) {
	                        Ruangan temp = daftarRuangan[j];
	                        daftarRuangan[j] = daftarRuangan[j + 1];
	                        daftarRuangan[j + 1] = temp;
	                    }
	                }
	            }
	
	            cout << "-------------------------------------------------\n";
	            cout << "  Urutan Ruangan Event Berdasarkan Harga Termahal\n";
	            cout << "-------------------------------------------------\n";
	            
	            for (int i = 0; i < daftarRuangan.size(); ++i) {
	                cout << daftarRuangan[i].nama << " => Rp. " << daftarRuangan[i].harga << ",-\n";
	            }
	            
	            cout << "-------------------------------------------------\n";
	            system("pause");
	            
            } else if (pilspecial == 0) {
                system("cls");
                return;
            }
            
            system("cls");
        } while (pilspecial !=0);
    }

    void bookingSpecial() {
        Special s;
        system("cls");
        cout << "--------------------------------------------------\n";
        cout << "           Booking Special Package & Event\n";
        cout << "--------------------------------------------------\n";
    
        cout << "\nMasukkan nama: ";
        cin.ignore();
        getline(cin, s.nama);
    
        cout << "Masukkan nomor KTP: ";
        getline(cin, s.nomorKTP);
    
    	cout << "--------------------------------------------------\n";
        cout << "           Pilih Special Package & Event\n";
        cout << "--------------------------------------------------\n";
        cout << "1. Amartapura Plenary Hall\n";
        cout << "2. Ground Floor Meeting Room\n";
        cout << "3. Abiyasa\n";
        cout << "4. Parikesit\n";
        cout << "5. Utari\n";
        cout << "--------------------------------------------------\n";
        cout << "Pilihan (1-5): ";
    
        int choice;
        cin >> choice;
        cout << "--------------------------------------------------\n";
    
        if(choice < 1 || choice > 5) {
            cout << "Pilihan tidak valid!\n";
            system("pause");
            return;
        }
        
        switch(choice) {
            case 1: 
                s.package = "Amartapura Plenary Hall";
                if(a001) {
                    cout << "\nRuangan A001 dipesan untuk Anda\n";
                    a001 = false;
                } else if(a002) {
                    cout << "\nRuangan A002 dipesan untuk Anda\n";
                    a002 = false;                 
                } else if(a003) {
                    cout << "\nRuangan A003 dipesan untuk Anda\n";
                    a003 = false;
                } else {
                    cout << "\nMaaf, semua ruangan Amartapura sudah penuh\n";
                    system("pause");
                    return;
                }
                break;
            
            case 2:
                s.package = "Ground Floor Meeting Room";
                if(g001) {
                    cout << "\nRuangan G001 dipesan untuk Anda\n";
                    g001 = false;
                } else if(g002) {
                    cout << "\nRuangan G002 dipesan untuk Anda\n";
                    g002 = false;
                } else if(g003) {
                    cout << "\nRuangan G003 dipesan untuk Anda\n";
                    g003 = false;
                } else {
                    cout << "\nMaaf, semua ruangan Meeting sudah penuh\n";
                    system("pause");
                    return;
                }
                break;
                
            case 3:
                s.package = "Abiyasa";
                if(ab001) {
                    cout << "\nRuangan AB001 dipesan untuk Anda\n";
                    ab001 = false;
                } else if(ab002) {
                    cout << "\nRuangan AB002 dipesan untuk Anda\n";
                    ab002 = false;
                } else if(ab003) {
                    cout << "\nRuangan AB003 dipesan untuk Anda\n";
                    ab003 = false;
                } else {
                    cout << "\nMaaf, semua ruangan Meeting sudah penuh\n";
                    system("pause");
                    return;
                }
                break;
                
            case 4:
                s.package = "Parikesit";
                if(p001) {
                    cout << "\nRuangan P001 dipesan untuk Anda\n";
                    p001 = false;
                } else if(p002) {
                    cout << "\nRuangan P002 dipesan untuk Anda\n";
                    p002 = false;
                } else if(p003) {
                    cout << "\nRuangan P003 dipesan untuk Anda\n";
                    p003 = false;
                } else {
                    cout << "\nMaaf, semua ruangan Meeting sudah penuh\n";
                    system("pause");
                    return;
                }
                break;
                
            case 5:
                s.package = "Utari";
                if(u001) {
                    cout << "\nRuangan U001 dipesan untuk Anda\n";
                    u001 = false;
                } else if(u002) {
                    cout << "\nRuangan U002 dipesan untuk Anda\n";
                    u002 = false;
                } else if(u003) {
                    cout << "\nRuangan U003 dipesan untuk Anda\n";
                    u003 = false;
                } else {
                    cout << "\nMaaf, semua ruangan Meeting sudah penuh\n";
                    system("pause");
                    return;
                }
                break;
                
                default:
                    cout << "Pilihan tidak valid\n";
                    system("pause");
                    return;
                    
        }
                    
        daftarSpecial.push_back(s);
    
    	cout << "\n--------------------------------------------------\n";
        cout << "Booking Special Package berhasil!\n";
        cout << "--------------------------------------------------\n";
        cout << "Detail Booking:\n";
        cout << "Nama    : " << s.nama << endl;
        cout << "Package : " << s.package << endl;
        
        cout << "--------------------------------------------------\n";
        system("pause");
    }
                
   
    void checkOut() {
	    system("cls");
	    if (daftarTamu.empty()) {
	        cout << "Tidak ada tamu yang sedang menginap.\n";
	        system("pause");
	        return;
	    }
	
	    string nomorKTP;
	    cout << "Masukkan nomor KTP untuk check out: ";
	    cin.ignore();
	    getline(cin, nomorKTP);
	
	    bool ditemukan = false;
	
	    for (size_t i = 0; i < daftarTamu.size(); ++i) {
	        Tamu& t = daftarTamu[i];
	        if (t.nomorKTP == nomorKTP) {
	            ditemukan = true;
	
	            int hargaPerMalam = 0;
	            string tipe = t.tipeKamar;
	            string kamarCheckOut = t.noKamar;
	
	            if (tipe == "Deluxe" || tipe == "deluxe") {
	            	hargaPerMalam = 800000;					
				} else if (tipe == "Executive Club" || tipe == "executive club") {
					hargaPerMalam = 1100000;
				} else if (tipe == "Family" || tipe == "family") {
					hargaPerMalam = 1700000;
				} else if (tipe == "Executive Suite" || tipe == "executive suite") {
					hargaPerMalam = 2200000;
				} else if (tipe == "Presidential" || tipe == "presidential") {
					hargaPerMalam = 3500000;
				}
	
	            int total = hargaPerMalam * t.durasiInap;
	            int diskon = 0;
	
	            if (t.durasiInap > 2) {
	                diskon = total * 0.1;
	                cout << "\nAnda mendapatkan diskon 10% untuk menginap lebih dari 2 malam!\n";
	                cout << "Diskon: Rp " << diskon << endl;
	                total -= diskon;
	            }
	
	            int totalLayanan = 0;
			    if (t.layananTambahan.size() > 0) {
			        cout << "\nLayanan Tambahan:\n";
			            for (int j = 0; j < t.layananTambahan.size(); j++) {
			                Layanan layanan = t.layananTambahan[j];
			                cout << "- " << layanan.nama << ": Rp " << layanan.harga << endl;
			                totalLayanan += layanan.harga;
			            }
			            cout << "Total biaya layanan: Rp " << totalLayanan << endl;
			            total += totalLayanan;
			    	}
	
	            cout << "\n-----------------------------------------\n";
	            cout << "       Detail Pembayaran Room\n";
	            cout << "-----------------------------------------\n";
	            cout << "Nama           : " << t.nama << endl;
	            cout << "Nomor KTP      : " << t.nomorKTP << endl;
	            cout << "Tipe Kamar     : " << t.tipeKamar << endl;
	            cout << "Nomor Kamar    : " << t.noKamar << endl;
	            cout << "Durasi Inap    : " << t.durasiInap << " malam\n";
	            cout << "Harga per Malam: Rp " << hargaPerMalam << endl;
	            
	            if (totalLayanan > 0) {
	            	cout << "Biaya Layanan  : Rp " << totalLayanan << endl;
				}
				
	            if (diskon > 0) {
	            	cout << "Diskon 10%     : Rp " << diskon << endl;
				}
				
	            cout << "Total Biaya    : Rp " << total << endl;
	            cout << "-----------------------------------------\n";
	
	            cout << "\nPilih Metode Pembayaran:\n";
	            cout << "1. Tunai\n";
	            cout << "2. Kartu Kredit\n";
	            cout << "3. Transfer Bank\n";
	            cout << "Pilihan: ";
	            int metode;
	            cin >> metode;
	
	            string bayar;
	            if (metode == 1) 
					bayar = "Tunai";
	            else if (metode == 2) 
					bayar = "Kartu Kredit";
	            else if (metode == 3) 
					bayar = "Transfer Bank";
	            else 
					bayar = "Tidak Valid";
	
	            cout << "\n+------------------------------------------------+\n";
	            cout << "|                STRUCT PEMBAYARAN               |\n";
	            cout << "+------------------------------------------------+\n";
	            cout << "| Nama           : " << t.nama << endl;
	            cout << "| Nomor KTP      : " << t.nomorKTP << endl;
	            cout << "| Tipe Kamar     : " << t.tipeKamar << endl;
	            cout << "| Nomor Kamar    : " << t.noKamar << endl;
	            cout << "| Durasi Inap    : " << t.durasiInap << " malam\n";
	            cout << "| Harga per Malam: Rp " << hargaPerMalam << endl;
	            
	            if (totalLayanan > 0)   {
	            	cout << "| Biaya Layanan  : Rp " << totalLayanan << endl;
				}
					
	            if (diskon > 0) {
	            	cout << "| Diskon 10%     : Rp " << diskon << endl;
				}
				
	            cout << "| Total Biaya    : Rp " << total << endl;
	            cout << "| Metode Bayar   : " << bayar << endl;
	            cout << "+------------------------------------------------+\n";
	            cout << "|                TERIMA KASIH                    |\n";
	            cout << "+------------------------------------------------+\n";
	
	            if (tipe == "Deluxe") {
	                if (kamarCheckOut == "D001") d001 = true;
	                else if (kamarCheckOut == "D002") d002 = true;
	                else if (kamarCheckOut == "D003") d003 = true;
	                else if (kamarCheckOut == "D004") d004 = true;
	                else if (kamarCheckOut == "D005") d005 = true;
	                
	            } else if (tipe == "Executive Club") {
	                if (kamarCheckOut == "E001") e001 = true;
	                else if (kamarCheckOut == "E002") e002 = true;
	                else if (kamarCheckOut == "E003") e003 = true;
	                else if (kamarCheckOut == "E004") e004 = true;
	                else if (kamarCheckOut == "E005") e005 = true;
	                
	            } else if (tipe == "Family") {
	                if (kamarCheckOut == "F001") f001 = true;
	                else if (kamarCheckOut == "F002") f002 = true;
	                else if (kamarCheckOut == "F003") f003 = true;
	                else if (kamarCheckOut == "F004") f004 = true;
	                else if (kamarCheckOut == "F005") f005 = true;
	                
	            } else if (tipe == "Executive Suite") {
	                if (kamarCheckOut == "ES001") es001 = true;
	                else if (kamarCheckOut == "ES002") es002 = true;
	                else if (kamarCheckOut == "ES003") es003 = true;
	                else if (kamarCheckOut == "ES004") es004 = true;
	                else if (kamarCheckOut == "ES005") es005 = true;
	                
	            } else if (tipe == "Presidential") {
	                if (kamarCheckOut == "P001") p001 = true;
	                else if (kamarCheckOut == "P002") p002 = true;
	                else if (kamarCheckOut == "P003") p003 = true;
	                else if (kamarCheckOut == "P004") p004 = true;
	                else if (kamarCheckOut == "P005") p005 = true;
	            }
	            
	            TransaksiSelesai ts;
	            
				ts.nama = t.nama;
				ts.nomorKTP = t.nomorKTP;
				ts.noKamar = t.noKamar;
				ts.tipeKamar = t.tipeKamar;
				ts.durasiInap = t.durasiInap;
				ts.total = total;
				ts.jenisTransaksi = "Room";
				ts.layananTambahan = t.layananTambahan;
				
				transaksiRoomSelesai.push_back(ts);
	
	            string noKamar = t.noKamar;
                string tipeKamar = t.tipeKamar;
                
                daftarTamu.erase(daftarTamu.begin() + i);

                cout << "\nCheck out berhasil untuk kamar " << noKamar << endl;
                
                char pilihan;
                cout << "\nApakah Anda ingin memberikan rating untuk kamar ini? (y/n): ";
                cin >> pilihan;
                
                if (tolower(pilihan) == 'y') {
                    beriRating(noKamar, tipeKamar);
                }
                
                system("pause");
                break;
	    	}
	    }
	    
	    if (!ditemukan) {
            cout << "Tamu dengan nomor KTP tersebut tidak ditemukan.\n";
            system("pause");
        }
	}

    void checkoutSpecial() {
        system("cls");
        if(daftarSpecial.empty()) {
            cout << "Tidak ada Special Package yang aktif.\n";
            system("pause");
            return;
        }
    
        string nomorKTP;
        cout << "Masukkan nomor KTP untuk check-out Special Package: ";
        cin.ignore();
        getline(cin, nomorKTP);

        bool ditemukan = false;
        for(size_t i = 0; i < daftarSpecial.size(); i++) {
            if(daftarSpecial[i].nomorKTP == nomorKTP) {
                Special s = daftarSpecial[i];
                string package = daftarSpecial[i].package;
                
	            if(s.nomorKTP == nomorKTP) {
	                int hargaPackage = 0;
	                if(s.package == "Amartapura Plenary Hall") 
						hargaPackage = 200000000;
	                else if(s.package == "Ground Floor Meeting Room") 
						hargaPackage = 400000;
	                else if(s.package == "Abiyasa") 
						hargaPackage = 600000;
	                else if(s.package == "Parikesit") 
						hargaPackage = 800000;
	                else if(s.package == "Utari") 
						hargaPackage = 1000000;
	
					cout << "\n-----------------------------------------\n";
	                cout << "  Detail Pembayaran Special Package\n";
	                cout << "-----------------------------------------\n";
	                cout << "Nama          : " << s.nama << endl;
	                cout << "Nomor KTP     : " << s.nomorKTP << endl;
	                cout << "Package       : " << s.package << endl;
	                cout << "Total Biaya   : Rp " << hargaPackage << endl;
	                cout << "-----------------------------------------\n";
	                
	                cout << "\nPilih Metode Pembayaran :\n";
	                cout << "1. Tunai\n";
	                cout << "2. Kartu Kredit\n";
	                cout << "3. Transfer Bank\n";
	                cout << "Pilihan : ";
	                
	                int metode;
	                cin >> metode;
	                
	                string bayar;
	                if(metode == 1) {
	                    bayar = "Tunai";
	                } else if(metode == 2) {
	                    bayar = "Kartu Kredit";
	                } else if(metode == 3) {
	                    bayar = "Transfer Bank";
	                } else {
	                    cout << "Metode pembayaran tidak valid\n";
	                }
	                
	                cout << "\n+-------------------------------------------------+\n";
	                cout << "|                STRUCT PEMBAYARAN                |\n";
	                cout << "+-------------------------------------------------+\n";
	                cout << "| Nama              : " << s.nama << endl;
	                cout << "| Nomor KTP         : " << s.nomorKTP << endl;
	                cout << "| Package           : " << s.package << endl;
	                cout << "| Total Biaya       : Rp " << hargaPackage << endl;
	                cout << "| Metode Pembayaran : " << bayar << endl;
	                cout << "+-------------------------------------------------+\n";
	                cout << "|                TERIMA KASIH                     |\n";
	                cout << "+-------------------------------------------------+\n";
            
	            if(package == "Amartapura Plenary Hall") {
	                if(!a001) a001 = true;
	                else if(!a002) a002 = true;
	                else if(!a003) a003 = true;
	                
	            } else if(package == "Ground Floor Meeting Room") {
	                if(!a001) a001 = true;
	                else if(!a002) a002 = true;
	                else if(!a003) a003 = true;
	                
	            } else if(package == "Abiyasa") {
	                if(!a001) a001 = true;
	                else if(!a002) a002 = true;
	                else if(!a003) a003 = true;
	                
	            } else if(package == "Parikesit") {
	                if(!a001) a001 = true;
	                else if(!a002) a002 = true;
	                else if(!a003) a003 = true;
	                
	            } else if(package == "Utari") {
	                if(!a001) a001 = true;
	                else if(!a002) a002 = true;
	                else if(!a003) a003 = true;
	            }
	            
	            SpecialTransaksiSelesai sts;
	            
				sts.nama = s.nama;
				sts.nomorKTP = s.nomorKTP;
				sts.package = s.package;
				sts.total = hargaPackage;
				
				transaksiSpecialSelesai.push_back(sts);
	            
	            daftarSpecial.erase(daftarSpecial.begin() + i);
	            cout << "\nTerima Kasih, Check-out Special Package berhasil!\n";
	            ditemukan = true;
	            system("pause");
	            break;
	        }
	    }
	    
	    if(!ditemukan) {
	        cout << "Nomor KTP tidak ditemukan.\n";
	    }
	}
}

    void menu() {
        int pilih;
        do {
        	system("cls");
            cout << "\n*************************************************************************************" << endl;
            cout << "*      \\\\////\\\\\\\\//                                               \\\\////\\\\\\\\//     *" << endl;
            cout << "*      //\\\\\\\\////\\\\    \\\\//    \\\\//     //\\\\     \\\\//    \\\\//     //\\\\\\\\////\\\\     *" << endl;
            cout << "*      \\\\////\\\\\\\\//    //\\\\    //\\\\     \\\\//     //\\\\    //\\\\     \\\\////\\\\\\\\//     *" << endl;
            cout << "*      //\\\\\\\\////\\\\    \\\\//    \\\\//     //\\\\     \\\\//    \\\\//     //\\\\\\\\////\\\\     *" << endl;
            cout << "*      \\\\////\\\\\\\\//    //\\\\    //\\\\     \\\\//     //\\\\    //\\\\     \\\\////\\\\\\\\//     *" << endl;
            cout << "*      //\\\\\\\\////\\\\                                               //\\\\\\\\////\\\\     *" << endl;
            cout << "*      \\\\////\\\\\\\\//                                               \\\\////\\\\\\\\//     *" << endl;
            cout << "*      //\\\\\\\\////\\\\                                               //\\\\\\\\////\\\\     *" << endl;
    
            cout << "************************************************************************************" << endl;
            cout << "@      \\\\//    \\\\//                                               \\\\//    \\\\//     @" << endl;
            cout << "@      //\\\\    //\\\\   ~~~@  H O T E L   T H E   A L A N A  @~~~   //\\\\    //\\\\     @" << endl;
            cout << "@      \\\\//    \\\\//                    BY ASTON                   \\\\//    \\\\//     @" << endl;
            cout << "@      //\\\\    //\\\\                                               //\\\\    //\\\\     @" << endl;
            cout << "====================================================================================" << endl;
            cout << "1. Hotel Information" << endl;
            cout << "2. View Room" << endl;
            cout << "3. Booking Room" << endl;
            cout << "4. Extra Service & Facilities (optional)" << endl;
            cout << "5. View Special Package & Event Room" << endl;
            cout << "6. Booking Special Package & Event Room" << endl;
            cout << "7. Check Out & Pay Room" << endl;
            cout << "8. Check Out & Pay Special Package" << endl;
            cout << "0. Exit" << endl;
            cout << "====================================================================================" << endl;
            cout << "Pilih menu (1-8): ";
            cin >> pilih;

            switch (pilih) {
            case 1:
                informasi();
                break;
            case 2:
                room();
                break;
            case 3:
                bookingRoom();
                break;
            case 4:
                service();
                break;
            case 5:
                special();
                break;
            case 6:
            	bookingSpecial();
            	break;
            case 7:
                checkOut();
                break;
            case 8:
                checkoutSpecial();
                break;
            default:
                break;
            }
        } while (pilih != 0);
	}
    
};

int main() {
    Hotel h;

    h.login();

    return 0;
}

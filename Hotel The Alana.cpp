#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Tamu {
    string nama;
    string nomorKTP; 
    string noKamar;
    string tipeKamar;
    int durasiInap;
    int total;
};

class Hotel {
private:
    vector<Tamu> daftarTamu;
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
    
public:
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
        int pilRoom;

        do {
            
            cout << "\n------------------------------------------------\n";
            cout << "           Room Hotel The Alana         \n";
            cout << "------------------------------------------------\n";
            cout << "1. Tipe-tipe Kamar dan Fasilitasnya\n";
            cout << "2. Cek Ketersediaan Kamar\n";
            cout << "0. Kembali ke Menu Utama\n";
            cout << "------------------------------------------------\n";
            cout << "Pilih menu : ";
            cin >> pilRoom;
            
            if (pilRoom == 1) {
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
                
            } else if (pilRoom == 2) {
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

            } else if (pilRoom == 0) {
            	system("cls");
            	return;
			}
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


        daftarTamu.push_back(t);
        cout << "Booking berhasil. Kamar Anda: " << t.noKamar << endl;
        cout << "--------------------------------------------------\n";
        system("pause");
    }

    void service() {
    	system("cls");
        cout << "-------------------------------------------------\n";
        cout << "            SERVICE & FACILITIES HOTEL\n";
        cout << "-------------------------------------------------\n";
        cout << "- Kolam Renang Outdoor\n";
        cout << "- Restoran & Coffee Shop\n";
        cout << "- Spa dan Pusat Kebugaran\n";
        cout << "- Layanan Kamar 24 Jam\n";
        cout << "- Ruang Pertemuan / Ballroom\n";
        cout << "- Parkir Luas dan Gratis\n";
        cout << "- Akses Wi-Fi Gratis di Seluruh Area Hotel\n";
        cout << "- Layanan Antar-Jemput Bandara (by request)\n";
        cout << "- Resepsionis 24 Jam\n";
        cout << "- Laundry dan Dry Cleaning\n";
        cout << "-------------------------------------------------\n\n";
        system("pause");
    }

    void pembayaran() {
    	system("cls");
        if (daftarTamu.empty()) {
            cout << "Tidak ada tamu yang sedang menginap.\n";
            return;
        }

        string nomorKTP;
        cout << "Masukkan nomor KTP untuk cek pembayaran: ";
        cin.ignore();
        getline(cin, nomorKTP);

        bool ditemukan = false;
		for (size_t i = 0; i < daftarTamu.size(); i++) {
        Tamu t = daftarTamu[i]; 
            if (t.nomorKTP == nomorKTP) {
                int hargaPerMalam = 0;
                if (t.tipeKamar == "Deluxe" || t.tipeKamar == "deluxe") hargaPerMalam = 800000;
                else if (t.tipeKamar == "Executive Club" || t.tipeKamar == "Executive Club") hargaPerMalam = 1100000;
                else if (t.tipeKamar == "Family" || t.tipeKamar == "family") hargaPerMalam = 1700000;
                else if (t.tipeKamar == "Executive Suite" || t.tipeKamar == "Executive Suite") hargaPerMalam = 2200000;
                else if (t.tipeKamar == "Presidential" || t.tipeKamar == "presidential") hargaPerMalam = 3500000;

                int total = hargaPerMalam * t.durasiInap;

                cout << "\nDetail Pembayaran\n";
                cout << "------------------------\n";
                cout << "Nama          : " << t.nama << endl;
                cout << "Nomor KTP     : " << t.nomorKTP << endl;
                cout << "Tipe Kamar    : " << t.tipeKamar << endl;
                cout << "Nomor Kamar   : " << t.noKamar << endl;
                cout << "Durasi Inap   : " << t.durasiInap << " malam\n";
                cout << "Harga per Malam: Rp " << hargaPerMalam << endl;
                cout << "Total Biaya   : Rp " << total << endl;
                cout << "------------------------\n";
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan) {
            cout << "Nomor KTP tidak ditemukan.\n";
        }
        system("pause");
    }

    void checkOut() {
    	system("cls");
        if (daftarTamu.empty()) {
            cout << "Tidak ada tamu yang sedang menginap.\n";
            return;
        }
        string nomorKTP, kamarCheckOut;
        cout << "Masukkan nomor KTP untuk check out: ";
        cin.ignore();
        getline(cin, nomorKTP);

        bool ditemukan = false;
        for (size_t i = 0; i < daftarTamu.size(); ++i) {
            if (daftarTamu[i].nomorKTP == nomorKTP) {
                kamarCheckOut = daftarTamu[i].noKamar;
                string tipe = daftarTamu[i].tipeKamar;
                
                // Kembalikan status kamar jadi tersedia
                if (tipe == "Deluxe" || tipe == "deluxe") {
                    if (kamarCheckOut == "D001") {
                        d001 = true;
                    } else if (kamarCheckOut == "D002") {
                        d002 = true;
                    } else if (kamarCheckOut == "D003") {
                        d003 = true;
                    } else if (kamarCheckOut == "D004") {
                        d004 = true;
                    } else if (kamarCheckOut == "D005") {
                        d005 = true;
                    } 
                if (tipe == "Executive Club" || tipe == "Executive Club") {
                    if (kamarCheckOut == "E001") {
                        e001 = true;
                    } else if (kamarCheckOut == "E002") {
                        e002 = true;
                    } else if (kamarCheckOut == "E003") {
                        e003 = true;
                    } else if (kamarCheckOut == "E004") {
                        e004 = true;
                    } else if (kamarCheckOut == "E005") {
                        e005 = true;
                    } 
                } else if (tipe == "Family" || tipe == "family") {
                    if (kamarCheckOut == "F001") {
                        f001 = true;
                    } else if (kamarCheckOut == "F002") {
                        f002 = true;
                    } else if (kamarCheckOut == "F003") {
                        f003 = true;
                    } else if (kamarCheckOut == "F004") {
                        f004 = true;
                    } else if (kamarCheckOut == "F005") {
                        f005 = true;
                    }
                } else if (tipe == "Executive Suits" || tipe == "Executive Suits") {
                    if (kamarCheckOut == "ES001") {
                        es001 = true;
                    } else if (kamarCheckOut == "ES002") {
                        es002 = true;
                    } else if (kamarCheckOut == "ES003") {
                        es003 = true;
                    } else if (kamarCheckOut == "ES004") {
                        es004 = true;
                    } else if (kamarCheckOut == "ES005") {
                        es005 = true;
                    } 
                } else if (tipe == "Presidential" || tipe == "presidential") {
                    if (kamarCheckOut == "P001") {
                        p001 = true;
                    } else if (kamarCheckOut == "P002") {
                        p002 = true;
                    } else if (kamarCheckOut == "P003") {
                        p003 = true;
                    } else if (kamarCheckOut == "P004") {
                        p004 = true;
                    } else if (kamarCheckOut == "P005") {
                        p005 = true;
                    } 
                }
                
                daftarTamu.erase(daftarTamu.begin() + i);
                cout << "Check out berhasil untuk kamar " << kamarCheckOut << ". Terima kasih telah menginap.\n";
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan) {
            cout << "Nomor KTP tidak ditemukan.\n";
        }
    	}
    	system("pause");
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
            cout << "@      \\\\//    \\\\//                                               \\\\//    \\\\//    @" << endl;
            cout << "@      //\\\\    //\\\\   ~~~@  H O T E L   T H E   A L A N A  @~~~   //\\\\    //\\\\    @" << endl;
            cout << "@      \\\\//    \\\\//                    BY ASTON                   \\\\//    \\\\//    @" << endl;
            cout << "@      //\\\\    //\\\\                                               //\\\\    //\\\\    @" << endl;
            cout << "====================================================================================" << endl;
            cout << "1. Informasi Hotel" << endl;
            cout << "2. Room" << endl;
            cout << "3. Booking Room" << endl;
            cout << "4. Service & Facilities" << endl;
            cout << "5. Struct Pembayaran" << endl;
            cout << "6. Check Out" << endl;
            cout << "0. Exit" << endl;
            cout << "====================================================================================" << endl;
            cout << "Pilih menu: ";
            cin >> pilih;

            switch (pilih)
            {
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
                pembayaran();
                break;
            case 6:
                checkOut();
                break;
            default:
                break;
            }
        } while (pilih != 0);
	}
    
};

int main() {
    Hotel h;

    h.menu();

    return 0;
}

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
    bool d001 = true, d002 = true, d003 = true;
    bool f001 = true, f002 = true, f003 = true;
    bool p001 = true, p002 = true, p003 = true;
    
public:
    void informasi() {
        cout << "\n------------------------------------------------\n";
        cout << "           Informasi Hotel The Alana         \n";
        cout << "------------------------------------------------\n";
        cout << "Telephone  : +62274888800\n";
        cout << "Website    : www.alanahotels.com\n";
        cout << "Email      : yogyakartainfo@alanahotels.com\n";
        cout << "Lokasi     : Jalan Palagan Tentara Pelajar KM 7\n";
        cout << "             Sleman, Yogyakarta 55581, Indonesia\n";
        cout << "------------------------------------------------\n";
    }

    void room() {
        int pilRoom;
        cout << "\n------------------------------------------------\n";
        cout << "           Room Hotel The Alana         \n";
        cout << "------------------------------------------------\n";
        cout << "1. Tipe-tipe Kamar dan Fasilitasnya\n";
        cout << "2. Cek Ketersediaan Kamar\n";
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
            cout << "2. Family Room     	 -     	 Rp. 1.700.000,-\n";
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
            cout << "3. Presidential Suite     	 -     	 Rp. 3.500.000,-\n";
            cout << "   Ukuran Kamar : 128 meter persegi\n";
            cout << "   Special Benefits :\n";
            cout << "   - City View                   - Jacuzzi\n";
            cout << "   - Akses Executive Lounge\n";
            cout << "   Fasilitas :\n";
            cout << "   - King Bed                    - Tea / Coffee Maker\n"; 
            cout << "   - Shower                      - Refrigerator\n";
            cout << "   - Minibar                     - Toiletries\n";
            cout << "   - Bathrobes                   - Hair Dryer\n";
            cout << "   - Iron & Ironing Board\n";
            cout << "   International TV Channels, Wi-Fi, Writing Desk, Dining Area, Extra Bed Available, Smoking Room, Non-Smoking Room, In-Room Safe\n";
            cout << "-------------------------------------------------------\n";

        } else if (pilRoom == 2) {
            cout << "--------------------------------------------------\n";
            cout << "       Cek Ketersediaan Kamar\n";
            cout << "--------------------------------------------------\n";
            cout << "1. Deluxe Room\n";
            cout << "   - D001  : " << (d001 ? "Tersedia" : "Tidak Tersedia") << endl;
            cout << "   - D002  : " << (d002 ? "Tersedia" : "Tidak Tersedia") << endl;
            cout << "   - D003  : " << (d003 ? "Tersedia" : "Tidak Tersedia") << endl;
            cout << "--------------------------------------------------\n";
            cout << "2. Family Room\n";
            cout << "   - F001  : " << (f001 ? "Tersedia" : "Tidak Tersedia") << endl;
            cout << "   - F002  : " << (f002 ? "Tersedia" : "Tidak Tersedia") << endl;
            cout << "   - F003  : " << (f003 ? "Tersedia" : "Tidak Tersedia") << endl;
            cout << "--------------------------------------------------\n";
            cout << "3. Presidential Suite\n";
            cout << "   - P001  : " << (p001 ? "Tersedia" : "Tidak Tersedia") << endl;
            cout << "   - P002  : " << (p002 ? "Tersedia" : "Tidak Tersedia") << endl;
            cout << "   - P003  : " << (p003 ? "Tersedia" : "Tidak Tersedia") << endl;
            cout << "--------------------------------------------------\n";

        } else {
            cout << "\nPilihan Anda Tidak Ada !\n";
        }
        
    }

    void bookingRoom() {
        Tamu t;
        cout << "Masukkan nama: ";
        cin.ignore();
        getline(cin, t.nama);
        cout << "Masukkan nomor KTP: ";
        getline(cin, t.nomorKTP);
        cout << "Pilih tipe kamar (Deluxe, Family, Presidential): ";
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
            } else { 
                cout << "Maaf, semua kamar Deluxe penuh.\n"; 
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
            } else { 
                cout << "Maaf, semua kamar Family penuh.\n"; 
                return; 
            }
		} else if (t.tipeKamar == "Presidential" || t.tipeKamar == "presidential") {
		    if (p001) {
                t.noKamar = "P001"; 
                p001 = false; }
		    else if (p002) { 
                t.noKamar = "P002"; 
                p002 = false; }
		    else if (p003) { 
                t.noKamar = "P003"; 
                p003 = false; }
		    else { cout << "Maaf, semua kamar Presidential penuh.\n"; return; }
		} else {
		    cout << "Tipe kamar tidak valid.\n";
		    return;
		}


        daftarTamu.push_back(t);
        cout << "Booking berhasil. Kamar Anda: " << t.noKamar << endl;

    }

    void service() {
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
    }

    void pembayaran() {
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
                else if (t.tipeKamar == "Family" || t.tipeKamar == "family") hargaPerMalam = 1700000;
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
    }

    void checkOut() {
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
                    if (kamarCheckOut == "D001") d001 = true;
                    else if (kamarCheckOut == "D002") d002 = true;
                    else if (kamarCheckOut == "D003") d003 = true;
                } else if (tipe == "Family" || tipe == "family") {
                    if (kamarCheckOut == "F001") f001 = true;
                    else if (kamarCheckOut == "F002") f002 = true;
                    else if (kamarCheckOut == "F003") f003 = true;
                } else if (tipe == "Presidential" || tipe == "presidential") {
                    if (kamarCheckOut == "P001") p001 = true;
                    else if (kamarCheckOut == "P002") p002 = true;
                    else if (kamarCheckOut == "P003") p003 = true;
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

    void menu() {
        int pilih;
        do {
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
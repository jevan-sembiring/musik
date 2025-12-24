#include "musik.h"
#include <iostream>
using namespace std;

int readInt(){
    int x;
    cin >> x;
    return x;
}

string readString(){
    string s;
    cin >> s;    
    return s;
}

int main(){
    GenreList G;
    ListPlaylist PL;
    ListFavorite F;
    PlayQueue Q;
    HistoryStack H;
    PermanentHistory PH;
    
    createGenreList(G);    
    createPlaylistList(PL);
    createFavorite(F);
    createQueue(Q);
    createStack(H);
    createPermanentHistory(PH);

    adrPlaylist activePL = nullptr;
    bool playingFromQueue = false;
    int running = 1;

    insertSongToGenre(G, {0, "We Hug Now", "Sydney Rose", "Pop", "Single", 2025, 210});
    insertSongToGenre(G, {0, "Birds of a Feather", "Billie Eilish", "Pop", "Album1", 2025, 195});
    insertSongToGenre(G, {0, "Down Bad", "Taylor Swift", "Pop", "Album2", 2025, 200});
    insertSongToGenre(G, {0, "Slow It Down", "Benson Boone", "Pop", "EP1", 2025, 205});
    insertSongToGenre(G, {0, "Illusion", "Dua Lipa", "Pop", "Album3", 2025, 198});
    insertSongToGenre(G, {0, "APT.", "BLACKPINK & Bruno Mars", "Pop", "Single", 2025, 220});
    insertSongToGenre(G, {0, "Man I Need", "Olivia Dean", "Pop", "Single", 2025, 215});
    insertSongToGenre(G, {0, "Sailor Song", "Gigi Perez", "Pop", "Single", 2025, 190});
    insertSongToGenre(G, {0, "Azul", "J Balvin", "Pop", "Album4", 2025, 200});
    insertSongToGenre(G, {0, "Hold My Hand", "Jess Glynne", "Pop", "Album5", 2025, 202});
    insertSongToGenre(G, {0, "Rock That Body", "Black Eyed Peas", "Pop", "Album6", 2025, 210});
    insertSongToGenre(G, {0, "Good Luck, Babe!", "Chappell Roan", "Pop", "Single", 2025, 208});
    insertSongToGenre(G, {0, "Party 4 U", "Charli XCX", "Pop", "Album7", 2025, 215});
    insertSongToGenre(G, {0, "Ordinary", "Alex Warren", "Hip-Hop", "Single", 2025, 180});
    insertSongToGenre(G, {0, "Not Like Us", "Kendrick Lamar", "Hip-Hop", "Album1", 2025, 200});
    insertSongToGenre(G, {0, "My World", "Chuckyy", "Hip-Hop", "Single", 2025, 195});
    insertSongToGenre(G, {0, "Tap Twice", "KESHA", "Hip-Hop", "Single", 2025, 198});
    insertSongToGenre(G, {0, "Show Me Love", "WizTheMc & Bees", "Hip-Hop", "Single", 2025, 205});
    insertSongToGenre(G, {0, "Dame Un Grrr", "Fantomel x Kate Linn", "Hip-Hop", "Single", 2025, 207});
    insertSongToGenre(G, {0, "Azul (Remix)", "J Balvin", "Hip-Hop", "Album4", 2025, 202});
    insertSongToGenre(G, {0, "Stecu Stecu", "Faris Adam", "Hip-Hop", "Single", 2025, 190});
    insertSongToGenre(G, {0, "Sailor Song (Hip-Hop Remix)", "Gigi Perez", "Hip-Hop", "Single", 2025, 192});
    insertSongToGenre(G, {0, "Yum Yum Bounce", "Trippy Tofu ft. Biaza", "Hip-Hop", "Single", 2025, 200});
    insertSongToGenre(G, {0, "Rock That Body (Rap Mix)", "Black Eyed Peas", "Hip-Hop", "Album6", 2025, 210});
    insertSongToGenre(G, {0, "Ordinary (Remix)", "Alex Warren", "Hip-Hop", "Single", 2025, 180});
    insertSongToGenre(G, {0, "Down Bad (Rap Feature)", "Taylor Swift", "Hip-Hop", "Album2", 2025, 200});
    insertSongToGenre(G, {0, "Folded", "Kehlani", "R&B", "Album1", 2025, 210});
    insertSongToGenre(G, {0, "Messy", "Lola Young", "R&B", "Single", 2025, 200});
    insertSongToGenre(G, {0, "Anxiety", "Doechii", "R&B", "Single", 2025, 195});
    insertSongToGenre(G, {0, "Slow It Down (R&B Remix)", "Benson Boone", "R&B", "EP1", 2025, 205});
    insertSongToGenre(G, {0, "We Hug Now (Acoustic R&B)", "Sydney Rose", "R&B", "Single", 2025, 210});
    insertSongToGenre(G, {0, "Man I Need (Soulful)", "Olivia Dean", "R&B", "Single", 2025, 215});
    insertSongToGenre(G, {0, "Good Luck, Babe! (R&B)", "Chappell Roan", "R&B", "Single", 2025, 208});
    insertSongToGenre(G, {0, "Birds of a Feather (Soft R&B)", "Billie Eilish", "R&B", "Album1", 2025, 195});
    insertSongToGenre(G, {0, "Show Me Love (Urban)", "WizTheMc & Bees", "R&B", "Single", 2025, 205});
    insertSongToGenre(G, {0, "Hold My Hand (R&B)", "Jess Glynne", "R&B", "Album5", 2025, 202});
    insertSongToGenre(G, {0, "Messy (Acoustic)", "Lola Young", "R&B", "Single", 2025, 200});
    insertSongToGenre(G, {0, "Party 4 U (R&B)", "Charli XCX", "R&B", "Album7", 2025, 215});
    insertSongToGenre(G, {0, "Tap Twice (Dance)", "KESHA", "Dance", "Single", 2025, 198});
    insertSongToGenre(G, {0, "Yum Yum Bounce (Dance)", "Trippy Tofu ft. Biaza", "Dance", "Single", 2025, 200});
    insertSongToGenre(G, {0, "Azul (Dance Remix)", "J Balvin", "Dance", "Album4", 2025, 202});
    insertSongToGenre(G, {0, "Rock That Body (Dance Mix)", "Black Eyed Peas", "Dance", "Album6", 2025, 210});
    insertSongToGenre(G, {0, "Party 4 U (Electronica)", "Charli XCX", "Dance", "Album7", 2025, 215});
    insertSongToGenre(G, {0, "Ordinary (Dance)", "Alex Warren", "Dance", "Single", 2025, 180});
    insertSongToGenre(G, {0, "APT. (Dance Pop)", "BLACKPINK & Bruno Mars", "Dance", "Single", 2025, 220});
    insertSongToGenre(G, {0, "Illusion (Dance)", "Dua Lipa", "Dance", "Album3", 2025, 198});
    insertSongToGenre(G, {0, "Sailor Song (Dance Edit)", "Gigi Perez", "Dance", "Single", 2025, 190});
    insertSongToGenre(G, {0, "Birds of a Feather (Upbeat)", "Billie Eilish", "Dance", "Album1", 2025, 195});
    insertSongToGenre(G, {0, "Down Bad (Club Mix)", "Taylor Swift", "Dance", "Album2", 2025, 200});
    insertSongToGenre(G, {0, "Messy (Dance Remix)", "Lola Young", "Dance", "Single", 2025, 200});
   

    while(running == 1){
        cout << endl;
        cout << "===|| MusikKuh by EL CUMLAUDE ||===" << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih : ";

        int menu = readInt();
        if(menu == 1){
            int adminRun = 1;

            while(adminRun == 1){
                cout << endl;
                cout << "---| ADMIN MENU |---" << endl;
                cout << "1. Tambah lagu" << endl;
                cout << "2. Lihat library" << endl;
                cout << "3. Hapus lagu" << endl;
                cout << "4. Update Lagu" << endl;
                cout << "5. Kembali" << endl;
                cout << "Pilih : ";

                int pilih = readInt();

                if(pilih == 1){
                    infoSong S;

                    cout << "Judul : ";
                    S.title = readString();
                    cout << "Artis : ";
                    S.artist = readString();
                    cout << "Genre : ";
                    S.genre = readString();
                    cout << "Album : ";
                    S.album = readString();
                    cout << "Tahun : ";
                    S.year = readInt();
                    cout << "Durasi : ";
                    S.duration = readInt();

                    insertSongToGenre(G, S);

                } else if(pilih == 2){
                    printLibraryByGenre(G);

                } else if(pilih == 3){
                    cout << "Masukkan ID Lagu yang ingin dihapus : ";
                    int id = readInt();
                    deleteSongByID(G, id);

                } else if(pilih == 4){
                    cout << "Masukkan ID lagu yang ingin diupdate : ";
                    int id;
                    cin >> id;
                    adrSong s = findSongByID_AllGenres(G, id);
                    if(s == nullptr){
                        cout << "Lagu tidak ditemukan" << endl;
                    } else {
                        updateSongInfo(s);
                    }
                } else if(pilih == 5){
                    adminRun = 0;

                } else {
                    cout << "Pilihan tidak valid" << endl;
                }
            }

        } else if(menu == 2){
            int userRun = 1;
            adrSong curr = nullptr;

            while(userRun == 1){
                cout << endl;
                cout << "---| USER MENU |---" << endl;
                cout << "1. Cari lagu" << endl;
                cout << "2. Play" << endl;
                cout << "3. Stop" << endl;
                cout << "4. Next" << endl;
                cout << "5. Prev" << endl;
                cout << "6. Playlist" << endl;
                cout << "7. Favorite" << endl;
                cout << "8. Queue" << endl;
                cout << "9. History" << endl;
                cout << "10. Lihat Library" << endl;
                cout << "11. Kembali" << endl;
                cout << "Pilih : ";

                int pilih = readInt();

                if(pilih == 1){
                    cout << "Judul : ";
                    string t = readString();
                    cout << "Artis : ";
                    string a = readString();

                    adrSong s = findSongByTitleArtist(G, t, a);
                    if(s == nullptr){
                        cout << "Tidak ditemukan" << endl;
                    } else {
                        playSong(s);
                        pushStack(H, s);
                        pushPermanentHistory(PH, s);
                        curr = s;
                    }

                } else if(pilih == 2){
                    cout << "ID : ";
                    int id = readInt();

                    adrSong s = nullptr;
                    adrGenre g = G.first;

                    while(g != nullptr && s == nullptr){
                        s = findSongByID(g->songs, id);
                        g = g->nextGenre;
                    }

                    if(s != nullptr){
                        playSong(s);
                        pushStack(H, s);
                        pushPermanentHistory(PH, s);
                        curr = s;
                        playingFromQueue = false;
                    } else {
                        cout << "Tidak ditemukan" << endl;
                    }

                } else if(pilih == 3){
                    stopSong();
                    curr = nullptr;

                } else if(pilih == 4){
                    if(curr == nullptr && Q.front != nullptr){
                        curr = dequeue(Q);
                        playSong(curr);
                        pushStack(H, curr);
                        pushPermanentHistory(PH, curr);
                        playingFromQueue = true;
                    }
                    else if(playingFromQueue && Q.front != nullptr){
                        curr = dequeue(Q);
                        playSong(curr);
                        pushStack(H, curr);
                        pushPermanentHistory(PH, curr);
                    }
                    else if(curr != nullptr){
                        curr = nextSongByGenreOrder(G, curr);
                        playSong(curr);
                        pushStack(H, curr);
                        pushPermanentHistory(PH, curr);
                        playingFromQueue = false;
                    }
                    else {
                        cout << "Tidak ada lagu untuk diputar\n";
                    }

                } else if(pilih == 5){
                    if(curr == nullptr){
                        cout << "Tidak ada lagu yang sedang dimainkan" << endl;
                    } else {
                        popStack(H);
                        adrSong prev = popStack(H);
                        if(prev == nullptr){
                            cout << "Tidak ada lagu sebelumnya" << endl;
                        } else {
                            curr = prev;
                            playSong(curr);
                            pushStack(H, curr);
                        }
                    }

                } else if(pilih == 6){
                    int playRun = 1;

                    while(playRun == 1){
                        cout << endl;
                        cout << "-- Menu Playlist --" << endl;
                        cout << "1. Buat Playlist" << endl;
                        cout << "2. Pilih Playlist" << endl;
                        cout << "3. Tambah Lagu" << endl;
                        cout << "4. Lihat Playlist" << endl;
                        cout << "5. Kembali" << endl;
                        cout << "Pilih : ";

                        int pp = readInt();

                        if(pp == 1){
                            cout << "Nama playlist : ";
                            string nm = readString();
                            insertPlaylistLast(PL, nm);

                        } else if(pp == 2){
                            cout << "Nama playlist : ";
                            string nm = readString();
                            activePL = findPlaylist(PL, nm);

                            if(activePL == nullptr){
                                cout << "Tidak ditemukan" << endl;
                            } else {
                                cout << "Dipilih : " << nm << endl;
                            }

                        } else if(pp == 3){
                            if(activePL == nullptr){
                                cout << "Belum pilih playlist." << endl;
                            } else {
                                cout << "ID lagu : ";
                                int id = readInt();

                                adrSong s = nullptr;
                                adrGenre g = G.first;

                                while(g != nullptr && s == nullptr){
                                    s = findSongByID(g->songs, id);
                                    g = g->nextGenre;
                                }

                                if(s != nullptr){
                                    addSongToPlaylist(activePL, s);
                                } else {
                                    cout << "Tidak ditemukan" << endl;
                                }
                            }

                        } else if(pp == 4){
                            if(activePL != nullptr){
                                printPlaylistContent(activePL);
                            } else {
                                cout << "Belum memilih playlist." << endl;
                            }

                        } else if(pp == 5){
                            playRun = 0;

                        } else {
                            cout << "Pilihan tidak valid" << endl;
                        }
                    }

                } else if(pilih == 7){
                    cout << "ID : ";
                    int id = readInt();

                    adrSong s = nullptr;
                    adrGenre g = G.first;

                    while(g != nullptr && s == nullptr){
                        s = findSongByID(g->songs, id);
                        g = g->nextGenre;
                    }

                    if(s != nullptr){
                        insertLastFavorite(F, s);
                    }

                } else if(pilih == 8){

                    int qRun = 1;

                    while(qRun){
                        cout << "\n-- MENU QUEUE --\n";
                        cout << "1. Tambah lagu ke Queue\n";
                        cout << "2. Hapus lagu dari Queue\n";
                        cout << "3. Lihat Queue\n";
                        cout << "4. Kembali\n";
                        cout << "Pilih : ";
                        int q = readInt();
                        if(q == 1){
                            cout << "ID : ";
                            int id = readInt();
                            adrSong s = findSongByID_AllGenres(G, id);
                            if(s != nullptr){
                                enqueue(Q, s);
                            }
                        } else if(q == 2){
                            adrSong s = dequeue(Q);
                            if(s != nullptr){
                                cout << "Dihapus dari queue: "
                                << s->info.title << endl;
                            } else {
                                cout << "Queue kosong\n";
                            }
                        } else if(q == 3){
                            printQueue(Q);
                        } else if(q == 4){
                            qRun = 0;
                        }    
                    }

                } else if(pilih == 9){
                    printPermanentHistory(PH);

                } else if(pilih == 10){
                    printLibraryByGenre(G);

                } else if(pilih == 11){
                    userRun = 0;
                } else {
                    cout << "Pilihan tidak valid" << endl;
                }
            }

        } else if(menu == 3){
            cout << "Terima kasih telah menggunakan MusikKuh by EL CUMLAUDE ;)" << endl;
            running = 0;
        } else {
            cout << "Pilihan tidak valid" << endl;
        }
    }
}
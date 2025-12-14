#include "musik.h"
#include <iostream>
using namespace std;

int autoID = 1;

void createListSong(ListSong &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrSong allocateSong(infoSong x){
    adrSong P = new elmSong;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertLastSong(ListSong &L, infoSong x){
    adrSong P = allocateSong(x);

    if(L.first == nullptr){
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

adrSong findSongByID(ListSong L, int id){
    adrSong P = L.first;

    while(P != nullptr){
        if(P->info.id == id){
            return P;
        } else {
            P = P->next;
        }
    }

    return nullptr;
}

adrSong findSongByID_AllGenres(GenreList &G, int id){
    adrGenre g = G.first;
    while(g != nullptr){
        adrSong s = g->songs.first;
        while(s != nullptr){
            if(s->info.id == id){
                return s;
            }
            s = s->next;
        }
        g = g->nextGenre;
    }
    return nullptr; 
}

void createGenreList(GenreList &G){
    G.first = nullptr;
}

adrGenre findGenre(GenreList G, string name){
    adrGenre P = G.first;

    while(P != nullptr){
        if(P->genreName == name){
            return P;
        } else {
            P = P->nextGenre;
        }
    }

    return nullptr;
}

void insertGenreLast(GenreList &G, string name){
    adrGenre P = new elmGenre;
    P->genreName = name;
    createListSong(P->songs);
    P->nextGenre = nullptr;

    if(G.first == nullptr){
        G.first = P;
    } else {
        adrGenre Q = G.first;
        while(Q->nextGenre != nullptr){
            Q = Q->nextGenre;
        }
        Q->nextGenre = P;
    }
}

bool isSongExist(GenreList G, string title, string artist){
    adrGenre g = G.first;
    while(g != nullptr){
        adrSong s = g->songs.first;
        while(s != nullptr){
            if(s->info.title == title &&
                s->info.artist == artist){
                return true;
            }
            s = s->next;
        }
        g = g->nextGenre;
    }
    return false;
}

 void insertSongToGenre(GenreList &G, infoSong x){
    x.id = autoID;
    autoID++;
    adrGenre Gx = findGenre(G, x.genre);

    if(isSongExist(G, x.title, x.artist)){
        cout << "Lagu dengan judul dan artis yang sama sudah ada!\n";
        return;
    }else if(Gx == nullptr){
        insertGenreLast(G, x.genre);
        Gx = findGenre(G, x.genre);
    }
    insertLastSong(Gx->songs, x);
}

void updateSongInfo(adrSong s){
    if(s != nullptr){
        string temp;

        cout << "Judul baru (- untuk skip) : ";
        cin >> temp;
        if(temp != "-"){
            s->info.title = temp;
        }

        cout << "Artist baru (- untuk skip) : ";
        cin >> temp;
        if(temp != "-"){
            s->info.artist = temp;
        }

        cout << "Album baru (- untuk skip) : ";
        cin >> temp;
        if(temp != "-"){
            s->info.album = temp;
        }

        int val;

        cout << "Tahun baru (0 untuk skip) : ";
        cin >> val;
        if(val != 0){
            s->info.year = val;
        }

        cout << "Durasi baru (0 untuk skip) : ";
        cin >> val;
        if(val != 0){
            s->info.duration = val;
        }

        cout << "Update selesai" << endl;
    }
}

void deleteSongByID(GenreList &G, int id){
    adrGenre P = G.first;

    while(P != nullptr){
        adrSong S = findSongByID(P->songs, id);

        if(S != nullptr){
            if(S == P->songs.first && S == P->songs.last){
                P->songs.first = nullptr;
                P->songs.last = nullptr;
            } else if(S == P->songs.first){
                P->songs.first = S->next;
                P->songs.first->prev = nullptr;
            } else if(S == P->songs.last){
                P->songs.last = S->prev;
                P->songs.last->next = nullptr;
            } else {
                S->prev->next = S->next;
                S->next->prev = S->prev;
            }
            delete S;
        }

        P = P->nextGenre;
    }
}

void printLibraryByGenre(GenreList G){
    adrGenre P = G.first;

    while(P != nullptr){
        cout << "== Genre : " << P->genreName << endl;

        adrSong S = P->songs.first;
        while(S != nullptr){
            cout << S->info.id << " - " << S->info.title << " - " << S->info.artist << endl;
            S = S->next;
        }

        cout << endl;
        P = P->nextGenre;
    }
}

adrSong findSongByTitleArtist(GenreList G, string title, string artist){
    adrGenre P = G.first;

    while(P != nullptr){
        adrSong S = P->songs.first;

        while(S != nullptr){
            if(S->info.title == title && S->info.artist == artist){
                return S;
            } else {
                S = S->next;
            }
        }

        P = P->nextGenre;
    }

    return nullptr;
}

void createPlaylistList(ListPlaylist &PL){
    PL.first = nullptr;
}

void insertPlaylistLast(ListPlaylist &PL, string name){
    adrPlaylist P = new elmPlaylist;
    P->name = name;
    P->firstSong = nullptr;
    P->next = nullptr;

    if(PL.first == nullptr){
        PL.first = P;
    } else {
        adrPlaylist Q = PL.first;
        while(Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrPlaylist findPlaylist(ListPlaylist PL, string name){
    adrPlaylist P = PL.first;

    while(P != nullptr){
        if(P->name == name){
            return P;
        } else {
            P = P->next;
        }
    }

    return nullptr;
}

void addSongToPlaylist(adrPlaylist P, adrSong S){
    adrPlaylistSong X = new elmPlaylistSong;
    X->songRef = S;
    X->next = nullptr;

    if(P->firstSong == nullptr){
        P->firstSong = X;
    } else {
        adrPlaylistSong Q = P->firstSong;
        while(Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = X;
    }
}

void printPlaylistContent(adrPlaylist P){
    cout << "== Playlist : " << P->name << endl;

    adrPlaylistSong Q = P->firstSong;

    if(Q == nullptr){
        cout << "(Kosong)" << endl;
    } else {
        while(Q != nullptr){
            cout << Q->songRef->info.id << " - "
                 << Q->songRef->info.title << " - "
                 << Q->songRef->info.artist << endl;
            Q = Q->next;
        }
    }
}

void createFavorite(ListFavorite &F){
    F.first = nullptr;
}

void insertLastFavorite(ListFavorite &F, adrSong S){
    adrFav P = new elmFavorite;
    P->songRef = S;
    P->next = nullptr;

    if(F.first == nullptr){
        F.first = P;
    } else {
        adrFav Q = F.first;
        while(Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = P;
    }
}

void printFavorite(ListFavorite F){
    adrFav P = F.first;

    while(P != nullptr){
        cout << P->songRef->info.title << endl;
        P = P->next;
    }
}

void createQueue(PlayQueue &Q){
    Q.front = nullptr;
    Q.back = nullptr;
}

void enqueue(PlayQueue &Q, adrSong S){
    adrQueue P = new elmQueue;
    P->songRef = S;
    P->next = nullptr;

    if(Q.front == nullptr){
        Q.front = P;
        Q.back = P;
    } else {
        Q.back->next = P;
        Q.back = P;
    }
}

adrSong dequeue(PlayQueue &Q){
    if(Q.front == nullptr){
        return nullptr;
    }

    adrQueue P = Q.front;
    adrSong s = P->songRef;

    Q.front = Q.front->next;
    if(Q.front == nullptr){
        Q.back = nullptr;
    }

    delete P;
    return s;
}

void printQueue(PlayQueue Q){
    adrQueue P = Q.front;

    while(P != nullptr){
        cout << P->songRef->info.title << endl;
        P = P->next;
    }
}

void createStack(HistoryStack &S){
    S.top = nullptr;
}

void pushStack(HistoryStack &S, adrSong x){
    adrStack P = new elmStack;
    P->songRef = x;
    P->next = S.top;
    S.top = P;
}

adrSong popStack(HistoryStack &S){
    if(S.top == nullptr) return nullptr; 

    adrStack P = S.top;
    adrSong s = P->songRef;  
    S.top = S.top->next;     
    delete P;                
    return s;                
}

void printHistory(HistoryStack S){
    adrStack P = S.top;

    while(P != nullptr){
        cout << P->songRef->info.title << endl;
        P = P->next;
    }
}

void createPermanentHistory(PermanentHistory &PH){
    PH.top = NULL;
}

void pushPermanentHistory(PermanentHistory &PH, adrSong x){
    if(isInPermanentHistory(PH, x->info.id)){
        return;
    }
    adrPHistory P = new elmPHistory;
    P->songRef = x;
    P->next = PH.top;
    PH.top = P;
}
bool isInPermanentHistory(PermanentHistory PH, int songID){
    adrPHistory P = PH.top;
    while(P != NULL){
        if(P->songRef->info.id == songID){
            return true;
        }
        P = P->next;
    }
    return false;
}

void printPermanentHistory(PermanentHistory PH){
    adrPHistory P = PH.top;
    if(P == NULL){
        cout << "(History kosong)" << endl;
        return;
    }

    while(P != NULL){
        cout << P->songRef->info.title 
             << " - " << P->songRef->info.artist << endl;
        P = P->next;
    }
}

void playSong(adrSong S){
    if(S != nullptr){
        cout << "Now Playing : " << S->info.title << " - " << S->info.artist << endl;
    }
}

void stopSong(){
    cout << "Lagu dihentikan." << endl;
}

adrSong nextSongByGenreOrder(GenreList &G, adrSong curr){
    if(curr == nullptr){
        return nullptr;
    }

    adrGenre g = findGenre(G, curr->info.genre);
    if(g == nullptr){
        return nullptr;
    } else if(curr->next != nullptr){
        return curr->next;
    } else if(g->nextGenre != nullptr){
        return g->nextGenre->songs.first;
    }else {
        return G.first->songs.first;
    }
}
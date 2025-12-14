#ifndef MUSIK_H
#define MUSIK_H
#include <iostream>

using namespace std;

typedef struct elmSong *adrSong;
typedef struct elmGenre *adrGenre;
typedef struct elmPlaylistSong *adrPlaylistSong;
typedef struct elmPlaylist *adrPlaylist;
typedef struct elmFavorite *adrFav;
typedef struct elmQueue *adrQueue;
typedef struct elmStack *adrStack;
typedef struct elmPHistory *adrPHistory;

struct infoSong {
    int id;
    string title;
    string artist;
    string genre;
    string album;
    int year;
    int duration;
};

struct elmSong {
    infoSong info;
    adrSong next;
    adrSong prev;
};

struct ListSong {
    adrSong first;
    adrSong last;
};

struct elmGenre {
    string genreName;
    ListSong songs;
    adrGenre nextGenre;
};

struct GenreList {
    adrGenre first;
};

struct elmPlaylistSong {
    adrSong songRef;
    adrPlaylistSong next;
};

struct elmPlaylist {
    string name;
    adrPlaylistSong firstSong;
    adrPlaylist next;
};

struct ListPlaylist {
    adrPlaylist first;
};

struct elmFavorite {
    adrSong songRef;
    adrFav next;
};

struct ListFavorite {
    adrFav first;
};

struct elmQueue {
    adrSong songRef;
    adrQueue next;
};

struct PlayQueue {
    adrQueue front;
    adrQueue back;
};

struct elmStack {
    adrSong songRef;
    adrStack next;
};

struct HistoryStack {
    adrStack top;
};

struct elmPHistory {
    adrSong songRef;
    adrPHistory next;
};

struct PermanentHistory {
    adrPHistory top;
};

void createListSong(ListSong &L);
adrSong allocateSong(infoSong x);
void insertLastSong(ListSong &L, infoSong x);
void updateSongInfo(adrSong s);
adrSong findSongByID(ListSong L, int id);
adrSong findSongByID_AllGenres(GenreList &G, int id);
void createGenreList(GenreList &G);
adrGenre findGenre(GenreList G, string genreName);
void insertGenreLast(GenreList &G, string genreName);
bool isSongExist(GenreList G, string title, string artist);
void insertSongToGenre(GenreList &G, infoSong x);
void deleteSongByID(GenreList &G, int id);
void printLibraryByGenre(GenreList G);
adrSong findSongByTitleArtist(GenreList G, string title, string artist);
void createPlaylistList(ListPlaylist &P);
void insertPlaylistLast(ListPlaylist &P, string name);
adrPlaylist findPlaylist(ListPlaylist P, string name);
void addSongToPlaylist(adrPlaylist P, adrSong S);
void printPlaylistContent(adrPlaylist P);
void createFavorite(ListFavorite &F);
void insertLastFavorite(ListFavorite &F, adrSong S);
void printFavorite(ListFavorite F);
void createQueue(PlayQueue &Q);
void enqueue(PlayQueue &Q, adrSong S);
adrSong dequeue(PlayQueue &Q);
void printQueue(PlayQueue Q);
void createStack(HistoryStack &S);
void pushStack(HistoryStack &S, adrSong S2);
adrSong popStack(HistoryStack &S);
void printHistory(HistoryStack S);
void createPermanentHistory(PermanentHistory &PH);
void pushPermanentHistory(PermanentHistory &PH, adrSong x);
bool isInPermanentHistory(PermanentHistory PH, int songID);
void printPermanentHistory(PermanentHistory PH);
void playSong(adrSong S);
void stopSong();
adrSong nextSongByGenreOrder(GenreList &G, adrSong curr);

#endif
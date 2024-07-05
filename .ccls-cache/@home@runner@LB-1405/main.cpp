 #include <iostream>
 #include <cstring>

 using namespace std;

 int main() {
  
  // Треба створити динамічний масив. Користувач вводить назви треків, треба додавати ці назви до масиву. Користувач вводить їх поки не скаже stop. Мивести потім цей масив.
   
const int MAX_TRACK_NAME = 100;
int mes = 2;
int size = 0;
char** tracks = new char*[mes];

char track[MAX_TRACK_NAME];

cout << "Введіть назви треків (введіть «стоп», щоб закінчити):" << endl;
 while (true) {
  cin.getline(track, MAX_TRACK_NAME);
    if (strcmp(track, "stop") == 0) {
          break;
    }
    if (size == mes) {
    mes *= 2;
    char** newTracks = new char*[mes];
    for (int i = 0; i < size; ++i) {
    newTracks[i] = tracks[i];
        }
        delete[] tracks;
        tracks = newTracks;
    }

  tracks[size] = new char[strlen(track) + 1];
    strcpy(tracks[size], track);
     ++size;
  }

cout << "Ви ввели такі треки:" << endl;
  for (int i = 0; i < size; ++i) {
  cout << tracks[i] << endl;
  delete[] tracks[i]; 
  }
   
  delete[] tracks;
     return 0;
 }
